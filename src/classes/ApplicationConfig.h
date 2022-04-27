#pragma once

#include <QFile>
#include <QString>
#include <QIODevice>
#include <QByteArray>
#include <QCoreApplication>

#include <QJsonObject>
#include <QJsonDocument>

class ApplicationConfig: public QJsonObject
{
    private:
        bool initialized = false;

        QString url;
        QString city;

    public:
        ApplicationConfig();

        bool isInitialized();

        QString getUrl();
        QString getCity();
};
