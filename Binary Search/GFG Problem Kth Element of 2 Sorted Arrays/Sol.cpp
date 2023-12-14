#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int kthElement(int nums1[], int nums2[], int n, int m, int k)
    {
        // we will calculate the contribution size of the smaller array
        if (n > m)
            return kthElement(nums2, nums1, m, n, k);

        // monotonic search space for binary search
        /*
            edge case: you can't always pick 0 elements from nums1 and m elements from nums2
            if k > m then u need to pick atleast k - m from nums1 since we need to pick k elements overall
        */
        int low = max(0, k - m), high = min(k, n);

        while (low <= high)
        {
            // contribution size in each array
            // to compute left half of the final merged array, we need k elements
            int cut1 = low + high >> 1;
            int cut2 = k - cut1;

            // 4 variables to check the validity of partition
            // max values in the left part of array
            int l1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
            int l2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];

            // min values in the right part of array
            int r1 = cut1 == n ? INT_MAX : nums1[cut1];
            int r2 = cut2 == m ? INT_MAX : nums2[cut2];

            // elements on the left part <= elements on the right part for the partition to be valid
            // l1 <= r1 is implied as the array is sorted
            if (l1 <= r2 && l2 <= r1)
            {
                return max(l1, l2);
            }
            // consider r2 before l1, dont consider l1 for now
            // decrease the contribution size of smaller array
            else if (l1 > r2)
                high = cut1 - 1;
            else
                low = cut1 + 1;
        }
        return -1;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        int *nums1 = new int[n];
        int *nums2 = new int[m];
        for (int i = 0; i < n; i++)
            cin >> nums1[i];
        for (int i = 0; i < m; i++)
            cin >> nums2[i];

        Solution ob;
        cout << ob.kthElement(nums1, nums2, n, m, k) << endl;
    }
    return 0;
}