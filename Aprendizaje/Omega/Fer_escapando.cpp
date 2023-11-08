//Ejercicio -> https://omegaup.com/course/introduccion_a_cpp/assignment/ciclos#problems/Fer-escapando
#include <iostream>
using namespace std;

int main(){
    int T,R,F;
    cin>>T>>R>>F;
    int c_i[T];

    for(int i = 0; i < T;++i)
        cin>>c_i[i];
    int V = F-R;
    bool entro = false;
    while((F-R) > 1){
        V--;
        --F;
    }
    ++V;
    ++F;
    int f_ = F,r_ = R;
    for(int i = 0; i <= T;++i){
        int aux_F = F;
        while((aux_F-R) < 1){
            ++V;
            aux_F = F;
            aux_F += V;
            entro = true;
        }
        if(entro){
            F = f_;
            R = r_;
            for(int j = 0; j < i;++j)
                R += c_i[j];
            F += V * ( i );
        }
        else if (i != T){
        R += c_i[i];
        F += V;
    }
    }
    cout<<V;
}
