#include "OfiterOperatiuni.h"

OfiterOperatiuni::OfiterOperatiuni(const std::string& nume, int id, int nivel)
    : AngajatAeroport(nume, id), 
      PersonalSecuritate(nume, id), 
      PersonalTehnic(nume, id), 
      nivelAutorizare(nivel) {}

void OfiterOperatiuni::afiseazaAtributii() const {
    std::cout << "Atributii Ofiter Operatiuni (Sef de Tura):\n";
    std::cout << "- Supravegheaza protocoalele de securitate.\n";
    std::cout << "- Coordoneaza echipele de mentenanta la sol.\n";
}

void OfiterOperatiuni::afisare() const {
    // Apelăm afișarea de bază
    AngajatAeroport::afisare();
    std::cout << "Nivel Autorizare: " << nivelAutorizare << " (Acces Total)\n";
}