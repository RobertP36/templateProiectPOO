#ifndef MENIU_H
#define MENIU_H

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <stdexcept>
#include "Zbor.h"
#include "AngajatAeroport.h"
#include "Avion.h"

// Meniu
class Meniu {
private:
    // pointeri clasa de baza - Polimorfism
    std::vector<AngajatAeroport*> personal;
    std::vector<Avion*> flota;
    std::vector<Zbor*> zboruri;

    void afiseazaOptiuni() const;
    void adaugaAvion();
    void adaugaAngajat();
    void creazaZbor();
    void stergeZbor();
    void adaugaPasagerInZbor();
    void actualizeazaOrePilot();
    void afiseazaTotPersonalul() const;

public:
    Meniu() = default;
    ~Meniu(); // Destructor pentru gestionarea resurselor
    
    void run(); // Bucla meniu
};

#endif