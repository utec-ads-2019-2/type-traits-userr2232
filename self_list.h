#ifndef SELF_LIST_H
#define SELF_LIST_H

#include "node.h"
#include <stdexcept>
#include <algorithm>

template <typename T>
class SelfList {
    public: 
        enum Method {
            Move, Count, Transpose
        };

    protected:
        Node<T>* head;
        Method method;

    public:
        SelfList(Method method) : head(nullptr), method(method) {};

        void insert(T data) {
            Node<T>* n = new Node<T>(data);
            n->next = this->head;
            this->head = n;
        }
             
        bool remove(T data) {
            Node<T>* current = current->data;
            Node<T>* previous(0);
            while(current && current->data != data) {
                previous = current;
                current = current->next;
            }
            if(current) {
                if(previous)
                    previous->next = current->next;
                else
                    this->head = current->next;
                delete current;
                this->nodes--;
            }
        }  

        bool find(T data) {
            Node<T>* current(this->head), previous(0);
            while(current && current->data != data) {
                previous = current;
                current = current->next;
            }
            if(current) {
                switch(this->method) {
                    case Move:
                        moveToFront(previous, current);
                        break;
                    case Count:
                        current->timesAccessed++;
                        count(previous, current);
                        break;
                    case Transpose:
                        transpose(previous, current);
                        break;
                }
                return data;
                return true;
            }
            return false;
        }

        T operator [] (int index) {
            if(index >= this->nodes) {
                throw runtime_error(string("Index out of bounds"));
            } else {
                Node<T>* current(this->head), previous(0);
                for(int i = 0; i < index; ++i) {
                    previous = current;
                    current = current->next;
                }
                T data = current->data;
                switch(this->method) {
                    case Move:
                        moveToFront(previous, current);
                        break;
                    case Count:
                        current->timesAccessed++;
                        count(previous, current);
                        break;
                    case Transpose:
                        transpose(previous, current);
                        break;
                }
                return data;
            }
        }

        void moveToFront(Node<T>*&previous, Node<T>*& current) {
            if(current == this->head) return;
            if(previous)
                previous->next = current->next;
            current->next = this->head;
            this->head = current;
        }

        void count(Node<T>*&previous, Node<T>*&current) {
            Node<T>* _previous(0), _next(this->head);
            while(_next && _next->timesAccessed > current->timesAccessed) {
                _previous = _next;
                _next = _next->next;
            }
            if(previous)
                previous->next = current->next;
            current->next = _next;
            if(_previous)
                _previous->next = current;
            else
                this->head = current;
        }

        void transpose(Node<T>*&previous, Node<T>*&current) {
            if(previous)
                swap(previous,current);
        }
             
        int size() {
            return this->nodes;
        }

        void print() {
            Node<T>* current(this->head);
            while(current) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }

        ~SelfList() {
            if(this->head)
                this->head->killSelf();
        }  
};

#endif