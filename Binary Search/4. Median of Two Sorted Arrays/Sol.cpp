#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();
        // we will calculate the contribution size of the smaller vector
        if (n > m)
            return findMedianSortedArrays(nums2, nums1);

        // monotonic search space for binary search
        int low = 0, high = n;

        while (low <= high)
        {
            // contribution size in each array
            // to compute left half of the final merged array, we need (n + m + 1) / 2 elements.
            int cut1 = low + high >> 1;
            int cut2 = (n + m + 1) / 2 - cut1;

            // 4 variables to check the validity of the partition
            // max values in the left part of each vector, handle corner cases
            int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];

            // min values in the right part of each vector, handle corner cases
            int r1 = (cut1 == n) ? INT_MAX : nums1[cut1];
            int r2 = (cut2 == m) ? INT_MAX : nums2[cut2];

            // elements on left part should be <= elements on the right part, for the partition to be valid
            // l1 <= r1 is impied as the vector is sorted
            if (l1 <= r2 && l2 <= r1)
            {
                // odd number of elements
                if ((n + m) % 2 == 1)
                    return (double)max(l1, l2);
                else
                    return (double)(min(r1, r2) + max(l1, l2)) / 2;
            }
            // consider r2 first before l1, dont consider l1 for now
            // decrease the contribution size of smaller vector
            else if (l1 > r2)
                high = cut1 - 1;
            else
                low = cut1 + 1;
        }
        // if nothing gets executed return 0.0 because of double rather than just 0
        return 0.0;
    }
};