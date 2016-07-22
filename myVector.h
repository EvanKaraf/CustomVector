//
// Created by Vaggelis on 21-Jul-16.
//

#ifndef UTF_S_MYVECTOR_H
#define UTF_S_MYVECTOR_H

#include <cstring>

template<class T>
class myVector {
public:
    myVector() {
        items = new T[16];
        Vsize = 0;
        Vcapacity = 16;
    }
    ~myVector(){
        delete[] items;
    }

    void push_back(T toAdd) {
        if (Vsize == Vcapacity)
            myrealloc();

        items[Vsize] = toAdd;
        Vsize++;
    }

    /*myVector Operators! */
    T &operator[](int i) const {
        if (i < 0 || i > Vsize) {
            return nullptr;
        }
        return items[i];
    }

    T &operator=(const T &other) {
        T *newVec = new T[other.Vsize];
        for (int i = 0; i < other.Vsize; i++) {
            newVec[i] = other[i];
        }
        delete[] items;
        items = newVec;
        Vsize = other.Vsize;
        return *this;
    }

    bool
    operator==(const T &other) {                      //WORKS ONLY IN STANDARD TYPES. NEEDS ADJUSTING FOR FURTHER TYPES.
        if (this->Vsize != other.Vsize)
            return false;
        else {
            for (int i = 0; i < Vsize; i++) {
                if (items[i] != other.items[i])
                    return false;
            }
        }
        return true;
    }

    int size() { return Vsize; }

    int capacity() { return Vcapacity; }

private:
    T *items;

    void myrealloc() {
        T *newVec = new T[Vcapacity << 1];
        //        for (int i=0;i<this->size();i++)
        //            newVec[i] = items[i];
        memcpy(newVec, items, Vsize * sizeof(T));
        delete[] items;
        items = newVec;
        Vcapacity <<= 1;
    }

    int Vsize;
    int Vcapacity;
};

#endif //UTF_S_MYVECTOR_H
