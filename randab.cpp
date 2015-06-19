#include <iostream>
using namespace std;

int Rand5(){
    int x = INT_MAX; 
    while(x > 5)
        x = Rand7();
    return x;
}

int Rand7(){
    int x = INT_MAX;
    while(x > 21)
        x = 5*Rand5()+Rand5();
    return x%7;
}



int main(){
    return 0;
}
