#ifndef STACK
#define STACK

#include <vector>

using namespace std;

template<typename T, int capacity = 30>

class Stack{
    private:
        vector<T>pool;

    public:
        Stack(){
            pool.reverse(capacity);
        }

        void clear(){
            pool.clear();
        }

        bool isEmpty() const{
            return pool.empty();
        }

        T& topEl(){
            return pool.back();
        }

        T pop(){
            T el = pool.back();
            pool.pop_back();
            return el;
        }

        void push(const T& el){
            pool.push_back(el);
        }
};

#endif