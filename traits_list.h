#ifndef TRAITS_LIST_H
#define TRAITS_LIST_H

#include "node.h"
#include "forward_iterator.h"

template <typename Tr>
class TraitsList {     
    public:
        typedef typename Tr::T T;
        typedef typename Tr::Operation Operation;
      
    private:
        Node<T>* head;
        int nodes;
        Operation cmp;

        bool find(T data, Node<T> **&pointer) {
            pointer = &this->head;
            ForwardIterator<T> it(pointer);
            while(*it  && **it && !cmp(data,(**it)->data)) ++it;
            return *it && **it && (**it)->data == data;
        }
              
    public:
        TraitsList() : head(0), nodes(0) {};

        bool insert(T data) {
            Node<T>** tmp(0);
            if(!this->find(data,tmp)) {
                Node<T>* n = new Node<T>(data);
                n->next = *tmp;
                *tmp = n;
                return this->nodes++;
            }
            return false;
        }
             
        bool remove(T data) {
            Node<T>** tmp(0);
            if(this->find(data,tmp)) {
                Node<T> *tmp2 = (*tmp)->next;
                delete *tmp;
                *tmp = tmp2;
                this->nodes--;
                return true;
            }
        }  

        bool find(T data) {
            Node<T>** tmp(0);
            return this->find(data, tmp);
        }

        T operator [] (int index) {
            if(index >= this->nodes) {
                throw runtime_error(string("Index out of bounds."));
            }
            else {
                Node<T>* current(this->head);
                for(int i = 0; i < index; ++i)
                    current = current->next;
                return current->data;
            }
        }
             
        int size() {
            return this->nodes;
        }

        void print() {
            Node<T>* current = this->head;
            while(current) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }

        ~TraitsList() {
            if(this->head) this->head->killSelf();
        }         
};

#endif