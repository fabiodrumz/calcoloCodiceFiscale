#include <iostream>
#include <string>
#include <cctype>
#include <algorithm> // Per utilizzare la funzione transform

using namespace std;

// Funzione ausiliaria per contare le consonanti in una stringa
int contaConsonanti(const string& s) {
    const string vocali = "AEIOU";
    int count = 0;
    for (char c : s) {
        if (isalpha(c) && vocali.find(toupper(c)) == string::npos) {
            count++;
        }
    }
    return count;
}

// Funzione per calcolare il codice fiscale
string calcolaCodiceFiscale(const string& cognome, const string& nome, const string& dataNascita, char genere) {
    // Conversione delle stringhe in maiuscolo
    string cognomeMaiuscolo = cognome;
    string nomeMaiuscolo = nome;
    transform(cognomeMaiuscolo.begin(), cognomeMaiuscolo.end(), cognomeMaiuscolo.begin(), ::toupper);
    transform(nomeMaiuscolo.begin(), nomeMaiuscolo.end(), nomeMaiuscolo.begin(), ::toupper);

    // Estrazione delle consonanti dal cognome
    string consonantiCognome = "";
    for (char c : cognomeMaiuscolo) {
        if (isalpha(c) && string("BCDFGHJKLMNPQRSTVWXYZ").find(c) != string::npos) {
            consonantiCognome += c;
            if (consonantiCognome.length() == 3) {
                break;
            }
        }
    }

    // Estrazione delle consonanti dal nome
    string consonantiNome = "";
    int numConsonanti = 0;
    for (char c : nomeMaiuscolo) {
        if (isalpha(c) && string("BCDFGHJKLMNPQRSTVWXYZ").find(c) != string::npos) {
            consonantiNome += c;
            numConsonanti++;
            if (numConsonanti == 3) {
                break;
            }
        }
    }

    // Estrazione ultime due cifre dell'anno di nascita
    string anno = dataNascita.substr(2, 2);

    // Estrazione del mese di nascita
    const string mesi = "ABCDEHLMPRST";
    int mese = stoi(dataNascita.substr(5, 2));
    char meseNascita = mesi[mese - 1];

    // Estrazione del giorno di nascita (con eventuale aggiustamento per genere femminile)
    int giorno = stoi(dataNascita.substr(8, 2));
    if (genere == 'F') {
        giorno += 40;
    }
    string giornoNascita = (giorno < 10) ? "0" + to_string(giorno) : to_string(giorno);

    // Costruzione del codice fiscale
    string codiceFiscale = consonantiCognome + consonantiNome + anno + meseNascita + giornoNascita;

    return codiceFiscale;
}

int main() {

    setlocale(LC_ALL, "italian");

    string cognome, nome, dataNascita;
    char genere;

    cout << "Inserisci il cognome: ";
    cin >> cognome;
    cout << "Inserisci il nome: ";
    cin >> nome;
    cout << "Inserisci la data di nascita secondo il formato 'AAAA-MM-GG': ";
    cin >> dataNascita;
    cout << "Inserisci il genere (M per maschio, F per femmina): ";
    cin >> genere;

    string codiceFiscale = calcolaCodiceFiscale(cognome, nome, dataNascita, genere);
    cout << "Il codice fiscale generato è: " << codiceFiscale << endl;

    return 0;
}