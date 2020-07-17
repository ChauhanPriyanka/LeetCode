#include<string>
#include <set>
#include<vector>
#include<iostream>
#include<map>
#include<stack>
#include <unordered_set>
#include <algorithm>    // std::min_element, std::max_element
using namespace std;
int f(int n, vector<int>&arr)
{
	if (n == 0 || n == 1) return 1;
	if (arr[n] != 0) return arr[n];
	else {
		arr[n] = f(n - 1, arr) + f(n - 2, arr);
		return arr[n];
	}
}



bool isHappy(int n)
{
    string s = to_string(n);
    int sum = 0;

    while (1)
    {
        for (int i = 0; i < s.length(); i++)
        {
            int a = s[i] - '0';
            sum += a * a;
        }

        if (sum == 1)
        {
            return true;
        }
        else if (sum > 1 && sum <= 9)
        {
            break;
        }
        else if (sum > 9)
        {
            s = to_string(sum);
            sum = 0;
        }
    }
    return false;
}

int climbStairs(int n) 
{
	//* p = (int*)malloc(sizeof(int) * (n + 1));
	vector<int> p(n + 1, 0);
	int res, i;

	if (n == 0 || n == 1) p[n] = 1;  //Base condition

	
	res = f(n, p);
	//free(p);

	return res;
}

int main76()
{
	
	//int count = climbStairs(5);
    bool bResult = isHappy(1111111);
	return 0;
}