#include <iostream>

int simil(const char a[], const char b[]) {

    int suma = 0, sum = 0, i = 0;
    int dlugoscA = 0, dlugoscB = 0;
    int d = 0, maksimum = 0;

    while(a[i] != '\0') {
        dlugoscA++;
        i++;
    }

    i = 0;
    while(b[i] != '\0') {
        dlugoscB++;
        i++;
    }

    if(dlugoscA == dlugoscB) {
        for(i = 0; i < dlugoscA; i++) {
            if(a[i] == b[i]) {
                d++;
            } else {
                suma += d*d;
                d = 0;
            }
        }
        suma += d*d;
    }

    if(dlugoscA > dlugoscB) {
        for(i = 0; i <= dlugoscA - dlugoscB; i++) {
            sum = 0;
            d = 0;
            for(int j = 0; j < dlugoscB; j++){
                if(a[j+i] == b[j]) {
                    d++;
                } else {
                    sum += d*d;
                    d = 0;
                }
            }
            sum += d*d;
            if(sum > suma) {
                suma = sum;
            }
        }
    }

    if(dlugoscB > dlugoscA) {
        for(i = 0; i <= dlugoscB - dlugoscA; i++) {
            sum = 0;
            d = 0;
            for(int j = 0; j < dlugoscA; j++){
                if(b[j+i] == a[j]) {
                    d++;
                } else {
                    sum += d*d;
                    d = 0;
                }
            }
            sum += d*d;
            if(sum > suma) {
                suma = sum;
            }
        }
    }

    return suma;
}

int main() {
    char a[] = "AACTACGTC",
         b[] = "ACGTA";
    std::cout << a << " and " << b << " -> "
              << simil(a,b) << std::endl;
    char c[] = "GCGC",
         d[] = "AGGGCA";
    std::cout << c << " and " << d << " -> "
              << simil(c,d) << std::endl;
}
