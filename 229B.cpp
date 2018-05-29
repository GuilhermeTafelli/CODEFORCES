#include<bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
typedef pair <long long int, long long int> ii;

vector <vector <long long int> > v, t;
vector <vector <ii> > grafo;

long long int dist[100010];

long long int busca(long long int a, long long int x){
    long long int ini = 0, meio, fim = v[a].size();

    if(v[a].size() == 0)return -1;

     while(fim >= ini){
        meio = (ini+fim)/2;
        if(v[a][meio] == x)return t[a][meio];
        else if (v[a][meio] < x)ini = meio+1;
        else fim = meio-1;
  
     }
     return -1;
}

long long int djk(long long int n){
    
    priority_queue<ii, vector<ii>, greater<ii> > q;
    memset(dist, INF, sizeof(dist));
    q.push(ii(0, 1));
    dist[1] = 0;
    
    while(!q.empty()){
        ii topo = q.top();
        long long int distancia = topo.first;
        long long int vertice = topo.second;
        //cout << vertice << " " << distancia << " -----" << endl;
        q.pop();
        
        if(vertice == n)return distancia; 
        
        long long int r = busca(vertice, distancia), aux = 0;
        //cout << r << endl;
        
        
        
        if(r!= -1) aux = r-distancia+1;
       // cout << r << " ** " << aux << endl;
        for(long long int i = 0;i<grafo[vertice].size();i++){
            long long int w = grafo[vertice][i].first;
            long long int custo = grafo[vertice][i].second;
        
       //     cout << w << " " << custo << endl;
            if(dist[w] > distancia+custo+aux){
                dist[w] = distancia+custo+aux;
                q.push(ii(dist[w], w));
            }
        }
    }
    return -1;


}

int main(){
    long long int a, b, x, y, z;
    
    cin >> a >> b;
    
    grafo.resize(a+1);
    v.resize(a+1);
    t.resize(a+1);
    for(long long int i = 0;i<b;i++){
        cin >> x >> y >> z;
        grafo[x].push_back(ii(y, z));
        grafo[y].push_back(ii(x, z));
    }
    for(long long int i = 1;i<=a;i++){
        cin >> x;
        for(long long int j = 0;j<x;j++){ 
            cin >> y;    
            v[i].push_back(y);
            t[i].push_back(0);
        }
    
        if(x>0){
            t[i][x-1] = v[i][x-1];
        }
        
        for(long long int j = x-2;j>=0;j--){
        
            if(v[i][j+1]-v[i][j] == 1)t[i][j] = t[i][j+1];
            else t[i][j] = v[i][j];
        }
       
    }
  
    long long int r = djk(a);
    cout << r << endl;
}
