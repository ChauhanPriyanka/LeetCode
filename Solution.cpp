#include<string.h>
#include <set>
#include<vector>
#include<iostream>
#include<map>
#include<algorithm>
#include<stack>
using namespace std;


int maxSubArray(vector<int>& nums)
{
	int sum = 0;
	int sMaxSum = INT_MIN;

	if(nums.size() == 1)
	{
		return nums[0];
	}
	for(int i = 0; i< nums.size();i++)
	{
		sum =  nums[i] + sum;
		sMaxSum = max(sum, sMaxSum);
		//if(sum < 0)
		// {
		//   sum =  0;

		//}
	}
	return sMaxSum;
}

string longestPalindrome(string s)
{
	int count = 0, max = 0, location =0, start =0, end = 0;
	for(int i = 0;i<(s.length()-1);i++)
	{
		int left = i;
		int right = i;
		count = 0;
		while(left>0)
		{
			if(s[left--] != s[right++])
			{
				break;
			}
			count++;
		}
		if(count > max)
		{
			location = i;
			max = count;
		}
	}
	//std::cout<<max<<"@"<<location;
	start = location-max;
	end = location+max;
	string s1 = "";
	for(int i= start;i<=end;i++)
	{
		char sChar = s[i];
		string s2(1,sChar);
		//s1 = s1+ s2;
		std::cout<<s[i];
	}
	return s1;
}

int maxProduct(vector<int>& nums) {
        
        int maxMulti = 1;
        int currentMulti = 1;
        for(int i=0;i<nums.size(); i++)
        {
            currentMulti = currentMulti * nums[i];
            maxMulti = max(currentMulti, maxMulti);
            if(currentMulti <= 0 )
            {
                currentMulti = 1;
            }
        }
        return maxMulti;
    }
int lengthOfLongestSubstring(string s) 
{
	int i = 0, j = 0;
	set<char> setUniqeSubStr;
	int len = s.length();
	int strSubStringLen = 0;
	set<char>::iterator it;
	while(i<len && j<len)
	{
		it = setUniqeSubStr.find(s[j]);

		if(it ==setUniqeSubStr.end() )
		{
			setUniqeSubStr.insert(s[j++]);
			strSubStringLen = max(strSubStringLen, j-i);

		}
		else
		{
			setUniqeSubStr.erase(s[i++]);
		}
	}
	return strSubStringLen;
}

int lengthOfLongestSubstring1(string s) {
	vector<int> dict(256, -1);
	int maxLen = 0, start = -1;
	for (int i = 0; i != s.length(); i++) {
		if (dict[s[i]] > start)
			start = dict[s[i]];
		dict[s[i]] = i;
		maxLen = max(maxLen, i - start);
	}
	return maxLen;
}

int romanToInt(string s) {
        map<char,int> mMap;
        
		mMap['I'] = 1;
        mMap['V'] = 5;
        mMap['X'] = 10;
		mMap['L'] = 50;
		mMap['C'] = 100;
		mMap['D'] = 500;
		mMap['M'] = 1000;     
        
        int len = s.length();
        int total = mMap[s[len-1]];
		
        for(int i = len-2; i>=0; i--)
        {
            int val = mMap[s[i]];
            if(val<mMap[s[i+1]])
            {
                total -= val;
            }
            else
            {
                total += val;
            }
        }
        
        return total;
    }

string intToRoman(int num) {

	const string THOUS[]	= {"","M","MM","MMM"};
	const string HUNDS[]	= {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
	const string TENS[]	= {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
	const string ONES[]	= {"","I","II","III","IV","V","VI","VII","VIII","IX"};
	string result;
	result += THOUS[(int)(num/1000)%10];
	result += HUNDS[(int)(num/100)%10];
	result += TENS[(int)(num/10)%10];
	result += ONES[num%10];
	return result;
}

bool isValid(string s) {

	stack <int> stk;
	for(int i =0; i<=s.length()-1; i++)
	{
		char c = s[i];
		switch(c)
		{
		case '(': stk.push(')');break;
		case '{': stk.push('}');break;
		case '[': stk.push(']');break;
		default:
			{
				if(stk.size() == 0 || c != stk.top()) 
					return false;
				else stk.pop();
			}
		}

	}
	return stk.size()==0;  
}


   int trap(vector<int>& height) {
        
        //brute force
        /*Iint answer = 0;
        int n = height.size();
        for(int i = 0; i<n ; i++)
        {
            int maxLeft = 0;
            int maxRight = 0;
            for(int j = i; j>=0; j--)
            {
                maxLeft = max(maxLeft, height[j]);
            }
            
             for(int j = i; j<n; j++)
            {
                maxRight = max(maxRight, height[j]);
            }
            
            answer += min(maxLeft, maxRight) - height[i];
        }
        return answer;
        */
        int answer = 0;
        int left = 0;
        int right = height.size()-1;
        int leftMax=0, rightMax =0;
        
        while(left<right)
        {
            if(height[left] < height[right])
            {
                if(height[left] >= leftMax)
                {
                    leftMax = height[left];
                   
                   
                }
				 answer += leftMax-height[left] ;
				 left++;
            }
            else
            {
                if(height[right] >= rightMax)
                {
					rightMax =height[right];               
                }
                  answer+=rightMax-height[right];
				 right--;
            }
        }
         return answer;
    }


    string minWindow(string s, string t) {
        int slen = s.size(), tlen = t.size(), i, start=0, count, minL = INT_MAX, minS;
        int dict[128];
        fill_n(dict,128,-slen);
        for(i=0;i<tlen;++i) dict[t[i]] = dict[t[i]]>0? (dict[t[i]]+1):1;
        
        for(i=0, count = tlen; i<slen;++i)
        {
            if( (--dict[s[i]]>=0) && (--count == 0) )
            {
                while(dict[s[start]]<=-slen || (++dict[s[start]] <= 0) ) ++start;
                if(minL>i-start+1)
                {
                    minL = i-start+1;
                    minS = start; 
                }
                count=1;
                ++start;
            }
        }
        return minL==INT_MAX? "":s.substr(minS, minL);
    }

int main1()
{

	string a = minWindow("ADOBECODEBANC","ABC");
	cout<<a.c_str();
	/*bool bResult  = isValid("()");
	cout<<bResult;*/
	/*string s = intToRoman(10);
	cout<<s.c_str();*/
	//lengthOfLongestSubstring("pwwkew");
	/*vector<int> vec;
	vec.push_back(-2);
	vec.push_back(-1);
	maxSubArray(vec);*/

	//longestPalindrome("babad");

	vector<int> vec;
		vec.push_back(1);
	vec.push_back(0);
		vec.push_back(2);
	
	trap(vec);
	//bool bResult = isIsomorphic("ab", "aa");


	//int total = romanToInt("CDXCVIII");
	//cout<<total;

	/*vector<int> vec;
	vec.push_back(-1);
	vec.push_back(0);
	vec.push_back(2);
	vec.push_back(4);*/
	//maxSubArray(vec);
	//maxProduct(vec);
	return 0;
}