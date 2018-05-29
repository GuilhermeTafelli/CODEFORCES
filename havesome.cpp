#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int > ii;
#define INF 0x3f3f3f3f

vector<vector<int> > grafo;

int dist[100010], v[100010];


int djk(int x, int y){
    priority_queue<ii, vector<ii>, greater<ii> > q;
    memset(dist, INF, sizeof dist);

    dist[x] = v[1];
    q.push(ii(v[1], 1));
    
    while(!q.empty()){
    
        ii topo = q.top();
        int vertice = topo.second;
        int distancia = topo.first;
        q.pop();
        
           
        for(int i = 0;i<grafo[vertice].size();i++){
            int w = grafo[vertice][i];
            int custo = v[w];
            if(custo+distancia < dist[w]){
                dist[w] = custo+distancia;
                q.push(ii(dist[w], w));
            }
        }    
    }
    return dist[y];
}

int djk1(int x, int y){
    priority_queue<ii> q;
    memset(dist, 0, sizeof dist);

    dist[x] = v[1];
    q.push(ii(v[1], 1));
    
    while(!q.empty()){
    
        ii topo = q.top();
        int vertice = topo.second;
        int distancia = topo.first;
        q.pop();
        
           
        for(int i = 0;i<grafo[vertice].size();i++){
            int w = grafo[vertice][i];
            int custo = v[w];
            if(custo+distancia > dist[w]){
                dist[w] = custo+distancia;
                q.push(ii(dist[w], w));
            }
        }    
    }
     return dist[y];
}




int main(){
 
    int a, b, c, x, y;
    memset(v, 0, sizeof(v));
    cin >> a >> b >> c;
    grafo.resize(a+2);
    for(int i = 0;i<b;i++){
        cin >> x;
        v[x] = 1;
    }
    for(int i = 0;i<c;i++){
        cin >> x >> y;
        grafo[x].push_back(y);    
    }
    int r1 = djk(1, a);
    cout << r1 << " ";
    int r2 = djk1(1, a);
    cout << r2 << endl;
}
    
    
