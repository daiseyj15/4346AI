#include <iostream>


#ifndef H1_H
#define H1_H


class H1
{
    //h1 function is the number of misplaced tiles
   private:
        int h1;
   public:
        H1(struct Node* );
    void calculateMissPlaced(struct Node*);
    int getH1();
        ~H1();


};

#endif // H1_H
