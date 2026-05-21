#ifndef DEPOZIT_H
#define DEPOZIT_H

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <string>
#include <iostream>


template<typename T>
class Depozit {
private:
    std::vector<T> m_elemente;
    int m_capacitateMax;
    std::string m_nume;

    static int s_numarDepozite;

public:
    explicit Depozit(const std::string& nume, int capacitateMax)
        : m_capacitateMax(capacitateMax), m_nume(nume)
    {
        ++s_numarDepozite;
    }

    void adauga(const T& element) {
        if (static_cast<int>(m_elemente.size()) >= m_capacitateMax)
            throw std::overflow_error("Depozit plin: " + m_nume);
        m_elemente.push_back(element);
    }

    void sterge(int index) {
        if (index < 0 || index >= static_cast<int>(m_elemente.size()))
            throw std::out_of_range("Index invalid in depozit");
        m_elemente.erase(m_elemente.begin() + index);
    }

    T& get(int index) {
        if (index < 0 || index >= static_cast<int>(m_elemente.size()))
            throw std::out_of_range("Index invalid");
        return m_elemente[index];
    }

    const T& get(int index) const {
        if (index < 0 || index >= static_cast<int>(m_elemente.size()))
            throw std::out_of_range("Index invalid");
        return m_elemente[index];
    }

    template<typename Predicat>
    T* cauta(Predicat p) {
        auto it = std::find_if(m_elemente.begin(), m_elemente.end(), p);
        return (it != m_elemente.end()) ? &(*it) : nullptr;
    }

    void afiseazaTot() const {
        std::cout << "=== Depozit [" << m_nume << "] ("
                  << m_elemente.size() << "/" << m_capacitateMax << ") ===\n";
        for (int i = 0; i < static_cast<int>(m_elemente.size()); i++) {
            std::cout << "  [" << i << "] " << m_elemente[i] << "\n";
        }
    }

    int size() const { return static_cast<int>(m_elemente.size()); }
    bool estePlin() const { return size() >= m_capacitateMax; }
    bool esteGol()  const { return m_elemente.empty(); }
    const std::string& getNume() const { return m_nume; }

    static int getNumarDepozite() { return s_numarDepozite; }
};

template<typename T>
int Depozit<T>::s_numarDepozite = 0;

#endif
