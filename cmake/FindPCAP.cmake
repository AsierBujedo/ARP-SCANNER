find_path(PCAP_INCLUDE_DIR
    NAMES pcap.h
    HINTS
        ${CMAKE_SOURCE_DIR}/external/pcap
        /usr/include
)

find_library(PCAP_LIBRARY
    NAMES pcap
    HINTS
        ${CMAKE_SOURCE_DIR}/external/pcap
        /usr/lib
)

if(PCAP_INCLUDE_DIR AND PCAP_LIBRARY)
    set(PCAP_FOUND TRUE)
    set(PCAP_INCLUDE_DIRS ${PCAP_INCLUDE_DIR})
    set(PCAP_LIBRARIES ${PCAP_LIBRARY})
else()
    set(PCAP_FOUND FALSE)
endif()

mark_as_advanced(PCAP_INCLUDE_DIR PCAP_LIBRARY)
