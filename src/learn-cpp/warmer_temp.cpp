#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, input;
    cin >> n;
    int temp[n];
    int ans[n];
    vector<int> stack;
    stack.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> input;
        temp[i] = input;
    }

    ans[n-1] = 0;
    for (int i = n - 2; i >= 0; i--) {
        bool found = false;
        for (int j = i + 1; j < n; j++) {
            if (temp[i] < temp[j]) {
                ans[i] = j - i;
                found = true;
                break;
            }
        }
        if (!found) {
            ans[i] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
