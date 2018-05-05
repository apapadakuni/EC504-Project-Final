


#include <iostream>
#include <list>
#include <chrono>

#include "eVEB.h"
#include "Graph.h"
#include "Graph.cpp"
#include "eVEB.cpp"

using namespace std;
#define NEG 1000000

int main(){
    
    Graph graph;
   
    graph.generateGraph("graph.txt");
    graph.print();
    
  
    
    //graph.modifiedDijkstra(0);
    int n = graph.getNumVertices();
    // list <int> example (1,NEG);
    
    vector <list <int> > d(10000);
    int source = 0;
    
    vector <int> PI(n,0);
    PI[source] = -20000; //equivalent of NULL
    list <int> zero (1,0);
    d[0].push_back(source);
    vector <int> keys(n);
    keys[0]=0;
    auto begin = chrono::high_resolution_clock::now(); keys[1]=25;
    int usize = 65536;
	eVEB* tree;
	tree = NULL;
    tree = Insert(tree, 0, 1, usize);
    //cout << GetCount(tree,0)<<endl;
    for (int i=2; i<n; i++){
        tree = Insert(tree, i+15500,1, usize);
        keys[i] = i+15500;
      //  cout << GetCount(tree,i+15000)<< endl;
    }
    int counter =0;
   
    while (tree!=NULL){
        if(counter == n)
            break;
        
  
        // cout << "YES" <<endl;
        int minkey = Minimum(tree);
        tree = Dlt(tree, minkey, usize);
        
        //    cout << "did it remove? " << (*tree).Search(tree,minkey) << endl;
        //    cout << "yo "<< endl;
       // cout << "minkey is " << minkey << endl;
        int u = d[minkey].front();
        
      //  cout << "U is " << u << endl;
        
        map <directedEdge, int>::iterator weightind;
        
        
        for (weightind = graph.weights.begin(); weightind != graph.weights.end(); weightind++){
            //    cout << "EDGES: " << (*weightind).first.first << " " << (*weightind).first.second<<endl;
            if ((*weightind).first.first == u){ //meaning that the first edge is equal to the our u edge
                //cout << u << " " << (*weightind).first.second << endl;
                int v = (*weightind).first.second;
                int weightuv = (*weightind).second;
//                cout << "v is " << v << endl;
//                cout << "keys v and u are " << keys[v] <<" "<< keys[u] << endl;
                if (keys[v]>(keys[u]+weightuv)){
      //              cout << "Relaxing and updating tree of " <<  keys[v] <<" " << keys[u]+weightuv << endl;
                    //cout << (*tree).Search(tree, keys[v]) ;
                    
                    //(*tree).Update(tree, keys[v], keys[u]+weightuv);
                    tree = Dlt(tree, keys[v], usize);
                    tree = Insert(tree, keys[u]+weightuv,1,usize);
                    keys[v]=keys[u]+weightuv;
                    
                    d[keys[v]].push_back(v);
                    PI[v]=u;
                    
                    
                }
                
                
            }
            
            
        }
        
        
        counter++;
    }
    auto end = chrono::high_resolution_clock::now();
    //cout << chrono::duration_cast<chrono::nanoseconds>(end-begin).count() << endl;
    
    
    
    
    cout << "Shortest paths from node " << source << ":" << endl;
    for (int j=0; j< keys.size(); j++){
        if (source == j) {
            j++;
        }
        cout << "Distance to vertex " << j << " is ";
        if (keys[j]==NEG){
            cout << "INF";
        }
        else cout <<  keys[j];
        
        cout << endl;
    }
    
    return 0;

//
//
//
//
//    }
    cout << "Done\n";
}
