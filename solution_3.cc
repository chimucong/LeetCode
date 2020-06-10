#include <array>
#include <string>
#include <iostream>

using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.size() <= 1)
        {
            return s.size();
        }

        int start = 0;
        // int sub_start = 0;
        // int sub_end = 0;
        int current_len = 0;
        int sub_max_len = 0;
        std::array<int, 256> stat{};
        for (int i = 0; i < s.size(); i++)
        {
            if (stat[s.at(i)] == 0)
            {

                stat[s.at(i)]++;
                current_len++;
                if (current_len > sub_max_len)
                {
                    sub_max_len = current_len;
                    // sub_start = start;
                    // sub_end = i;
                }
            }
            else
            {
                while (s.at(start) != s.at(i))
                {
                    stat[s.at(start)]--;
                    current_len--;
                    start++;
                }
                start++;
            }
        }
        return sub_max_len;
    }
};

int main(int argc, char **argv)
{
    Solution s;
    string str = "bab";
    std::cout << s.lengthOfLongestSubstring(str) << std::endl;
}