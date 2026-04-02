#ifndef PASAGER_H
#define PASAGER_H

#include <string>
#include <iostream>

class Pasager {
private:
    std::string nume;
    std::string nrPasaport;
    int varsta;

public:
    explicit Pasager(const std::string& nume = "Necunoscut", const std::string& pasaport = "N/A", int varsta = 0);

    ~Pasager() = default;

    // Getters pentru încapsulare
    //std::string getNume() const { return nume; }
    //std::string getPasaport() const { return nrPasaport; }
    //int getVarsta() const { return varsta; }

    void afisare() const;
};

#endif