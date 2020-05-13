#include <iostream>
using namespace std;
// Reference from https://www.geeksforgeeks.org/rabin-karp-algorithm-for-searchtern-searching/

#define d 256 //Range of our character set

void RKA(char search[], char txt[], int q)
{
    int M = strlen(search);
    int N = strlen(txt);
    int p = 0; // hash value for pattern
    int t = 0; // hash value for txt
    int h = 1;
    int j;

    // The value of h would be "pow(d, M-1)%q"
    //Useful for computations later on
    for (int i = 0; i < M - 1; i++)
        h = (h * d) % q;

    // Calculate the hash value of text and first few letters of pattern
    for (int i = 0; i < M; i++)
    {
        p = (d * p + search[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    // Slide the pattern over text one by one
    for (int i = 0; i <= N - M; i++) //N-M as it doesnt make sense to till N when we know they are going to be false
    {

        //Only go on checking if they same hash values
        if (p == t)
        {
            /* Check for characters one by one */
            for (j = 0; j < M; j++)
            {
                if (txt[i + j] != search[j])
                {
                    break;
                }
            }

            //if at the end M and J are same point we can be sure pattern found
            if (j == M)
            {
                cout << "Pattern found at index " << i << endl;
            }
        }

        // Calculate hash value for next window of text: Remove
        // leading digit, add trailing digit
        if (i < N - M)
        {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;

            // We might get negative value of t, converting it to positive
            if (t < 0)
            {
                t = (t + q);
            }
        }
    }
}

int main()
    {
        char txt[] = "LONG COMPLICATED %^^SEARCH";
        char search[] = "%^^";
        int q = 101; // A prime number needed for our hashing fucntion
        RKA(search, txt, q);
        return 0;
    }
