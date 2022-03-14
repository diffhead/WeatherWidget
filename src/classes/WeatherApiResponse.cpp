#include <WeatherApiResponse.h>

WeatherApiResponse::WeatherApiResponse(QJsonObject json)
{
    this->json = json;

    this->main = json.value("main").toObject();
    this->wind = json.value("wind").toObject();
    this->weather = json.value("weather").toArray().at(0).toObject();
}

QString WeatherApiResponse::getWindText()
{
    QString windText = "Wind: ";

    windText.append(QString::number(this->wind.value("speed").toDouble(), 'f', 1));
    windText.append(" m/s");

    return windText;
}

QString WeatherApiResponse::getWeatherCity()
{
    return this->json.value("name").toString();
}

QString WeatherApiResponse::getWeatherIcon()
{
    return this->weather.value("icon").toString();
}

QString WeatherApiResponse::getWeatherText(QString units)
{
    QString weatherText;

    weatherText.append(this->weather.value("main").toString()).append(" ");
    weatherText.append(QString::number(this->main.value("temp").toDouble(), 'f', 0));

    if ( units == "metric" ) {
        weatherText.append(" C");
    } else if ( units == "imperial" ) {
        weatherText.append(" F");
    } else {
        weatherText.append(" K");
    }

    return weatherText;
}
