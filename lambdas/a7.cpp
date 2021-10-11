#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
void negate_all(vector<T>& v) 
{
    // se paso el vector como referencia y se uso templates
    // en la implementacion del parametro de la funcion lambda
    for_each(v.begin(), v.end(), [] (T& n) { n = -n; });
}

template <typename T>
void print_all(const vector<T>& v) 
{
    for_each(v.begin(), v.end(), [] (const T& n) { cout << n << "\n"; }); 
}

int main() 
{
    vector<int> v;
    v.push_back(34);
    v.push_back(-43);
    v.push_back(56);
    
    cout << "Original vector:\n";
    print_all(v);
    negate_all(v);

    cout << "\nAfter negate_all():\n";
    print_all(v);

    return 0;
}
