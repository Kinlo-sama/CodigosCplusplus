#include<bits/stdc++.h>

using namespace std;
struct Workshop
{
    int start_time, duration, end_time;//Variable para la almacen de los tiempos
    Workshop(int start, int d) : start_time(start), duration(d)//Constuctor para inicializar el tiempo de finalizacion
    {
        end_time = start_time + duration;
    }
};

struct Available_Workshops//Digamos el arreglo de workshops
{
    int n;//Cuantos ?
    multimap<int, Workshop> workshops; //endTime - Workshop
}available_workshops;
//Hacemos hincapie en que tanto los multimap como los map se ordenan con respecto a sus claves usando arboles binarios

Available_Workshops* initialize(int start_time[], int duration[], int n)
{
    available_workshops.n = n;
    for(int i = 0; i < n; ++i)
    {
        Workshop w{start_time[i], duration[i]};
        available_workshops.workshops.insert({w.end_time, w});//Insertamos en el map y se ordenan mientras se insertan
    }
    return &available_workshops;
}

int CalculateMaxWorkshops(Available_Workshops* ptr)
{
    int max = 0;
    int time = ptr->workshops.begin()->second.start_time;
    for(auto [end_time, workshop] : ptr->workshops)
    {
        if(workshop.start_time >= time)
        {
            time = end_time;
            ++max;
        }
    }
    return max;
}
//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops

int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
