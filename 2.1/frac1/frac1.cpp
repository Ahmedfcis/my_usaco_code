/*
ID: ahmed_f6
PROG: frac1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

struct _D{
	int v;
	int d;
} D[25600];


int compare(const void * a, const void * b)
{
  _D& d1 = *(_D*)a;
  _D& d2 = *(_D*)b;
  return ((d1.v * d2.d) == (d2.v * d1.d))?(d1.v - d2.v):((d1.v * d2.d) - (d2.v * d1.d));
}

int main() {
    ofstream fout ("frac1.out");
    ifstream fin ("frac1.in");
	
	int N;
	fin >> N;
	
	D[0].v = 0; D[0].d = 1;
	int k=1;
	for(int i=1;i <= N;i++)
		for(int j=i; j <= N;j++){
			D[k].d = j;
			D[k++].v = i;
		}
	
	qsort(D,k,sizeof(_D),compare);
	
	fout << D[0].v << "/" << D[0].d << endl;
	for(int i=1;i<k;i++)
		if(D[i].v * D[i-1].d != D[i-1].v * D[i].d)
			fout << D[i].v  << "/" << D[i].d << endl;
	
	return 0;
}