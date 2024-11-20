cmake_minimum_required(VERSION 3.10)

project(ARPScanner)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB SOURCES "src/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})

find_package(Pcap REQUIRED)
include_directories(${PCAP_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${PCAP_LIBRARY})
