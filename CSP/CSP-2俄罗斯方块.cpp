#include<bits/stdc++.h>
using namespace std ;
//关键是确定新加入板块的第一行应该停在初始方格图的第几行。
//定义二维数组A存储初始方格图，B存储新加入板块，
//num存储新加入板块左侧在初始方格图那一列。
//定义一个长度为10的数组Atemp记录初始方格图每一列方块所在的最小行数（行数从0开始编号，对应数组的行号），
//若没有方块，则置为15；
//定义一个长度为4的数组Btemp记录新加入板块每一列方块所在的最大行数（行数从0开始编号，对应数组的行号）。
//minRow记录新加入板块的第一行应该停在初始方格图的行数，///
//遍历Btemp，
//对于每一个不为-1的元素Btemp[i]（0<=i<4），
//更新minRow=min(minRow,Atemp[num+i-1]-Btemp[i]-1)，
//最后得到的minRow即为新加入板块的第一行应该停在初始方格图的行数
//然后将新加入板块从minRow行从上到下填充进初始方格图即可。
int main()
{
    int a[15][10] , atemp[10] ;
    int b[4][4],btemp = {-1,-1,-1,-1} ;

    fill(atemp , atemp+10 , 15) ;

    for(int i = 0  ; i<15 ; i ++ )
    {
        scanf("%d" , &a[i][j]) ;
        if(a[i][j] == 1 && atemp[j])
            atemp [j] = i ;
    }
    for( int i = 0 ; i < 4 ; i ++ )
    {
        for( int j = 0 ; j <4 ; j ++)
        {
            scanf("%d" , &b[i][j]);
            if(b[i])[j] == 1)
            {
                    btemp[j] = i ;
            }
        }

    }

    int num  , minRow = 15 ;
    scanf("%d" , &num ) ;
    for(int i = 0 ;i < 4 ; i++)
    {
        if(btemp[i] > -1)
            minRow = min(minRow , atemp[num + i - 1] - btemp[i] - 1) ;
    }
    for(int i = 0 ; i < 4 && i+minRow <15; i ++ )
    {
        for( int j = 0 ; j <4 ; j ++)
        {
            if( i +minRow >= 0 )
                a[i+minRow][num-1+j] = b[i][j] == 1? 1 : a[i+minRow][num-1+j] ;
        }
    }

    for( int  i= 0 ; i < 15 ; i ++ )
    {
        for( int  j= 0 ;j <10 ; j ++
            printf("%d" , a[i][j]) ;
        printf("\n");
    }

    return 0 ;
}
