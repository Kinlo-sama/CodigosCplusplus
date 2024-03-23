#include <iostream>
#include <vector>
#include <utility>  //lo usar pair
using namespace std;

typedef pair<int,int> PII;
typedef vector<PII> Vp;

int main(){
    Vp coor_vecN;
    int n,k;
    int x,y;
    cin >> n >> k;
    while(n--){
        cin >> x >> y;
        coor_vecN.push_back(make_pair(x,y));
    }
    while(k--){
        cin >> x >> y;
        PII coor_bus = make_pair(x,y);
        bool encontrado = false;
        for(const auto& coord: coor_vecN){
            if( coord == coor_bus){
                encontrado = true;
                break;
            }
        }
        if(encontrado)
            cout << 0 << endl;
        else
            cout << 1 << endl;
    }
}
