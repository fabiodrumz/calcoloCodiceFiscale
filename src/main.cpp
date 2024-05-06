#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string calcolaCodiceFiscale(string nome, string cognome, int giorno, int mese, int anno, char sesso) {

    // Array di vocali per il calcolo del codice fiscale
    const char vocali[] = {'A', 'E', 'I', 'O', 'U'};
    
    // Costruzione del codice fiscale
    string codiceFiscale = "";
    
    // Parte del codice fiscale derivata dal cognome
    codiceFiscale += cognome.substr(0, 3);
    
    // Parte del codice fiscale derivata dal nome
    int contatore = 0;
    for (char lettera : nome) {
        if (contatore == 3)
            break;
        if (lettera != 'A' && lettera != 'E' && lettera != 'I' && lettera != 'O' && lettera != 'U') {
            codiceFiscale += lettera;
            contatore++;
        }
    }
    
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