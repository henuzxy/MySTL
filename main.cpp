#include <iostream>
#include "Tree/SplayTreeSet.h"
using namespace std;
int main(void){
    SplayTreeSet<int> st;
    st.insert(2);
    st.insert(200);
    st.insert(300);
    cout << st.count(2) << endl;
    return 0;
}
