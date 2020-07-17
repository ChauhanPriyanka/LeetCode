 #include<string>
#include <set>
#include<vector>
#include<iostream>
#include<map>
#include<stack>
#include<unordered_map>
#include<queue>
using namespace std;

class TreeNode {
 public:
  TreeNode *left_;
  TreeNode *right_;
  int val_;
  int num_smaller_; // Num of smaller values
  int num_; // Num of this value
  TreeNode(int val) : val_(val) 
  {
	  left_ = nullptr;
	  right_ = nullptr;
	   num_smaller_ = 0;
	   num_ =1;
  }
};


void insert(TreeNode *root, int val, int &num_smaller) {
    while (true) {
      if (val > root->val_) {
        num_smaller += root->num_ + root->num_smaller_;
        if (root->right_ == nullptr) {
          root->right_ = new TreeNode(val);
          break;
        }
        root = root->right_;
      } else if (val < root->val_) {
        root->num_smaller_++;
        if (root->left_ == nullptr) {
          root->left_ = new TreeNode(val);
          break;
        }
        root = root->left_;
      } else {
        root->num_++;
        num_smaller += root->num_smaller_;
        break;
      }
    }
  }

  vector<int> countSmaller1(vector<int> &nums) {
    if (nums.empty()) return vector<int>();
    TreeNode *root = new TreeNode(nums.back());
    vector<int> res(nums.size());
    res.back() = 0;
    int i = nums.size() - 1;
    for (auto ri = nums.rbegin() + 1; ri != nums.rend(); ri++) {
      int num_smaller = 0;
      insert(root, *ri, num_smaller);
      res[--i] = num_smaller;
    }
    return res;
  }

   vector<int> ans;
    void merge_s(vector<pair<int, int> > &v, int left, int right) {
        if (left + 1 >= right)
            return;
        vector<pair<int, int> > tmp;
        int mid = (left + right) / 2;
        merge_s(v, left, mid);
        merge_s(v, mid, right);
        int li = left, ri = mid;
        while (li < mid || ri < right) {

            while (ri < right && (li >= mid || (v[ri].first < v[li].first))) {
                tmp.push_back(v[ri++]);
            }

            while (li < mid && (ri >= right || (v[li].first <= v[ri].first))) {
                tmp.push_back(v[li]);
                ans[v[li].second] += ri - mid;
                li++;
            }

        }
        for (int i = left;i < right;i++)
            v[i] = tmp[i - left];
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int, int> > v;
        ans.resize(nums.size(), 0);
        for (int i = 0;i < nums.size();i++)
         //   v.emplace_back(nums[i], i);
        merge_s(v, 0, nums.size());
        return ans;
    }

	int oddEvenJumps1(vector<int>& A) {
    int N = A.size();
    vector<bool> even(N, false);
    vector<bool> odd(N, false);
    even[N-1] = true;
    odd[N-1] = true;
    int cnt = 1;
    map<int, int> m;
    m[A[N-1]] = N-1;
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
  
 

    int findCheapestPrice2(int cities, vector<vector<int>>& flights, int src, int dst, int stops)
   {
       unordered_map<int, vector<pair<int, int>>> adjList;
       for (auto flight : flights)
       {
           adjList[flight[0]].push_back({ flight[1], flight[2] });
       }

       queue< pair<int, int> > q; // < city, distancefromsource > pair
       q.push({ src, 0 });
       int srcDist = INT_MAX; // result

       while (!q.empty() && stops-- >= 0)
       {
           int qSize = q.size();
           for (int i = 0; i < qSize; i++)
           {
               pair<int, int> curr = q.front();
               q.pop();
               for (auto next : adjList[curr.first])
               {
                   if (srcDist < curr.second + next.second)
                       continue;
                
                   q.push({ next.first, curr.second + next.second });

                   if (dst == next.first)
                   {
                       srcDist = min(srcDist, curr.second + next.second);
                   }
               }
           }
       }
       return srcDist == INT_MAX ? -1 : srcDist;
   }


    int mainBFS()
  {
	 /* vector <int> vec;
	  vec.push_back(5);
	  vec.push_back(6);
	  vec.push_back(2);
	  vec.push_back(1);
	  //countSmaller(vec);*/

	  //int hrs = 200;
	  //string newTime = string(1, '0' + hrs / 10) ;
	  //vector <int> vec;
	  //vec.push_back(2);
	  //vec.push_back(3);
	  //vec.push_back(1);
	  //vec.push_back(1);
	  //vec.push_back(4);
	  ////countSmaller(vec);
	  //oddEvenJumps1(vec);

   
       //input flight : {Source, Destination, Cost}
        vector<vector<int>> flights = { {4,1,1 }, { 1, 2, 3 }, { 0, 3, 2 }, { 0, 4, 10 }, { 3, 1, 1 }, { 1, 4, 3 } };

        //vec, n, stops, src , dst
        int stops = 2;
        int totalCities = 5;
        int sourceCity = 0;
        int destCity = 4;
        long ans = findCheapestPrice2(totalCities, flights, sourceCity, destCity, stops);
        return 0;
    }