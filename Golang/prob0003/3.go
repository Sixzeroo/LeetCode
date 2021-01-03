package prob0003

func lengthOfLongestSubstring(s string) int {
	start, end, maxLen := 0, 0, 0
	subStrMap := make(map[byte]int)
	bytes := []byte(s)
	for ; end < len(bytes); end += 1 {
		endLetter := bytes[end]

		index, found := subStrMap[endLetter]
		if found {
			if index+1 > start {
				start = index + 1
			}
		}

		subStrMap[endLetter] = end

		currentLen := end - start + 1
		if currentLen > maxLen {
			maxLen = currentLen
		}
	}
	return maxLen
}
