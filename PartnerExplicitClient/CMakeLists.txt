cmake_minimum_required(VERSION 3.20)
project(PartnerExplicitClient LANGUAGES CXX)

add_executable(PartnerExplicitApp main.cpp)

# Копіювання DLL поруч із зібраним .exe для зручності
add_custom_command(TARGET PartnerExplicitApp POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${CMAKE_CURRENT_SOURCE_DIR}/IntegrationLib.dll"
    "$<TARGET_FILE_DIR:PartnerExplicitApp>"
)