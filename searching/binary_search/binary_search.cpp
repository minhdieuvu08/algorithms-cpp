#include <iostream>
#include <vector>

int binary_search(const std::vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] > target) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return -1;
}

int main() {
    std::vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15};
    int target = 7;

    int result = binary_search(arr, target);
    if (result != -1) {
        std::cout << "Element found at index " << result << std::endl;
    } else {
        std::cout << "Element not found in the array" << std::endl;
    }

    return 0;
}
