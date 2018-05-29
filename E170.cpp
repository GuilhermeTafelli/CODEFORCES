#include<bits/stdc++.h>
using namespace std;

int dp[100010][30], pai[100010], t[100010], nivel[100010], k = 0, s[100010];
vector <vector <int> > grafo, nivelt;
vector <int> v;
int dfs(int a){
    dp[a][0] = pai[a];
    
    for(int j = 1;j<25;j++){
        dp[a][j] = dp[dp[a][j-1]][j-1];
        
    }
    k++;
    t[a] = k;
    nivelt[nivel[a]].push_back(k);
    int x = 1;

    for(int i = 0;i<grafo[a].size();i++){
        int  w = grafo[a][i];
        if(pai[a] != w){
            nivel[w] = nivel[a]+1;
            pai[w] = a;
            x+=dfs(w);        
        } 
    }
    //cout << a << " " << s[a] << endl;
    return s[a] = x;
}

int lca(int a, int x){
    for(int j = 30;j>=0;j--){
        if(x >= (1 << j)){
            x-= (1 << j);
            a = dp[a][j];
        }
    }
    return a;
}


int main(){
    int a, x, y, val[100010];
    cin >> a;
    grafo.resize(a+1);
    nivelt.resize(a+1);
    
    for(int i = 1;i<=a;i++){
        cin >> x;
        if(x == 0)v.push_back(i);
        else grafo[x].push_back(i);
    }
    
    //cout << "!" << endl;
    for(int i = 0;i<v.size();i++){
            pai[v[i]] = 0;
            nivel[v[i]] = 0;
            dfs(v[i]);
    }
    
    //cout << "!" << endl;
    cin >> a;
    for(int i = 0;i<a;i++){
        cin >> x >> y;
        int r = lca(x, y);       
        int resp = lower_bound(nivelt[nivel[x]].begin(), nivelt[nivel[x]].end(), t[r])-nivelt[nivel[x]].begin();
        int ro = upper_bound(nivelt[nivel[x]].begin(), nivelt[nivel[x]].end(), (t[r]+s[r]))-nivelt[nivel[x]].begin();
        if(ro-resp-1 == -1)val[i] = 0;
        else val[i] = ro-resp-1;
    }
    for(int i = 0;i<a;i++)cout << val[i] << " ";
    cout << endl;
    
}
