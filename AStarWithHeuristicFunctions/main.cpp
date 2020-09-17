#include <iostream>
#include <stdlib.h>
#include <H1.h>

using namespace std;



struct Node {

           //  x  y   y/x 0 1 2

    int puzzle[3][3];// 0 x x x

                     // 1 x x x

                     // 2 x x x

    int empty[2];

    //empty[0] == X coord

    //empty[1] == Y coord

    struct Node* next;

    struct Node* previous;

    int f_value;

};

int type = 0; //increments as program runs to eventually run all 5 heuristic functions

int record_count = 0;

bool win_flag = false;

void print(Node* a);

void setStartPosition1(Node* a);

void setStartPosition2(Node* a);

void pushCLOSE(Node* a);

void popOPEN(Node* a);

void mergeSortOPEN(Node** a);

Node* SortedMerge(Node* a, Node* b);

void FrontBackSplit(Node* source,

    Node** frontRef, Node** backRef);

Node* moveLeft(Node* a);

Node* moveRight(Node* a);

Node* moveUp(Node* a);

Node* moveDown(Node* a);

bool checkIfGoal(Node* current);

bool checkIfRepeat(Node* a);

void init();

void run();

int calculateFvalue(Node* a);

Node* chooseBest(Node* a);

struct Node* openHead = (struct Node*) malloc(sizeof(struct Node));

struct Node* closeHead = (struct Node*) malloc(sizeof(struct Node));



/*

Node setTile(Node a, int x, int y, int tileNumber) {

    a.puzzle[x][y] = tileNumber;

    return a;

}*/



void setStartPosition1(Node* a) {

    a->puzzle[0][0] = 2;

    a->puzzle[0][1] = 1;

    a->puzzle[0][2] = 0; //0 = EMPTY

    a->puzzle[1][0] = 8;

    a->puzzle[1][1] = 6;

    a->puzzle[1][2] = 7;

    a->puzzle[2][0] = 3;

    a->puzzle[2][1] = 4;

    a->puzzle[2][2] = 5;

    a->empty[0] = 0;

    a->empty[1] = 2;

}



void setStartPosition2(Node* a) {

    a->puzzle[0][0] = 2;

    a->puzzle[0][1] = 4;

    a->puzzle[0][2] = 7;

    a->puzzle[1][0] = 1;

    a->puzzle[1][1] = 0; //0 = EMPTY

    a->puzzle[1][2] = 5;

    a->puzzle[2][0] = 6;

    a->puzzle[2][1] = 8;

    a->puzzle[2][2] = 3;

    a->empty[0] = 1;

    a->empty[1] = 1;

}



Node* moveLeft(Node* a) {

    Node* temp = (struct Node*) malloc(sizeof(struct Node));

    temp->puzzle[0][0] = a->puzzle[0][0];//copying over current node

    temp->puzzle[0][1] = a->puzzle[0][1];

    temp->puzzle[0][2] = a->puzzle[0][2];

    temp->puzzle[1][0] = a->puzzle[1][0];

    temp->puzzle[1][1] = a->puzzle[1][1];

    temp->puzzle[1][2] = a->puzzle[1][2];

    temp->puzzle[2][0] = a->puzzle[2][0];

    temp->puzzle[2][1] = a->puzzle[2][1];

    temp->puzzle[2][2] = a->puzzle[2][2];

    //moving blank space left

    temp->puzzle[a->empty[0]][a->empty[1]] = temp->puzzle[a->empty[0] - 1][a->empty[1]];

    temp->puzzle[a->empty[0] - 1][a->empty[1]] = 0;

    temp->empty[0] = a->empty[0] - 1;

    temp->empty[1] = a->empty[1];

    temp->next = NULL;

    temp->previous = a;

    temp->f_value = calculateFvalue(temp);              //CALCUALTES F VALUE HERE

    return temp;

}



Node* moveRight(Node* a) {

    Node* temp = (struct Node*) malloc(sizeof(struct Node));

    temp->puzzle[0][0] = a->puzzle[0][0];//copying over current node

    temp->puzzle[0][1] = a->puzzle[0][1];

    temp->puzzle[0][2] = a->puzzle[0][2];

    temp->puzzle[1][0] = a->puzzle[1][0];

    temp->puzzle[1][1] = a->puzzle[1][1];

    temp->puzzle[1][2] = a->puzzle[1][2];

    temp->puzzle[2][0] = a->puzzle[2][0];

    temp->puzzle[2][1] = a->puzzle[2][1];

    temp->puzzle[2][2] = a->puzzle[2][2];

    //moving blank space right

    temp->puzzle[a->empty[0]][a->empty[1]] = temp->puzzle[a->empty[0] + 1][a->empty[1]];

    temp->puzzle[a->empty[0] + 1][a->empty[1]] = 0;

    temp->empty[0] = a->empty[0] + 1;

    temp->empty[1] = a->empty[1];

    temp->next = NULL;

    temp->previous = a;

    temp->f_value = calculateFvalue(temp);              //CALCUALTES F VALUE HERE

    return temp;

}



Node* moveUp(Node* a) {

    Node* temp = (struct Node*) malloc(sizeof(struct Node));

    temp->puzzle[0][0] = a->puzzle[0][0];//copying over current node

    temp->puzzle[0][1] = a->puzzle[0][1];

    temp->puzzle[0][2] = a->puzzle[0][2];

    temp->puzzle[1][0] = a->puzzle[1][0];

    temp->puzzle[1][1] = a->puzzle[1][1];

    temp->puzzle[1][2] = a->puzzle[1][2];

    temp->puzzle[2][0] = a->puzzle[2][0];

    temp->puzzle[2][1] = a->puzzle[2][1];

    temp->puzzle[2][2] = a->puzzle[2][2];

    //moving blank space up

    temp->puzzle[a->empty[0]][a->empty[1]] = temp->puzzle[a->empty[0]][a->empty[1] - 1];

    temp->puzzle[a->empty[0]][a->empty[1] - 1] = 0;

    temp->empty[0] = a->empty[0];

    temp->empty[1] = a->empty[1] - 1;

    temp->next = NULL;

    temp->previous = a;

    temp->f_value = calculateFvalue(temp);              //CALCUALTES F VALUE HERE

    return temp;

}



Node* moveDown(Node* a) {

    Node* temp = (struct Node*) malloc(sizeof(struct Node));

    temp->puzzle[0][0] = a->puzzle[0][0];//copying over current node

    temp->puzzle[0][1] = a->puzzle[0][1];

    temp->puzzle[0][2] = a->puzzle[0][2];

    temp->puzzle[1][0] = a->puzzle[1][0];

    temp->puzzle[1][1] = a->puzzle[1][1];

    temp->puzzle[1][2] = a->puzzle[1][2];

    temp->puzzle[2][0] = a->puzzle[2][0];

    temp->puzzle[2][1] = a->puzzle[2][1];

    temp->puzzle[2][2] = a->puzzle[2][2];

    //moving blank space down

    temp->puzzle[a->empty[0]][a->empty[1]] = temp->puzzle[a->empty[0]][a->empty[1] + 1];

    temp->puzzle[a->empty[0]][a->empty[1] + 1] = 0;

    temp->empty[0] = a->empty[0];

    temp->empty[1] = a->empty[1] + 1;

    temp->next = NULL;

    temp->previous = a;

    temp->f_value = calculateFvalue(temp);              //CALCUALTES F VALUE HERE

    return temp;

}



void print(Node a) {

    cout << "--------" << endl;

    cout << "|" << a.puzzle[0][0] << "|" << a.puzzle[1][0] << "|" << a.puzzle[2][0] << "|" << endl;

    cout << "--------" << endl;

    cout << "|" << a.puzzle[0][1] << "|" << a.puzzle[1][1] << "|" << a.puzzle[2][1] << "|" << endl;

    cout << "--------" << endl;

    cout << "|" << a.puzzle[0][2] << "|" << a.puzzle[1][2] << "|" << a.puzzle[2][2] << "|" << endl;

    cout << "--------" << endl;

}







//returns false if it has been repeated and has a lower f_value, otherwise true

bool checkIfRepeat(Node* a) {

    Node* cur = a;

    Node* temp = closeHead;

    for (int i = 0; i < record_count; i++) {

        if ((temp->puzzle[0][0] == cur->puzzle[0][0] &&

            temp->puzzle[0][1] == cur->puzzle[0][1] &&

            temp->puzzle[0][2] == cur->puzzle[0][2] &&

            temp->puzzle[1][0] == cur->puzzle[1][0] &&

            temp->puzzle[1][1] == cur->puzzle[1][1] &&

            temp->puzzle[1][2] == cur->puzzle[1][2] &&

            temp->puzzle[2][0] == cur->puzzle[2][0] &&

            temp->puzzle[2][1] == cur->puzzle[2][1] &&

            temp->puzzle[2][2] == cur->puzzle[2][2]) &&

            ((temp->f_value < cur->f_value) || (temp->f_value == 0)))

        {

            cout << "a" << endl;

            return false;

        }

        if(temp->next != NULL)

            temp = temp->next;

    }

    temp = openHead;

    for (int i = 0; i < record_count; i++) {

        if (temp->puzzle[0][0] == cur->puzzle[0][0] &&

            temp->puzzle[0][1] == cur->puzzle[0][1] &&

            temp->puzzle[0][2] == cur->puzzle[0][2] &&

            temp->puzzle[1][0] == cur->puzzle[1][0] &&

            temp->puzzle[1][1] == cur->puzzle[1][1] &&

            temp->puzzle[1][2] == cur->puzzle[1][2] &&

            temp->puzzle[2][0] == cur->puzzle[2][0] &&

            temp->puzzle[2][1] == cur->puzzle[2][1] &&

            temp->puzzle[2][2] == cur->puzzle[2][2] &&

            temp->f_value < cur->f_value           )

            return false;

        if (temp->next != NULL)

            temp = temp->next;

    }

    return true;

}



//this function generates the four possible blank moves and assigns them to each

//respective pointer node. Before adding them it checks to see if it has been recorded or not

//if it hasnt, it will be added to the record

void generateSuccessors(Node* current) {

    Node* cur = current;

    Node* record = closeHead;

    Node* temp = (struct Node*) malloc(sizeof(struct Node));

    Node* adding = (struct Node*) malloc(sizeof(struct Node));



    //cout << "test 0" << endl;

    //print(current);

    if (current->empty[1] != 2) //Move Down possible

    {

        temp = moveDown(current);

        if (checkIfRepeat(temp)) {

            while (cur->next != NULL)

                cur = cur->next;

            cur->next = temp;



        }

    }

    //cout << "test 1" << endl;

    //print(current);

    if (current->empty[1] != 0)//Move Up possible

    {

        temp = moveUp(current);

        if (checkIfRepeat(temp)) {



            while (cur->next != NULL)

                cur = cur->next;

            cur->next = temp;

        }

    }

    //cout << "test 2" << endl;

    //print(current);

    if (current->empty[0] != 2)// Move Right Possible

    {

        temp = moveRight(current);

        if (checkIfRepeat(temp)) {

            while (cur->next != NULL)

                cur = cur->next;

            cur->next = temp;



        }

    }

    //cout << "test 3" << endl;

    //print(current);

    if (current->empty[0] != 0)//Move Left possible

    {

        temp = moveLeft(current);

        if (checkIfRepeat(temp)) {

            while (cur->next != NULL)

                cur = cur->next;

            cur->next = temp;



        }

    }



    //push current onto closed list

    pushCLOSE(current);

    //pop current from open list

    popOPEN(current);



    //sort open from highest to lowest F-value

    mergeSortOPEN(&openHead);

    record_count++;

}



void mergeSortOPEN(Node** current) {

    Node* head = *current;

    Node* a;

    Node* b;



    /* Base case -- length 0 or 1 */

    if ((head == NULL) || (head->next == NULL)) {

        return;

    }

    FrontBackSplit(head, &a, &b);

    /* Recursively sort the sublists */

    mergeSortOPEN(&a);

    mergeSortOPEN(&b);

    /* answer = merge the two sorted lists together */

    *current = SortedMerge(a, b);

}



Node* SortedMerge(Node* a, Node* b)

{

    Node* result = NULL;



    /* Base cases */

    if (a == NULL)

        return (b);

    else if (b == NULL)

        return (a);



    /* Pick either a or b, and recur */

    if (a->f_value <= b->f_value) {

        result = a;

        result->next = SortedMerge(a->next, b);

    }

    else {

        result = b;

        result->next = SortedMerge(a, b->next);

    }

    return (result);

}



void FrontBackSplit(Node* source,

    Node** frontRef, Node** backRef)

{

    Node* fast;

    Node* slow;

    slow = source;

    fast = source->next;



    /* Advance 'fast' two nodes, and advance 'slow' one node */

    while (fast != NULL) {

        fast = fast->next;

        if (fast != NULL) {

            slow = slow->next;

            fast = fast->next;

        }

    }



    /* 'slow' is before the midpoint in the list, so split it in two

    at that point. */

    *frontRef = source;

    *backRef = slow->next;

    slow->next = NULL;

}





void popOPEN(Node* current) {

    struct Node* temp;



    // check for stack underflow

    if (openHead == NULL) {

        cout << "\nStack Underflow" << endl;

        exit(1);

    }

    else {

        // openHead assign into temp

        temp = openHead;

        // assign second node to openHead

        openHead = openHead->next;

        // destroy connection between first and second

        temp->next = NULL;



        // release memory of top node

        free(temp);

    }

}



void pushCLOSE(Node* a)

{

    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));



    // check if stack (heap) is full. Then inserting an element would

    // lead to stack overflow

    if (!temp) {

        cout << "\nHeap Overflow";

        exit(1);

    }

    // initialize data into temp data field

    temp->puzzle[0][0] = a->puzzle[0][0];//copying over current node

    temp->puzzle[0][1] = a->puzzle[0][1];

    temp->puzzle[0][2] = a->puzzle[0][2];

    temp->puzzle[1][0] = a->puzzle[1][0];

    temp->puzzle[1][1] = a->puzzle[1][1];

    temp->puzzle[1][2] = a->puzzle[1][2];

    temp->puzzle[2][0] = a->puzzle[2][0];

    temp->puzzle[2][1] = a->puzzle[2][1];

    temp->puzzle[2][2] = a->puzzle[2][2];

    temp->empty[0] = a->empty[0];

    temp->empty[1] = a->empty[1];

    temp->f_value = a->f_value;

    // put top pointer reference into temp link

    temp->next = closeHead;

    temp->previous = NULL;

    // make temp as top of Stack

    closeHead = temp;

}





void init() {

    openHead->puzzle[0][0] = 0;

    openHead->puzzle[0][1] = 0;

    openHead->puzzle[0][2] = 0;

    openHead->puzzle[1][0] = 0;

    openHead->puzzle[1][1] = 0;

    openHead->puzzle[1][2] = 0;

    openHead->puzzle[2][0] = 0;

    openHead->puzzle[2][1] = 0;

    openHead->puzzle[2][2] = 0;

    openHead->empty[0] = 0;

    openHead->empty[1] = 0;

    openHead->previous = NULL;

    openHead->next = NULL;

    openHead->f_value = 0;



    closeHead->puzzle[0][0] = 0;

    closeHead->puzzle[0][1] = 0;

    closeHead->puzzle[0][2] = 0;

    closeHead->puzzle[1][0] = 0;

    closeHead->puzzle[1][1] = 0;

    closeHead->puzzle[1][2] = 0;

    closeHead->puzzle[2][0] = 0;

    closeHead->puzzle[2][1] = 0;

    closeHead->puzzle[2][2] = 0;

    closeHead->empty[0] = 0;

    closeHead->empty[1] = 0;

    closeHead->previous = NULL;

    closeHead->next = NULL;

    closeHead->f_value = 0;

    setStartPosition1(openHead);

    //setStartPosition1(closeHead);

    record_count = 1;

}



void print(Node* a) {

    cout << "--------" << endl;

    cout << "|" << a->puzzle[0][0] << "|" << a->puzzle[1][0] << "|" << a->puzzle[2][0] << "|" << endl;

    cout << "--------" << endl;

    cout << "|" << a->puzzle[0][1] << "|" << a->puzzle[1][1] << "|" << a->puzzle[2][1] << "|" << endl;

    cout << "--------" << endl;

    cout << "|" << a->puzzle[0][2] << "|" << a->puzzle[1][2] << "|" << a->puzzle[2][2] << "|" << endl;

    cout << "--------" << endl;

}



//compares a given nodes puzzle to the goal state

//returns true if is is the goal state, false otherwise

bool checkIfGoal(Node* current) {

    Node* cur = current;

    if (current->puzzle[0][0] == 1 &&

        current->puzzle[0][1] == 8 &&

        current->puzzle[0][2] == 7 &&

        current->puzzle[1][0] == 2 &&

        current->puzzle[1][1] == 0 &&

        current->puzzle[1][2] == 6 &&

        current->puzzle[2][0] == 3 &&

        current->puzzle[2][1] == 4 &&

        current->puzzle[2][2] == 5)

        return true;

    else

        return false;

}



//used to test merge sort worked correctly

int x = 20;

//Implementation of different Heuristic Functions to get F values!!!

int calculateFvalue(Node* a) {

    Node* temp = a;
    int x;

    switch (type) {

    case 0: H1 h1value = new H1(temp);
            x = h1value.getH1();

        break;

    case 1://h2

        break;

    case 2://h3

        break;

    case 3://h4

        break;

    case 4://h5

        break;

    }

    x--;

    return x;

}



//chooses best f_value ***********MAY NEED REVISION************

Node* chooseBest(Node* current) {

    Node* cur = current;

    return cur;

}





void run() {

    init();//initializes heads & recordHead

    while (type < 5) {//runs 5 times for each of the 5 heuristic functions

        while (!win_flag) {

            generateSuccessors(openHead);//generates 4 potential children

            openHead = chooseBest(openHead);//increments to one of the 4 nodes by best f_value

            win_flag = checkIfGoal(openHead);//checks to see if the goal has been reached

        }

        type++;//increments to next type

    }

}



int main()

{

    init();

    //run();

    Node* temp;

    int i = 0;

    cout << "HEAD NODE*****" << endl;

    print(openHead);

    while (i < 4) {

        generateSuccessors(openHead);

         temp = openHead;

        cout << "OPEN AFTER GENERATING CHILDREN FROM HIGHEST F VALUE*******" << endl;

        for (int i = 0; i < 30; i++) {

            print(temp);

            cout << temp->f_value << endl;

            if (temp->next != NULL)

              temp = temp->next;

            else break;

        }

    cout << "NEW OPEN NODE HEAD******" << endl;

    print(openHead);

    cout << openHead->f_value << endl;

    i++;

    }

    /*cout << "***************CLOSED LIST*****************" << endl;

    for (int i = 0; i < 6; i++) {

        print(closeHead);

        cout << closeHead->f_value << endl;

        if (closeHead->next != NULL)

            closeHead = closeHead->next;

        else break;

    }*/



    return 0;

}
