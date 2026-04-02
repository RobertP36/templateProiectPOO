#include "Meniu.h"
#include "Pilot.h"
#include "OfiterOperatiuni.h"
#include "Stewardesa.h"
#include "PersonalSecuritate.h"
#include "PersonalTehnic.h"
#include "Exceptii.h"
#include <iostream>

// Implementare Meniu
void Meniu::afiseazaOptiuni() const {
    std::cout << "\n    Sistem Gestiune Aeroport    \n";
    std::cout << "1. Adauga Avion\n";
    std::cout << "2. Adauga Angajat (Pilot/Ofiter)\n";
    std::cout << "3. Creaza Zbor Nou\n";
    std::cout << "4. Afiseaza Toate Zborurile\n";
    std::cout << "5. Sterge Zbor\n";
    std::cout << "6. Adauga Pasager in Zbor\n";
    std::cout << "7. Actualizeaza Ore Pilot\n";
    std::cout << "8. Afiseaza tot personalul\n";
    std::cout << "0. Iesire\n";
    std::cout << "Optiune: ";
}

void Meniu::run() {
    int optiune = -1;
    while (optiune != 0) {
        afiseazaOptiuni();
        if (!(std::cin >> optiune)) {
                        std::cout << "\nInput terminat sau eroare. Inchidere program...\n";
            break; 
        }

        try {
            switch (optiune) {
                case 1: adaugaAvion(); break;
                case 2: adaugaAngajat(); break;
                case 3: creazaZbor(); break;
                case 4: 
                    for(const auto* z : zboruri) z->afisareDetaliiZbor(); 
                    break;
                case 5: stergeZbor(); break;
                case 6: adaugaPasagerInZbor(); break;
                case 7: actualizeazaOrePilot(); break;
                case 8: afiseazaTotPersonalul(); break;
                case 0: std::cout << "La revedere!\n"; break;
                default: std::cout << "Optiune invalida!\n";
            }
        } catch (const std::exception& e) {
            std::cerr << "EROARE: " << e.what() << std::endl;
        }
    }
}

void Meniu::adaugaAvion() {
    std::string model;
    int cap, serie;
    std::cout << "Model avion: "; std::cin >> model;
    std::cout << "Capacitate: "; std::cin >> cap;
    std::cout << "Serie motor: "; std::cin >> serie;
    flota.push_back(new Avion(model, cap, serie));
    std::cout << "Avion adaugat cu succes!\n";
}

void Meniu::adaugaAngajat() {
    int tip;
    std::string nume;
    int id;
    std::cout << "\n--- Adaugare Angajat ---\n";
    std::cout << "1. Pilot\n2. Ofiter Operatiuni (DIAMANT)\n3. Stewardesa\n";
    std::cout << "4. Personal Securitate\n5. Personal Tehnic\n";
    std::cout << "Optiune: "; std::cin >> tip;
    
    std::cout << "Nume: "; std::cin >> nume;
    std::cout << "ID: "; std::cin >> id;
    if (id < 0) {
        throw IDInvalidException();
    }

    if (tip == 1) {
        int ore; std::string lic;
        std::cout << "Ore zbor: "; std::cin >> ore;
        std::cout << "Licenta: "; std::cin >> lic;
        personal.push_back(new Pilot(nume, id, ore, lic));
    } 
    else if (tip == 2) {
        int nivel;
        std::cout << "Nivel autorizare (1-5): "; std::cin >> nivel;
        personal.push_back(new OfiterOperatiuni(nume, id, nivel));
    } 
    else if (tip == 3) {
        int nrZ;
        std::cout << "Nr. zboruri efectuate: "; std::cin >> nrZ;
        personal.push_back(new Stewardesa(nume, id, nrZ));
    }
    else if (tip == 4) {
        std::string zona; bool arma;
        std::cout << "Zona deservita: "; std::cin >> zona;
        std::cout << "Are arma? (1-Da, 0-Nu): "; std::cin >> arma;
        personal.push_back(new PersonalSecuritate(nume, id, zona, arma));
    }
    else if (tip == 5) {
        std::string spec; int ani;
        std::cout << "Specializare: "; std::cin >> spec;
        std::cout << "Ani experienta: "; std::cin >> ani;
        personal.push_back(new PersonalTehnic(nume, id, spec, ani));
    }

    std::cout << "Angajat adaugat cu succes!\n";
}


void Meniu::creazaZbor() {
    if (flota.empty() || personal.empty()) {
        std::cout << "Eroare: Aveti nevoie de cel putin un avion si un angajat (Pilot) pentru a crea un zbor!\n";
        return;
    }

    std::string cod;
    std::cout << "Cod Zbor: "; std::cin >> cod;
    
    Pilot* p = dynamic_cast<Pilot*>(personal[0]);
    if (p) {
        zboruri.push_back(new Zbor(cod, flota[0], p));
        std::cout << "Zbor creat cu succes!\n";
    } else {
        std::cout << "Eroare: Primul angajat din lista nu este Pilot!\n";
    }
}

void Meniu::adaugaPasagerInZbor() {
    if (zboruri.empty()) {
        std::cout << "Eroare: Nu exista niciun zbor creat!\n";
        return;
    }

    std::string numeP, pasaport;
    int varsta;
    std::cout << "Nume pasager: "; std::cin >> numeP;
    std::cout << "Nr. Pasaport: "; std::cin >> pasaport;
    std::cout << "Varsta: "; std::cin >> varsta;

    Pasager nou(numeP, pasaport, varsta);

    try {
        zboruri[0]->adaugaPasager(nou); 
        std::cout << "Pasager adaugat cu succes in zborul " << 0 << "!\n";
    } catch (const CapacitateDepasitaException& e) {
        // Aceasta este "catch"-ul care va prinde eroarea ta!
        std::cerr << "\n!!! " << e.what() << " !!!\n";
    }
}

void Meniu::stergeZbor() {
    if (zboruri.empty()) {
        std::cout << "Nu exista zboruri de sters.\n";
        return;
    }
    
    delete zboruri.back(); 
    zboruri.pop_back();
    std::cout << "Ultimul zbor a fost sters.\n";
}

void Meniu::actualizeazaOrePilot() {
    int idCautat, oreNoi;
    std::cout << "Introduceti ID-ul pilotului: ";
    std::cin >> idCautat;

    bool gasit = false;
    for (auto* angajat : personal) {
        // Încercăm să vedem dacă angajatul este un Pilot (Downcasting)
        Pilot* p = dynamic_cast<Pilot*>(angajat);
        
        if (p && p->getID() == idCautat) {
            std::cout << "Pilot gasit! Introduceti noul numar de ore de zbor: ";
            std::cin >> oreNoi;
            p->setOreZbor(oreNoi);
            std::cout << "Ore actualizate cu succes!\n";
            gasit = true;
            break;
        }
    }

    if (!gasit) {
        std::cout << "Pilotul cu ID-ul " << idCautat << " nu a fost gasit sau nu este Pilot.\n";
    }
}
void Meniu::afiseazaTotPersonalul() const {
    if (personal.empty()) {
        std::cout << "Nu exista angajati inregistrati in sistem.\n";
        return;
    }

    std::cout << "\n LISTA PERSONAL AEROPORT \n";
    for (const auto* angajat : personal) {
        angajat->afisare(); 
        std::cout << "Final lista de personal\n";
    }
}

Meniu::~Meniu() {
    // Eliberare - memory leaks
    for (auto a : personal) delete a;
    for (auto v : flota) delete v;
    for (auto z : zboruri) delete z;
}