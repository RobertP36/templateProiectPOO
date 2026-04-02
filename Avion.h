#ifndef AVION_H
#define AVION_H

#include <string>
#include <iostream>

class Avion {
private:
    std::string model;
    int capacitateMaxima;
    int* serieMotor; // Resursă alocata dinamic - Regula celor 3

public:
    explicit Avion(const std::string& model = "Necunoscut", int cap = 0, int serie = 0);
    
    // Regula celor 3
    virtual ~Avion();                             // Destructor 
    Avion(const Avion& ot);              // Constructor de copiere 
    Avion& operator=(const Avion& ot);   // Operator de atribuire 

    int getCapacitate() const { return capacitateMaxima; }
    
    //void setCapacitate(int cap) { capacitateMaxima = cap; }
    //std::string getModel() const { return model; }

    virtual void afisare() const; 
};

#endif