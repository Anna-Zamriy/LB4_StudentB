cmake_minimum_required(VERSION 3.20)
project(NumericalDiffDll LANGUAGES CXX)

# Створюємо ДИНАМІЧНУ бібліотеку за допомогою ключового слова SHARED
add_library(NumericalDiff SHARED src/NumericalDiff.cpp)

# Визначаємо макрос NUMDIFF_EXPORTS виключно під час збірки САМОЇ бібліотеки
target_compile_definitions(NumericalDiff PRIVATE NUMDIFF_EXPORTS)

# Публічна папка із заголовочними файлами для майбутнього SDK
target_include_directories(NumericalDiff PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(NumericalDiff PUBLIC cxx_std_20)