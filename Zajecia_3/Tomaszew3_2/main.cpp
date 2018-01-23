#include <iostream>

using namespace std;

int main()
{
    int zmienna = 5;
    int *w = &zmienna;
    int &refw = *w;

    int tab[] = {*w, refw};

    cout << tab[0] <<  " " << tab[1] << endl;

    return 0;
}
