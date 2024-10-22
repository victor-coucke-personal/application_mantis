#include "Station.h"
#include <iostream>


int StationA::process(int material) {
    return material + 1;
}

int StationB::process(int material) {
    return material - 1;
}

int StationC::process(int material) {
    if (material % 2 == 0) {
        std::cout << "Station C: Skipping next station.\n";
        return -2;  // Signal to skip the next station
    }
    return material;
}

int StationD::process(int material) {
    return prevStation->process(material);  // Mimics the previous station's behavior
}
