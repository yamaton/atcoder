// Union-Find (disjoint set)
// https://www.youtube.com/watch?v=zV3Ul2pA2Fw

struct UnionFind {
    parent: Vec<i32>,
}


impl UnionFind {
    fn new(n: usize) -> UnionFind {
        UnionFind { parent: vec![-1; n] }
    }

    fn root(&self, mut x: usize) -> usize {
        while self.parent[x as usize] >= 0 {
            x = self.parent[x as usize] as usize;
        }
        x
    }

    fn size(&self, x: usize) -> usize {
        let ans = -self.parent[self.root(x)];
        ans as usize
    }

    fn connect(&mut self, x: usize, y: usize) -> bool {
        if self.size(x) < self.size(y) {
            return self.connect(y, x);
        }

        let root_x = self.root(x);
        let root_y = self.root(y);
        if root_x == root_y {
            return false;
        }

        self.parent[root_x] += self.parent[root_y];
        self.parent[root_y] = root_x as i32;

        return true;
    }

    fn is_connected(&self, x: usize, y: usize) -> bool {
        self.root(x) == self.root(y)
    }
}


fn main() {
    let mut uf = UnionFind::new(10);
    assert_eq!(uf.root(3), 3);
    assert!(!uf.is_connected(1, 3));
    assert!(!uf.is_connected(2, 3));
    assert!(uf.is_connected(3, 3));
    assert!(!uf.is_connected(4, 3));
    assert!(!uf.is_connected(5, 3));
    assert_eq!(uf.size(3), 1);
    uf.connect(1, 2);
    uf.connect(2, 3);
    uf.connect(1, 4);
    assert!(uf.is_connected(1, 3));
    assert!(uf.is_connected(2, 3));
    assert!(uf.is_connected(3, 3));
    assert!(uf.is_connected(4, 3));
    assert!(!uf.is_connected(5, 3));
    assert_eq!(uf.size(3), 4);
}