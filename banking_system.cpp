#include<iostream>
#include<string.h>
using namespace std;
class bank
{
private:
    string name,mob,addr,email;
    float bal;
public:
    string accunt;
    void new1()
    {
        cin.ignore();
        cout<<"enter name";
        getline(cin,name);
        bal=0.0;
    }
    void show()
    {
        cout<<endl;
        cout<<"name is "<<name<<endl;
        cout<<"account number is "<<accunt<<endl;
        cout<<"address is "<<addr<<endl;
        cout<<"mobile number is "<<mob<<endl;
        cout<<"email is "<<email<<endl;
        cout<<"balance is "<<bal<<endl;
    }
    void withdraw(float n)
    {
        cout<<endl;
        bal=bal-n;
        cout<<"name is "<<name<<endl;
        cout<<"account number is "<<accunt<<endl;
        cout<<"address is "<<addr<<endl;
        cout<<"mobile number is "<<mob<<endl;
        cout<<"email is "<<email<<endl;
        cout<<"new balance is "<<bal<<endl;
    }
    void deposit(float n)
    {
        bal=bal+n;
        cout<<endl;
        cout<<"name is "<<name<<endl;
        cout<<"account number is "<<accunt<<endl;
        cout<<"address is "<<addr<<endl;
        cout<<"mobile number is "<<mob<<endl;
        cout<<"email is "<<email<<endl;
        cout<<"balance is "<<bal<<endl;
    }
    void bal1()
    {
        cout<<"balance is "<<bal<<endl;
    }
    string acunt()
    {
        return accunt;
    }
};
int main()
{
    bank ob[5];
    int ch,temp=0,i,temp1,temp2,k=1;
    string acc;
    float n;
    do
    {
        int temp1=0;
        cout<<endl;
        cout<<"enter 1 to open new account \n 2 to see all accounts \n 3 to see specific account \n 4 to withdraw \n 5 to deposit \n 6 to check balance \n 0 to exit";
        cin>>ch;
        switch(ch)
        {
        case 1:
            cin.ignore();
            cout<<"enter account number";
            do
            {
                getline(cin,ob[temp].accunt);
                for(i=0;i<temp;i++)
                {
                    if(ob[temp].accunt!=ob[i].acunt())
                    {
                        k=1;
                    }
                    else k=0;

                }
                if(k==1)
                {
                    ob[temp].new1();
                    temp++;
                }
                else
                {
                    cout<<"account number already exists.Enter new account number"<<endl;
                }
            }while(k!=1);

        break;
        case 2:
            for(i=0;i<temp;i++)
            {
                ob[i].show();
            }
            break;
        case 3:
            cout<<"enter account number";
            cin>>acc;
            for(i=0;i<temp;i++)
            {
                if(acc==ob[i].acunt())
                {
                    temp1=1;
                    temp2=i;
                }
            }
            if(temp1==1)
                ob[temp2].show();
            else
                cout<<"account does not exists";
                break;
        case 4:
            cout<<"enter account number";
            cin>>acc;
            cout<<"enter amount to be withdrawn";
            cin>>n;
            for(i=0;i<temp;i++)
            {
                if(acc==ob[i].acunt())
                {
                    temp1=1;
                    int temp2=i;
                }
            }
            if(temp1==1)
                ob[temp2].withdraw(n);
            else
                cout<<"account does not exists";
                break;
        case 5:
            cout<<"enter account number";
            cin>>acc;
            cout<<"enter amount to deposit";
            cin>>n;
            for(i=0;i<temp;i++)
            {
                if(acc==ob[i].acunt())
                {
                    temp1=1;
                    int temp2=i;
                }
            }
            if(temp1==1)
                ob[temp2].deposit(n);
            else
                cout<<"account does not exists";
                break;
        case 6:
            cout<<"enter account number";
            cin>>acc;
            for(i=0;i<temp;i++)
            {
                if(acc==ob[i].acunt())
                {
                    temp1=1;
                    int temp2=i;
                }
            }
            if(temp1==1)
                ob[temp2].bal1();
            else
                cout<<"account does not exists";
                break;
        default:
            cout<<"enter valid choice";
        }
        if(ch==0)
            break;
    }while(temp!=5);
    return 0;
}






