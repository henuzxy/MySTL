#pragma once
template<typename F>
class Deferbase{
public:
    Deferbase(const F &_f):f(_f){
    }
    ~Deferbase(){
        f();
    }
private:
    F f;
};

template<typename F>
Deferbase<F> defer_func(const F &_f){
    return Deferbase<F>(_f);
}

#define concat_content(x,y) x##y
#define defer(code) auto concat_content(_defer_,__COUNTER__) = defer_func([&](){code;})
