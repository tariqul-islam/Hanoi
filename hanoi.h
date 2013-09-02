/**************
HANOI.H
Contains a hanoi class
which can be used to create a game.
I created is to build one of such game.
But never finished.

Written By:
Mohammad Tariqul Islam
ponir . bd @ hotmail . com
10/2/2011
**************/

#ifndef HANOI_H
#define HANOI_H


//starts the description
class hanoi
{
private:
    int *A, *B, *C;
    int a;
    int p, q, r;

public:
    hanoi(int size); //constructor, creates a tower of size size
    hanoi(const hanoi &source); //copy constructor
    ~hanoi(); //destructor, frees memory
    int recons(int size); //reconstruct the class midway, old memories will be deleted, new tower os size 'size' will be created
    int move(int srce, int dest); //moves a tile from srce to dest, values 1, 2 or 3
    int move(char *srce, char *dest); //moves a tile from srce to dest, values, strings "A","B","C" , not case sensetive
    int move(char srce, char dest); //moves a tile from srce to dest, values, chars 'A','B','C' , not case sensetive
    int move(char *str); ////moves a tile from srce to dest, values, strings "AB","BC","CA", "BA" , not case sensetive, will move from first character to second character
    void print(); //prints the tower
    int check(); //checks whether the tower is correct or not
    //coming soon
    /*
    char *solve() //solves the current state of the tower
    */
};

#endif
