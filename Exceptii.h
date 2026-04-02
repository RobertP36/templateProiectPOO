#ifndef EXCEPTII_H
#define EXCEPTII_H


#include <stdexcept>

class CapacitateDepasitaException : public std::runtime_error {
public:
    CapacitateDepasitaException() : std::runtime_error("Eroare: Capacitatea maxima a aeronavei a fost depasita!") {}
};
class IDInvalidException : public std::runtime_error {
public:
    IDInvalidException() : std::runtime_error("Eroare: ID-ul angajatului trebuie sa fie un numar pozitiv!") {}
};

#endif