#include "Pilot.h"

Pilot::Pilot(const std::string& nume, int id, int ore, const std::string& tipLicenta) 
    : AngajatAeroport(nume, id), oreZbor(ore), licenta(tipLicenta) {}

// Implementarea metodei polimorfice
void Pilot::afiseazaAtributii() const {
    std::cout << "Atributii Pilot: Operarea aeronavei, planificarea rutei si siguranta pasagerilor.\n";
}

void Pilot::afisare() const {
    AngajatAeroport::afisare(); 
    std::cout << "Ore de zbor: " << getOreZbor() << " | Tip Licenta: " << licenta << "\n";
}