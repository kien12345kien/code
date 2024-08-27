#ifndef LL_STACK
#define LL_STACK

#include <list>

template<class T>
class LLStack{
    private:
        list<T> lst;

    public:
        LLStack(){

        }
        void clear(){
            lst.clear();
        }

        bool isEmpty() const{
            return lst.empty();
        }

        T& top El(){
            return lst.back();
        }

        T pop(){
            Tel = lst.back();
            lst.pop_back();
            return el;
        }

        void push (const T& el){
            lst.push_back(el);
        }
};

#endif