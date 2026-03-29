#include "Aeroport.h"
// Implementare angajati
AngajatAeroport::AngajatAeroport(std::string nume, int id) : nume(nume), idAngajat(id) {}

void AngajatAeroport::afisare() const {
    std::cout << "ID: " << idAngajat << " | Nume: " << nume << std::endl;
}

PersonalSecuritate::PersonalSecuritate(std::string nume, int id, std::string zona, bool arma)
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

PersonalTehnic::PersonalTehnic(std::string nume, int id, std::string spec, int ani)
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

OfiterOperatiuni::OfiterOperatiuni(std::string nume, int id, int nivel)
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

Pilot::Pilot(std::string nume, int id, int ore, std::string tipLicenta) 
    : AngajatAeroport(nume, id), oreZbor(ore), licenta(tipLicenta) {}

// Implementarea metodei polimorfice
void Pilot::afiseazaAtributii() const {
    std::cout << "Atributii Pilot: Operarea aeronavei, planificarea rutei si siguranta pasagerilor.\n";
}

void Pilot::afisare() const {
    AngajatAeroport::afisare(); 
    std::cout << "Licenta: " << licenta << " | Ore de zbor: " << oreZbor << "\n";
}

Stewardesa::Stewardesa(std::string nume, int id, int nrZboruri) 
    : AngajatAeroport(nume, id), nrZboruriEfectuate(nrZboruri) {}

void Stewardesa::adaugaLimba(const std::string& limba) {
    limbiStraine.push_back(limba);
}

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

// Implementare avion - Regula celor 3
Avion::Avion(std::string model, int cap, int serie) : model(model), capacitateMaxima(cap) {
    serieMotor = new int(serie); 
}

// Destructor 
Avion::~Avion() {
    delete serieMotor;
}

// Constructor de copiere 
Avion::Avion(const Avion& ot) {
    model = ot.model;
    capacitateMaxima = ot.capacitateMaxima;
    serieMotor = new int(*ot.serieMotor); 
}

// Operator de atribuire 
Avion& Avion::operator=(const Avion& ot) {
    if (this == &ot) return *this;
    
    delete serieMotor;
    
    model = ot.model;
    capacitateMaxima = ot.capacitateMaxima;
    serieMotor = new int(*ot.serieMotor);
    
    return *this;
}

void Avion::afisare() const {
    std::cout << "Avion model: " << model << " | Capacitate: " << capacitateMaxima 
              << " | Serie Motor: " << *serieMotor << std::endl;
}

// Implementare Zbor si Pasager
Pasager::Pasager(std::string nume, std::string pasaport, int varsta) 
    : nume(nume), nrPasaport(pasaport), varsta(varsta) {}

void Pasager::afisare() const {
    std::cout << "Pasager: " << nume 
              << " | Pasaport: " << nrPasaport 
              << " | Varsta: " << varsta << " ani" << std::endl;
}

int Zbor::contorZboruri = 0; 

Zbor::Zbor(std::string cod, Avion* a, Pilot* p) 
    : codZbor(cod), aeronava(a), capitan(p) {
    contorZboruri++;
}

int Zbor::getNrZboruri() {
    return contorZboruri;
}

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

// Implementare Meniu
void Meniu::afiseazaOptiuni() const {
    std::cout << "\n    Sistem Gestiune Aeroport    \n";
    std::cout << "1. Adauga Avion\n";
    std::cout << "2. Adauga Angajat (Pilot/Ofiter)\n";
    std::cout << "3. Creaza Zbor Nou\n";
    std::cout << "4. Afiseaza Toate Zborurile\n";
    std::cout << "5. Sterge Zbor\n";
    std::cout << "6. Adauga Pasager in Zbor\n";
    std::cout << "0. Iesire\n";
    std::cout << "Optiune: ";
}

void Meniu::run() {
    int optiune = -1;
    while (optiune != 0) {
        afiseazaOptiuni();
        std::cin >> optiune;

        try {
            switch (optiune) {
                case 1: adaugaAvion(); break;
                case 2: adaugaAngajat(); break;
                case 3: creazaZbor(); break;
                case 4: 
                    for(auto z : zboruri) z->afisareDetaliiZbor(); 
                    break;
                case 5: stergeZbor(); break;
                case 6: adaugaPasagerInZbor(); break;
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

Meniu::~Meniu() {
    // Eliberare - memory leaks
    for (auto a : personal) delete a;
    for (auto v : flota) delete v;
    for (auto z : zboruri) delete z;
}