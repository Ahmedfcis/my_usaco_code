/*
ID: ahmed_f6
PROG: sprime
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

bool prime(long n){
	if(n==1)
		return false;
	for(long i=2;i*i<=n;i++)
		if(n%i == 0)
			return false;
	return true;
}

void allSprime(ofstream& fout,int b,int N){
	
	for(int i=1;i<10;i++)
		if(prime(b+i)){
			if(N>1)
				allSprime(fout,(b+i)*10,N-1);
			else
				fout << (b+i)<<endl;
		}

}

int main() {
    ofstream fout ("sprime.out");
    ifstream fin ("sprime.in");

	int N;
	fin >> N;
	
	allSprime(fout,0,N);
	return 0;
}