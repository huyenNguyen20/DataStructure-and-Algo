#include <iostream>
#include <vector>
#include <algorithm>
long long MaxPairwiseProductFast(const std::vector<int>& numbers){
    int n = numbers.size();
    int index1 = -1;
    for (int i = 1; i < n; i++) {
        if( index1 == -1 || numbers[i] > numbers[index1]) index1 = i;
    }
    int index2 = -1;
    for (int i = 0; i < n; i++) {
       if (index1 != i &&  (index2 == -1 || numbers[i] > numbers[index2]))  index2 = i;
    }
    return ((long long) (numbers[index1])) * numbers[index2];
}
long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
                ((long long) (numbers[first])) * numbers[second]);
        }
    }

    return max_product;
}

int main() {
    while (true) {
        int n = rand() % 1000 + 2;
        std::cout << n << "\n";
        std::vector<int>A;
        for (int i = 0; i < n; i++) {
            A.push_back(rand() % 100000);
        }
        for (int i = 0; i < n; i++) {
            std::cout << A[i] << " ";
        }
        std::cout << "\n";
        long long result1 = MaxPairwiseProduct(A);
        long long result2 = MaxPairwiseProductFast(A);
        if (result1 == result2) std::cout << "OK" << "\n";
        else {
            std::cout << "Wrong as " << result1 << " is not equal to " << result2 << "\n";
            break;
        }
    }
    //int n;
    //std::cin >> n;
    //std::vector<int> numbers(n);
    //for (int i = 0; i < n; ++i) {
     //   std::cin >> numbers[i];
   // }

    //std::cout << MaxPairwiseProduct(numbers); 
    //std::cout << "\n";
    return 0;
}
