//quash.cpp

#include "quash.h"
#include <string>
#include <sstream>


using namespace std;

void quash::insert(int key){
	//“item successfully inserted, count = 1” or “item already present, new count =n”
	int myHashKey;
	if(key<0){
		myHashKey = (key%43)+43;
	}
	else{
		myHashKey = key%43;
	}
	if(!myHash.searchAndAdd(myHashKey)){
		pair<int, int> temp;
		temp.first=key;
		temp.second=1; 
		myHash.insertIt(temp, myHashKey);
		myHeap.push(key);
	}
}

void quash::lookup(int key){
	//“item found, count = n” or “item not found”

}

void quash::deleteMin(){
	//“min item = x, count decremented, new count = n” or “min item x successfully deleted” or “min item not present since table is empty”

}

void quash::Delete(int key){
	//"item count decremented, new count = n” or “item successfully deleted” or “item not present in the table”

}

void quash::print(){
	//prints out the heap array with elements separated by a whitespace.

}


int main(int argc, char* argv[]){
	if(argc!=2){
		cerr<<argv[0]<< " Expects two arguements"<<endl;
	}
	quash myQuash;
	string command;
	stringstream ss1;
	ss1<< argv[1];
	while(getline(ss1,command,',')){
		int insert = 0;
		int Delete= 0;
		int lookUp=0;
		string thing;
		stringstream ss2;
		ss2<<command;
		while(getline(ss2, thing, ' ')){
			if(thing=="insert"){
				insert++;
			}
			else if(thing=="Delete"){
				Delete++;
			}
			else if(thing=="lookup"){
				lookUp++;
			}
			else if(thing=="deleteMin"){
				myQuash.deleteMin();
			}
			else if(thing=="print"){
				myQuash.print();
			}
			else{
				if(insert>0){
					myQuash.insert(stoi(thing));
				}
				else if(Delete>0){
					myQuash.Delete(stoi(thing));
				}
				else if(lookUp>0){
					myQuash.lookup(stoi(thing));
				}
			}

		}
		

	}

	return 0;
}
