#include <iostream>

#include "H2.h"

H2::H2(Node* head)
{
    calculateSumOfDistances(head);
}

void H2::calculateSumOfDistances(Node* head)
{
        h2=0;

        if(head->puzzle[0][0] != 1)
        {
            if(head->puzzle[0][0]==2)
                h2 += 1;
            if(head->puzzle[0][0]==3)
                h2 += 2;
            if(head->puzzle[0][0]==4)
                h2 += 3;
            if(head->puzzle[0][0]==5)
                h2 += 4;
            if(head->puzzle[0][0]==6)
                h2 += 3;
            if(head->puzzle[0][0]==7)
                h2 += 2;
            if(head->puzzle[0][0]==8)
                h2 += 1;
        }
        if(head->puzzle[0][1] != 2)
        {
            if(head->puzzle[0][1]==1)
                h2 += 1;
            if(head->puzzle[0][1]==3)
                h2 += 1;
            if(head->puzzle[0][1]==4)
                h2 += 2;
            if(head->puzzle[0][1]==5)
                h2 += 3;
            if(head->puzzle[0][1]==6)
                h2 += 2;
            if(head->puzzle[0][1]==7)
                h2 += 3;
            if(head->puzzle[0][1]==8)
                h2 += 2;

        }
        if(head->puzzle[0][2] != 3)
        {
            if(head->puzzle[0][2]==1)
                h2 += 2;
            if(head->puzzle[0][2]==2)
                h2 += 1;
            if(head->puzzle[0][2]==4)
                h2 += 1;
            if(head->puzzle[0][2]==5)
                h2 += 2;
            if(head->puzzle[0][2]==6)
                h2 += 3;
            if(head->puzzle[0][2]==7)
                h2 += 4;
            if(head->puzzle[0][2]==8)
                h2 += 3;
        }
        if(head->puzzle[1][0] != 8)
        {
            if(head->puzzle[1][0]==1)
                h2 += 1;
            if(head->puzzle[1][0]==2)
                h2 += 2;
            if(head->puzzle[1][0]==3)
                h2 += 3;
            if(head->puzzle[1][0]==4)
                h2 += 2;
            if(head->puzzle[1][0]==5)
                h2 += 3;
            if(head->puzzle[1][0]==6)
                h2 += 2;
            if(head->puzzle[1][0]==7)
                h2 += 1;
        }
        if(head->puzzle[1][1] != 0)
        {
            if(head->puzzle[1][1]==1)
                h2 += 2;
            if(head->puzzle[1][1]==2)
                h2 += 1;
            if(head->puzzle[1][1]==3)
                h2 += 2;
            if(head->puzzle[1][1]==4)
                h2 += 1;
            if(head->puzzle[1][1]==5)
                h2 += 2;
            if(head->puzzle[1][1]==6)
                h2 += 1;
            if(head->puzzle[1][1]==7)
                h2 += 2;
            if(head->puzzle[1][1]==8)
                h2 += 1;
        }
        if(head->puzzle[1][2] != 4)
        {
            if(head->puzzle[1][2]==1)
                h2 += 3;
            if(head->puzzle[1][2]==2)
                h2 += 2;
            if(head->puzzle[1][2]==3)
                h2 += 1;
            if(head->puzzle[1][2]==5)
                h2 += 1;
            if(head->puzzle[1][2]==6)
                h2 += 2;
            if(head->puzzle[1][2]==7)
                h2 += 3;
            if(head->puzzle[1][2]==8)
                h2 += 2;
        }
        if(head->puzzle[2][0] != 7)
        {
            if(head->puzzle[2][0]==1)
                h2 += 2;
            if(head->puzzle[2][0]==2)
                h2 += 3;
            if(head->puzzle[2][0]==3)
                h2 += 4;
            if(head->puzzle[2][0]==4)
                h2 += 3;
            if(head->puzzle[2][0]==5)
                h2 += 2;
            if(head->puzzle[2][0]==6)
                h2 += 1;
            if(head->puzzle[2][0]==8)
                h2 += 1;
        }
        if(head->puzzle[2][1] != 6)
        {
            if(head->puzzle[2][1]==1)
                h2 += 3;
            if(head->puzzle[2][1]==2)
                h2 += 2;
            if(head->puzzle[2][1]==3)
                h2 += 3;
            if(head->puzzle[2][1]==4)
                h2 += 2;
            if(head->puzzle[2][1]==5)
                h2 += 1;
            if(head->puzzle[2][1]==7)
                h2 += 1;
            if(head->puzzle[2][1]==8)
                h2 += 2;
        }
        if(head->puzzle[2][2] != 5)
        {
            if(head->puzzle[2][2]==1)
                h2 += 4;
            if(head->puzzle[2][2]==2)
                h2 += 3;
            if(head->puzzle[2][2]==3)
                h2 += 2;
            if(head->puzzle[2][2]==4)
                h2 += 1;
            if(head->puzzle[2][2]==6)
                h2 += 1;
            if(head->puzzle[2][2]==7)
                h2 += 2;
            if(head->puzzle[2][2]==8)
                h2 += 3;
        }

}

int H2::getH2()
{
    return h2;
}


H2::~H2()
{

}
