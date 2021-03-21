package prob0099

import "sort"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

type SortInt []int

func (a SortInt) Len() int           { return len(a) }
func (a SortInt) Swap(i, j int)      { a[i], a[j] = a[j], a[i] }
func (a SortInt) Less(i, j int) bool { return a[i] < a[j] }

func recoverTree(root *TreeNode) {
	// 先中序排序
	order := make([]int, 0)
	inorder(root, &order)

	// 对内容进行排序
	sort.Sort(SortInt(order))

	// 再中序排序插入
	index := 0
	orderInsert(root, &order, &index)
}

func inorder(root *TreeNode, l *[]int) {
	if root == nil {
		return
	}
	inorder(root.Left, l)
	*l = append(*l, root.Val)
	inorder(root.Right, l)
}

func orderInsert(root *TreeNode, l *[]int, index *int) {
	if root == nil {
		return
	}
	orderInsert(root.Left, l, index)
	root.Val = (*l)[*index]
	*index = *index + 1
	orderInsert(root.Right, l, index)
}
