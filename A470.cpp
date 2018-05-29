#include<bits/stdc++.h>
using namespace std;

int a, b;
char v[510][510];
bool flag = true;

int test(int i, int j){
    if(i-1 >=0 and v[i-1][j] == 'W')return false;
    if(i+1 < a and v[i+1][j] == 'W')return false;
    if(j-1 >=0 and v[i][j-1] == 'W')return false;
    if(j+1 < b and v[i][j+1] == 'W')return false;
    
    return true;
}



int main(){

    cin >> a >> b;
    for(int i = 0;i<a;i++){
        for(int j = 0;j<b;j++){
            cin >> v[i][j];
        }
    }
    for(int i = 0;i<a;i++){
        for(int j = 0;j<b;j++){
            if(v[i][j] == 'S' and test(i, j) == false){
                flag = false;
                break;
            }
        }
        if(flag == false)break;
    }
    if(flag == false)cout << "No" << endl;
    else {
    cout << "Yes" << endl;
        for(int i = 0;i<a;i++){
            for(int j = 0;j<b;j++){
                if(v[i][j] == '.'){
                    cout << "D";                
                }
                else cout << v[i][j];
            }
            cout << endl;
            if(flag == false)break;
        }
    }

}


