#include "Aeroport.h"
#include <iostream>

int main() {
    try {
        // Meniu alocat pe stiva
        Meniu aeroport;

        std::cout << "      SISTEM MANAGEMENT AEROPORT        " << std::endl;

        // Bucla
        aeroport.run();

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