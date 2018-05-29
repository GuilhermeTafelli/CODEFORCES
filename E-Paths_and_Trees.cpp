#include<bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
typedef pair <long long int, long long int> ii;

vector <vector <pair <long long int, ii> > > grafo;
long long int dist[3000010], s = 0;
int v[3000010], c[3000010], m;

void djk(int a){
    priority_queue <ii, vector<ii>, greater<ii> > q;
    dist[a] = 0;
    q.push(ii(0, a));
    while(!q.empty()){
        ii topo = q.top();
        
        long long int distancia = topo.first;
        long long int vertice = topo.second;
        
        //cout << vertice << " " << distancia << "----" << endl;
        q.pop();
        for(int i = 0;i<grafo[vertice].size();i++){
            int long long  w = grafo[vertice][i].first;
            long long int custo = grafo[vertice][i].second.first;
            
            //cout << w << " " << custo << endl;
            if(dist[w] > custo+distancia){
                dist[w] = custo+distancia;
                v[w] = grafo[vertice][i].second.second;
                c[w] = custo;
                q.push(ii(dist[w], w));
            }
            if(dist[w] == custo+distancia){
                if(c[w] > custo){
                    c[w] = custo;
                    v[w] = grafo[vertice][i].second.second;
                    q.push(ii(dist[w], w));
                }
            }
        }
    }
}

int main(){
    long long int m, b, x, y, z;
    cin >> m >> b;
    
    memset(dist, INF, sizeof dist);
    memset(v, -1, sizeof v);
    memset(c, 0, sizeof c);
    
    grafo.resize(m+1);
    for(int i = 0;i<b;i++){
        cin >> x >> y >> z;
        grafo[y].push_back(make_pair(x, ii(z, i+1)));
        grafo[x].push_back(make_pair(y, ii(z, i+1)));
    }
    cin >> x;
    djk(x);
    for(int i = 0;i<=m;i++){
       s+=c[i];
    }
    cout << s << endl;
    for(int i = 1;i<=m;i++){
        if(v[i] != -1 and x!=i)cout << v[i] << " ";
    }
}

//E-Paths_and_Trees.cpp
