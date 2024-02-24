class DSQ
{
public:
    vector<int> parent;
    vector<int> size;
    DSQ(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int findParent(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }
    void Union(int u, int v)
    {
        int a = findParent(u);
        int b = findParent(v);
        if (a == b)
            return;
        if (size[a] > size[b])
        {
            parent[b] = a;
            size[a] += size[b];
        }
        else
        {
            parent[a] = b;
            size[b] += size[a];
        }
    }
};