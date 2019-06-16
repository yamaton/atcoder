"""
Topological sort

Ref: CLRS
"""
import collections


def toposort(vertices, adj):
    """
    Args:
        vertices (iterable): graph vertices
        adj: (list of list) adjacency list
    Returns:
        topo_order: list or vertices in topologically-sorted order
        parent: dict {vertex: vertex or None} indicating parent of each vertex
    """
    parent = dict()
    finish_time = dict()
    time = 0

    def dfs_visit(u):
        nonlocal time
        for v in adj[u]:
            if v not in parent:
                parent[v] = u
                dfs_visit(v)
        time += 1
        finish_time[u] = time

    for i in vertices:
        if i not in parent:
            parent[i] = None
            dfs_visit(i)

    topo_order = sorted(finish_time.keys(), key=lambda k: finish_time[k], reverse=True)
    return topo_order, parent


def test_toposort():
    vertices = range(6)
    adj_list = collections.defaultdict(list)
    adj_list[2] = [3]
    adj_list[3] = [1]
    adj_list[4] = [0, 1]
    adj_list[5] = [0, 2]

    topo_order, parent = toposort(vertices, adj_list)
    assert topo_order == [5, 4, 2, 3, 1, 0]
    print(parent)
    # assert parent == {0: 1, 1: 3, 3: 2, 2: 4, 4: 5, 5: None}


if __name__ == "__main__":
    test_toposort()