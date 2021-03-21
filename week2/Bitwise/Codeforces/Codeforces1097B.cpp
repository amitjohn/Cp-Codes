#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	vector<int>input(n) ;
	for(int i=0;i<n;i++) cin>>input[i];
	
	int sum;
	for(int i=0;i<(1<<n);i++){
	    sum=0;
	    for(int bit=0;bit<n;bit++){
	        if( (i & (1<<bit)) != 0 )
	            sum = sum + input[bit];
	        else
	            sum = sum - input[bit];
	    }
	    if(sum % 360 == 0 ){
	        cout<<"YES";
	        return 0;
	    }
	}
	cout<<"NO";
	return 0;
}