/*
ID: ahmed_f8
TASK: ariprog
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

struct seq
{
	int n1;
	int n2;
};

bool a[126000]={0};
int b[40000]={0};
vector<seq> S;
int N=0, M=0;


bool check(int n, int m)
{
	for (int i=0; i<N; i++)
		if (n+i*m>M*M*2 || a[n+i*m]==false)
			return false;

	return true;
}

int main(void)
{
	freopen("ariprog.in", "r", stdin);
	freopen("ariprog.out", "w", stdout);

	cin >> N >> M;

	for (int i=0;i<=M;i++)
		for (int j=i;j<=M;j++)
			if (a[i*i+j*j]==false)
				a[i*i+j*j]=true;

	int maxNum=M*M*2;

	int leng=0;
	for (int i=0;i<=maxNum;i++)
		if (a[i]==true)
		{
			b[leng]=i;
			leng++;
		}

	int largestDiff=0;
	for (int i=0;i<leng-N;i++)
	{

		int n=b[i];
		int m;
		for (int j=i+1; j<leng-N+2;j++)
		{
			m=b[j]-n;
			if (check(n,m))
			{
				seq temp;
				temp.n1=n;
				temp.n2=m;
				if (m>largestDiff) largestDiff=m;
				S.push_back(temp);
			}
		}
	}

	if (S.size()==0)
	{
		cout << "NONE" << endl;
		return 0;
	}

	for (int i=1;i<=largestDiff;i++)
		for (size_t j=0;j<S.size();j++)
			if (S[j].n2==i)
			{
				cout << S[j].n1 << " " << S[j].n2 << endl;
				S.erase(S.begin()+j);
				j--;
			}

	return 0;
}
