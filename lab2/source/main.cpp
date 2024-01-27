#include "weather_dialog.h"
#include "weather_forecast.h"
#include "weather_forecast_vector.h"
#include "iostream"
int main() {
    WeatherForecastVector forecastVector;

    WeatherDialog::runInteractiveDialog(forecastVector);

    return 0;
}

