#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

#include "Node.h"

template<class T>
class LinkedList {
public: // DO NOT CHANGE THIS PART.
    LinkedList();
    LinkedList(const LinkedList<T> &obj);

    ~LinkedList();

    int getSize() const;
    bool isEmpty() const;
    bool contains(Node<T> *node) const;

    Node<T> *getFirstNode() const;
    Node<T> *getLastNode() const;
    Node<T> *getNode(const T &data) const;
    Node<T> *getNodeAtIndex(int index) const;

    void insertAtTheFront(const T &data);
    void insertAtTheEnd(const T &data);
    void insertAfterNode(const T &data, Node<T> *node);
    void insertAsEveryKthNode(const T &data, int k);

    void removeNode(Node<T> *node);
    void removeNode(const T &data);
    void removeAllNodes();
    void removeEveryKthNode(int k);

    void swap(Node<T> *node1, Node<T> *node2);
    void shuffle(int seed);

    void print(bool reverse=false) const;

    LinkedList<T> &operator=(const LinkedList<T> &rhs);

private: // YOU MAY ADD YOUR OWN UTILITY MEMBER FUNCTIONS HERE.
    

private: // DO NOT CHANGE THIS PART.
    Node<T> *head;

    int size;
};

template<class T>
LinkedList<T>::LinkedList() {
    /* TODO */
    size=0; 
    head=NULL;
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T> &obj) {
    /* TODO */
    /* LinkedList<T>  */
    head=obj.head;
    obj=obj.size;
    //WRONG

}

template<class T>
LinkedList<T>::~LinkedList() {
    /* TODO */
    removeAllNodes();
    delete head;
    head=NULL ;

}

template<class T>
int LinkedList<T>::getSize() const {
    /* TODO */
    return size ;
}

template<class T>
bool LinkedList<T>::isEmpty() const {
    /* TODO */
    return (size==0);
    // ın the slides return head==NULL ;

}

template<class T>
bool LinkedList<T>::contains(Node<T> *node) const {
    /* TODO */
    if (size==0)
    {
        return false ;
    }
    if (size==1)
    {
        return (head->data == node->data);
    }
    
    Node<T> *temp = head ;
    while (temp->next!=head)
    {
        //check if checking next and prev pointers can work properly
        //ıf not , check next and prev pointer's data.
        if (temp->data==node->data && temp->next==node->next&& temp->prev==node->prev )
        {
            return true;
        }

        temp=temp->next;
        
    }return false;
    
    


}

template<class T>
Node<T> *LinkedList<T>::getFirstNode() const {
    /* TODO */
    return head ;
    //should return a pointer!!
}

template<class T>
Node<T> *LinkedList<T>::getLastNode() const {
    /* TODO */
      if(head) //if head
        return head->prev ;
    else
        return NULL;  
   /*    if (getSize()==0)
     {
        return NULL;
     }if (getSize()==1)
     {
        return head;
     }else
     {
        return head->prev;
     }
      
      */
        
}

template<class T>
Node<T> *LinkedList<T>::getNode(const T &data) const {
    /* TODO */
    if (getSize()==0)
    {
        return NULL ;
    }
    
    Node<T> *temp = head ;
    while (temp->next!=head)
    {
        if (temp->data==data)
        {
            return temp ;
        }
        temp = temp->next;
    }
    return NULL ;
    
}

template<class T>
Node<T> *LinkedList<T>::getNodeAtIndex(int index) const {
    /* TODO */
        if (getSize()<index+1)
        {
            return NULL ;
        }
        Node<T> *temp = head ;
        int startIndex = 0;
        while (startIndex<= index)
        {
            if (startIndex== index)
            {
                return  temp;
            }
            startIndex ++ ;
            temp=temp->next ;
        }
        
}

template<class T>
void LinkedList<T>::insertAtTheFront(const T &data) {
    /* TODO */
    Node<T> *newNode = new Node<T>(data);

    if (size==0)
    {
        head = newNode;
        head->next=head;
        head->prev=head;
    }else
    {
        Node <T> *temp = head ;
        while (temp->next!=head)
        {
            temp=temp->next;
        }

        temp->next=newNode;
        newNode->prev=temp ;
        temp=head;
        temp->prev=newNode;
        newNode->next=temp;
        head=newNode;  
    }
    size++;

    
}

template<class T>
void LinkedList<T>::insertAtTheEnd(const T &data) {
    /* TODO */
    
    Node<T> *newNode = new Node<T>(data);
    

    if (size==0)
    {
        
        head = newNode;
        head->next=head;
        head->prev=head;
        
    }else
    {
        Node <T> *temp = head ;
        while (temp->next!=head)
        {
            temp=temp->next;
        }

        temp->next=newNode;
        newNode->prev=temp ;
        temp=head;
        temp->prev=newNode;
        newNode->next=temp;
        
    }
    size++;
}

template<class T>
void LinkedList<T>::insertAfterNode(const T &data, Node<T> *node) {
    /* TODO */
   /*  bool isNodeExist = false; */
   if (size==0)
   {
    return ;
   }if (size==1)
   {
    if (head->data==node->data)
    {
        insertAtTheEnd(data);   
    }else return;
    
   }
   
    Node<T> *temp= head;
    while (temp->next!=head)
    {
        if (temp->data ==node->data)
        {
            Node<T> *newNode = new Node<T>(data);
            Node<T> *tempNext = temp->next;
            temp->next= newNode;
            newNode->prev = temp ;
            newNode->next = tempNext ;
            tempNext->prev = newNode;
            size ++ ;
        }

        temp=temp->next;
        
    }
    

}

template<class T>
void LinkedList<T>::insertAsEveryKthNode(const T &data, int k) {
    /* TODO */
    if (k<2 )
    {
        return;
    }
    
 Node<T> *temp = head;
 int temp_Index= k;
 int temp_Size= getSize();
for (int i = 0; i < temp_Size; i++)
{
    temp_Index--;

    if(temp_Index == 1)
    {
        insertAfterNode(data, temp);

        temp = temp->next->next;

        temp_Index = k;
    }
    else
    {
        temp = temp->next;
    }

}



}

template<class T>
void LinkedList<T>::removeNode(Node<T> *node) {
    /* TODO */
    if (size==0)
    {
        return ;
    } if (size==1)
    {
        if (node->data == head->data)
        {
            head=NULL;
            size -- ;
        }
        
    } 
    else
    {
        Node <T> *temp = head ;
    
        
         while ( temp->next!= head)
        {
            if (temp->data==node->data)
            {
                if (temp==head)
                {
                    head=temp->next;
                }
                
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
                size-- ;
            }

             temp = temp->next; 
            
        } 
        
    }
    
    
}

template<class T>
void LinkedList<T>::removeNode(const T &data) {
    /* TODO */
    
    if (size==0)
    {
        return ;
    }
    if (size==1)
    {
        if (data == head->data)
        {
            head=NULL;
            size -- ;
        }
        
    }
    else
    {
        Node <T> *temp = head ;
        while (temp->next!=head)
        {
            if (temp->data==data)
            {
                if (temp==head)
                {
                    head=temp->next;
                }
                
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
                size-- ;
            }
              temp = temp->next; // ADDED!!!!!
        }
        
    }
}

template<class T>
void LinkedList<T>::removeAllNodes() {
    /* TODO */
    

    if(head != NULL){
        while (getSize() == 0)
        {
            Node<T>* tmp = head;
            removeNode(tmp);
        }
        
        head=NULL;
        size=0;
    }
    
    //allocate ettiğin memoryi deallocate et.//
    
}

template<class T>
void LinkedList<T>::removeEveryKthNode(int k) {
    /* TODO */
     if (k<2 )
    {
        return;
    }
    
 Node<T> *temp = head;
 int temp_Index= k;
 int temp_Size= getSize();
for (int i = 0; i < temp_Size; i++)
{
    temp_Index--;

    if(temp_Index == 1)
    {
         removeNode(temp);

        temp = temp->next->next;

        temp_Index = k;
    }
    else
    {
        temp = temp->next;
    }

}
}

template<class T>
void LinkedList<T>::swap(Node<T> *node1, Node<T> *node2) {
    /* TODO */
if (!contains(node1)|| !contains(node2))
{
    return ;
}

    Node<T>*temp1= head;
    Node<T>*temp2=head;
    while (temp1!=node1)
    {
        temp1=temp1->next;

    }
    while (temp2!=node2)
    {
        temp2=temp2->next;
        
    }
    Node<T>*temp1_prev= temp1->prev;
    Node<T>*temp2_prev=temp2->prev;
    Node<T>*temp1_next= temp1->next;
    Node<T>*temp2_next=temp2->next;
    temp1->prev=temp2_prev;
    temp1->next=temp2_next;
    temp2->prev=temp1_prev;
    temp2->next=temp1_next;
}

template<class T>
void LinkedList<T>::shuffle(int seed) {
    /* TODO */
     
    for (int i = 0; i < size-1; i++)
    {
        Node<T>*temp1=getNodeAtIndex(0);
        Node<T>*temp2=getNodeAtIndex((i*i+seed)%size);
        swap(temp1,temp2);
    }

}

template<class T>
void LinkedList<T>::print(bool reverse) const {
    if (this->isEmpty()) {
        std::cout << "The list is empty." << std::endl;
        return;
    }

    if (reverse) {
        // traverse in reverse order (last node to first node).

        Node<T> *node = this->getLastNode();

        do {
            std::cout << *node << std::endl;
            node = node->prev;
        }
        while (node != this->getLastNode());
    } else {
        // traverse in normal order (first node to last node).

        Node<T> *node = this->getFirstNode();

        do {
            std::cout << *node << std::endl;
            node = node->next;
        }
        while (node != this->getFirstNode());
    }
}

template<class T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &rhs) {
    /* TODO */
/*     removeAllNodes();

    Node<T>* rhsTmp = rhs.head;

    for (int i = 0; i < rhs.getSize(); i++)
    {
        this->insertAtTheEnd(rhsTmp->data);
        rhsTmp = rhsTmp->next;
    }
    
    
    return *this; */
}

#endif //LINKEDLIST_H
