#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int commonPrefixAux(string& first, string& second) {
        int length = min(first.length(), second.length());
        int common = 0;
        for(int i = 0; i < length; i++) {
            if(first[i] == second[i]) {
                common++;
            }
            else break;
        }
        return common;
    }
    int lengthC(vector<string>& strs) {
        int words = strs.size();
        int minLen = 201; //above the limit of 200
        for(int i = 1; i < words; i++) {
            minLen = min(minLen, commonPrefixAux(strs[0], strs[i]));
        }
        return minLen;
    }
    string longestCommonPrefix(vector<string>& strs) {
        int length = lengthC(strs); //common letters
        string common = strs[0].substr(0, length);
        return common;
    }
};

int main() {
    Solution s;
    vector<string> strs = {"flower", "flow", "flight"};
    cout << s.longestCommonPrefix(strs) << endl;
    return 0;
}
