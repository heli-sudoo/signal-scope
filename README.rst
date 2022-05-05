Introduction
============
signal-scope is a live plotting tool for LCM message fields.


Build Instructions
==================

The required system dependencies are:

  - LCM 1.0 or greater
  - Qt 4.8
  - Qwt 6.0 or greater
  - Python 2.7

To install dependencies on Ubuntu::

    sudo apt-get install python-dev libqt4-dev libqwt-dev

To install dependencies on Mac homebrew::

    brew install qt qwt

Next install LCM from source if you don't already have it.
Visit the lcm webpage: https://lcm-proj.github.io/build_instructions.html

Finally, to build the signal-scope software, run::

    make externals
    make

The output will be build/bin/signal-scope.


Examples
========

See the examples directory for scripts demonstrating
the basic usage of signal-scope.  Launch a python
script by using the File --> Open menu or by passing
the script filename on the command line to signal-scope.

Qt5
===

To work with Qt5 and Ubuntu20.04

    sudo apt-get install python-dev-is-python3(2) qtbase5-dev qtscript5-dev qttools5-dev qtmultimediat5-dev libqwt-qt5-dev qtbase5-private-dev

Modify top `CMakelists.txt`

Add

    set(USED_QTVERSION 5)

Modify `CMakelist.txt` under `externals`

Change

    find_package(Qt4 4.8 REQUIRED)

    set(qt_args -DQT_QMAKE_EXECUTABLE:PATH=${QT_QMAKE_EXECUTABLE})

To

    set(qt_args -DQt5_DIR:PATH=${home}/Qt/5.12.2/gcc_64/lib/cmake/Qt5)


Use `GIT_TAG GIT_TAG patched-9` for `PythonQt`

Use `GIT_TAG add-qt5-support` for `ctkPythonConsole`


Go to `src/signal_scope`, modify `CMakelists.txt` as follows

Change

    if("${USED_QTVERSION}" STRGREATER_EQUAL "5")
      find_package(Qt5 REQUIRED Core Gui Script Widgets)
      set(QT_LIBRARIES Qt5::Core Qt5::Gui Qt5::Script Qt5::Widgets)
      # Compatibility macros
      macro(qt4_wrap_cpp)
        qt5_wrap_cpp(${ARGN})
      endmacro()
      macro(qt4_wrap_ui)
        qt5_wrap_ui(${ARGN})
      endmacro()
      macro(qt4_add_resources)
        qt5_add_resources(${ARGN})
      endmacro()
      if(APPLE)
        find_library(QWT_LIBRARY qwt)
      else()
        find_library(QWT_LIBRARY qwt-qt5)
      endif()
    else()
      find_library(QWT_LIBRARY qwt-qt)
      find_package(Qt4 REQUIRED QtCore QtGui QtScript)
    endif()

To

    if("${USED_QTVERSION}" STREQUAL "5")
      find_package(Qt5 REQUIRED Core Gui Script Widgets)
      set(QT_LIBRARIES Qt5::Core Qt5::Gui Qt5::Script Qt5::Widgets)
      set(QT_INCLUDE_DIR ${Qt5Widgets_INCLUDE_DIRS} ${Qt5Script_INCLUDE_DIRS})
      # Compatibility macros
      macro(qt4_wrap_cpp)
        qt5_wrap_cpp(${ARGN})
      endmacro()
      macro(qt4_wrap_ui)
        qt5_wrap_ui(${ARGN})
      endmacro()
      macro(qt4_add_resources)
        qt5_add_resources(${ARGN})
      endmacro()
      if(APPLE)
        find_library(QWT_LIBRARY qwt)
      else()
        find_library(QWT_LIBRARY qwt-qt5)
      endif()
    else()
      find_library(QWT_LIBRARY qwt-qt5)
      find_package(Qt5 REQUIRED Core Gui Script Widgets)
    endif()
    find_package(LCM REQUIRED)

Add 

    include_directories(${QT_INCLUDE_DIR})

Change

    qt4_wrap_cpp(...)
    qt4_wrap_ui(...)
    qt4_add_resources(...)

To

    qt5_wrap_cpp(...)
    qt5_wrap_ui(...)
    qt5_add_resources(...)
