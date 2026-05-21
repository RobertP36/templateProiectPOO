#ifndef ANGAJATFACTORY_H
#define ANGAJATFACTORY_H

#include "AngajatAeroport.h"
#include "Pilot.h"
#include "Stewardesa.h"
#include "PersonalSecuritate.h"
#include "PersonalTehnic.h"
#include <memory>
#include <string>
#include <stdexcept>


class AngajatFactory {
public:
    static std::unique_ptr<AngajatAeroport> creeaza(
        const std::string& tip,
        const std::string& nume,
        int id)
    {
        if (tip == "pilot")
            return std::make_unique<Pilot>(nume, id);           
        if (tip == "stewardesa")
            return std::make_unique<Stewardesa>(nume, id);     
        if (tip == "securitate")
            return std::make_unique<PersonalSecuritate>(nume, id); 
        if (tip == "tehnic")
            return std::make_unique<PersonalTehnic>(nume, id);  

        throw std::invalid_argument("Tip de angajat necunoscut: " + tip);
    }

    static std::unique_ptr<Pilot> creeazaPilot(
        const std::string& nume, int id,
        int oreZbor, const std::string& licenta)
    {
        return std::make_unique<Pilot>(nume, id, oreZbor, licenta);
    }

    static std::unique_ptr<Stewardesa> creeazaStewadesa(
        const std::string& nume, int id, int nrZboruri)
    {
        return std::make_unique<Stewardesa>(nume, id, nrZboruri);
    }

    static std::unique_ptr<PersonalSecuritate> creeazaSecuritate(
        const std::string& nume, int id,
        const std::string& zona, bool areArma)
    {
        return std::make_unique<PersonalSecuritate>(nume, id, zona, areArma);
    }

    static std::unique_ptr<PersonalTehnic> creeazaTehnic(
        const std::string& nume, int id,
        const std::string& specializare, int aniExperienta)
    {
        return std::make_unique<PersonalTehnic>(nume, id, specializare, aniExperienta);
    }
};

#endif
