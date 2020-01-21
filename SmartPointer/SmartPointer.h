#include <iostream>
#include <cstdlib>

template<typename T>
class SmartPointer{
public:
    SmartPointer(){
        this->use = new size_t(1);
        this->value = nullptr;
    }
    explicit SmartPointer(T *_value){
        this->use = new size_t(1);
        this->value = _value;
    }
    SmartPointer(const SmartPointer &_ptr){
        this->value = _ptr.value;
        this->use = _ptr.use;
        (*use) += 1;
    }
    SmartPointer& operator = (const SmartPointer &_ptr){
        if(this->value != nullptr){
            (*this->use) -= 1;
            if((*this->use) == 0){
                free();
            }
        }
        this->value = _ptr.value;
        this->use = _ptr.use;
        (*this->use) += 1;
    }
private:
    size_t *use;
    T *value;
    void free(){
        delete value;
        delete use;
        value = nullptr;
        use = nullptr;
    }
};