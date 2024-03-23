cmake_minimum_required(VERSION 3.5)

project(UrlEncoderDecoder VERSION 1.0.0 LANGUAGES CXX)

# Find the QtWidgets library
find_package(Qt5 COMPONENTS Widgets Core Gui REQUIRED)

# Tell CMake to run moc when necessary
set(CMAKE_AUTOMOC ON)
# As we are using QGuiApplication, which includes resources, enable automoc
set(CMAKE_AUTORCC ON)
# Automatic handling of uic (Qt User Interface Compiler)
set(CMAKE_AUTOUIC ON)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set the icon file for the macOS bundle
set(MACOSX_BUNDLE_ICON_FILE appicon.icns)
# Specify the path to the icon file relative to the project root
set(APP_ICON_MACOSX ${CMAKE_CURRENT_SOURCE_DIR}/resources/appicon.icns)
# Ensure the icon is included in the bundle
set_source_files_properties(${APP_ICON_MACOSX} PROPERTIES MACOSX_PACKAGE_LOCATION "Resources")

# When adding your executable, make sure to include the icon file if it's not already part of your sources
# Define the executable and its source files
add_executable(UrlEncoderDecoder
	MACOSX_BUNDLE
    main.cpp
    ${APP_ICON_MACOSX}
)

# Link the executable to the Qt5 widgets library
target_link_libraries(UrlEncoderDecoder Qt5::Widgets Qt5::Core Qt5::Gui)
