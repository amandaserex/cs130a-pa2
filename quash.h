//quash.h
#ifndef QUASH_H
#define QUASH_H

using namespace std;

class quash{
public:
    void insert(int key); // Insert element i in both the heap and the hash table
    void lookup(int key); // Use the hash table to determine if i is in the data structure.
    void deleteMin(); //Use the heap to find the minimum element and decrement its count, return key that is deleted
    void Delete(int key); //Use the hash table to determine where i is and decrement its count
    void print(); //Print out the heap contents
private:
    pair<int,int> myHeap[100];//idk
    pair<int,int> myHashTable[43];//idk
};

#endif