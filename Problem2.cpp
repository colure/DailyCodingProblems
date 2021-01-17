/*
* Given an array of integers, return a new array such that each element at index i 
* of the new array is the product of all the numbers in the original array except the one at i.
* For example, if our input was [1, 2, 3, 4, 5], the expected output would be 
* [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        //size of the input array
        int size = nums.size();
        
        //left and right arrays
        int L[size];
        int R[size];
        
        //final answer to be returned
        vector<int> answer(size);
        
        //L[i] contains the product of all elements to the left
        //For the element at index '0', there are no elements to the left so L[0] would be 1.
        L[0] = 1;
        for (int i = 1; i < size; i++) {
            //L[i-1] contains prod to the left of 'i-1'
            //simplify mult with nums[i-1] would give product of all elements to left of index 'i'
            L[i] = nums[i-1] * L[i - 1];
        }
        
        //R[i] contains product of all elements to right
        //for element at index 'size-1' there are no elements to the right, so R[size-1] would be 1
        R[size - 1] = 1;
        for (int i = size - 2; i >= 0; i--) {
            //R[i+1] already contains product of elements to right of i+1
            //mult w nums [i+1 gives product of all elements to right of index i]
            R[i] = nums[i + 1] * R[i + 1];
        }
        
        //constructing answer array
        for (int i = 0; i < size; i++) {
            answer[i] = L[i] * R[i];
        }
        
        return answer;
    }
};
