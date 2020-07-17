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
#include<queue>

using namespace std;


void  dfsHelper(vector<vector<int>>& res, vector<int>& path, unordered_map<int, int>& numMap, int len)
{
    if (path.size() == len) { res.push_back(path); return; }
    for (auto it = numMap.begin(); it != numMap.end(); ++it)
    {
        if (it->second)
        {
            path.push_back(it->first); // update the current path
            --(it->second); // and map
            dfsHelper(res, path, numMap, len); // then do dfs at the next level
            path.pop_back(); // backtracking by recovering path and map
            ++(it->second);
        }
    }
}

void dfs(vector<vector<int>>& res, vector<int>& cur, vector<int> canVec, int len)
{
    if (cur.size() == len)
    {
        res.push_back(cur);
    }
    else
    {
        for (auto i = 0; i < canVec.size(); ++i)
        {
            if (i > 0 && canVec[i] == canVec[i - 1]) continue;
            cur.push_back(canVec[i]);
            vector<int> temp = canVec;
            temp.erase(temp.begin() + i);
            dfs(res, cur, temp, len);
            cur.pop_back();
        }
    }
}

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        //int i, len = nums.size();
        //vector<vector<int>> res;
        //if (len > 0)
        //{
        //    vector<int> path;

        //    unordered_map<int, int> numMap; //generate a map
        //    for (i = 0; i < len; ++i) ++numMap[nums[i]];

        //    dfsHelper(res, path, numMap, len);
        //}
        //return res;

        vector<vector<int>> res;
        int  len = nums.size();
        if (len > 0)
        {
            vector<int> cur;
            std::sort(nums.begin(), nums.end());
            dfs(res, cur, nums, len);
        }
        return res;
    }


void plantFlowerInGarden(int G, vector<int> adjG, vector<int>& result)
    {
        bool found;
        for (int f = 1; f <= 4; ++f)
        {
            found = true;
            for (int n : adjG)
            {
                if (result[n] != -1 && result[n] == f)
                    found = false;
            }
            if (found)
            {
                result[G] = f;
                return;
            }
        }
    }

vector<vector<int>> graph;
vector<int> flowers;
vector<int> gardenNoAdj1(int N, vector<vector<int>>& paths) {
        vector<int> result(N, -1);
        //graph(N);

        for (auto e : paths)
        {
            graph[e[0] - 1].push_back(e[1] - 1);
            graph[e[1] - 1].push_back(e[0] - 1);
        }

        for (int i = 0; i < N; ++i)
            plantFlowerInGarden(i, graph[i], result);
        return result;
    }

bool used(int i, int flower) {
    for (auto& neighbor : graph[i])
        if (flowers[neighbor - 1] == flower)
            return true;
    return false;
}

void dfs1(int i) {
    if (flowers[i - 1])
        return; // already visited

    int f = 1;
    while (used(i, f))
        f++;
    flowers[i - 1] = f;

    for (auto& neighbor : graph[i]) {
        dfs1(neighbor);
    }
}

vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
    graph.resize(N + 1);
    flowers.resize(N);
    for (auto& path : paths) {
        graph[path[0]].push_back(path[1]);
        graph[path[1]].push_back(path[0]);
    }
    for (int i = 1; i <= N; ++i) {
        dfs1(i);
    }
    return flowers;
}

vector<string> letterCombinations(string digits)
{
    string alphabet[] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    vector<string> result;

    if (digits.empty()) return result;
    result.push_back("");
    for (int i = 0; i < digits.length(); ++i)
    {
        int val = digits[i] - '0';
        if (val > 0 || val < 9)
        {
            string sequnece = alphabet[val];
            if (sequnece.empty()) return result;
            vector<string> temp;
            for (int i = 0; i < sequnece.length(); ++i)
            {
                for (int j = 0; j < result.size(); ++j)
                {
                    temp.push_back(result[j] + sequnece[i]);
                }
            }

            result.swap(temp);
        }
    }

    return result;
}

//BFS
vector<string> letterCombinations2(string digits) {
    if (digits.empty()) {
        return vector<string>();
    }
    vector<string> words{ " ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    deque<string> q;
    q.push_back("");

    for (char digit : digits) {
        int d = digit - '0';
        for (int i = q.size(); i > 0; i--) {
            string token = q.front();
            q.pop_front();
            for (char ch : words[d]) {
                q.push_back(token + ch);
            }
        }
    }

    return vector<string>(q.begin(), q.end());
}
/**
 * start with an empty builder, for every digit, use all chars it represents to attach to the builder, when i reaches the end of digits, push builder to result;
 */
void build(string builder, int i, const string& digits, const vector<string>& chars, vector<string>& combs) {
    if (i == digits.size()) {
        combs.push_back(builder);
        return;
    }

    int d = digits[i] - '0';
    for (char ch : chars[d]) {
        build(builder + ch, i + 1, digits, chars, combs);
    }
}
vector<string> letterCombinations3(string digits) {
    if (!digits.size()) {
        return {};
    }

    vector<string> combs;
    const vector<string> chars = { "0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    string builder;
    build(builder, 0, digits, chars, combs);
    return combs;
}


void Recursion(vector<string>& vec, string str, int counter, int left, int right) {
    if (counter < 0)return;
    if (left == 0 && right == 0) {
        vec.push_back(str);
        return;
    }
    if (left) {
        Recursion(vec, str + "(", counter + 1, left - 1, right);
    }
    if (right) {
        Recursion(vec, str + ")", counter - 1, left, right - 1);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> vec;
    Recursion(vec, "", 0, n, n);
    return vec;
}


int countIter = 0;
void permute(vector<int> nums, int i, vector<vector<int>>& perms) {

    countIter++;
  
    if (i == nums.size()) {
        perms.push_back(nums);
        cout << "********" << i << "**********\n";
    }
    else {
        for (int j = i; j < nums.size(); j++) {
            swap(nums[i], nums[j]);
            cout << "i: " << i << "  j:"<<j <<"\n";
            permute(nums, i + 1, perms);
            cout << "back i: " << i << " back j:" << j << "\n";
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> perms;
    permute(nums, 0, perms);
    return perms;
}


void check(vector<vector<char>>& board, int i, int j) {
    if (board[i][j] == 'O') {
        board[i][j] = '1';
        if (i > 1) check(board, i - 1, j);
        if (j > 1) check(board, i, j - 1);
        if (i + 1 < board.size()) check(board, i + 1, j);
        if (j + 1 < board[0].size()) check(board, i, j + 1);
    }
}
void solve(vector<vector<char>>& board) {
    if (board.empty()) return;
    int row = board.size(), col = board[0].size();
    for (int i = 0; i < row; ++i) {
        check(board, i, 0);             // first column
        check(board, i, col - 1);       // last column
    }
    for (int j = 1; j < col - 1; ++j) {
        check(board, 0, j);             // first row
        check(board, row - 1, j);       // last row
    }
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j)
            if (board[i][j] == 'O') board[i][j] = 'X';
            else if (board[i][j] == '1') board[i][j] = 'O';
}

int numUniqueEmails(vector<string>& emails) {
    set<string> setUniqueEmails;
    for (auto email : emails)
    {
        int pos1 = email.find('+');
        int pos2 = email.find('@');
        cout << pos2;
        string sNewEmail;
        for (int i = 0; i < email.size(); ++i)
        {
            if (i < pos2 && email[i] == '.')
                continue;

            if (email[i] == '+')
                continue;

            if (pos1!= -1 && i > pos1&& i < pos2)
                continue;

            sNewEmail = sNewEmail + email[i];
        }
        if (!setUniqueEmails.count(sNewEmail))
        {
            setUniqueEmails.insert(sNewEmail);
        }
    }
    return setUniqueEmails.size();
}

void rotate(vector<int>& nums, int k) {
    k = k % nums.size();
    int count = 0;
    for (int start = 0; count < nums.size(); start++)
    {
        int current = start;
        int prev = nums[start];
        do
        {
            int next = (current + k) % nums.size();
            int temp = nums[next];
            nums[next] = prev;
            prev = temp;
            current = next;
            count++;
        } while (start != current);
    }
}

void sortColors(vector<int>& nums) {

    int low = 0, mid = 0, high = nums.size() - 1;
    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            swap(nums[low], nums[mid]);
            low++; mid++;

        }
        else if (nums[mid] == 1)
        {
            mid++;
        }
        else if (nums[mid] == 2)
        {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

bool wordBreak(string s, vector<string>& wordDict)
{
    if (s.empty() || wordDict.empty())
        return false;

    vector<int> dp(s.size() + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= s.size(); i++) {
        for (const string& word : wordDict) {
            int len = word.size();
            if (i - len >= 0 &&
                s.substr(i - len, len) == word && dp[i - len] == 1) {
                dp[i] = 1;
            }
        }
    }

    return dp[s.size()] == 1;

}

void dfs2(int l, int r, string solution, vector<string>& ans) {
    if (l == r) {
        solution[l] = '0';
        ans.push_back(solution);
        solution[l] = '1';
        ans.push_back(solution);
        solution[l] = '8';
        ans.push_back(solution);
        return;
    }
    else if (l > r) {
        ans.push_back(solution);
        return;
    }

    solution[l] = solution[r] = '1';
    dfs2(l + 1, r - 1, solution, ans);
    solution[l] = solution[r] = '8';
    dfs2(l + 1, r - 1, solution, ans);
    solution[l] = '6', solution[r] = '9';
    dfs2(l + 1, r - 1, solution, ans);
    solution[l] = '9', solution[r] = '6';
    dfs2(l + 1, r - 1, solution, ans);
    if (l != 0) {
        solution[l] = solution[r] = '0';
        dfs2(l + 1, r - 1, solution, ans);
    }
}
vector<string> findStrobogrammatic(int n) {
    vector<string> ans;
    if (n <= 0)  return ans;
    string solution;
    for (int i = 0; i < n; i++) solution += "0";
    int l = 0, r = n - 1;
    dfs2(l, r, solution, ans);
    return ans;
}

string reorganizeString(string str) {

    int strSize = str.size();
    if (strSize < 2)
        return str;

    vector<int> freq(26, 0);
    int freqChar = -1, freqCharCount = -1;

    for (int i = 0; i < strSize; i++) {
        freq[str[i] - 'a']++;
        if (freq[str[i] - 'a'] > freqCharCount) {
            freqCharCount = freq[str[i] - 'a'];
            freqChar = str[i] - 'a';
        }
    }

    if (freqCharCount > (strSize + 1) / 2)
        return "";


    int position = 0;

    for (int i = -1; i < 26; i++) {
        int current = (i == -1) ? freqChar : i;
        while (freq[current]-- > 0) {
            str[position] = 'a' + current;
            position = (position + 2 >= strSize) ? 1 : position + 2;
        }
    }
    return str;
}

string rearrangeString(string str, int k) {
    int maxFreq = 0;
    int freqs[26];
    memset(freqs, 0, sizeof(freqs));

    for (char c : str) {
        freqs[c - 'a']++;
        maxFreq = max(maxFreq, freqs[c - 'a']);
    }

    vector<string> buckets(maxFreq, "");

    for (int i = 0; i < 26; i++) {
        if (freqs[i] == maxFreq) {
            char c = 'a' + i;
            for (int k = 0; k < freqs[i]; k++) {
                buckets[k] += c;
            }
        }
    }

    for (int i = 0; i < 26; i++) {
        if (freqs[i] == maxFreq - 1) {
            char c = 'a' + i;
            for (int k = 0; k < freqs[i]; k++) {
                buckets[k] += c;
            }
        }
    }

    int bIdx = 0;
    for (int i = 0; i < 26; i++) {
        if (freqs[i] < maxFreq - 1) {
            char c = 'a' + i;
            for (int k = 0; k < freqs[i]; k++) {
                buckets[bIdx] += c;
                bIdx = (bIdx + 1) % (maxFreq - 1);
            }
        }
    }

    string ans = "";
    for (int i = 0; i < maxFreq; i++) {
        if (i < maxFreq - 1 && buckets[i].length() < k) {
            return "";
        }
        ans += buckets[i];
    }
    return ans;
}

string countAndSay(int n) 
{
    if (n == 0) return "";
    string res = "1";
    while (--n) 
    {
        string cur = "";
        for (int i = 0; i < res.size(); i++) 
        {
            int count = 1;
            while ((i + 1 < res.size()) && (res[i] == res[i + 1]))
            {
                count++;
                i++;
            }
            cur += to_string(count) + res[i];
        }
        res = cur;
    }
    return res;
}
void moveZeroes(vector<int>& nums) {
    int last = 0, cur = 0;

    while (cur < nums.size()) {
        if (nums[cur] != 0) {
            swap(nums[last], nums[cur]);
            last++;
        }

        cur++;
    }
}

int findPeakElement(const vector<int>& num)
{
    int low = 0;
    int high = num.size() - 1;

    while (low < high)
    {
        int mid1 = (low + high) / 2;
        int mid2 = mid1 + 1;
        if (num[mid1] < num[mid2])
            low = mid2;
        else
            high = mid1;
    }
    return low;
}

unordered_set<string> words;

void constructSentence(const string& s,
    const vector<int>& dp,
    int pos,
    vector<string>& res,
    string temp) {
    for (int i = pos + 1; i < dp.size(); ++i) {
        if (dp[i]) {
            string new_word = s.substr(pos, i - pos);
            if (words.count(new_word)) {
                if (i + 1 == dp.size()) {
                    res.push_back(temp + new_word);
                    return;
                }
                constructSentence(s, dp, i, res, temp + new_word + " ");
            }
        }
    }
}
    vector<string> wordBreakII(string s, vector<string>& wordDict) {
        words.clear();
        copy(wordDict.begin(), wordDict.end(), std::inserter(words, words.end()));

        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (dp[j]) {
                    if (words.count(s.substr(j, i - j))) {
                        dp[i] = 1;
                        break;
                    }
                }
            }
        }

        vector<string> res;
        if (dp[n]) {
            constructSentence(s, dp, 0, res, "");
        }
        return res;
    }

 /*   bool two_dig(string s, int beg)
    {
        return (s[beg - 1] == '1' || (s[beg - 1] == '2' && s[beg] <= '6'));
    }
    int numDecodings(string s)
    {
        int len = s.length();
        if (len == 0 || s[0] == '0')
            return 0;
        int res = 0;
        vector<int > dp(len, 0);
        dp[0] = 1;
        if (s[1] > '0')
            dp[1] = 1;
        if (two_dig(s, 1))
            dp[1] += 1;
        for (int i = 2; i < len; ++i) {
            bool f = (s[i] > '0' || two_dig(s, i));
            if (!f)
                return 0;
            if (s[i] > '0')
                dp[i] = dp[i - 1];
            if (t
        }
    }*/

    
    int longestConsecutive(vector<int>& num) {
        unordered_map<int, int> m;
        int r = 0;
        for (int i : num) 
        {
            if (m[i]) continue;
            int before = m[i - 1];
            int after = m[i + 1];
            int atIM1 = m[i - m[i - 1]];
            int atIP1 = m[i + m[i + 1]];
            int val = m[i] = m[i + m[i + 1]] = m[i - m[i - 1]] = m[i + 1] + m[i - 1] + 1;
            r = max(r, val);
        }
        return r;
    }

    int kEmptySlots(vector<int>& flowers, int k) {
        vector<int> days(flowers.size());
        for (int i = 0; i < flowers.size(); i++)days[flowers[i] - 1] = i + 1;
        int left = 0, right = k + 1, res = INT_MAX;
        for (int i = 0; right < days.size(); i++) {
            if (days[i] < days[left] || days[i] <= days[right]) {
                if (i == right)res = min(res, max(days[left], days[right]));    //we get a valid subarray
                left = i, right = k + 1 + i;
            }
        }
        return (res == INT_MAX) ? -1 : res;
    }

    string nextClosestTime(string time)
    {
        set<char> sorted;
        for (auto c : time)
        {
            if (c == ':') continue;
            sorted.insert(c);
        }

        string res = time;
        for (int i = time.size() - 1; i >= 0; i--)
        {
            if (time[i] == ':') continue;
            auto it = sorted.find(time[i]);
            if (*it != *sorted.rbegin())
            {// not the largest number
                it++; // go to the next element
                res[i] = *it;
                if ((i >= 3 && stoi(res.substr(3, 2)) < 60) || (i < 2 && stoi(res.substr(0, 2)) < 24))
                    return res;
            }
            res[i] = *sorted.begin(); // take the smallest number

        }
        return res;
    }

    bool similar(vector<int>& a)
    {
        for (int i = 1; i < a.size(); ++i)
        {
            if (a[i] != a[i - 1])
            {
                return false;
            }
        }
        return true;
    }
    int minDominoRotations(vector<int>& A, vector<int>& B) {

        if (A.size() != B.size()) return -1;
        map<int, int> mpA;
        map<int, int> mpB;
        map<int, int> ::iterator it;
        for (int i = 0; i < A.size(); ++i)
        {
            mpA[A[i]]++;
            mpB[B[i]]++;
        }

        //get the highest frequency element from both the map
        pair<int, int> maxA;;
        pair<int, int> maxB;;
        for (it = mpA.begin(); it != mpA.end(); ++it)
        {
            if (it->second > maxA.second)
            {
                maxA.second = it->second;
                maxA.first = it->first;
            }
        }

        for (it = mpB.begin(); it != mpB.end(); ++it)
        {
            if (it->second > maxB.second)
            {
                maxB.second = it->second;
                maxB.first = it->first;
            }
        }
        int i = 0; bool bIsA = false;
        int swap = 0, item = 0;
        if (maxA.second > maxB.second)
        {
            item = maxA.first;
            bIsA = true;
        }
        else
        {
            item = maxB.first;
        }

        while (i < A.size())
        {
            if (bIsA)
            {
                //item to be replaced in A
                if (A[i] != B[i] && A[i] != item)
                {
                    int val = B[i];
                    B[i] = A[i];
                    A[i] = B[i];

                    swap++;
                    //check if(all the elements are similar)
                    if (similar(A))
                        return swap;
                }
            }
            else
            {
                //item to be replaced in B
            }
            i++;
        }
        return -1;
    }

    void duplicateZeros(vector<int>& A) {
        int n = A.size(), j = n + count(A.begin(), A.end(), 0);
        for (int i = n - 1; i >= 0; --i) 
        {
            if (--j < n)
                A[j] = A[i];
            if (A[i] == 0 && --j < n)
                A[j] = 0;
        }
    }

    void bfs(vector<vector<int>>& graph, vector<int>& color, int i, bool bIs_bipartite)
    {
        queue<int> q;
        color[i] = 1;
        q.push(i);

        while (!q.empty())
        {
            int u = q.front(); q.pop();
            for (int v : graph[u])
            {
                if (color[v] == 2) //not visited
                {
                    color[v] = 1 - color[u];
                    q.push(v);
                }
                else if (color[u] == color[v])
                    {
                        bIs_bipartite = false;
                        return;
                    }
                
            }
        }
    }
    bool isBipartite(vector<vector<int>>& graph)
    {
        vector<int> color(graph.size(), 2);
        bool bIs_bipartite = true;
        for (int i = 0; i < graph.size(); ++i)
        {
            if (color[i] == 2)
            {
                bfs(graph, color, i, bIs_bipartite);
            }
        }
        return bIs_bipartite;
    }

    int findDuplicate(vector<int>& nums) {
        int result = 0;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] == nums[i - 1])
            {
                return nums[i];
            }
            if (nums[i] < nums[i - 1])
            {
                int j = i;
                while (j - 1 >= 0 && nums[j - 1] > nums[j])
                {
                    swap(nums[j], nums[j - 1]);
                    j--;
                    if (j - 1 >= 0 && nums[j] == nums[j - 1])
                        return true;
                }
            }
        }
        return result;
    }

    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> cnt, tails;
        for (int& i : nums) cnt[i]++;
        for (int& i : nums) {
            if (!cnt[i]) continue;
            cnt[i]--;
            if (tails[i - 1] > 0) {
                tails[i - 1]--;
                tails[i]++;
            }
            else if (cnt[i + 1] && cnt[i + 2]) {
                cnt[i + 1]--;
                cnt[i + 2]--;
                tails[i + 2]++;
            }
            else return false;
        }
        return true;
    }
    string addBinary(string a, string b)
    {
        string result = ""; // Initialize result 
        int s = 0;          // Initialize digit sum 

        // Traverse both strings starting from last 
        // characters 
        int i = a.size() - 1, j = b.size() - 1;
        while (i >= 0 || j >= 0 || s == 1)
        {
            // Comput sum of last digits and carry 
            s += ((i >= 0) ? a[i] - '0' : 0);
            s += ((j >= 0) ? b[j] - '0' : 0);

            // If current digit sum is 1 or 3, add 1 to result 
            result = char(s % 2 + '0') + result;

            // Compute carry 
            s /= 2;

            // Move to next digits 
            i--; j--;
        }
        return result;
    }
    bool isSubSwequence(string source, string target)
    {
        int sL = source.length() - 1;
        int tL = target.length() - 1;
        int i = 0, j = 0;
        while (i <= sL && j <= tL)
        {
            if (source[i] == target[j])
            {
                i++;
                j++;
            }

            i++;
        }
        return j == tL - 1;
    }
    int numMatchingSubseq(string S, vector<string>& words) {
        int count = 0;
        for (auto& word : words)
        {
            if (isSubSwequence(S, word))
            {
                count++;
            }
        }
        return count;
    }

   
    vector<int> dest;
    vector<vector<int>> pos;
    vector<vector<int>> vec;
   
    int minKnightMoves(int x, int y)
    {
        if (x == 0 && y == 0)
            return 0;

        queue<pair<int, int>> q;
        queue<int> level;
        set<pair<int, int>> v;
        vector<vector<int>> dir = { {1,2},{2,1},{2,-1},{1,-2},{-1,2},{-2,1},{-1,-2},{-2,-1} };
        q.push(make_pair(0, 0));
        v.insert(make_pair(0, 0));
        level.push(0);
        pair<int, int> temp;

        while (!q.empty())
        {
            int l = level.front();
            level.pop();

            pair<int, int> cur = q.front();
            q.pop();

            if (cur.first == abs(x) && cur.second == abs(y))
                return l;

            for (int i = 0; i < dir.size(); i++)
            {
                temp.first = abs(cur.first + dir[i][0]);
                temp.second = abs(cur.second + dir[i][1]);
                if (v.find(temp) == v.end())
                {
                    v.insert(temp);
                    q.push(temp);
                    level.push(l + 1);

                }

            }

        }
        return -1;
    }

    int n, m;
    vector<vector<int>>& flip(vector<vector<int>>& mat, int y, int x) {
        mat[y][x] ^= 1;
        if (y - 1 >= 0) mat[y - 1][x] ^= 1;
        if (y + 1 < n) mat[y + 1][x] ^= 1;
        if (x - 1 >= 0) mat[y][x - 1] ^= 1;
        if (x + 1 < m) mat[y][x + 1] ^= 1;
        return mat;
    }

    bool isZeroMat(vector<vector<int>>& mat) {
        for (auto i = 0; i < n; ++i)
            for (auto j = 0; j < m; ++j)
                if (mat[i][j])
                    return false;
        return true;
    }

    int FlipOrNotFlip(vector<vector<int>> mat, int y, int x) {
        if (x == m) y++, x = 0;
        if (y == n) return isZeroMat(mat) ? 0 : 10000;

        auto ret1 = FlipOrNotFlip(mat, y, x + 1);
        auto ret2 = FlipOrNotFlip(flip(mat, y, x), y, x + 1) + 1;
        return min(ret1, ret2);
    }

    int minFlips(vector<vector<int>>& mat) {
        n = mat.size(), m = mat[0].size();
        auto ret = FlipOrNotFlip(mat, 0, 0);
        return (ret >= 10000 ? -1 : ret);
    }

    bool isPalindrome(string s)
    {
        int left = 0;
        int right = s.length() - 1;
        while (left <= (right))
        {
            if (s[left] != s[right])
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    void dfs(string s, int pos, vector<string>& result)
    {
        if (pos < s.length())
        {
            string sTemp;
            for (int i = pos; i < s.length(); i++)
            {
                sTemp = sTemp + s[i];
                if (isPalindrome(sTemp))
                {
                    result.push_back(sTemp);
                }
            }
        }
    }

  
    int countSubstrings(string s)
    {

        vector<string> result;
        for (int i = 0; i < s.length(); i++)
        {
            dfs(s, i, result);
        }
        return result.size();
    }
    int DFS(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j, int row, int col)
    {
        if (dp[i][j] > 0)
        {
            return dp[i][j];
        }
        int left = 1, right = 1, up = 1, down = 1;
        if (j > 0 && matrix[i][j - 1] > matrix[i][j]) {
            left = 1 + DFS(matrix, dp, i, j - 1, row, col);
        }
        if (j < (col - 1) && matrix[i][j + 1] > matrix[i][j]) {
            right = 1 + DFS(matrix, dp, i, j + 1, row, col);
        }
        if (i > 0 && matrix[i - 1][j] > matrix[i][j]) {
            up = 1 + DFS(matrix, dp, i - 1, j, row, col);
        }
        if (i < (row - 1) && matrix[i + 1][j] > matrix[i][j]) {
            down = 1 + DFS(matrix, dp, i + 1, j, row, col);
        }
        dp[i][j] = max(max(left, right), max(up, down));
        return dp[i][j];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if (!row) return 0;
        int col = matrix[0].size();
        vector<vector<int>> dp(row, vector<int>(col, 0));
        int maxd = 0, tmp;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                tmp = DFS(matrix, dp, i, j, row, col);
                maxd = max(maxd, tmp);
            }
        }
    }
 
   
    void visit(string airport, map<string, multiset<string>>& targets, vector<string>& route ) {
        while (targets[airport].size()) {
            string next = *targets[airport].begin();
            targets[airport].erase(targets[airport].begin());
            visit(next,targets,route);
        }
        route.push_back(airport);
    }
    vector<string> findItinerary(vector<vector<string>> tickets) {
        map<string, multiset<string>> targets;
        vector<string>route;
        for (auto ticket : tickets)
            targets[ticket[0]].insert(ticket[1]);
        visit("JFK",targets,route);
        return vector<string>(route.rbegin(), route.rend());
    }
    int shortestWay(string s, string t) {
        auto i = 0, j = 0, res = 0;
        while (i < t.size() && res <= i) {
            while (t[i] != s[j] && j < s.size()) ++j;
            if (j == s.size()) j = 0, ++res;
            else ++i, ++j;
        }
        return res <= i ? res + 1 : -1;
    }

    int binarySearch(int arr[], int l, int r, int x)
    {
        while (l <= r) {
            int m = l + (r - l) / 2;

            // Check if x is present at mid 
            if (arr[m] == x)
                return m;

            // If x greater, ignore left half 
            if (arr[m] < x)
                l = m + 1;

            // If x is smaller, ignore right half 
            else
                r = m - 1;
        }

        // if we reach here, then element was 
        // not present 
        return -1;
    }

    int missingElement(vector<int>& nums, int k) {
        int l = 0, h = nums.size();
        while (l < h) {
            int m = l + (h - l) / 2;
            nums[m] - m - k >= nums[0] ? h = m : l = m + 1;
        }
        return nums[0] + l + k - 1;
    }
    string longestCommonPrefix(vector<string>& strs) {
        string lcp("");
        if (strs.size() == 0) return lcp;
        if (strs.size() == 1) return strs[0];

        for (int j = 0; j < strs[0].size(); ++j) {
            char ch = strs[0][j];
            for (int i = 1; i < strs.size(); ++i)
            {
                if (ch != strs[i][j]) return lcp;
                cout << strs[i]<<endl;
                lcp += ch;
            }
        }

        return lcp;

    }



    bool adjacentSearch(vector<vector<char>>& board, const string& word, int i, int j, int index)
    {
        if (index == word.size()) return true; // end condition
        if (i < 0 || j < 0 || i > board.size() - 1 || j > board[0].size() - 1) return false; // boundary of matrix
        if (board[i][j] != word[index]) return false; // do not match
        // match!
        board[i][j] = '*'; // change the content, to avoid duplicated search
        bool furtherSearch = adjacentSearch(board, word, i + 1, j, index + 1) || // up
            adjacentSearch(board, word, i - 1, j, index + 1) || // down
            adjacentSearch(board, word, i, j - 1, index + 1) || // left
            adjacentSearch(board, word, i, j + 1, index + 1);   // right

        board[i][j] = word[index]; // modify it back!
        return furtherSearch;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                if (adjacentSearch(board, word, i, j, 0))
                    return true;
            }
        }
        return false;

    }
    int main3()
    {
        vector<string> vc = { "flower", "flow", "flight" };
       // string r1 =  longestCommonPrefix(vc);


        vector<vector<char>> vp = { {'A', 'B', 'C', 'E'} ,
            {'S', 'F', 'C', 'S'},
            {'A', 'D', 'E', 'E'} };
        exist(vp, "ABCCED");

        //vector<int> vc = { 4,7,9,10 };
        //missingElement(vc,1);
        int arr[] = { 2, 3, 4, 10, 40 };
        int x = 10;
        int n = sizeof(arr) / sizeof(arr[0]);
       // int result = binarySearch(arr, 0, n - 1, x);
       // shortestWay("abc", "abcbc");
        //vector<vector<string>> vv3 = { { "MUC", "LHR"},{"JFK", "MUC"},{"SFO", "SJC"},{"LHR", "SFO" } };
       // findItinerary(vv3);
        //vector<int>  vv1 = { 0,1,2,4,5,7 };
        //summaryRanges(vv1);
        vector<vector<int>> vv2 = { {3,4,5}, {3,2,6}, {2,2,1} };
       // longestIncreasingPath(vv2);
        //countSubstrings("abcabac");
        vector<vector<int>> mat = { {0,0}, {0,1} };
        //minFlips(mat);
        minKnightMoves(2, 1);
        string src = "abcde";
        vector<string> vecWords = { "a","bb","acd","ace" };
       // numMatchingSubseq(src, vecWords);
       // vector<int> dups = {1,3,4,2,2};
      // int num = findDuplicate(dups);

        string a = "1101", b1 = "100";
        //cout << addBinary(a, b1) << endl;

        //vector<int> v1 = { 1,2,3,4,4,5 };
        //isPossible(v1);
        //[[1,3], [0,2], [1,3], [0,2]] [1,2,3], [0,2], [0,1,3], [0,2]
        //vector<vector<int>> v = { {1,2,3},{0,2},{0,1,3},{0,2} };
        //isBipartite(v);
        
        // vector<int> A = { 2, 1, 2, 4, 2, 2 };
        //vector<int> B = { 5, 2, 6, 2, 3, 2 };
        //int swap  = minDominoRotations(A, B);

        vector<int> A = { 1,0,2,3,0,4,5 };
        duplicateZeros(A);
        //vector<int> num1 = { 100,4,200,1,2,3 };
      // int val = longestConsecutive(num1);

        // vector<int> num = {1,2,3,1};
        // int index = findPeakElement(num);

        //  vector<int> vec1 = { 1,0,2,3,}; moveZeroes(vec1);

         //vector<int> nums = { 1,1,2 }; vector<vector<int>> vecResult = permuteUnique(nums);

        /* int n = 4;
         vector<vector<int>> paths = { {1,2},{3,4} };
         vector<int> result = gardenNoAdj(4, paths);*/

         //vector<string> vec = letterCombinations3("23");
         // vector<string> vecResult = generateParenthesis(3);
        vector<int> vect = { 1,2,3 };
        // vector<vector<int>> result =  permute(vect);

        /* vector<vector<char>> vec = {
             {'X','X','X','X'},
              {'X','O','O','X'},
             {'X','X','O','X'},
             {'X','O','X','X'},
         };
         solve(vec);*/
         //vector<string>emails = { "testemail@leetcode.com", "testemail1@leetcode.com", "testemail+david@lee.tcode.com" };
        //
         //numUniqueEmails(emails);
        vector<int> r = { 1,2,3,4,5,6,7 };
        //rotate(r, 3);

        vector<int> c = { 2,0,2,1,1,0 };
        //sortColors(c);
        vector<string> words = { "apple", "pen" };
       // bool bResult = wordBreak("applepenapple", words);
        // findStrobogrammatic(4);
        // string sAns = reorganizeString("baaba");
        // string sAns = rearrangeString("aaadbbcc",2);
         //countAndSay(4);

        string s = "catsanddog";
        vector<string> wordDict = { "cat", "cats", "and", "sand", "dog" };
        vector<string> resultString = wordBreakII(s, wordDict);
 /* s = "catsanddog"
      wordDict = ["cat", "cats", "and", "sand", "dog"]
      Output:
  [
      "cats and dog",
      "cat sand dog"
  ]*/
       // numDecodings("127");
        vector<int> b = { 6, 5, 8, 9, 7, 1, 10, 2, 3, 4 };
        //kEmptySlots(b, 1);

     //   string res = nextClosestTime("19:34");

   return 0;
}