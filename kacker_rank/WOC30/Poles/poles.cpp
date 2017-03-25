#include <cmath>
#include <cstdio>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

int N,K;
long A[5000][5000];

long dX[5000];
long W[5000];

void setup(){
	int tW;
	for(int i=N-1;i>=0;i--){
		A[i][i]=0;
		tW = W[i];
		for(int j= i-1;j>=0;j--){
			A[i][j] = A[i][j+1] + tW * dX[j];
			tW += W[j];
		}
	}
}

long mCost = LONG_MAX;
long cost=0;

void Find(int rK,int s){

	if(rK==1){
		cost += A[N-1][s];
		if(cost < mCost)
			mCost = cost;
		cost -= A[N-1][s];
		return;
	}

	//????
	for(int e= s;e<N-rK+1;e++){
		cost += A[e][s];
		if(cost < mCost)
			DFS(rK-1,e+1);
		cost -= A[e][s];
	}
}

int main() {
    cin >>N >> K;
	
	cin >> dX[0] >> W[0];
	for(int i=1;i<N;i++){
		cin >> dX[i] >> W[i];
		dX[i-1] = dX[i] - dX[i-1];
	}
	
	setup();
	
	Find(K,0);
	
	cout << mCost << endl;
    return 0;
}
