#ifndef STATION_H
#define STATION_H

#include <iostream>

class Station {
public:
    virtual int process(int material) = 0;
    virtual ~Station() {}
    virtual std::string getName() const = 0;
};

class StationA : public Station {
public:
    int process(int material) override {
        return material + 1;
    }
    std::string getName() const override {
        return "A";
    }
};

class StationB : public Station {
public:
    int process(int material) override {
        return material - 1;
    }
    std::string getName() const override {
        return "B";
    }
};

class StationC : public Station {
public:
    int process(int material) override {
        if (material % 2 == 0) {
            std::cout << "Station C: Skipping next station, passing to the next after.\n";
            return -2;  // Indicates to skip the next station
        }
        return material;
    }
    std::string getName() const override {
        return "C";
    }
};

class StationD : public Station {
public:
    Station* prevStation;
    
    StationD(Station* prev) : prevStation(prev) {}
    
    int process(int material) override {
        return prevStation->process(material);  // Mimics the previous station
    }
    std::string getName() const override {
        return "D";
    }
};

#endif // STATION_H
