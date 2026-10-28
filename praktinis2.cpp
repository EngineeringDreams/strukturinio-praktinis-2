#include <fstream>
#include <iostream>

using namespace std;
void meniu() {
    cout << "\n===== MOKINIU PAZYMIU SISTEMA =====" << endl;
    cout << "1. Ivesti mokini ir jo pazymius" << endl;
    cout << "2. Perziureti visu mokiniu pazymius" << endl;
    cout << "3. Perziureti konkretaus mokinio pazymius" << endl;
    cout << "4. Atnaujinti pazymi" << endl;
    cout << "5. Apskaiciuoti mokinio vidurki" << endl;
    cout << "6. Pasalinti mokini" << endl;
    cout << "7. Iseiti" << endl;
   
}
int nuskaitytiSkaiciu() {
    int skaicius;

    while (!(cin >> skaicius)) {
        
        cout << "Klaida! Iveskite sveikaji skaiciu: ";
        cin.clear();
    }

    return skaicius;
}
int const MAXMOK=100;
int const MAXPAZ=10;

string Mok[MAXMOK], Mpaz[MAXMOK][MAXPAZ];
int veiksmas = 0, mokkiek, kiekis2=0, temp = 0, pazskait=0;


int main(){
    do{
        meniu();
        cin >> veiksmas;
        switch (veiksmas){

            case 1:{
                cout << "kiek mokiniu?"<<endl;
                cin >> mokkiek;
                if(mokkiek > MAXMOK)
                {
                    cout << "sarasas perpildytas!" <<endl;
                    break;
                } 
                

                while(mokkiek > kiekis2)
                {
                    cout << "iveskite varda" <<endl;
                       cin >> Mok[kiekis2];
                       kiekis2++;

                }
                cout << "kiek pazymiu turi mokiniai (1-10)?" <<endl;
                pazskait = nuskaitytiSkaiciu();
                if (pazskait > 10 || pazskait <1) {
                    cout << "galima ivesti nuo 1 iki 10 pazymiu" <<endl;
                    
                }

                



            }

        }
        

    }while(veiksmas <=4);
}