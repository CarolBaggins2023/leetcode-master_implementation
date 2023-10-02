#include <vector>

class Solution {
public:
    int candy_wrong(std::vector<int>& ratings) {
        std::vector<int> candies(ratings.size(), 0);
        candies[0] = 1;
        for (int i = 1; i < candies.size(); ++i) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
                continue;
            }

            candies[i] = 1;
            for (int j = i - 1; j >= 0; --j) {
                if (ratings[j] > ratings[j + 1] && candies[j] <= candies[j + 1]) {
                    candies[j] = candies[j + 1] + 1;
                } else {
                    break;
                }
            }
        }

        int sum = 0;
        for (int i : candies) {
            sum += i;
        }
        
        return sum; 
    }

    int candy(std::vector<int>& ratings) {
        std::vector<int> candies(ratings.size(), 1);
        for (int i = 1; i < candies.size(); ++i) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }
        for (int i = candies.size() - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = std::max(candies[i], candies[i + 1] + 1);
            }
        }

        int sum = 0;
        for (int i : candies) {
            sum += i;
        }
        
        return sum; 
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> ratings{1, 2, 2};
    Solution solution;
    printf("%d", solution.candy(ratings));
    
    return 0;
}
