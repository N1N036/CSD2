cmake_minimum_required(VERSION 3.17)
project(ProjectName)

include(FetchContent)

project(QJack)
cmake_minimum_required(VERSION 2.8)


include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(qjack)
add_subdirectory(examples)


add_executable(example ringbuffer.cpp reverb.cpp)

target_compile_features(example PRIVATE cxx_std_17)

target_link_libraries(example PRIVATE portaudio_static fmt::fmt)