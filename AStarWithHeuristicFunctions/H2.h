#include <iostream>

#ifndef H2_H
#define H2_H

//h2 function is the sum of the distances of misplaced tiles
class H2
{
   private:
        int h2;
   public:
        H2(struct Node*);
        void calculateSumOfDistances(struct Node*);
        int getH2();
        ~H2();


};

#endif // H2_H
