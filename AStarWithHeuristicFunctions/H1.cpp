#include "H1.h"
#include <iostream>


H1::H1(Node* head)
{
        calculateMissPlaced(head);
}

void H1::calculateMissPlaced(Node* head)
{
            h1=0;

        if(head->puzzle[0][0] != 1)
            h1 += 1;
        if(head->puzzle[0][1] != 2)
            h1 += 1;
        if(head->puzzle[0][2] != 3)
            h1 += 1;
        if(head->puzzle[1][2] != 4)
            h1 += 1;
        if(head->puzzle[2][2] != 5)
            h1 += 1;
        if(head->puzzle[2][1] != 6)
            h1 += 1;
        if(head->puzzle[2][0] != 7)
            h1 += 1;
        if(head->puzzle[1][0] != 8)
            h1 += 1;


}

int H1::getH1()
{
    return h1;
}

H1::~H1()
{

}
//[0][0] | [1][0] | [2][0]
//[0][1] |  [1][1]| [2][1]
//[0][2] |  [1][2]| [2][2]

//1 | 2 | 3
//8 | 0 | 4
//7 | 6 | 5
