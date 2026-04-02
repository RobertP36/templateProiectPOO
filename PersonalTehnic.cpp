#include "PersonalTehnic.h"

PersonalTehnic::PersonalTehnic(const std::string& nume, int id, const std::string& spec, int ani)
    : AngajatAeroport(nume, id), specializare(spec), aniExperienta(ani) {}

void PersonalTehnic::afiseazaAtributii() const {
    std::cout << "Atributii Tehnice: Verificarea sistemelor si mentenanta aeronavelor (Specializare: " 
              << specializare << ").\n";
}

void PersonalTehnic::afisare() const {
    AngajatAeroport::afisare(); 
    std::cout << "Specializare: " << specializare 
              << " | Experienta: " << aniExperienta << " ani\n";
}