#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Spell {
    private:
        string scrollName;
    public:
        Spell(): scrollName("") { }
        Spell(string name): scrollName(name) { }
        virtual ~Spell() { }
        string revealScrollName() {
            return scrollName;
        }
};

class Fireball : public Spell {
    private: int power;
    public:
        Fireball(int power): power(power) { }
        void revealFirepower(){
            cout << "Fireball: " << power << endl;
        }
};

class Frostbite : public Spell {
    private: int power;
    public:
        Frostbite(int power): power(power) { }
        void revealFrostpower(){
            cout << "Frostbite: " << power << endl;
        }
};

class Thunderstorm : public Spell {
    private: int power;
    public:
        Thunderstorm(int power): power(power) { }
        void revealThunderpower(){
            cout << "Thunderstorm: " << power << endl;
        }
};

class Waterbolt : public Spell {
    private: int power;
    public:
        Waterbolt(int power): power(power) { }
        void revealWaterpower(){
            cout << "Waterbolt: " << power << endl;
        }
};

class SpellJournal {
    public:
        static string journal;
        static string read() {
            return journal;
        }
};
string SpellJournal::journal = "";

void counterspell(Spell *spell) {

    if(Fireball *poder = dynamic_cast<Fireball*>(spell);poder != nullptr)
        poder->revealFirepower();
    else if(Frostbite *poder = dynamic_cast<Frostbite*>(spell);poder != nullptr)
        poder->revealFrostpower();
    else if(Waterbolt *poder = dynamic_cast<Waterbolt*>(spell); poder != nullptr)
        poder->revealWaterpower();
    else if(Thunderstorm * poder = dynamic_cast<Thunderstorm*>(spell); poder != nullptr)
        poder->revealThunderpower();
    else{
        string hechizo = spell->revealScrollName();
        string auxHechizo = SpellJournal::journal;
        //Para encontrar la subsecuencia mas larga se utiliza el algoritmo de Longest Common Subsequence(LCS)
        //Como primer paso encontremos las longitud de ambas cadenas
        //La longitud de la cadena de donde obtendremos la subsecuencia sera igual a la cantidad de filas +1 de nuestro arreglo a usar
        //Lo longitud de la cadnea donde se encuentran los caracteres para generar la secuencia sera igual al a la cantidad de col + 1 del arreglo
        int m = hechizo.length();
        int n = auxHechizo.length();
        //Crearemos una funcion anonima para rellenar un arreglo de m + 1 filas por n + 1 columnas
        auto inicializar_2d = [](int a,int b){
            vector<vector<int>> arr(a + 1,vector<int>(b + 1,0));
            return arr;
        };
        vector<vector<int>> arr = inicializar_2d(m,n);//inicializamos el arreglo con los tamaños dados de las cadenas
        //El algoritmo de LCS usa programacion dinamica por ende arr es importante aqui para que funcione
        for(int i = 1; i <= m;++i){//Iteramos por todos los caracteres de la cadena1
            for(int j = 1;j <= n;++j)//Iteramos por todos los caracteres de la cadena2
                if(hechizo[i - 1] == auxHechizo[ j - 1])//Si encontramos un caracter igual                                              * +
                    arr[i][j] = arr[i - 1][j - 1] + 1;//¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨Agregamos una unidad al elemento en el lugar i - 1, j - 1    + i
                else //                                                                                                                      *
                    arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);//En caso de no ser caracteres igual se comparan  de la siguiente manera   * i
        }
        cout<<arr[m][n];//El tamaño de la subsecuencia mas larga se guarda en la esquina derecha inferior del arreglo
    }


  /* Enter your code here */

}

class Wizard {
    public:
        Spell *cast() {
            Spell *spell;
            string s; cin >> s;
            int power; cin >> power;
            if(s == "fire") {
                spell = new Fireball(power);
            }
            else if(s == "frost") {
                spell = new Frostbite(power);
            }
            else if(s == "water") {
                spell = new Waterbolt(power);
            }
            else if(s == "thunder") {
                spell = new Thunderstorm(power);
            }
            else {
                spell = new Spell(s);
                cin >> SpellJournal::journal;
            }
            return spell;
        }
};

int main() {
    int T;
    cin >> T;
    Wizard Arawn;
    while(T--) {
        Spell *spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}
