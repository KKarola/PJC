#include <iostream>

using namespace std;

void fun1(int i) {
    cout << i << endl;
    i++;
    cout << i << endl;
}

void fun2(int *i) {
    cout << *i << endl;
    *i = *i + 1;
    cout << *i << endl;
}

void fun3(int &i) {
    cout << i << endl;
    i++;
    cout << i << endl;
}

int main()
{
    int wrt = 4;
    cout << wrt << endl;
    fun1(wrt);
    fun2(&wrt);
    fun3(wrt);
    cout << wrt << endl;

    return 0;
}
