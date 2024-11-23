#include<pcap.h>
#include<iostream>
#include<vector>
#include<devices.hpp>

char errbuff[PCAP_ERRBUF_SIZE];

std::vector<std::string> getAllAvailableDevices() {

    pcap_if_t* alldevs;
    pcap_if_t* device;

    if(pcap_findalldevs(&alldevs, errbuff) == 1) {
        std::cerr << "Could not find devices" << std::endl;
        return NULL;
    }

    std::cout << "Available devices are:" << std::endl;
    
    int count = 0;
    for (device = alldevs; device != nullptr; device->next) {
        count++;
        std::cout << count << ". " << device->name << std::endl;
    }
}


