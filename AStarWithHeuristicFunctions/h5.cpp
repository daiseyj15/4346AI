
float heuristicFunction_H5(Node* s, AStar* t)
{
    //h5(n) = {Go around the edge of the board, i.e.,
    //omit the center square, count the number of pairs
    //of tiles that are "inverted" compared to the goal position, and return this number}

    float pairsInverted = 0;
    int** currentpuzzle = s->getPuzzle();

    if(currentpuzzle[0][0] == (currentpuzzle[0][1]+1))
        pairsInverted += 1;
    if(currentpuzzle[0][1] == (currentpuzzle[0][2]+1))
        pairsInverted += 1;
    if(currentpuzzle[0][2] == (currentpuzzle[1][2]+1))
        pairsInverted += 1;
    if(currentpuzzle[1][2] == (currentpuzzle[2][2]+1))
        pairsInverted += 1;
    if(currentpuzzle[2][2] == (currentpuzzle[2][1]+1))
        pairsInverted += 1;
    if(currentpuzzle[2][1] == (currentpuzzle[2][0]+1))
        pairsInverted += 1;
    if(currentpuzzle[2][0] == (currentpuzzle[1][0]+1))
        pairsInverted += 1;

 return  pairsInverted;
}

