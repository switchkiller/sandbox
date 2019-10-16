clas edge:
    def __init__(self, a, b, w):
        self.a = a;
        self.b = b;
        self.w = w;
    def __str__(self):
        return "A: " + str(self.a) + " B: " + str(self.b) + "W: " + str(self.w)

    def tuple_rep(self):
        return ((self.a.x, self.a.y), (self.b.x, self.b.y))

    def to(self, fro):
        if fro == self.a.v:
            return self.b
        elif fro == self.b.v:
            return self.a
        else:
            return None

class point:
    def __init__(self, v, x, y):
        self.v = v
        self.x = x
        self.y = y

    def __str__(self):
        return str(self.v)

def union(p, x, y):
    p[find(p,x)] = find(p,y)

def find(p, i):
    if (p[i] == -1):
        return i
    return find(p,p[i])

def has_cycle(g, p){
    for e in g:
        x = find(p, e._a)
        y = find(p, e._b)

        if x == y:
            return True
        else:
            union(p, x, y)
    return Flase
}

if __name__ == "__main__":
    # graph ver
    # 0
    # |\
    # 1-2
    edge_1 = edge(0, 1)
    edge_2 = edge(1, 2)
    edge_3 = edge(0, 2)

    graph = [edge_1, edge_2, edge_3]
    n = len(graph)
    parents = [-1 for _ in range(n)]

    print(has_cycle(graph, parents))
