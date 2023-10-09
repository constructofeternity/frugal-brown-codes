#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <map>

//Add the standard format referencing Leet_Code_51.cpp

class Solution {
public:
    // function to check if placing the queen at x,y will be valid
    bool isvalid(std::vector<std::string> &vec, int x, int y)
    {   
        int n=vec.size();
        for(int i=0;i<n;i++)
        {
            if(vec[x][i]=='Q'||vec[i][y]=='Q') return false;
            if(x-i>=0&&y-i>=0&&vec[x-i][y-i]=='Q') return false;
		    if(x-i>=0&&y+i< n&&vec[x-i][y+i]=='Q') return false;
        }
        return true;
    }
    void backtrack(std::vector<std::string> &vec, std::vector<std::vector<std::string>> &ans, int n, int i1, int j1)
    {
        if(n==0){
            ans.push_back(vec);
            return;
        }
        int len=vec.size();
        for(int i=i1;i<len;i++)
        {   
            if(len-i<n) return;
            for(int j=j1;j<len;j++)
            {
                if(vec[i][j]=='Q') continue;
                else if(vec[i][j]=='.')
                {
                    if(isvalid(vec,i,j))
                    {
                        vec[i][j]='Q';
                        backtrack(vec,ans,n-1,i1+1,0);
                        vec[i][j]='.';
                    }
                }
            }
        }
    }
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> ans;
        std::vector<std::string> vec(n,std::string (n,'.'));
        backtrack(vec,ans,n,0,0);
        return ans;
    }
};

int main() {
    int k = 12;

    Solution solution;

    // Call the function with the input data
    std::map<int, int> Dict;

    for (int key = 1; key <= k; ++key) {
        Dict[key] = solution.solveNQueens(key).size();
    }

    // Display the result
    std::cout << "Number of Possibilities given the size of Chessboard: "<< std::endl;
    for (int key = 1; key <= k; ++key) {
        std::cout << "Key: " << key << ", Value: " << Dict[key] << std::endl;
    }
    std::cout << std::endl;

    return 0;
}