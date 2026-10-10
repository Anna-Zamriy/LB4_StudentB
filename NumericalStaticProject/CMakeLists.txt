cmake_minimum_required(VERSION 3.20)
project(NumericalStaticProject LANGUAGES CXX)

# Додаємо папки бібліотеки та програми до загального процесу збірки
add_subdirectory(NumericalDiff)
add_subdirectory(App)