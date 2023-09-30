#include <map>
#include <vector>

class Solution {
public:
    bool lemonadeChange(std::vector<int>& bills) {
        std::map<int, int> changes;
        changes[5] = 0;
        changes[10] = 0;
        changes[20] = 0;
        for (const int &bill : bills) {
            int change = bill - 5;
            if (change == 5) {
                if (changes[5] == 0) {
                    return false;
                }
                --changes[5];
            } else if (change == 15) {
                if (changes[10] > 0 && changes[5] > 0) {
                    --changes[10];
                    --changes[5];
                } else if (changes[5] >= 3) {
                    changes[5] -= 3;
                } else {
                    return false;
                }
            }
            ++changes[bill];
        }
        return true;
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> bills{5,5,10,10,20};
    Solution solution;
    printf("%d", solution.lemonadeChange(bills));
    
    return 0;
}
