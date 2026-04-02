#ifndef PERSONALTEHNIC_H
#define PERSONALTEHNIC_H

#include "AngajatAeroport.h"

class PersonalTehnic : virtual public AngajatAeroport {
protected:
    std::string specializare;
    int aniExperienta;

public:
    explicit PersonalTehnic(const std::string& nume = "Anonim", int id = 0, const std::string& spec = "General", int ani = 0);
    
    // metoda virtuala pura
    void afiseazaAtributii() const override;
    
    void afisare() const override;

    virtual ~PersonalTehnic() = default;
};

#endif