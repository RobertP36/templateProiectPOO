#ifndef ANGAJATAEROPORT_H
#define ANGAJATAEROPORT_H

#include <string>
#include <iostream>

class AngajatAeroport {
protected:
    std::string nume;
    int idAngajat;

public:
    AngajatAeroport(const std::string& nume = "Anonim", int id = 0);
    virtual ~AngajatAeroport() {} //polimorfism
    int getID() const { return idAngajat; }
    // clasa abstractă
    virtual void afiseazaAtributii() const = 0; 

    virtual void afisare() const;
};

#endif