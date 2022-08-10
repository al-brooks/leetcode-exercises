// Prolem 167: Two Sum II - Input Array is Sorted

#include <vector>

using std::vector;

class Solution167 {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int start = 0;
        int end = (int) numbers.size() - 1;

        while (start != end) {
            if (numbers[end] + numbers[start] > target) {
                --end;
            } else if (numbers[start] + numbers[end] < target) {
                ++start;
            } else {
                return vector<int> {start + 1, end + 1};
            }
        }

        return vector<int> {-1, -1};
    }
};

