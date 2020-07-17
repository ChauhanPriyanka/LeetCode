#include<string>
#include <set>
#include<vector>
#include<iostream>
#include<map>
#include<stack>
#include<set>
#include<unordered_set>
using namespace std;


bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) 
{
	if(words1.size() != words2.size())
	{
		return false;
	}

    map<string, set<string>> parent;
    for (auto p : pairs) {
        parent[p[0]].insert(p[0]);
        parent[p[0]].insert(p[1]);
        parent[p[1]].insert(p[0]);
        parent[p[1]].insert(p[1]);
    }

    for (int i = 0; i < words1.size(); i++) {
        stack<string> record;
        set<string> seen;
        record.push(words1[i]);
        seen.insert(words1[i]);
        bool matched = false;
        while (!record.empty()) {
            string word = record.top();
            record.pop();
            if (word == words2[i]) {
                matched = true;
                break;
            }
            for (auto nei : parent[word]) {
                if (seen.find(nei) == seen.end()) {
                    record.push(nei);
                    seen.insert(nei);
                }
            }

        }
        if (!matched)
            return false;

    }
    return true;
}

set<string> seen;
string sAnswer;

void dfs(string node, int k)
{
    for (int i = 0; i < k; ++i)
    {
        string nei = node + to_string(i);
        if (!seen.count(nei))
        {
            seen.insert(nei);
            dfs(nei.substr(1), k);
            sAnswer = sAnswer + to_string(i);
        }
    }
}
string crackSafe(int n, int k) {
    if (n == 1 && k == 1) return 0;

    string data(n-1, '0');

    dfs(data, k);
    sAnswer = sAnswer + data;
    return sAnswer;
}



string crackSafe1(int n, int k) {
    string ans = string(n, '0');
    unordered_set<string> visited;
    visited.insert(ans);

    for (int i = 0; i < pow(k, n); i++) {
        string prev = ans.substr(ans.size() - n + 1, n - 1);
        for (int j = k - 1; j >= 0; j--) {
            string now = prev + to_string(j);
            if (!visited.count(now)) {
                visited.insert(now);
                ans += to_string(j);
                break;
            }
        }
    }
    return ans;
}

string ans;
unordered_set<string> v;

void dfs2(string root, int k) {
    for (int i = 0; i < k; i++) {
        string node = root + to_string(i);
        if (v.find(node) == v.end()) v.insert(node), dfs(node.substr(1), k), ans += to_string(i);
    }
}

string crackSafe2(int n, int k) {
    string root;

    ans = "";
    v.clear();
    root.assign(n - 1, '0');

    dfs(root, k);
    return ans + root;
}

int oddEvenJumps2(vector<int>& A) {
    int N = A.size();
    vector<bool> even(N, false);
    vector<bool> odd(N, false);
    even[N - 1] = true;
    odd[N - 1] = true;
    int cnt = 1;
    map<int, int> m;
    m[A[N - 1]] = N - 1;
    map<int, int>::iterator it;
    for (int i = A.size() - 2; i >= 0; i--) {
        it = m.lower_bound(A[i]);
        if (it != m.end())
            odd[i] = even[it->second];
        if (odd[i])
            cnt++;
        it = m.upper_bound(A[i]);
        if (it != m.begin()) {
            it--;
            even[i] = odd[it->second];
        }
        m[A[i]] = i;
    }
    return cnt;
}
int oddEvenJumps(vector<int>& A) {
    vector<pair<int, int>> bound(A.size()); // odd/even jump
    bound.back() = { 1, 1 };

    map<int, int> indx;
    int total = 0;

    for (int i = A.size() - 1; i >= 0; --i) {
        auto upper = indx.lower_bound(A[i]); // return 1st elem s.t. >= val
        auto lower = indx.upper_bound(A[i]); // return 1st elem s.t. > val
        if (upper != indx.end()) {
            bound[i].first = bound[upper->second].second;
        }
        if (lower != indx.begin()) {
            --lower;
            bound[i].second = bound[lower->second].first;
        }
        total += bound[i].first; // if it works when starting at index `i`
        indx[A[i]] = i;
    }
    return total;
}

// A C++ program to check if a string is 'n' times 
// repetition of one of its substrings 
#include<iostream> 
#include<cstring> 
using namespace std;

// A utility function to fill lps[] or compute prefix funcrion 
// used in KMP string matching algorithm. Refer 
// https://www.geeksforgeeks.org/archives/11902 for details 
void computeLPSArray(char str[], int M, int lps[])
{
    int len = 0; //lenght of the previous longest prefix suffix 
    int i;

    lps[0] = 0; //lps[0] is always 0 
    i = 1;

    // the loop calculates lps[i] for i = 1 to M-1 
    while (i < M)
    {
        if (str[i] == str[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len]) 
        {
            if (len != 0)
            {
                // This is tricky. Consider the example AAACAAAA 
                // and i = 7. 
                len = lps[len - 1];

                // Also, note that we do not increment i here 
            }
            else // if (len == 0) 
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Returns true if str is repetition of one of its substrings 
// else return false. 
bool isRepeat(char str[])
{
    // Find length of string and create an array to 
    // store lps values used in KMP 
    int n = strlen(str);
    int lps[12];

    // Preprocess the pattern (calculate lps[] array) 
    computeLPSArray(str, n, lps);

    // Find length of longest suffix which is also 
    // prefix of str. 
    int len = lps[n - 1];

    // If there exist a suffix which is also prefix AND 
    // Length of the remaining substring divides total 
    // length, then str[0..n-len-1] is the substring that 
    // repeats n/(n-len) times (Readers can print substring 
    // and value of n/(n-len) for more clarity. 
    return (len > 0 && n % (n - len) == 0) ? true : false;
}

// Driver program to test above function 
int main11()
{
    char txt[][100] = { "ABCABCABCABC" };
    //"ABABAB", "ABCDABCD", "GEEKSFORGEEKS",
                       //"GEEKGEEK", "AAAACAAAAC", "ABCDABC" };
    int n = sizeof(txt) / sizeof(txt[0]);
    for (int i = 0; i < n; i++)
        isRepeat(txt[i]) ? cout << "True\n" : cout << "False\n";
    return 0;
}
int main10()
{
	/*vector<string> words1;
	words1.push_back("great");
	words1.push_back("acting");
	words1.push_back("skills");

	vector<string> words2;
	words2.push_back("fine");
	words2.push_back("drama");
	words2.push_back("talent");

	vector<vector<string>> pairs;
	vector<string> sent1;
	sent1.push_back("great");
	sent1.push_back("good");

	vector<string> sent2;
	sent2.push_back("fine");
	sent2.push_back("good");


	vector<string> sent3;
	sent3.push_back("acting");
	sent3.push_back("drama");

	vector<string> sent4;
	sent4.push_back("talent");
	sent4.push_back("skills");
	pairs.push_back(sent1);
	pairs.push_back(sent2);
	pairs.push_back(sent3);
	pairs.push_back(sent4);

	areSentencesSimilarTwo(words1, words2, pairs);
    */

    //cout<<crackSafe(2,2);
    vector<int> vec{ 10,13,12,14,15 };
    std::cout<<oddEvenJumps2(vec);
    return 0;
}