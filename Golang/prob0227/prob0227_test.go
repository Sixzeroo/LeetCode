package prob0227

import "testing"

func Test_getNextIntStr(t *testing.T) {
	type args struct {
		b []byte
	}
	tests := []struct {
		name      string
		args      args
		wantRes   int
		wantIndex int
	}{
		{
			name: "case1",
			args: args{
				[]byte("33+45456"),
			},
			wantRes:   33,
			wantIndex: 2,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			gotRes, gotIndex := getNextIntStr(tt.args.b)
			if gotRes != tt.wantRes {
				t.Errorf("getNextIntStr() gotRes = %v, want %v", gotRes, tt.wantRes)
			}
			if gotIndex != tt.wantIndex {
				t.Errorf("getNextIntStr() gotIndex = %v, want %v", gotIndex, tt.wantIndex)
			}
		})
	}
}

func Test_calculate(t *testing.T) {
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
				"3+2*2",
			},
			want: 7,
		},
		{
			name: "case2",
			args: args{
				" 3/2 ",
			},
			want: 1,
		},
		{
			name: "case3",
			args: args{
				" 3+5 / 2 ",
			},
			want: 5,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := calculate(tt.args.s); got != tt.want {
				t.Errorf("calculate() = %v, want %v", got, tt.want)
			}
		})
	}
}
