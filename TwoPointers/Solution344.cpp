// Problem 344: Reverse String
#include <vector>

using std::vector;

class Solution344 {
public:
    void reverseString(vector<char> &s) {
        int start = 0;
        int end = (int) s.size() - 1;

        while (start < end) {
            int temp = s[end];
            s[end--] = s[start];
            s[start++] = temp;
        }
    }
};

