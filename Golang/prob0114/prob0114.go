package prob0114

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func flatten(root *TreeNode) {
	if root == nil {
		return
	}
	flatten(root.Left)
	flatten(root.Right)
	tem := root
	right := root.Right
	if root.Left != nil {
		root.Right = root.Left
		root.Left = nil
		tem = root.Right
		for tem.Right != nil {
			tem = tem.Right
		}
	}
	if right != nil {
		tem.Right = right
	}
}
