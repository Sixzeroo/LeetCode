package prob0087

import "testing"

func Test_isScramble(t *testing.T) {
	type args struct {
		s1 string
		s2 string
	}
	tests := []struct {
		name string
		args args
		want bool
	}{
		{
			name: "case1",
			args: args{
				s1: "great",
				s2: "rgeat",
			},
			want: true,
		},
		{
			name: "case2",
			args: args{
				s1: "abcde",
				s2: "caebd",
			},
			want: false,
		},
		{
			name: "case3",
			args: args{
				s1: "abcdbdacbdac",
				s2: "bdacabcdbdac",
			},
			want: true,
		},
		{
			name: "case4",
			args: args{
				s1: "abcdbdac",
				s2: "bdacabcd",
			},
			want: true,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := isScramble(tt.args.s1, tt.args.s2); got != tt.want {
				t.Errorf("isScramble() = %v, want %v", got, tt.want)
			}
		})
	}
}
