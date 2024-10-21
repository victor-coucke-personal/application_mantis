#ifndef PROCESSFLOW_H
#define PROCESSFLOW_H

#include <vector>
#include <map>
#include "Station.h"

class ProcessFlow {
    std::vector<Station*> stations;
    std::map<std::string, int> stationCounter;
public:
    void addStation(Station* station) {
        stations.push_back(station);
        stationCounter[station->getName()] = 0;
    }

    int processMaterial(int material) {
        int processedMaterial = material;
        for (size_t i = 0; i < stations.size(); ++i) {
            stationCounter[stations[i]->getName()]++;
            processedMaterial = stations[i]->process(processedMaterial);

            if (processedMaterial == -2) { // If C says to skip next station
                ++i; // Skip the next station
            }
        }
        return processedMaterial;
    }

    void showStationUsage() const {
        for (const auto& entry : stationCounter) {
            std::cout << "Station " << entry.first << " has been called " << entry.second << " times.\n";
        }
    }
};

#endif // PROCESSFLOW_H
