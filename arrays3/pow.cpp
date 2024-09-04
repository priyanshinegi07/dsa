#include<iostream>
using namespace std;
//brute : run a loop from 1 to n and multiply ans to x
//if n can be -ve : so we return 1/ans, we calculate ans for x^n
//if n can be any integer then there might be overflow while converting negative n to positive so we store n in new long long variable
//TC : O(n) SC : O(1)

//approach 2
//TC : O(log(base2)n) SC : O(1)
//2^10 = (2*2)^5 = 4^5
//4^5 = 4*4^4 
//4^4 = (4*4)^2
//16^2 = (16*16)^1
//256^1 = 256*256^0 so we stop here when n is 0
class Solution {
public:

    double myPow(double x, int n) {
    double ans = 1.0;
    long new_n = n;
    if(n < 0) new_n = -1 * new_n;
    while(new_n > 0) {
        if(new_n % 2 == 0) {
            x = x*x;
            new_n /= 2;
        }
        else {
            ans = ans * x;
            new_n -= 1;
        }
        }
        return (n < 0) ? 1/ans : ans;
        // return ans*ans;

    }   
};