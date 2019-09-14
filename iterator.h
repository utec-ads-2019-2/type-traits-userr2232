#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"
#include <iostream>

template <typename T> 
class Iterator {
    protected:
        Node<T> **&current;

    public:
        Iterator() : current(nullptr) {}
        Iterator(Node<T>**&node) : current(node) {}
        virtual Node<T>** operator*() = 0;
};

#endif