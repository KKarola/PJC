#include <iostream>
#include <cmath>
using namespace std;

unsigned short koduj(int plec, int stan_cyw, int grupa_wiek, int edu,int zam, int region, int odp) {
    stan_cyw = stan_cyw << 1;
    grupa_wiek = grupa_wiek << 3;
    edu = edu << 5;
    zam = zam << 7;
    region = region << 9;
    odp = odp << 13;

    unsigned short kod = plec + stan_cyw + grupa_wiek + edu + zam + region + odp;
    return kod;
}

void info (unsigned short kod) {
    int plec;
    plec = (kod & 1? 1 : 0);

    kod >>= 1;
    int stan_cyw = 0;
    for(int i = 0; i < 2; i++, kod >>= 1) {
        if(kod & 1) {
            stan_cyw = stan_cyw + pow(2.0, i);
        }
    }

    int grupa_wiek = 0;
    for(int i = 0; i < 2; i++, kod >>= 1) {
        if(kod & 1) {
            grupa_wiek = grupa_wiek + pow(2.0, i);
        }
    }

    int edu = 0;
    for(int i = 0; i < 2; i++, kod >>= 1) {
        if(kod & 1) {
            edu = edu + pow(2.0, i);
        }
    }

    int zam = 0;
    for(int i = 0; i < 2; i++, kod >>= 1) {
        if(kod & 1) {
            zam = zam + pow(2.0, i);
        }
    }

    int region = 0;
    for(int i = 0; i < 4; i++, kod >>= 1) {
        if(kod & 1) {
            region = region + pow(2.0, i);
        }
    }

    int odp = 0;
    for(int i = 0; i < 3; i++, kod >>= 1) {
        if(kod & 1) {
            odp = odp + pow(2.0, i);
        }
    }

    cout << "plec:          "  << plec << endl;
    cout << "stan cywilny:  "  << stan_cyw << endl;
    cout << "grupa wiekowa: "  << grupa_wiek << endl;
    cout << "wyksztalcenie: "  << edu << endl;
    cout << "miejsce zam:   "  << zam << endl;
    cout << "region:        "  << region << endl;
    cout << "odpowiedz:     "  << odp << endl;

}

int main()
{
    unsigned short kod = koduj(1, 0, 1, 1, 3, 13, 1);
    info(kod);
    return 0;
}
