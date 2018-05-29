#include<bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define INF 0x3f3f3f3f
typedef pair <int , int > ii;
typedef pair<pair <int, int>, pair <int, int> > ip;

int main(){

int a, b, c, d, e;
bool flag = false;

    cin >> a >> b >> c >> d >> e;
    for(int i = a;i<=b;i++){
        if(i%e == 0 and i/e >=c and i/e <=d){
            flag =true;
        }        
    }
    if(flag)cout << "YES" << endl;
    else cout << "NO" << endl;


}
