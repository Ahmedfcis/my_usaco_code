/*
ID: ahmed_f6
PROG: skidesign
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define SQUARE(X)	((X)*(X))

int main() {
    ofstream fout ("skidesign.out");
    ifstream fin ("skidesign.in");
	
	int nHills[1001];
	int	N;
	int nMax,nMin;
	
	fin >> N;
	fin >> nHills[0];
	
	nMax = nMin = nHills[0];
	
	for(int i=1;i<N;i++){
		fin >> nHills[i];
		if(nHills[i] > nMax)
			nMax = nHills[i];

		if(nHills[i] < nMin)
			nMin = nHills[i];
	}
	
	int minCost = SQUARE(nMax)*N;//too large
	for(int j=nMin;j <= (nMax-17);j++){
		int cost=0;
		for(int i=0;i<N;i++){
			if(nHills[i] < j)
				cost += SQUARE(j - nHills[i]);
			else if(nHills[i] > (j+17))
				cost += SQUARE(nHills[i] - j - 17);
		}
		if(cost < minCost)
			minCost = cost;
	}
	
	fout << minCost << endl;
	return 0;
}