#ifndef IOBSERVER_H
#define IOBSERVER_H

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>


class IObserver {
public:
    virtual ~IObserver() = default;
    virtual void onNotificare(const std::string& eveniment,
                              const std::string& detalii) = 0;
};

class ISubject {
public:
    virtual ~ISubject() = default;
    virtual void adaugaObserver(IObserver* obs) = 0;
    virtual void stergeObserver(IObserver* obs) = 0;
    virtual void notificaObservatori(const std::string& eveniment,
                                     const std::string& detalii) = 0;
};

class LoggerZbor : public IObserver {
private:
    std::string m_numeLogger;
public:
    explicit LoggerZbor(const std::string& nume = "Logger")
        : m_numeLogger(nume) {}

    void onNotificare(const std::string& eveniment,
                      const std::string& detalii) override {
        std::cout << "[LOG - " << m_numeLogger << "] "
                  << eveniment << ": " << detalii << "\n";
    }
};

class AlertaIntarziere : public IObserver {
public:
    void onNotificare(const std::string& eveniment,
                      const std::string& detalii) override {
        if (eveniment == "INTARZIERE") {
            std::cout << "    ALERTA INTARZIERE: " << detalii << "\n";
        }
    }
};

class SubjectZbor : public ISubject {
private:
    std::vector<IObserver*> m_observatori;

public:
    void adaugaObserver(IObserver* obs) override {
        m_observatori.push_back(obs);
    }

    void stergeObserver(IObserver* obs) override {
        m_observatori.erase(
            std::remove(m_observatori.begin(), m_observatori.end(), obs),
            m_observatori.end());
    }

    void notificaObservatori(const std::string& eveniment,
                             const std::string& detalii) override {
        for (auto* obs : m_observatori)
            obs->onNotificare(eveniment, detalii);
    }
};

#endif
