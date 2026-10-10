cmake_minimum_required(VERSION 3.20)

add_executable(StaticApp main.cpp)

# Лінкуємо статичну бібліотеку NumericalDiff до нашого додатку
target_link_libraries(StaticApp PRIVATE NumericalDiff)