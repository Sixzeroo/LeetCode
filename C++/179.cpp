class Solution {
public:
    // 自定义 排序函数
    string largestNumber(vector<int>& nums) {
        vector<string> strnums;
        for (int i = 0; i < nums.size() ; ++ i) {
            strnums.push_back(to_string(nums[i]));
        }
        sort(strnums.begin(), strnums.end(), comparetor);
        string result;
        for (auto item : strnums) {
            result += item;
        }
        if (result[0] == '0') {
            return "0";
        }
        return result;
    }
    
    static bool comparetor(string s1, string s2) {
        string s1s2 = s1 + s2;
        string s2s1 = s2 + s1;
        
        return s1s2 > s2s1;
    }
};