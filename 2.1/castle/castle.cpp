/*
ID: ahmed_f6
PROG: castle
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

int N,M;
int P[50*50+1];

#define MAP(x,y) ((x)+M*(y))
#define lout  if(0) cout

int root(int i){
	
	int r = i;
	while(P[r] > -1)
		r = P[r];
	
	int s;
	while(i!=r){
		s = P[i];
		P[i]=r;
		i = s;
	}
	return r;
}

void join(int i,int j){
	
	lout << i << "," << j << endl;
	i = root(i);
	j = root(j);
	
	if(i == j)
		return;
	
	int s = P[i] + P[j];
	if(P[i] < P[j]){
		P[j] = i;
		P[i] = s;
	}
	else{
		P[i] = j;
		P[j] = s;
	}
	
	lout << i << "," << j; 
	for(int b=0;b<M*N;b++){
		if(b%M==0)
			lout<<endl;
		lout << P[b] << " ";
	}
	lout <<endl;

}

void decode(int x,int y,int c){
	
	if((c & 0x08)==0 && (y < N-1)){
		lout<<"join south "<< c <<endl;
		join(MAP(x,y),MAP(x,y+1));
	}
	
	if((c & 0x04)==0 && (x < M-1)){
		lout<<"join east "<< c <<endl;
		join(MAP(x,y),MAP(x+1,y));
	}
}

int tryJoin(int i,int j){
	i = root(i);
	j = root(j);
	
	if(i == j)
		return -1;
	
	return -(P[i] + P[j]);
}

int main() {
    ofstream fout ("castle.out");
    ifstream fin ("castle.in");

	fin >> M >> N;
	for(int b=0;b<M*N;b++)
		P[b] = -1;
	
	int c;
	for(int y=0;y < N;y++)
		for(int x=0;x < M;x++){
			fin >> c;
			decode(x,y,c);
		}
	
	int max=0;
	int nroom=0;
	for(int b=0;b<M*N;b++){
		if(P[b] < max)
			max = P[b];
		if(P[b] < 0)
			nroom++;
	}
	
	fout << nroom << endl;
	fout << (-max) << endl;
	
	int maxMerge=-1;
	int wX,wY;
	char wD;
	
	for(int x=0;x<M;x++)
		for(int y=N-1;y>=0;y--){
			int m;
			
			if(y> 0){
				m = tryJoin(MAP(x,y),MAP(x,y-1));
				lout << "test (x , y) " << x << " , " <<y <<" = " << m <<endl;
				if( m > maxMerge){
					maxMerge = m; wX = x; wY = y; wD = 'N';
				}
			}
			
			if(x < M-1){
				m = tryJoin(MAP(x,y),MAP(x+1,y));
				lout << "test (x , y) " << x << " , " <<y <<" = " << m <<endl;
				if(m > maxMerge){
					maxMerge = m; wX = x; wY = y; wD = 'E';
				}
			}
		}
		
	fout << maxMerge << endl;
	fout << (wY+1) << " " << (wX+1) << " " << wD << endl;
	
	return 0;
}