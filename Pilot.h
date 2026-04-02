#ifndef PILOT_H
#define PILOT_H

#include "AngajatAeroport.h"
#include <string>

class Pilot : public AngajatAeroport {
private:
    int oreZbor;
    std::string licenta;

public:
    // Constructor care apeleaza constructorul clasei de baza
    explicit Pilot(const std::string& nume = "Necunoscut", int id = 0, int ore = 0, const std::string& tipLicenta = "PPL");
    // Polimorfism
    void afiseazaAtributii() const override;

    void afisare() const override;
    
    int getOreZbor() const { return oreZbor; }
    void setOreZbor(int ore) { oreZbor = ore; }
};

#endif