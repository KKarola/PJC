#include <iostream>

using namespace std;

int main()
{
    int x, y, z;

    cout << "Podaj pierwsza liczbe: ";
    cin >> x;
    cout << "Podaj druga liczbe: ";
    cin >> y;
    cout << "Podaj trzecia liczbe: ";
    cin >> z;

    int max;
    if (x > y) max = x;
    else max = y;
    if (max < z) max = z;

    for(int i = max; i > 0; i--) {
        if(x >= max) {
            cout << "*";
        } else {
            cout << " ";
        }
        if(y >= max) {
            cout << "*";
        } else {
            cout << " ";
        }
        if(z >= max) {
            cout << "*";
        } else {
            cout << " ";
        }
        max--;
        cout << endl;
    }

    return 0;
}
