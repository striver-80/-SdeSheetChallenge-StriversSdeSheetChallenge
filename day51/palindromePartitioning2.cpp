#include<vector>
bool isPalindrome(int i, int j, string &s){
    while(i <= j){
        if(s[i] != s[j]) return false;
        i++; j--; 
    } return true;
}
int f(int i, int n, string &s, vector<int> &dp){
    if(i == n) return 0;
    if(dp[i] != -1) return dp[i];
    
    int mini = INT_MAX;
    for(int j = i; j<n; j++){
        if(isPalindrome(i, j, s)){
           int cost = 1+f(j+1, n, s, dp);
            mini = min(mini, cost);
        }
    } return dp[i] = mini;
}
int palindromePartitioning(string str) {
    // Write your code here
    int n = str.size();
    vector<int> dp(n+1, -1);
    return f(0, n, str, dp)-1;
}
