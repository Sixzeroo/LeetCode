// O(n^2) 算法
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int len = gas.size();
        if(len == 0) return -1;
        vector<int> ab(len);
        int sum = 0;
        for(int i = 0; i < len; i++)
        {
            ab[i] = gas[i] - cost[i];
            sum += ab[i];
        }
        if(sum < 0) return -1;
        for(int i = 0; i < len; i++)
        {
            int temi = ab[i], j = 1;
            while(j < len && temi >= 0)
            {
                temi += ab[(i + j) % len];
                j++;
            }
            if(j == len) return i;
        }
        return -1;
    }
};

// O(n)贪心算法
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int i = 0, j = 0, n = gas.size(), tot = 0;
        while(i < n)
        {
            j = i;
            while(tot >= 0 && i < n)
            {
                tot += gas[i] - cost[i];
                i++;
            }
            if(tot < 0)
            {
                tot = 0;
                j = -1;
            }
        }
        for(int k = 0; k < j; k++)
        {
            tot += gas[k] - cost[k];
            if(tot < 0)
            {
                j = -1;
                break;
            }
        }
        return j;
    }
};