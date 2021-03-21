package prob0124

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func maxPathSum(root *TreeNode) int {
	res := -30000001
	travel(root, &res)
	return res
}

func travel(root *TreeNode, res *int) int {
	if root == nil {
		return 0
	}
	l := travel(root.Left, res)
	if l < 0 {
		l = 0
	}
	r := travel(root.Right, res)
	if r < 0 {
		r = 0
	}

	// 贪心思想，当前树的最值一定在左边或者右边
	*res = max(*res, l+r+root.Val)
	return max(0, max(l, r)+root.Val)
}

func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}
