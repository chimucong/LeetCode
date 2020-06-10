#include <vector>
#include <limits>
#include <iostream>

using namespace std;

class Solution
{
public:
    int reverse(int x1)
    {
        long x = x1;
        if (x == 0)
        {
            return 0;
        }
        bool negtive = false;
        if (x < 0)
        {
            negtive = true;
            x = -x;
        }
        vector<char> v;

        while (x)
        {
            v.push_back(x % 10);
            x /= 10;
        }
        long result = 0;
        for (auto &i : v)
        {
            result = result * 10 + i;
        }
        if (negtive)
        {
            result = -result;
            if (result < std::numeric_limits<int>::min())
            {
                return 0;
            }
        }
        else
        {
            if (result > std::numeric_limits<int>::max())
            {
                return 0;
            }
        }
        return result;
    }
};

int main(int argc, char **argv)
{
    Solution sol;
    std::cout << std::numeric_limits<int>::max() << std::endl;
    std::cout << sol.reverse(-2147483641) << std::endl;
}