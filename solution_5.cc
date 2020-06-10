#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.size() <= 1)
        {
            return s;
        }
        int max = 1;
        int start = 0;
        int end = 0;
        for (int i = 1; i < s.size() - 1; i++)
        {
            int current_len = 1;
            int left = i - 1, right = i + 1;
            for (; left >= 0 && right < s.size();)
            {
                if (s.at(left) == s.at(right))
                {
                    current_len += 2;
                }
                else
                {
                    break;
                }
                left--;
                right++;
            }
            if (current_len > max)
            {
                max = current_len;
                start = left + 1;
                end = right - 1;
            }
        }
        for (int i = 0; i < s.size() - 1; i++)
        {
            int current_len = 0;
            int left = i, right = i + 1;
            for (; left >= 0 && right < s.size();)
            {
                if (s.at(left) == s.at(right))
                {
                    current_len += 2;
                }
                else
                {
                    break;
                }
                left--;
                right++;
            }
            if (current_len > max)
            {
                max = current_len;
                start = left + 1;
                end = right - 1;
            }
        }
        return s.substr(start, end - start + 1);
    }
};
int main(int argc, char **argv)
{
    Solution s;
    string str("ccc");
    auto result = s.longestPalindrome(str);
    std::cout << result << std::endl;
}