#include <iostream>

using namespace std;

void show(int *tab) {

    for(int i = 0; i < 3; i++) {
        cout << tab[i] << " " ;
    }
    cout << endl;
}

int main()
{
    int tab1[] = {1, 2, 3},
        tab2[] = {4, 5, 6},
        tab3[] = {7, 8, 9};

    cout << "tab1: " ; show(tab1);
    cout << "tab2: " ; show(tab2);
    cout << "tab3: " ; show(tab3);


    return 0;
}
