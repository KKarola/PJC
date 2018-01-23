#include <iostream>

using namespace std;

char inputData[100];

int main()
{
    cout << "Wprowadz slowo: ";
    cin >> inputData;

    int dlugoscSlowa = 0, i = 0;

    while(inputData[i] != '\0') {
        dlugoscSlowa++;
        i++;
    }
    cout << "Dlugosc podanego slowa to:" << dlugoscSlowa << endl;

    char *tab = new char[dlugoscSlowa];
    for(i = 0; i < dlugoscSlowa; i++) {
      tab[i] = inputData[i];
    }

    cout << tab;

    delete[] tab;


    return 0;
}
