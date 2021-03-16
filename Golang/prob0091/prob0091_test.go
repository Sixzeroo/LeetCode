package prob0091

import "testing"

func Test_numDecodings(t *testing.T) {
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
				s: "12",
			},
			want: 2,
		},
		{
			name: "case2",
			args: args{
				s: "226",
			},
			want: 3,
		},
		{
			name: "case3",
			args: args{
				s: "0",
			},
			want: 0,
		},
		{
			name: "case4",
			args: args{
				s: "06",
			},
			want: 0,
		},
		{
			name: "case5",
			args: args{
				s: "27",
			},
			want: 1,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := numDecodings(tt.args.s); got != tt.want {
				t.Errorf("numDecodings() = %v, want %v", got, tt.want)
			}
		})
	}
}
