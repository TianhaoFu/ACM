#include<cstdio>
#include<vector>
#include<algorithm>
//希望最小生成树中的最大权值的边权是所有生成树中最小的边权
//最小生成树权值列表是最小的，若有更小的边（最大边往前移）
//为了满足总边权最小的性质则必有边往后移，此时最大的边就变了 
//因此此题求出最小生成树即可 

//1.POJ 2395 Out of Hay
//好像是叫最小瓶颈生成树，要求生成树中的最大边最小。
//其实最小生成树的最大边就是要求的值。
//用反证法，首先假设最小生成树为T1,最大边为E1,另外一棵最大边更小的生成树为T2，最大边为E2。
//如果E2 < E1，则T2中所有的边权值均小于E1，E1在T1中连接两个连通分量A,B，在T2中一定有连接A,B两个连通分量的边（否则整个树就不联通了），这些边都小于E1，用他们替换E1，则T1的总权值更小，与 T1是最小生成树矛盾。
//因此最小生成树的最大边的权值就是所有生成树最大边权值的最小值。
//（听说最小生成树第K小的边是所有生成树第 K小的边中最小的，不知道怎么证明）

using namespace std ; 
struct Edge{
	int from ; 
	int to ; 
	int distance ;
};

int father[50005] ; 

bool  cmp(Edge e1 ,  Edge e2){
	return e1.distance < e2.distance ; 
}

int result = 0   ;

int main()
{
	void init(int number) ; 
	void unio(int from , int to , int distance) ;
	int vertextNumber , edgeNumber , root ;
	scanf("%d%d%d" , &vertextNumber , &edgeNumber , &root) ;
	vector<Edge> vec ;
	Edge temp ; 
	int from , to , distance ; 
	
	for (int i = 0 ; i < edgeNumber ; i ++ )
	{
		scanf("%d%d%d",&from , &to , &distance)  ;
		temp.from = from ; 
		temp.to = to ;
		temp.distance = distance ;
		vec.push_back(temp) ;
	 } 
	
	sort(vec.begin() , vec.end() , cmp) ; 
	init(veretxtNumber) ; 
	for(  int i = 0 ; i < vec.size() ; i ++) 
	 {
	 	temp = vec[i] ; 
	 	from = temp.from ; 
	 	to = temp.to ;
	 	distance = temp.distance ; 
	 	unio(from , to , distance) ;
	 }
	 
	printf("%d\n" , result) ;
	
	 return 0 ;
}

void init(int number)
{
	for( int i = 0 ;i <= numbre ; i ++ )
	{
		father[i] = i;
	}
}

int findFather(int x){
	int a = x ;
	while(x != father[x])
	{
		x = father[x] ; 
	}
	
	while(a != father[a])
	{
		int z = father[a] ;
		
		father[a] = x ;
		a = z ;
	}
	
	return x  ;
	
}

void unio ( int from , int to , itn distance)
{
	int fx = findFather(from ) ; 
	int fy = findFather(to ) ;
	if( fx != fy) 
	{
		fahter[fx]  =fy  ;
		result = distance ;
	 } 
}
