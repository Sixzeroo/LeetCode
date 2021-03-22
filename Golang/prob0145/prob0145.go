package prob0145

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func postorderTraversal(root *TreeNode) []int {
	res := make([]int, 0)
	realPostorderTraversal(root, &res)
	return res
}

func realPostorderTraversal(root *TreeNode, res *[]int) {
	if root == nil {
		return
	}
	realPostorderTraversal(root.Left, res)
	realPostorderTraversal(root.Right, res)
	*res = append(*res, root.Val)
}
