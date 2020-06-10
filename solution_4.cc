#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int total = nums1.size() + nums2.size();
        if (total == 0)
        {
            return 0;
        }
        int mid = (total + 1) / 2;
        int p = 0, q = 0;
        auto next = [&p, &q, &nums1, &nums2]() {
            if (p >= nums1.size())
            {
                return nums2[q++];
            }
            else if (q >= nums2.size())
            {
                return nums1[p++];
            }
            else if (nums1[p] < nums2[q])
            {
                return nums1[p++];
            }
            else
            {
                return nums2[q++];
            }
        };
        for (int i = 0; i < mid - 1; i++)
        {
            next();
        }
        if (total % 2)
        {
            return next();
        }
        else
        {
            return 1.0 * (next() + next()) / 2;
        }
    }
};

int main(int argc, char **argv)
{
    Solution sol;
    vector<int> nums1{1}, nums2{2};
    std::cout << sol.findMedianSortedArrays(nums1, nums2) << std::endl;
}