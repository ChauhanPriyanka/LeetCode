#include<vector>
#include<iostream>
using namespace std;

class Solution {

private:
    bool solved;
    int target;
    vector<int>v;
public:
    Solution(int target) {
        solved = false;
        this->target = target;
        v = vector<int>(target + 1, -1);
        v[0] = 0;
    }

    vector<int> stream(int x) {

        vector<int>ans;
        if (solved || x > target)  return ans;

        if (v[target - x] != -1) {
            solved = true;
            ans.push_back(x);

            int res = target - x;
            while (res > 0) {
                ans.push_back(v[res]);
                res -= v[res];
            }
            reverse(ans.begin(), ans.end());
            return ans;
        }

        for (int i = target; i >= x; i--)
        {
            if (v[i] == -1 && v[i - x] != -1)
            {
                v[i] = x;
            }
        }

        return ans;//empty array
    }
};

int mainSubsetGoogle(void) {

    Solution* s = new Solution(20);

    vector<int> arr = { 2, 7, 8, 1, 10 };
    for (int x : arr) {
        auto ans = s->stream(x);
        if (!ans.empty()) {
            for (auto y : ans)cout << y << ' ';
            cout << endl;
            break;
        }
    }
    return 0;
}