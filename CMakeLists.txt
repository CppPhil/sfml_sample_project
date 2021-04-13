cmake_minimum_required(VERSION 3.15)

project(sfml_sample_project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Threads REQUIRED)

set(BUILD_SHARED_LIBS OFF CACHE BOOL "Build shared libraries" FORCE)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/external/SFML)

set(APP_NAME sfml_sample_app)

add_executable(${APP_NAME} src/main.cpp)

target_link_libraries(
  ${APP_NAME}
  PRIVATE
  Threads::Threads
  sfml-audio
  sfml-graphics
  sfml-network
  sfml-system
  sfml-window
)

if(WIN32)
  target_link_libraries(
    ${APP_NAME}
    PRIVATE
    sfml-main
  )
endif()
