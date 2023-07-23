#include<vector>
#include<string>
//return -> size de la subsecuencia mas larga de cad1 apartir de cad2
int LCS_size(std::string cad1,std::string cad2){
    int m = cad1.length();
    int n = cad2.length();

    auto inicializar_2d = [](int a,int b){
        std::vector<std::vector<int>> arr(a + 1,std::vector<int>(b + 1,0));
        return arr;
    };

    std::vector<std::vector<int>> almacen = inicializar_2d(m,n);

    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            if(cad1[i - 1] == cad2[j - 1])
                almacen[i][j] = almacen[i - 1][j - 1] + 1;
            else
                almacen[i][j] = std::max(almacen[ i - 1][j],almacen[i][j - 1]);
        }
    }
    return almacen[m][n];
}
