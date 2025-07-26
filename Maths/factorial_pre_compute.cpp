#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<long long>fact(n+1,1);
    fact[0] = 1;
    for(int i=1;i<=n;i++){
         fact[i] = (i*fact[i-1])%100000009;
    }

    for(int i=0;i<=n;i++) {
        cout<<fact[i]<<" ";
    }
}