/*
ID: ahmed_f6
PROG: sort3
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

int N;
int A[1001];
int B[1001];

struct _G{
vector<int> e;
bool v;
};

_G* G;

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int find (int * L, int v){
	for(int i=0;i<N;i++)
		if(L[i] == v)
			return i;
			
	return -1;
}

int BFS(int k){

	return 0;
}

int main() {
    ofstream fout ("sort3.out");
    ifstream fin ("sort3.in");

	fin >> N;
	
	G = new _G[N];
	
	for(int i=0;i<N;i++){
		fin >> A[i];
		B[i] = A[i];
	}
	
	qsort (B, N, sizeof(int), compare);
	
	for(int i = 0;i < N;i++){
		int k = find(B,A[i]);
		do{
			G[i].e.push_back(k++);
		}while(B[k]==A[i]);
		
		G[i].v = false;
	}
	
	int cost = 0;
	for(int i=0;i < N; i++){
		if(G[i].v == false)
			cost += BFS(i);
	}
	
	fout << cost << endl;
	return 0;
}