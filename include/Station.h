#ifndef STATION_H
#define STATION_H

#include <string>

const std::string validChars = "ABCD->";  // Constant string containing valid station characters

// Base class for stations
class Station {
public:
    // Constructor and destructor defined inside the class as they're trivial
    Station() = default;
    virtual ~Station() = default;

    // Pure virtual function to be defined in derived classes
    virtual int process(int material) = 0;
    
    // Accessor for the name, trivial function defined inside the class
    virtual std::string getName() const = 0;
};

// Derived classes for StationA, StationB, StationC, and StationD

class StationA : public Station {
public:
    int process(int material) override;  // Declaration, to be defined in Station.cpp
    std::string getName() const override { return "A"; }  // Trivial definition inside the class
};

class StationB : public Station {
public:
    int process(int material) override;  // Declaration, to be defined in Station.cpp
    std::string getName() const override { return "B"; }
};

class StationC : public Station {
public:
    int process(int material) override;  // Declaration, to be defined in Station.cpp
    std::string getName() const override { return "C"; }
};

class StationD : public Station {
    Station* prevStation;
public:
    StationD(Station* prev) : prevStation(prev) {}  // Constructor defined inline
    int process(int material) override;  // Declaration, to be defined in Station.cpp
    std::string getName() const override { return "D"; }
};

#endif // STATION_H
