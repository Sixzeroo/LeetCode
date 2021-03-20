package prob0126

func findLadders(beginWord string, endWord string, wordList []string) [][]string {
	res := make([][]string, 0)
	findLadders2(beginWord, endWord, wordList, []string{beginWord}, &res)

	if len(res) == 0 {
		return res
	}
	minLen := len(res[0])
	for _, list := range res {
		if len(list) < minLen {
			minLen = len(list)
		}
	}
	realRes := make([][]string, 0)
	for _, list := range res {
		if len(list) == minLen {
			realRes = append(realRes, list)
		}
	}
	return realRes
}

func findLadders2(begin, end string, wordList []string, currentList []string, res *[][]string) {
	if begin == end {
		inputRes := make([]string, 0, len(currentList))
		for _, item := range currentList {
			inputRes = append(inputRes, item)
		}
		*res = append(*res, inputRes)
		return
	}
	n := len(begin)

	for currentLevel := 0; currentLevel < n; currentLevel++ {
		visitedByte := make(map[byte]bool)
		for _, word := range wordList {
			thisByte := word[currentLevel]
			isByteVisited, found := visitedByte[thisByte]
			if found && isByteVisited {
				continue
			}

			newBegin := begin[0:currentLevel] + string(thisByte) + begin[currentLevel+1:]
			//fmt.Printf("current: %d, thisByte: %s, case: %s\n", currentLevel, string(thisByte), newBegin)
			if strContain(currentList, newBegin) {
				continue
			}
			index := findStrIndex(wordList, newBegin)
			if index == -1 {
				continue
			}
			//fmt.Println(newBegin)
			newCurrentList := append(currentList, newBegin)
			findLadders2(newBegin, end, wordList, newCurrentList, res)

			visitedByte[thisByte] = true
		}
	}

}

func strContain(list []string, elem string) bool {
	for _, item := range list {
		if item == elem {
			return true
		}
	}
	return false
}

func findStrIndex(list []string, elem string) int {
	for i, item := range list {
		if item == elem {
			return i
		}
	}
	return -1
}
