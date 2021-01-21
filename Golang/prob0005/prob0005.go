package prob0005

func longestPalindrome(s string) string {
	b := []byte(s)
	if len(b) == 0 {
		return ""
	}

	res := []byte{}
	maxLen := -1
	sLen := 2*len(b) - 1
	for i := 0; i < sLen; i++ {
		for j := 0; i-j >= 0 && i+j < sLen; j++ {
			if same, val := isSameByte(b, i-j, i+j); same {
				if len(val) > maxLen {
					maxLen = len(val)
					res = val
				}
			} else {
				break
			}
		}
	}
	return string(res)
}

// 插入中间元素判断是否一致
func isSameByte(s []byte, a, b int) (bool, []byte) {
	if a%2 == 0 && b%2 == 0 {
		return s[a/2] == s[b/2], s[a/2 : b/2+1]
	} else if a%2 == 1 && b%2 == 1 {
		return true, s[a/2+1 : b/2+1]
	} else {
		return false, nil
	}
}
