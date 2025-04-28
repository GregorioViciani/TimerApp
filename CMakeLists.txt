cmake_minimum_required(VERSION 3.21)
project(QtApp)

enable_testing()

# Usa CMake per gestire automaticamente i file .ui
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Trova i pacchetti Qt6 richiesti
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Multimedia Test Network)

# Abilita AUTOMOC, AUTOUIC, AUTORCC per Qt
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)


# Aggiungi i file di risorse
qt_add_resources(RESOURCE_FILES resources.qrc)

# File sorgente dell'app principale
set(SOURCE_FILES
        timerlogic.cpp
        homewindow.cpp
        timerwindow.cpp
        countdownwindow.cpp
        globalusage.cpp
)

# Header dell'app principale
set(HEADER_FILES
        timerlogic.h
        homewindow.h
        timerwindow.h
        countdownwindow.h
        globalusage.h
)

# Aggiungi i file .ui
set(UI_FILES
        countdownwindow.ui
        homewindow.ui
        timerwindow.ui
)

# Aggiungi l'eseguibile principale dell'app
add_executable(QtApp WIN32 main.cpp ${SOURCE_FILES} ${HEADER_FILES} ${RESOURCE_FILES} ${UI_FILES})

# Collega le librerie Qt all'app principale
target_link_libraries(QtApp PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets Qt6::Multimedia Qt6::Network)

# File di test
set(TEST_FILES
        tests/test_homewindow.cpp
        tests/test_timerlogic.cpp
        tests/test_all.cpp
        tests/test_timerwindow.cpp
        tests/test_countdownwindow.cpp
)

# Aggiungi l'eseguibile dei test
add_executable(tests ${TEST_FILES}  ${SOURCE_FILES} ${HEADER_FILES} ${UI_FILES})
# Collega le librerie Qt ai test
target_link_libraries(tests PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets Qt6::Test Qt6::Multimedia Qt6::Network)

# Registra i test
add_test(NAME AllTests COMMAND tests)

