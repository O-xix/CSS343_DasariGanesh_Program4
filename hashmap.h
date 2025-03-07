//
// Created by tdasari on 3/7/25.
//

#ifndef HASHMAP_H
#define HASHMAP_H

using namespace std;

template <typename K, typename V>
class HashMap {
public:
    HashMap(int capacity);
        //Initialize table with capacity
        //Set size to 0
    ~HashMap();
        //Clear all LinkedLists in array indices for the table
    void insert(K key, V value);
    //To insert values into the HashMap
    //Would calculate hash value through a hash function
    //Would insert into table with key and value
    //Upon collision, would handle using open hashing, separate chaining, adding a node linked to nodes already at that index
    V get(K key);
    //To get values from the HashMap
    //Would go to the hash value/index in the table through traversal
    //Look for the key in the “bucket”, the LinkedList at that index
    //Retrieve the value associated with that key
    void remove(K key);
    //To remove key-value pairs from the Map
    //Would follow the same logic as the get() method, but would delete the node containing the key-value pair
    bool containsKey(K key);
    //To check if a key is already within the Map
    //Again, would follow the same value as the get() method to find the key, returns true or false if the key was found.
private:
    struct Node {
      K key;
      V value;
      Node *next;
      Node(K key, V value) : key(key), value(value), next(nullptr) {}
    };

    Node<K, V>** table; //Pointer to an array of LinkedlList Nodes with LinkedLists attached to those.
    int capacity; //Fixed size for hash table
    int size; //Tracks number of elements
}




#endif //HASHMAP_H
