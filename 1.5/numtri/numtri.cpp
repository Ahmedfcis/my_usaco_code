/*
ID: ahmed_f6
PROG: numtri
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <set>
using namespace std;

int N;
int V[1001]={0};

void swap(int& x,int& y){
	int t=x;
	x=y;
	y=t;
}

int main() {
    ofstream fout ("numtri.out");
    ifstream fin ("numtri.in");
	
	fin >> N;
	for(int i=0;i<N;i++){	
		for(int j=0;j<=i;j++){
			int a;
			fin >> a;
			V[j] += a;
		}
		
		if(i == N-1) //last line
			break;
			
		int l = V[0];
		for(int j=1;j<=i;j++){
			if(l > V[j])
				swap(l,V[j]);
			else
				l = V[j];
		}
		V[i+1] = l;
	}
	
	int max=0;
	for(int i=0;i<N;i++)
		if(V[i]>max)
			max = V[i];
			
	fout<<max<<endl;
	return 0;
}
