#pragma once

#include <QFile>
#include <QString>
#include <QIODevice>
#include <QByteArray>

#include <QJsonObject>
#include <QJsonDocument>

class ApplicationConfig: public QJsonObject
{
    private:
        bool initialized = false;

        QString url;
        QString key;

        QString latitude;
        QString longitude;

        QString units;

    public:
        ApplicationConfig();

        bool isInitialized();

        QString getUrl();
        QString getApiKey();
        QString getLatitude();
        QString getLongitude();
        QString getUnits();
};
