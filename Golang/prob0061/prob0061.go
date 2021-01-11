package prob0061

type ListNode struct {
	Val  int
	Next *ListNode
}

func rotateRight(head *ListNode, k int) *ListNode {
	if head == nil {
		return nil
	}
	listLen := 1
	cursor := head
	for cursor.Next != nil {
		cursor = cursor.Next
		listLen += 1
	}
	cursor.Next = head

	dis := listLen - k%listLen
	cursor = head
	for i := 0; i < dis-1; i += 1 {
		cursor = cursor.Next
	}
	res := cursor.Next
	cursor.Next = nil

	return res
}
