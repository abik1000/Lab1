#ifndef WEATHER_FORECAST_VECTOR_H
#define WEATHER_FORECAST_VECTOR_H

#include "weather_forecast.h"
#include <vector>
#include <functional>

class WeatherForecastVector {
private:
    std::vector<WeatherForecast> forecasts;

public:
    WeatherForecastVector() = default;
    WeatherForecastVector(const std::vector<WeatherForecast>& forecasts);
    WeatherForecastVector(const WeatherForecast& forecast);

    void operator+=(const WeatherForecast& forecast);
    WeatherForecast& operator[](size_t index);
    void removeForecast(size_t index);
    WeatherForecast findColdestDay(long startDate, long endDate) const;
    WeatherForecast findClosestSunnyDay(long currentDate) const;
    void removeIncorrectForecasts();
    void mergeDuplicateForecasts();
    void sortForecastsByDate();
    void getForecastsForMonth(int month, std::vector<WeatherForecast>& result) const;
    std::vector<WeatherForecast> getForecastsForMonth(int month) const;
    std::vector<WeatherForecast>::iterator begin() {
        return forecasts.begin();
    }

    std::vector<WeatherForecast>::iterator end() {
        return forecasts.end();
    }

    std::vector<WeatherForecast>::const_iterator begin() const {
        return forecasts.begin();
    }

    std::vector<WeatherForecast>::const_iterator end() const {
        return forecasts.end();
    }
    std::vector<WeatherForecast> getFilteredForecasts(std::function<bool(const WeatherForecast&)> filter) const;
};

#endif // WEATHER_FORECAST_VECTOR_H

