/*
ID: ahmed_f6
PROG: palsquare
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int reverse(int n,int base){
	int ret=0;
	while(n>0){
		ret *= base;
		ret += (n%base);
		n = n /base;
	}
	return ret;
}

bool palindrome(int n,int base){
	return ( n == reverse(n,base));
}


string print(int n,int base){
	string str;
	const char* charlist="0123456789ABCDEFGHIJKLMNOPQRSTUVXYZ";
	while(n>0){
		str = charlist[n%base] + str;
		n = n / base;
	}
	return str;
}

int main() {
    ofstream fout ("palsquare.out");
    ifstream fin ("palsquare.in");
    
	int max=300;
	int base;
	fin >> base;
	
	for(int i=1;i<=max;i++){
		if(palindrome(i*i,base))
			fout<<print(i,base)<<" "<<print(i*i,base)<<endl;
	}
	
    return 0;
}