#include <iostream>
#include "MiVector.h"

using namespace std;

int main() {
    int n = 20;
    MiVector<float> vec(n);

    for (int i = 0; i < n; i++) {
        vec[i] = i * 10;
    }

    cout << "[ ";
    for (int i = 0; i < n; i++) {
        cout << vec[i] << " ";
    }
    cout << "]\n";

    cout << "[ ";
    for (float e: vec) {
        cout << e << " ";
    }
    cout << "]\n";

    cout << "[ ";
    MiVector<float>::iterator it;
    for (it = vec.begin();
         it != vec.end();
         ++it) {
        cout << *it << " ";
    }
    cout << "]\n";


    return 0;
}
