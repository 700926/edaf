//
// Created by csalmeida on 15/06/2023.
//

#ifndef LISTAS_STACK_H
#define LISTAS_STACK_H

#include <vector>

template<class T, int capacity = 30>
class STACK {
public:
    STACK() { pool.reserve(capacity); }
    void clear() { pool.clear(); }
    bool isEmpty() const { return pool.empty(); }
    T& peek() { return pool.back(); }
    T pop() {
        T el = pool.back();
        pool.pop_back();
        return el;
    }
    void push(const T& el) { pool.push_back(el); }
private:
    std::vector<T> pool;
};

#endif //LISTAS_STACK_H
