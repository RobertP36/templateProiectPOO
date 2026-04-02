#include "Avion.h"

// Implementare avion - Regula celor 3
Avion::Avion(const std::string& model, int cap, int serie) : model(model), capacitateMaxima(cap), serieMotor(new int(serie)) {}

// Destructor 
Avion::~Avion() {
    delete serieMotor;
}

// Constructor de copiere 
Avion::Avion(const Avion& ot) 
    : model(ot.model), 
    capacitateMaxima(ot.capacitateMaxima), 
    serieMotor(new int(*ot.serieMotor)) {}

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