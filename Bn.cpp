#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;


ii m[] = {ii(1, 0), ii(-1, 0), ii(0, 1), ii(0, -1)};
ii d[4];
int a, b, r = 0, ix, iy, vis[100][100], visit[5], result = 0;
char grafo[100][100];
string s;
bool flag = false;

bool test(int i, int j){
    if(i>=0 and i<a and j >=0 and j < b and grafo[i][j] != '#')return true;
    else return false;
}

void dfs(int i, int j, int comand){
    if(grafo[i][j] == 'E'){
        flag = true;
        return;  
    }
  //  cout << i << " " << j << " " << grafo[i][j] << endl;
  //  cout << d[s[comand]-'0'].first << " " << j+d[s[comand]-'0'].second << endl;
    if(comand == s.size()-1)return;
    if(test(i+d[s[comand]-'0'].first, j+d[s[comand]-'0'].second)){
                dfs(i+d[s[comand]-'0'].first, j+d[s[comand]-'0'].second, comand+1);
    }
}

void back(int i){
    if(i == 4){
        result++;
   //     cout << "#########################" << endl << endl; 
  //      for(int i = 0;i<4;i++)cout << d[i].first << " " << d[i].second << endl;
        
        dfs(ix, iy, 0);
        if(flag == true){r++;}
        flag = false;
    }
    for(int k = 0;k<4;k++){
        //cout << i << " " << k << endl;
        if(visit[k] == 0){
        //cout << k << endl;
            d[i] = m[k];    
            visit[k] = 1;
            back(i+1);
            visit[k] = 0;
        }
    }
}

int main(){
    char x;
    cin >> a >> b;
    
    for(int i = 0;i<a;i++){
        for(int j = 0;j<b;j++){
            
            cin >> x;
           
            grafo[i][j] = x;
            if(grafo[i][j] =='S'){
                ix = i;
                iy = j;
            }
        }
    }
   
    getchar();
    getline(cin, s);
    //cout << s.size() << "!" << endl;
    //cout << "!" << endl;
    memset(visit, 0, sizeof visit);
    back(0);   
    cout << r << endl;
    //cout << result << endl;
}
