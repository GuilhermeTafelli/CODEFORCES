#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int a, b, x, r;
    vector <int> v;
    cin >> a >> b;
    for(int i = 0;i<a;i++){
        cin >> x;
        v.push_back(x);   
    }
    sort(v.begin(), v.end());
    for(int i = v.size()-1;i>=0;i--){
        if(b%v[i] == 0){
            r = b/v[i];
            break;
        }
    }
    cout << r << endl;

}
