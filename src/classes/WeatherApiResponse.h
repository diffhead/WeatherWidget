#pragma once

#include <QString>
#include <QByteArray>

#include <QJsonObject>
#include <QJsonArray>

class WeatherApiResponse
{
    private:
        QJsonObject city;
        QJsonObject weather;

    public:
        WeatherApiResponse(QJsonObject json);

        QString getWindText();
        QString getWeatherCity();
        QString getWeatherIcon();
        QString getWeatherText();
};
