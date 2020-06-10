#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> indexes(nums.size());
        std::iota(indexes.begin(), indexes.end(), 0);
        std::sort(indexes.begin(), indexes.end(),
                  [&nums](auto &lhs, auto &rhs) {
                      return nums[lhs] < nums[rhs];
                  });
        for (int i = 0, j = indexes.size() - 1; i < j;)
        {
            int idx1 = indexes[i];
            int idx2 = indexes[j];
            int sum = nums[idx1] + nums[idx2];
            if (sum == target)
            {
                return vector<int>{idx1, idx2};
            }
            else if (sum < target)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return vector<int>{};
    }
    vector<int> twoSum2(vector<int> &nums, int target)
    {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            int other = target - nums[i];
            if (m.find(other) != m.end())
            {
                return vector<int>{m[other], i};
            }
            m[nums[i]] = i;
        }
        return vector<int>{};
    }
};

int main(int argc, char **argv)
{
    vector<int> nums{2, 15, 7, 11};
    int taget = 9;
    Solution s;
    auto result = s.twoSum2(nums, taget);
    if (result.size() == 2)
    {
        std::cout << result[0] << " , " << result[1] << std::endl;
    }
    return 0;
}