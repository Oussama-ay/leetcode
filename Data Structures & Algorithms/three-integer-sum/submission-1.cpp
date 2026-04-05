class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            unordered_set<int> st;
            int j = i + 1;
            while (j < n)
            {
                if (st.count(-nums[i] - nums[j]))
                {
                    ans.push_back({nums[i], -nums[i] - nums[j], nums[j]});
                    while (j + 1 < n && nums[j] == nums[j+1])
                        j++;
                }
                st.insert(nums[j]);
                j++;
            }
        }
        return ans;
    }
};
