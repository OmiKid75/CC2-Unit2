#include <iostream>
#include <vector>

class Solution {
public:
    int findDuplicate(std::vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

int main() {
    Solution solution;

    // Test case 1: nums = [1, 3, 4, 2, 2] -> duplicate is 2
    std::vector<int> nums1 = {1, 3, 4, 2, 2};
    std::cout << "Duplicate in [1, 3, 4, 2, 2] is: " << solution.findDuplicate(nums1) << std::endl;

    // Test case 2: nums = [3, 1, 3, 4, 2] -> duplicate is 3
    std::vector<int> nums2 = {3, 1, 3, 4, 2};
    std::cout << "Duplicate in [3, 1, 3, 4, 2] is: " << solution.findDuplicate(nums2) << std::endl;

    // Test case 3: nums = [2, 2, 2, 2, 2] -> duplicate is 2
    std::vector<int> nums3 = {2, 2, 2, 2, 2};
    std::cout << "Duplicate in [2, 2, 2, 2, 2] is: " << solution.findDuplicate(nums3) << std::endl;

    return 0;
}