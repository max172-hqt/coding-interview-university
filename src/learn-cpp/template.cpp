#include <iostream>

using namespace std;

template <class T>
T maximum(T value1, T value2, T value3)
{
    T max = value1;

    if (value2 > max) {
        max = value2;
    }

    if (value3 > max) {
        max = value3;
    }

    return max;
}

int main(void)
{
    /* int a, b, c; */

    /* cout << "Input three integers: " << endl; */
    /* cin >> a >> b >> c; */

    /* cout << "Max is: " << maximum(a, b, c) << endl; */

    double a, b, c;
    cout << "Input three doubles: " << endl;
    cin >> a >> b >> c;

    cout << "Max is: " << maximum(a, b, c) << endl;
    return 0;
}
