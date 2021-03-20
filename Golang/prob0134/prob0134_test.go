package prob0134

import "testing"

func Test_canCompleteCircuit(t *testing.T) {
	type args struct {
		gas  []int
		cost []int
	}
	tests := []struct {
		name string
		args args
		want int
	}{
		{
			name: "case1",
			args: args{
				gas:  []int{1, 2, 3, 4, 5},
				cost: []int{3, 4, 5, 1, 2},
			},
			want: 3,
		},
		{
			name: "case2",
			args: args{
				gas:  []int{2, 3, 4},
				cost: []int{3, 4, 3},
			},
			want: -1,
		},
		{
			name: "case3",
			args: args{
				gas:  []int{3, 1, 1},
				cost: []int{1, 2, 2},
			},
			want: 0,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := canCompleteCircuit(tt.args.gas, tt.args.cost); got != tt.want {
				t.Errorf("canCompleteCircuit() = %v, want %v", got, tt.want)
			}
		})
	}
}
