#include <iostream>
#include <cmath>

using namespace std;

class InsertionSort
{
    static const size_t ArraySize = 6;
    int A[ArraySize];
    static const size_t NonincreasingSize = 6;
    int B[NonincreasingSize];
    static const size_t ArraySizeC = 6;
    int C[ArraySizeC];

    public:
        InsertionSort() : A{5, 2, 4, 6, 1, 3}, B{31, 41, 59, 26, 41, 58}, C{4, 23, 1, 16, 72, 21}
        {
            insertionSort(A, ArraySize);
            printArray(A, ArraySize);
            insertionSortNonincreasing(B, NonincreasingSize);
            printArray(B, NonincreasingSize);
            selectionSort(C, ArraySizeC);
            printArray(C, ArraySizeC);
        }

    //I guess don't put main in the class!!!?????
    /*int main() //no int on this main I guess????
    {
        InsertionSort x;
        // int *Arr = new Arr[5];
        //printArray(A);
        insertionSort(x.A, x.ArraySize);
        printArray(x.A, x.ArraySize);
        //cout << endl;
        return 0;
    }*/


    static void insertionSort(int *A, int ArraySize) //void or int in method????
    {
        for(int j = 1; j < ArraySize; j++)
        {
            int key = A[j]; //at our current index, key saves that number!!!

            //the while loop and i just move all #'s in the Array to the right!!!
            int i = j - 1;
            while (i >= 0 && A[i] > key) //i is to make sure index isn't out of bounds!!!
            {
                A[i + 1] = A[i];
                i = i - 1;
            }
            A[i + 1] = key; //key saved the # and now this puts it into its correct position!!
        }

    }

    static void insertionSortNonincreasing(int *B, int NonincreasingSize)
    {
        for(int j = 1; j < NonincreasingSize; j++)
        {
            int key = B[j];

            int i = j - 1;
            //What is the number we want to move to the right?? The smaller one!!!
            //So check if the # to the left of our key is smaller & if so move it to the right!!!
            while(i >= 0 && B[i] < key)
            {
                B[i + 1] = B[i];
                i--;
            }
            B[i + 1] = key;
        }
    }

    //Exercise 2.2-2: Did this my way so the book's way is just a bit different!!(instead of saving key save index)
    static void selectionSort(int *C, int ArraySizeC)
    {
        for(int i = 0; i < ArraySizeC - 1; i++)
        {
             int key = C[i]; //don't save key, instead save index, b/c by saving key and then swapping there's no
            //way that for in place swaps to work!!???(especially through each iteration in the 2nd for loop?)
            //JK I just did it!!! But pretty sure this is worse b/c more variables are needed in this way!!!!!!!!!
            int jj = i;
            // int j = i + 1;
            for(int j = i + 1; j < ArraySizeC; j++)
            {
                if(key > C[j])
                {
                    key = C[j];
                    jj = j;
                }
            }
            // while(j != (ArraySizeC+1) && key > C[j]) //Can't be while b/c if length fails, no way to j++
            // {
            //     int key = C[j];
            //     j++;
            // }
            C[jj] = C[i];
            C[i] = key;
        }
    }


    static void printArray(int *A, int Arraysize)
    {
        for (int i = 0; i < ArraySize; i++)
        {
            cout << A[i] << " ";
        }
        /*for (auto x = std::end(A); x != std::begin(A); )
        {
            std::cout <<*--x<< ' ';
        }*/
        cout << endl;
    }
};

int main() //no int on this main I guess????
    {
        // int *Arr = new Arr[5];
        InsertionSort x;
        //x.printArray(x.A);  //I think class variables are only private!! Constructor variables are public!!??????
        //insertionSort(A, ArraySize);
        //printArray(A);
        return 0;
    }