#include "node.h"

#define NMAX 50

using namespace std;

class AdvancedStack {
    private:
        node stackArray[NMAX]; // an array of NMAX dimension
        int topLevel, topMax, topMin; // the top of the stack, representing the INDEX of last element of the
                    //stackArray:0, 1, 3,....
        node stackMax[NMAX];
        node stackMin[NMAX];

    public:
        void push(node x) // puts an element in the stack array
        {
            if (topLevel >= NMAX-1) //check if the stack array has the maximum dimension
			{
                cout<<"The stack is full: we have already NMAX elements!\n";
                //exit the function without making anything
                return;
            }
        	/* add an element=> the index of the last element of the stack Array
        	increases and put the value of the new element in the stack array */

			if(isEmpty()){
				stackArray[++topLevel] = x;
            	stackMax[++topMax] = x;
            	stackMin[++topMin] = x;
            	return;
			}

			if (x.priority > stackMax[topMax].priority ){
            	stackMax[++topMax] = x;
            	node min = stackMin[topMin];
            	stackMin[++topMin] = min;
            }
            else if (x.priority < stackMin[topMin].priority){
            	stackMin[++topMin] = x;
            	node max = stackMax[topMax];
            	stackMax[++topMax] = max;
            }
        	else{
        		node max = stackMax[topMax], min = stackMin[topMin];
            	stackMax[++topMax] = max;
            	stackMin[++topMin] = min;
            }

            stackArray[++topLevel] = x;
        }

        int isEmpty()
        {
            //returns 1, if topLevel>=0, meaning the stack array has elements
            // returns 0, otherwise
            return (topLevel < 0);
        }

        node pop() // extracts and element from the stack array and returns the new top
        {
            if (isEmpty())
            {
            // the extraction is made only if the array is not empty
                cout<<"The stack is empty! \n";
                node x;
                return x;
            }

            stackMax[topMax--];
            stackMin[topMin--];


            return stackArray[topLevel--]; 	// the topLevel decreases and the new top is changed
            //difference return stackArray[--topLevel] ?
        }

        node peek()
        {
        // returns the top of the stack
            if (isEmpty())
            {
            // the extraction is made only if the array is not empty
                cout<<"The stack is empty! \n";
                node x;
                return x;
        	}
            return stackArray[topLevel];
        }

        int getTopLevel()
        {
            return topLevel;
        }

        node getMax(){
			return stackMax[topMax];
		}

		node getMin(){
			return stackMin[topMin];
		}

        AdvancedStack()
        { // constructor
            topLevel = -1; //the stack is empty in the beginning
            topMax = -1;
            topMin = -1;

        }

        ~AdvancedStack()
        { // destructor
        }
};


