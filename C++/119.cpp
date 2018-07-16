class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(1, 1);
        for(int i = 0; i < rowIndex; i++)
        {
            vector<int> tem(i+1, 1);
            for(int j = 1; j <= i; j++)
                tem[j] = res[j-1] + res[j];
            tem.push_back(1);
            res = tem;
        } 
        return res;
    }
};