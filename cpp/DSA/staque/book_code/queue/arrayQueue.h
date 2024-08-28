#ifndef ARRAY_QUEUE
#define ARRAY_QUEUE

using namespace std;


template<typename T, int size = 100>
class arrayQueue{
    private:
        int first, last;
        T storage[size];

    public:
        arrayQueue(){
            first = last = -1;
        }

        void enqueue(T);

        T dequeue();

        bool isFull(){
            return first == 0 && last == size-1 || first == last+1;
        }

        bool isEmpty(){
            return first == -1;
        }
};

template<typename T, int size>
void arrayQueue<T, size> ::enqueue(T el){
    if(!isFull()){
        if(last == size - 1 || last == -1){
            storage[0] = el;
            last = 0;
            if(first == -1) first = 0;
        }
        else storage [++last] = el;
    }
    else cout << "Full queue." << endl;
}

template<typename T, int size>
T arrayQueue<T,size>::dequeue(){
    T tmp; tmp = storage[first];
    if(first == last)   last = first = -1;
    else if(first == size -1)   first  = 0;
    else first ++;
    return tmp;
}

#endif