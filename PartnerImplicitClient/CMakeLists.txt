cmake_minimum_required(VERSION 3.20)
project(PartnerImplicitClient LANGUAGES CXX)

add_executable(PartnerImplicitApp main.cpp)

# Підключаємо заголовочні файли партнера
target_include_directories(PartnerImplicitApp PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/3rdParty/IntegrationLib/include
)

# Лінкуємо .lib файл партнера
target_link_libraries(PartnerImplicitApp PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/3rdParty/IntegrationLib/lib/IntegrationLib.lib
)

# Автоматичне копіювання його .dll у папку з бінарником після збірки
add_custom_command(TARGET PartnerImplicitApp POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${CMAKE_CURRENT_SOURCE_DIR}/3rdParty/IntegrationLib/bin/IntegrationLib.dll"
    "$<TARGET_FILE_DIR:PartnerImplicitApp>"
)