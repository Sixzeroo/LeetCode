package prob0148

type ListNode struct {
	Val  int
	Next *ListNode
}

func sortList(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	// 快慢指针拆分为两份
	fast, slow := head.Next, head
	for fast != nil && fast.Next != nil {
		slow = slow.Next
		fast = fast.Next.Next
	}
	mid := slow.Next
	slow.Next = nil

	// 两份分别排序
	leftList := sortList(head)
	rishtList := sortList(mid)

	// 合并
	return mergeList(leftList, rishtList)
}

func mergeList(l1, l2 *ListNode) *ListNode {
	preHead := &ListNode{}
	cursor := preHead

	for l1 != nil && l2 != nil {
		if l1.Val < l2.Val {
			cursor.Next = l1
			l1 = l1.Next
		} else {
			cursor.Next = l2
			l2 = l2.Next
		}
		cursor = cursor.Next
	}

	if l1 != nil {
		cursor.Next = l1
	}
	if l2 != nil {
		cursor.Next = l2
	}

	return preHead.Next
}
