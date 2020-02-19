#ifndef HASH_H
#define HASH_H

#include <vector>
using namespace std;

class Hash{
public:
    //void insert(pair<int,int> newguy);//increase count if there if not add to both
    bool Delete(int key);//delete from heap
    bool searchAndAdd(int key);
    void insertIt(pair<int,int> newguy, int where);
    int currentCount(int key);
    vector<pair<int,int>> table[43];
};

#endif