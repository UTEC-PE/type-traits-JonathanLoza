#ifndef SLIST_H
#define SLIST_H
#include <iostream>
#include "iterator.h"
using namespace std;
template <class T>
class SListIterator : public Iterator<T> {
    public:
        SListIterator() : Iterator<T>() {};
        SListIterator(Node<T> *current) : Iterator<T>(current) {};
        SListIterator<T> operator++(){
          this->current=this->current->next;
          return *this;
        };
};

template <typename Tr>
class SList {
    public:
        typedef typename Tr::T T;
        typedef typename Tr::Operation Operation;
        typedef SListIterator<T> iterator;

    private:
        Node<T>* head;
        Operation cmp;

    public:
        SList() {
            head = nullptr;
        };

        bool find(T search, Node<T> **&pointer) {
          pointer=&head;
          while(*pointer){
            if(cmp(search,(*pointer)->data)){
              break;
            }
            pointer=&((*pointer)->next);
          }
          if(!(*pointer)){
            return false;
          }
          else if ((*pointer)->data==search) {
            return true;
          }
          else{
            return false;
          }

            // TODO
        }

        bool insert(T data) {
          Node<T> **pointer;
          bool x=find(data,pointer);
          if(x){
            return false;
          }else{
            auto* nodo= new Node<T>(data);
            if (!*pointer) {
              *pointer=nodo;
              nodo->next=nullptr;
              return true;
            }
            else{
              auto* temp=*pointer;
              *pointer=nodo;
              nodo->next=temp;
              return true;
            }
          }
            // TODO
        }

        bool remove(T item) {
          Node<T> **pointer;
          bool x=find(item,pointer);
          if(!x){
            return false;
          }else{
            auto* temp=(*pointer)->next;
            if(!temp){
              temp=*pointer;
              *pointer=nullptr;
              delete temp;
              return true;
            }
            else{
              auto* temp2=*pointer;
              *pointer=temp;
              delete temp2;
              return true;
            }
          }
            // TODO
        }

        iterator begin() {
          return iterator(head);
            // TODO
        }

        iterator end() {
          auto* temp=head;
          while(temp)
            temp=temp->next;
          return iterator(temp);
            // TODO
        }

        ~SList() {
            if (head) {
                head->killSelf();
            }
        }
      void print(){
        auto* temp=head;
        while(temp){
          cout<<temp->data<<" ";
          temp=temp->next;
        }
        cout<<" "<<endl;
      }
};

#endif
