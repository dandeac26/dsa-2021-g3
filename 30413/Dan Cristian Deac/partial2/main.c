#include <stdio.h>
#include <stdlib.h>

int n,m,solutions = 1;

int dx[]={0,1,1},
    dy[]={1,0,1};

int mat[100][100];

int posibil(int x, int y)
{
    return (x>=0 && x<n && y>=0 && y<m );
}

void back(int x,int y,int pas)
{
    for(int k=0;k<3;k++)
    {

        int X = x + dx[k];
        int Y = y + dy[k];

        if(posibil(X,Y))
            back(X,Y,pas+1);

        else
        {
            mat[X][Y] = 0;
            if(X == n-1 && Y == m-1)
                solutions++;
        }


    }
}



int main()
{

    scanf("%d", &n);
    scanf("%d", &m);
    back(0, 0, 1);

    printf("%d", solutions);
    return 0;
}
