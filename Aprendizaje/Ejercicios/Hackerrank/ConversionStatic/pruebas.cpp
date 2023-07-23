#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    string cad1 = "AquaVitae";
    string cad2 = "AruTaVae";
    int m = cad1.length();
    int n = cad2.length();
    //Crear una funcion para rellenar un arreglo  2D con 0´s, el arreglo puede ser de m x n
    //Para ello usaremos una funcion anonima denominada lambda
    auto inicializar_2d = [](int a,int b){
        vector<vector<int>> arr(a + 1,vector<int>(b + 1,0));
        return arr;
    };
    vector<vector<int>> dp = inicializar_2d(m,n);
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (cad1[i - 1] == cad2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        cout << dp[m][n] << endl;

}
