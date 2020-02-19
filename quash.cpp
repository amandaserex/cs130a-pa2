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
		cout<<"item successfully inserted, count = 1"<<endl;
	}
	else{
		cout<<"item already present, new count = " << myHash.currentCount(myHashKey)<<endl;
	}
}

void quash::lookup(int key){
	int myHashKey;
	if(key<0){
		myHashKey = (key%43)+43;
	}
	else{
		myHashKey = key%43;
	}
	if(myHash.currentCount(myHashKey)==0){
		cout<<"item not found"<<endl;
	}
	else{
		cout<<"item found, count = "<<myHash.currentCount(myHashKey)<<endl;
	}
	//“item found, count = n” or “item not found”

}

void quash::deleteMin(){
	//“min item = x, count decremented, new count = n” or “min item x successfully deleted” or “min item not present since table is empty”
	if(myHeap.empty()){
		cout<<"min item not present since table is empty"<<endl;
	}
	else{
		if(myHash.Delete(myHeap.top())){
			cout<<"min item "<< myHeap.top() <<" successfully deleted"<<endl;
			myHeap.pop();
		}
		else{
			cout<<"min item = "<< myHeap.top()<< ", count decremented, new count = "<<myHash.currentCount(myHeap.top())<<endl;
		}
	}
}

void quash::Delete(int key){
	//"item count decremented, new count = n” or “item successfully deleted” or “item not present in the table”
	if(myHash.Delete(key)){
		cout<< "item successfully deleted"<<endl;
		priority_queue<int> temp;
		while(myHeap.top()!=key){
			temp.push(myHeap.top());
			myHeap.pop();
		}
		myHeap.pop();
		while(!temp.empty()){
			myHeap.push(temp.top());
			temp.pop();
		}
	}
	else if(myHash.currentCount(key)>0){
		cout<<"item count decremented, new count = "<<myHash.currentCount(key)<<endl;
	}
	else{
		cout<<"item not present in the table"<<endl;
	}
}

void quash::print(){
	//prints out the heap array with elements separated by a whitespace.
	priority_queue<int> temp;
	while(!myHeap.empty()){
		cout<<myHeap.top()<<" ";
		temp.push(myHeap.top());
		myHeap.pop();
	}
	while(!temp.empty()){
		myHeap.push(temp.top());
		temp.pop();
	}
	cout<<endl;
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
			else if(thing=="delete"){
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
