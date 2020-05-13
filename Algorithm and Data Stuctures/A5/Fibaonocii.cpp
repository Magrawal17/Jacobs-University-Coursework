#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int naive(int n)
{
    if (n < 2)
    {
        return n;
    }
    else
    {
        return naive(n - 1) + naive(n - 2);
    }
}
int bottomup(int n)
{
    int arr[n];
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        arr[i] = arr[i - 2] + arr[i - 1];
    }
    return arr[n];
}
int closedup(int n)
{
    double gold = (1 + sqrtl(5)) / 2.0;
    return round(powl(gold, n) / sqrtl(5));
}

int matrix(int n)
{
    int arr[2][2];
    arr[0][0] = 1;
    arr[0][1] = 1;
    arr[1][0] = 1;
    arr[1][1] = 0;
    int Mult[2][1];
    Mult[0][0] = 0;
    Mult[1][0] = 1;
    int temp1;
    int temp2;
    for (int i = 0; i < n; i++)
    {
        temp1 = Mult[0][0];
        temp2 = Mult[1][0];
        Mult[0][0] = arr[0][0] * temp1 + arr[0][1] * temp2;
        Mult[1][0] = arr[1][0] * temp1 + arr[1][1] * temp2;
    }

    return Mult[0][0];
}

int main()
{
    time_t fixed = 1.0;                     //fixed time to 1 seconds for each function
    clock_t begin, end;
    double time_spent;

    int input = 0;
    ofstream out;
    out.open("Naive_Data.txt");
    do
    {
        begin = clock();
        naive(input);
        end = clock();
        time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        out <<input <<" "<<  time_spent << endl;
        input=input+10;
    } while (time_spent < fixed);
    out.close(); 

    ofstream out1;
    out1.open("Bottom_Data.txt");
    input = 0;
    do
    {
        begin = clock();
        bottomup(input);
        end = clock();
        time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        out1<< input << " "  << time_spent << endl;
        input=input+10;
    } while (time_spent < fixed);
    out1.close();
    
    ofstream out2;
    out2.open("Closed_Data.txt");
    input = 0;
    do
    {
        begin = clock();
        closedup(input);
        end = clock();
        time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        out2 << input << " " << time_spent << endl;
        input=input+10;
    } while (time_spent < fixed);
    out2.close();

    ofstream out3;
    out3.open("Matrix_Data.txt");
    input = 0;
    do
    {
        begin = clock();
        matrix(input);
        end = clock();
        time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        out3 << input << " " << time_spent << endl;
        input=input+10;
    } while (time_spent < fixed);
    out3.close();

    return 0;
}
