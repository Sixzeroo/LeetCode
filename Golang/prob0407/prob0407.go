package prob0407

import (
	"container/heap"
)

type Item struct {
	X   int
	Y   int
	Val int
}

type Items []*Item

func (it Items) Len() int {
	return len(it)
}

func (it Items) Less(i, j int) bool {
	// 最小堆
	return it[i].Val < it[j].Val
}

func (it Items) Swap(i, j int) {
	it[i], it[j] = it[j], it[i]
}

func (it *Items) Push(x interface{}) {
	item, _ := x.(*Item)
	*it = append(*it, item)
}

func (it *Items) Pop() interface{} {
	old := *it
	n := len(old)
	item := old[n-1]
	old[n-1] = nil
	*it = old[0 : n-1]
	return item
}

func trapRainWater(heightMap [][]int) int {
	m := len(heightMap)
	if m == 0 {
		return 0
	}
	n := len(heightMap[0])
	if n == 0 {
		return 0
	}

	// 访问数组
	visited := make([][]bool, 0, m)
	for i := 0; i < m; i++ {
		visited = append(visited, make([]bool, n, n))
	}

	// 最小堆
	items := make(Items, 0)
	heap.Init(&items)
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if i == 0 || i == m-1 || j == 0 || j == n-1 {
				item := &Item{X: i, Y: j, Val: heightMap[i][j]}
				heap.Push(&items, item)
				visited[i][j] = true
			}
		}
	}

	// 模拟水位不断上涨
	res := 0
	for items.Len() != 0 {
		topI := heap.Pop(&items)
		top, _ := topI.(*Item)
		for _, d := range [][]int{{0, 1}, {1, 0}, {0, -1}, {-1, 0}} {
			dx := d[0]
			dy := d[1]
			x := top.X + dx
			y := top.Y + dy
			if x > 0 && x < m && y > 0 && y < n && !visited[x][y] {
				// 有低洼时计算到总量中，并替换为当前水位
				if heightMap[x][y] < top.Val {
					//fmt.Printf("v: %v, %v: %v\n", x, y, top)
					res = res + top.Val - heightMap[x][y]
					heightMap[x][y] = top.Val
				}
				item := &Item{X: x, Y: y, Val: heightMap[x][y]}
				heap.Push(&items, item)
				visited[x][y] = true
			}
		}
	}

	return res
}
