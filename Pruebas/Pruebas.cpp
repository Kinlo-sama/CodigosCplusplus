#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <cmath>
#include <set>
using namespace std;
int main() {
    set<int> conjunto;
    set<int> conjunto1;
    conjunto.insert(3);
    conjunto.insert(4);
    conjunto1.insert(2);
    conjunto1.insert(5);
    conjunto1.insert(1);
    conjunto = conjunto | conjunto1;
}
