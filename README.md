Platforma Gestiune Aeroport - Proiect POO
Acest proiect reprezinta un sistem de gestiune pentru un aeroport, dezvoltat in C++, utilizand principiile Programarii Orientate pe Obiecte (POO).

Functionalitati
    Gestiune Flota: Adaugarea si evidenta avioanelor (model, capacitate, serie motor).
    Gestiune Personal: Administrarea angajatilor (Piloti, Stewardese, Ofiteri, Personal Tehnic si Securitate).
    Management Zboruri: Crearea de zboruri prin asocierea avioanelor cu personalul disponibil.
    Sistem de Pasageri: Adaugarea pasagerilor cu verificare automata a capacitatii locurilor.
    Meniu Interactiv: Interfata in consola pentru utilizator. 

Concepte POO Implementate
    Mostenire si Polimorfism: Ierarhie de clase pentru angajati cu functii virtuale (afisare).
    Mostenire Multipla (Diamant): Rezolvata prin utilizarea virtual public in clasa OfiterOperatiuni.
    Incapsulare: Utilizarea modificatorilor de acces (private, protected) si a metodelor de tip Getter/Setter.
    Gestiune Resurse (Rule of 3): Implementata in clasa Avion pentru gestionarea memoriei alocate dinamic (pointeri).
    Tratarea Exceptiilor: Validarea datelor prin try-catch (ex: CapacitateDepasitaException, IDInvalidException).
    Clase Abstracte: Utilizarea interfetelor pentru a forta implementarea metodelor specifice in clasele derivate.

Autor
    Nume: Petrescu Robert
    Grupa: 143
