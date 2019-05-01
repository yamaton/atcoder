"""
Union-Find (disjoint set)

https://www.youtube.com/watch?v=zV3Ul2pA2Fw

"""
import collections

class UnionFind(object):
    def __init__(self, n):
        self.parent = [-1] * n
        self.n = n

    def __repr__(self):
        d = collections.defaultdict(set)
        for i in range(len(self.parent)):
            d[self.root(i)].add(i)
        return " ".join(map(str, d.values()))

    def __str__(self):
        return self.__repr__()

    def check_sanity(self, a):
        if not (0 <= a < self.n):
            raise ValueError("Out of bound!")

    def root(self, a):
        self.check_sanity(a)
        if self.parent[a] < 0:
            return a
        self.parent[a] = self.root(self.parent[a])
        return self.parent[a]

    def size(self, a):
        self.check_sanity(a)
        return -self.parent[self.root(a)]

    def connect(self, a, b):
        self.check_sanity(a)
        self.check_sanity(b)

        root_a = self.root(a)
        root_b = self.root(b)

        if root_a == root_b:
            return False

        if self.size(a) < self.size(b):
            root_a, root_b = root_b, root_a

        self.parent[root_a] += self.parent[root_b]
        self.parent[root_b] = root_a

    def is_connected(self, a, b):
        return self.root(a) == self.root(b)


def test_unionfind():
    uni = UnionFind(10)
    uni.connect(0, 4)
    uni.connect(8, 9)
    uni.connect(0, 6)
    uni.connect(8, 9)
    assert '{0, 4, 6} {1} {2} {3} {5} {7} {8, 9}'
    assert uni.size(0) == uni.size(4) == uni.size(6) == 3
    assert uni.size(1) == uni.size(2) == uni.size(3) ==  uni.size(5) == uni.size(7) == 1
    assert uni.size(8) == uni.size(9) == 2
    assert uni.root(0) == uni.root(4) == uni.root(6) == 0
    assert uni.root(8) == uni.root(9) == 8
    assert uni.root(3) == 3
    assert uni.is_connected(4, 6)
    assert not uni.is_connected(4, 9)

    uni.connect(4, 9)
    assert '{0, 4, 6, 8, 9} {1} {2} {3} {5} {7}'
    assert uni.size(0) == uni.size(4) == uni.size(6) == uni.size(8) == uni.size(9)== 5
    assert uni.size(1) == uni.size(2) == uni.size(3) ==  uni.size(5) == uni.size(7) == 1
    assert uni.root(0) == uni.root(4) == uni.root(6) == 0
    assert uni.root(8) == uni.root(9) == 0
    assert uni.root(3) == 3
    assert uni.is_connected(4, 6)
    assert uni.is_connected(6, 8)


if __name__ == "__main__":
    test_unionfind()