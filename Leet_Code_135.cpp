#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>
#include <iostream>

//Add the standard format referencing Leet_Code_1337.cpp

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candies(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); ++i)
        {
            if(ratings[i] > ratings[i-1])
            {
                candies[i] = candies[i-1] + 1;
            }
        }
        for (int i = ratings.size() - 2; i >= 0 ; --i)
        {
            if((ratings[i] > ratings[i+1]) & !(candies[i] > candies[i+1]))
            {
                candies[i] = candies[i+1] + 1;;
            }
        }
        int candies_sum = accumulate(candies.begin(), candies.end(), 0);
        return candies_sum;
    }
};