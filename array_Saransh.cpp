#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;  
    if (n % 2 == 0) return false;
    for (int i = 3; i <= std::sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}
std::vector<int> rearrangeArray(const std::vector<int>& arr) {
    std::vector<int> primes;
    std::vector<int> nonPrimes;
    for (int num : arr) {
        if (isPrime(num)) {
            primes.push_back(num);
        } else {
            nonPrimes.push_back(num);
        }
    }
    std::sort(primes.begin(), primes.end(), std::greater<int>());
    std::sort(nonPrimes.begin(), nonPrimes.end(), std::greater<int>());
    std::vector<int> result;
    if (!primes.empty()) {
        result.push_back(primes[0]);
        primes.erase(primes.begin());
    }
    result.insert(result.end(), nonPrimes.begin(), nonPrimes.end());
    if (!primes.empty()) {
        result.push_back(primes.back());
    }

    return result;
}

int main() {
    std::vector<int> arr = {1, 6, 4, 13, 9, 3};
    std::vector<int> result = rearrangeArray(arr);
    for (int num : result) {
        std::cout << num << " ";
    }

    return 0;
}
