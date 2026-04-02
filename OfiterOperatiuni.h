#ifndef OFITEROPERATIUNI_H
#define OFITEROPERATIUNI_H

#include "PersonalSecuritate.h"
#include "PersonalTehnic.h"


// CLASA DIAMANT
class OfiterOperatiuni : public PersonalSecuritate, public PersonalTehnic {
private:
    int nivelAutorizare;

public:
    // Constructorul
    explicit OfiterOperatiuni(const std::string& nume = "Anonim", int id = 0, int nivel = 1);

    // Suprascrierea metodei virtuale pure 
    void afiseazaAtributii() const override;

    // Suprascrierea metodei de afișare - includerea atributelor relevante
    void afisare() const override;

    ~OfiterOperatiuni() = default;
};

#endif