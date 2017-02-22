/*
ID: ahmed_f6
PROG: wormhole
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <set>
using namespace std;

int conn[20];
int hole[20];

int isLoop(int N){
	
	for(int i=0;i<N;i++){
		int c = i;
		for(int j=0;j<=N;j++){
			if(conn[c]==-1)
				break;
			c = hole[conn[c]];
		}
		if(conn[c]!=-1)
			return 1;
	}
	return 0;
}
	
int checkAll(int N){

		int from=-1;
		for(int i=0;i<N;i++)
			if(hole[i]==-1){
				from = i;
				break;
			}
			
		if(from != -1){
			int loops=0;
			for(int i=from+1;i<N;i++){
				if(hole[i]==-1){
					hole[from]=i;
					hole[i]=from;
					loops += checkAll(N);
					hole[from]=-1;
					hole[i]=-1;
				}
			}
			return loops;
		}

	cout<<endl;
	return isLoop(N);
}

int main() {
    ofstream fout ("wormhole.out");
    ifstream fin ("wormhole.in");
	
	int N;
	int	X[20]={0};
	int Y[20]={0};
	
	fin >> N;
	for(int i=0;i<N;i++){
		fin >> X[i] >> Y[i];
		conn[i]=hole[i]=-1;
	}
	
	for(int i=0;i<N;i++){
		int prev=-1;
		int prevX=-1;
		for(int j=0;j<N;j++){
			if(i!=j && Y[i] == Y[j] && X[j] < X[i] && X[j] > prevX){
				prev = j;
				prevX = X[j];
			}
		}
		if(prev != -1)
			conn[prev]=i;
	}
	
	int nloops = checkAll(N);
	fout<< nloops <<endl;
	return 0;
}