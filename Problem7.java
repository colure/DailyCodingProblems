/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.dailychallenge.problem7;

class decodinator {
    //Given the mapping a = 1, b = 2, ... z = 26, and an encoded message,
    //count the number of ways it can be decoded.
    //For example, the message '111' would give 3, since it could be 
    //decoded as 'aaa', 'ka', and 'ak'.
    
    //how many ways a string can be decoded of length > 0, starting
    //1 and greater
    static int countDecoding (char[] digits, int n) {
        //base case
        if (n == 0 || n == 1)
            return 1;
        
        //base condition ex: 01123 returns 0
        if (digits[0] == '0')
            return 0;
        
        //init count
        int count = 0;
        
        //if last digit not 0, must add to num of words
        if (digits[n - 1] > '0')
            count = countDecoding(digits, n - 1);
        
        //if last 2 form num smaller or equal to 26, consider last 2 digits
        if (digits[n-2] == '1' || (digits[n-2] == '2' && digits[n-1] < '7'))
            count += countDecoding(digits, n-2);
        
        return count;
    }
    
    static int countWays(char[] digits, int n) {
        if (n == 0 || (n == 1 && digits[0] == '0'))
            return 0;
        return countDecoding(digits, n);
    }       
    
    public static void main(String[] args) {
    char digits[] = {'1','2','3','4'};
    int n = digits.length;
    System.out.printf("Count is %d", countWays(digits, n));
    }
}

/**
 *
 * @author blush
 */
