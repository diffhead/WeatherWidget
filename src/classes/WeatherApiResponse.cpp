#include <WeatherApiResponse.h>

WeatherApiResponse::WeatherApiResponse(QJsonObject json)
{
    this->weather = json.value("weather").toObject();
    this->city = json.value("location").toObject().value("city").toObject();
}

QString WeatherApiResponse::getWindText()
{
    QString windText = "Wind: ";

    windText.append(QString::number(this->weather.value("wind_speed").toDouble(), 'f', 0));
    windText.append("m/s");

    return windText;
}

QString WeatherApiResponse::getWeatherCity()
{
    return this->city.value("title").toString();
}

QString WeatherApiResponse::getWeatherIcon()
{
    return this->weather.value("weather_icon").toString();
}

QString WeatherApiResponse::getWeatherText()
{
    QString weatherText;

    weatherText.append(this->weather.value("weather").toString()).append(" ");
    weatherText.append(QString::number(this->weather.value("temperature").toString().toDouble(), 'f', 0));
    weatherText.append(" C");

    return weatherText;
}
