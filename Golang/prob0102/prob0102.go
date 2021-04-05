package prob0102

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

type TreeNodeWrap struct {
	Level int
	Node  *TreeNode
}

type TreeNodeWrapQueue struct {
	Q []*TreeNodeWrap
}

func NewTreeNodeWrapQueue() *TreeNodeWrapQueue {
	return &TreeNodeWrapQueue{
		Q: make([]*TreeNodeWrap, 0),
	}
}

func (q *TreeNodeWrapQueue) Push(node *TreeNodeWrap) {
	q.Q = append(q.Q, node)
}

func (q *TreeNodeWrapQueue) Pop() *TreeNodeWrap {
	if len(q.Q) == 0 {
		return nil
	}
	res := q.Q[0]
	q.Q = q.Q[1:]
	return res
}

func (q *TreeNodeWrapQueue) Empty() bool {
	return len(q.Q) == 0
}

func levelOrder(root *TreeNode) [][]int {
	q := NewTreeNodeWrapQueue()
	res := make([][]int, 0)
	if root == nil {
		return res
	}

	q.Push(&TreeNodeWrap{
		Level: 0,
		Node:  root,
	})
	currentLevel := 0
	currentLevelRes := make([]int, 0)
	for !q.Empty() {
		node := q.Pop()
		if node.Level == currentLevel {
			currentLevelRes = append(currentLevelRes, node.Node.Val)
		} else {
			currentLevel++
			res = append(res, currentLevelRes)
			currentLevelRes = []int{node.Node.Val}
		}
		if node.Node.Left != nil {
			q.Push(&TreeNodeWrap{
				Level: currentLevel + 1,
				Node:  node.Node.Left,
			})
		}
		if node.Node.Right != nil {
			q.Push(&TreeNodeWrap{
				Level: currentLevel + 1,
				Node:  node.Node.Right,
			})
		}
	}
	res = append(res, currentLevelRes)

	return res
}
