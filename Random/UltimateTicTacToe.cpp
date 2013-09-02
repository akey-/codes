/* HackerRank ULTIMATE TIC-TAC-TOE implementation
   Written By : Akey-
*/

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

char utt[3][3][3][3],tic[10][10],ch[20],player;
int fx,fy;

int isFull(int ix,int iy)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(utt[ix][i][iy][j]=='-')
                return 0;
        }
    }
    return 1;
}


int move_at_any_position(int ix,int iy)
{
    int flag=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(!flag)
            {
                if(utt[ix][i][iy][j]=='-')
                {
                    utt[ix][i][iy][j]=player;
                    fx=i;
                    fy=j;flag=1;
                    return 1;
                }

            }
        }
    }
    return 0;
}

int check_square(int ix,int iy)
{

    if(utt[ix][0][iy][0]== 'X' && utt[ix][1][iy][1] == 'X' && utt[ix][2][iy][2]== 'X')
        return 1;
    if(utt[ix][0][iy][2]== 'X'  && utt[ix][1][iy][1]== 'X' && utt[ix][2][iy][0]== 'X' )
        return 1;

    if(utt[ix][0][iy][0]== 'O' && utt[ix][1][iy][1] == 'O' && utt[ix][2][iy][2]== 'O')
        return 1;
    if(utt[ix][0][iy][2]== 'O'  && utt[ix][1][iy][1]== 'O' && utt[ix][2][iy][0]== 'O')
        return 1;

    for(int i=0;i<3;i++)
    {
        if((utt[ix][i][iy][0]=='X'))
        if((utt[ix][i][iy][0]==utt[ix][i][iy][1]) && (utt[ix][i][iy][1]==utt[ix][i][iy][2]))
            return 1;

        if((utt[ix][i][iy][0]=='O'))
        if((utt[ix][i][iy][0]==utt[ix][i][iy][1]) && (utt[ix][i][iy][1]==utt[ix][i][iy][2]))
            return 1;
    }

    for(int j=0;j<3;j++)
    {
        if((utt[ix][0][iy][j]=='X'))
        if((utt[ix][0][iy][j]==utt[ix][1][iy][j]) && (utt[ix][1][iy][j]==utt[ix][2][iy][j]))
            return 1;

        if((utt[ix][0][iy][j]=='O'))
        if((utt[ix][0][iy][j]==utt[ix][1][iy][j]) && (utt[ix][1][iy][j]==utt[ix][2][iy][j]))
            return 1;
    }

    if(isFull(ix,iy))
        return 1;

    return 0;
}

void move_here(int ix,int iy)
{
    int flag=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(!flag)
            {
                if(utt[ix][i][iy][j]=='-')
                {
                    utt[ix][i][iy][j]=player;

                    fx=i;
                    fy=j;flag=1;
                    return;
                }

            }
        }
    }
}

void correct_move(int ix,int iy)
{
    for(int i=0;i<3;i++)
    {
        if( (utt[ix][i][iy][0]==utt[ix][i][iy][1])  && (utt[ix][i][iy][0]!='-'))
        {
            if(utt[ix][i][iy][2]=='-')
            {
               utt[ix][i][iy][2]=player;
               fx=i;fy=2;
               return;
            }
        }

        if( (utt[ix][i][iy][1]==utt[ix][i][iy][2])  && (utt[ix][i][iy][1]!='-'))
        {
            if(utt[ix][i][iy][0]=='-')
            {
               utt[ix][i][iy][0]=player;
               fx=i;fy=0;
               return;
            }
        }
    }

    for(int j=0;j<3;j++)
    {
        if( (utt[ix][0][iy][j]==utt[ix][1][iy][j] ) && (utt[ix][0][iy][j]!='-'))
        {
            if(utt[ix][2][iy][j]=='-')
            {
               utt[ix][2][iy][j]=player;
               fx=2;fy=j;
               return;
            }
        }

        if( (utt[ix][1][iy][j]==utt[ix][2][iy][j])  && (utt[ix][1][iy][j]!='-'))
        {
            if(utt[ix][0][iy][j]=='-')
            {
               utt[ix][0][iy][j]=player;
               fx=0;fy=j;
               return;
            }
        }
    }

    for(int i=0;i<3;i++)
    {
        if( (utt[ix][i][iy][0]==utt[ix][i][iy][2]) && (utt[ix][i][iy][0]!='-'))
        {
            if(utt[ix][i][iy][1]=='-')
            {
               utt[ix][i][iy][1]=player;
               fx=i;fy=1;
               return;
            }
        }
    }

    for(int j=0;j<3;j++)
    {
        if( (utt[ix][0][iy][j]==utt[ix][2][iy][j])  && (utt[ix][0][iy][j]!='-'))
        {
            if(utt[ix][1][iy][j]=='-')
            {
               utt[ix][1][iy][j]=player;
               fx=1;fy=j;
               return;
            }
        }
    }

    if((utt[ix][0][iy][0]==utt[ix][1][iy][1]) && (utt[ix][0][iy][0]!='-'))
    {
        if(utt[ix][2][iy][2]=='-')
        {
            utt[ix][2][iy][2]=player;
            fx=2;fy=2;
            return;
        }
    }

    if((utt[ix][0][iy][0]==utt[ix][2][iy][2]) && (utt[ix][0][iy][0]!='-'))
    {
        if(utt[ix][1][iy][1]=='-')
        {
            utt[ix][1][iy][1]=player;
            fx=1;fy=1;
            return;
        }
    }

    if((utt[ix][1][iy][1]==utt[ix][2][iy][2]) && (utt[ix][1][iy][1]!='-'))
    {
        if(utt[ix][0][iy][0]=='-')
        {
            utt[ix][0][iy][0]=player;
            fx=0;fy=0;
            return;
        }
    }


    if((utt[ix][0][iy][2]==utt[ix][1][iy][1]) && (utt[ix][0][iy][2]!='-'))
    {
        if(utt[ix][2][iy][0]=='-')
        {
            utt[ix][2][iy][0]=player;
            fx=2;fy=0;
            return;
        }
    }

    if((utt[ix][0][iy][2]==utt[ix][2][iy][0]) && (utt[ix][0][iy][2]!='-'))
    {
        if(utt[ix][1][iy][1]=='-')
        {
            utt[ix][1][iy][1]=player;
            fx=1;fy=1;
            return;
        }
    }

    if((utt[ix][1][iy][1]==utt[ix][2][iy][0]) && (utt[ix][1][iy][1]!='-'))
    {
        if(utt[ix][0][iy][2]=='-')
        {
            utt[ix][0][iy][2]=player;
            fx=0;fy=2;
            return;
        }
    }


    if(utt[ix][ix][iy][iy]=='-')
    {
        utt[ix][ix][iy][iy]=player;
        fx=ix;fy=iy;
        return;
    }
    else
    {
         move_here(ix,iy);
    }
}

int main()
{
    scanf("%c",&player);
    int ix,iy;
    scanf("%d%d",&ix,&iy);
    for(int i=0;i<9;i++)
    {
        scanf("%s",ch);
        for(int j=0;j<9;j++)
            tic[i][j]=ch[j];
    }

    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            int x=i/3;
            int z=j/3;
            utt[x][i%3][z][j%3]=tic[i][j];
        }
    }

    int flag=0;

    if(ix==-1 || iy==-1)
    {
        ix=0;iy=0;
        int f=0;
        int count=0;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                count++;
                if(!f)
                {
                    int ans=check_square(i,j);
                    if(!ans)
                    {
                        f=1;ix=i;iy=j;
                        break;
                    }
                }
            }
        }
        
        
        if(count>=9)
        {
            int ans;
            for(int i=0;i<3;i++)
            {
                for(int j=0;j<3;j++)
                {
                    ans=move_at_any_position(i,j);
                    if(ans)
                    {
                      ix=i;iy=j;
                      break;
                    }

                  } 
                  if(ans) break;
              }
          }
          else
          {
              correct_move(ix,iy);
          }
    }

    else
    {
        if(check_square(ix,iy)==0)
        {
            correct_move(ix,iy);
        }
        else
        {
            int f=0;
            for(int i=0;i<3;i++)
            {
                for(int j=0;j<3;j++)
                {
                    if(!f)
                    {
                        int ans=check_square(i,j);
                        if(!ans)
                        {
                            f=1;ix=i;iy=j;
                            break;
                        }
                    }
                }
                correct_move(ix,iy);
            }
        }
    }


    printf("%d %d %d %d\n",ix,iy,fx,fy);
    return 0;
}


