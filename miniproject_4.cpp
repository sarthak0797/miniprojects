#include<iostream>
#include<cstdlib>
using namespace std;
int a[100][100],n,flag=0,flag1=0;
// TO INPUT THE ARRAY
void input()
{
    int i,j;
    cout<<("enter the size of matrix : \n");
    cin>>n;
    if(n>100)
    {
        cout<<"INVALID INPUT!\n";
        exit(0);
    }

     cout<<"enter the square matrix \n";
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>a[i][j];
            if(a[i][j]<0||a[i][j]>2)
            {
                cout<<"INVALID INPUT";
                exit(0);
            }
        }
    }
}
// TO CHECK IF THERE IS A PATH OF 1'S FROM 1ST ROW TILL nTH ROW
int row_check()
{
    int i,j,n;
    for(i=0;i<n;i++){
        if(a[0][i]==1){
            flag++;
            break;
        }
    }
    for(i=1;i<n;i++){
            for(j=0;j<n;j++){
                if(a[i][j]==1)
                {

                    if(a[i-1][j-1]==1){
                        if(a[i][j+1]==1||a[i+1][j-1]==1||a[i+1][j]==1||a[i+1][j+1]==1){
                            flag++;
                            break;
                        }
                    }
                    if(a[i-1][j]==1){
                        if(a[i][j+1]==1||a[i+1][j-1]==1||a[i+1][j]==1||a[i+1][j+1]==1){
                            flag++;
                            break;
                        }
                    }
                    if(a[i-1][j+1]==1){
                        if(a[i][j+1]==1||a[i+1][j-1]==1||a[i+1][j]==1||a[i+1][j+1]==1){
                            flag++;
                            break;
                        }
                    }
                }

            }
    }
    for(i=0;i<n;i++)
    {
        if(a[n-1][i]==1)
            flag++;
    }


    for(j=0;j<n;j++){
        if(a[j][0]==2){
            flag1++;
            break;
        }
    }
    return flag;
}
// TO CHECK IF THERE IS A PATH OF 2'S FROM 1ST COLUMN TILL nTH COLUMN
int column_check()
{
    int i,j,n;
    for(i=1;i<n;i++){
            for(j=0;j<n;j++){
                if(a[j][i]==2)
                {
                    if(a[i-1][j-1]==2){
                        if(a[i+1][j]==2||a[i+1][j+1]==2||a[i][j+1]==2||a[i-1][j+1]==2){
                            flag1++;
                            break;
                        }
                    }
                    if(a[i][j-1]==2){
                        if(a[i+1][j]==2||a[i+1][j+1]==2||a[i][j+1]==2||a[i-1][j+1]==2){
                            flag1++;
                            break;
                        }
                    }
                    if(a[i+1][j-1]==2){
                        if(a[i+1][j]==2||a[i+1][j+1]==2||a[i][j+1]==2||a[i-1][j+1]==2){
                            flag1++;
                            break;
                        }
                    }
                }

            }
    }
    for(i=0;i<n;i++)
    {
        if(a[i][n-1]==2)
            flag1++;
    }
    return flag1;
}
int main()
{
    input();
    row_check();
    column_check();
    if(flag==n&&flag1==n)
        cout<<"AMBIGIOUS";
    else if(flag==n)
        cout<<"1";
    else if(flag1==n)
        cout<<"2";
    else
        cout<<"0";
    return 0;
}
