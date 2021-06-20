#include <iostream>
#include <vector>

using namespace std;

/*A binary gap within a positive integer N is any maximal sequence of consecutive zeros that is surrounded by ones at both ends in the binary representation of N.
For example, number 9 has binary representation 1001 and contains a binary gap of length 2. The number 529 has binary representation 1000010001 and contains two binary gaps:
one of length 4 and one of length 3. The number 20 has binary representation 10100 and contains one binary gap of length 1. The number 15 has binary representation 1111 and has no binary gaps.
Write a function:  int solution(int N);  that, given a positive integer N, returns the length of its longest binary gap. The function should return 0 if N doesn't contain a binary gap.
For example, given N = 1041 the function should return 5, because N has binary representation 10000010001 and so its longest binary gap is of length 5.*/

/**
 * Converts an integer to a binary number.
 * Parameters:
 * int N - the number the user wishes to convert;
 * vector <int> &binary - stores the digits of the binary equivalent of N.
 */
void convertToBinary(int N, vector <int> &binary)
{
    int bit = 0;
    int counter = 0;

    cout << "The binary equivalent of "<< N <<" is ";
    while(N != 0)
    {
        bit = N%2;
        binary.push_back(bit);
        N = N/2;

        cout << binary[counter];
        counter++;
    }
    cout << "\n";
}


/**
 * The length of a binary gap is number of consecutive 0s in a binary number.
 * Binary Gaps must be surrounded by 1s on both sides.
 * Parameters:
 * int N - positive decimal number.
 */
int getLongestGap(int N)
{
    vector <int> binary;
    int longestGap = 0;
    int temp = 0;

    convertToBinary(N, binary);

    for(int c = 0; c < binary.size()-1; c++)
    {
        if(binary[c] == 1)
        {
            while(binary[c+1] != 1)
            {
                temp++;
                c++;
            }

            if(temp >= longestGap)
            {
                longestGap = temp;
            }
            temp = 0;
        }
    }

    return longestGap;
}


int main()
{
    int gap = getLongestGap(1041);
    cout << "The longest binary gap is " << gap << endl;

    return 0;
}
