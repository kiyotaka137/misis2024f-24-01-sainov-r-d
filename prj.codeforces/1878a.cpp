#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
 
bool contains(const std::vector<int>& a, int element){
    return std::find(a.begin(), a.end(), element) != a.end();
}
int main() {
    int n = 0;
    int n1 = 0;
    int k = 0;
    int num = 0;
    std::vector<int> a;
    std::cin >> n;
    while (n--) {
        std::cin >> n1 >> k;
        a.clear();
        for (int i = 0; i < n1; i++) {
            std::cin >> num;
            a.push_back(num);
        }
        if (contains(a,k)) {
            std::cout << "YES" << std::endl;
        }
        else {
            std::cout << "NO" << std::endl;
        }
    }
 
    return 0;
}
