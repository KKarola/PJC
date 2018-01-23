#include <iostream>

using namespace std;

int main()
{
    int liczba, minimum, maksimum, ileMin = 0, ileMax = 0;

    cout << "Podaj liczbe: ";
    cin >> liczba;
    minimum = liczba;
    maksimum = liczba;

    while (liczba != 0)
    {
        if(liczba < minimum)
        {
            minimum = liczba;
            ileMin = 1;
        } else
        if(liczba == minimum)
        {
          ileMin++;
        }

         if(liczba > maksimum)
        {
            maksimum = liczba;
            ileMax = 1;
        } else
        if(liczba == maksimum)
        {
          ileMax++;
        }

        cout << "Podaj liczbe: ";
        cin >> liczba;
    }

    cout << "Min " << minimum << " " << ileMin << " razy" << endl;
    cout << "Max " << maksimum << " " << ileMax << " razy" << endl;

    return 0;
}
