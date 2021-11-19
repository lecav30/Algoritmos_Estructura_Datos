#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
/*
 * 128 64 32 16 8 4 2 1 
 * 0   0  0  0  1 0 1 0
 * 0   0  0  0  0 1 1 0
 * 10 -> 00001010
 * 6  -> 00000110
 * AND   00000010 => 2
 * OR    00001110 => 14
 * XOR   00001100 => 12
 * NEG   11110101 => 245  (NEG 10)
 * DER   0001010(0) => 20 se agrego un bit a la derecha (0)
 * IZQ   (0)0000101 => 5 se agrego un bit a la izquierda (0)
 */

// AND LOGICO
short AND(int a, int b) { return a & b; }
short OR(int a, int b) { return a | b; }
short XOR(int a, int b) { return a ^ b; }
unsigned short NEG(unsigned short a) { return ~a; }
short DER(int a, int b) { return a << b; }
short IZQ(int a, int b) { return a >> b; }

TEST_CASE("Caso de prueba 3", "[factorial]")
{
    REQUIRE(AND(10,6) == 2);
    REQUIRE(OR(10,6) == 14);
    REQUIRE(XOR(10,6) == 12);
    REQUIRE((unsigned short)NEG(10) == 65525);
    REQUIRE(IZQ(10,1) == 20);
    REQUIRE(DER(10,1) == 5);
}

