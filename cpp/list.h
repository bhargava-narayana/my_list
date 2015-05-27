#ifndef __LIST_H
#define __LIST_H

#include <iostream>
#include <cstdlib>
#include <cassert>
//#include <cstdbool>

template <class Type>
struct node
{
        Type info;
        struct node<Type> *next;
};

template <class Type>
class linkedList
{
        public:
                const linkedList<Type>& operator=
                        (const linkedList<Type>&); //overload assignment operator
                linkedList(); //default constructor
                linkedList(const linkedList<Type>& otherList); //copy constructor
                void initList();
                bool isEmpty();
                int length();
                void destroyList();
                Type front();
                Type back();
                bool search(const Type& searchData);
                void insertFirst(const Type& newData);
                void insertLast(const Type& newData);
                void deleteNode(const Type& data);
                void printReverse();
                void reverseList();
                Type nodeFromTail(int position);
                void remove_duplicate(); //only for sorted list
                node  remove_nth_node(int position);
                bool detect_loop();
                ~linkedList(); //destructor
        
        protected:
                int count;
                node<Type> *first;
                node<Type> *last;
        
        private:
                void copyList(const linkedList<Type>& newList); //copy linkedList

};
#endif
