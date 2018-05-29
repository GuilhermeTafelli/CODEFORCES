#include<bits/stdc++.h>
using namespace std;

typedef pair<long long int, long long int > ii;
#define INF 0x3f3f3f3f

vector<vector<ii> > grafo;

long long int dist[30010], v[30010], d;


long long int djk(long long int x, long long int y){
    priority_queue<ii, vector<ii>, greater<ii> > q;
    memset(dist, INF, sizeof dist);
    q.push(ii(0, 1));
    
    while(!q.empty()){
    
        ii topo = q.top();
        long long int vertice = topo.second;
        long long int distancia = topo.first;
        q.pop();
        
           
        for(long long int i = 0;i<grafo[vertice].size();i++){
            long long int w = grafo[vertice][i].first;
            long long int custo = grafo[vertice][i].second+(v[w]*d);
            if(custo+distancia < dist[w]){
                dist[w] = custo+distancia;
                q.push(ii(dist[w], w));
            }
        }    
    }
    return dist[y];
}
int main(){
 
    long long int a, b, c, e, x, y, z;
    memset(v, 0, sizeof(v));
    cin >> a >> b >> c >> d >> e;
    grafo.resize(a+2);
    for(long long int i = 0;i<e;i++){
        cin >> x;
        v[x] = 1;
    }
    for(long long int i = 0;i<b;i++){
        cin >> x >> y >> z;
        grafo[x].push_back(ii(y, z*60));

    }
    long long int r = djk(1, a);  
    if(r > c*60)cout << -1 << endl;
    else cout << r << endl;
}
