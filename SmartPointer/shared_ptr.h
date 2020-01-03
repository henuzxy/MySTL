template<typename T>
class shared_ptr{
public:
    shared_ptr(T * _value){
        if(_value != nullptr){
            value = _value;
            use = new size_t(1);
        }
    }
    ~shared_ptr(){
        *use -= 1;
        if(*use == 0){
            free();
        }
    }
    shared_ptr(const shared_ptr<T> &ptr){
        this->value = ptr->value;
        this->use = ptr->use;
        *(this->use) += 1;
    }
    shared_ptr& operator = (cosnt shared_ptr &ptr){
        this->value = ptr->value;
        this->use = ptr->use;
        *(this->use) += 1;
    }
private:
    size_t *use;
    T *value;
    void free(){
        delete use;
        delete value;
        use = nullptr;
        value = nullptr;
    }
};