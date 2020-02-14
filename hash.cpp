#include "hash.h"
#include <vector>
#include <iostream>
using namespace std;

bool Hash:searchAndAdd(int key){
    for(int m = table[myHashKey].begin(); m!= table[myHashKey].end();m++){
		if(m.first==key){
			m.second++;
            return true;
        }
    }
    return false;
}
void Hash::insertIt(pair<int,int> newguy, int where){
    table[where].push_back(newguy);
    //increase count if there if not add to both

}


void Hash::Delete(int key){
//decrease count if zero delete from has and heap

}