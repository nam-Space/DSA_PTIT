#include <bits/stdc++.h>
using namespace std;

// Hàm digitCount để đếm số lần xuất hiện của mỗi chữ số từ 0 đến 9 trong các số từ 1 đến x
vector<long long> digitCount(long long x) {
    vector<long long> count(10, 0);
    for (long long i = 1; i <= x; i *= 10) {
		// divider là biến chia để tách các chữ số
        long long divider = i * 10;
		
		// fullCycles là số chu kỳ đầy đủ của các chữ số hiện tại trong dãy số
        long long fullCycles = x / divider;
		
		// remainder là phần còn lại sau khi chia cho divider
        long long remainder = x % divider;

        for (int j = 0; j < 10; ++j) {
            count[j] += fullCycles * i;
            if (j == 0 && fullCycles > 0) count[j] -= i;
        }

        for (int j = 0; j <= remainder / i; ++j) {
            if (j == 0 && fullCycles == 0) continue;
            count[j] += i;
        }

        count[remainder / i] -= (i - 1 - remainder % i);
    }
    return count;
}

// Hàm này sử dụng digitCount để đếm số lần xuất hiện của các chữ số từ A đến B bằng cách lấy hiệu số lần xuất hiện từ 1 đến B và từ 1 đến A-1
vector<long long> countDigitsInRange(long long A, long long B) {
    vector<long long> countB = digitCount(B);
    vector<long long> countA = digitCount(A - 1);
    vector<long long> result(10, 0);

    for (int i = 0; i < 10; ++i) {
        result[i] = countB[i] - countA[i];
    }

    return result;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        long long A, B;
        cin >> A >> B;

        vector<long long> result = countDigitsInRange(A, B);
        for (int i = 0; i < 10; ++i) {
            cout << result[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
