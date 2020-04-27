#include <mutex>
template<typename T>
class SingleTon{
public:
    static T& getinstance(){
        std::once_flag once;
        std::call_once(once,[](){
            ptr = new T();
        });
        return *ptr;
    }
    SingleTon() = default;
private:
    
    static T* ptr;
};
template<typename T>
T* SingleTon<T>::ptr = nullptr;
/*
//test
class A:public SingleTon<A>{
 public:
        friend SingleTon;
        int get(){
                return 2;
        }
private:
    A() = default;
};
int main(void){
   cout <<  A::getinstance().get() << endl;

    return 0;
}


*/