#include "Pasager.h"

Pasager::Pasager(const std::string& nume, const std::string& pasaport, int varsta) 
    : nume(nume), nrPasaport(pasaport), varsta(varsta) {}

void Pasager::afisare() const {
    std::cout << "Pasager: " << nume 
              << " | Pasaport: " << nrPasaport 
              << " | Varsta: " << varsta << " ani" << std::endl;
}