#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> leftMax(n), rightMin(n);
    
    leftMax[0] = arr[0];
    for(int i = 1; i < n; i++) {
        leftMax[i] = max(leftMax[i-1], arr[i]);
    }

    rightMin[n-1] = arr[n-1];
    for(int i = n-2; i >= 0; i--) {
        rightMin[i] = min(rightMin[i+1], arr[i]);
    }

    vector<int> pivots;
    for(int i = 0; i < n; i++) {
        if ((i == 0 || arr[i] >= leftMax[i-1]) && (i == n-1 || arr[i] < rightMin[i+1])) {
            pivots.push_back(arr[i]);
        }
    }

    int M = pivots.size();
    cout << M;
    for(int i = 0; i < min(M, 100); i++) {
        cout << " " << pivots[i];
    }
    cout << endl;

    return 0;
}

//Cách 2
//int main() {
//    int n;
//    cin >> n;
//    int a[n];
//    for (int &x : a) cin >> x;
//    int left[n], right[n];
//    stack<int> st1, st2;
//    for (int i = 0; i < n; i++) {
//    	while(!st1.empty() && a[i] >= a[st1.top()]) {
//    		st1.pop();
//		}
//		left[i] = st1.empty() ? a[i] : a[st1.top()];
//		st1.push(i);
//	}
//	for (int i = n - 1; i >= 0; i--) {
//		while(!st2.empty() && a[i] <= a[st2.top()]) {
//			st2.pop();
//		}
//		right[i] = st2.empty() ? a[i] : a[st2.top()];
//		st2.push(i);
//	}
//	vector<int> res;
//	for (int i = 0; i < n; i++) {
//		if ((i == 0 || left[i - 1] <= a[i]) && (i == n - 1 || a[i] < right[i + 1])) {
//			res.push_back(a[i]);
//		}
//	}
//	cout << res.size() << " ";
//	for (int x : res) cout << x << " ";
//	cout << endl;
//    return 0;
//}