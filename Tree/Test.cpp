//
// Created by ByteDance on 2020/3/10.
//

#include "Test.h"
#include <iostream>
Test::Test(int _value):value(_value){

}
void Test::show() {
    std::cout << "value:" << value << std::endl;
}