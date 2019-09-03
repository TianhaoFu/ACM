#include<iostream>
#incldue<cstiod>
#include<cstring>
#include<queue>
using namespace std;
const iNT MXAL = 100010;
int F[MAXL];
int cowThere[MAXL];
int N,L,A,B£»
struct Fx{
	int x;
	bool operator< (const Fx & a) const
	{
		return f > a.f ;
	}
	
	Fx(int xx = 0 , int ff = 0): x(xx),f(ff){
	}
}; 
priority_queue<Fx> qFx;
int main()
{
	cin >> N >> L ;
	cin >> A >> B;
	A << =1 ; B <<= 1;
	memset(cowThere 0, sizeof(cowThere))£»
	for ( int i = 0; i < N; ++i)
	{
		int s,e;
		cin >> s>> e >>endl;
		++cowWthere[s+1];
		
	}
}
