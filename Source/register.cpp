

/*
Register system for console games by Sreyas

*/
//global vars
int data_size,_logined=0,_connected=0,P_INDEX;//saving data size in a var is much more optimised than use tellg()
//global functions
void Register();

void Login();

void Save();

void connect();

//class for storing player data

class P_DATA
{
 public:
 char name[24],password[24];
 int pscore;

 P_DATA()
 {
  pscore = 0;
 }

 void P_GET()
 {
  cout<<"Input your name ";
  gets(name);
  cout<<"Input password ";
  gets(password);
 }

 ~P_DATA()
 {

 }

};



////////////////////////////////////////////////////////////////////////////
