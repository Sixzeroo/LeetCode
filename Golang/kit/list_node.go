package kit

//  Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func convIntSlice2ListNode(input []int) *ListNode {
	reqPreHead := &ListNode{}
	cursor := reqPreHead
	for _, val := range input {
		node := &ListNode{Val: val}
		cursor.Next = node
		cursor = cursor.Next
	}
	return reqPreHead.Next
}

func convListNode2IntSlice(node *ListNode) []int {
	res := []int{}
	cursor := node
	for cursor != nil {
		res = append(res, cursor.Val)
		cursor = cursor.Next
	}
	return res
}
