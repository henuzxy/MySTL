/*************************************************************************
	> File Name: DynamicMath.cpp
	> Author: 
	> Mail: 
	> Created Time: 四  4/ 2 14:11:53 2020
 ************************************************************************/

#include<iostream>
#include "DynamicMath.h"

using namespace std;
double DynamicMath::add(double a,double b){
    cout << "OK" << endl;
    return a+b;
}
double DynamicMath::sub(double a,double b){
    return a-b;
}
double DynamicMath::mul(double a,double b){
    return a*b;
}
double DynamicMath::div(double a,double b){
    return a/b;
}
void DynamicMath::print(){
    cout << "DynamicMath lib" << endl;
}
