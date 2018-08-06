class Solution {
public:
    int countPrimes(int n) {
        bool arr[n+1];
        memset(arr,true,sizeof(arr));
        for(int i=2;i*i<=n;i++)
            if(arr[i]==true)
                for(int j=i*2;j<=n;j+=i)
                    arr[j]=false;
        
        int cnt=0;
        for(int i=2;i<n;i++)
            if(arr[i])
                cnt++;
        
        return cnt;
        
    }
};