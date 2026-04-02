#ifndef ZBOR_H
#define ZBOR_H

#include <vector>
#include <string>
#include "Avion.h"
#include "Pilot.h"
#include "Pasager.h"
#include "Exceptii.h"

class Zbor {
private:
    static int contorZboruri;
    std::string codZbor;
    Avion* aeronava;
    Pilot* capitan;           
    std::vector<Pasager> pasageri;

public:
    explicit Zbor(const std::string& cod = "", Avion* a = nullptr, Pilot* p = nullptr);
    
    //static int getNrZboruri();

    // Metoda care validează datele
    void adaugaPasager(const Pasager& p);
    
    void afisareDetaliiZbor() const;
    
    ~Zbor() = default; 
};

#endif