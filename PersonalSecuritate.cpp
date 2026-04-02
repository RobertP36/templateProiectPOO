#include "PersonalSecuritate.h"

PersonalSecuritate::PersonalSecuritate(const std::string& nume, int id, const std::string& zona, bool arma)
    : AngajatAeroport(nume, id), zonaDeservita(zona), areArma(arma) {}

void PersonalSecuritate::afiseazaAtributii() const {
    std::cout << "Atributii Securitate: Monitorizarea zonei " << zonaDeservita 
              << " si controlul accesului.\n";
}

void PersonalSecuritate::afisare() const {
    AngajatAeroport::afisare(); 
    std::cout << "Zona: " << zonaDeservita 
              << " | Inarmat: " << (areArma ? "Da" : "Nu") << "\n";
}