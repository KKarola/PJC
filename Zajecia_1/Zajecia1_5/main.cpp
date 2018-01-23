#include <iostream>

using namespace std;

int main()
{
    int n, q;
    int zakresDolny = 0;
    int zakresGorny = 1000000;
    char answer;

    cout << "Pomysl liczbe z przedzialu od 0 do 1 000 000" << endl;

    for(int i = 1; i < 21; i++) {
        n = (zakresGorny - zakresDolny)/2 + zakresDolny;
       cout << "\nCzy to liczba n? " << n << endl;
       cin >> answer;

        if (answer == 's')
        {
            zakresDolny = n;
        }
        else
           if (answer == 'b')
           {
                zakresGorny = n;
           }
           else
                if (answer == 'y')
                {
                q = i;
                break;
                }
    }

    cout << "\nPomyslana liczba to: " << n << endl;
    cout << "Liczba zadanych pytan: " << q << endl;

    return 0;
}
