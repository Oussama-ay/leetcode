class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int p[n];
        p[0] = height[0];
        for (int i = 1; i < n; i++)
            p[i] = max(height[i], p[i - 1]);
        int s[n];
        s[n-1] = height[n-1];
        for (int i = n - 2; i >= 0; i--)
            s[i] = max(height[i], s[i + 1]);
        
        int ans = 0;
        for (int i = 1; i < n - 1; i++)
            ans += min(p[i], s[i]) - height[i];
        return ans;
    }
};