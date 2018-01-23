#include <functional>
#include <iostream>

double f1(double x) { return  x/4; }
double f2(double x) { return -2*x; }


using D2D = std::function<double(double)>;

D2D maxfun(D2D funs[], size_t size,
           double a, double b, double* pxmax) {

    static constexpr double eps = 1;
    int k = 0;
    double maksymalna;
    for(size_t i=0; i<size; i++) {
        for(double j=a; j<=b; j+=eps) {
            if(funs[i](j) > maksymalna) {
                maksymalna = funs[i](j);
                *pxmax = j;
                k = i;
            }
        }
    }
    return funs[k];

}

int main() {
    D2D funcs[]{
        f1,
        [] (double x) -> double {return x*x;},
        f2
    };
    double xmax;
    D2D pf = maxfun(funcs, 3, 0, 3, &xmax);
    std::cout << "xmax = " << xmax << "; f(xmax) = "
              << pf(xmax)  << std::endl;
}
