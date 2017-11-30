cmake_minimum_required(VERSION 3.4)
project(FinalProject)


FIND_PACKAGE(Qt5Widgets)
FIND_PACKAGE(Qt5Gui)
FIND_PACKAGE(QT5OpenGL)
FIND_PACKAGE(VTK)
FIND_PACKAGE( OpenSceneGraph REQUIRED COMPONENTS osgDB osgGA osgUtil osgViewer osgText )
include(${VTK_USE_FILE})
INCLUDE_DIRECTORIES( ${OPENSCENEGRAPH_INCLUDE_DIRS} )

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED 1)

SET(CMAKE_INCLUDE_CURRENT_DIR ON)
SET(CMAKE_AUTOMOC ON)
SET(CMAKE_AUTOUIC ON)
SET(CMAKE_AUTORCC ON)

SET(MYSOURCE
    engine.h
    engine.cpp
    otto.h
    otto.cpp
    diesel.h
    diesel.cpp
    fourstroke.h
    fourstroke.cpp
    mainwindow.h
    mainwindow.cpp
    mainwindow.ui
    main.cpp
    graphoutputwidget.h
    graphoutputwidget.cpp
    )
add_executable(${PROJECT_NAME}
    ${MYSOURCE}
    ${MY_RES}
    )


target_link_libraries(${PROJECT_NAME}
    ${VTK_LIBRARIES}
    ${OPENSCENEGRAPH_LIBRARIES}
    Qt5::OpenGL
    Qt5::Widgets
    Qt5::Gui
)
