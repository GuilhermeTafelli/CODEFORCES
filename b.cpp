#include<bits/stdc++.h>
using namespace std;

int main(){
    
    long long int a, b;
    int v[] = {1, 2, 6, 4, 0};

    cin >> b >> a;
    long long int x = a-b;
    if(a == b)cout << 1 << endl;
    else if(x>4 or x<0)cout << 0 << endl;
    else cout << v[x-1] << endl;
}
