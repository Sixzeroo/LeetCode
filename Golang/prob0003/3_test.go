package prob0003

import "testing"

func TestLengthOfLongestSubstringCase1(t *testing.T) {
	s := "a"

	res := lengthOfLongestSubstring(s)

	if res != 1 {
		t.Fail()
	}
}

func TestLengthOfLongestSubstringCase2(t *testing.T) {
	s := "bbbbb"

	res := lengthOfLongestSubstring(s)

	if res != 1 {
		t.Fail()
	}
}

func TestLengthOfLongestSubstringCase3(t *testing.T) {
	s := "bbbbb"

	res := lengthOfLongestSubstring(s)

	if res != 1 {
		t.Fail()
	}
}
