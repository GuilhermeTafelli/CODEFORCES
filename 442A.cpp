#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<string> v;
    string s;
    v.push_back("Danil");    
    v.push_back("Olya");
    v.push_back("Slava");
    v.push_back("Ann");
    v.push_back("Nikita");
    cin >> s;
    int cont, flag = 0;
    int t = s.size();
    for(int i = 0;i<5;i++){
        cont = 0;
       
        for(int j = 0;j<t;j++){
            if(s[j] == v[i][cont]){
                cont++;
            }
            else cont = 0;
            if(cont == v[i].size()){
                flag++;
                              
                
            }
        }
    }
    if(flag == 1)cout << "YES" << endl;
    else cout << "NO" << endl;


}
