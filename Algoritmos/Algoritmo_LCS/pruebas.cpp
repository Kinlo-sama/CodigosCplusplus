#include "LCS.h"
#include <iostream>

using namespace std;

int main(){
    string cad1 = "AquaVitae";
    string cad2 = "AruTaVae";
    int tam = LCS_size(cad1,cad2);
    cout<<tam<<endl;
}
