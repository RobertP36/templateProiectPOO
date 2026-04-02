#include "Zbor.h"

int Zbor::contorZboruri = 0; 

Zbor::Zbor(const std::string& cod, Avion* a, Pilot* p) 
    : codZbor(cod), aeronava(a), capitan(p) {
    contorZboruri++;
}

/*int Zbor::getNrZboruri() {
    return contorZboruri;
}*/

void Zbor::adaugaPasager(const Pasager& p) {
    if (aeronava == nullptr) {
        return;
    }

    // Utilizarea exceptiilor 
    if (pasageri.size() >= (size_t)aeronava->getCapacitate()) {
        throw CapacitateDepasitaException(); 
    }
    pasageri.push_back(p);
}

void Zbor::afisareDetaliiZbor() const {
    std::cout << "Zbor Cod: " << codZbor << "\n";
    if (aeronava) {
        aeronava->afisare(); 
    }
    if (capitan) {
        capitan->afiseazaAtributii();
    }
    std::cout << "Pasageri la bord: " << pasageri.size() << "\n";
}