package prob0109

import "fmt"

type ListNode struct {
	Val  int
	Next *ListNode
}

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func sortedListToBST(head *ListNode) *TreeNode {
	if head == nil {
		return nil
	}
	middlePreNode, middleNode := findMiddleNode(head)
	if middlePreNode != nil {
		middlePreNode.Next = nil
	} else {
		head = nil
	}
	middleNextNode := middleNode.Next
	middleNode.Next = nil

	treeNode := &TreeNode{
		Val: middleNode.Val,
	}
	// TODO: delete
	fmt.Println(treeNode.Val)

	treeNode.Left = sortedListToBST(head)
	treeNode.Right = sortedListToBST(middleNextNode)

	return treeNode
}

func findMiddleNode(head *ListNode) (*ListNode, *ListNode) {
	l := 0
	tem := head
	for tem != nil {
		l++
		tem = tem.Next
	}
	middleNodePos := l / 2
	middlePreNodePos := middleNodePos - 1
	var middleNode, middlePreNode *ListNode
	tem = head
	for i := 0; i < middleNodePos; i++ {
		if i == middlePreNodePos {
			middlePreNode = tem
		}
		tem = tem.Next
	}
	middleNode = tem
	return middlePreNode, middleNode

}
