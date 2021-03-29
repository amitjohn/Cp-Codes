// https://www.hackerearth.com/challenges/competitive/codemonk-checkpoint-i-1/algorithm/little-monk-and-balanced-parentheses/

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];

	stack<int>s;
	s.push(0);
	int len=0;
	for(int i=0; i<n; i++){
		if(arr[i]>0)
			s.push(i);
		if(arr[i]<0){
			if(arr[i] == -arr[s.top()]){
				s.pop();
				len = i-s.top()+1;
			}	
			else{
				s.pop();
				s.push(i);
			}
		}
	}
	cout<<len;
}