#include <cmath>
#include <cstdio>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

int N,K;

struct Node{
	long X;
	long W;
	long C;
	Node* N;
	Node* P;
};

Node A[5000];

long cost=0;

void merge(){
	
	Node* Q = A[0].N;
	Node* mQ = Q;
	long mC = Q->C;
	Q = Q->N;
	while(Q){
		if(Q->C < mC){
			mC = Q->C;
			mQ = Q;
			break;
		}
		Q = Q->N;
	}
	
	mQ->P->W += mQ->W;
	mQ->P->C  = (mQ->P->P)? mQ->P->W * (mQ->P->X - mQ->P->P->X):0;
	mQ->P->N = mQ->N;
	
	cost += mC;
	
	if(mQ->N){
		mQ->N->C = mQ->N->W * (mQ->N->X - mQ->P->X);
		mQ->N->P = mQ->P;
	}
}

int main() {
    cin >>N >> K;
	
	cin >> A[0].X >> A[0].W;
	A[0].C = 0;
	A[0].P = NULL;
	
	for(int i=1;i<N;i++){
		cin >> A[i].X >> A[i].W;
		A[i].C = A[i].W*(A[i].X-A[i-1].X);
		A[i].P = A+i-1;
		A[i-1].N = A+i;
	}
	A[N-1].N = NULL;
	
	
	for(int i=0;i<N-K;i++)
		merge();
	
	cout << cost << endl;
	return 0;
}