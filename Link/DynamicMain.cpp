/*************************************************************************
	> File Name: DynamicMain.cpp
	> Author: 
	> Mail: 
	> Created Time: 四  4/ 2 14:14:12 2020
 ************************************************************************/

#include<iostream>
#include "DynamicMath.h"
using namespace std;

int main(void){
    double a = 10,b = 2;
    cout << DynamicMath::add(a,b) << endl;
    DynamicMath DM;
    DM.print();

    return 0;
}
