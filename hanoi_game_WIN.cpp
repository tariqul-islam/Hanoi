//sample game created using hanoi class defined in hannoi.h
//
//Mohammad Tariqul Islam
//ponir.bd @ hotmail.com

#include<iostream>
#include "hanoi.h"
#include "hanoi.cpp"

using namespace std;

const char* note = "This is a sample tower of hanoi game. Start with 5tiles.\nUse 2 space separated integers to move tiles from one peg to another.\ni.e. 1 2 will move a tile from peg no 1 to peg no 2.\nPossible integer values are 1 2 and 3\nNOTE: inputs other than integers is likely to crash the program.\n\n";

main()
{
    cout<<note;
    hanoi a(5);
    a.print();
    int i, j;
    while(1)
    {
        cin>>i>>j;
        a.move(i,j);
        a.print();
    }

    cout<<a.check();
    return 0;
}
