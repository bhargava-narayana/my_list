#include "list.h"


//overload assignment operator
template <class Type>
const linkedList<Type>::linkedList<Type>& operator=
        (const linkedList<Type>&)
{

}

//overload stream insertion operator
template <class Type>
ostream& operator<<(ostream osObj, 
                const linkedList<Type>* list)
{
        node<Type> *current;
        
        current = list.first;

        while(current != NULL)
        {
                osObj<<current->info<<" ";
                current = current->next;
        }

        return osObj;
}

//default constructor
template <class Type>
linkedList<Type>::linkedList()
{
        first = NULL;
        last = NULL;
        count = 0;
}

//copy constructor
template <class Type>
linkedList<Type>::linkedList(const linkedList<Type>& otherList)
{
}

template <class Type>
void linkedList<Type>::initList()
{
        //init the list by deleting all nodes
        destroyList();
}

template <class Type>
bool linkedList<Type>::isEmpty()
{
        return (first == NULL);
}

template <class Type>
int linkedList<Type>::length()
{
        return count;
}

template <class Type>
void linkedList<Type>::destroyList()
{
        node<Type> *temp;

        while(first != NULL)
        {
                temp = first;
                first = first->next;
                delete temp;
        }
        
        last = NULL;
        count = 0;
}

template <class Type>
Type linkedList<Type>::front()
{
        assert(last != NULL);

        return (first->info);
}

template <class Type>
Type linkedList<Type>::back()
{
        assert(last != NULL);

        return (last->info);

}

template <class Type>
bool linkedList<Type>::search(const Type& searchData)
{
        node<Type> *current;
        bool found;

        current = first;
        
        found = false;

        while((current != NULL) && !found)
        {
                if(current->info == searchData)
                        found = true;
                else
                        current = current->next;
        }

        return found;
}

template <class Type>
void linkedList<Type>::insertFirst(const Type& newData)
{
        /* 1. create a node
         * 2. if unable to create, terminate 
         * 3. store newData in new_node
         * 4. insert node before first
         * 5. increment count
         * 6. if list was empty; last = new_node
         */ 
        
        node<Type> *new_node;

        assert((new_node = new node<Type>) != NULL);

        new_node->info = newData;

        new_node->next = first;
        first = new_node;

        count++;

        if(last = NULL)
        {
                last = new_node;
        }

}

template <class Type>
void linkedList<Type>::insertLast(const Type& newData)
{
        /*
         * 1. create a node
         * 2. if unable to create, terminate
         * 3. store newData in new_node, new_node->next = NULL
         * 4. if list is empty, first = new_node
         * 5. else insert after last
         * 6. increment count 
         */

        node<Type> *new_node;

        assert((new_node = new node<Type>) != NULL);

        new_node->info = newData;
        new_node->next = NULL;

        if(first == NULL)
        {
                first = new_node;
                last = new_node;
        }
        else
        {
                last->next = new_node;
                last = new_node;
        }

        count++;
}

template <class Type>
void linkedList<Type>::deleteNode(const Type& data)
{
        /*
         * case 1: list is empty
         * case 2: fist node
         * case 3: middle
         * case 4: not found
         *
         * if list is empty
         *      nothing to delete
         * else
         * {
         * if first node
         *      adjust first, last and decrement count 
         * else
         *      {
         *              search list
         *              if found
         *              {
         *                delete it and adjust values of 
         *                last(if necessary) and
         *                decrement count
         *              }
         *      }
         * }
         */ 

        node<Type> *current;
        node<Type> *previous;
        bool found;

        //case 1
        if(first == NULL)
        {
                cerr<<"empty list. nothing to delete\n";
        }
        else
        {
                //case 2
                if(first->info == data)
                {
                        current = first;
                        first = first->next;
                        count--;
                        if(first == NULL)
                                last = NULL;
                        delete current;
                }
                else  //search
                {
                        found = false;
                        while((current != NULL) && !found)
                        {
                                if(current->info == data)
                                        found = true;
                                else
                                {
                                        previous = current;
                                        current = current->next;
                                }
                        } //end while

                        //case 3
                        if(found) 
                        {
                                previous->next = current->next;
                                count--;

                                //node to be deleted is last node
                                //update last
                                if(current == last)
                                        last = previous;

                                delete current;
                                }
                                else //case 4
                                {
                                        cout<<data<<" could not be found in the list\n"; 
                                } // end else
                } //ende else
        } //end else
} //end deleteNode

//print in reverse
//Algorithm:
//      1. call printReverse for head->next
//      2. print head data
template <class Type>
void linkedList<Type>::printReverse()
{
        //base case
        if(first == NULL)
        {
                return;
        }

        //print the list after head
        printReverse(first->next);

        //after everything is printed; print the head
        cout<<first->info<<"->";
}

//reverse list
template<class Type>
void linkedList<Type>::reverseList()
{
        Node *current;
        Node *next;
        Node *prev;

        current = first;
        prev = NULL;

        while(current)
        {
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
        }

        first = prev;
}

//find info of node from tail 
template <class Type>
Type linkedList<Type>::nodeFromTail(int position)
{

         int index;
         Node* current;
         Node* result;

         index = 0;
         current = first;
         result = first;
                     
         while(current!=NULL)
         {
                 current=current->next;
                 if (index++>positionFromTail)
                 {
                          result=result->next;
                 }
         }

         return result->info;
}

//remove duplicates in a sorted list
template <calss Type>
void linkedList<Type>::remove_duplicates()
{
        Node *current;
        Node *next;

        current = first;

        if(current == NULL)
                return EXIT_FAILURE;

        while(current->next != NULL)
        {
                if(current->info == current->next->info)
                {
                        next = current->next->next;
                        free(current->next);
                        current->next = next;
                }
                else
                        current = current->next;
        }
}

//detect loop
//Algorith: Floyd's cycle detecting algorithm
template <class Type>
bool linkedList<Type>::detectLoop()
{
        Node *fast;
        Node *slow;

        fast = first;
        slow = first;

        while(fast && slow && fast->next)
        {
                fast = fast->next->next;
                slow = slow->next;

                if(fast == slow)
                        return true;
        }
        
        return false;
}
//remove node at nth position
template <class Type>
Node linkedList<Type>::remove_nth_node(int position)
{
        Node *current;
        Node *prev;
        int i;

        current = first;
        prev = NULL;

        //traverse to nth node
        for(i = 0; i < position; i++)
        {
                prev = current;
                current = current->next;
        }

        if(n != 0) //update (n-1)th node 
                prev->next = current->next;
        else //update head
                first = first->next;

        free(current); //del nth node

        return head;

}
//destructor
template <class Type>
linkedList<Type>::~linkedList()
{
}
