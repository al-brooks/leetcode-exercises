#ifndef Solution121_hpp
#define Solution121_hpp

// Problem 121: Best Time to Buy and Sell Stock
#include <vector>

using std::vector;

class Solution121 {
public:
    int maxProfit(vector<int> &prices) {
        int max = 0;
        int min = INT_MAX; // set to max int so firt val is guaranteed to be smaller

        for (int i = 0; i < prices.size(); ++i) {
            if (prices[i] < min) {
                min = prices[i];
            } else if (prices[i] - min > max) {
                    max = prices[i] - min;
            }
        }

        return max;
    }
};



#endif /* Solution121_hpp */
