#include <iostream>
#include <vector>

using namespace std;

/**
    You are given a range of integers (A,B) where A and B are inclusive. Create a function that will return
    the number of prime numbers in that given range. For the range (11,19) the function should return 4.
*/
int PrimeCount(int A, int B)
{
    int numPrimes = 0;
    int nonDevisibleNum = -1;
    vector <int> primeNums;

    //Checks all numbers in the given range
    for(int c = A; c <= B; c++)
    {
        if(c%1 == 0 && c%c == 0)
        {
            nonDevisibleNum = c;
            cout << c << " could be prime "<< endl;

            for(int a = 2; a < B; a++)
            {
                if(a != c)
                {
                    //Checks if they are not devisible by every other number in the same range
                    if(c%a != 0)
                    {
                        //cout << c << "%" << a << " = "<< c%a << endl;
                        nonDevisibleNum = c;
                    }

                    if (c%a == 0)
                    {//Checks if the number that the numbers that c is devisible isitself
                        cout << c << "%" << a << " = "<< c%a<< endl;
                        nonDevisibleNum = -1;
                        break;
                    }
                }
            }
        }

        //Checking if nonDevisibleNum stores a positive number in the range given
        cout <<"nonDevisibleNum is " << nonDevisibleNum <<"\n" << endl;

        //if at this point nonDevisibleNum is -1 then the number is not prime
        if(nonDevisibleNum >= A)
        {
            numPrimes++;
            //cout << "adding prime " << nonDevisibleNum << endl;
            primeNums.push_back(nonDevisibleNum);
        }else if(nonDevisibleNum == -1 )
        {
            //nothing happens
        }

        cout << "Current Prime Nums: ";
        for(int c = 0; c < primeNums.size(); c++)
        {
            cout << primeNums.at(c) << ", ";
        }
        cout << " \n\n";
    }

    return numPrimes;
}

/**
    You are given the vector A which stores positive numbers. Example vectors and results are [25, 30, 10, 18, 1] -> result 30 - 25 = 5;
    [24,17,8,1,3] -> 3-1 = 2; [3,3,7,7,21,42] -> 3-3 = 0 and 7-7 = 0
    Create a function that will return the smallest distance between the given elements in the vector.
*/
int CalcDistance(vector<int> &A)
{
    int smallestDist;
    bool swap = true;
    int temp;

    //Bubble sort
    while(swap)
    {
        swap = false;

        for(int c = 0; c < A.size()-1; c++)
        {
            if(A.at(c) > A.at(c+1))
            {
                temp = A.at(c+1);
                A.at(c+1) = A.at(c);
                A.at(c) = temp;
                swap = true;
            }
        }
    }

    for (int c = 0 ; c < A.size(); c++){
        cout << A.at(c) << " ";
    }
    cout << "\n";

    //Getting the distance between the smallest numbers in the vector
    smallestDist = A.at(1) - A.at(0);

    //Since I already have the distance between the first and the second I start checking from index 1
    for(int c = 1; c < A.size()-1; c++)
    {
        //Since the numbers in the vector go from smallest to biggest,
        //I'm getting the distance by subtracting the number at the current index
        //from the number at the next index and checking if it's smaller than smallestDist
        if(A.at(c+1) - A.at(c) < smallestDist)
        {
            smallestDist = A.at(c+1) - A.at(c); //Reassigning smallestDist
        } //else nothing changes
    }//repeating until the end of the vector

    return smallestDist;
}


/**
    (N,M) are Q - rounds because (N*N) + (M*M) = Q.
    Examples of rounds/pairs:(0,0) is a 0-round;
    (0,1), (1,0), (-1, 0) and (0, -1) are 1-pairs because 0*0 + -1*-1 = 0+1 = 1 so the number of 4;
    (1,1), (-1,-1), (-1,1), (1, -1) are 2-pairs because -1*-1 + -1*-1 = 1+1 = 2 so the number of 2 pairs is 4;
    Find all possible pairs/rounds for a given number.
*/
int IntPairing(int Q)
{
    int numPairs = 0;

    //the condition must be <= Q because its inclusive
    //if it's not <= Q and Q is 1 it says the pairs are 2 because it only checks -1, 0 for pairs but 1 is a pair too
    //no matter how unlikely in most cases that is.
    for(int count = -Q; count <= Q; count++)
    {
        for(int c = -Q; c <= Q; c++)
        {
            if((count*count) + (c*c) == Q)
            {
                numPairs++;
                cout << "("<<count<<", " <<c << ") => " << Q <<endl;
            }
        }
    }

    return numPairs;
}

int main()
{
    vector <int> a;
    a.push_back(25);
    a.push_back(30);
    a.push_back(10);
    a.push_back(18);
    a.push_back(1);

    cout << "Number of primes in the given range is:  "<<PrimeCount(11, 19) << endl;
    IntPairing(10);
    cout << "Distance:  "<< CalcDistance(a);

    return 0;
}
