cmake_minimum_required(VERSION 3.21)
project(QtApp)
enable_testing()  # abilita i test

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Trova i pacchetti Qt6 richiesti
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Multimedia Test)

# Abilita AUTOMOC, AUTOUIC, AUTORCC prima di add_executable
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Aggiungi il file di risorse (prima di add_executable)
qt_add_resources(RESOURCE_FILES resources.qrc)

# Aggiungi i file sorgente
add_executable(QtApp
        main.cpp
        homewindow.cpp
        timerwindow.cpp
        countdownwindow.cpp
        timerlogic.cpp
        globalusage.cpp
        ${RESOURCE_FILES}
)

# Collega le librerie Qt
target_link_libraries(QtApp PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets Qt6::Multimedia)

add_executable(tests
        test/test_timerlogic.cpp
        countdownwindow.cpp
        timerlogic.cpp
        globalusage.cpp
)

target_link_libraries(tests
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
        Qt6::Test
        Qt6::Multimedia
)
add_test(NAME AllTests COMMAND tests)