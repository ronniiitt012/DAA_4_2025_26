#include<bits/stdc++.h>
using namespace std;
int lcs(string s1, string s2){
    int m = s1.length();
    int n = s2.length();
    int dp[m+1][n+1];
    for(int i = 0; i <= m; i++){
        dp[i][0] = 0;
    }
    for(int j = 0; j <= n; j++){
        dp[0][j] = 0;
    }
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    } 
    return dp[m][n];
}
int longestPalindromicSubsequence(string s){
    string rev = s;
    reverse(rev.begin(), rev.end());
    return lcs(s, rev);
}
int main(){
    string str;
    cout << "Enter the string: ";
    cin >> str;   
    cout << "String: " << str << endl;
    cout << "Reverse: ";
    string rev = str;
    reverse(rev.begin(), rev.end());
    cout << rev << endl;
    int result = longestPalindromicSubsequence(str);
    cout << "Length of Longest Palindromic Subsequence: " << result << endl;
    return 0;
}
