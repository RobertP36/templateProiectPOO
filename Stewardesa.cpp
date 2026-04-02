#include "Stewardesa.h"

Stewardesa::Stewardesa(const std::string& nume, int id, int nrZboruri) 
    : AngajatAeroport(nume, id), nrZboruriEfectuate(nrZboruri) {}

/*void Stewardesa::adaugaLimba(const std::string& limba) {
    limbiStraine.push_back(limba);
}*/

void Stewardesa::afiseazaAtributii() const {
    std::cout << "Atributii Stewardesa: Siguranta pasagerilor, servicii la bord si asistenta in timpul zborului.\n";
}

void Stewardesa::afisare() const {
    AngajatAeroport::afisare();
    std::cout << "Zboruri la activ: " << nrZboruriEfectuate << " | Limbi cunoscute: ";
    if (limbiStraine.empty()) {
        std::cout << "Niciuna";
    } else {
        for (const auto& limba : limbiStraine) {
            std::cout << limba << " ";
        }
    }
    std::cout << std::endl;
}