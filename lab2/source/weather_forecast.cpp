#include "weather_forecast.h"

WeatherForecast::WeatherForecast(long date, double morningTemp, double dayTemp, double eveningTemp, const std::string& condition, double precipitation)
    : date(date), morningTemperature(morningTemp), dayTemperature(dayTemp), eveningTemperature(eveningTemp), weatherCondition(condition), precipitation(precipitation) {
    validateInput();
}

WeatherForecast::WeatherForecast(long date, double morningTemp, double dayTemp, double eveningTemp, double precipitation)
    : date(date), morningTemperature(morningTemp), dayTemperature(dayTemp), eveningTemperature(eveningTemp), precipitation(precipitation) {
    determineWeatherCondition();
    validateInput();
}

WeatherForecast& WeatherForecast::operator+=(const WeatherForecast& other) {
    morningTemperature = (morningTemperature + other.morningTemperature) / 2;
    dayTemperature = (dayTemperature + other.dayTemperature) / 2;
    eveningTemperature = (eveningTemperature + other.eveningTemperature) / 2;
    precipitation = (precipitation + other.precipitation) / 2;
    
    if (other.weatherCondition == "снег" || weatherCondition == "снег") {
        weatherCondition = "снег";
    } else if(other.weatherCondition == "дождь" || weatherCondition == "дождь") {
        weatherCondition = "дождь";
    } else if (other.weatherCondition == "облачно" || weatherCondition == "облачно") {
        weatherCondition = "облачно";
    } else if (other.weatherCondition == "солнечно" || weatherCondition == "солнечно") {
        weatherCondition = "солнечно";
    }	    

    return *this;
}

double WeatherForecast::getAverageTemperature() const {
    return (morningTemperature + dayTemperature + eveningTemperature) / 3;
}
bool WeatherForecast::isForecastIncorrect() const {
    bool sunnyOrCloudy = (weatherCondition == "солнечно" || weatherCondition == "облачно");
    bool snowy = (weatherCondition == "снег");

    bool incorrectPrecipitation = sunnyOrCloudy && precipitation != 0;
    bool incorrectSnowTemperature = snowy && getAverageTemperature() > 0;
    bool incorrectTemperatureRange = (morningTemperature < -100 || dayTemperature < -100 || eveningTemperature < -100 ||
                                      morningTemperature > 60 || dayTemperature > 60 || eveningTemperature > 60);
    bool excessivePrecipitation = precipitation > 1500;

    return incorrectPrecipitation || incorrectSnowTemperature || incorrectTemperatureRange || excessivePrecipitation;
}

void WeatherForecast::determineWeatherCondition() {
    if (precipitation == 0) {
        weatherCondition = "солнечно";
    } else if (precipitation <= 5) {
        weatherCondition = "облачно";
    } else if (precipitation <= 20) {
        weatherCondition = "дождь";
    } else if (temperature <=0){
        weatherCondition = "снег";
    }
}

void WeatherForecast::validateInput() {
    if (morningTemperature < -273 || dayTemperature < -273 || eveningTemperature < -273 ||
        morningTemperature > 60 || dayTemperature > 60 || eveningTemperature > 60 ||
        precipitation < 0) {
        throw std::invalid_argument("Неверные параметры прогноза");
    }
}
bool WeatherForecast::operator==(const WeatherForecast& other) const {
    return forecastDate == other.forecastDate;  // Изменили имя переменной
}

bool WeatherForecast::operator<(const WeatherForecast& other) const {
    return forecastDate < other.forecastDate;  // Изменили имя переменной
}
