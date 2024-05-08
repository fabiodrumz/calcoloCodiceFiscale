#include <iostream>
#include <string>
#include <cmath>
#include <vector>


using namespace std;

    

    // Parte del codice fiscale derivata dalla data di nascita
    codiceFiscale += to_string(anno % 100); // Anno solo con le ultime due cifre
    codiceFiscale += (mese < 10) ? '0' + to_string(mese) : to_string(mese); // Mese
    codiceFiscale += (giorno < 10) ? '0' + to_string(giorno) : to_string(giorno); // Giorno
    

    // Parte del codice fiscale derivata dal sesso
    codiceFiscale += sesso;
    
    return codiceFiscale;

}

int main() {

    string nome, cognome;
    int giorno, mese, anno;
    char sesso;

    cout << "Inserisci il nome: ";
    cin >> nome;
    cout << "Inserisci il cognome: ";
    cin >> cognome;
    cout << "Inserisci il giorno di nascita: ";
    cin >> giorno;
    cout << "Inserisci il mese di nascita: ";
    cin >> mese;
    cout << "Inserisci l'anno di nascita: ";
    cin >> anno;
    cout << "Inserisci il sesso (M per maschio, F per femmina): ";
    cin >> sesso;

    string codiceFiscale = calcolaCodiceFiscale(nome, cognome, giorno, mese, anno, sesso);
    cout << "Il codice fiscale calcolato è: " << codiceFiscale << endl;

    return 0;

}