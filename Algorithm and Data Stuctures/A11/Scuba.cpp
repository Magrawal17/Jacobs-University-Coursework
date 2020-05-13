#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int dp[1000][21][79];
int INF=801;        //no need to set sth too high as 800 is the max weighr possible
int oxy[1000],nitro[1000],weight[1000];

int main()
{
    int numberoftestcase ,oxyvol,nitrovol,numcylinder;
    
    ifstream input;
    input.open("input3.txt");
    input>>numberoftestcase;
    
    for (int i = 0; i < numberoftestcase; i++)
    {
        input>>oxyvol;
        input>>nitrovol;
        input>>numcylinder;

        for (int j = 0; j < numcylinder; j++)
        {
            input>>oxy[j];
            input>>nitro[j];
            input>>weight[j];
        }
        //cout<<minweight(numcylinder,oxyvol,nitrovol)<<endl;
       
        for (int i = 0; i < numcylinder; i++)
        {
            for (int j = 0; j <= oxyvol; j++)
            {
                for (int k = 0; k <= nitrovol; k++)
                {
                    dp[i][j][k] = INF;      //setting everything to max;

                    if ((j == 0) && (k == 0))           //honestly dont thing as too necessary works without it as well
                    {
                        dp[i][j][k] = 0;           //fing the first row and column of number of cylinder matirx  to 0;
                    }
                }
            }
        }


        for (int j = 0; j <= oxyvol; j++)
        {
            for (int k = 0; k <= nitrovol; k++)
            {
                if (j <= oxy[0] && k <= nitro[0])
                {
                    dp[0][j][k] = weight[0];            //just filling the first activity with the weight if it satisfies the conditon
                }                                         
            }   
        }
      

        for (int i = 1; i <= numcylinder; i++)         //this time we start from one as 0th activity already filled
        {
            for (int j = 0; j <= oxyvol; j++)
            {
                for (int k = 0; k <= nitrovol; k++)
                {
                    dp[i][j][k] = dp[i-1][j][k];      //filling it with the value behind it at first
                       
                    if ((j <= oxy[i]) && (k <= nitro[i]))   //add more in the current cyclinder if there is still nitro and oxy availaible         
                    {
                        dp[i][j][k] = min(dp[i][j][k],weight[i]);
                    }
                    else    
                    {
                        dp[i][j][k] = min(dp[i][j][k], weight[i] + dp[i-1][max(0,j-oxy[i])][max(0,k-nitro[i])]);    //esle consider the remainng scenarios        
                    }   
                }
            }
        }
        cout << dp[numcylinder-1][oxyvol][nitrovol] << endl;    //the last answer is our value
    }
    input.close();
    
    vector<int> print;
    do
    {
            if (dp[numcylinder][oxyvol][nitrovol] != dp[numcylinder - 1][oxyvol][nitrovol])
            {
                oxyvol = oxyvol - oxy[numcylinder];
                //oxyvol = max(oxyvol, 0);          //I dont think neccesary as values would logically never below 0 in our case
                nitrovol = nitrovol - nitro[numcylinder];
                //nitrovol = max(nitrovol, 0);      
                print.push_back(numcylinder + 1);
            }
            numcylinder = numcylinder - 1;
    } while (numcylinder >= 0);

    vector<int>::reverse_iterator it;
    for (it = print.rbegin(); it != print.rend(); it++)
    {
            cout << *it << " ";
    }
    cout<<endl;
}