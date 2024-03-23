#include <map>
#include <iostream>
using namespace std;

int main(){
    map<int,int> cor;
    int N;  cin >> N;
    while(N--){
        int x,y;
        cin >> x >> y;
        if(cor.find(x) == cor.end() || y < cor[x]){
            cor[x] = y;
           }
    }
    cout << cor.size() << endl;
    for(auto iter = cor.begin(); iter != cor.end(); ++iter)
        cout << iter->first << " " << iter->second << endl;
}
