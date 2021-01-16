package prob0148

import (
	"reflect"
	"testing"
)

func Test_sortList(t *testing.T) {
	type args struct {
		head []int
	}
	tests := []struct {
		name string
		args args
		want []int
	}{
		{
			name: "case1",
			args: args{
				[]int{-1, 5, 3, 4, 0},
			},
			want: []int{-1, 0, 3, 4, 5},
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := sortList(convIntSlice2ListNode(tt.args.head)); !reflect.DeepEqual(convListNode2IntSlice(got), tt.want) {
				t.Errorf("sortList() = %v, want %v", got, tt.want)
			}
		})
	}
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
