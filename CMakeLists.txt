cmake_minimum_required(VERSION 3.16.0)

set(TARGET cute-analyzer)

project(${TARGET} VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# tell CMake to run the Qt tools moc, rcc, and uic automatically
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(QT NAMES Qt6 COMPONENTS Widgets LinguistTools REQUIRED)
find_package(Qt6 COMPONENTS Widgets LinguistTools REQUIRED)

# translation files
set(TS_FILES basic_zh_CN.ts)

set(PROJECT_SOURCES main.cpp mainwindow.cpp mainwindow.ui ${TS_FILES})

qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})

qt_add_executable(${TARGET} ${PROJECT_SOURCES})

target_link_libraries(${TARGET} PRIVATE Qt6::Widgets)
