#include<string>
#include <set>
#include<vector>
#include<iostream>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<stack>
#include<unordered_set>
#include <iterator> 
using namespace std;

unordered_map <int , char> mp;
int c = 0;
void fillMap()
{
	mp[1] = 'a'; mp[2] = 'b'; mp[3] = 'c'; mp[4] = 'd'; mp[5] = 'e'; mp[6] = 'f'; mp[7] = 'g';
	mp[8] = 'h'; mp[9] = 'i'; mp[10] = 'j'; mp[11] = 'k'; mp[12] = 'l';/* mp['m'] = 13; mp['n'] = 14;
	mp['o'] = 15; mp['p'] = 16; mp['q'] = 17; mp['r'] = 18; mp['s'] = 19; mp['t'] = 20; */mp[21] = 'u';
	//mp['v'] = 22; mp['w'] = 23; mp['x'] = 24; mp['y'] = 25; mp['z'] = 26;
}

void permute(string s, int pos, string result)
{
	if (pos < s.length())
	{
		for (int j = pos; j >= 0; --j)
		{
			if (mp.find(s[j] - '0') != mp.end())
			{
				result += mp[s[j] - '0'];
				permute(s, j+1, result);
			}
		}
		if (result != "")
		{
			result = "";
			c++;
		}
	}
}
int findCombinations(string s)
{
	fillMap();
	for (int i = 0; i < s.length(); ++i)
	{
		string result;
		permute(s, i, result);
	}
	return c;
}

void reverse(vector<char>& s, int start, int end)
{
	if (start < end && start < s.size() && end >= 0)
	{
		swap(s[start], s[end]);
		reverse(s, start+1, end-1);
	}
}
void reverseString(vector<char>& s) {
	int end = s.size() - 1;
	reverse(s, 0, end);
}

unordered_set<string> setU;
void allCombinations(string tiles, int l,  int r)
{
	if (l >= 1)
	{
		string temp = tiles.substr(0, l);
		setU.insert(temp);
	}
		

	for (int i = l; i <= r; ++i)
	{
		swap(tiles[l], tiles[i]);
		allCombinations(tiles, l + 1, r);
		swap(tiles[l], tiles[i]);

		/*if(i+1 <tiles.length())
			swap(tiles[i], tiles[i + 1]);*/
	}
}
int numTilePossibilities(string tiles) {
	
    allCombinations(tiles, 0, tiles.length()-1 );
	return setU.size();
}


unordered_map<char, string> charToWordMap;
unordered_map<string, char> wordToCharMap;
bool wordPattern(string pattern, string str) {
	int j = 0;
	for (int i = 0; i < pattern.length(); ++i)
	{
		int k = j;
		while (j < str.length() && str[j] != ' ') j++;

		string temp = str.substr(k, j-k);

		j++;

		if (charToWordMap.find(pattern[i]) != charToWordMap.end())
		{
			string val = charToWordMap[pattern[i]];
			if (val != temp)
				return false;
		}
		else
		{
			charToWordMap[pattern[i]] = temp;
		}

		if (wordToCharMap.find(temp) != wordToCharMap.end())
		{
			char c = wordToCharMap[temp];
			if (c != pattern[i])
				return false;
		}
		else
		{
			wordToCharMap[temp] = pattern[i];
		}
	}
	return true;
}

int repeatedStringMatch(string a, string b) {
	vector<int> lps(b.size()); // longest proper suffix prefix array
	for (int i = 1, j = 0; i < b.size();) {
		if (b[j] == b[i])
			lps[i++] = ++j;
		else if (j == 0)
			i++;
		else
			j = lps[j - 1];
	}
	for (auto i = 0, j = 0; i < a.size(); i++, j = j ? lps[j - 1] : 0) {
		while (j < b.size() && a[(i + j) % a.size()] == b[j])
			++j;
		if (j == b.size())
			return ceil((float)(i + j) / a.size());
	}
	return -1;
}

map<string, multiset<string>> targets;
vector<string> route;
void visit(string airport) {
	while (targets[airport].size()) {
		string next = *targets[airport].begin();
		targets[airport].erase(targets[airport].begin());
		visit(next);
	}
	route.push_back(airport);
}
vector<string> findItinerary1(vector<vector<string>> tickets) {
	for (auto ticket : tickets)
		targets[ticket[0]].insert(ticket[1]);
	visit("JFK");
	return vector<string>(route.rbegin(), route.rend());
}

double minmaxGasDist(vector<int>& st, int K) {
	int count, N = st.size();
	double left = 0, right = st[N - 1] - st[0], mid;
	while (left + 1e-6 < right) {
		mid = (left + right) / 2;
		count = 0;
		for (int i = 0; i < N - 1; ++i)
			count += ceil((st[i + 1] - st[i]) / mid) - 1;
		if (count > K) left = mid;
		else right = mid;
	}
	return right;
}


set<string> setUnique;
void permuteCombination(string s, int pos)
{
	if (pos == s.length() - 1)
	{
		setUnique.insert(s);
		return;
	}

	for (int i = pos; i < s.length(); ++i)
	{
		//swap(s[i], s[pos]);
		permuteCombination(s, i + 1);
		swap(s[i], s[pos]);
	}
}
bool checkInclusion(string s1, string s2) {
	vector<int> cnts(256, 0);
	for (char ch : s1) {
		cnts[ch]++;
	}

	int left = s1.size();
	for (int i = 0, j = 0; j < s2.size(); j++) {
		if (cnts[s2[j]]-- > 0) {
			left--;
		}

		while (left == 0) {
			if (j + 1 - i == s1.size()) {
				return true;
			}
			if (++cnts[s2[i++]] > 0) {
				left++;
			}
		}
	}

	return false;
}
int main15()
{
	//int val = findCombinations("11");
	//vector<char> s = { 'h', 'e', 'l', 'l' }; reverseString(s);

	//int c = numTilePossibilities("AAB");
	//wordPattern("abab", "dog dog dog dog");

	//repeatedStringMatch("abcd", "cdabcdab");

	//vector<vector<string>> tickets = { {"MUC", "LHR"},{"JFK", "MUC"},{"SFO", "SJC"},{"LHR", "SFO"} };
	//findItinerary(tickets);
	
	//vector<int> st = { 1,5,7,8 };
	//double result =minmaxGasDist(st, 3);

	checkInclusion("ab", "eidbaooo");
	return 0;
}