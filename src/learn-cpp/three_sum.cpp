#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, input;
    int lo, hi, target;
    vector<int> nums;

    cin >> n;
    nums.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> input;
        nums[i] = input;
    }

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i] == nums[i-1]) continue;                
        lo = i + 1;
        hi = n - 1;
        target = nums[i] * -1;

        while (lo < hi) {
            if (nums[lo] + nums[hi] == target) {
                cout << nums[lo] << " " << nums[hi] << " " << nums[i] << endl;
                lo++;
                hi--;

                while (lo < hi && nums[lo] == nums[lo - 1]) lo++;
                while (lo < hi && nums[hi] == nums[hi + 1]) hi--;
            } else if (nums[lo] + nums[hi] < target) {
                lo++;
            } else {
                hi--;
            }
        }
    }

    return 0;
}
