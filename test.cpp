#include <iostream>
#include <random>
#include <ctime>
using namespace std;
int main(){
    mt19937 rng(time(nullptr));
    cout << rng();
    return 0;
}