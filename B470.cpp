#include<bits/stdc++.h>
using namespace std;

vector <int> v;

int primo(int a){
    for(int i = 2;i<=sqrt(a);i++){
        if(a%i == 0)return false;
    }
    return true;

}


int main(){
    int a, m, o = 100000000;
    cin  >> a;
    for(int i = 1;i<=a;i++){
        if(primo(i))v.push_back(i);
    }
    for(int i = 0;i<v.size();i++){
        if(a%v[i] == 0)m = v[i];
    }
    //cout << m << endl;
    
    for(int i = 0;i<v.size() and v[i] < a-m;i++){
        //cout << v[i] << " " << (a-m+1)/v[i]*v[i]  << " " << v[i]-((a-m+1)%v[i]) << " "<<  ((a-m+1)%v[i]) << endl; 
        if((a-m+1)/v[i]>0){
            //cout <<"@" << endl;
            if(o > ((a-m+1)/v[i]*v[i])-v[i] and ((a-m+1)%v[i]) == 0){
                o = ((a-m+1)/v[i]*v[i])-v[i];
                o++;
            }
            
            else if(o > (a-m+1)/v[i]*v[i] and v[i]-((a-m+1)%v[i]) < a-(a-m)){
                o = (a-m+1)/v[i]*v[i];
                o++;
            }
        }
    }
    cout << o << endl;


}
