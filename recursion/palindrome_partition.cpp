// tc : O( (2^n) *k*(n/2) )
// sc : O(k * x) x is no of palindromes
class Solution {
public:
    bool is_palindrome(string s, int start, int end) {
        while(start <= end) {
            if(s[start] != s[end]) return false;
            start ++; end--;
        }
        return true;

    }
    void generate_palindrome_substr(string &s, int n, int indx, vector<vector<string>>&ans, vector<string>&curr) {
        //base case
        if(indx == n) {
            ans.push_back(curr);
            return;
        }
        //recursive case
        for(int i = indx; i < n; i++) {
            if(is_palindrome(s, indx, i)) {
                //partition
                curr.push_back(s.substr(indx, i - indx + 1));
                generate_palindrome_substr(s, n, i + 1, ans, curr);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>curr;
        
        int i = 0;
        generate_palindrome_substr(s, s.size(), i, ans, curr);
        
        return ans;
    }
};