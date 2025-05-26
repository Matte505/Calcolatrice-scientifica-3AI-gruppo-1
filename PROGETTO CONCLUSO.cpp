#include <iostream>
#include <cmath>
#include <vector>
#include <fstream> // Per gestire i file
using namespace std;

// Funzione per calcolare il fattoriale ( utilizaimo long long per lavorare su numeri grandi cosi da non mandarlo in overflow)
unsigned long long fattoriale(int n) {
    unsigned long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Funzione per calcolare la potenza
double potenza(double base, int esponente) {
    double result = 1;
    for (int i = 0; i < abs(esponente); ++i) {
        result *= base;
    }
    if (esponente < 0)
        return 1 / result;
    return result;
}

// Funzione per visualizzare la cronologia
void visualizzaCronologia(const vector<string>& cronologia) {
    if (cronologia.empty()) {
        cout << "La cronologia è vuota." << endl;
    } else {
        cout << "Cronologia delle operazioni:" << endl;
        for (const string& operazione : cronologia) {
            cout << operazione << endl;
        }
    }
}

int main() {
    int scelta;
    double num1, num2;
    vector<string> cronologia; // Vettore per memorizzare la cronologia delle operazioni

    // Il menu delle operazioni
    do {
        cout << "----- MENU -----" << endl;
        cout << "1. Addizione" << endl;
        cout << "2. Sottrazione" << endl;
        cout << "3. Moltiplicazione" << endl;
        cout << "4. Divisione" << endl;
        cout << "5. Fattoriale" << endl;
        cout << "6. Potenza" << endl;
        cout << "7. Radice quadrata" << endl;
        cout << "8. Visualizza cronologia" << endl;
        cout << "0. Esci" << endl;
        cout << "Scegli un'opzione: ";
        cin >> scelta;

        switch (scelta) {
            //Addizione
            case 1:
                cout << "Inserisci due numeri che vuoi sommare: ";
                cin >> num1 >> num2;
                cout << "Risultato: " << num1 + num2 << endl;
                cronologia.push_back("Addizione: " + to_string(num1) + " + " + to_string(num2));
                break;
            //Sottrazione
            case 2:
                cout << "Inserisci due numeri che vuoi sottrarre: ";
                cin >> num1 >> num2;
                cout << "Risultato: " << num1 - num2 << endl;
                cronologia.push_back("Sottrazione: " + to_string(num1) + " - " + to_string(num2));
                break;
            //Moltiplicazione
            case 3:
                cout << "Inserisci due numeri che vuoi moltiplicare: ";
                cin >> num1 >> num2;
                cout << "Risultato: " << num1 * num2 << endl;
                cronologia.push_back("Moltiplicazione: " + to_string(num1) + " * " + to_string(num2));
                break;
            //Divisione
            case 4:
                cout << "Inserisci due numeri che vuoi dividere: ";
                cin >> num1 >> num2;
                if (num2 != 0)
                    cout << "Risultato: " << num1 / num2 << endl;
                else
                    cout << "non puoi dividere per zero" << endl;
                cronologia.push_back("Divisione: " + to_string(num1) + " / " + to_string(num2));
                break;
            //Fattoriale
            case 5: {
                int n;
                cout << "Inserisci un numero intero di cui vuoi calcolare il fattoriale: ";
                cin >> n;
                if (n >= 0)
                    cout << "Fattoriale di " << n << " = " << fattoriale(n) << endl;
                else
                    cout << "Errore il numero non può essere negativo" << endl;
                cronologia.push_back("Fattoriale di " + to_string(n));
                break;
            }
            //potenza
            case 6: {
                int esponente;
                cout << "Inserisci la base e l'esponente: ";
                cin >> num1 >> esponente;
                cout << num1 << " elevato a " << esponente << " = " << potenza(num1, esponente) << endl;
                cronologia.push_back("Potenza: " + to_string(num1) + " ^ " + to_string(esponente));
                break;
            }
            //Radice quadrata
            case 7: {
                int numero;
                cout << "Inserisci un numero per calcolare la sua radice quadrata: ";
                cin >> numero;
                if (numero < 0) {
                    cout << "Errore: non è possibile calcolare la radice quadrata di un numero negativo.\n";
                } else {
                    double radice = sqrt(numero);
                    cout << "La radice quadrata di " << numero << " è " << radice << endl;
                }
                cronologia.push_back("Radice quadrata di " + to_string(numero));
                break;
            }
            //Cronologia
            case 8:
                visualizzaCronologia(cronologia);
                break;
            //Uscita dal programma
            case 0:
                cout << "Uscita dal programma." << endl;
                break;
            default:
                cout << "Scelta non valida." << endl;
        }

        cout << endl;
    } while (scelta != 0);

    // Salvataggio della cronologia su file
    ofstream file("cronologia.txt");
    if (file.is_open()) {
        for (const string& operazione : cronologia) {
            file << operazione << endl;
        }
        file.close();
        cout << "Cronologia salvata nel file 'cronologia.txt'" << endl;
    } else {
        cout << "Errore nell'apertura del file per il salvataggio." << endl;
    }

    return 0;
}