#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
 
std::vector<int> removeDuplicatesKeepRightmost(const std::vector<int>& a) {
    std::unordered_set<int> seen;
    std::vector<int> result;
 
    
    for (int i = a.size() - 1; i >= 0; --i) {
        if (seen.find(a[i]) == seen.end()) {
            seen.insert(a[i]);
            result.push_back(a[i]);
        }
    }
 
  
    std::reverse(result.begin(), result.end());
    return result;
}
 
int main() {
    int n = 0;
    int num = 0;
    std::cin >> n;
    std::vector<int> a;
    for (int i = 0; i < n; i++) {
        std::cin >> num;
        a.push_back(num);
    }
 
    std::vector<int> result = removeDuplicatesKeepRightmost(a);
    std::cout << result.size() << std::endl;
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
 
    return 0;
}
