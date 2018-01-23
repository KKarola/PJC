#include <iostream>

using namespace std;

int main()
{
    double wzrost, waga;

    cout << "Podaj swoj wzrost w metrach: ";
    cin >> wzrost;
    cout << "Podaj swoja wage w kilogramach: ";
    cin >> waga;
    cout <<  "\nTwoj wskaznik BMI wynosi: " << waga/(wzrost * wzrost) << endl;

    return 0;
}
