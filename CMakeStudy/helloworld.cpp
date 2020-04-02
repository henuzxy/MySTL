/*************************************************************************
	> File Name: helloworld.cpp
	> Author: 
	> Mail: 
	> Created Time: 四  4/ 2 10:21:23 2020
 ************************************************************************/

#include<iostream>
#include "HelloBase.h"
using namespace std;
int main(void){
    HelloBase HB;
    auto fun = [&HB](){
        HB.show();
    };

    fun();
    return 0;
}
