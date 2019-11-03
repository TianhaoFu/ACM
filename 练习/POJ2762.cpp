#include<cstdio>
#include<string>
#define _ 60002
#define o 10002
//题目要求判定图中是否任意两点可过，即由i到j存在通路或由j到i存在通路
//这即是判定该图是否是弱连通图 
//有一种方式即为将图中的所有强连通分量进行缩点，然后判断新图是否连通
//一般判连通，若是无环图，则需图中的所有点都在一条链上
//这点可通过拓扑排序判断实现 ，如果某次删除点的时候发现两个入度为0的点，
//则说明这两个点只能由已经被删掉的点到达，
//也就是说这两个点互相不可达。 
//那么只需记录当前入度为0的个数，当多于1个时则不成立


//参考： 
//“如果是没有环的有向图的话，
//那么只有当所有的点都在一条链上的时候，图才是连通的。” 

//“得到强连通分支后重新建图的方法是，
//新建一个存储图的空间。
//用每个强连通分支的编号作为新图中结点的编号。
//判断原来的每条边的两端点是否属于同一强连通分支，
//若不属于则在新图中加入一条连接两个强连通分支编号对应结点的边。” 
using namespace std ;

void link( int , int  )  ;
void link2 (int  , int ) ;
void tarjan( int ) ;
bool judge () ;
void topsort(int ) ; 

int dfn[ o ] ;
int low[ o ] ;
int h[ 0 ] ;
int h2[ o ] ;
int id[ o ] ;
int od [ o ] ;
int stack[ o ] ;
int code [ o ] ;

int net[ _ ] ;
int g[ _ ] ;
int next2[ _ ] ;
int g2[ _ ] ;

int q , n , m  , t , t2 , top , cnt , index , sid ;
bool ins[ o ] ;
bool flag ;

int main()
{
	freopen( "2762.in" , "r"  ,stdin );
	freopen( "2762.out" , "w" , stdout) ;
	scanf("%d" , &q ) ;
	
	int aa , bb ;
	
	while(q--) 
	{
		memset( dfn , 0 , sizeof( dfn )) ;
		memeset( low , 0 , sizeof( low )) ;
		memset ( next , 0 , sizeof( next)) ;
		memset( h , 0 , sizeof( h )) ;
		memset( next2 , 0 , sizeof(next2)) ; 
		memset( id , 0 , sizeof( id)) ;
		memset( od , 0 , sizeof(od)) ;
		memset( code , 0 , sizeof( code )) ;
		
		t = 0 ; 
		t2 = 0 ;
		cnt = 0 ;
		scanf("%d%d" , &n , &m) ;
		
		for( int i = 1 ; i <= m ; i ++ )
		{
			scanf("%d%d" , &aa , &bb ) ;
			link( aa,  bb ) ; 
	    }

	    for( int i = 1 ; i <= n ;i ++ )
	    	if( !dfn[i])
	    		tarjan( i ) ;
	    
	    if ( judge( ) )
	    	printf("Yes\n") ;
	    else 
	    	printf("No\n") ;
	}
	
	return 0 ;
	
} 

void link( int aa , int bb )
{
	next[ ++t ] = h [aa] ;
	h[aa] = t ;
	g[ t ] = bb ;
}

void link2( int aa , int bb )
{
	next2 [ ++t2 ]  = h2[ aa ] ;
	h2 [ aa ] = t2 ; 
	g2[ t2 ] = bb ;
}

void tarjan( int i )
{
	int j ;
	
	dfn[i] = low[i] = ++index ;
	stack[ ++top ] = i ;
	ins[ i ] = true ;
	
	for( int k = h[ i ] ; k ; k = next[ k ])
	{
		j = g [ k ] ;
		
		if( !dfn[j])
		{
			tarjan( j ) ;
			if( low[ j ] < low[ i ])
				low[ i ] = low[ j ];
		}
		
		else if ( ins[ j ] && dfn[ j ] < low[ i ])
			low[ i ] = dfn[ j ];
	}
	
	if( low[ i ] == dfn[ i ])
	{
		cnt++ ;
		do
		{
			j = stack[ top-- ] ;
			code[ j ] = cnt ;
			ins[ j ] = false ;
		}
		
		while( i != j) ;
	}
}

bool judge( )
{
	int j ;
	
	flag = true ; 
	sid = 0;
	for( int i = 1 ; i<= n ;i ++ )
	{
		for( int k = h[ i ] ; k ; k = next [ k ])
		{
			j = [ k ] ;
			if( code[ i ] != code[ j ])
			{
				id[ code[ j ]]++ ;
				link2( code[ i ] , code[ j ]) ;
			}
		}
	}
	
	for( int i = 1 ; i <= cnt ; i++ )
		if( id[ i ] == 0)
			sid++ ;
			
	if( sid > 1) return 0 ;
	
	for( int i = 1 ; i <= cnt ; i++)
		if( id[ i ] == 0)
			topsort( i ) ;
	
	if( flag )
		return 1;  
		
	return  0 ;
}

void topsort( int i )
{
	int j ;
	sid-- ;
	id[ i ]  = -1 ;
	
	for( int k = h2[ i ] ; k ; k = next2[ k ])
	{
		j = g2[ k ] ;
		id[ j ]-- ;
		if( id[ j ] == 0)
			sid++ ;
	}
	
	if( sid > 1) 
		flag = false ;
		
	for( int k = h2[ i ] ; k ; k = next2[ k ])
	{
		j = g2[ k ] ;
		if( id[ j ] == 0)
			topsort( j );
	}
 } 
