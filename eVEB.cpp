#include "eVEB.h"
#include <math.h>
#include <iostream>

int high(int val, int u){
    int num = val/sqrt(u);
    return num;
}


int low(int val, int u){
    int sq = sqrt(u);
    int res = val%sq;
    return res;
}



int Minimum(eVEB *Tree){
    return Tree->min;
}

int Maximum(eVEB *Tree){
    return Tree->max;
}

eVEB* Insert(eVEB *Tree, int val, int count, int u){

    if(!Tree){
     //   cout << "sup";
        Tree = (eVEB*)malloc(sizeof(eVEB));
        Tree->min = val;
        Tree->max = val;
        Tree->u = u;
        Tree->countmin = count;
        Tree->countmax = count;
        
        Tree->summary = NULL;
        Tree->cluster = NULL; //Space Efficiency here, declaring all clusters to be Null and creating them when they are initialized
        
    }
    else if(Tree->min == val){
        Tree->countmin+=count;
        if(Tree->max == val)
            Tree->countmax = Tree->countmin;
    }
    else if(Tree->max == val){
        Tree->countmax+=count;
    }
    else{
        if(val < Tree->min){
            if(Tree->min == Tree->max){
                Tree->min = val;
                Tree->countmin = count;
                return Tree;
            }
            int tempmin = Tree->min;
            Tree->min = val;
            val = tempmin;
            int tempcount = Tree->countmin;
            Tree->countmin = count;
            count = tempcount;
        }
        else if(val > Tree->max){
            int tempmax = Tree->max;
            Tree->max = val;
            val = tempmax;
            int tempcount = Tree->countmax;
            Tree->countmax = count;
            count = tempcount;
       //cout << val << endl;
            if(Tree->min == val)
                return Tree;
        }
        if(Tree->u > 2){
            if(Tree->cluster[high(val, Tree->u)] == NULL){
                Tree->summary = Insert(Tree->summary, high(val, Tree->u), 1, sqrt(Tree->u));
            }
   //        cout << "about to insert to cluster << high(val, Tree->u),low(val, Tree->u);
            Tree->cluster[high(val, Tree->u)] = Insert(Tree->cluster[high(val, Tree->u)], low(val, Tree->u), count, sqrt(Tree->u));
        }
    }
  //cout <<  "Just inserted " << x<<endl;
    return Tree;
}

eVEB* Dlt(eVEB *Tree, int val, int u){
    if(Tree->min == Tree->max){
        if(Tree->countmin > 1){
            Tree->countmin--;
            Tree->countmax--;
        }
        else{
            //Tree = NULL;
            free(Tree);
            return NULL;
        }
    }
    else if(Tree->u == 2){
        if(val == 0){
            if(!--Tree->countmin){
                Tree->min = 1;
                Tree->countmin = Tree->countmax;
            }
        }
        else{
            if(!--Tree->countmax){
                Tree->max = 0;
                Tree->countmax = Tree->countmin;
            }
        }
    }
    else{
       
        if(val == Tree->min){
           
            if(!--Tree->countmin){
                if(Tree->summary){
                    int first_cluster = Minimum(Tree->summary);
                    int new_min = Minimum(Tree->cluster[first_cluster]);
                 //cout << first_cluster << endl;
                    Tree->min = first_cluster * (int)sqrt(Tree->u) + new_min;
                 
                    Tree->countmin = Tree->cluster[first_cluster]->countmin;
                    (Tree->cluster[first_cluster])->countmin = 1;
                    if((Tree->cluster[first_cluster])->min == (Tree->cluster[first_cluster])->max)
                        (Tree->cluster[first_cluster])->countmax = 1;
                    Tree->cluster[first_cluster] = Dlt(Tree->cluster[first_cluster], new_min, sqrt(Tree->u));
                    if(Tree->cluster[first_cluster] == NULL)
                        Tree->summary = Dlt(Tree->summary, first_cluster, sqrt(Tree->u));
                }
                else{
                    Tree->min = Tree->max;
                    Tree->countmin = Tree->countmax;
                }
            }
        }
        else if(val == Tree->max){
            if(!--Tree->countmin){
                if(Tree->summary){
                    int last_cluster = Maximum(Tree->summary);
                    int new_max = Maximum(Tree->cluster[last_cluster]);
                    Tree->max = last_cluster * (int)sqrt(Tree->u) + new_max;
                    Tree->countmax = Tree->cluster[last_cluster]->countmax;
                    (Tree->cluster[last_cluster])->countmax = 1;
                    if((Tree->cluster[last_cluster])->min == (Tree->cluster[last_cluster])->max)
                        (Tree->cluster[last_cluster])->countmin = 1;
                    Tree->cluster[last_cluster] = Dlt(Tree->cluster[last_cluster], new_max, sqrt(Tree->u));
                    if(Tree->cluster[last_cluster] == NULL)
                        Tree->summary = Dlt(Tree->summary, last_cluster, sqrt(Tree->u));
                }
            }
        }
        else{
            Tree->cluster[high(val, Tree->u)] = Dlt(Tree->cluster[high(val, Tree->u)], low(val, Tree->u), sqrt(Tree->u));
            if(Tree->cluster[high(val, Tree->u)] == NULL)
                Tree->summary = Dlt(Tree->summary, high(val, Tree->u), sqrt(Tree->u));
        }
    }
    return Tree;
}



int GetCount(eVEB *Tree, int val){

    if(!Tree)
        return 0;
    else if(Tree->min == val)
        return Tree->countmin;
    else if(Tree->max == val)
        return Tree->countmax;
    else{
        if(Tree->cluster)
            return GetCount(Tree->cluster[high(val, Tree->u)], low(val, Tree->u));
        else
            return 0;
    }
}
