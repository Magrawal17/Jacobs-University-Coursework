/*
CH-230-A
a9_p10.cpp
Mahiem Agrawal
m.agrawal@jacobs-university.de
*/

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    Start:
    string words[17]={"computer","television","keyboard", "laptop","mouse","hello","world","these","are","the","only","words","i","know","right","now","sorry"};
    int randomNumber;
    string user_input;
    int count=0;
    srand (static_cast <unsigned int>(time (0)));
    randomNumber = rand () ;
    randomNumber = (randomNumber % 17);
    string randomword=words[randomNumber];
    string temp=randomword;
    for (unsigned int i = 0; i < randomword.length(); i++)
    {
        if (randomword[i]=='a' ||randomword[i]=='e' ||randomword[i]=='i' ||randomword[i]=='o' ||randomword[i]=='u')
        {
            temp[i]='_';
        }
    }
   
    while(1)
    {
        cout<<"The word to be guessed is"<<endl;
        cout<<temp<<endl;
        cout<<"Try guessing the word"<<endl;
        cin>>user_input;
        count=count+1;
        if (user_input=="quit")
        {
            cout<<"Thank you for trying my program"<<endl;
            exit(1);
        }
        if (user_input==randomword)
        {
            cout<<"You solved the program in "<<count<<" tries"<<endl;
            cout<<"Do you want to play again, Yes or No"<<endl;
            string ans;
            cin>>ans;
            if (ans=="Yes")
            {
                goto Start;
            }
            else
            {
                break;
            }
        }
        
    }
    
    return 0;
}