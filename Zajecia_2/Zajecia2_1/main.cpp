#include <iostream>
#include <cmath>

const double* aver(const double* arr,
                   size_t size, double& average) {

    double sum = 0;

    for(size_t i = 0; i < size; i++) {
        sum += arr[i];
    }

    average = sum / size;

    double sigma = std::abs(arr[0] - average);
    size_t element = 0;

    for(size_t i = 0; i < size; i++) {
        if(std::abs(arr[i] - average) < sigma) {
            sigma = std::abs(arr[i] - average);
            element = i;
        }
    }

    return &arr[element];
}

int main () {
    using std::cout; using std::endl;

    double arr[] = {1,2,3,4,5,7};
    size_t size = sizeof(arr)/sizeof(arr[0]);
    double average = 0;
    const double* p = aver(arr, size, average);
    cout << *p << " " << average << endl;
}
