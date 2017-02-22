/*
ID: ahmed_f6
PROG: helpcross
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <set>
using namespace std;

int Nh,Nc;
int H[20001];
struct Interval{
	int s;
	int e;
	bool v;
} C[20001];

int HComp(const void * a, const void * b){
  return ( *(int*)a - *(int*)b );
}

int CComp(const void * a, const void * b){
	C* c1 = (C*)a;
	C* c2 = (C*)b;
	return (c1->s == c2->s)?(c1->e - c2->e):(c1->s - c2->s);
}

int main() {
    ofstream fout ("helpcross.out");
    ifstream fin ("helpcross.in");
		
	fin >> Nh >> Nc;
	for(int i=0;i<Nh;i++)
		fin >> H[i];
	
	for(int i=0;i<Nc;i++){
		fin >> C[i].s >> C[i].e;
		C[i].v = false;
	}
	
	qsort(H,Nh,sizeof(int),HComp);
	qsort(C,Nc,sizeof(Interval),CComp);
	
	int total=0;
	
	
	return 0;
}