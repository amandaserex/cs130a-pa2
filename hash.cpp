#include "hash.h"
#include <vector>
#include <iostream>
using namespace std;

bool Hash::searchAndAdd(int key){
    for(std::vector<std::pair<int, int> >::iterator m = table[key].begin(); m!= table[key].end();m++){
		if(m->first==key){
			m->second++;
            return true;
        }
    }
    return false;
}

int Hash::currentCount(int key){
    for(std::vector<std::pair<int, int> >::iterator m = table[key].begin(); m!= table[key].end();m++){
		if(m->first==key){
            return m->second;
        }
    }
    return 0;
}

bool Hash::Delete(int key){
    for(std::vector<std::pair<int, int> >::iterator m = table[key].begin(); m!= table[key].end();m++){
		if(m->first==key){
            m->second--;
            if(m->second==0){
                table[key].erase(m);
                return true; //it has been deleted
            }
        }
    }
    return false; //just decreased
}
void Hash::insertIt(pair<int,int> newguy, int where){
    table[where].push_back(newguy);
    //increase count if there if not add to both

}

