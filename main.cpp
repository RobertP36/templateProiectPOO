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