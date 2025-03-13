//
// Created by tdasari on 3/7/25.
//

#ifndef HASHMAP_H
#define HASHMAP_H

using namespace std;

template <typename K, typename V>
struct Node {
    K key;
    V value;
    Node *next;
    Node(K key, V value) : key(key), value(value), next(nullptr) {};
};

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
    int hash(K key);
private:
    Node<K, V>** table; //Pointer to an array of LinkedlList Nodes with LinkedLists attached to those.
    int capacity; //Fixed size for hash table
    int size; //Tracks number of elements
};

// Implementation (because template classes must be implemented in the same file) -----------------------------------------------------------------------------------

template <typename K, typename V>
HashMap<K, V>::HashMap(int capacity) : capacity(capacity), size(0) {
    table = new Node<K, V>*[capacity];
    for (int i = 0; i < capacity; i++) {
        table[i] = nullptr;
    }
}

template <typename K, typename V>
HashMap<K, V>::~HashMap() {
    for (int i = 0; i < capacity; i++) {
        Node<K, V>* current = table[i];
        while (current != nullptr) {
            Node<K, V>* next = current->next;
            delete current;
            current = next;
        }
    }
    delete[] table;
}

// Define a hash function (example for integers)

template <typename K, typename V>
void HashMap<K, V>::insert(K key, V value) {
    // @todo: Implement a better hash function
    int index = hash(key) % capacity;
    Node<K, V>* current = table[index];
    while (current != nullptr) {
        if (current->key == key) {
            current->value = value;
            return;
        }
        current = current->next;
    }
    Node<K, V>* newNode = new Node<K, V>(key, value);
    newNode->next = table[index];
    table[index] = newNode;
    size++;
}

template <typename K, typename V>
V HashMap<K, V>::get(K key) {
    int index = hash(key) % capacity;
    Node<K, V>* current = table[index];
    while (current != nullptr) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }
    return V(); // Return default value of V
}

template <typename K, typename V>
void HashMap<K, V>::remove(K key) {
    int index = hash(key) % capacity;
    Node<K, V>* current = table[index];
    Node<K, V>* prev = nullptr;
    while (current != nullptr) {
        if (current->key == key) {
            if (prev == nullptr) {
                table[index] = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;
            size--;
            return;
        }
        prev = current;
        current = current->next;
    }
}

template <typename K, typename V>
bool HashMap<K, V>::containsKey(K key) {
    int index = hash(key) % capacity;
    Node<K, V>* current = table[index];
    while (current != nullptr) {
        if (current->key == key) {
            return true;
        }
        current = current->next;
    }
    return false;
}

template <typename K, typename V>
int HashMap<K, V>::hash(K key) {
    if (typeid(K) == typeid(int)) {
        return key;
    }
    if (typeid(K) == typeid(string)) {
        int hash = 0;
        for (char c : key) {
            hash += c;
        }
        return hash;
    }
    return 0;
}

#endif //HASHMAP_H
