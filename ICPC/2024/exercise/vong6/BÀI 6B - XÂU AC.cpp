#include <iostream>
using namespace std;

char findNthChar(long long N) {
    long long length = 3;  // Độ dài ban đầu của S(0)
    long long k = 0;

    // Xác định k đủ lớn để S(k) có độ dài bao phủ vị trí N
    while (length < N) {
        k++;
        length = 2 * length + (k + 3);
    }

    // Truy hồi ngược để tìm ký tự tại vị trí N
    while (k > 0) {
        long long len_k_minus_1 = (length - (k + 3)) / 2;

        if (N <= len_k_minus_1) {
            k--;
            length = len_k_minus_1;
        } else if (N > len_k_minus_1 && N <= len_k_minus_1 + (k + 3)) {
            if (N == len_k_minus_1 + 1) {
                return 'a';
            } else {
                return 'c';
            }
        } else {
            N -= (len_k_minus_1 + (k + 3));
            k--;
            length = len_k_minus_1;
        }
    }

    // Nếu đã xuống S(0)
    if (N == 1) return 'a';
    if (N == 2 || N == 3) return 'c';

    return ' '; // Trường hợp mặc định, không nên xảy ra
}

int main() {
    long long N;
    cin >> N;

    cout << findNthChar(N) << endl;

    return 0;
}
