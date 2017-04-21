/*
ID: ahmed_f6
PROG: holstein
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

int V,G;
short VL[25];
short GL[15][25];

bool  DP[1<<15+1] = {false};
short DP_v[1<<15+1][25];

bool check(int mask,int k){
	bool f=true;
	int nMask = mask | (1<<k);
	for(int i=0;i<V;i++){
		DP_v[nMask][i] = DP_v[mask][i] + GL[k][i];
		if( DP_v[nMask][i] < VL[i])
			f = false;
	}
	
	return f;
}

int find(int mask,int k,int deepth){
	
	for(int i=k;i<G;i++)
		if(!((1<<i) & mask)){
			int nMask = (1<<i) | mask;
			if(deepth > 0){
				int res = find(nMask,i,deepth-1);
				if( res !=-1)
					return res;
			}
			else{
				if(DP[nMask])
					continue;
				
				if(check(mask,i))
					return nMask;
				
				DP[nMask]=true;
			}
		}

	return -1;
}

int main() {
    ofstream fout ("holstein.out");
    ifstream fin ("holstein.in");

	fin >> V;
	for(int i=0;i<V;i++)
		fin >> VL[i]; 
	
	fin >> G;
	for(int i=0;i<G;i++)
		for(int j=0;j<V;j++)
			fin >> GL[i][j];
	
	
	int mask =-1;
	
	for(int i=0;i<G;i++){
		mask = find(0,0,i);
		if(mask!=-1)
			break;
	}
	
	int count=0;
	for(int i=0;i<G;i++)
		if((1<<i)&mask)
			count++;
	fout<<count;
	for(int i=0;i<G;i++)
		if((1<<i)&mask)
			fout<<" "<<(i+1);
	fout<<endl;
	return 0;
}