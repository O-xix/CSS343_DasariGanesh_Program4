//-------------------------- hashmap.h ---------------------------
// Programmers: Teja Dasari and Shreyas Sundar Ganesh
// Creation Date: 2/25/25
// Date of last modification: 3/15/25
// -------------------------------------------------------------------- 
// Purpose: This header file defines and implements the `HashMap` class,
// a key-value store implementation using separate chaining 
// (open hashing) for collision resolution.
// -------------------------------------------------------------------- 

#ifndef HASHMAP_H
#define HASHMAP_H

#include <string>
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
    /**
     * @brief Constructs a HashMap with the given capacity.
     * 
     * @param capacity The capacity of the HashMap.
     * @pre None
     * @post The HashMap is created with the specified capacity.
     */
    HashMap(int capacity);
        //Initialize table with capacity
        //Set size to 0
    /**
     * @brief Destroys the HashMap and frees all allocated memory.
     * 
     * @pre The HashMap has been created.
     * @post All memory allocated for the HashMap is freed.
     */
    ~HashMap();
        //Clear all LinkedLists in array indices for the table

    /**
     * @brief Inserts a key-value pair into the HashMap.
     * 
     * @param key The key to insert.
     * @param value The value to insert.
     * @pre The HashMap has been created.
     * @post The key-value pair is inserted into the HashMap.
     */
    void insert(K key, V value);
    //To insert values into the HashMap
    //Would calculate hash value through a hash function
    //Would insert into table with key and value
    //Upon collision, would handle using open hashing, separate chaining, adding a node linked to nodes already at that index
    /**
     * @brief Retrieves the value associated with the given key.
     * 
     * @param key The key to search for.
     * @return V The value associated with the key.
     * @pre The HashMap has been created.
     * @post Returns the value associated with the key.
     */
    V get(K key);
    //To get values from the HashMap
    //Would go to the hash value/index in the table through traversal
    //Look for the key in the “bucket”, the LinkedList at that index
    //Retrieve the value associated with that key
    /**
     * @brief Removes the key-value pair associated with the given key.
     * 
     * @param key The key to remove.
     * @pre The HashMap has been created.
     * @post The key-value pair is removed from the HashMap.
     */
    void remove(K key);
    //To remove key-value pairs from the Map
    //Would follow the same logic as the get() method, but would delete the node containing the key-value pair
    /**
     * @brief Checks if the HashMap contains the given key.
     * 
     * @param key The key to check for.
     * @return bool True if the key is found, false otherwise.
     * @pre The HashMap has been created.
     * @post Returns true if the key is found, false otherwise.
     */
    bool containsKey(K key);
    //To check if a key is already within the Map
    //Again, would follow the same value as the get() method to find the key, returns true or false if the key was found.
    /**
     * @brief Hash function for integer keys.
     * 
     * @param key The key to hash.
     * @return int The hash value of the key.
     * @pre The HashMap has been created.
     * @post Returns the hash value of the key.
     */
    int hash(int key) {
        return key;
    }

    /**
     * @brief Hash function for string keys.
     * 
     * @param key The key to hash.
     * @return int The hash value of the key.
     * @pre The HashMap has been created.
     * @post Returns the hash value of the key.
     */
    int hash(string& key) {
        int hash = 0;
        for (char c : key) {
            hash = hash * 2 + c;
        }
        return hash;
    }

    /**
     * @brief Finds a value in the HashMap that satisfies the given condition.
     * 
     * @param condition A function pointer to the condition to check.
     * @return V* A pointer to the value that satisfies the condition, or nullptr if no value is found.
     * @pre The HashMap has been created.
     * @post Returns a pointer to the value that satisfies the condition, or nullptr if no value is found.
     */
    V* findValue(bool (*condition)(const V&));
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
V* HashMap<K, V>::findValue(bool (*condition)(const V&)) {
    for (int i = 0; i < capacity; i++) {
        Node<K, V>* current = table[i];
        while (current != nullptr) {
            if (condition(current->value)) {
                return &(current->value);
            }
            current = current->next;
        }
    }
    return nullptr; // Return nullptr if no value matches the condition
}

#endif //HASHMAP_H
