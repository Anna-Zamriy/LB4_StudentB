cmake_minimum_required(VERSION 3.20)

# Створюємо статичну бібліотеку з ім'ям NumericalDiff
add_library(NumericalDiff STATIC src/NumericalDiff.cpp)

# Вказуємо, де лежать заголовочні файли. Ключове слово PUBLIC означає,
# що цей шлях автоматично передасться і всім, хто підключить нашу бібліотеку!
target_include_directories(NumericalDiff PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Встановлюємо сучасний стандарт мови C++20
target_compile_features(NumericalDiff PUBLIC cxx_std_20)