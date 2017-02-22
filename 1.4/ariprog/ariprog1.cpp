/*
ID: ahmed_f6
PROG: ariprog
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <map>
using namespace std;

struct Seq{
	int a;
	int b;
	int size;
};

int N,M;
set<int> sqrM;

bool findNext(set<int>::iterator it,int b,int v){

	int nextV = (*it)+b;
	while(it!=sqrM.end()){
		if((*it)>=nextV){
			if((*it)>nextV)
				return false;
			nextV += b;
			v--;
			if(v==0)
				return true;
		}
		it++;
	}
	return false;
}

int main() {
    ofstream fout ("ariprog.out");
    ifstream fin ("ariprog.in");
	
		
	fin >> N;
	fin >> M;
	
	for(int i=0;i<=M;i++)
		for(int j=i;j<=M;j++)
			sqrM.insert(i*i+j*j);
	
	vector<Seq> result;
	
	auto it1 = sqrM.begin();
	while(it1!=sqrM.end()){
		auto it2 = it1;
		it2++;
		int step=1;
		while(it2!=sqrM.end()){
			if(findNext(it2,(*it2)-(*it1),N-2))
				result.push_back({*it1,(*it2)-(*it1)});
			it2++;
		}
		it1++;
	}
	
	

	for(auto it:result)
		fout << it.a <<" " << it.b <<endl;
	
	return 0;
}