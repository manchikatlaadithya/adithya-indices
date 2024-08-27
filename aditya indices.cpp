#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

void getInput(std::vector<int>& nums, int& target) {
    int n;
    std::cout << "Enter the number of elements in the array (minimum 2, maximum 104): ";
    std::cin >> n;

    if (n < 2 || n > 104) {
        std::cerr << "The array must contain between 2 and 104 elements." << std::endl;
        exit(EXIT_FAILURE);
    }

    nums.resize(n);
    std::cout << "Enter the elements of the array (each between -10^9 and 10^9): ";
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
        if (nums[i] < -109 || nums[i] > 109) {
            std::cerr << "Each element must be between -10^9 and 10^9." << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    std::cout << "Enter the target value (between -10^9 and 10^9): ";
    std::cin >> target;

    if (target < -109 || target > 109) {
        std::cerr << "The target must be between -10^9 and 10^9." << std::endl;
        exit(EXIT_FAILURE);
    }
}

std::vector<int> twoSumBruteForce(const std::vector<int>& nums, int target) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }
    return {}; // If no solution is found
}

std::vector<int> twoSumTwoPointer(std::vector<int>& nums, int target) {
    std::vector<std::pair<int, int>> indexedNums;
    for (int i = 0; i < nums.size(); ++i) {
        indexedNums.push_back({nums[i], i});
    }

    // Sort the array based on the values
    std::sort(indexedNums.begin(), indexedNums.end());

    int left = 0, right = nums.size() - 1;

    while (left < right) {
        int sum = indexedNums[left].first + indexedNums[right].first;
        if (sum == target) {
            return {indexedNums[left].second, indexedNums[right].second};
        } else if (sum < target) {
            ++left;
        } else {
            --right;
        }
    }

    return {}; // If no solution is found
}

int main() {
    std::vector<int> nums;
    int target;

    getInput(nums, target);

    // Brute-force approach
    std::vector<int> resultBruteForce = twoSumBruteForce(nums, target);

    if (!resultBruteForce.empty()) {
        std::cout << "Brute-force result: [" << resultBruteForce[0] << ", " << resultBruteForce[1] << "]" << std::endl;
    } else {
        std::cout << "Brute-force: No solution found." << std::endl;
    }

    // Two-pointer approach after sorting
    std::vector<int> resultTwoPointer = twoSumTwoPointer(nums, target);

    if (!resultTwoPointer.empty()) {
        std::cout << "Two-pointer result: [" << resultTwoPointer[0] << ", " << resultTwoPointer[1] << "]" << std::endl;
    } else {
        std::cout << "Two-pointer: No solution found." << std::endl;
    }

    return 0;
}
