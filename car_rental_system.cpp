#include <iostream>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <Windows.h> // can only run on windows consoles
#include <conio.h>
#include <stdio.h>
#include <cstdio>
#include <cstring>
#include<time.h>
#include<cctype>
#include<cstdlib>

using namespace std;

void adminLogin();

void CheckPreviousBooking();

void menu();

void loading();

void changePass();

void bookingMenu();

//class to input user data

class user{

    public:

//long long long int coz length of integer 10 digits
    long long int phone;
    string username;
    string fname;
    string lname;
    char* password;
    string mail;
    int age;

    friend void login();
    friend int checkPass(user obj);
    friend void choices(user obj);
    friend int checkMail(user obj);
    friend void signUp(user obj);

};

//structure to get value of various car details from the admin

struct car
{

char plateno[20]; //plate number minimum 6 letters
char brand[20];
char model[20];
int capacity;
char color[20];
float RatePhour;
float RatePhday;
float RatePday;

};

//structure to get value of various driver details from the admin

struct driver
{

char name[20];
int age;
int phoneno;
int aadharno;
float rating;

};

struct booking
{
    char carPlateno[20];
    char driverName[20];
    char bookingDate[20];
    int bookedForhours;
};

int checkMail();

int checkPass(user obj);

void login(user obj);

void signUp(user obj){

    cout<<"Enter first name :";
    cin>>obj.fname;

    cout<<"Enter Last name :";
    cin>>obj.lname;

    cout<<"Enter Phone Number :";
    cin>>obj.phone;

    cout<<"Enter username: ";
    cin>>obj.username;

    cout<<"Enter password: ";
    cin>>obj.password;


    if(checkPass(obj)==1){
        cout<<"Minimum Password Length is 6 characters.Retry again!!!\n\n"<<endl;
        menu();
    }
    else{

        cout<<"Enter your email address: ";
        cin>>obj.mail;

        if(checkMail(obj)==0){
            cout<<"Invalid mail"<<endl;
            menu();
        }
        else{
        cout<<"Enter age:";
        cin>>obj.age;

        char* filename;

        ofstream myFile;

        myFile.open(obj.username + ".txt");

        myFile<<"UserName : "<<obj.username<<endl;
        myFile<<"Password : "<<obj.password<<endl;
        myFile<<"First Name : "<<obj.fname<<endl;
        myFile<<"Last Name : "<<obj.lname<<endl;
        myFile<<"Phone Number : "<<obj.phone<<endl;
        myFile<<"E-Mail : "<<obj.mail<<endl;
        myFile<<"Age : "<<obj.age;

        myFile.close();
        }

    }

}
int checkPass(user obj){

    int a;
    a = strlen(obj.password);
    if(a<6){
        return 1;
    }
    else
        return 0;
}

int checkNewpass(string a){

    int b;
    b = a.length();
    if(b<6){

        return 1;

    }
    else
        return 0;

}

void login(){

    string userN;
    string str[100];
    string match;
    string pass;
    cout<<"Enter your username  : ";
    cin>>userN;
    cout<<"Enter your password : ";
    cin>>pass;
    fstream file;
    file.open(userN + ".txt",ios::in);
    if(file.is_open()){
        // file>>str[0]>>str[1]>>str[2]>>str[3]>>str[4]>>str[5];
        int i = 0;
        while(!file.eof()){
            file>>str[i];
            i++;
        }

        int c = pass.compare(str[5]);
        if(c==0){
            cout<<"LOGIN SUCCESSFULL"<<endl;
            file.close();
            bookingMenu();
        }
        else{

            cout<<"INCORRECT USERNAME OR PASSWORD!!!!!"<<endl;
            login();

        }


    }
    else{

        cout<<"Username doesn't exist"<<endl;
        login();

    }

}


/*Template - cout<<"LOADING";
            loading();
            cout<<endl;*/


void choices(int i,user obj){
    switch(i){

        case 1:{
            cout<<"LOADING";
            loading();
            cout<<endl;
            //clrscr();
            signUp(obj);
            break;
        }

        case 2: {
            cout<<"LOADING";
            loading();
            cout<<endl;
            //clrscr();
            login();
            break;
            }

        case 3: {
            adminLogin();
            break;
        }

        case 4: {
            changePass();
            break;
        }

        case 5: {
            exit(0);
            break;
        }

        case 6: {
            char s1[] = "temp.txt";
            string str;
            str = "new.txt";
            char s2[7];
            strcpy(s2,str.c_str());
            rename(s2, s1);
            break;
        }


        default:{
            cout<<"\nEnter a Valid choice.\n"<<endl;
            menu();
            break;
        }

    }
}

void menu(){

    int choice;
    user cust1;
    cout<<"1. New User sign up"<<endl;
    cout<<"2. Existing user login"<<endl;
    cout<<"3. Admin Login"<<endl;
    cout<<"4. Change User Password"<<endl;
    cout<<"5. Exit"<<endl;
    cout<<"Enter your choice(1/2/3/4/5) :";
    cin>>choice;
    choices(choice,cust1);

}

int checkMail(user obj){

    char c = '@';
    if(obj.mail.find(c)!=string::npos){
        return 1;
    }
    else
        return 0;

}

void changePass(){

    string userN;
    string pass;
    string newpass;
    string str2[200];
    int count = 0;
    cout<<"Enter your username : ";
    cin>>userN;

    cout<<"Enter your password : ";
    cin>>pass;
    fstream file;
    file.open(userN + ".txt",ios::in);
    string filename = userN + ".txt";
    if(file.is_open()){
        int j=0;
        while(!file.eof()){
            file>>str2[j];
            j++;
            count++;
        }
    }
    else{
        cout<<"Incorrect username or password!!!!"<<endl;
        cout<<"LOADING";
        loading();
        cout<<endl;
        menu();
    }
    if(pass.compare(str2[5])==0){

        cout<<"Enter New password : ";
        cin>>newpass;
        if(checkNewpass(newpass)==0){

            ofstream myFile;
            myFile.open("temp.txt",ios::out);

            int i = 0;
            for(i=0;i<count;i++){
                if(i==5){
                    str2[i]=newpass;
                    myFile<<str2[i]<<endl;;
             }
                else if(i==2 || i==9 || i==13 || i==17 || i == 20 || i == 23){
                    myFile<<str2[i]<<endl;
                }
                else{
                    myFile<<str2[i]<<" ";
                }
          }
          file.close();
          myFile.close();
          char tmp[100];
          strcpy(tmp, filename.c_str());
          remove(tmp);
          rename("temp.txt",tmp);
     }

}
    else{
        cout<<"Incorrect username or password!!!!"<<endl;
        cout<<"LOADING";
        loading();
        cout<<endl;
        menu();
    }
}

void loading(){
    int i;
    for(i =0;i < 6 ; i++){
        cout<<".";
        Sleep(300);
    }
}

int dist_calc (){
    srand((unsigned) time(NULL));
    int random = 0 + (rand() % 101);
    return random;
}

float pr_calc (int dist1){
  float gst = 18.0/100.0;
  float pr = (dist1*10) + (dist1*10*gst) ;
  return pr;
}

void newBooking(){
  int x=1;
    while (x>0)
    {
        char carch;
        string fn, ln, dest,pno;
        float dist, prc;
        cin.ignore ();
        cout << "Please enter your Username" << endl;
        getline (cin, fn);
        cout << "Please enter your NAME" << endl;
        getline (cin, ln);
        cout << "Please enter your destination" << endl;
        getline (cin, dest);
        cout<<"Please enter your phone number for driver to contact (max 10 numbers)"<<endl;
        getline(cin,pno);
        dist = dist_calc ();
        cout <<"Calculated distance between starting point and destination is : "<< dist << endl;
        prc = pr_calc (dist);
        cout << endl;
        cout << "Price is Calculated as per The norms below";
        loading();
        cout << endl;
        cout << "Price = Rs10/Kilometre + GST"<<endl;
        cout << "GST=18%" << endl;
        cout << "Your total Bill for the trip will be approximately :" <<
        prc << endl;
        cout << endl;
        cout << "Do You want to Confirm The trip?(y/n)";
        cin >> carch;
        if (toupper (carch) == 'Y')
        {
            cout << "Please wait Checking for Available drivers";
            loading();
            string bdg;
            string car_av;
            fstream vfile;
            vfile.open("Car_availability.txt",ios::out |ios::in);
            cout<<"Drivers on duty are :-"<<endl;
            cout<<"Badge status Name   Vehcile"<<endl;
            while(getline(vfile,car_av)){
              if(car_av[7] =='n'){
                  cout<<car_av<<endl;
              }
              else{
                  continue;
              }
            }
            vfile.close();
            cout<<"Please input the badge number of driver for confirming ride"<<endl;
            cin>>bdg;
            cout<<"Your Ride is booked with the following driver and Vehcile :-"<<endl;
            cout<<"Badge status Name   Vehcile"<<endl;
            string car_av1;
            string text;
            fstream v2file;
            v2file.open("Car_availability.txt",ios::out |ios::in);
            while(getline(v2file,car_av1))
            {
                if(car_av1[2]==bdg[2]){
                  cout<<car_av1<<endl;
                  text=car_av1;
              }
            }
            v2file.close();
            cout<<"Saving your booking details";
            loading();
            ofstream v3file;
            v3file.open("Bookingsfor" + fn + ".txt");
            v3file<<"Personal details- \n"<<fn<<'\t'<<ln<<'\t'<<pno<<endl;
            v3file<<"Driver Details- \n"<<text;
            v3file.close();
            break;
          
          }
          else if(toupper (carch) == 'N'){
              continue;
          }
      }
}
void bookingMenu(){
  int choose;
  cout<<"\t\t\t\t BOOKING MENU \t\t\t\t"<<endl;
  cout<<"1. New Booking "<<endl;
  cout<<"Enter your choice (1): ";
  cin>>choose;
  switch(choose){
    case 1: {
      newBooking();
      break;
    }
    case 2: {
      //carAvail();
      break;
    }
    default: {
      cout<<"Invalid choice!!!Please enter a valid choice"<<endl;
      cout<<"LOADING";
      loading();
      menu();
      break;
    }
  }
}
void enterBooking()
{
    struct booking booking1;
    cout<<"Enter car plate no.: "<<endl;
    cin>>booking1.carPlateno;
    cout<<"Enter driver name: "<<endl;
    cin>>booking1.driverName;
    cout<<"Enter booking date: "<<endl;
    cin>>booking1.bookingDate;
    cout<<"Enter booking duration in hours: "<<endl;
    cin>>booking1.bookedForhours;

    FILE *fp6;
    fp6=fopen("Bookings.txt", "a");
    fwrite(&booking1,sizeof(struct booking),1,fp6);
    fclose(fp6);
    CheckPreviousBooking();
}

void CheckPreviousBooking()
{
    int oho;
    cout<<"would you like to enter a booking entry? if yes type 1 if no type 2. "<<endl;
    cin>>oho;
    if(oho==1)enterBooking();
    else if(oho==2){
    struct booking booking[100];

    FILE *fp5;
    fp5=fopen("Bookings.txt","r");
    for(int i=0;i<100;i++)
    {
        while(fread(&booking[i],sizeof(struct booking),1,fp5))
        {
            cout<<"Booking entry no. "<<i+1<<endl;
            cout<<"Car plate no.: "<<booking[i].carPlateno<<endl;
            cout<<"Driver Name: "<<booking[i].driverName<<endl;
            cout<<"Booking date: "<<booking[i].bookingDate<<endl;
            cout<<"Booking duration in hours: "<<booking[i].bookedForhours<<endl;
        }
    }
    fclose(fp5);
  menu();
    }
}

void enterCarDetails()
{
    struct car car1;
    cout<<"enter car plate no.: "<<endl;
    cin>>car1.plateno;
    cout<<"enter car brand: "<<endl;
    cin>>car1.brand;
    cout<<"enter car model: "<<endl;
    cin>>car1.model;
    cout<<"enter car capacity: "<<endl;
    cin>>car1.capacity;
    cout<<"enter car color: "<<endl;
    cin>>car1.color;
    cout<<"enter car rate per hour: "<<endl;
    cin>>car1.RatePhour;
    cout<<"enter car rate per half day: "<<endl;
    cin>>car1.RatePhday;
    cout<<"enter car rate per day: "<<endl;
    cin>>car1.RatePday;

    FILE *fp;
    fp=fopen("CarDetails.txt", "a");
    fwrite(&car1,sizeof(struct car),1,fp);
    fclose(fp);
    adminLogin();

}

void EnterDriverDetails()
{
    struct driver driver1;
    cout<<"Enter driver name: "<<endl;
    cin>>driver1.name;
    cout<<"Enter driver age: "<<endl;
    cin>>driver1.age;
    cout<<"Enter driver phone no.: "<<endl;
    cin>>driver1.phoneno;
    cout<<"Enter driver aadhar no: "<<endl;
    cin>>driver1.aadharno;
    cout<<"Enter driver rating: "<<endl;
    cin>>driver1.rating;

    FILE *fp3;
    fp3=fopen("DriverDetails.txt", "a");
    fwrite(&driver1,sizeof(struct driver),1,fp3);
    fclose(fp3);
    adminLogin();

}

void adminLogin()
{
    int hmm;
    cout<<"Would you like to go to Bookings section? If yes type 1 if not type 2. If you want to go to driver details type 3. "<<endl;
    cin>>hmm;
    if(hmm==1)CheckPreviousBooking();

    else if(hmm==2){
    int qwerty;
    cout<<"would you like to enter car details? if yes type 1 if not type 2. "<<endl;
    cin>>qwerty;
    if(qwerty==1)enterCarDetails();

    struct car car[50];

  FILE *fp;
  fp=fopen("CarDetails.txt","r");
  for(int i=0; i<50; i++)
  {
      while(fread(&car[i],sizeof(struct car),1,fp))
        {
            cout<<"Car no. "<<i+1<<endl;
            cout<<"Plate no.: "<<car[i].plateno<<endl;
            cout<<"model: "<<car[i].model<<endl;
            cout<<"color: "<<car[i].color<<endl;
            cout<<"Rate per hour: "<<car[i].RatePhour<<endl;
            cout<<"Rate per half day: "<<car[i].RatePhday<<endl;
            cout<<"Rate per day: "<<car[i].RatePday<<endl;
        }
  }
  fclose(fp);}
    else if(hmm==3){
  struct driver driver[50];

  int wow;
  cout<<"would you like to enter driver details? if yes type 1 if not type 2. "<<endl;
  cin>>wow;
  if(wow==1)EnterDriverDetails();
  FILE *fp2;
  fp2=fopen("DriverDetails.txt", "r");
  for(int i=0;i<50;i++)
  {
      while(fread(&driver[i],sizeof(struct driver),1,fp2))
      {
          cout<<"Driver no. "<<i+1<<endl;
          cout<<"Driver name: "<<driver[i].name<<endl;
          cout<<"Driver age: "<<driver[i].age<<endl;
          cout<<"Driver phone no.: "<<driver[i].phoneno<<endl;
          cout<<"Driver aadhar no.: "<<driver[i].aadharno<<endl;
          cout<<"Driver rating: "<<driver[i].rating<<endl;
      }
  }
  fclose(fp2);
  menu();}
}

int main(){

    cout << "\t\t\t\t WELCOME TO CAR RENTAL SYSTEM\t\t\t\t\n";
    menu();
    return 0;

}
