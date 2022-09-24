#include <iostream>
#include <iomanip>
#include <cstring>
void search_passenger();//forward declaration
int check;// global variable
using namespace std;
#define size 100
class indigo
{
private:
string fname, lname;
long int phone_no;
int ID, reserve_num, seat_num;
public: static int reserve;//static variable to keep count of passengers
indigo(); //default constructor
indigo(string, string,long int,int,int,int); //parametrized constructor
indigo(const indigo &obj); //copy constructor
static void getcount();//static function to access static variable
void make_reservation(); // To make reservation.
void print_list(indigo*); //To print the passenger list.
void print_report(); //To print the status report. inline function
friend void search_passenger(indigo*); //friend function
friend class B; //friend class
~indigo(); //default constructor
/*indigo operator + (indigo const &obj)
{
indigo res;
res.price = price + obj.price;
return res;
} //operator overloading function ,adding price values of different objects using +
overloading*/
};
int indigo::reserve=0;
indigo::~indigo()
{
cout<<"destructor invoked explicitly"<<endl;
}
//default constructor
indigo::indigo()
{
fname="Saurabh/o";
lname="Hulyal/o";
phone_no= 8600997540;
ID=27;
reserve_num=24;
seat_num=34;
}
//Parameterized Constructor
indigo::indigo( string a, string b,long int c,int d, int e,int f)
{
char* strcpy(char* fname, const char* a);
char* strcpy(char* lname, const char* b);
phone_no=c;
ID=d;
reserve_num=e;
seat_num=f;
}
//copy constructor
indigo::indigo(const indigo &f)
{
ID=f.ID;
}
//initialise seats with unoccupied state
int seat[size];
void seat_fill()//not a member function
{
for (int i = 0; i < size; i++)
{
seat[i] = 0;//initial condition, all seats are unoccupied
}
}
//****
bool taken=false;
void seat_no(int y)
{
for (int i = 0; i < size; i++ ) //loop checks if the seat is taken or not.
{
if( seat[i] == -1 )
{
taken=true;
cout << "The seat is taken already. \n";
cout << "Please choose another seat number from below."<<endl;
int j = 1;
while ( j < size+1 )
{
if ( seat[j-1] == -1)
j++;
else
{
cout <<"|" << j << "|";
if ( j%10 == 0 )
cout << endl;
j++;
}
}
}
}
} // this will print the available seat numbers only
//static function to access static variable
void indigo::getcount()
{
check=reserve;
}
void menu(indigo* passenger)
{
char choice;
int i=0;
do{
cout <<"\t\t ------------------------------ \n";
cout <<"\t\t Make Reservation ...... '1' \n";
cout <<"\t\t ------------------------------ \n";
cout <<"\t\t Search Passenger ...... '2' \n";
cout <<"\t\t ------------------------------ \n";
cout <<"\t\t Print a list ...... '3' \n";
cout <<"\t\t ------------------------------ \n";
cout <<"\t\t Print status Report ...... '4' \n ";
cout <<"\t\t ------------------------------ \n";
cout <<"\t\t Quit ...... '5' \n ";
cout <<"\t\t ------------------------------ \n";
cout <<"::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
cout <<"\n Option :: ";
cin >> choice;
choice = ((int)(choice)-48);
switch (choice) //starting casefn1353.
{
case 1: system("CLS"); passenger[i].make_reservation();
i++;
break;
case 2: system("CLS"); search_passenger( passenger);
// break;
case 3: system("CLS"); passenger[i].print_list(passenger);
// break;
case 4: system("CLS"); passenger[i].print_report();
break;
case 5: cout << "\n\n you are out of the management system\n\n\n";
break;
default: cout<<" Invalid choice \n\n";
break;
} // Ending case loop.
} while(choice != 5);
}
void indigo::make_reservation() //This function makes reservation.
{
int x;
cout<<"\n\nEnter First Name: ";
cin>>fname;
cout<<"--------------------------------\n";
cout<<"Enter Last Name: ";
cin>>lname;
cout<<"--------------------------------\n";
cout<<"Enter ID of the person: ";
cin>>ID;
cout<<"--------------------------------\n";
cout<<"Enter Phone Number of Person: ";
cin>>phone_no;
cout<<"--------------------------------\n";
do{
cout << "Please Enter the Seat Number: ";
cin>>x;
while(x>size){
cout<<" Try again:: ";
cin >>x;
}
cout<<"--------------------------------\n";
if((seat[x-1])>-1) // if seat value is 0 and more than it's is empty
taken = false;
else //cp
seat_no(x); // if taken print available seat from another function
seat[x-1] = -1; // make current seat unavailable as -1 value representation
seat_num = x;
}while(taken==true);
reserve++; //increments the reservation numbers
getcount();
reserve_num=reserve;
cout <<"\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
cout << "YOUR RESERVATION NUMBER IS :: " << reserve << "\n\n";
cout <<"::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
}
void search_passenger(indigo* passenger) //This function helps to search a passenger
{//either by first name
string searchname;
cout << "Please enter your first name here: ";
cin >> searchname;
int i=0;
int flag=0;
while (passenger != NULL && i<check)
{
if (passenger[i].fname == searchname) //found
{
flag=1;
cout << "First Name : " <<passenger[i].fname << endl;
cout << "Last Name : " << passenger[i].lname << endl;
cout << "ID " << passenger[i].ID << endl;
cout << "Phone number: " << passenger[i].phone_no << endl;
cout << "seat Number: " << passenger[i].seat_num << endl;
cout << "Reservation No. " << passenger[i].reserve_num<<
endl;
return;
}
i=i+1;
}
if (flag==0)
cout << " Sorry!!! NOT FOUND \n\n";
}
void indigo:: print_list(indigo* passenger) //This function prints the list of the passengers.
{
int i=0;
if(passenger == NULL)
cout<<" End of lists"<<endl;
else
{ int cnt = 1;
cout << "\tNumber\t First Name\t Last Name\t ID\t";
cout << "Phone Number\t seat Number\t Reservation No\t Menu\n";
while(passenger != NULL && i<check) // Display details for what temp
points to
{
cout << passenger[i].fname <<endl;
cout << passenger[i].lname << endl;
cout << passenger[i].ID << endl;
cout << passenger[i].phone_no <<endl;
cout << passenger[i].seat_num <<endl;
cout << passenger[i].reserve_num <<endl;
cnt++;
i++;
}
cout << "\n\n";
}
}
//inline function
inline void indigo:: print_report() //This function prints the status report of the flight.
{
int count = 0;
for (int i =0; i < size; i++ )
{
if (seat[i] == -1)
count++;
}
cout<<"The number of reserved seats are: " << count <<endl;
}
int main()
{
system("CLS"); // clean the terminal
cout<<"\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
cout << "\t WELCOME TO AIRLINE RESERVATION SYSTEM \n";
cout<<":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
cout<<" ..................... MENU OPTIONS .............................\n"<<endl;
seat_fill(); // initialize seat array.
indigo* passenger ;
passenger= new indigo[size];
menu(passenger); //calling the menu function.
return 0;
 }