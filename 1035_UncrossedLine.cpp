#include<string>
#include <set>
#include<vector>
#include<iostream>
#include<map>
#include<stack>
#include <unordered_set>
#include <algorithm>    // std::min_element, std::max_element
using namespace std;

int best;
int getMax(vector<int>& A, vector<int>& B, vector<vector<int>> dp, vector<vector<int>> calc, int aIndex, int bIndex)
{
    if (aIndex == A.size() || bIndex == B.size())
            return 0;

   
    if (calc[aIndex][bIndex])
        return dp[aIndex][bIndex];

    cout << aIndex << "    |   " << bIndex << "   |   " << best << endl;
    best = max(best, getMax(A, B, dp, calc, aIndex + 1, bIndex));
    best = max(best, getMax(A, B, dp, calc, aIndex, bIndex + 1));


    if (A[aIndex] == B[bIndex])
        best = max(best, getMax(A, B, dp, calc, aIndex + 1, bIndex + 1)+1);

    dp[aIndex][bIndex] = best;
    calc[aIndex][bIndex] = 1;
    cout << best << endl;
    return best;

}
int maxUncrossedLines(vector<int>& A, vector<int>& B) {

    /*int lA = A.size();
    int lB = B.size();
    vector<vector<int>> dp(lA + 1, vector<int>(lB + 1, -1));
    vector<vector<int>> calc(lA + 1, vector<int>(lB + 1, 0));
    best = 0;*/

    //return getMax(A, B, dp, calc, 0, 0);

    int m = A.size(), n = B.size();
    // dp[i][j] represent max no of connecting lines between A[0...i-1] and B[0...j-1]
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (A[i - 1] == B[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    return dp[m][n];

}


int main1035()
{

	//int count = climbStairs(5);
	int N = 2;
    vector<int> a{1,4,2 };
    vector<int> b{ 1, 2, 4 };
    cout << "aIndex" << " | " << "bIndex" << " | " << "best" <<endl;
	int lnResult = maxUncrossedLines(a, b);
	cout << lnResult;
	return 0;
}