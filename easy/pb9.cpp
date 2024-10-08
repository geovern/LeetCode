//easy
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int digitsLen(int x){ //finds the len of x
        if(x == 0)
            return 0;
        else
            return 1 + digitsLen(x/10);
    }

    int getDigit(int x, int k) { // number, digit
        int g = x;
        g /= pow(10, k);
        g = g % 10;
        return g;
    }

    bool isPalindrome(int x) {
        if (x < 0) return false;
        bool is = true;
        int digits = digitsLen(x);
        int first = 0, last = digits - 1;
        while(first <= last) {//binary search
            if(getDigit(x, first) != getDigit(x, last)) {
                is = false;
                break;
            }
            first++;
            last--;
        }
        return is;
    }
};

int main() {
    Solution s;
    cout << s.isPalindrome(121) << endl;
}
