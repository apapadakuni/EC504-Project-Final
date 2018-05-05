#ifndef eVEB_h
#define eVEB_h

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class eVEB{
public:
    int u;
    int min, max;
    int countmin, countmax;
    eVEB *summary, **cluster;
};

int high(int x, int u);

int low(int x, int u);

//int index(int x, int y, int u);


int Minimum(eVEB *Tree);

int Maximum(eVEB *Tree);

int GetCount(eVEB *Tree, int val);

eVEB* Insert(eVEB *Tree, int val, int count, int u);

eVEB* Dlt(eVEB *Tree, int val, int u);



#endif
