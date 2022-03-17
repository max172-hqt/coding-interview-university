#include <iostream>
#include <vector>

using namespace std;

int my_lower_bound(int n, int a[], int target) {
    int lo = 0;
    int hi = n - 1;
    int mid;

    while (lo <= hi) {
        mid = lo + (hi - lo) / 2;

        if (a[mid] == target) return mid;

        if (a[mid] > target) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    return lo;
}

// Find the first index that has value equal or greater than the target
// 1 2 4 6 7 8 11 14 ; n = 8
// n n n n n y y y
// target: 10
int my_ceiling(vector<int>& a, int target) {
    int lo, hi, mid, n;

    n = a.size();
    lo = 0;
    hi = n - 1;

    while (lo < hi) {
        mid = lo + (hi - lo) / 2;
        if (a[mid] >= target) { // on the left, but including mid
            hi = mid;
        } else {
            lo = mid + 1; // on the right, skip mid
        }
    }
    return lo;
}

int main() {
    int n, target;
    cin >> n;
    cin >> target;
    vector<int> nums(n);

    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int ans = my_ceiling(nums, target);
    cout << "index: " << ans << endl;

    return 0;
}
