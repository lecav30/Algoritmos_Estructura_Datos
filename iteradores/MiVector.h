#ifndef __MIVECTOR_H__
#define __MIVECTOR_H__

template <typename T>
class MiVector {
    T* elems;
    int cap;
    int numElems;
public:

    class iterator {
        int i;
        T* elems;
    public:
        iterator(int i=0, T* elems=nullptr)
            : i(i), elems(elems) {}
        void operator ++ () {
            i++;
        }
        T operator * () {
            return elems[i];
        }
        bool operator != (iterator b) {
            return this->i != b.i;
        }
    };

    iterator begin() {
        return iterator(0, elems);
    }
    iterator end() {
        return iterator(numElems, nullptr);
    }

    MiVector(int cap=10)
        : elems(new T[cap]), cap(cap),
          numElems(cap) {}
    ~MiVector() {
        delete[] elems;
    }
    T operator[] (int i) const {
        return elems[i];
    }
    T& operator[] (int i) {
        return elems[i];
    }
};

#endif
