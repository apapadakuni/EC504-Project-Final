#include <iostream>
#include <fstream>
#include <time.h>
#include <chrono>
#include <string>
#include <list>
#include "Fibheap.h"
using namespace std;

#define size 1001

int main(int argc, char* argv[]){
	int n = stoi(argv[1]);
	int n2 = stoi(argv[2]);
	bool dense;
	if(n2 == 1){
		dense = true;
	}
	else{
		dense = false;
	}


	int counter= 0;
	auto begin = std::chrono::high_resolution_clock::now();

	FibHeap<int> f;
	list<FibHeap<int>::FibNode*> nodes;

	// FibHeap<int>::FibNode* node2 = new FibHeap<int>::FibNode(3, nullptr);
	// f.insert(node2);

	// FibHeap<int>::FibNode* node3 = new FibHeap<int>::FibNode(3, nullptr);
	// f.insert(node3);
	for(int i = 1; i < n; i++){
		FibHeap<int>::FibNode* node = new FibHeap<int>::FibNode(i, nullptr);
		f.insert(node);
		nodes.push_back(node);
	}

	// f.decrease_key(node3, 1);

	for(int i = 1; i < n; i++){
		if(dense){
			for(list<FibHeap<int>::FibNode*>::iterator it = nodes.begin(); it != nodes.end(); it++){
				f.decrease_key(*it, (*it)->key-1);
			}
		}
		else{
			f.decrease_key(*(nodes.begin()), (*(nodes.begin()))->key-1);
		}
		FibHeap<int>::FibNode* min = f.minimum();
		//cout << min->key << endl;
		f.extract_min();
		nodes.pop_front();
	}



/*
	ifstream file(argv[1]);

	FibHeap<int>::FibNode* ptr;
	int input;
	int max = 0;
	int count = 0;
	while(!file.eof()){
		file >> input;

		FibHeap<int>::FibNode* node = new FibHeap<int>::FibNode(input, nullptr);
		if(input > max){
			max = input;
			ptr = node;
		}
		f.insert(node);
	}

	int min;
	while(!f.empty()){
		f.extract_min();
		if(f.empty()){
			break;
		}

		//sparse
		for(int i = 0; i < count; i++){
			f.decrease_key(ptr, ptr->key -10);
		}
		//Dense

	}
		file.close();

	*/

	auto end = std::chrono::high_resolution_clock::now();
	cout << chrono::duration_cast<chrono::nanoseconds>(end-begin).count() << endl;
	

	return 0;
}