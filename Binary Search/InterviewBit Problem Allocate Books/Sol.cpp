#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int isPossible(int *A, int n, int barrier, int B)
    {
        int allocatedStu = 0;
        int pages = 0;
        for (int i = 0; i < n; i++)
        {
            if (A[i] > barrier)
                return false;

            if (pages + A[i] > barrier)
            {
                allocatedStu++;
                pages = A[i];
            }
            else
            {
                pages += A[i];
            }
        }
        if (allocatedStu < B)
            return true;
        return false;
    }
    int books(int *A, int n1, int B)
    {
        if (B > n1)
            return -1;
        int low = A[0];
        int high = 0;
        // to find minimum value and sum of all pages
        for (int i = 0; i < n1; i++)
        {
            high = high + A[i];
            low = min(low, A[i]);
        }
        // binary search
        while (low <= high)
        {
            int barrier = (low + high) >> 1;
            if (isPossible(A, n1, barrier, B))
            {
                high = barrier - 1;
            }
            else
            {
                low = barrier + 1;
            }
        }
        return low;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int *A = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.books(A, n, m) << endl;
    }
    return 0;
}