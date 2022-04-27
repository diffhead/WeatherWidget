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
    this->city = json.value("apiCity").toString();

    if ( this->url != "" && this->city != "" ) {
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

QString ApplicationConfig::getCity()
{
    return this->city;
}
