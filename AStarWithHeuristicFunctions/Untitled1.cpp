

int heuristicFunctionS(Node* current)
{
    int s=0;
    if(current->puzzle[1][1] != 0)
    {
        s += 1;
    }
    if(current->puzzle[1][0] != (current->puzzle[0][0] + 1))
    {
        s += 2;
    }
    if(current->puzzle[2][0] != (current->previous[1][0]+1))
    {
        s += 2;
    }
    if(current->puzzle[2][1] != (current->puzzle[2][0]+1))
    {
        s += 2;
    }
    if(current->puzzle[2][2] != (current->puzzle[2][1]+1))
    {
        s+=2;
    }
    if(current->puzzle[1][2] != (current->puzzle[2][2]+1))
    {
        s+=2;
    }
    if(current->puzzle[0][2] != (current->puzzle[1][2]+1))
    {
        s+=2;
    }
    if(current->puzzle[0][1] != (current->puzzle[0][2]+1))
    {
        s+=2;
    }
//[0][0] | [1][0] | [2][0]
//[0][1] |  [1][1]| [2][1]
//[0][2] |  [1][2]| [2][2]

//1 | 2 | 3
//8 | 0 | 4
//7 | 6 | 5
    return s;
}

int heuristicFunctionH(int h2Value, int sValue)
{
    //H (n) = h2(n) + 3 * S (n)
    int capitalhValue = 0;
    capitalhValue = h2Value + (3*sValue);
    return capitalhValue;
}

int heuristicFunctionF(int gValue, int capitalHValue)
{
    //F(n) = g(n) + H(n)

    int capitalFvalue = 0;
    capitalFvalue = gValue + capitalHValue;
    return capitalFvalue;
}

int calculateSumOfDistances(Node* current)
{
//[0][0] | [1][0] | [2][0]
//[0][1] |  [1][1]| [2][1]
//[0][2] |  [1][2]| [2][2]

//1 | 2 | 3
//8 | 0 | 4
//7 | 6 | 5
        int h2=0;

        if(current->puzzle[0][0] != 1)
        {
            if(current->puzzle[0][0]==2)
                h2 += 1;
            if(current->puzzle[0][0]==3)
                h2 += 2;
            if(current->puzzle[0][0]==4)
                h2 += 3;
            if(current->puzzle[0][0]==5)
                h2 += 4;
            if(current->puzzle[0][0]==6)
                h2 += 3;
            if(current->puzzle[0][0]==7)
                h2 += 2;
            if(current->puzzle[0][0]==8)
                h2 += 1;
        }
        if(current->puzzle[1][0] != 2)
        {
            if(current->puzzle[1][0]==1)
                h2 += 1;
            if(current->puzzle[1][0]==3)
                h2 += 1;
            if(current->puzzle[1][0]==4)
                h2 += 2;
            if(current->puzzle[1][0]==5)
                h2 += 3;
            if(current->puzzle[1][0]==6)
                h2 += 2;
            if(current->puzzle[1][0]==7)
                h2 += 3;
            if(current->puzzle[1][0]==8)
                h2 += 2;

        }
        if(current->puzzle[2][0] != 3)
        {
            if(current->puzzle[2][0]==1)
                h2 += 2;
            if(current->puzzle[2][0]==2)
                h2 += 1;
            if(current->puzzle[2][0]==4)
                h2 += 1;
            if(current->puzzle[2][0]==5)
                h2 += 2;
            if(current->puzzle[2][0]==6)
                h2 += 3;
            if(current->puzzle[2][0]==7)
                h2 += 4;
            if(current->puzzle[2][0]==8)
                h2 += 3;
        }
        if(current->puzzle[0][1] != 8)
        {
            if(current->puzzle[0][1]==1)
                h2 += 1;
            if(current->puzzle[0][1]==2)
                h2 += 2;
            if(current->puzzle[0][1]==3)
                h2 += 3;
            if(current->puzzle[0][1]==4)
                h2 += 2;
            if(current->puzzle[0][1]==5)
                h2 += 3;
            if(current->puzzle[0][1]==6)
                h2 += 2;
            if(current->puzzle[0][1]==7)
                h2 += 1;
        }
        if(current->puzzle[1][1] != 0)
        {
            if(current->puzzle[1][1]==1)
                h2 += 2;
            if(current->puzzle[1][1]==2)
                h2 += 1;
            if(current->puzzle[1][1]==3)
                h2 += 2;
            if(current->puzzle[1][1]==4)
                h2 += 1;
            if(current->puzzle[1][1]==5)
                h2 += 2;
            if(current->puzzle[1][1]==6)
                h2 += 1;
            if(current->puzzle[1][1]==7)
                h2 += 2;
            if(current->puzzle[1][1]==8)
                h2 += 1;
        }
        if(current->puzzle[2][1] != 4)
        {
            if(current->puzzle[2][1]==1)
                h2 += 3;
            if(current->puzzle[2][1]==2)
                h2 += 2;
            if(current->puzzle[2][1]==3)
                h2 += 1;
            if(current->puzzle[2][1]==5)
                h2 += 1;
            if(current->puzzle[2][1]==6)
                h2 += 2;
            if(current->puzzle[2][1]==7)
                h2 += 3;
            if(current->puzzle[2][1]==8)
                h2 += 2;
        }
        if(current->puzzle[0][2] != 7)
        {
            if(current->puzzle[0][2]==1)
                h2 += 2;
            if(current->puzzle[0][2]==2)
                h2 += 3;
            if(current->puzzle[0][2]==3)
                h2 += 4;
            if(current->puzzle[0][2]==4)
                h2 += 3;
            if(current->puzzle[0][2]==5)
                h2 += 2;
            if(current->puzzle[0][2]==6)
                h2 += 1;
            if(current->puzzle[0][2]==8)
                h2 += 1;
        }
        if(current->puzzle[1][2] != 6)
        {
            if(current->puzzle[1][2]==1)
                h2 += 3;
            if(current->puzzle[1][2]==2)
                h2 += 2;
            if(current->puzzle[1][2]==3)
                h2 += 3;
            if(current->puzzle[1][2]==4)
                h2 += 2;
            if(current->puzzle[1][2]==5)
                h2 += 1;
            if(current->puzzle[1][2]==7)
                h2 += 1;
            if(current->puzzle[1][2]==8)
                h2 += 2;
        }
        if(current->puzzle[2][2] != 5)
        {
            if(current->puzzle[2][2]==1)
                h2 += 4;
            if(current->puzzle[2][2]==2)
                h2 += 3;
            if(current->puzzle[2][2]==3)
                h2 += 2;
            if(current->puzzle[2][2]==4)
                h2 += 1;
            if(current->puzzle[2][2]==6)
                h2 += 1;
            if(current->puzzle[2][2]==7)
                h2 += 2;
            if(current->puzzle[2][2]==8)
                h2 += 3;
        }
    return h2;
}

int calculateMissPlaced(Node* current)
{
//[0][0] | [1][0] | [2][0]
//[0][1] |  [1][1]| [2][1]
//[0][2] |  [1][2]| [2][2]

//1 | 2 | 3
//8 | 0 | 4
//7 | 6 | 5
            int h1=0;

        if(current->puzzle[0][0] != 1)
            h1 += 1;
        if(current->puzzle[1][0] != 2)
            h1 += 1;
        if(current->puzzle[2][0] != 3)
            h1 += 1;
        if(current->puzzle[2][1] != 4)
            h1 += 1;
        if(current->puzzle[2][2] != 5)
            h1 += 1;
        if(current->puzzle[1][2] != 6)
            h1 += 1;
        if(current->puzzle[0][2] != 7)
            h1 += 1;
        if(current->puzzle[0][1] != 8)
            h1 += 1;

    return h1;
}

