
template<typename T>
class SingleTon{
public:
    static T& GetInstance(){
        std::once_t once;
        std::call_once(&once,init);
        return *_value;
    }
    static void init(){
        _value = new T();
    }
private:
    static std::once_t once;
    static T* _value;
private:
    SingleTon(const SingleTon &T) = delete;
    SingleTon& operator = (const SingleTon &T) = delete;
    SingleTon();
    ~SingleTon();
};