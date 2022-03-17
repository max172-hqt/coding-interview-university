#include <iostream>

using namespace std;
#define ll long long

int main()
{
    int ans = 0, curr = 0;
    string seq;
    char l = 'A';
    cin >> seq;
    for (char c: seq) {
        if (c == l) {
            curr++;
            ans = max(ans, curr);
        } else {
            l = c;
            curr = 1;
        }
    }
    cout << ans;

    return 0;
}
