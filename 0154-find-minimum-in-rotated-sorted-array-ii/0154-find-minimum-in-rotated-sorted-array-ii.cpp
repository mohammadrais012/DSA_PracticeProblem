class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right]) {
                // Minimum right side mein hoga
                left = mid + 1;
            } else if (nums[mid] < nums[right]) {
                // Minimum mid ya left side mein hoga
                right = mid;
            } else {
                // nums[mid] == nums[right] → duplicates case
                // Safe option: right ko ek step reduce karo
                right--;
            }
        }
        return nums[left];
    }
};