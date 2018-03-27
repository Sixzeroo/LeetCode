class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int L) {
        int len = words.size();
        vector<string> res;
        // i表示对words遍历， count表示一个串的计数， k表示放入的个数
        for(int i=0,count,k; i<len; i+=k)
        {
            for(count=k=0; i+k<len && count + words[i+k].size() <= L-k; k++)
            {
                count += words[i+k].size();
            }   
            string tem = words[i];
            // 分配空格
            for(int j=0; j<k-1; j++)
            {
                // 最后一行的情况
                if(i+k>=len) tem+=" ";
                // 每一行对空格进行均分
                else tem += string((L-count)/(k-1)+(j<((L-count)%(k-1))) ,' ');
                tem += words[i+j+1];
            }
            // 补充多余的空格
            tem += string(L-tem.size(), ' ');
            res.push_back(tem);
        }
        return res;
    }
};