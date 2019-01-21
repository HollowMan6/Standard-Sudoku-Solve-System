#include<stdio.h>
#include<string.h>
int q[10][10],row[10][10],column[10][10],cell[10][10];
void print()                                            //输出函数
{
    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=9;j++)
            printf("%d ",q[i][j]);
        printf("\n");
    }
}
void dfs(int x,int y)                                   //深度优先搜索
{
    if(q[x][y]!=0)                                      //数独中不为零的数直接跳过
    {
        if(x==9&&y==9)                                  //搜索结束后输出
            print();
        if(y==9)                                        //行到顶端后搜索列
            dfs(x+1,1); 
        else                                            //搜索行
            dfs(x,y+1);
    }
    else                                                //等于零时
    {
        for(int i=1;i<=9;i++)
        { 
            if(row[x][i]&&column[y][i]&&cell[(x-1)/3*3+(y-1)/3+1][i])
            {
                q[x][y]=i;
                row[x][i]=0;                            //此格被占 (行)
                column[y][i]=0;                         //此格被占 (列)
                cell[(x-1)/3*3+(y-1)/3+1][i]=0;         //此格被占 (格)
                if(x==9&&y==9)                          //搜索结束后输出
                    print();
                if(y==9)                                //行到顶端后搜索列
                    dfs(x+1,1); 
                else                                    //搜索行
                    dfs(x,y+1);
                q[x][y]=0;                              //当前格退出 
                row[x][i]=1;
                column[y][i]=1;
                cell[(x-1)/3*3+(y-1)/3+1][i]=1;
            }
        } 
    }
}
int main(void)
{
    puts("标准数独(Sudoku)(9*9)解题系统      ***Powered By Hollow Man***");
    puts("");
    puts("              Standard Sudoku Solve System(SSSS)");
    puts("****************************************************************");
    puts("");
    puts("输入格式如下所示(要填数字的地方用0表示)：");
    puts("");
    puts("The input format is as follows(replace the space where you have to input numbers with 0.):");
    puts("");
    for(int i=0;i<9;i++)
        puts("X X X X X X X X X");
    puts("");
    puts("请输入待解决的数独：");
    puts("");
    puts("Please input the sudoku to be solved:");
    puts("");
    memset(row,1,sizeof(row));
    memset(column,1,sizeof(column));
    memset(cell,1,sizeof(cell));
    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=9;j++)
        {
            scanf("%d",&q[i][j]);
            if(q[i][j]>0)
            {
                row[i][q[i][j]]=0;                      //表示格子上有数
                column[j][q[i][j]]=0;                   //表示格子上有数
                cell[(i-1)/3*3+(j-1)/3+1][q[i][j]]=0;   //表示格子上有数
            }
        }
    } 
    puts("");
    puts("答案如下：");
    puts("");
    puts("The solution is here:");
    puts("");
    dfs(1,1);                                           //从(1,1)格开始搜索
    puts("");
    system("pause");
    return 0;
}