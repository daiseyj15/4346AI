
float heuristicFunction_H4(Node* s, AStar* t)
{
    //h4(n) = # tiles misplaced in terms of row + # tiles misplaced in terms of column
    float misplacedRow = 0;
    float misplacedColum = 0;

    int** currentpuzzle = s->getPuzzle();
    if(currentpuzzle[0][0] != 1 && currentpuzzle[0][0] != 2 && currentpuzzle[0][0] != 3)
        misplacedRow += 1;
    if(currentpuzzle[0][1] != 1 && currentpuzzle[0][1] != 2 && currentpuzzle[0][1] != 3)
        misplacedRow += 1;
    if(currentpuzzle[0][2] != 1 && currentpuzzle[0][2] != 2 && currentpuzzle[0][2] != 3)
        misplacedRow += 1;
    if(currentpuzzle[1][0] != 8 && currentpuzzle[1][0] != 0 && currentpuzzle[1][0] != 4)
        misplacedRow += 1;
    if(currentpuzzle[1][1] != 8 && currentpuzzle[1][1] != 0 && currentpuzzle[1][1] != 4)
        misplacedRow += 1;
    if(currentpuzzle[1][2] != 8 && currentpuzzle[1][2] != 0 && currentpuzzle[1][2] != 4)
        misplacedRow += 1;
    if(currentpuzzle[2][0] != 7 && currentpuzzle[2][0] != 6 && currentpuzzle[2][0] != 5)
        misplacedRow += 1;
    if(currentpuzzle[2][1] != 7 && currentpuzzle[2][1] != 6 && currentpuzzle[2][1] != 5)
        misplacedRow += 1;
    if(currentpuzzle[2][2] != 7 && currentpuzzle[2][2] != 6 && currentpuzzle[2][2] != 5)
        misplacedRow += 1;


    if(currentpuzzle[0][0] != 1 && currentpuzzle[0][0] != 8 && currentpuzzle[0][0] != 7)
        misplacedColum += 1;
    if(currentpuzzle[1][0] != 1 && currentpuzzle[1][0] != 8 && currentpuzzle[1][0] != 7)
        misplacedColum += 1;
    if(currentpuzzle[2][0] != 1 && currentpuzzle[2][0] != 8 && currentpuzzle[2][0] != 7)
        misplacedColum += 1;
    if(currentpuzzle[0][1] != 2 && currentpuzzle[0][1] != 0 && currentpuzzle[0][1] != 6)
        misplacedColum += 1;
    if(currentpuzzle[1][1] != 2 && currentpuzzle[1][1] != 0 && currentpuzzle[1][1] != 6)
        misplacedColum += 1;
    if(currentpuzzle[2][1] != 2 && currentpuzzle[2][1] != 0 && currentpuzzle[2][1] != 6)
        misplacedColum += 1;
    if(currentpuzzle[0][2] != 3 && currentpuzzle[0][2] != 4 && currentpuzzle[0][2] != 5)
        misplacedColum += 1;
    if(currentpuzzle[1][2] != 3 && currentpuzzle[1][2] != 4 && currentpuzzle[1][2] != 5)
        misplacedColum += 1;
    if(currentpuzzle[2][2] != 3 && currentpuzzle[2][2] != 4 && currentpuzzle[2][2] != 5)
        misplacedColum += 1;

    return (misplacedColum + misplacedRow);
}



