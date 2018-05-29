#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, v[2000010], x, cont = 0;
    
    cin >> a;
    int v1[a+1], v2[a+1];
    memset(v, 0, sizeof v);
    for(int i = 0;i<a;i++){
        cin >> x;
        v[x] = 1;
        v1[i] = x;
    }
    for(int i = 0;i<a;i++){
        cin >> x;
        v[x] = 1;
        v2[i] = x;
    }
    for(int i = 0;i<a;i++){
        for(int j = 0;j<a;j++){
            long long int s = v1[i]^v2[j];
            if(s <=2*(1000000)){                
                if(v[v1[i]^v2[j]]== 1)cont++;
            }
        }
    }
    //cout << cont << endl;
    if(cont%2 == 0)cout << "Karen" << endl;
    else cout << "Koyomi" << endl;
}
