project(QObjectProxyExample)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    Include/QObjectProxyExample/MyModelClass.h
    Src/MyModelClass.cpp

    Include/QObjectProxyExample/MyModelQObjectProxy.h
    Src/MyModelQObjectProxy.cpp
    )

add_library(${PROJECT_NAME} ${SOURCES})

set (UsedQtComponents Core)

find_package(Qt5 COMPONENTS
    ${UsedQtComponents}
    REQUIRED)

qt5_use_modules(${PROJECT_NAME} ${UsedQtComponents})

target_include_directories(${PROJECT_NAME} PUBLIC Include/)

add_subdirectory(Tests)
