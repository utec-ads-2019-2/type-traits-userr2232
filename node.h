#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
    T data;
    int timesAccessed;
    Node<T>* next;
      
    Node(T data) : data(data), next(0), timesAccessed(0) {}
      
    void killSelf();
};

template <typename T>
void Node<T>::killSelf() {
    if (next) {
        next->killSelf();
    }
    
    delete this;
}

#endif