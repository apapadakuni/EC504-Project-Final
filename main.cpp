


#include <iostream>
#include <list>
#include <chrono>

#include "veb.h"
// #include "eVEB.cpp"

using namespace std;

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
    
    int usize = 4294967296;
	vEB* tree;
	tree = nullptr;
    for (int i = 1; i<=n; i++){
        tree = Insert(tree,i,1, usize);
      //  tree = Dlt(tree,i,usize);
       // cout << GetCount(tree,i) << endl;
    }


    //Simulate Decrease key by inserting the updated key and deleting the previous key
    for (int i=n+1; i<=2*n+1; i++){
        if(dense){
            for(int j = n+1; j<=2*n+1; j++){
                tree = Insert(tree,i,1, usize);
                tree = Dlt(tree,i,usize);
            }
        }
        else{
            tree = Insert(tree,i,1, usize);
            tree = Dlt(tree,i,usize);
        }
    }
    
    for (int i=1; i<=n; i++){
        int min = Minimum(tree);
        tree = Dlt(tree,min,usize);
    }
    
//    for (int i=1; i<=2; i++){
//        cout << i<< endl;
//
//
//
//
//    }
    
    auto end = std::chrono::high_resolution_clock::now();
    cout << chrono::duration_cast<chrono::nanoseconds>(end-begin).count() << endl;
}
