//quash.h
#ifndef QUASH_H
#define QUASH_H
#include "hash.h"
#include <bits/stdc++.h> 
#include <list>
using namespace std;


class quash{
public:
    void insert(int key); // Insert element i in both the heap and the hash table, (-100 % 43)+43 for neg numbers
    void lookup(int key); // Use the hash table to determine if i is in the data structure.
    void deleteMin(); //Use the heap to find the minimum element and decrement its count, return key that is deleted
    void Delete(int key); //Use the hash table to determine where i is and decrement its count
    void print(); //Print out the heap contents
private:
    Hash myHash;
    priority_queue<int, vector<int>, greater<int>> myHeap;
};

#endif