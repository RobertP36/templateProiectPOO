#include "Meniu.h"
#include "Depozit.h"
#include "IObserver.h"
#include "AngajatFactory.h"
#include <iostream>

int main() {
    try {
        // Meniu alocat pe stiva
        Meniu aeroport;

        std::cout << "      SISTEM MANAGEMENT AEROPORT        " << std::endl;

        // Bucla
        aeroport.run();
        Depozit<std::string> ruteActive("Rute Active", 5);
        ruteActive.adauga("Bucuresti -> Paris");
        ruteActive.adauga("Bucuresti -> Londra");
        ruteActive.adauga("Bucuresti -> Berlin");
        std::cout << "Rute in depozit: " << ruteActive.size() << "\n";
        std::cout << "Ruta 0: " << ruteActive.get(0) << "\n";
        std::string* gasit = ruteActive.cauta(
        [](const std::string& r){ return r.find("Paris") != std::string::npos; });
        if (gasit)
        std::cout << "Gasita ruta spre Paris: " << *gasit << "\n";
        std::cout << "Total depozite create: "
        << Depozit<std::string>::getNumarDepozite() << "\n";
        std::cout << "\nProgramul s-a incheiat cu succes." << std::endl;

        std::cout << "\nFactory: AngajatFactory\n";
        
    auto pilot1 = AngajatFactory::creeazaPilot("Ion Ionescu", 201, 1500, "ATPL");
    pilot1->afisare();

    auto stew1 = AngajatFactory::creeazaStewadesa("Maria Popescu", 202, 80);
    stew1->afisare();

    auto sec1 = AngajatFactory::creeazaSecuritate("Gheorghe Popa", 203, "Poarta A", true);
    sec1->afisare();

    auto teh1 = AngajatFactory::creeazaTehnic("Alexandru Stan", 204, "Avionica", 5);
    teh1->afisare();

    auto generic = AngajatFactory::creeaza("pilot", "Test Pilot", 299);
    std::cout << "Creat prin factory generic: ";
    generic->afisare();

        std::cout << "\nObserver: SubjectZbor + LoggerZbor + AlertaIntarziere\n";

    SubjectZbor monitorizareZbor;
    LoggerZbor logger("Sistem-Log");
    AlertaIntarziere alerta;

    monitorizareZbor.adaugaObserver(&logger);
    monitorizareZbor.adaugaObserver(&alerta);

    monitorizareZbor.notificaObservatori("PLECARE",    "RO-201 Bucuresti->Paris, ora 10:30");
    monitorizareZbor.notificaObservatori("INTARZIERE", "RO-202 Bucuresti->Londra, +45 min");
    monitorizareZbor.notificaObservatori("ATERIZARE",  "RO-201 a aterizat la Paris");

    monitorizareZbor.stergeObserver(&alerta);
    monitorizareZbor.notificaObservatori("INTARZIERE", "RO-203 Bucuresti->Berlin, +20 min");
        
    } catch (const CapacitateDepasitaException& e) {
        // Gasim exceptia
        std::cerr << "\n[EROARE CRITICA]: " << e.what() << std::endl;
        return 0;
    } catch (const std::exception& e) {
        // Gasim eroare standard
        std::cerr << "\n[EROARE SISTEM]: " << e.what() << std::endl;
        return 0;
    } catch (...) {
        // Erori necunoscute
        std::cerr << "\n[EROARE]: A aparut o problema neasteptata." << std::endl;
        return 0;
    }

    return 0;
}
