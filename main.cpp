#include <iostream>
#include <pthread.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include "SmartPointer/SmartPointer.h"
int main(void){
    SmartPointer<int> p1;
    SmartPointer<int> p2(new int(2));
    p1 = p2;

   // shared_ptr<int> ptr2 = ptr1;
 //   std::cout << ptr1.use_count() << std::endl;
    return 0;
}