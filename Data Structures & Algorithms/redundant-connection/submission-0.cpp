class Solution {
    vector<int> parent, size;
    int find(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }
    bool unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
            return false;
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        return true;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges)
    {
        int n = edges.size();

        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 1; i <= n; i++)  parent[i] = i;

        int u, v;
        for (auto &edge : edges)
        {
            u = edge[0];
            v = edge[1];
            if (!unite(u, v))
                break;
        }
        return {u, v};
    }
};