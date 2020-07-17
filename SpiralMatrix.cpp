
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
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = m ? matrix[0].size() : 0, u = 0, d = m - 1, l = 0, r = n - 1, p = 0;
    vector<int> order(m * n);
    while (u <= d && l <= r) {
        for (int col = l; col <= r; col++) {
            order[p++] = matrix[u][col];
        }
        if (++u > d) {
            break;
        }
        for (int row = u; row <= d; row++) {
            order[p++] = matrix[row][r];
        }
        if (--r < l) {
            break;
        }
        for (int col = r; col >= l; col--) {
            order[p++] = matrix[d][col];
        }
        if (--d < u) {
            break;
        }
        for (int row = d; row >= u; row--) {
            order[p++] = matrix[row][l];
        }
        if (l++ > r) {
            break;
        }
    }
    return order;
}

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n, 0));

    int u = 0, l = 0;
    int d = n-1, r = n-1;

    int count = 1;
    while (u <= d && l <= r) {
        for (int col = l; col <= r; col++) {
            matrix[u][col] = count++;
        }
        if (++u > d) {
            break;
        }
        for (int row = u; row <= d; row++) {
            matrix[row][r] = count++;
        }
        if (--r < l) {
            break;
        }
        for (int col = r; col >= l; col--) {
           matrix[d][col] = count++;
        }
        if (--d < u) {
            break;
        }
        for (int row = d; row >= u; row--) {
            matrix[row][l] = count++;
        }
        if (l++ > r) {
            break;
        }
    }
    return matrix;
}
int main345()
{

    vector<vector<int>> vec = { { 1, 2, 3 }, {4, 5, 6}, {7, 8, 9} };
    //vector<int> r = spiralOrder(vec);
    vector<vector<int>> vec1 = generateMatrix(3);
    return 0;
}