#include <time.h>
#include "sorts.h"

int main() 
{
    auto greaterThan = [] (float a, float b) { return a > b; };
    
    float a1[10], a2[10], a3[10], a4[10], a5[10];

    srand(time(0));

    for (size_t i = 0; i < 10; ++i)
    {
        a1[i] = rand() % 100;
        a5[i] = a4[i] = a3[i] = a2[i] = a1[i];
    }

    cout << "Paso a paso intercambio\n";
    swap<float>(a1, 10, greaterThan);
    
    cout << "Paso a paso burbuja\n";
    bubble<float>(a2, 10, greaterThan);

    return 0;
}
