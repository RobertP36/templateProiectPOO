#ifndef STEWARDESA_H
#define STEWARDESA_H

#include "AngajatAeroport.h"
#include <vector>
#include <string>

class Stewardesa : public AngajatAeroport {
private:
    std::vector<std::string> limbiStraine;
    int nrZboruriEfectuate;

public:
    explicit Stewardesa(const std::string& nume = "Anonim", int id = 0, int nrZboruri = 0);

    void adaugaLimba(const std::string& limba);

    void afiseazaAtributii() const override;

    void afisare() const override;

    ~Stewardesa() = default;
};

#endif