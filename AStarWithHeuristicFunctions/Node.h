#ifndef NODE_H
#define NODE_H


class Node
{
    public:
        int gValue;
        int hprime;
   //hPrime is an estimate of the additional cost of getting from the current node to a goal state
        int fprime;
    //fPrime is set to hPrime

        int h1;
    //h1 function is the number of misplaced tiles
    //h2 function is the sum of the distances of misplaced tiles
        int h2;
    //I think for our 3rd heuristic function
    //we could do h which I think is the straight line distance
    //not sure we could calculate it for this problem??
        int h;//?
        int puzzle[3][3];

//        Node(int puz[][]);
        Node();
        ~Node();

    protected:
        void calculateHprime();

    private:
};

#endif // NODE_H
