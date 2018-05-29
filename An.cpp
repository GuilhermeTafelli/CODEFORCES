#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int r = 0;
    cin >> s;
    for(int i = 0;i<s.size();i++){
        if(s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u')r++;
        else if((s[i]-'0')%2 == 1 and s[i] >= '0' and s[i] <= '9')r++;
    }
    cout << r << endl;



}
