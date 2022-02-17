#include <iostream>

using namespace std;

int main(void)
{
    int firstInt;
    int secondInt;
    int sum, product, difference, quotient;

    cout << "Enter the first number: ";
    cin >> firstInt;
    cout << "Enter the second number: ";
    cin >> secondInt;

    sum = firstInt + secondInt;
    difference = firstInt - secondInt;
    product = firstInt * secondInt;
    quotient = firstInt / secondInt;

    cout << "The sum is: " << sum << endl;
    cout << "The difference is: " << difference << endl;
    cout << "The product is: " << product << endl;
    cout << "The quotient is: " << quotient << endl;
    cout << sizeof(int) << endl; // 4 bytes
    cout << sizeof(short) << endl; // 2 bytes
    cout << sizeof(char) << endl; // 1 bytes

    return 0;
}
