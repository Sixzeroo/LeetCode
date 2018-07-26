class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        bool nega = false;
        long num = numerator, den = denominator;
        if (num * den < 0) nega = true;
        num = abs(num), den = abs(den);
        long quotient = num / den, remainder = num % den;
        string ans = remainder > 0 ? to_string(quotient) + "." : to_string(quotient);
        while (remainder > 0) {
            if (rem.count(remainder)) {
                string repitition = ans.substr(rem[remainder]);
                ans = ans.substr(0, rem[remainder]) + "(" + repitition + ")";
                break;
            }
            rem[remainder] = ans.size();
            num = remainder * 10;
            quotient = num / den;
            remainder = num % den;
            ans += to_string(quotient);
        }
        if (nega) return "-" + ans;
        return ans;
    }
    
private:
    map<int, int> rem;
};