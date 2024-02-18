cmake_minimum_required(VERSION 3.28)
project(Clock)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "D:/IDE/Qt/6.7.0/msvc2019_64")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(Clock
        res/resources.qrc
        res/icon/app.rc
        src/main.cxx
        src/mainwindow/mainwindow.cxx
        src/mainwindow/mainwindow.hxx
)

target_link_libraries(Clock
        Qt::Core
        Qt::Gui
        Qt::Widgets
)
