#ifndef WEATHER_DIALOG_H
#define WEATHER_DIALOG_H

#include "weather_forecast_vector.h"

class WeatherDialog {
public:
    static void printMenu();
    static void executeMenuChoice(int choice, WeatherForecastVector& forecastVector);
    static void runInteractiveDialog(WeatherForecastVector& forecastVector);
};

#endif // WEATHER_DIALOG_H

