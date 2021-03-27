package prob0912

import (
	"reflect"
	"testing"
)

func Test_sortArray(t *testing.T) {
	type args struct {
		nums []int
	}
	tests := []struct {
		name string
		args args
		want []int
	}{
		{
			name: "case1",
			args: args{
				nums: []int{5, 2, 3, 1},
			},
			want: []int{1, 2, 3, 5},
		},
		{
			name: "case2",
			args: args{
				nums: []int{996, 903, 88, 537, 661, 667, 896, 936, 36, 578, 304, 252, 175, 267, 764, 324, 965, 956, 425, 400, 649, 973, 607, 480, 837, 637, 559, 42, 289, 670, 759, 702, 91, 549, 107, 481, 530, 945, 482, 990, 806, 151, 869, 16, 257, 400, 32, 601, 268},
			},
			want: []int{16, 32, 36, 42, 88, 91, 107, 151, 175, 252, 257, 267, 268, 289, 304, 324, 400, 400, 425, 480, 481, 482, 530, 537, 549, 559, 578, 601, 607, 637, 649, 661, 667, 670, 702, 759, 764, 806, 837, 869, 896, 903, 936, 945, 956, 965, 973, 990, 996},
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := sortArray(tt.args.nums); !reflect.DeepEqual(got, tt.want) {
				t.Errorf("sortArray() = %v, want %v", got, tt.want)
			}
		})
	}
}
