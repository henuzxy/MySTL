/*************************************************************************
	> File Name: DynamicMath.cpp
	> Author: 
	> Mail: 
	> Created Time: 四  4/ 2 14:11:53 2020
 ************************************************************************/

#include<iostream>
#include "StaticMath.h"
using namespace std;
double StaticMath::add(double a,double b){
    cout << "OK" << endl;
    return a+b;
}
double StaticMath::sub(double a,double b){
    return a-b;
}
double StaticMath::mul(double a,double b){
    return a*b;
}
double StaticMath::div(double a,double b){
    return a/b;
}
void StaticMath::print(){
    cout << "StaticMath lib" << endl;
}
