#include <ApplicationHandler.h>

ApplicationHandler::ApplicationHandler(QApplication *application, QString widgetVersion, ApplicationConfig *config)
{
    this->config = config; 
    this->application = application;
    this->widgetVersion = widgetVersion;

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

    request.setRawHeader(QByteArray("User-Agent"), QByteArray("QWeatherWidget v").append(this->getWidgetVersion().toUtf8()));

    this->reply = this->network->get(request);

    QObject::connect(this->reply, &QNetworkReply::finished, this, [=]() {
        WeatherApiResponse response(QJsonDocument::fromJson(this->reply->readAll()).object());

        QString weatherText = response.getWeatherCity().append("\n\n");
        QString weatherIcon = response.getWeatherIcon();

        weatherText.append(response.getWeatherText()).append("\n\n");
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

QString ApplicationHandler::getWidgetVersion()
{
    return this->widgetVersion;
}

QString ApplicationHandler::buildWeatherRequestUri()
{
    QString url = this->config->getUrl();
    QString city = this->config->getCity();

    url.append("?city=").append(city);

    return url;
}

QString ApplicationHandler::buildWeatherIconUri(QString icon)
{
    return QString("https://openweathermap.org/img/w/").append(icon).append(".png");
}
