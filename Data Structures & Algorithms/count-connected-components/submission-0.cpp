class Solution {
    vector<int> parent;
    vector<int> size;
    int find(int a)
    {
        if (parent[a] == a)
            return a;
        return parent[a] = find(parent[a]);
    }
    bool unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a != b)
        {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
            return true;
        }
        return false;
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
        int ans = n;
        for (auto e : edges)
        {
            int a = e[0];
            int b = e[1];
            if (unite(a, b))
                ans--;
        }
        return ans;
    }
};
