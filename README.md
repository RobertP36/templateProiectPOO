# Platforma Management Aeroport

Aplicatia simuleaza un sistem de management al unui aeroport printr-un meniu interactiv in terminal.

Proiectul este impartit in mai multe fisiere .h si .cpp:

# Ierarhie de Mostenire

Clasa de baza abstracta este AngajatAeroport, din care deriva PersonalSecuritate + PersonalTehnic prin mostenire virtuala, Pilot si Stewardesa cu una simpla. OfiterOperatiuni mosteneste PersonalSecuritate + PersonalTehnic, ce rezulta clasa diamant, prin mostenirea clasei de baza

# Mostenire in Diamant

OfiterOperatiuni mosteneste virtual PersonalSecuritate + PersonalTehnic din AngajatAeroport. Deci se evita duplicarea instantei clasei de baza.

# Clase Abstracte si Polimorfism

Am folosit o metoda virtuala pura in clasa de baza ca sa fiu sigur ca fiecare clasa derivata are propria implementare. Metoda afisare() este suprascrisa polimorfic in fiecare clasa derivata. Vectorii din clasa Meniu stockeaza pointeri la clasa de baza si apelurile cu dinamic runtime.

# Encapsulare

Toti membrii de date sunt private/protected. Accesul extern se face exclusiv prin metode publice. Modificatorii de acces sunt folositi in toate clasele.

# Regula Celor 3

Clasa Avion gestioneaza o resursa alocata dinamic = pointer la seria motorului. Foloseste constructorul de copiere + operatorul de atribuire + destructorul, pentru a nu avea memory leaks.

# Membrii Statici

Clasa Zbor contine membrul static contorZboruri, care numara toate obiectele de tip Zbor create in terminal.

# Exceptii Personalizate

Exceptiile sunt definite in Exceptii.h si deriva din std::runtime_error. CapacitateDepasitaException se activeaza cand numarul de pasageri depaseste capacitatea maxima a avionului. IDInvalidException se activeaza cand ID-ul unui angajat este un numar sub zero.

# Downcasting

In clasa Meniu se foloseste dynamic_cast pentru a identifica obiectele de tip Pilot dintr-un vector de pointeri la clasa de baza AngajatAeroport,pt actualizarea orelor de zbor.

# Meniu Interactiv

Clasa Meniu are ca optiuni: adaugarea unui avion in flota, adaugarea unui angajat de orice tip, crearea unui zbor nou, afisarea tuturor zborurilor, stergerea ultimului zbor, adaugarea unui pasager intr-un zbor, actualizarea orelor de zbor ale unui pilot si afisarea intregului personal inregistrat.

