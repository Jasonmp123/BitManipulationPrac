// NvidiaCodingProblems.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

uint32_t get5Bits(uint32_t num) {
    int mask = 0x1F;
    uint32_t numToReturn = num & mask;

    return numToReturn;
}

uint32_t clearBit(uint32_t num, int position) {
    uint32_t numToReturn = num & ~(1 << position);

    return numToReturn;
}

uint32_t setBit(uint32_t num, int position) {
    uint32_t numToReturn = num | (1 << position);

    return numToReturn;
}

uint32_t flipBit(uint32_t num, int position) {
    uint32_t numToReturn = num ^ (1 << position);

    return numToReturn;
}

void printBits(uint32_t& num) {
    int track = 31;
    while (track >= 0) {
        std::cout << ((num >> track) & 1);
        track--;
    }
}

uint32_t mirrorBits( uint32_t number, uint8_t numBits ) {
    uint32_t toRet = 0;
    uint8_t maskL = 0x1;
    uint8_t maskR = 0x1;

    maskL <<= ((32 - numBits) - 1);
    maskR <<= numBits - 1;
    return toRet;
}

int countSetBits(uint32_t number) {
    int num = 0;
    uint32_t mask = 0x80000000;

    for (int i = 31; i >= 0; --i) {
        std::cout << "I " << i << std::endl;
        if (mask & number) {
            num++;
        }
        mask = mask >> 1;
    }

    return num;
}

void reverseBits(uint32_t& number) {
    uint32_t mask = 0x1;

    for (int i = 0; i < 32; ++i) {
        if (number & mask) {
            number &= ~(mask);
        }
        else {
            number |= mask;
        }

        mask <<= 1;
    }

    printBits(number);
    std::cout << std::endl;
}

int main()
{
    uint32_t testInt = 0x00004124;
    uint32_t testInt2 = 0x00000001;
    uint32_t test1;
    uint32_t test2;
    uint32_t test3;
    int test4;

    std::cout << "Print Bits for test: ";
    printBits(testInt);
    std::cout << std::endl;

    test1 = get5Bits(testInt);
    test2 = clearBit(testInt, 2);
    test3 = setBit(testInt, 3);
    test4 = countSetBits(testInt2);


    std::cout << "5 bits of " << std::hex << testInt << " = " << std::hex << test1 << std::endl;
    std::cout << "cleared " << std::hex << testInt << " = " << std::hex << test2 << std::endl;
    std::cout << "set " << std::hex << testInt << " = " << std::hex << test3 << std::endl;
    std::cout << "Set bits in " << std::hex << testInt2 << " = " << test4 << std::endl;
    std::cout << "reverseBits " << std::hex << testInt2 << " = ";
    reverseBits(testInt2);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
