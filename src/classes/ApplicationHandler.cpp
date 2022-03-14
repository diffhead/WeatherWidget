#include <ApplicationHandler.h>

ApplicationHandler::ApplicationHandler(QApplication *application, ApplicationConfig *config)
{
    this->config = config; 
    this->application = application;

    this->timer = new QTimer(this);
    this->network = new QNetworkAccessManager();
    this->window = new ApplicationWindow();

    this->weatherRequestUri = this->buildWeatherRequestUri();
    this->weatherIconCurrent = QString("");
}

QApplication* ApplicationHandler::getApplication()
{
    return this->application;
}

void ApplicationHandler::showApplicationWindow(int width, int height)
{
    this->window->resize(width, height);
    this->window->setWindowOpacity(0.8);

    this->window->show();
}

void ApplicationHandler::setApplicationWindowTitle(const char *title)
{
    this->window->setWindowTitle(title);
}

void ApplicationHandler::startWeatherMonitoring()
{
    this->requestWeatherAndShowIt();

    this->timer->start(5000);

    QObject::connect(this->timer, &QTimer::timeout, this->timer, [=]() {
        this->requestWeatherAndShowIt();
    });
}

void ApplicationHandler::requestWeatherAndShowIt()
{
    QNetworkRequest request(QUrl(this->weatherRequestUri));

    this->reply = this->network->get(request);

    QObject::connect(this->reply, &QNetworkReply::finished, this, [=]() {
        WeatherApiResponse response(QJsonDocument::fromJson(this->reply->readAll()).object());

        QString weatherText = response.getWeatherCity().append("\n\n");
        QString weatherIcon = response.getWeatherIcon();

        weatherText.append(response.getWeatherText(this->config->getUnits())).append("\n\n");
        weatherText.append(response.getWindText());

        this->window->setWeatherText(weatherText);

        if ( this->weatherIconCurrent != weatherIcon ) {
            QNetworkRequest request(QUrl(this->buildWeatherIconUri(weatherIcon)));

            this->reply = this->network->get(request);

            QObject::connect(this->reply, &QNetworkReply::finished, this, [=]() {
                QByteArray icon = this->reply->readAll();

                this->window->setWeatherIcon(icon);
            });
        }
    });
}

QString ApplicationHandler::buildWeatherRequestUri()
{
    QString url = this->config->getUrl();

    QString apiKey = QString("appid=").append(this->config->getApiKey());
    QString latitude = QString("lat=").append(this->config->getLatitude());
    QString longitude = QString("lon=").append(this->config->getLongitude());
    QString units = QString("units=").append(this->config->getUnits());

    QStringList params = { apiKey, latitude, longitude, units };

    url.append("?").append(params.join('&'));

    return url;
}

QString ApplicationHandler::buildWeatherIconUri(QString icon)
{
    return QString("https://openweathermap.org/img/w/").append(icon).append(".png");
}
