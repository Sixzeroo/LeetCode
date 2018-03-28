# [LeetCode](https://github.com/Sixzeroo/LeetCode) ![language](https://img.shields.io/badge/language-C%2B%2B-yellow.svg)

LeetCode 代码和题解集合

## Hash Table
|  #  | 题目           |  代码       |  时间复杂度           | 空间复杂度           | 难度    | 题解| 
|-----|---------------- | --------------- | --------------- | --------------- | ------------- |-----|
| 001 | [Two Sum](https://leetcode.com/problems/two-sum/description/) | [C++](./C++/1-Two-Sum.cpp) | _O(n)_ | _O(n)_ | Easy | |
| 003 | [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/) | [C++](./C++/3-Longest-Substring-Without-Repeating-Characters.cpp) | _O(n)_ | _O(1)_ | Medium | |
|036| [Valid Sudoku](https://leetcode.com/problems/valid-sudoku/) | [C++](./C++/036.cpp) | _O(9^2)_         | _O(9)_          | Easy           ||
|049| [Group Anagrams](https://leetcode.com/problems/group-anagrams/)     | [C++](./C++/049.cpp)  | _O(n * glogg)_          | _O(n)_          | Medium         ||
|128 | [Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/)| [C++](./C++/128.cpp)  | _O(n)_ | _O(n)_ | Hard         ||


## Linked List
|  #  | 题目           |  代码       |  时间复杂度           | 空间复杂度           | 难度    | 题解| 
|-----|---------------- | --------------- | --------------- | --------------- | ------------- |-----|
| 002 | [Add Two Numbers](https://leetcode.com/problems/add-two-numbers/) | [C++](./C++/2-Add-Two-Numbers.cpp) | _O(n)_ | _O(1)_ | Medium | | 
|019| [Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)| [C++](./C++/019.cpp) | _O(n)_       | _O(1)_         | Easy         | 双指针 | 
| 021| [Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/)| [C++](./C++/21-Merge-Two-Sorted-Lists.cpp)| _O(n)_ | _O(1)_ | Easy         ||
| 023| [Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/) | [C++](./C++/23-Merge-k-Sorted-Lists.cpp) | _O(nlogk)_| _O(1)_| Hard          | [here](https://www.liuin.cn/2018/01/26/LeetCode%20Merge%20k%20Sorted%20Lists%20%E9%A2%98%E8%A7%A3/) | 
|024| [Swap Nodes in Pairs](https://leetcode.com/problems/swap-nodes-in-pairs/)| [C++](./C++/024.cpp)   | _O(n)_          | _O(1)_          | Easy         ||
|025| [Reverse Nodes in k-Group](https://leetcode.com/problems/reverse-nodes-in-k-group/)| [C++](./C++/025.cpp) | _O(n)_       | _O(1)_         | Hard         ||
|061| [Rotate List](https://leetcode.com/problems/rotate-list/)| [C++](./C++/061.cpp)  | _O(n)_          | _O(1)_          | Medium         ||
|086| [Partition List](https://leetcode.com/problems/partition-list/)| [C++](./C++/086.cpp) | _O(n)_       | _O(1)_         | Medium         ||



## Math
|  #  | 题目           |  代码       |  时间复杂度           | 空间复杂度           | 难度    | 题解| 
|-----|---------------- | --------------- | --------------- | --------------- | ------------- |-----|
| 007 | [Reverse Integer](https://leetcode.com/problems/reverse-integer/) | [C++](./C++/7-Reverse-Integer.cpp) | _O(1)_ | _O(1)_ | Easy | |
| 009| [Palindrome Number](https://leetcode.com/problems/palindrome-number/) | [C++](./C++/9-Palindrome-Number.cpp) | _O(1)_ | _O(1)_        | Easy           ||
|012| [Integer to Roman](https://leetcode.com/problems/integer-to-roman/) | [C++](./C++/012.cpp) | _O(n)_ | _O(1)_          | Medium ||
| 013| [Roman to Integer](https://leetcode.com/problems/roman-to-integer/) | [C++](./C++/13-Roman-to-Integer.cpp)  | _O(n)_ | _O(1)_          | Easy           ||
|029| [Divide Two Integers](https://leetcode.com/problems/divide-two-integers/) | [C++](./C++/029.cpp)   | _O(1)_       | _O(1)_         | Medium         | 位运算 |
|050| [Pow(x, n)](https://leetcode.com/problems/powx-n/)     | [C++](./C++/050.cpp)     | _O(1)_       | _O(1)_       | Medium         | 快速幂运算 |
| 060| [Permutation Sequence](https://leetcode.com/problems/permutation-sequence/) | [C++](./C++/060.cpp)  | _O(n^2)_ | _O(n)_  | Medium         ||
|065| [Valid Number](https://leetcode.com/problems/valid-number/) | [C++](./C++/065.cpp) | _O(n)_         | _O(1)_          | Hard | 匹配 |

## String
|  #  | 题目           |  代码       |  时间复杂度           | 空间复杂度           | 难度    | 题解| 
|-----|---------------- | --------------- | --------------- | --------------- | ------------- |-----|
|006| [ZigZag Conversion](https://leetcode.com/problems/zigzag-conversion/) | [C++](./C++/006.cpp)  | _O(n)_ | _O(1)_        | Easy           | 模拟法 |
|008| [String to Integer (atoi)](https://leetcode.com/problems/string-to-integer-atoi/) | [C++](./C++/008.cpp)  | _O(n)_ | _O(1)_ | Medium      | 模拟法|
| 014| [Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix/) | [C++](./C++/14-Longest-Common-Prefix.cpp) | _O(n * k)_   | _O(1)_  | Easy           ||
|028| [Implement strStr()](https://leetcode.com/problems/implement-strstr/) | [C++](./C++/028-1.cpp) | _O(n + k)_   | _O(k)_  | Easy           | `KMP Algorithm`(待实现)|
|030| [Substring with Concatenation of All Words](https://leetcode.com/problems/substring-with-concatenation-of-all-words/) | [C++](./C++/030.cpp)  | _O((m + n) * k)_ | _O(n * k)_ | Hard     |[here](https://www.liuin.cn/2018/03/15/LeetCode-%E9%A2%98%E8%A7%A3%E2%80%94%E2%80%94Substring-with-Concatenation-of-All-Words/)|
|038| [Count and Say](https://leetcode.com/problems/count-and-say/) | [C++](./C++/038.cpp) | _O(n * 2^n)_  | _O(2^n)_        | Easy           ||
|043| [Multiply Strings](https://leetcode.com/problems/multiply-strings/) | [C++](./C++/043.cpp)| _O(m * n)_ | _O(m + n)_  | Medium         |大数乘法|
|058| [Length of Last Word](https://leetcode.com/problems/length-of-last-word/) | [C++](./C++/058.cpp) | _O(n)_   | _O(1)_  | Easy||
| 067| [Add Binary](https://leetcode.com/problems/add-binary/)    | [C++](./C++/067.cpp) | _O(n)_          | _O(1)_          | Easy           ||
|068| [Text Justification](https://leetcode.com/problems/text-justification/) | [C++](./C++/068.cpp) | _O(n)_ | _O(1)_      | Hard           ||


## Stack
|  #  | 题目           |  代码       |  时间复杂度           | 空间复杂度           | 难度    | 题解| 
|-----|---------------- | --------------- | --------------- | --------------- | ------------- |-----|
| 020| [Valid Parentheses](https://leetcode.com/problems/valid-parentheses/)| [C++](./C++/20-Valid-Parentheses.cpp) | _O(n)_        | _O(n)_          | Easy           ||
|032| [Longest Valid Parentheses](https://leetcode.com/problems/longest-valid-parentheses/)| [C++](./C++/032-2.cpp)  | _O(n)_ | _O(1)_ | Hard   |[here]()|


## Array
|  #  | 题目           |  代码       |  时间复杂度           | 空间复杂度           | 难度    | 题解| 
|-----|---------------- | --------------- | --------------- | --------------- | ------------- |-----|
|015 | [3 Sum](https://leetcode.com/problems/3sum/)         | [C++](./C++/15-3Sum.cpp)    | _O(n^2)_        | _O(1)_          | Medium         | [here](https://www.liuin.cn/2018/01/28/LeetCode-3Sum-3Sum-Closest-题解/)| 
|016 | [3 Sum Closest](https://leetcode.com/problems/3sum-closest/) | [C++](./C++/16-3Sum-Closest.cpp) | _O(n^2)_       | _O(1)_          | Medium         |[here](https://www.liuin.cn/2018/01/28/LeetCode-3Sum-3Sum-Closest-题解/)|
|018| [4 Sum](https://leetcode.com/problems/4sum/)         | [C++](./C++/18-4Sum.cpp)         | _O(n^3)_    | _O(1)_    | Medium         ||
|026 | [Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)| [C++](./C++/026.cpp) | _O(n)_       | _O(1)_         | Easy           ||
|027 | [Remove Element](https://leetcode.com/problems/remove-element/) | [C++](./C++/027.cpp) | _O(n)_      | _O(1)_         | Easy           ||
|031 | [Next Permutation](https://leetcode.com/problems/next-permutation/)| [C++](./C++/031.cpp)| _O(n)_  | _O(1)_          | Medium         | [here](https://www.liuin.cn/2018/02/25/LeetCode-Next-Permutation-题解/)|
|035 | [Search Insert Position](https://leetcode.com/problems/search-insert-position/description/)| [C++](./C++/035.cpp) | _O(n)_ | _O(1)_ | Easy         || 
|041 | [First Missing Positive](https://leetcode.com/problems/first-missing-positive/)| [C++](./C++/041.cpp) | _O(n)_ | _O(1)_ | Hard         || 
|048 | [Rotate Image](https://leetcode.com/problems/rotate-image/)   | [C++](./C++/048.cpp) | _O(n^2)_      | _O(1)_         | Medium         ||
|054 | [Spiral Matrix](https://leetcode.com/problems/spiral-matrix/) | [C++](./C++/054.cpp) | _O(m * n)_    | _O(1)_         | Medium         ||
|059 | [Spiral Matrix II](https://leetcode.com/problems/spiral-matrix-ii/) | [C++](./C++/059.cpp)  | _O(n^2)_ | _O(1)_      | Medium         ||
|066 | [Plus One](https://leetcode.com/problems/plus-one/)      | [C++](./C++/066.cpp)  | _O(n)_           | _O(1)_         | Easy           || 


## Binary Search
|  #  | 题目           |  代码       |  时间复杂度           | 空间复杂度           | 难度    | 题解| 
|-----|---------------- | --------------- | --------------- | --------------- | ------------- |-----|
|004| [Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/) | [C++](./C++/004.cpp)  | _O(log(min(m, n)))_ | _O(1)_ | Hard         |[here](https://www.liuin.cn/2018/03/08/LeetCode-%E9%A2%98%E8%A7%A3%E2%80%94%E2%80%94Median-of-Two-Sorted-Arrays/)|
|033| [Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/) | [C++](./C++/033.cpp)  | _O(logn)_ | _O(1)_   | Hard         | 坐标转换+二分法 |
|034| [Search for a Range](https://leetcode.com/problems/search-for-a-range/) | [C++](./C++/034.cpp)  | _O(logn)_ | _O(1)_   | Medium         ||

## DP
|  #  | 题目           |  代码       |  时间复杂度           | 空间复杂度           | 难度    | 题解| 
|-----|---------------- | --------------- | --------------- | --------------- | ------------- |-----|
|010| [Regular Expression Matching](https://leetcode.com/problems/regular-expression-matching/) | [C++](./C++/010-1.cpp) [C++](./C++/010-2.cpp)| _O(m * n)_ | _O(n)_ | Hard | [动态规划](https://www.liuin.cn/2018/03/09/LeetCode-%E9%A2%98%E8%A7%A3%E2%80%94%E2%80%94Regular-Expression-Matching/) |
|032| [Longest Valid Parentheses](https://leetcode.com/problems/longest-valid-parentheses/)| [C++](./C++/032-1.cpp)  | _O(n)_ | _O(1)_ | Hard   | [here]() |
|044| [Wildcard Matching](https://leetcode.com/problems/wildcard-matching/) | [C++](./C++/044.cpp) | _O(m + n)_ | _O(1)_    | Hard           | DP | 
|053| [Maximum Subarray](https://leetcode.com/problems/maximum-subarray/)|[C++ 数学](./C++/053-1.cpp)| _O(n)_     | _O(1)_         | Medium         ||
|062| [Unique Paths](https://leetcode.com/problems/unique-paths/)    | [C++](./C++/062.cpp) | _O(m * n)_      | _O(m + n)_   | Medium         ||
| 063| [Unique Paths II](https://leetcode.com/problems/unique-paths-ii/) | [C++](./C++/063.cpp) |  _O(m * n)_ | _O(m + n)_   | Medium         ||
|064| [Minimum Path Sum](https://leetcode.com/problems/minimum-path-sum/)| [C++](./C++/064.cpp)| _O(m * n)_ | _O(m + n)_     | Medium         ||



## Greedy
|  #  | 题目           |  代码       |  时间复杂度           | 空间复杂度           | 难度    | 题解| 
|-----|---------------- | --------------- | --------------- | --------------- | ------------- |-----|
|011| [Container With Most Water](https://leetcode.com/problems/container-with-most-water/)| [C++](./C++/011.cpp) | _O(n)_ | _O(1)_ | Medium | [贪心算法](https://www.liuin.cn/2018/03/09/LeetCode-%E9%A2%98%E8%A7%A3%E2%80%94%E2%80%94Container-With-Most-Water/) |
|042| [Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/) | [C++](./C++/042.cpp) | _O(n)_ | _O(1)_ | Hard | 双指针，巧妙方法 | 
|045| [Jump Game II](https://leetcode.com/problems/jump-game-ii/)  | [C++](./C++/045.cpp) | _O(n)_        | _O(1)_          | Hard           ||
|055| [Jump Game](https://leetcode.com/problems/jump-game/)     | [C++](./C++/055.cpp)  | _O(n)_          | _O(1)_          | Medium         ||

## Backtracking
|  #  | 题目           |  代码       |  时间复杂度           | 空间复杂度           | 难度    | 题解| 
|-----|---------------- | --------------- | --------------- | --------------- | ------------- |-----|
|017| [Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)| [C++ 循环](./C++/017-1.cpp) [C++ 回溯](./C++/017-2.cpp) | _O(n * 4^n)_ | _O(n)_ | Medium ||
|022| [Generate Parentheses](https://leetcode.com/problems/generate-parentheses/)|[C++ 回溯](./C++/022.cpp)| _O(4^n / n^(3/2))_ | _O(n)_   | Medium         ||
|037| [Sudoku Solver](https://leetcode.com/problems/sudoku-solver/) | [C++](./C++/037.cpp) | _O((9!)^9)_  | _O(1)_          | Hard           | bfs |
|039| [Combination Sum](https://leetcode.com/problems/combination-sum/)|[C++](./C++/039.cpp) | _O(k * n^k)_    | _O(k)_          | Medium         ||
|040| [Combination Sum II](https://leetcode.com/problems/combination-sum-ii/)| [C++](./C++/040.cpp)| _O(k * C(n, k))_| _O(k)_         | Medium         ||
|046| [Permutations](https://leetcode.com/problems/permutations/)| [C++](./C++/046.cpp) | _O(n * n!)_         | _O(n)_          | Medium         ||
|047| [Permutations II](https://leetcode.com/problems/permutations-ii/)| [C++](./C++/047.cpp) | _O(n * n!)_   | _O(n)_          | Medium           ||
|051| [N-Queens](https://leetcode.com/problems/n-queens/)      | [C++](./C++/051.cpp)   | _O(n!)_         | _O(n)_          | Hard           | 值得优化 |
|052| [N-Queens-II](https://leetcode.com/problems/n-queens-ii/)   | [C++](./C++/052.cpp) | _O(n!)_        | _O(n)_          | Hard           | 值得优化 |
|357| [Count Numbers with Unique Digits](https://leetcode.com/problems/count-numbers-with-unique-digits/) | [C++](./C++/357.cpp) | _O(n!)_ | _O(1)_ | Medium || DP实现 |

## Tree
|  #  | 题目           |  代码       |  时间复杂度           | 空间复杂度           | 难度    | 题解| 
|-----|---------------- | --------------- | --------------- | --------------- | ------------- |-----|
|094 | [Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/)  | [C++](./C++/094.cpp) | _O(n)_| _O(1)_| Medium           || |
|684 | [Redundant Connection](https://leetcode.com/problems/redundant-connection/) | [C++](./C++/684.cpp)  | _O(n)_ | _O(n)_ | Medium | 并查集 |
|685 | [Redundant Connection II](https://leetcode.com/problems/redundant-connection-ii/) | [C++](./C++/685.cpp)  | _O(n)_ | _O(n)_ | Hard ||
 
## Sort
|  #  | 题目           |  代码       |  时间复杂度           | 空间复杂度           | 难度    | 题解| 
|-----|---------------- | --------------- | --------------- | --------------- | ------------- |-----|
|056| [Merge Intervals](https://leetcode.com/problems/merge-intervals/)| [C++](./C++/056.cpp) | _O(nlogn)_  | _O(1)_        | Medium          ||
|057| [Insert Interval](https://leetcode.com/problems/insert-interval/)| [C++](./C++/057.cpp) | _O(n)_    | _O(1)_          | Hard           ||

## DFS
|  #  | 题目           |  代码       |  时间复杂度           | 空间复杂度           | 难度    | 题解| 
|-----|---------------- | --------------- | --------------- | --------------- | ------------- |-----|
|130| [Surrounded Regions](https://leetcode.com/problems/surrounded-regions/)|[C++](./C++/130.cpp) | _O(m * n)_ | _O(m + n)_ | Medium         ||
|200| [Number of Islands](https://leetcode.com/problems/number-of-islands/) | [C++](./C++/200.cpp) | _O(m * n)_ | _O(m * n)_| Medium         ||