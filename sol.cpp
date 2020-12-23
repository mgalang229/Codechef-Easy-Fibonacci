#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	//create an array for fibonacci
	int fibNum[60];
	//create an array for the 2 raise to n 
	ll pow2[60];
	//the fibonacci sequence will accommodate 60 places since it's periodic
	fibNum[0]=0;
	fibNum[1]=1;
	//store the last numbers of every fibonacci number in the array
	for(int i=2; i<60; ++i)
		fibNum[i]=(fibNum[i-1]+fibNum[i-2])%10;
	//store the 2 raise to n values in the array
	pow2[0]=1;
	for(int i=1; i<60; ++i)
		pow2[i]=pow2[i-1]*2;
	int t;
	cin >> t;
	while(t--) {
		ll n;
		cin >> n;
		int i;
		//check if the 2 raise to 'n' is less than or equal to 'n'
		//explanation: this will give the place of the target value
		for(i=59; i>=0; --i)
			if(pow2[i]<=n)
				break;
		//print the answer using the pow2[i]-1 value as an index
		//and if it's greater than 60, then the mod 60 will handle it
		cout << fibNum[(pow2[i]-1)%60] << "\n";
	}
}
