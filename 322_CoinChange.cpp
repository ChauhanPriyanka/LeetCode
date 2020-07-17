#include<string>
#include <set>
#include<vector>
#include<iostream>
#include<map>
#include<stack>
#include <unordered_set>
#include <algorithm>    // std::min_element, std::max_element
using namespace std;


int coinChange(vector<int>& coins, int amount)
{
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++)
    {
        for (int j = 0; j < coins.size(); j++)
        {
            if (coins[j] <= i)
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}

int main322()
{
    vector<int> coins = { 1,2,5 };
    int amt = 11;
    coinChange(coins, amt);
    return 0;
}