#include<stdio.h>
#include<conio.h>
int lucky(int);//to check whether the number is lucky or not
int sop(int);//to calculate the sum of digits of the number
int diff(int);//to calculate the maximum difference between two consecutive digits
void output(int,int);//to print sum and difference of number
float prime(int,int);//to check no. of prime numbers in the given range
float prob(float,float);//to check the probability of a number
void output1(float);//to print the probability
int main(int argc,char *argv[])
{
    FILE *fp;
    int ch,n,m,pr,k,temp,temp1=0,sum,tc,max,test,i;
    float d,pp;char ch1;
    printf("enter 1 for lucky,2 for probability");
    scanf("%d",&ch);//to input the choice from user
    switch(ch)
    {
    case 1:fp=fopen(argv[1],"r");
    ch1=fgetc(fp);
    fclose(fp);
    if(ch1==EOF)//to check if the text file is empty or not
    {
    printf("empty file");
    }
    else
    {
        fp=fopen(argv[1],"r");
        fscanf(fp,"%d",&tc);
        while(ch1!=EOF)//to calculate number of inputs in the given file
        {
            ch1=fgetc(fp);
            if(ch1=='\n')
                temp1++;
        }
        fclose(fp);
        if(tc!=temp1)//to check if number of inputs is equal to test cases given
        {
            printf("INVALID TEST CASES");
        }
        else
        {
         fp=freopen(argv[1],"r",stdin);
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d",&n);
        temp=lucky(n);
        if(temp==1)
        {
            sum=sop(n);
            max=diff(n);
            output(sum,max);
        }
        else
        {
            printf("not lucky\n");
        }
    }

    fclose(fp);
}
    }
    break;
    case 2:fp=fopen(argv[2],"r");
    ch1=fgetc(fp);
    fclose(fp);
    if(ch1==EOF)//to check if file is empty or not
    {
    printf("empty file");
    }
    else
    {
        fp=fopen(argv[2],"r");
        fscanf(fp,"%d",&tc);
        ch1=fgetc(fp);
        while(ch1!=EOF)//to calculate number of inputs
        {
            ch1=fgetc(fp);
            if(ch1=='\n')
                temp1++;
        }
        temp1++;
        fclose(fp);
        if(tc!=temp1)//to check if number of inputs is equal to test cases
        {
            printf("INVALID TEST CASES");
        }
        else
        {
        fp=freopen(argv[2],"r",stdin);
        scanf("%d",&test);
        for(i=0;i<test;i++)
        {
        scanf("%d%d",&n,&m);
        if(n<=m)
        {
        pr=prime(n,m);
        d=m-n+1;
        pp=prob(pr,d);
        output1(pp);
        }
        else
        {
        printf("invalid input\n");
        }
        }
    fclose(fp);
        }
    break;
    default:
    printf("wrong choice");
    }
    return 0;
    }
}
int lucky(int m)
{
    int t=1,k,k1;
    while(m>0)
    {
    k=m%10;
    m=m/10;
    k1=m%10;
    if(k<k1)
    t++;
    }
    return(t);
}
int sop(int m)
{
    int s=0,k;
    while(m>0)
    {
    k=m%10;
    s=s+k;
    m=m/10;
    }
    return(s);
}
int diff(int m)
{
    int d=0,d1,k,k1;
    while(m>10)
    {
    k=m%10;
    m=m/10;
    k1=m%10;
    d1=k-k1;
    if(d1>d)
    d=d1;
    }
    return(d);
}
void output(int s,int d)
{
    printf("%d,%d\n",d,s);
}
float prime(int n,int m)
{
    int i,p,j,temp;
    float k=0;
    for(i=n;i<=m;i++)
    {
        temp=0;
        for(j=2;j<=i;j++)
        {
            if(i%j==0)
            {
                temp++;
            }
        }
        if(temp==1)
        {
            k++;
        }
    }
    return(k);
}
float prob(float pr,float m)
{
    float p=pr/m;
    return(p);
}
void output1(float pr)
{
    printf("%f\n",pr);
}
