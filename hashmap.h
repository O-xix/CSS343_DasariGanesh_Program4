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

// ---------- HashMap Constructor -----------
// Description: Initializes a new hash map with a fixed capacity (number of buckets) 
// and sets up the internal storage structure (an array of linked lists).
// Preconditions: capacity must be a positive integer, as it represents the number of buckets in the hash map.
// The caller must ensure the capacity is reasonable for the data size intended to 
// be stored in the map (e.g., avoid too small a capacity to minimize collisions).
// Postconditions: The HashMap instance is initialized with a table of size 
// capacity where each index is set to nullptr, indicating an empty bucket.
template <typename K, typename V>
HashMap<K, V>::HashMap(int capacity) : capacity(capacity), size(0) {
    table = new Node<K, V>*[capacity];
    for (int i = 0; i < capacity; i++) {
        table[i] = nullptr;
    }
}

// ---------- HashMap Destructor -----------
// Description: Destroys the hash map by deallocating all dynamically 
// allocated memory, including the linked lists at each table index and the table array itself.
// Preconditions: The HashMap instance has been properly initialized 
// and contains allocated memory for its table and any linked lists.
// Postconditions: All memory allocated for the linked lists at each index in the hash table is freed.
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

// ---------- insert -----------
// Description: The `insert` method adds a key-value pair to the hash table.  
//    If the key already exists, the value is updated.  
//    In case of a hash collision, the method handles the collision using open hashing (separate chaining) by adding a new node to the linked list at the corresponding index.  
// Preconditions:  
//    - The key is of type K and the value is of type V.  
// Postconditions:  
//    - The key-value pair is added to the hash table, or if the key already exists, its value is updated.  
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

// ---------- get -----------
// Description:  
//    The `get` method retrieves the value associated with the given key.  
//    It computes the index using the hash function, and then traverses the linked list at that index to find the key.  
//    If the key is found, its value is returned; otherwise, the method returns a default-constructed value of type V.  
// Preconditions:  
//    - The key is of type K.  
// Postconditions:  
//    - If the key is found, the associated value is returned. If not, a default value of type V is returned.  
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

// ---------- remove -----------
// Description:  
//    The `remove` method removes the key-value pair with the given key from the hash table.  
//    It computes the index using the hash function, then traverses the linked list at that index to find and delete the corresponding node.  
//    The previous node's pointer is adjusted to maintain the linked list structure.  
// Preconditions:  
//    - The key is of type K.  
// Postconditions:  
//    - The key-value pair is removed from the hash table, and the size is decremented.  
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

// ---------- containsKey -----------
// Description:  
//    The `containsKey` method checks if the given key exists in the hash table.  
//    It computes the index using the hash function and traverses the linked list at that index to check for the key.  
// Preconditions:  
//    - The key is of type K.  
// Postconditions:  
//    - Returns true if the key exists in the hash table, false otherwise.  
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

// ---------- findValue -----------
// Description:  
//    The `findValue` method searches for a value in the hash table that satisfies a condition specified by the provided function pointer.  
//    It iterates through all linked lists in the hash table, invoking the condition function for each node's value.  
//    If a value satisfying the condition is found, the method returns a pointer to that value.  
// Preconditions:  
//    - The `condition` function pointer is a valid function that takes a reference to a value of type V and returns a boolean.  
// Postconditions:  
//    - If a value that satisfies the condition is found, a pointer to that value is returned.  
//    - If no matching value is found, nullptr is returned.  
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
