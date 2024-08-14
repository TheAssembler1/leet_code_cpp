class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        int its = 0;

        int mid = (right - left) / 2;
        while(left < right) {
            std::cout << "left: " << left << std::endl;
            std::cout << "right: " << right << std::endl;
            std::cout << "mid: " << mid << std::endl;

            if(nums[mid] == target) {
                return mid;
            }
            
            if(nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }

            mid = left + (right - left) / 2;
        }

        std::cout << "left: " << left << std::endl;
        std::cout << "right: " << right << std::endl;
        std::cout << "mid: " << mid << std::endl;

        if(nums[mid] < target) {
            return mid + 1;
        }

        return mid;
    }
};
