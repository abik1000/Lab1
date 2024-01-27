cmake_minimum_required(VERSION 3.22.1)
project(Lab2)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
add_executable(main
    ./source/main.cpp
    ./source/weather_dialog.h
    ./source/weather_dialog.cpp
   ./source/weather_forecast_vector.h
    ./source/weather_forecast_vector.cpp
    ./source/weather_forecast.h
    ./source/weather_forecast.cpp
)

