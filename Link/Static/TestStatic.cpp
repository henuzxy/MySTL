/*************************************************************************
	> File Name: TestStatic.cpp
	> Author:henuzxy 
	> Mail: 
	> Created Time: Thu 02 Apr 2020 03:51:11 PM CST
 ************************************************************************/

#include<iostream>
#include "StaticMath.h"
using namespace std;

int main(void){
    double a = 10,b = 2;
    cout << StaticMath::add(a,b) << endl;
    StaticMath SM;
    SM.print();
    return 0;
}
