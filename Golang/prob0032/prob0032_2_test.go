package prob0032

import "testing"

func Test_longestValidParenthesesV2(t *testing.T) {
	type args struct {
		s string
	}
	tests := []struct {
		name string
		args args
		want int
	}{
		{
			name: "case1",
			args: args{
				s: "(()",
			},
			want: 2,
		},
		{
			name: "case2",
			args: args{
				s: ")()())",
			},
			want: 4,
		},
		{
			name: "case3",
			args: args{
				s: "",
			},
			want: 0,
		},
		{
			name: "case4",
			args: args{
				s: ")()())",
			},
			want: 4,
		},
		{
			name: "case5",
			args: args{
				s: "())",
			},
			want: 2,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := longestValidParenthesesV2(tt.args.s); got != tt.want {
				t.Errorf("longestValidParenthesesV2() = %v, want %v", got, tt.want)
			}
		})
	}
}
