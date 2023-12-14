#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
// Brute force
// max heap.
// Time Complexity: O(N^2)
// Auxiliary Space : O(N^2)
/*vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C)
{
    int n = A.size();
    vector<int> ans;
    priority_queue<int> pq;

    // insert all the possible combinations
    // in max heap.

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            pq.push(A[i] + B[j]);

    // pop first N elements from max heap
    // and display them.
    int count = 0;
    while (count < C)
    {
        ans.push_back(pq.top());
        pq.pop();
        count++;
    }
    return ans;
}*/

// Time complexity : O(nlogn)
vector<int> solve(vector<int> &A, vector<int> &B, int C)
{

    int n = A.size();
    vector<int> ans;
    // sort both arrays
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // Store sum -> (i,j)
    priority_queue<pair<int, pair<int, int>>> pq; // (sum, (i,j))
    set<pair<int, int>> st;
    pq.push({A[n - 1] + B[n - 1], {n - 1, n - 1}});
    st.insert({n - 1, n - 1}); // which pair of indices we have used already, to keep a track of them

    while (C--)
    {
        auto p = pq.top();
        pq.pop();

        int sum = p.first;
        int i = p.second.first;
        int j = p.second.second;
        // max sum -> answer
        ans.push_back(sum);

        // Next two sum combinations (i-1,j), (i,j-1)
        sum = A[i - 1] + B[j];
        if (st.find({i - 1, j}) == st.end())
        {
            pq.push({sum, {i - 1, j}});
            st.insert({i - 1, j});
        }

        sum = A[i] + B[j - 1];
        if (st.find({i, j - 1}) == st.end())
        {
            pq.push({sum, {i, j - 1}});
            st.insert({i, j - 1});
        }
    }

    return ans;
}