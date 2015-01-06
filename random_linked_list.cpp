/* 
You are given a Double Linked List with one pointer of each node pointing to the next node just like in a single link list. The second pointer however CAN point to any node in the list and not just the previous node. Now write a program in O(n) time to duplicate this list. That is, write a program which will create a copy of this list.
*/

/*
What do you mean by copy? copy the content only or the pointers have to point to the original nodes as well?

I mean this... lets say you have 
[3]   [1]  [2]
^      ^    ^
|      |    |
[1]-> [2]->[3]

you need to make new nodes on heap with the data like this and keep track of random pointers so you don't create duplicate nodes for random pointers

*/

#include<iostream>
#include <map>

using namespace std;

typedef struct node_t {
  int data;
  struct node *next;
  struct node *random;
}node;

node * copied(node * head_original){
    
    if( head_original == NULL )
        return NULL;

    node * head_copy = calloc( 1, sizeof(node_t));
    
    head_copy->data = head->data;

    head_copy->random = NULL;
    
    node * curr = head_original->next;
    node * copy = head_copy;
    node * nova = NULL;
    
    head_copy->next = nova;
    
    int counter = 0;
    
    map<node *, int> dict;
    map<int, node *> dict1;
    
    dict.insert( pair<node *, int>(head_original, counter) );
    counter++;
    
    while ( curr != NULL ) { // if curr is not NULL then populate
        nova = calloc( 1, sizeof(node_t));
        nova->data = curr->data;
        
        copy->next = nova;
        copy = nova;
        dict.insert( pair<node *, int>(curr, counter) );
        
        //update
        curr = curr->next;
        counter++;
    }
    
    curr = head_original;
    copy = head_copy;
    counter = 0;
    
    while ( curr != NULL ) {
    
        node * random = curr->random;
        int target = dict(random);
        
        dict1.insert( pair<int, node *>( target, copy) ); //copy should target at the same i-th node as its original copy in the list
    
        curr = curr->next;
        copy = copy->next;
        counter++;
    }
    
    copy = head_copy;
    counter = 0;
    
    while (copy != NULL ) {
        node * from = dict1(counter);
        from->random = copy;
        
    }

    return head_copy;
}
