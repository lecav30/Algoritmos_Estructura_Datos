#include <iostream>
using namespace std; 

int main()
{
    short x = 14;
    short bit = 0;
    int c = 0;
    int arr[16];
    for (int i = 15; i >= 0; i--)
    {
        bit = (x >> i) & 1;
        arr[c++] = bit;
        cout << bit;
    }
}
