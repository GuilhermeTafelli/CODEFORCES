#include<bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

int v[4], dp[4001], a;

int rec(int s){
    if(s == 0)return 0;
    if(s < 0)return -INF;
    if(dp[s] != -1)return dp[s];
 
    return dp[s] = max(rec(s-v[0])+1, max(rec(s-v[1])+1, rec(s-v[2])+1)); 
}


int main(){
    
    memset(dp, -1, sizeof dp);
    cin >> a >> v[0] >> v[1] >> v[2];
    cout << rec(a) << endl;
}
