#include<iostream>
using namespace std;
int main()
{
    int test,ss=0,flag=0;
    cout<<"enter number of test cases";
    cin>>test;
    while(test>0){
        int i,j,k,m,n,s=0,temp,g;
        cout<<"enter number of rooms and and number of paths";
        cin>>n>>m;
        int u[m],v[m],t[m];
        for(i=0;i<m;i++){
            cout<<"enter the two rooms which are connected and time taken to travel from one to another respectively";
            cin>>u[i]>>v[i]>>t[i];
        }
        temp=u[0];
        s=0;
        for(i=0;i<m-1;i++)
            {
                s=0;
                for(int l=0;l<m;l++){
                    if(u[l]!=-1||v[l]!=-1)
                    {
                        if(temp==u[l])
                        {
                            if(t[l]>s){
                            s=t[l];
                            g=l;
                            flag=1;
                            }
                        }
                        else if(temp==v[l])
                        {
                            if(t[l]>s){
                            s=t[l];
                             g=l;
                            flag=2;
                            }
                        }
                    }
                }
                //cout<<s<<endl;
                if(flag==1){
                ss+=s;
                u[g]=-1;
                temp=v[g];
                v[g]=-1;
                }
                else if(flag==2){
                    ss+=s;
                    v[g]=-1;
                temp=u[g];
                u[g]=-1;
                }
            }
            cout<<"maximum time that can be taken to travel is"<<ss;
            test-=1;
        }
    }
