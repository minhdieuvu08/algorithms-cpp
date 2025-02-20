#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int lowerBound(vector<int>& nums, int target) {
        // We will define two variables:
        // 'low' starts at the first position in the array.
        // 'high' starts at the last position in the array.
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            // Compute the middle position.
            // We use this formula instead of (high + low) / 2 to prevent integer overflow.
            int mid = low + (high - low) / 2;

            // If the number at the middle position is not the target, we have two cases:
            // Case 1: The number at the middle position is smaller than the target.
            if (nums[mid] < target) {
                // The target must be in the range [mid + 1, high].
                // So we update 'low' to 'mid + 1'.
                low = mid + 1;
            } else {
                // Case 2: The number at the middle position is greater than or equal to the target.
                // The target must be in the range [low, mid-1]
                // So we move 'high' to 'mid - 1' to search in the left half.
                high = mid - 1;
            }
        }
        return low;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = lowerBound(nums, target);
        int end = lowerBound(nums, target + 1) - 1;

        // If the target exists in the array, return its range.
        if (start < nums.size() && nums[start] == target) {
            return {start, end};
        }
        // Otherwise, return [-1, -1] to indicate that the target is not found.
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
