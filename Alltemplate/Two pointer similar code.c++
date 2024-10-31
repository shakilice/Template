#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSumWithCondition(const vector<int>& nums, int target) {
    int left = 1, right = 1, currentSum = 0, maxSum = 0;
    int n = nums.size() - 1; // Adjusting for 1-based indexing

    while (right <= n) {
        // Add the right element to the current sum
        currentSum += nums[right];

        // Check if the condition is broken
        while (currentSum > target && left <= right) {
            // Reduce the current sum by moving the left pointer
            currentSum -= nums[left];
            left++;
        }

        // Update the max sum if the condition is met
        maxSum = max(maxSum, currentSum);

        // Move the right pointer forward
        right++;
    }

    return maxSum;
}

int main() {
    // 1-based indexing; index 0 is ignored
    vector<int> nums = {0, 1, 2, 3, 4, 5};
    int target = 7;

    int result = maxSumWithCondition(nums, target);
    cout << "Maximum sum with condition: " << result << endl;

    return 0;
}
