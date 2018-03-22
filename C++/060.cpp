class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factorial(n, 1);
        vector<bool> used(n, false);
        // 计算阶乘数组
        for(int i=1, tem =1;i<n;i++)
        {
            tem*=i;
            factorial[n-i-1] = tem;
        }
        string s;
        k--;
        for(int i=0;i<n;i++)
        {
            // 计算应该取排在多少位的数字
            int th = k/factorial[i] + 1;
            k = k%factorial[i];
            // 取出数字
            for(int j=0,tem=0;j<n;j++)
            {
                if(!used[j]) tem ++;
                if(tem == th)
                {
                    s.push_back('0'+j+1);
                    used[j] = true;
                    break;
                }
            }
        }
        return s;
    }
};