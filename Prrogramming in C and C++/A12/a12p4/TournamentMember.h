/*
 CH-230-A
 a12_p4.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <cstring>
using namespace std;

class TournamentMember
{
    private:
       char fname[36];
       char lname[36];
       char dob[11];
       string teamname;
       int age;
       static string location;
    public:
        TournamentMember() {cout<<"Empty construcutor being called"<<endl;}
        TournamentMember(const TournamentMember& obj);
        //~TournamentMember() { cout<<"Destructor being called"<<endl;}
        TournamentMember(const char nfname[36],const char nlname[36],const char ndob[36],const string nteamname,const int nage);
        
        void setfname(const char nfname[36]) { strcpy(fname,nfname);}
        void setlname(const char nlname[36]) { strcpy(lname,nlname);}
        void setdob(const char ndob[36]) { strcpy(dob,ndob);}
        void setteamname(const string nteamname) { teamname=nteamname;}
        void setage(const int nage) {age=nage;}

        const char* getfname() const {return fname;}
        const char* getlname() const {return lname;}
        const char* getdob() const {return dob;}
        string getteamname() const {return teamname;}
        int getage() const { return age;}
        string getlocation() const{return location;}

        void print() const;
        static void clocation(const string nlocation);
};

class Player : public TournamentMember 
{
    private:
        int number;
        string position;
        int goals;
        string foot;
    public:
        Player():TournamentMember(){cout<<"Empty Constructor being called"<<endl;}
        //~Player(){cout<<"Destructor being called"<<endl;}
        Player(const Player& obj);
        Player(const char nfname[36],const char nlname[36],const char ndob[36],const string nteamname,const int nage,int nnumber,string nposition,int ngoals,string nfoot);

        void setnumber(const int nnumber){number=nnumber;}
        void setposition(const string nposition){position=nposition;}
        void setfoot(const string nfoot){foot=nfoot;}

        int getnumber()const {return number;}
        string getposition()const {return position;}
        string getfoot()const {return foot;}
    
        void print()const;
        void increment(int num);
};

class Referee : public TournamentMember
{
    private:
        int yellowCardCount;
        Player *yellowCardList[40];
        int redCardCount;
        Player *redCardList[40];
    public:
        Referee();
        Referee(const char nfname[36],const char nlname[36],const char ndob[36],const string nteamname,const int nage);
        bool addToYellowCardList(Player *p);
        bool addToRedCardList(Player *p);
        void print() const;

};

inline TournamentMember::TournamentMember(const TournamentMember& obj)
{
    cout<<"Copy construcotr being called"<<endl;
    strcpy(fname,obj.fname);
    strcpy(lname,obj.lname);
    strcpy(dob,obj.dob);
    teamname=obj.teamname;
    age=obj.age;
}

inline Player::Player(const Player& obj): TournamentMember(obj)
{
    number=obj.number;
    position=obj.position;
    goals=obj.goals;
    foot=obj.foot;
}
inline Referee::Referee(const char nfname[36],const char nlname[36],const char ndob[36],const string nteamname,const int nage)
:TournamentMember(nfname,nlname,ndob,nteamname,nage)
{
     yellowCardCount=0;
     redCardCount=0;
}
