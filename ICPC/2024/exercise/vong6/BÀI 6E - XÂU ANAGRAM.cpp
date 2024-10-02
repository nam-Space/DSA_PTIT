#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    int N;
    cin >> N;
    unordered_map<string, int> freq_map;  // Hash map để lưu số lượng xâu sau khi sắp xếp

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());  // Sắp xếp các ký tự trong xâu
        freq_map[s]++;  // Tăng số lượng của xâu này trong hash map
    }
    
    long long result = 0;
    // Tính tổng số cặp (i, j) thỏa mãn
    for (const auto& pair : freq_map) {
        int count = pair.second;
        result += 1LL * count * (count - 1) / 2;  // Số cặp có thể hình thành từ count phần tử
    }
    
    cout << result << endl;
    return 0;
}
