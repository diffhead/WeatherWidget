#include <ApplicationHandler.h>

ApplicationHandler::ApplicationHandler(QApplication *application, ApplicationConfig *config)
{
    this->config = config; 
    this->application = application;

    this->timer = new QTimer(this);
    this->network = new QNetworkAccessManager();
    this->window = new ApplicationWindow();
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
    QNetworkRequest request(QUrl(this->getWeatherRequestUrl()));

    this->reply = this->network->get(request);

    QObject::connect(this->reply, &QNetworkReply::finished, this->reply, [=]() {
        QJsonObject json = QJsonDocument::fromJson(this->reply->readAll()).object();

        QJsonObject main = json.value("main").toObject();
        QJsonObject weather = json.value("weather").toArray().at(0).toObject();

        QString weatherDescription = weather.value("main").toString();
        QString weatherTemperature = QString::number(main.value("temp").toDouble(), 'f', 0);

        this->window->setWeatherText(weatherDescription.append(QString(" ")).append(weatherTemperature));
    });
}

QString ApplicationHandler::getWeatherRequestUrl()
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
