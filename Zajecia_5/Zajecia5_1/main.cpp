#include <iostream>
#include <typeinfo>
#include <cstring>
using namespace std;

template <typename T>
int indeks (T tab[], size_t sizeTab) {
    T maksymalna = tab[0];
    size_t indeks = 0;
    for(size_t i = 0; i < sizeTab; i++) {
        if(tab[i] > maksymalna) {
            maksymalna = tab[i];
            indeks = i;
        }
    }
    return ((int) indeks);
}

int indeks (string tab, size_t sizeTab) {
    char maksymalna = tab[0];
    size_t indeks = 0;
    for(size_t i = 0; i < sizeTab; i++) {
        if(tab[i] > maksymalna) {
            maksymalna = tab[i];
            indeks = i;
        }
    }
    return ((int) indeks);
}

int main()
{
    int tab1[] = {1, 2, 3, 4, 5};
    double tab2[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    string tab3 = "Karolina";

    cout << indeks(tab1, (sizeof(tab1)/sizeof(tab1[0]))) << endl;
    cout << indeks(tab2,(sizeof(tab2)/sizeof(tab2[0]))) << endl;
    cout << indeks(tab3, 8) << endl;

    return 0;
}
