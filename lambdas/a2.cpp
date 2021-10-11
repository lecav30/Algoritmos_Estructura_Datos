#include <iostream>
using namespace std;

float sum(float, float);
float res(float, float);
float pro(float, float);
float div(float, float);

int main(void)
{
    float a, b;
    unsigned char op;
    float (*operacion)(float, float);
    cout << "Primer operador ... ";
    cin >> a;
    cout << "Segundo operador ... ";
    cin >> b;
    cout << "Operacion ( + , - , * , / ) ... ";
    do
        op = getchar();
    while(op !='+' && op !='-' && op !='*' && op !='/');
    switch(op)
    {
        case '+': operacion = sum; break;
        case '-': operacion = res; break;
        case '*': operacion = pro; break;
        case '/': operacion = div;
    }
    cout << a << " " <<  op << " " << b << " = ";
    cout << (*operacion)(a, b) << "\n";
}
float sum(float x, float y)
{ return x + y; }
float res(float x, float y)
{ return x - y; }
float pro(float x, float y)
{ return x * y; }
float div(float x, float y)
{ return y ? x / y : 0; }
