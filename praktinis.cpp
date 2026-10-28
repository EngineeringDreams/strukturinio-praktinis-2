#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int MAX_MOKINIU = 100;
const int MAX_PAZYMIU = 10;

void meniu() {
    cout << "\n===== MOKINIU PAZYMIU SISTEMA =====" << endl;
    cout << "1. Ivesti mokini ir jo pazymius" << endl;
    cout << "2. Perziureti visu mokiniu pazymius" << endl;
    cout << "3. Perziureti konkretaus mokinio pazymius" << endl;
    cout << "4. Atnaujinti pazymi" << endl;
    cout << "5. Apskaiciuoti mokinio vidurki" << endl;
    cout << "6. Pasalinti mokini" << endl;
    cout << "7. Iseiti" << endl;
    cout << "Pasirinkite: ";
}

int nuskaitytiSkaiciu() {
    int skaicius;

    while (!(cin >> skaicius)) {
        cin.clear();
        cout << "Klaida! Iveskite sveikaji skaiciu: ";
    }

    return skaicius;
}

int pasirinktiMokini(int mokiniuKiekis) {
    if (mokiniuKiekis == 0) {
        cout << "Mokiniu sarasas tuscias!" << endl;
        return -1;
    }

    cout << "Mokinio numeris nuo 1 iki "
         << mokiniuKiekis << ": ";

    int numeris = nuskaitytiSkaiciu();

    if (numeris < 1 || numeris > mokiniuKiekis) {
        cout << "Neteisingas mokinio numeris!" << endl;
        return -1;
    }

    return numeris - 1;
}

int main() {
    string vardai[MAX_MOKINIU];
    int pazymiai[MAX_MOKINIU][MAX_PAZYMIU];
    int kiekPazymiu[MAX_MOKINIU];

    int mokiniuKiekis = 0;
    int pasirinkimas;

    cout << fixed << setprecision(2);

    do {
        meniu();
        pasirinkimas = nuskaitytiSkaiciu();

        switch (pasirinkimas) {

        case 1: {
            if (mokiniuKiekis >= MAX_MOKINIU) {
                cout << "Mokiniu sarasas pilnas!" << endl;
                break;
            }

            cin.ignore(10000, '\n');

            cout << "Iveskite mokinio varda: ";
            getline(cin, vardai[mokiniuKiekis]);

            do {
                cout << "Kiek pazymiu turi mokinys (1-10): ";
                kiekPazymiu[mokiniuKiekis] = nuskaitytiSkaiciu();

                if (kiekPazymiu[mokiniuKiekis] < 1 ||
                    kiekPazymiu[mokiniuKiekis] > MAX_PAZYMIU) {
                    cout << "Galima ivesti nuo 1 iki 10 pazymiu!"
                         << endl;
                }

            } while (kiekPazymiu[mokiniuKiekis] < 1 ||
                     kiekPazymiu[mokiniuKiekis] > MAX_PAZYMIU);

            for (int j = 0; j < kiekPazymiu[mokiniuKiekis]; j++) {
                do {
                    cout << "Iveskite " << j + 1
                         << "-aji pazymi (1-10): ";

                    pazymiai[mokiniuKiekis][j] = nuskaitytiSkaiciu();

                    if (pazymiai[mokiniuKiekis][j] < 1 ||
                        pazymiai[mokiniuKiekis][j] > 10) {
                        cout << "Pazymys turi buti nuo 1 iki 10!"
                             << endl;
                    }

                } while (pazymiai[mokiniuKiekis][j] < 1 ||
                         pazymiai[mokiniuKiekis][j] > 10);
            }

            mokiniuKiekis++;
            cout << "Mokinys pridetas sekmingai!" << endl;
            break;
        }
        case 2: {

            cout << "Mokinių pazymiai" <<endl;
            for(int i=0; i<mokiniuKiekis; i++){
                cout << vardai[i] <<endl;
                for(int j=0; j<kiekPazymiu[i]; j++){
                    cout << pazymiai[i][j] <<" ";

                }
                cout <<endl;
            }
        }
        case 3: {
            cout << "iveskite mokinio numeri 1 - 100" <<endl;
            int pasirinkimas2;
            pasirinkimas2 = nuskaitytiSkaiciu();
            pasirinkimas2 = pasirinkimas2 - 1;
            cout << vardai[pasirinkimas2] <<endl;
            for(int i=0; i<kiekPazymiu[pasirinkimas2];i++){
                cout << pazymiai[pasirinkimas2][i] <<" ";
            }
            cout << endl;
        }
    }
          } while (pasirinkimas != 7);

    return 0;
        }
    
