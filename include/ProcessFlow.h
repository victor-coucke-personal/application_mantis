#ifndef PROCESSFLOW_H
#define PROCESSFLOW_H

#include <vector>
#include <map>
#include "Station.h"


class ProcessFlow {
    std::vector<Station*> stations;
    std::map<std::string, int> stationCounter;
    


public:
    // Constructor defined inline since it's trivial
    ProcessFlow() = default;

    // Trivial destructor
    ~ProcessFlow();

    void addStation(Station* station);
    int processMaterial(int material);
    void showStationUsage() const;
};

#endif // PROCESSFLOW_H
