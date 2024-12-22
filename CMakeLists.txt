cmake_minimum_required(VERSION 3.10)
project(Database)

# Specify C++ standard (set to C++17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Optional strict mode
if(STRICT)
  message("-- Enabling strict compilation mode")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
endif()

# Include directories for your project
include_directories(${PROJECT_SOURCE_DIR})

# Add executables
add_executable(db main.cpp student.cpp db.cpp programHandler.cpp)
add_executable(test_exe test/test.cpp student.cpp db.cpp)

# Set C++ standard for the targets (C++17)
set_property(TARGET db PROPERTY CXX_STANDARD 17)
set_property(TARGET test_exe PROPERTY CXX_STANDARD 17)

# Include the Catch2 library for test_exe
target_include_directories(test_exe PRIVATE ${PROJECT_SOURCE_DIR}/test/catch2)

# Include cURL's header files for 'db' executable
target_include_directories(db PRIVATE ${CURL_INCLUDE_DIR})

# Link cURL and additional libraries to 'db' executable
target_link_libraries(db PRIVATE ${CURL_LIBRARY} ${ADDITIONAL_LIBS})
target_link_libraries(test_exe PRIVATE ${CURL_LIBRARY} ${ADDITIONAL_LIBS})  # If tests also require cURL
