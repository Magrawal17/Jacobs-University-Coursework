/*
 CH-230-A
 a12_p2.c
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
        ~TournamentMember() { cout<<"Destructor being called"<<endl;}
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

inline TournamentMember::TournamentMember(const TournamentMember& obj)
{
    cout<<"Copy construcotr being called"<<endl;
    strcpy(fname,obj.fname);
    strcpy(lname,obj.lname);
    strcpy(dob,obj.dob);
    teamname=obj.teamname;
    age=obj.age;
}
