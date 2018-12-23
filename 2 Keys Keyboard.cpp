#include<bits/stdc++.h>
using namespace std; 
/*
  QAQ 35.44% 
*/
class Solution {
public:
    int minSteps(int n) {
        int dp[n+1];
        dp[0] = dp[1] = 0;
        for(int i=2; i<=n; i++){
            dp[i] = i; //最大不超过i
            for(int j=i/2+1; j>=1; j--){ 
                if(i % j == 0){
                    dp[i] = min(dp[i], i/j+dp[j]);
                    break;
                }
            }
        }
        return dp[n];
    }
    /*int minSteps(int n) {
        return DP(n);
    }
    int DP(int n){
        if(n==1){
            return 0;
        }
        for(int i=n/2+1; i>=1; i--){
            if(n%i == 0){
                return (n/i + DP(i));
            }
        }
    }*/
};
