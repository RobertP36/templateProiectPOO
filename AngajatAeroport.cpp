#include "AngajatAeroport.h"
// Implementare angajati
AngajatAeroport::AngajatAeroport(const std::string& nume, int id) : nume(nume), idAngajat(id) {}

void AngajatAeroport::afisare() const {
    std::cout << "ID: " << idAngajat << " | Nume: " << nume << std::endl;
}