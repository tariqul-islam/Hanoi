/**************
HANOI.CPP

Contains inplementation detail for the class
defined in hanoi.h

Written By:
Mohammad Tariqul Islam
ponir . bd @ hotmail . com
10/2/2011
**************/


#include<iostream>
#include "hanoi.h"

using namespace std;



hanoi::hanoi(int size)
{
    while(size<1 || size>64)
    {
        size=5;
    }
    a=size;
    A = new int [a+1];
    B = new int [a+1];
    C = new int [a+1];

    A[0]=B[0]=C[0]=0;
    for(int i=1; i<=a; i++)
    {
        A[i]=i;
        B[i]=C[i]=0;
    }
    p=0; q=a; r=a;
}

hanoi::hanoi(const hanoi &source)
{
    a=source.a;
    A = new int [a+1];
    B = new int [a+1];
    C = new int [a+1];

    for(int i=0; i<=a; i++)
    {
        A[i]=source.A[i];
        B[i]=source.B[i];
        C[i]=source.C[i];
    }
    p=source.p;
    q=source.q;
    r=source.r;
}

hanoi::~hanoi()
{
    delete[] A;
    delete[] B;
    delete[] C;
}

int hanoi::recons(int size)
{
    delete[] A;
    delete[] B;
    delete[] C;

    while(size<1 || size>64)
    {
        size=5;
    }

    a=size;
    A = new int [a+1];
    B = new int [a+1];
    C = new int [a+1];

    A[0]=B[0]=C[0]=0;
    for(int i=1; i<=a; i++)
    {
        A[i]=i;
        B[i]=C[i]=0;
    }
    p=0; q=a; r=a;


}

void hanoi::print()
{
    cout<<endl;
    for(int i=1; i<=a; i++)
    {
        if(A[i]==0) cout<<"  |\t";
            else if(A[i]<=9) cout<<" "<<A[i]<<"|\t";
            else cout<<A[i]<<"|\t";
        if(B[i]==0) cout<<"  |\t";
            else if(B[i]<=9) cout<<" "<<B[i]<<"|\t";
            else cout<<B[i]<<"|\t";
        if(C[i]==0) cout<<"  |"<<endl;
            else if(C[i]<=9) cout<<" "<<C[i]<<"|"<<endl;
            else cout<<C[i]<<"|"<<endl;
    }
    cout<<"________________________________________"<<endl;
    cout<<" A\t B\t C"<<endl<<endl;
}

int hanoi::check()
{
    int flag=0;
    for(int i=1; i<a; i++)
    {
        if(A[i]!=0 || A[i+1]!=0)
        {
            if(A[i]>A[i+1])
            {
                flag=-1;
            }
        }

        if(B[i]!=0 || B[i+1]!=0)
        {
            if(B[i]>B[i+1])
            {
                flag=-1;
            }
        }

        if(C[i]!=0 || C[i+1]!=0)
        {
            if(C[i]>C[i+1])
            {
                flag=-1;
            }
        }
    }

    return flag;
}

int hanoi::move(int srce, int dest)
{
    int *S, *D, *m, *n;
    char ch1, ch2;

    if(srce==1)    { S=A; m=&p; ch1='A';}
    else if(srce==2)    { S=B; m=&q; ch1='B';}
    else if(srce==3)    { S=C; m=&r; ch1='C';}
    else    return -1;

    if(dest==1)    { D=A; n=&p; ch2='A';}
    else if(dest==2)    { D=B; n=&q; ch2='B';}
    else if(dest==3)    { D=C; n=&r; ch2='C';}
    else    return -1;

    if(srce==dest) return 0;

    if(*m==a)
    {
        return -1;
    }
    else if(*n==0)
    {
        return -1;
    }
    else if(*n==a)
    {
        D[*n]=S[*m+1];
        S[*m+1]=0;
        *m=*m+1;
        *n=*n-1;
        return 0;
    }
    else if(S[*m+1]<D[*n+1])
    {
        D[*n]=S[*m+1];
        S[*m+1]=0;
        *m=*m+1;
        *n=*n-1;
        return 0;
    }
    else if(S[*m+1]>D[*n+1])
    {
        return -1;
    }
}

int hanoi::move(char *srce, char *dest)
{
    int i, j;
    if(srce[0]=='a' || srce[0]=='A' || srce[0]=='1') i=1;
    else if(srce[0]=='b' || srce[0]=='B' || srce[0]=='2') i=2;
    else if(srce[0]=='c' || srce[0]=='C' || srce[0]=='3') i=3;
    else i=4;

    if(dest[0]=='a' || dest[0]=='A' || dest[0]=='1') j=1;
    else if(dest[0]=='b' || dest[0]=='B' || dest[0]=='2') j=2;
    else if(dest[0]=='c' || dest[0]=='C' || dest[0]=='3') j=3;
    else j=4;

    return move(i, j);
}

int hanoi::move(char srce, char dest)
{
    int i, j;
    if(srce=='a' || srce=='A' || srce=='1') i=1;
    else if(srce=='b' || srce=='B' || srce=='2') i=2;
    else if(srce=='c' || srce=='C' || srce=='3') i=3;
    else i=4;

    if(dest=='a' || dest=='A' || dest=='1') j=1;
    else if(dest=='b' || dest=='B' || dest=='2') j=2;
    else if(dest=='c' || dest=='C' || dest=='3') j=3;
    else j=4;

    return move(i, j);
}

int hanoi::move(char *str)
{
    int length=0, flag=0;
    char srce, dest;
    while(str[length++]) if(length==100) break;
    length--;

    for(int i=0; i<length; i++)
    {
        if(str[i]=='a' || str[i]=='A' || str[i]=='1' || str[i]=='b' || str[i]=='B' || str[i]=='2' || str[i]=='c' || str[i]=='C' || str[i]=='3')
        {
            if(flag==0)
            {
                srce=str[i];
                flag=1;
            }
            else if(flag==1)
            {
                dest=str[i];
                flag=2;
                break;
            }
        }
    }

    if(flag!=2)
    {
        return -1;
    }
    else
    {
        return move(srce,dest);
    }
}
