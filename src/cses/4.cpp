#include <iostream>

using namespace std;
#define ll long long

int main()
{
    int n, mx;
    ll ans = 0;
    cin >> n;
    cin >> mx;
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        mx = max(x, mx);
        ans += mx - x;
    }
    cout << ans;

    return 0;
}
