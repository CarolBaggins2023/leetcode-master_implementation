#include <vector>

class Solution {
public:
    int FindFib(std::vector<int> &fibs, int n) {
        if (n == 0 || n == 1 || (n != 0 && n != 1 && fibs[n] != 0)) {
            return fibs[n];
        }

        fibs[n] = FindFib(fibs, n - 1) + FindFib(fibs, n - 2);
        return fibs[n];
    }
    
    int fib(int n) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        
        std::vector<int> fibs(n + 1, 0);
        fibs[1] = 1;
        return FindFib(fibs, n);
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
