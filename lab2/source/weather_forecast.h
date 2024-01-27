#ifndef WEATHER_FORECAST_H
#define WEATHER_FORECAST_H

#include <iostream>
#include <string>
#include <chrono>
class WeatherForecast {
private:
    long date;
    double morningTemperature;
    double dayTemperature;
    double eveningTemperature;
    std::string weatherCondition;
    double precipitation;
    std::chrono::time_point<std::chrono::system_clock> forecastDate;
public:
    WeatherForecast(long date, double morningTemp, double dayTemp, double eveningTemp, const std::string& condition, double precipitation);
    WeatherForecast(long date, double morningTemp, double dayTemp, double eveningTemp, double precipitation);

    WeatherForecast& operator+=(const WeatherForecast& other);
    double getAverageTemperature() const;
    bool isForecastIncorrect() const;
    bool operator==(const WeatherForecast& other) const;
    bool operator<(const WeatherForecast& other) const;

    long getDate() const { return date; }
    std::string getWeatherCondition() const { return weatherCondition; }
    void determineWeatherCondition();
    void validateInput();
};

#endif // WEATHER_FORECAST_H

