#include <iostream>
#include <pcap.h>

char errbuff[PCAP_ERRBUF_SIZE];

int main() {
    pcap_if_t *devices;

    if (pcap_findalldevs(&devices, errbuff) == -1) {
        std::cerr << "Error al obtener dispositivos: " << errbuff << std::endl;
        return 1;
    }

    std::cout << devices->name << std::endl;

    bpf_u_int32 netp;
    bpf_u_int32 maskp;

    if (pcap_lookupnet(devices->name, &netp, &maskp, errbuff) == -1) {
        std::cerr << "Error al buscar la red: " << errbuff << std::endl;
        pcap_freealldevs(devices);
        return 1;
    }

    std::cout << "Red: " << netp << std::endl;
    std::cout << "Máscara: " << maskp << std::endl;

    pcap_freealldevs(devices);

    return 0;
}
