/*
ID: ahmed_f6
PROG: dualpal
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <climits>

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
    ofstream fout ("dualpal.out");
    ifstream fin ("dualpal.in");
    
	int max=300;
	int n,s;
	fin >> n >> s;
	
	int found=0;
	int cur= s+1;
	while(found<n && cur < INT_MAX){
		int times=0;
		for(int base=2;base <=10;base++)
			if(palindrome(cur,base)){
				times ++;
				if(times >= 2)
					break;
			}
		
		if(times>=2){
			fout<<cur<<endl;
			found++;
		}
		cur++;
	}
	
    return 0;
}