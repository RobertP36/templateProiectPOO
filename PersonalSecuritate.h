#ifndef PERSONALSECURITATE_H
#define PERSONALSECURITATE_H

#include "AngajatAeroport.h"

class PersonalSecuritate : virtual public AngajatAeroport {
protected:
    std::string zonaDeservita;
    bool areArma;

public:
    explicit PersonalSecuritate(const std::string& nume = "Anonim", int id = 0, const std::string& zona = "Terminal", bool arma = false);
    
    void afiseazaAtributii() const override;
    
    void afisare() const override;

    virtual ~PersonalSecuritate() = default;
};

#endif