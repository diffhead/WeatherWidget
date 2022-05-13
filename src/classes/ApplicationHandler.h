#pragma once

#include <QTimer>
#include <QObject>
#include <QString>
#include <QStringList>
#include <QByteArray>

#include <QLabel>
#include <QWidget>
#include <QApplication>

#include <QUrl>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>

#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

#include <ApplicationConfig.h>
#include <ApplicationWindow.h>
#include <WeatherApiResponse.h>

class ApplicationHandler: public QObject
{
    private:
        QString widgetVersion;

        QApplication *application;
        ApplicationConfig *config;
        ApplicationWindow *window;

        QTimer *timer;
        QNetworkReply *reply;
        QNetworkAccessManager *network;

        QString weatherRequestUri;
        QString weatherIconCurrent;

        void requestWeatherAndShowIt();
        QString getWidgetVersion();

        QString buildWeatherRequestUri();
        QString buildWeatherIconUri(QString icon);

    public:
        ApplicationHandler(QApplication *application, QString widgetVersion, ApplicationConfig *config);

        QApplication *getApplication();
        
        void showApplicationWindow(int width, int height);
        void setApplicationWindowTitle(const char *title);
        void startWeatherMonitoring();
};
