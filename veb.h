#ifndef eVEB_h
#define eVEB_h

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class vEB{
public:
    int u;
    int min, max;
    int countmin, countmax;
    struct vEB *summary, **cluster;
};

int high(int x, int u);

int low(int x, int u);

//int index(int x, int y, int u);


int Minimum(vEB *V);

int Maximum(vEB *V);

int GetCount(vEB *V, int x);

vEB* Insert(vEB *V, int x, int qtd, int u);

vEB* Dlt(vEB *V, int x, int u);



#endif