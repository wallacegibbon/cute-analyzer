cmake_minimum_required(VERSION 3.16.0)

set(PRJ_NAME cute-analyzer)

project(${PRJ_NAME} VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

## tell CMake to run the Qt tools moc, rcc, and uic automatically
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt6 COMPONENTS Widgets LinguistTools REQUIRED)

## translation files
set(TS_FILES basic_zh_CN.ts)

set(PROJECT_SOURCES main.cpp mainwindow.cpp mainwindow.ui ${TS_FILES})

qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})

set(QT_SERIAL_PORT_DIR "/home/wallace/work/qtserialport-6.2.4/build")

## "link_directories" and "link_libraries" have to be before target creation
link_directories("${QT_SERIAL_PORT_DIR}/lib")

## in CMake, "target" can be created by "add_library()" or "add_executable()"
# add_executable(${PRJ_NAME} ${PROJECT_SOURCES})
qt_add_executable(${PRJ_NAME} ${PROJECT_SOURCES})

target_link_libraries(${PRJ_NAME} PRIVATE Qt6::Widgets Qt6SerialPort)
target_include_directories(${PRJ_NAME} PRIVATE "${QT_SERIAL_PORT_DIR}/include")
