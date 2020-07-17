

#include<string>
#include <set>
#include<iostream>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<stack>
#include<unordered_set>
#include <iterator> 
#include<vector>

using namespace std;
const std::string space = " \n\r\t\f\v";

string reverse(string& s) {
	int start = 0;
	int end = s.length() - 1;
	while (start <= end) {
		swap(s[start], s[end]);
		start++; end--;
	}
	return s;
}

string reverseWords(string s) {

	string sResult;

	s = reverse(s);

	cout << s;

	int left = 0;
	int right = 0;
	while (right < s.length()) {
		left = right;

		//till next space is found
		while (right < s.length() && s[right] != ' ') {
			right++;
		}
		
		//we found a word from left to right-1

		string sVal = s.substr(left, (right - left));
		sResult = sResult == "" ? reverse(sVal) : sResult + " " + reverse(sVal);

		//right is at space
		right++; 

		//trim the extra space in the middle
		while (right < s.length() && s[right] == ' ') {
			right++;
		}
	}

	size_t startPos = sResult.find_first_not_of(space);
	sResult = (startPos == std::string::npos) ? "" : sResult.substr(startPos);

	size_t endPos = s.find_last_not_of(space);
	sResult = (endPos == std::string::npos) ? "" : sResult.substr(0, endPos + 1);
	return sResult;
}

int main(void) {

	string sResult = reverseWords("aaaaaaaaaaaaaaa");
	cout << sResult;
	return 0;
}