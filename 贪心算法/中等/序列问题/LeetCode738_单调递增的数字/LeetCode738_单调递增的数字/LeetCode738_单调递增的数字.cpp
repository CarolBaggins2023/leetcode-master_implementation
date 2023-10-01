#include <string>

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        std::string num = std::to_string(n);
        for (int i = num.size() - 1; i > 0; --i) {
            if (num[i - 1] > num[i]) {
                --num[i - 1];
                for (int j = i; j < num.size(); ++j) {
                    num[j] = '9';
                }
            }
        }
        return std::stoi(num);
    }
};

int main(int argc, char* argv[])
{
    int n = 100;
    Solution solution;
    printf("%d", solution.monotoneIncreasingDigits(n));
    
    return 0;
}
