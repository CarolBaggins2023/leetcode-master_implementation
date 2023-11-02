#include <string>
#include <vector>

class Solution {
public:
    void BackTracking(const std::string &digits, int pos, std::string &path, std::vector<std::string> &res, const std::vector<std::vector<char>> &num2word) {
        if (pos == digits.size()) {
            res.emplace_back(path);
            return;
        }

        for (const char word : num2word[digits[pos] - '0' - 2]) {
            path.push_back(word);
            BackTracking(digits, pos + 1, path, res, num2word);
            path.pop_back();
        }
    }
    
    std::vector<std::string> letterCombinations(std::string digits) {
        if (digits.empty()) {
            return std::vector<std::string> {};
        }
        
        std::vector<std::vector<char>> num2word;
        num2word.emplace_back(std::vector<char> {'a', 'b', 'c'});
        num2word.emplace_back(std::vector<char> {'d', 'e', 'f'});
        num2word.emplace_back(std::vector<char> {'g', 'h', 'i'});
        num2word.emplace_back(std::vector<char> {'j', 'k', 'l'});
        num2word.emplace_back(std::vector<char> {'m', 'n', 'o'});
        num2word.emplace_back(std::vector<char> {'p', 'q', 'r', 's'});
        num2word.emplace_back(std::vector<char> {'t', 'u', 'v'});
        num2word.emplace_back(std::vector<char> {'w', 'x', 'y', 'z'});

        std::string path;
        std::vector<std::string> res;
        BackTracking(digits, 0, path, res, num2word);

        return res;
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
