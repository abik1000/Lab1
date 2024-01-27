#include "weather_forecast_vector.h"
#include <algorithm>
#include <iterator>

WeatherForecastVector::WeatherForecastVector(const std::vector<WeatherForecast>& forecasts)
    : forecasts(forecasts) {}

WeatherForecastVector::WeatherForecastVector(const WeatherForecast& forecast) {
    forecasts.push_back(forecast);
}

void WeatherForecastVector::operator+=(const WeatherForecast& forecast) {
    forecasts.push_back(forecast);
    sortForecastsByDate();
}

WeatherForecast& WeatherForecastVector::operator[](size_t index) {
    if (index < forecasts.size()) {
        return forecasts[index];
    } else {
        throw std::out_of_range("Индекс выходит за пределы размера вектора");
    }
}

void WeatherForecastVector::removeForecast(size_t index) {
    if (index < forecasts.size()) {
        forecasts.erase(forecasts.begin() + index);
    } else {
        throw std::out_of_range("Индекс выходит за пределы размера вектора");
    }
}

WeatherForecast WeatherForecastVector::findColdestDay(long startDate, long endDate) const {
    auto result = std::min_element(forecasts.begin(), forecasts.end(), [=](const WeatherForecast& a, const WeatherForecast& b) {
        return a.getAverageTemperature() < b.getAverageTemperature();
    });

    return *result;
}

WeatherForecast WeatherForecastVector::findClosestSunnyDay(long currentDate) const {
    auto sunnyDays = getFilteredForecasts([](const WeatherForecast& forecast) {
        return forecast.getWeatherCondition() == "солнечно";
    });

    auto result = std::min_element(sunnyDays.begin(), sunnyDays.end(), [=](const WeatherForecast& a, const WeatherForecast& b) {
        return std::abs(a.getDate() - currentDate) < std::abs(b.getDate() - currentDate);
    });

    return *result;
}

void WeatherForecastVector::removeIncorrectForecasts() {
    forecasts.erase(std::remove_if(forecasts.begin(), forecasts.end(), [](const WeatherForecast& forecast) {
        return forecast.isForecastIncorrect();
    }), forecasts.end());

    sortForecastsByDate();
}

void WeatherForecastVector::mergeDuplicateForecasts() {
    std::vector<WeatherForecast> uniqueForecasts;

    for (const auto& forecast : forecasts) {
        auto it = std::find_if(uniqueForecasts.begin(), uniqueForecasts.end(), [&](const WeatherForecast& uniqueForecast) {
            return uniqueForecast.getDate() == forecast.getDate();
        });

        if (it != uniqueForecasts.end()) {
            *it += forecast;
        } else {
            uniqueForecasts.push_back(forecast);
        }
    }

    forecasts = uniqueForecasts;
    sortForecastsByDate();
}

void WeatherForecastVector::getForecastsForMonth(int month, std::vector<WeatherForecast>& result) const {
    for (const auto& forecast : forecasts) {
        time_t date = forecast.getDate();
        struct tm *timeinfo = gmtime(&date);

        if (timeinfo->tm_mon + 1 == month) {
            result.push_back(forecast);
        }
    }
}

std::vector<WeatherForecast> WeatherForecastVector::getForecastsForMonth(int month) const {
    std::vector<WeatherForecast> result;
    getForecastsForMonth(month, result);
    return result;
}

std::vector<WeatherForecast> WeatherForecastVector::getFilteredForecasts(std::function<bool(const WeatherForecast&)> filter) const {
    std::vector<WeatherForecast> filteredForecasts;

    std::copy_if(forecasts.begin(), forecasts.end(), std::back_inserter(filteredForecasts), filter);

    return filteredForecasts;
}
void WeatherForecastVector::sortForecastsByDate() {
    // Сортируем прогнозы по дате
    std::sort(forecasts.begin(), forecasts.end(),
              [](const WeatherForecast& a, const WeatherForecast& b) {
                  return a.getDate() < b.getDate();
              });
}
