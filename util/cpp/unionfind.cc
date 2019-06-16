// Union-Find (disjoint set)
// https://www.youtube.com/watch?v=zV3Ul2pA2Fw

#include <vector>

class UnionFind
{

    std::vector<int> parent;

public:
    UnionFind(int n)
    {
        parent.resize(n, -1);
    }

    int root(int x)
    {
        while (parent[x] >= 0)
        {
            x = parent[x];
        }
        return x;
    }

    int size(int x)
    {
        return -parent[root(x)];
    }

    bool connect(int x, int y)
    {
        if (size(x) < size(y))
            std::swap(x, y);

        int root_x = root(x);
        int root_y = root(y);
        if (root_x == root_y)
            return false;
        parent[root_x] += parent[root_y];
        parent[root_y] = root_x;

        return true;
    }

    bool is_connected(int x, int y)
    {
        return (root(x) == root(y));
    }
};
