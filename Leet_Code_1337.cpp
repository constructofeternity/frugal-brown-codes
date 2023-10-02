#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>
#include <iostream>

//Standard Format for input, set up the code in a similar format

class Solution {
public:
    std::vector<int> kWeakestRows(std::vector<std::vector<int>>& mat, int k) {
        std::vector<std::pair<int, int>> rowStrengths;
        for (int i = 0; i < mat.size(); ++i) {
            int strength = std::accumulate(mat[i].begin(), mat[i].end(), 0);
            rowStrengths.push_back(std::make_pair(strength, i));
        }
        std::sort(rowStrengths.begin(), rowStrengths.end());

        std::vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(rowStrengths[i].second);
        }
        return result;
    }
};

int main() {
    std::vector<std::vector<int>> mat = {
        {1, 1, 0, 0, 0},
        {1, 1, 1, 1, 0},
        {1, 0, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {1, 1, 1, 1, 1}
    };
    int k = 3;

    Solution solution;

    // Call the function with the input data
    std::vector<int> weakestRows = solution.kWeakestRows(mat, k);

    // Display the result
    std::cout << "Indices of Weakest Rows: ";
    for (int index : weakestRows) {
        std::cout << index << " ";
    }
    std::cout << std::endl;

    return 0;
}