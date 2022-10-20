cmake_minimum_required(VERSION 3.20)

project(Tetris VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (APPLE)
    set(CMAKE_PREFIX_PATH "~/Qt/5.15.2/clang_64")
else()
    set(CMAKE_PREFIX_PATH "C:/Qt/5.15.2/msvc2019_64/lib/cmake")
endif ()

include_directories(inc)
aux_source_directory(src SRC_LIST)
aux_source_directory(inc INC_LIST)


find_package(Qt5 COMPONENTS Widgets Core Gui REQUIRED)

if (APPLE)
    add_executable(${PROJECT_NAME}
            src/NextShape.h
            src/DisplayWidget.h
            src/Shape.h
            src/ShapeFactory.h
            src/DisplayWidget.cpp
            src/main.cpp
            src/NextShape.cpp
            src/Shape.cpp
            src/Button.h src/Button.cpp src/mainwindow.h src/mainwindow.cpp src/ScoreWidget.cpp src/ScoreWidget.h src/Coor.h src/ShapeFactory.cpp)
else()
    add_executable(${PROJECT_NAME} WIN32
            src/NextShape.h
            src/DisplayWidget.h
            src/Shape.h
            src/ShapeFactory.h
            src/DisplayWidget.cpp
            src/main.cpp
            src/NextShape.cpp
            src/Shape.cpp
            src/Button.h src/Button.cpp src/mainwindow.h src/mainwindow.cpp src/ScoreWidget.cpp src/ScoreWidget.h src/Coor.h src/ShapeFactory.cpp)
endif()


target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Gui)

install(TARGETS Tetris
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})