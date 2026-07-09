type UnionFind struct {
    parent []int
}

func NewUnionFind(n int) *UnionFind {
    p := make([]int, n)
    for i := range p {
        p[i] = i
    }
    return &UnionFind{parent: p}
}

func (uf *UnionFind) Find(i int) int {
    if uf.parent[i] == i {
        return i
    }
    uf.parent[i] = uf.Find(uf.parent[i]) // Path compression
    return uf.parent[i]
}

func (uf *UnionFind) Union(i, j int) {
    rootI := uf.Find(i)
    rootJ := uf.Find(j)
    if rootI != rootJ {
        uf.parent[rootI] = rootJ
    }
}

func pathExistenceQueriesDSU(n int, nums []int, maxDiff int, queries [][]int) []bool {
    uf := NewUnionFind(n)
    for i := 1; i < n; i++ {
        if nums[i]-nums[i-1] <= maxDiff {
            uf.Union(i, i-1)
        }
    }
    
    ans := make([]bool, len(queries))
    for i, q := range queries {
        ans[i] = uf.Find(q[0]) == uf.Find(q[1])
    }
    return ans
}
