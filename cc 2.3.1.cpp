#include <iostream>

class Solution {
public:
    int addDigits(int num) {
        if (num == 0) {
            return 0;
        }
        return 1 + (num - 1) % 9;
    }
};

int main() {
    Solution solution;

    // Test case 1: num = 38 -> 3 + 8 = 11 -> 1 + 1 = 2
    int num1 = 38;
    std::cout << "addDigits(" << num1 << ") = " << solution.addDigits(num1) << std::endl;

    // Test case 2: num = 0 -> 0
    int num2 = 0;
    std::cout << "addDigits(" << num2 << ") = " << solution.addDigits(num2) << std::endl;

    // Test case 3: num = 99 -> 9 + 9 = 18 -> 1 + 8 = 9
    int num3 = 99;
    std::cout << "addDigits(" << num3 << ") = " << solution.addDigits(num3) << std::endl;

    // Test case 4: num = 123 -> 1 + 2 + 3 = 6
    int num4 = 123;
    std::cout << "addDigits(" << num4 << ") = " << solution.addDigits(num4) << std::endl;

    return 0;
}