#include <iostream>

using namespace std;
    #define STAR
    //#define EQU
        #define ch "*";
    #if (defined(STAR) && defined(EQU))
        #error zle
    #endif

    #if (!defined(STAR) && !defined(EQU))
        #error zle
    #endif

    #ifdef STAR
        #define ch "*";
    #endif // STAR

    #ifdef EQU
        #define ch "=";
    #endif // EQU

void histo(int arr[], size_t size) {

    // wyznaczam wysokosc histogramu
    int maksimum = arr[0];
    for(int i = 0; i < size; i++)
    {
       if(arr[i] > maksimum)
       {
         maksimum = arr[i];
       }
    }

    while (maksimum != 0)
    {
        for(int i = 0; i < size; i++)
        {
            if(arr[i] >= maksimum)
            {
            cout << ch;
            } else {
                cout << " ";
            }
        }
        maksimum--;
        cout << endl;
    }
}

int main()
{
    int arr[]{2,1,0,7,1,9};
    size_t size = sizeof(arr)/sizeof(*arr);
    histo(arr,size);
    return 0;
}
