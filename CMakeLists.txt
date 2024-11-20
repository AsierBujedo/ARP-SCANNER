cmake_minimum_required(VERSION 3.10)

project(ARPScanner VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

find_package(PCAP REQUIRED)
include_directories(${PCAP_INCLUDE_DIRS})
file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(ARPScanner ${SOURCES})
target_link_libraries(ARPScanner ${PCAP_LIBRARIES})
