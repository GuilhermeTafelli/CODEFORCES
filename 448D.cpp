#include<bits/stdc++.h>
using namespace std;
long long int a, b, c;
long long int teste(long long int x){
    long long int r = 0;
    for(long double i = 1;i<=b;i++){
        if(x/i > a)r+=a;
        else r+=ceil((x/i))-1;
    }

    return r;
}

long long int bb(){
    long long int ini = 1, meio, fim = a*b, result;
    
    while(ini <= fim){
        meio = (ini+fim)/2;
        
        long long int k = teste(meio); 
       // cout << meio << " " << k << endl;
        if(k <= c-1){
            result = meio;
            ini = meio+1;
        }
        if(k > c-1)fim = meio-1;

    }
    return result;
}



int main(){
    cin >> a >> b >> c;
    long long int r = bb();
    cout << r << endl;
}
