#ifndef AEROPORT_H
#define AEROPORT_H

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <stdexcept>

// Exceptii
class CapacitateDepasitaException : public std::runtime_error {
public:
    CapacitateDepasitaException() : std::runtime_error("Eroare: Capacitatea maxima a aeronavei a fost depasita!") {}
};
class IDInvalidException : public std::runtime_error {
public:
    IDInvalidException() : std::runtime_error("Eroare: ID-ul angajatului trebuie sa fie un numar pozitiv!") {}
};

// Ierahie angajati - 6 clase si diamant
class AngajatAeroport {
protected:
    std::string nume;
    int idAngajat;

public:
    AngajatAeroport(std::string nume = "Anonim", int id = 0);
    virtual ~AngajatAeroport() {} //polimorfism

    // clasa abstractă
    virtual void afiseazaAtributii() const = 0; 

    virtual void afisare() const;
};

class PersonalSecuritate : virtual public AngajatAeroport {
protected:
    std::string zonaDeservita;
    bool areArma;

public:
    PersonalSecuritate(std::string nume = "Anonim", int id = 0, std::string zona = "Terminal", bool arma = false);
    
    void afiseazaAtributii() const override;
    
    void afisare() const override;

    virtual ~PersonalSecuritate() = default;
};

class PersonalTehnic : virtual public AngajatAeroport {
protected:
    std::string specializare;
    int aniExperienta;

public:
    PersonalTehnic(std::string nume = "Anonim", int id = 0, std::string spec = "General", int ani = 0);
    
    // metoda virtuala pura
    void afiseazaAtributii() const override;
    
    void afisare() const override;

    virtual ~PersonalTehnic() = default;
};

// CLASA DIAMANT
class OfiterOperatiuni : public PersonalSecuritate, public PersonalTehnic {
private:
    int nivelAutorizare;

public:
    // Constructorul
    OfiterOperatiuni(std::string nume = "Anonim", int id = 0, int nivel = 1);

    // Suprascrierea metodei virtuale pure 
    void afiseazaAtributii() const override;

    // Suprascrierea metodei de afișare - includerea atributelor relevante
    void afisare() const override;

    ~OfiterOperatiuni() = default;
};

class Pilot : public AngajatAeroport {
private:
    int oreZbor;
    std::string licenta;

public:
    // Constructor care apeleaza constructorul clasei de baza
    Pilot(std::string nume = "Necunoscut", int id = 0, int ore = 0, std::string tipLicenta = "PPL");
    // Polimorfism
    void afiseazaAtributii() const override;

    void afisare() const override;
    
    int getOreZbor() const { return oreZbor; }
    void setOreZbor(int ore) { oreZbor = ore; }
};

class Stewardesa : public AngajatAeroport {
private:
    std::vector<std::string> limbiStraine;
    int nrZboruriEfectuate;

public:
    Stewardesa(std::string nume = "Anonim", int id = 0, int nrZboruri = 0);

    void adaugaLimba(const std::string& limba);

    void afiseazaAtributii() const override;

    void afisare() const override;

    ~Stewardesa() = default;
};

//Clase Logistice
class Pasager {
private:
    std::string nume;
    std::string nrPasaport;
    int varsta;

public:
    Pasager(std::string nume = "Necunoscut", std::string pasaport = "N/A", int varsta = 0);

    ~Pasager() = default;

    // Getters pentru încapsulare
    std::string getNume() const { return nume; }
    std::string getPasaport() const { return nrPasaport; }
    int getVarsta() const { return varsta; }

    void afisare() const;
};

class Avion {
private:
    std::string model;
    int capacitateMaxima;
    int* serieMotor; // Resursă alocata dinamic - Regula celor 3

public:
    Avion(std::string model = "Necunoscut", int cap = 0, int serie = 0);
    
    // Regula celor 3
    virtual ~Avion();                             // Destructor 
    Avion(const Avion& ot);              // Constructor de copiere 
    Avion& operator=(const Avion& ot);   // Operator de atribuire 

    int getCapacitate() const { return capacitateMaxima; }
    
    void setCapacitate(int cap) { capacitateMaxima = cap; }
    std::string getModel() const { return model; }

    virtual void afisare() const; 
};

class Zbor {
private:
    static int contorZboruri;
    std::string codZbor;
    Avion* aeronava;
    Pilot* capitan;           
    std::vector<Pasager> pasageri;

public:
    Zbor(std::string cod = "", Avion* a = nullptr, Pilot* p = nullptr);
    
    static int getNrZboruri();

    // Metoda care validează datele
    void adaugaPasager(const Pasager& p);
    
    void afisareDetaliiZbor() const;
    
    ~Zbor() = default; 
};

// Meniu
class Meniu {
private:
    // pointeri clasa de baza - Polimorfism
    std::vector<AngajatAeroport*> personal;
    std::vector<Avion*> flota;
    std::vector<Zbor*> zboruri;

    void afiseazaOptiuni() const;
    void adaugaAvion();
    void adaugaAngajat();
    void creazaZbor();
    void stergeZbor();
    void adaugaPasagerInZbor();

public:
    Meniu() = default;
    ~Meniu(); // Destructor pentru gestionarea resurselor
    
    void run(); // Bucla meniu
};

#endif