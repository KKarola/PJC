#include <iostream>

using namespace std;
    #define POL
    //#define ENG

    #if (defined(POL) && defined(ENG))
        #error zle
    #elif (!defined(POL) && !defined(ENG))
        #error zle
    #endif

    #ifdef POL
        #define napis1 "Podaj liczbe naturalna (0 konczy): "
        #define napis2 "Maksymalna suma wynosi "
        #define napis3 " dla liczby "
    #endif // POL

    #ifdef ENG
        #define napis1 "Enter a natural number (0 if done): "
        #define napis2 "Max sum of digits was "
        #define napis3 " for "
    #endif // ENG

int main()
{
    int number, sum, maxNumber, numb, maxs = 0;

    do {
        cout << napis1;
        cin >> number;
        sum = 0;
        numb = number;

        while (numb != 0) {
            sum += numb%10;
            numb /= 10;
        }

        if (sum > maxs)  {
            maxs = sum;
            maxNumber = number;
        }
    } while (number != 0);

    cout << endl << napis2 << maxs << napis3 << maxNumber << endl;

    return 0;
}
