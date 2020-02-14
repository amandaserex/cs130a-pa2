#ifndef HASH_H
#define HASH_H

#include <vector>
using namespace std;

class Hash{
public:
    //void insert(pair<int,int> newguy);//increase count if there if not add to both
    void Delete(int key);//decrease count if zero delete from heap
    bool searchAndAdd(int key);
    void insertIt(pair<int,int> newguy, int where);
    vector<pair<int,int>> table[43];
}

#endif