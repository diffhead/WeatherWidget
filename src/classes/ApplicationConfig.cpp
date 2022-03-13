#include <ApplicationConfig.h>

ApplicationConfig::ApplicationConfig()
{
    QString filePath = QCoreApplication::applicationDirPath().append("/config.json");

    QFile configFile(filePath);

    QByteArray jsonText;

    if ( configFile.open(QIODevice::ReadOnly) ) {
        jsonText = configFile.readAll();
    }

    configFile.close();

    QJsonObject json = QJsonDocument::fromJson(jsonText).object();

    this->url = json.value("apiUrl").toString();
    this->key = json.value("apiKey").toString();
    this->units = json.value("units").toString();

    this->latitude = QString::number(json.value("latitude").toDouble(), 'f', 2);
    this->longitude = QString::number(json.value("longitude").toDouble(), 'f', 2);

    if ( this->url != "" && this->key != "" ) {
        this->initialized = true;
    }
}

bool ApplicationConfig::isInitialized()
{
    return this->initialized;
}

QString ApplicationConfig::getUrl()
{
    return this->url;
}

QString ApplicationConfig::getApiKey()
{
    return this->key;
}

QString ApplicationConfig::getUnits()
{
    return this->units;
}

QString ApplicationConfig::getLatitude()
{
    return this->latitude;
}

QString ApplicationConfig::getLongitude()
{
    return this->longitude;
}
