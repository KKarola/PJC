#include <iostream>
#include <utility>  // you can use std::swap

void getMinMax(double &a, double& b, double& c,
               double*& ptrMin, double*& ptrMax) {

    if(a > b) {
        ptrMin = &b;
        ptrMax = &a;
    } else {
        ptrMin = &a;
        ptrMax = &b;
    }

    if(c > *ptrMax) {
        ptrMax = &c;
    }

    if(c < *ptrMin) {
        ptrMin = &c;
    }
}

void getMinMax(double *a, double* b, double* c,
               double** ptrMin, double** ptrMax) {

    if(*a > *b) {
        *ptrMin = b;
        *ptrMax = a;
    } else {
        *ptrMin = a;
        *ptrMax = b;
    }

    if(*c > **ptrMax) {
        *ptrMax = c;
    }

    if(*c < ** ptrMin) {
        *ptrMin = c;
    }
}

void ord3(double& a, double& b, double& c) {

    double najwieksza, srednia, najmniejsza;

    if(a > b) {
            if(a > c) {
                najwieksza = a;

                if(b > c) {
                    srednia = b;
                    najmniejsza = c;
                } else {
                    srednia = c;
                    najmniejsza = b;
                }
            } else {
                najwieksza = c;
                srednia = a;
                najmniejsza = b;
            }
    } else {
        if(a < c) {
            najmniejsza = a;

            if(b < c) {
                najwieksza = c;
                srednia = b;
            } else {
                najwieksza = b;
                srednia = c;
            }
        } else {
            najwieksza = b;
            srednia = a;
            najmniejsza = c;
        }
    }

    a = najmniejsza;
    b = srednia;
    c = najwieksza;

}

void ord3(double* a, double* b, double* c) {

    double najwieksza, srednia, najmniejsza;

    if(*a > *b) {
            if(*a > *c) {
                najwieksza = *a;

                if(*b > *c) {
                    srednia = *b;
                    najmniejsza = *c;
                } else {
                    srednia = *c;
                    najmniejsza = *b;
                }
            } else {
                najwieksza = *c;
                srednia = *a;
                najmniejsza = *b;
            }
    } else {
        if(*a < *c) {
            najmniejsza = *a;

            if(*b < *c) {
                najwieksza = *c;
                srednia = *b;
            } else {
                najwieksza = *b;
                srednia = *c;
            }
        } else {
            najwieksza = *b;
            srednia = *a;
            najmniejsza = *c;
        }
    }

    *a = najmniejsza;
    *b = srednia;
    *c = najwieksza;
}

int main() {
    using std::cout; using std::endl;
    double a, b, c, *ptrMin, *ptrMax;

    a = 2; b = 1; c = 3;
    ord3(a, b, c);
    cout << a << " " << b << " " << c << endl;

    a = 3; b = 2; c = 1;
    ord3(&a, &b, &c);
    cout << a << " " << b << " " << c << endl;

    a = 2; b = 3; c = 1; ptrMin = ptrMax = nullptr;
    getMinMax(a, b, c, ptrMin, ptrMax);
    std:: cout << "Min = " << *ptrMin << "; "
               << "Max = " << *ptrMax << std::endl;

    a = 3; b = 1; c = 2; ptrMin = ptrMax = nullptr;
    getMinMax(&a, &b, &c, &ptrMin, &ptrMax);
    std:: cout << "Min = " << *ptrMin << "; "
               << "Max = " << *ptrMax << std::endl;
}
