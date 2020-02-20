#include "hash.h"
#include <list>
#include <iostream>
using namespace std;

bool Hash::searchAndAdd(int key){
    int myHashKey;
	if(key<0){
		myHashKey = (key%43)+43;
	}
	else{
		myHashKey = key%43;
	}
    for(std::list<std::pair<int, int> >::iterator m = table[myHashKey].begin(); m!= table[myHashKey].end();m++){
		if(m->first==key){
			m->second++;
            return true;
        }
    }
    return false;
}

int Hash::currentCount(int key){
    int myHashKey;
	if(key<0){
		myHashKey = (key%43)+43;
	}
	else{
		myHashKey = key%43;
	}
    for(std::list<std::pair<int, int> >::iterator m = table[myHashKey].begin(); m!= table[myHashKey].end();m++){
		if(m->first==key){
            return m->second;
        }
    }
    return 0;
}

bool Hash::Delete(int key){
    int myHashKey;
	if(key<0){
		myHashKey = (key%43)+43;
	}
	else{
		myHashKey = key%43;
	}
    for(std::list<std::pair<int, int> >::iterator m = table[myHashKey].begin(); m!= table[myHashKey].end();m++){
		if(m->first==key){
            m->second=m->second-1;
            if(m->second==0){
                table[myHashKey].erase(m);
                return true; //it has been deleted
            }
        }
    }
    return false; //just decreased
}
void Hash::insertIt(pair<int,int> newguy, int where){
    table[where].push_front(newguy);
    //increase count if there if not add to both

}

