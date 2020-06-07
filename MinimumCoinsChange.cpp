class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //DP Solution
        
        vector<int> dp(amount+1,INT_MAX);
        dp[0]=0;
        
        //Iterate through all amounts
        for(int i=1;i<=amount;i++){
            //Iterate through coins and check if the coin is less than given i
            for(int j=0;j<coins.size();j++){
                if(coins[j]<=i){
                    int temp=dp[i-coins[j]];
                    //Check if valid then add this coin to subproblem and replace with existing value
                    if(temp!=INT_MAX && temp+1<dp[i] )
                        dp[i]=temp+1;
                }
            }
        }
        if(dp[amount]==INT_MAX)
            return -1;
        return dp[amount];
    }
};