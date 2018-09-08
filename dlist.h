#ifndef DLIST_H
#define DLIST_H

#include "iterator.h"

template <typename T>
class DListIterator : public Iterator<T> {
    public:
        DListIterator() : Iterator<T>() {};
        DListIterator(Node<T> *current) : Iterator<T>(current) {
          //this->current=current;
        };
        DListIterator<T> operator++(){
          this->current=this->current->next;
          return *this;
        };
        DListIterator<T> operator--(){
          this->current=this->current->prev;
          return *this;
        };
};

template <typename Tr>
class DList {
    public:
        typedef typename Tr::T T;
        typedef DListIterator<T> iterator;

    private:
        Node<T>* head;
        Node<T>* tail;
        int nodes;
    public:
        DList() {
            head = tail = nullptr;
            nodes=0;
        };

        void push_front(T data) {
          auto* temp= new Node<T>(data);
          if (head==nullptr) {
              head=temp;
              tail=temp;
          }else{
              temp->next=head;
              head->prev=temp;
              head=temp;
          }
          nodes++;
            // TODO
        }

        void push_back(T data) {
          auto* temp= new Node<T>(data);
          if (head==nullptr) {
              head=temp;
              tail=temp;
          }else{
            tail->next=temp;
            temp->prev=tail;
            tail=temp;
          }
          nodes++;
            // TODO
        }

        void pop_front() {
          auto* temp=head;
          if(!head)
              throw "Lista vacia";
          if(nodes==1)
              head=tail=nullptr;
          else{
              head->next->prev=nullptr;
              head=temp->next;
          }
          delete temp;
          nodes--;
            // TODO
        }

        void pop_back() {
          auto* temp=head;
          if(!head)
              throw "Lista vacia";
          if(nodes==1)
              head=tail=nullptr;
          else{
              while(temp->next!=tail)
                  temp=temp->next;
              tail=temp;
              temp=temp->next;
              tail->next=nullptr;
          }
          delete temp;
          nodes--;
            // TODO
        }

        iterator begin() {
          return iterator(head);
            // TODO
        }

        iterator end() {
          return iterator(tail);
            // TODO
        }

        ~DList() {
            if (head) {
                head->killSelf();
            }
        }
};

#endif
