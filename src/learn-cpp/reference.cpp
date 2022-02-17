#include <iostream>

using namespace std;

void squareByReference(int &);

int main(void) {
    int a = 6;

    // Can be simply used by name
    // cannot change to refer to another object
    // alias for a, must be initialized
    int &ref = a;

    cout << ref << endl;

    cout << "Before: " << a << endl;
    squareByReference(ref);
    cout << "After: " << a << endl;
    cout << "After: " << ref << endl;

    return 0;
}

void squareByReference(int &numberRef)
{
    numberRef *= numberRef;
}
