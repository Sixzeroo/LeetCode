class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int len = numbers.size();
        int f = 0, s = len - 1;
        while(numbers[f] + numbers[s] != target)
        {
            if (numbers[f] + numbers[s] > target) s--;
            else f++;
        }
        vector<int> res;
        res.push_back(f + 1);
        res.push_back(s + 1);
        return res;
    }
};