class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> map{};

        int cur_index = 0;
        for(auto num: nums) {
            if(map.count(target - num) > 0) {
                int other_index = map[target - num];
                return std::vector<int>{cur_index, other_index};
            }
            map[num] = cur_index;
            cur_index++;
        }

        return std::vector<int>{0, 0};
    }
};
