#include <utility>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// vector<int> mergeKSortedArrays(vector<vector<int> *> kArrays)
// {
//     // Write your code here
//     vector<int> answer;

//     priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

//     // Insert the first element of k arrays into the priority queue
//     for (int i = 0; i < kArrays.size(); i++)
//     {
//         pq.push({kArrays[i]->at(0), {i, 0}});
//     }

//     // This takes O(klogk) time

//     while (!pq.empty())
//     {
//         pair<int, pair<int, int>> top = pq.top();
//         pq.pop();

//         answer.push_back(top.first);

//         int arrayIndex = top.second.first;
//         int elementIndex = top.second.second;

//         // So push the element from the same array into priority queue

//         if (elementIndex + 1 < kArrays[arrayIndex]->size())
//         {
//             pq.push({kArrays[arrayIndex]->at(elementIndex + 1), {arrayIndex, elementIndex + 1}});
//         }
//     }

//     // This takes O(nlogK) time and O(n) space

//     return answer;
// }

vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
    vector<int> answer;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    // Insert the first element of k arrays into the priority queue
    for (int i = 0; i < kArrays.size(); i++)
    {
        pq.push({kArrays[i][0], {i, 0}});
    }
    // This takes O(klogk) time

    while (!pq.empty())
    {
        pair<int, pair<int, int>> top = pq.top();
        pq.pop();

        answer.push_back(top.first);

        int arrayIndex = top.second.first;
        int elementIndex = top.second.second;

        // So push the element from the same array into priority queue
        if (elementIndex + 1 < kArrays[arrayIndex].size())
        {
            pq.push({kArrays[arrayIndex][(elementIndex + 1)], {arrayIndex, elementIndex + 1}});
        }
    }
    // This takes O(nlogK) time and O(n) space

    return answer;
}