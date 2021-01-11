package prob0025

type ListNode struct {
	Val  int
	Next *ListNode
}

func reverseKGroup(head *ListNode, k int) *ListNode {
	realHead := &ListNode{Next: head}
	cursor := realHead
	suc := true
	for {
		suc, cursor = reverseNextKNode(cursor, k)
		if !suc {
			break
		}
	}

	return realHead.Next
}

func reverseNextKNode(head *ListNode, k int) (success bool, tailNode *ListNode) {
	list := make([]*ListNode, 0, k)
	cursor := head
	for i := 0; i < k; i++ {
		if cursor.Next == nil {
			return false, nil
		} else {
			list = append(list, cursor.Next)
			cursor = cursor.Next
		}
	}
	tail := cursor.Next
	cursor = head
	for i := 0; i < k; i++ {
		cursor.Next = list[k-1-i]
		cursor = cursor.Next
	}
	cursor.Next = tail

	return true, cursor
}
