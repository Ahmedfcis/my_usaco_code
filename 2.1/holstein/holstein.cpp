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

int VL[26];
int AL[26]={0};
int GL[16][26];

int main() {
    ofstream fout ("sort3.out");
    ifstream fin ("sort3.in");
	
	int V,G;
	fin >> V;
	for(int i=0;i<V;i++)
		fin >> VL[i]; 
	
	fin >> G;
	for(int i=0;i<G;i++)
		for(int j=0;j<V;j++)
			fin >> GL[i][j];
	
	int m = 0;
	int l= 1 << G;
	while(m < l){
		int x = m ^ ++m;
		int a = x & m;
		int r = x &(~m);
		
	}
	
	return 0;
}