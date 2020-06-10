#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows < 2)
        {
            return s;
        }
        vector<string> v(numRows);
        int direct = 1;
        int idx = -1;
        for (auto i : s)
        {
            idx += direct;
            v[idx] += i;
            if (idx == 0)
            {
                direct = 1;
            }
            else if (idx == numRows - 1)
            {
                direct = -1;
            }
        }
        string result{};
        result.reserve(s.size());
        for (auto &i : v)
        {
            result.append(i);
        }
        return result;
    }
};

int main(int argc, char **argv)
{
    Solution sol;
    string s{"PAYPALISHIRING"};
    int numRows = 4;
    std::cout << sol.convert(s, numRows) << std::endl;
}