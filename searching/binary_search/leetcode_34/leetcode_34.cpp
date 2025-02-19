#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int lowerBound(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = lowerBound(nums, target);
        int end = lowerBound(nums, target + 1) - 1;

        if (start < nums.size() && nums[start] == target) {
            return {start, end};
        }
        return {-1, -1};
    }
};

int main() {
    Solution sol;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    vector<int> result = sol.searchRange(nums, target);
    cout << "Output: [" << result[0] << ", " << result[1] << "]\n";

    return 0;
}
