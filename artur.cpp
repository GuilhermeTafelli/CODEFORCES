#include<bits/stdc++.h>
using namespace std;

int t1, t2, dp[1000][1000];
string x, y;
    
int rec(int a, int b){
    cout << x[a] << " " << y[b] << endl;
    if(b == t2-1 and x[a] == y[b])return 1;
    if(a == t1-1)return 0;
    
    int v = 0;

    for(int i = a;i<t1;i++){
        if(x[a+i] == y[b])v += rec(a+1, b+1);
         v += rec(a+i, b);
        cout << v << endl;
    }
    cout << "!!!!!!!" << endl;
    
    return v;
}

int main(){
    memset(dp, -1, sizeof dp);

    getline(cin, x);
    getline(cin, y);
   
    t1 = x.size();
    t2 = y.size();   
    int r = rec(0, 0);
    cout << r << endl;
}
