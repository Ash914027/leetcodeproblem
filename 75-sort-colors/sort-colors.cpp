class Solution {
public:
    void sortColors(vector<int>& nums) {
        int two = 0;
        int ones = 0;
        int n = nums.size();
        for(int i = 0; i < n; ++i)
        {
            if(nums[i])
            {
                nums[i] & 1 ? ++ones : ++two;
            }
            nums[i] = 0;
        }
        int idx = n - 1;
        while(two --> 0)
        {
            nums[idx--] = 2;
        }
        while(ones --> 0)
        {
            nums[idx--] = 1;
        }
    }
};