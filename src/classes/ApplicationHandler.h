#pragma once

#include <QTimer>
#include <QObject>
#include <QString>
#include <QStringList>

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

class ApplicationHandler: public QObject
{
    private:
        QApplication *application;
        ApplicationConfig *config;
        ApplicationWindow *window;

        QTimer *timer;
        QNetworkReply *reply;
        QNetworkAccessManager *network;

        void requestWeatherAndShowIt();

        QString getWeatherRequestUrl();

    public:
        ApplicationHandler(QApplication *application, ApplicationConfig *config);

        QApplication *getApplication();

        void showApplicationWindow(int width, int height);

        void setApplicationWindowTitle(const char *title);

        void startWeatherMonitoring();
};