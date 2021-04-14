package prob0105

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func buildTree(preorder []int, inorder []int) *TreeNode {
	if len(preorder) == 0 || len(inorder) == 0 {
		return nil
	}

	rootNodeVal := preorder[0]
	node := &TreeNode{Val: rootNodeVal}

	inorderIndex := 0
	for i, val := range inorder {
		if val == rootNodeVal {
			inorderIndex = i
			break
		}
	}
	node.Left = buildTree(preorder[1:inorderIndex+1], inorder[0:inorderIndex])
	node.Right = buildTree(preorder[inorderIndex+1:], inorder[inorderIndex+1:])

	return node
}
