#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, r = 1;
    cin >> a >> b >> c;
    if(b*(c+1) > a)cout << -1 << endl;
    else {
        for(int i = b;i>1;i--){
            r*=i;
        }
        cout << r*(a-(b*(c+1))+1+c) << endl;
    }
}
