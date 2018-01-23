#include <iostream>

using namespace std;
    #define GETMAX
    #define GETMIN

    #if !(defined(GETMAX) && defined(GETMIN))
    #error zle
    #endif

int main()
{
    int x, y, z, max, min;

    cout << "Podaj pierwsza liczbe: ";
    cin >> x;
    cout << "Podaj druga liczbe: ";
    cin >> y;
    cout << "Podaj trzecia liczbe: ";
    cin >> z;
    cout << endl;

    if (x > y) max = x;
    else max = y;
    if (max < z) max = z;

    # ifdef GETMAX
    cout << "Najwieksza wczytana liczba to: " << max << endl;
    # endif // GETMAX


    if (x > y) min = y;
    else min = x;
    if (min > z) min = z;

    #ifdef GETMIN
    cout << "Najmniejsza wczytana liczba to: " << min << endl;
    # endif

/*  #if defined(GETMAX) && defined(GETMIN)
    cout << "Wartosc maksymalna to " << max << ", a wartosc minimalna to " << min << endl;
    #endif
*/
    return 0;
}
