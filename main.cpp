#include <iostream>
#include "Base/defer.h"

using namespace std;

int main(void){
    int x[2] = {1,2};
    auto [a,b] = x;
    cout << a << " " << b << endl;
    return 0;
}