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
int S[4]={0};
int C[4][4];

int main() {
    ofstream fout ("sort3.out");
    ifstream fin ("sort3.in");
	
	fin >> N;
	
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			C[i][j]=0;
	
	for(int i=0;i<N;i++){
		fin >> A[i];
		S[A[i]]++;
	}

	int t=0;
	for(int k=1;k<=3;k++)
		for(int j=0;j<S[k];j++)
			C[k][A[t++]]++;
/*
	for(int i=0;i<4;i++)		
		cout << S[i] <<", ";
	cout <<endl;
	
	for(int i=1;i<4;i++){
		for(int j=1;j<4;j++)
			cout << C[i][j]<<", ";
		cout <<endl;
	}*/
	
	int cost=0;
	for(int i=1;i<4;i++)
		for(int j=i+1;j<4;j++){
			int c = min(C[i][j],C[j][i]);
			cost += c;
			C[i][j] -= c;
			C[j][i] -= c;
		}
	
	for(int i=2;i<4;i++)
		cost += C[i][1] * 2;//two steps swap :)
	
	fout << cost <<endl;
	return 0;
}