#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

ll f[100001];

void init(){
	f[1] = 0; f[2] = 1; f[3] = 1;
	for(int i = 4; i <= 100000; i++){
		if(i % 2 == 0){
			if(i % 3 == 0){
				f[i] = min(f[i - 1], min(f[i/2], f[i/3])) + 1;
			} else {
				f[i] = min(f[i - 1], f[i/2]) + 1;
			}
		} else if (i % 3 == 0){
			f[i] = min(f[i - 1], f[i/3]) + 1;
		} else {
			f[i] = f[i - 1] + 1;
		}
	}
}

int main(){
	init();
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<f[n]<<endl;
	}
}