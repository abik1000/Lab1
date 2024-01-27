#include "weather_dialog.h"
#include <iostream>

void WeatherDialog::printMenu() {
    std::cout << "==== Меню ====\n";
    std::cout << "1. Добавить прогноз\n";
    std::cout << "2. Добавить прогноз(Авто-выбор погодного явления)\n";
    std::cout << "3. Удалить прогноз по номеру\n";
    std::cout << "4. Найти самый холодный день за период\n";
    std::cout << "5. Найти ближайший солнечный день\n";
    std::cout << "6. Удалить ошибочные прогнозы\n";
    std::cout << "7. Объединить повторяющиеся прогнозы за сутки\n";
    std::cout << "8. Вывести прогнозы за месяц\n";
    std::cout << "9. Вывести все прогнозы\n";
    std::cout << "0. Выйти\n";
}

void WeatherDialog::executeMenuChoice(int choice, WeatherForecastVector& forecastVector) {
    switch (choice) {
        case 1: {
            long date;
            double morningTemp, dayTemp, eveningTemp, precipitation;
            std::string condition;

            std::cout << "Введите дату (Unix timestamp): ";
            std::cin >> date;
            std::cout << "Введите утреннюю температуру: ";
            std::cin >> morningTemp;
            std::cout << "Введите дневную температуру: ";
            std::cin >> dayTemp;
            std::cout << "Введите вечернюю температуру: ";
            std::cin >> eveningTemp;
            std::cout << "Введите погодное явление (солнечно, облачно, дождь, снег): ";
            std::cin >> condition;
            std::cout << "Введите количество осадков: ";
            std::cin >> precipitation;

            WeatherForecast newForecast(date, morningTemp, dayTemp, eveningTemp, condition, precipitation);
            forecastVector += newForecast;

            std::cout << "Прогноз добавлен.\n";
            break;
        }
	case 2: {
	    long date;
            double morningTemp, dayTemp, eveningTemp, precipitation;
            
	    std::cout << "Введите дату (Unix timestamp): ";
            std::cin >> date;
            std::cout << "Введите утреннюю температуру: ";
            std::cin >> morningTemp;
            std::cout << "Введите дневную температуру: ";
            std::cin >> dayTemp;
            std::cout << "Введите вечернюю температуру: ";
            std::cin >> eveningTemp;
            std::cout << "Введите количество осадков: ";
            std::cin >> precipitation;	 
	    
	    WeatherForecast newForecast(date, morningTemp, dayTemp, eveningTemp, precipitation);
            forecastVector += newForecast;
	    std::cout << "Прогноз добавлен.\n";
	    break;   
	}
        case 3: {
            size_t index;
            std::cout << "Введите номер прогноза для удаления: ";
            std::cin >> index;

            try {
                forecastVector.removeForecast(index);
                std::cout << "Прогноз удален.\n";
            } catch (const std::out_of_range& e) {
                std::cerr << e.what() << "\n";
            }
            break;
        }
        case 4: {
            long startDate, endDate;
            std::cout << "Введите начальную дату (Unix timestamp): ";
            std::cin >> startDate;
            std::cout << "Введите конечную дату (Unix timestamp): ";
            std::cin >> endDate;

            WeatherForecast coldestDay = forecastVector.findColdestDay(startDate, endDate);
            std::cout << "Самый холодный день: " << coldestDay.getDate() << "\n";
            break;
        }
        case 5: {
            long currentDate;
            std::cout << "Введите текущую дату (Unix timestamp): ";
            std::cin >> currentDate;

            WeatherForecast closestSunnyDay = forecastVector.findClosestSunnyDay(currentDate);
            std::cout << "Ближайший солнечный день: " << closestSunnyDay.getDate() << "\n";
            break;
        }
        case 6: {
            forecastVector.removeIncorrectForecasts();
            std::cout << "Удалены ошибочные прогнозы.\n";
            break;
        }
        case 7: {
            forecastVector.mergeDuplicateForecasts();
            std::cout << "Повторяющиеся прогнозы объединены.\n";
            break;
        }
        case 8: {
            int month;
            std::cout << "Введите номер месяца: ";
            std::cin >> month;

            std::vector<WeatherForecast> forecastsForMonth = forecastVector.getForecastsForMonth(month);
            std::cout << "Прогнозы за месяц:\n";
            for (const auto& forecast : forecastsForMonth) {
                std::cout << "Дата: " << forecast.getDate() << ", Температура: " << forecast.getAverageTemperature() << "°C\n";
            }
            break;
        }
        case 9: {
            std::cout << "Все прогнозы:\n";
            for (const auto& forecast : forecastVector) {
                std::cout << "Дата: " << forecast.getDate() << ", Температура: " << forecast.getAverageTemperature() << "°C\n";
            }
            break;
        }
	case 10:{
	    
	    getAverageTemperature();
	    break;
	}
	case 11:
	
	case 12:

        case 0:
            std::cout << "Программа завершена.\n";
            break;
        default:
            std::cerr << "Неверный выбор. Пожалуйста, повторите ввод.\n";
    }
}

void WeatherDialog::runInteractiveDialog(WeatherForecastVector& forecastVector) {
    int choice;
    do {
        printMenu();
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        executeMenuChoice(choice, forecastVector);

    } while (choice != 0);
}

