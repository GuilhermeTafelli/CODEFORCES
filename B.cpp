#include<bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define INF 0x3f3f3f3f
typedef pair <int , int > ii;
typedef pair<pair <int, int>, pair <int, int> > ip;

int main(){
    int a, b, c, x, y, z, cont = 0;;
    cin >> a >> b >> c;
    
    for(int i = 0;i<c;i++){
        cin >> x >> y >> z;
        
        double dist = hypot(x, y);
        if(dist-z >=a-b and dist+z<=a){
            cont++;
        }
    }
    cout << cont << endl;

}
