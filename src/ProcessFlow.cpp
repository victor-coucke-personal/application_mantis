#include "ProcessFlow.h"
#include <iostream>

ProcessFlow::~ProcessFlow() {
    for (Station* station : stations) {
        delete station;  // Ensure memory cleanup
    }
}

void ProcessFlow::addStation(Station* station) {
    stations.push_back(station);
    stationCounter[station->getName()] = 0;
}

int ProcessFlow::processMaterial(int material) {
    int processedMaterial = material;
    for (size_t i = 0; i < stations.size(); ++i) {
        stationCounter[stations[i]->getName()]++;
        processedMaterial = stations[i]->process(processedMaterial);
    }
    return processedMaterial;
}

void ProcessFlow::showStationUsage() const {
    for (const auto& entry : stationCounter) {
        std::cout << "Station " << entry.first << " has been called " << entry.second << " times.\n"; 
    }
}
