#include<bits/stdc++.h>
using namespace  std ;
int main(0)
{
    int a[20] ;
    for (int i = 0 ; i <20;i++)
    {
        a[i] =  5;
    }

    int n ;
    scanf("%d" , &n) ;

    while(n--)
    {
        int  k ;
        scanf("%d"  ,& k) ;
        int  i = 0 ;


        while(i < 20 && a[i] < k )
        {
            ++ i ;
        }

        if(i < 20)
        {
            int start = i *5 + 6 - a[i]l;
            for(int  j= 0  ; j <k ; j ++ )
                {
                    printf("%d" , start + j) ;
                }
            printf("\n") ;
            a[i] -= k ;
        }

        else
        {
            for( int j = 0 ; j <20 && k >0  ; j++)
            {
                if(a[j] > 0 )
                {
                    int start = j * 5 +6 -a[j] ;
                    for( int m = 0 ; m <min(a[j],k) ; ++m)
                        printf("%d" , start +m) ;
                    k-= a[j] ;
                    a[j] =k >a[j] ? 0 :a[j] - k ;
                }
            }
            printf("\n");
        }
    }
    return 0 ;
}
