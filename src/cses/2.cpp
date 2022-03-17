#include <iostream>

using namespace std;
#define ll long long

int main()
{
    ll n, sum = 0;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int input;
        cin >> input;
        sum += input;
    }

    cout << n * (n + 1) / 2 - sum;

    return 0;
}
