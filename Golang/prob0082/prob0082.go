package prob0082

type ListNode struct {
	Val  int
	Next *ListNode
}

func deleteDuplicates(head *ListNode) *ListNode {
	valMap := map[int]int{}
	preHead := &ListNode{Next: head}

	cursor := preHead
	for cursor.Next != nil {
		cursor = cursor.Next
		val := cursor.Val
		if _, found := valMap[val]; found {
			valMap[val] = valMap[val] + 1
		} else {
			valMap[val] = 1
		}
	}

	cursor = preHead
	for cursor.Next != nil {
		val := cursor.Next.Val
		if num, found := valMap[val]; found && (num > 1) {
			cursor.Next = cursor.Next.Next
			continue
		}

		cursor = cursor.Next
	}

	return preHead.Next
}
