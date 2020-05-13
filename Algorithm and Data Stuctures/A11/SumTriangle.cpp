#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


int main()
{
    ifstream input;
    input.open("input2.txt");
    string line;
    int numberofline=0;
    while (!input.eof())        //finding out the number of lines
    {
        getline(input, line);
        numberofline++;
    }
    input.close();
    input.open("input2.txt");
    int arr[numberofline][numberofline];        //creating a n*n matrix for it
    while (!input.eof()){
    for(int i = 0; i < numberofline; i++) 
    {
        for (int j = 0; j <= i; j++) 
        {
                input >> arr[i][j];
        }
    }
    }
    input.close();
    
    //try created another function but creates error when supplying 2*2 matrix as parameter
    int n=numberofline;

    int sum[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            sum[i][j]=arr[i][j];            //creating another array that has only sums
        }
    }

    for (int i = n-2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            if (sum[i][j] + sum[i+1][j] >sum[i][j] +sum[i+1][j+1])  
            {                                           //finding total sum by conisdering whether adding the left or right reuslts higher sum
                sum[i][j] += sum[i+1][j];       
            }
            else
            {
                sum[i][j] += sum[i+1][j+1];
            }
        }
    }
    cout<<sum[0][0]<<endl;          //total maximum sum will be the first element as it bottom up approach

    int temp = 0;
    for (int i = 0; i < n; i++) {
        if (sum[i][temp] < sum[i][temp + 1]) {      //finding max sum in each level         
            temp++;
        }
        cout << arr[i][temp] << " ";            //generating path
    }
    cout << endl;
}