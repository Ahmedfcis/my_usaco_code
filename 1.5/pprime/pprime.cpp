/*
ID: ahmed_f6
PROG: pprime
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;


bool prime(long n){
	for(long i=2;i*i<=n;i++)
		if(n%i == 0)
			return false;
	return true;
}

long D[20]={0};
long Tens[15];
#define pow10(n)	Tens[n]
void setup(){
	Tens[0]=1;
	for(int i=1;i<15;i++)
		Tens[i] = Tens[i-1]*10;
}

void startP(int n){
	for(int i=0;i<20;i++)
		D[i]=0;
	D[(n+1)/2-1]=1;
}

long nextP(int n){
	long l=0,h=0;
	int r= (n+1)/2;
	if(D[r]>0)
		return -1;
	
	if(n%2)
		l = D[0];
	
	int j= n/2+(n%2);
	for(int i = (n%2);i<r;i++){	
		l *= 10;
		l += D[i];
		h += D[i]*pow10(j++);
	}

	//next
	D[0]++;
	for(int i=0;i<=r;i++){
		D[i+1] += D[i]/10;
		D[i] = D[i] % 10;
	}
	if(D[r-1]%2==0)
		D[r-1]++;

	return l+h;
}

int main() {
    ofstream fout ("pprime.out");
    ifstream fin ("pprime.in");

	setup();
	
	long A,B;
	fin >> A >> B;
	
	int d=1;
	while(pow10(d)<A)
		d++;
	
	long v;
	
	while(1){
		startP(d);
		v = nextP(d);
		while(v!=-1){
			if(v > B)
				return 0;
			if(v >= A && prime(v))
				fout << v << endl;
			v = nextP(d);
		}
		d++;
	}
	return 0;
}