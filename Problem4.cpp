// DCProblem4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

class Solution {
public:
    static int firstMissingPositive(std::vector<int>& nums) {
        bool contains_one = false;
        for (int x: nums){ //checking to see if 1 is in the vector
            if (x == 1){
                contains_one = true;
                break;
            }
        }
        if(!contains_one) return 1; //already found the first missing positive!

        int n = nums.size();
        if (n == 1) return 2; 

        /* num being greater/less than vector length indicates that
        a number in the range 1 thru n is missing! */
        for (int i = 0; i < n; ++i)
            if (nums[i] <= 0 || nums[i] > n) nums[i] = 1; //don't need nums outside range of vect length

        for (int i = 0; i < n; ++i) {
            int x = abs(nums[i]); //absolute values of num at index i
            if (nums[x-1] > 0) nums[x - 1] *= -1; //negative transformation marks presence of value
        }
        
        for (int i = 0; i < n; ++i)
            if (nums[i] > 0) return i+1; //iterate through until there is a positive
        
        return n + 1; //all nums present
    }
};

int main()
{
    int input;
    std::vector<int> testV;
    std::cout << "Enter an integer. Enter 9999 to quit.";
    while ((std::cin >> input) && input != 9999)
        testV.push_back(input);
    std::cout << Solution::firstMissingPositive(testV);
}
