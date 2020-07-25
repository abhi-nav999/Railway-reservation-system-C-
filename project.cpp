#include<iostream>  //features to be added transactions of user(to be stored in a linked list,display trains data store in a linked list and sort them according to hours and display them,about us ,emergency enquiry,feedback.
#include<conio.h>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<iomanip>  //has function setw-USED SET WIDTH IN MAKING OF A TABLE
#include<windows.h>  //for use of SetConsoleTextAttribute(to set bg colour)
#include<time.h>     //contains time and date function declarations
using namespace std;
//LINEKD LIST TO STORE TRAIN DATA
struct node
{
    int train_no;
    char sour_Stat[50];
    int station_n;
    //char desti_Stat[50];
    int hour;
    int minut,seat1,fare1,seat2,fare2,date,month,year;
    struct node* next;
};
struct node* rear;  //pointer to rear of linked list
//class store data in a linked list
class store_LL  //linked list
{
    //struct node* head=NULL;

public://insertion at front
    void store(struct node** head,int t_no,char source[],int hours,int minute,int fare,int seats,int seats2,int sc_fare,int stationno,int date,int month,int year)
    {
        struct node* temp=new(nothrow)struct node;
        if(*head==NULL)
        {
            temp->next=NULL;
            rear=temp;
        }
        else
        {
        //cout<<"2";
        temp->next=*head;}
        *head=temp;
        temp->train_no=t_no;
        strcpy(temp->sour_Stat,source);
        //strcpy(temp->desti_Stat,dest);
        temp->station_n=stationno;
        temp->hour=hours;
        temp->minut=minute;
        temp->fare1=fare;
        temp->seat1=seats;
        temp->seat2=seats2;  //second class seat
        temp->fare2=sc_fare;  //fare of second class seat
        temp->date=date;
        temp->month=month;
        temp->year=year;
    }
    int counter(struct node* head)   //it will count the number of nodes in a linked list
    {
        int counts=0;
        while(head!=NULL)
        {
            head=head->next;
            counts++;
        }
        return counts;
    }
    //
    void swaps(struct node* current1,struct node* current2)
    {
        struct node temp;
        temp.hour=current1->hour;
        temp.minut=current1->minut;
        //strcpy(temp.desti_Stat,current1->desti_Stat);
        temp.station_n=current1->station_n;
        strcpy(temp.sour_Stat,current1->sour_Stat);
        temp.train_no=current1->train_no;
        temp.fare1=current1->fare1;
        temp.seat1=current1->seat1;
        temp.seat2=current1->seat2;
        temp.fare2=current1->fare2;
        //__________________________________
        current1->hour=current2->hour;
        current1->minut=current2->minut;
        strcpy(current1->sour_Stat,current2->sour_Stat);
        //strcpy(current1->desti_Stat,current2->desti_Stat);
        current1->station_n=current2->station_n;
        current1->train_no=current2->train_no;
        current1->fare1=current2->fare1;
        current1->seat1=current2->seat1;
        current1->seat2=current2->seat2;
        current1->fare2=current2->fare2;
        //_____________
        current2->hour=temp.hour;
        current2->minut=temp.minut;
        //strcpy(current2->desti_Stat,temp.desti_Stat);
        current2->station_n=temp.station_n;
        strcpy(current2->sour_Stat,temp.sour_Stat);
        current2->train_no=temp.train_no;
        current2->fare1=temp.fare1;
        current2->seat1=temp.seat1;
        current2->seat2=temp.seat2;
        current2->fare2=temp.fare2;
      }
    void bubbleSort(struct node** head)   //sorts linked list in order of departure time
    {
        struct node* current=*head;
         int j=counter(current);
         //cout<<j;
         int i;
         for(i=0;i<j;i++)
         {
             current=*head;
             while(current->next!=NULL)
             {
                 if(current->hour > current->next->hour)
                 {
                     swaps(current,current->next);
                 }
                 if(current->hour==current->next->hour)
                 {
                   swaps(current,current->next);
                 }
                 current=current->next;
             }
        }
    }
    void  bubblesort_trainno(struct node** head)
    {
      struct node* current=*head;
       int j=counter(current);
       //cout<<j;
       int i;
       for(i=0;i<j;i++)
       {
           current=*head;
           while(current->next!=NULL)
           {
               if(current->train_no > current->next->train_no)
               {
                   swaps(current,current->next);
               }
               if(current->train_no==current->next->train_no)
               {
                 swaps(current,current->next);
               }
               current=current->next;
           }
      }
    }

    void display(struct node** head,int date,int month,int year)
    {
        struct node* current=*head;
        int flag=0,prev_train_no=0;
        //cout<<"1";
        while(current!=NULL)
        {
            //cout<<"\n "<<current->train_no<<"\t\t\t "<<current->sour_Stat<<"\t\t\t "<<current->desti_Stat<<"\t\t\t "<<current->hour<<":"<<current->minut;
            if(current->train_no!=prev_train_no)
            {
              cout<<"\n\t________________________________________________________________________________________________________________________________________________________________________\n\n";
            }
            if(current->date==date && current->year==year && current->month==month)
            {
              //cout<<"\n";
              prev_train_no=current->train_no;
              cout<<setw(12)<< current->train_no;
            cout<<setw(20)<< current->sour_Stat;
            //cout<<setw(20)<< current->desti_Stat;
            cout<<setw(20)<< current->station_n;
            cout<<setw(20)<< current->hour<<":"<<current->minut;
            cout<<setw(27)<< current->fare1;
            cout<<setw(20)<< current->seat1;
            cout<<setw(20)<< current->seat2;
            cout<<setw(25)<< current->fare2;
            cout<<endl;
            flag=1;
          }
            current=current->next;
        }
        cout<<"\n\t________________________________________________________________________________________________________________________________________________________________________\n\n";
      if(flag==0)
      {
        cout<<"\n\t\tNO TRAIN SCHEDULED ON THIS DATE ON THIS ROUTE:";
      }
        //cout<<"1";
    }
    void deleteLL(struct node** head)
    {
      struct node* current=*head;
      struct node* temp;
      while(current!=NULL)
      {
        temp=current;
        free(current);
        current=current->next;
      }
      *head=current;
    }
    void updateseat_inLL(struct node** head,int train_no,int nofseat,int stationno,int type)
    {
      struct node* current=*head;
        while(current)
        {
          if(current->train_no==train_no && current->station_n==stationno)
          {
            if(type==1)
            current->seat1=nofseat;
            if(type==2)
            current->seat2=nofseat;
          }
          current=current->next;
        }
    }
    int check(struct node** head,int train_no,int seats,int type,int sn,int dsn)   //this function will check train_n and no of seats availabe in booking ticket menu
    {
      struct node* current=*head;
      if(sn==0 || dsn==0)
      {
        cout<<"\n\n\t\t\tINVALID TRAIN NUMBER\n\n\t\t\tENTER VALID TRAIN NUMBER:";
        return 1;
      }
      //cout<<"dsn sn"<<dsn<<sn;
      while(current)
      {
        if(current->train_no==train_no && current->station_n==sn)
        {
          while(current->train_no==train_no && current->station_n!=dsn+1 &&current->station_n > sn && current->station_n < dsn)
          {
          //cout<<"sn"<<current->station_n;
            if(type==1)
            {
              if(seats > current->seat1)
              {
                cout<<"\n\n\t\t\tNOT ENOUGH SEATS AVAILABLE";
                return 1;
              }
            }
            if(type==2)
            {
              if(seats > current->seat2)
              {
                cout<<"\n\n\t\t\tNOT ENOUGH SEATS AVAILABLE";
                return 1;
              }
            }
            current=current->next;
          }
          //cout<<"y";
        }
        current=current->next;
      }
      return 0;
    }
    void deleteFrom_rearLL(struct node** head,struct node** rear)  //it will work like a queue first in first out;
    {
       struct node* temp;
       struct node* current=*head;
       temp=*rear;
       if(temp==current)
       {
         *rear=NULL;
         return;
       }
       while(current->next!=temp)
       {
         current=current->next;
       }
       *rear=current;
       free(temp);
    }
};
///////////////////
//void update_train(struct node** head2,char name[],int nofseat,int totalfare);
void update_train(struct node** head,int trainno,int date,int month,int year,int totalfare,int nofseat,char name[],int sn,char source[],int hour,int minutes,int type,char dest[]);
void station(struct node** head,char source[],char dest[],int date,int month,int year,char name[]);
//CLASS 1 TRAIN DATA
struct node* head=NULL;
class Train
{
private:
    int train_no;
    int choice;
    char sourcestat[50],dest_stat[50];
    int hours,minute;
    int fare;
    int seats_available; //stores no of seats in a first class
    int seats_second;
    int fare_2;
    int station_no;
    int date;
    int month;
    int year;
    struct node* head3;

    public:
        ofstream fout;

    void heading()
    {
        cout<<"\n\n\n\n\n\t\t\t\t\t\t\t\t\t==========================================================";
        cout<<"\n\n\t\t\t\t\t\t\t\t\t\t        RAILWAY RESERVATION SYSTEM\n";
        cout<< "\t\t\t\t\t\t\t\t\t===========================================================\n";
    }
    void addTrain()
    {
        system("cls");

        heading();
        cout<<"\n\t\tENTER TRAIN NUMBER:";
        cin>>train_no;
        cout<<"\n\t\tENTER STATION:";
        cin>>sourcestat;
        cout<<"\n\t\tENTER STATION NO:";
        cin>>station_no;
        //cout<<"\n\t\tENTER DESTINATION STATION:";
        //cin>>dest_stat;
        cout<<"\n\t\tENTER DATE:";
        cin>>date>>month>>year;
        cout<<"\n\t\tENTER DEPARTURE TIME:";
        cin>>hours>>minute;
        cout<<"\n\t\tENTER FARE:";
        cin>>fare;
        cout<<"\n\t\tENTER FIRST CLASS AVAILABLE SEATS:";
        cin>>seats_available;
        cout<<"\nt\t\tENTER SECOND CLASS AVAILABLE SEATS:";
        cin>>seats_second;
        cout<<"\n\t\tENTER SECOND CLASS SEAT FARE:";
        cin>>fare_2;
        cout<<"\n\t\tPRESS ANY KEY FOR ADMIN MENU....";
    }
   //
  void view_schedule()
    {
        system("cls");
        heading();
        cout<<"\n\n\n\t\t\tENTER DATE[dd-mm-yyyy]:\t";
        int dt,mt,yr;
        cin>>dt>>mt>>yr;
        cout<<"\n\n";
        store_LL l1;
        ifstream fin;
        fin.open("Train1.dat",ios::in|ios::binary);
        if(!fin.is_open())
        {
            cout<<"\n\t\tFILE DOES NOT EXIST";
        }
        else
        {
        // cout<<"\n  TRAIN NO\tSOURCE STATION\tDESTINATION STATION\tDEPARTURE TIME\tFARE\tAVAILABLE SEATS";
        cout <<setw(15)<< "TRAIN_NO\t";
        cout <<setw(20)<< "SOURCE STATION\t";
        cout <<setw(20)<< "STATION NUMBER:\t";
        cout <<setw(20)<< "DEPARTURE TIME";
        cout <<setw(20)<< "FC-FARE";
        cout <<setw(25)<< "FC-AVAILABLE SEATS";
        cout <<setw(25)<< "SC-AVAILABLE SEATS";
        cout <<setw(15)<< "SC-FARE";
        cout<< endl;
          /*while(fin.read((char*)this,sizeof(*this)))
         {
             cout<<"\n  "<<train_no<<"\t\t\t"<<sourcestat<<"\t\t\t"<<dest_stat<<"\t\t\t\t"<<hours<<":"<<minute;
             //fin.read((char*)this,sizeof(*this));
         }*/
        while(fin.read((char*)this,sizeof(*this)))   //'this' contains caller objects address
        {
          /*cout<<setw(15)<< train_no;
          cout<<setw(15)<< sourcestat;
          cout<<setw(15)<< dest_stat;
          cout<<setw(15)<< hours<<":"<<minute;
          cout<<setw(22)<< fare;
          cout<<setw(15)<< seats_available;
          cout<<setw(15)<< seats_second;
          cout<<setw(15)<< fare_2;
          cout<<endl;
        }*/
           //cout<<"1";
           //cout<<"\n  "<<train_no<<"\t\t"<<sourcestat<<"\t\t"<<dest_stat<<"\t\t"<<hours<<":"<<minute<<"\t\t"<<fare<<"\t\t"<<seats_available;}
           //store(head,train_no,sourcestat,dest_stat,hours,minute);  //it will store read object data in linked list.
           //cout<<train_no;
           if(date==dt && month==mt && year==yr)   //this linked list will only stores train scheduled on this date(if any)
          l1.store(&head,train_no,sourcestat,hours,minute,fare,seats_available,seats_second,fare_2,station_no,date,month,year);}
          //l1.display(&head);
          //l1.bubbleSort(&head);
          //cout<<"\n\t\t\    AFTER SORTING";
          //l1.display(&head);
           //fin.close();}
           //fin.read((char*)this,sizeof(*this));
         //}
         //l1.bubbleSort(&head);
         //cout<<"\n\t\t    AFTER SORTING";
         //cout<<date<<month<<year;
          l1.display(&head,dt,mt,yr);
          l1.deleteLL(&head);

        cout<<"\n\t\tPRESS ANY KEY FOR ADMIN MENU......";
        }
}

    ////
    int delete_train(int train_n)
    {
        ifstream fin;
        fin.open("Train1.dat",ios::in|ios::binary);
        int flag=0;
        if(!fin)
        {
            cout<<"\n\t\tERROR!FILE NOT FOUND";
        }
        else
        while(fin.read((char*)this,sizeof(*this)))//we will store all train no in a linked list and then we will search for desired train_no to be deleted
        {
            if(!(train_no==train_n))  //if train_no is not that which has to be deleted then we copy that another file tempfile
            {
                ofstream fout;                             //then in tempfile we will have all record except the record which has to be deleted..
                fout.open("tempfile.dat",ios::app|ios::binary);          //then we will remove the file train.txt
                fout.write((char *)this,sizeof(*this));      //AND RENAME tempfile.txt to train.txt
                fout.close();
            }
            if(train_no==train_n)
            {
              flag=1;
            }
        }
        int x;
        if(flag==0)  //IF NO TRAIN WITH INPUT TRAIN NUMBER
        {
          cout<<"\n\t\t<<<<<<<<<<<<<<<<<NO RECORD FOUND>>>>>>>>>>>>>>>>>";
        }
        else //IF TRAIN FOUND WITH GIVEN INPUT TRAIN NUMBER
        {
        cout<<"\n\t\tARE YOU SURE YOU WANNA PROCEED(y/n)\n\t\t";
        char c;
        cin>>c;
        if(c=='y')
        {
        fin.close();
        //fout.close();
        remove("Train1.dat");    //make sure file is not open anywhere else in the program
        rename("tempfile.dat","Train1.dat");
         x=1;
        }
        //if(c=='n')
        else
        {
            remove("tempfile.dat");
             x=0;
        }
        }
        cout<<"\n\t\tPRESS ANY KEY FOR ADMIN MENU....";
        getch();
        system("cls");
        return x;
     }
    /*void modify_Schedule(int trainnumber)
    {
      // OTHER METHOD USING ios::ate
      /*fstream f;
     f.open("Train1.dat",ios::in|ios::out|ios::ate|ios::binary);
      f.seekg(0); // f is a file pointer it will be pointing 0 bytes from the start of a file
      while(f.read((char*)this,sizeof(*this)))
      {
        if(train_no==trainnumber)
    }*/
    void delete_train2(int train_no,int stationno)
    {
      ifstream fin;
      fin.open("Train1.dat",ios::in|ios::binary);
      int flag=0;
      if(!fin)
      {
          cout<<"\n\t\tERROR!FILE NOT FOUND";
      }
      else
      while(fin.read((char*)this,sizeof(*this)))//we will store all train no in a linked list and then we will search for desired train_no to be deleted
      {
          if(!(train_no==train_no)  && !(station_no==stationno))  //if train_no is not that which has to be deleted then we copy that another file tempfile
          {
              ofstream fout;                             //then in tempfile we will have all record except the record which has to be deleted..
              fout.open("tempfile.dat",ios::app|ios::binary);          //then we will remove the file train.txt
              fout.write((char *)this,sizeof(*this));      //AND RENAME tempfile.txt to train.txt
              fout.close();
          }
          if(train_no==train_no)
          {
            flag=1;
          }
      }
      if(flag==0)  //IF NO TRAIN WITH INPUT TRAIN NUMBER
      {
        cout<<"\n\t\t<<<<<<<<<<<<<<<<<NO RECORD FOUND>>>>>>>>>>>>>>>>>";
      }
      else //IF TRAIN FOUND WITH GIVEN INPUT TRAIN NUMBER
      {
      cout<<"\n\t\tARE YOU SURE YOU WANNA PROCEED(y/n)\n\t\t";
      char c;
      cin>>c;
      if(c=='y')
      {
      fin.close();
      //fout.close();
      remove("Train1.dat");    //make sure file is not open anywhere else in the program
      rename("tempfile.dat","Train1.dat");
      }
      //if(c=='n')
      else
      {
          remove("tempfile.dat");
      }
      }
      cout<<"\n\t\tPRESS ANY KEY FOR ADMIN MENU....";
      getch();
      system("cls");

    }
     void bookticket(char name[])
    {
      system("cls");
      heading();
      char source_stat[50];
      char dest_stati[50];
      cout<<"\n\n\t\tENTER SOURCE STATION     :\t";
      cin>>source_stat;
      cout<<"\t\tENTER DESTINATION STATION:\t";
      cin>>dest_stati;
      cout<<"\t\tENTER DATE               :\t";
      int dt,mt,yr;
      cin>>dt>>mt>>yr;
      int flag=0;
      ifstream fin;
      fin.open("Train1.dat",ios::in|ios::binary);
      cout<<"\n\t\tAVAILABLE TRAINS:\n"<<endl;
      store_LL l3;
      struct node* head2=NULL;
      while(fin.read((char*)this,sizeof(*this)))
      {
         if(date==dt && month==mt && year==yr)
        l3.store(&head2,train_no,sourcestat,hours,minute,fare,seats_available,seats_second,fare_2,station_no,date,month,year);
      }
      fin.close();
      //l3.bubblesort_trainno(&head2);
      //l3.display(&head2,dt,mt,year);
      station(&head2,dest_stati,source_stat,dt,mt,yr,name);
    }

void printOrder(struct node** head2,int nofseat)
{
  cout<<"\t  ";
  cout <<setw(15)<< "TRAIN_NO\t";
  cout <<setw(15)<< "SOURCE STATION\t";
  //cout <<setw(15)<< "DESTINATION STATION\t";
  cout<<setw(15)<< "STATION NUMBER:";
  cout <<setw(15)<< "DEPARTURE TIME";
  cout <<setw(15)<< "SEATS BOOKED\t";
  cout<< endl;
  struct node* current=*head2;
  cout <<setw(19)<< current->train_no;
  cout <<setw(22)<< current->sour_Stat;
  //cout <<setw(15)<< current->desti_Stat;
  cout<<setw(15)<<current->station_n;
  cout <<setw(22)<< current->hour <<":"<<current->minut;
  cout <<setw(15)<< nofseat;
  cout<< endl;
}
void addTrainAgain(int trainno,char source[],int hour2,int minute2,int tempfare1,int fcseat,int scseat,int tempfare2,int stationno)
{
  train_no=trainno;
  hours=hour2;
  minute=minute;
  fare=tempfare1;
  fare_2=tempfare2;
  seats_available=fcseat;
  seats_second=scseat;
  strcpy(sourcestat,source);
  //strcpy(dest_stat,dest);
  station_no=stationno;
}
};
/////////////////////////////////////////////////////////////////////////////////////
void station(struct node** head,char dest[],char source[],int dt,int mt,int yr,char name[])
{
  //cout<<"rsn"<<rear->station_n;  //to check rear is working or not
  struct node* current=*head;
  struct node* current2;
  int flag=0,temp_trainno,temp_sn,temp_dsn;  //temp-sn-source station no   and temp-dsn-destination station no
  char temp_ss[50];
  cout <<setw(15)<< "TRAIN_NO\t";
  cout <<setw(20)<< "SOURCE STATION\t";
  cout <<setw(20)<< "DESTINATION STATION";
  cout <<setw(20)<< "STATION NUMBER:\t";
  cout <<setw(20)<< "DEPARTURE TIME";
  cout <<setw(20)<< "FC-FARE";
  cout <<setw(25)<< "FC-AVAILABLE SEATS";
  cout <<setw(25)<< "SC-AVAILABLE SEATS";
  cout <<setw(15)<< "SC-FARE";
  cout<< "\n\n";
  int fare1,fare2;
  //////////TO PRINT TRAIN DETAIL///////////////////schedule will be displayed
  while(current!=NULL)
  {
    if(!strcmp(current->sour_Stat,source))
    {
       temp_trainno=current->train_no;
       temp_sn=current->station_n;
       fare1=current->fare1;
       fare2=current->fare2;
       strcpy(temp_ss,current->sour_Stat);
       current2=*head;
       while(current2)
       {
         if(!strcmp(current2->sour_Stat,dest) && current2->train_no==temp_trainno && current2->station_n >temp_sn)
         {
           cout<<setw(12)<< current->train_no;
           cout<<setw(20)<< current->sour_Stat;
           cout<<setw(20)<< dest;
           cout<<setw(20)<< current->station_n;
           cout<<setw(20)<< current->hour<<":"<<current->minut;
           cout<<setw(24)<< fare1;
           cout<<setw(20)<< current->seat1;
           cout<<setw(20)<< current->seat2;
           cout<<setw(25)<< fare2;
           cout<<endl;
           temp_dsn=current2->station_n;
           flag=1;
           break;
         }
         if(current2->train_no==temp_trainno && current2->station_n > temp_sn)
         {
           //cout<<"tn"<<temp_trainno;
           fare1=fare1+current2->fare1;
           fare2=fare2+current2->fare2;
         }
         current2=current2->next;
     }
    }
    current=current->next;
  }
  if(flag==0)
  {
    cout<<"\n\n\t\tNO TRAINS FOUND\n\n\t\tPRESS ANY KEY FOR MAIN MENU....";
    getch();
    return;
  }
  cout<<"\n\n\t\t\tSELECT YOUR CHOICE:\n\n\t\t\t1.TO BOOK TICKET\n\n\t\t\t2.BACK\n\t\t\t";
  int i;
  cin>>i;
  switch(i)
  {
    case 1:
    int noftrain,nofseat,type;
    label:
    cout<<"\n\n\t\t\tENTER TRAIN NUMBER    :\t";
    cin>>noftrain;
    cout<<"\n\n\t\t\tENTER NUMBER OF A SEAT:\t";
    cin>>nofseat;
    cout<<"\n\n\t\t\tSELECT CLASS OF A SEAT :\n\n\t\t\t1.FIRST CLASS\n\n\t\t\t2.SECOND CLASS\n\t\t\t";
    cin>>type;
    current=*head;
    int flag2=0,x;
    struct node* head3=NULL;  //to store the deleted stations
    store_LL l4;
    /////////////////////////////////////////////////////////////////////////////

    //l4.display(head);
    // geting temp_sn and temp_dsn of source and destination from linked list node corresponding to that node
    temp_sn=temp_dsn=0;
    while(current)
    {
      if(current->train_no==noftrain && !strcmp(current->sour_Stat,source) && current!=NULL)
      {
        temp_sn=current->station_n;
        current=*head;
        while(current)
        {
           if(current->train_no==noftrain && !strcmp(current->sour_Stat,dest))
          {//cout<<"w";
          temp_dsn=current->station_n;}
          current=current->next;
        }
        //temp_dsn++;
        break;
      }
      //cout<<"e";
      current=current->next;
    }
    int z=l4.check(head,noftrain,nofseat,type,temp_sn,temp_dsn);   //this will check entered train no and no of seats are valid or not
    if(z)
    {
      cout<<"\n\n\t\t\tPRESS ANY KEY TO ENTER CREDENTIALS AGAIN.....";
      getch();
      system("cls");
      Train t7;
      t7.heading();
      goto label;
    }
    /////////////////
    //temp_trainno=trainno;
    //cout<<"DEST"<<temp_dsn<<endl;
    //cout<<"source"<<temp_sn<<endl;
    int hour,minute4;
    current=*head;
    ////////////Storing linked list available seats in each modified station ////
       while(current)   //VERY IMPORTANT :MAKE SURE THAT ORDER OF STORED DATA IN A LINKED LIST IN INCREASING ORDER OF STATION NO
      {
        if(current->train_no==noftrain && current->station_n==temp_sn)  //in linked list data stored is sorted according train_no and station no are in asecnding order
      {
        //cout<<temp_dsn;
         hour=current->hour;
        minute4=current->minut;
        fare1=fare2=0;
         while(current->station_n!=temp_dsn && current->train_no==noftrain && current!=NULL)
        {
          if(type==1)
          {
            //cout<<"st no"<<current->station_n<<endl;
            current->seat1=current->seat1-nofseat;
            x=current->seat1;
            //l4.store(&head3,noftrain,current->sour_Stat,current->hour,current->minut,current->fare1,x,current->seat2,current->fare2,current->station_n);
            l4.updateseat_inLL(head,noftrain,x,current->station_n,type);
            //update_train(head,noftrain);
            fare1=fare1+current->fare1;
            //cout<<"currentfare "<<current->fare1<<endl;
            flag2=1;
          }
          if(type==2)
          {
            current->seat2=current->seat2-nofseat;
            x=current->seat2;
            //l4.store(&head3,temp_trainno,current->sour_Stat,current->hour,current->minut,current->fare1,x,current->seat2,current->fare2,current->station_n);
            l4.updateseat_inLL(head,noftrain,x,current->station_n,type);
            fare2=fare2+current->fare2;
            flag2=1;
          }
          current=current->next;
          //cout<<"sn"<<current->station_n;
        }
      }
      //cout<<"fare"<<fare1<<endl;
      if(flag2==1)
      {
        //cout<<"55";
        if(type==1)
        {int totalfare1=fare1*nofseat;
          cout<<"\n\n\t\t\tTOTALFARE:\t"<<totalfare1<<endl;
        update_train(head,noftrain,dt,mt,yr,totalfare1,nofseat,name,temp_sn,source,hour,minute4,type,dest);}
        if(type==2)
        {
          int totalfare2=fare2*nofseat;
          cout<<"\n\n\t\t\tTOTALFARE:\t"<<totalfare2<<endl;
          update_train(head,noftrain,dt,mt,yr,totalfare2,nofseat,name,temp_sn,source,hour,minute4,type,dest);}
        break;
      }
      current=current->next;
    }
    cout<<"PROCESSING...................:\n\n";
    //l4.display(head);
 }
  getch();
}
//////////////////////////////////////////////////////////////////////////////////////////
class store_bookt
{
  char username[30];
  int train_n;
  int hour;
  int minute;
  char sourcestat[50];
  char desti_Stat[50];
  int seat;
  int fare;
  int type_seat;
  int station_no;
  int date;
  int month;
  int year;
  int ticket_id;
  int transaction_id;
  int PNR_no;
public:
  void store(char name[],int trainno,char source[],int hour3,int minute3,int tfare2,int tseat,int stationno,int date1,int month1,int year1,int type,char dest[],int tranId)
  {
    strcpy(username,name);
    train_n=trainno;
    strcpy(sourcestat,source);
    strcpy(desti_Stat,dest);
    hour=hour3;
    fare=tfare2;
    station_no=stationno;
    minute=minute3;
    seat=tseat;
    date=date1;
    month=month1;
    year=year1;
    type_seat=type;
    srand(time(0));
    ticket_id=rand();
    PNR_no=rand();
    transaction_id=tranId; //To initialize the random number generator, you need to call srand() with a seed.You only need to initialize it onceYou will get the same sequence of numbers with the same seed, so normally, people use the current time as seed as that is pretty much guaranteed to change between program executions:
  }
  ///////////////////
  void printticket(char name[])
  {
    ifstream fin;
    if(!fin)
    {
      cout<<"\n\n\t\t\tFILE CANNOT BE OPENED!!!";
      return;
    }
    int flag=0;
    fin.open("Bookticket.txt",ios::in);
    cout<<"\n\n\t\t\tBOOKED TICKETS:";
    while(fin.read((char*)this,sizeof(*this)))
    {

      if(!strcmp(username,name))
      {
        cout<<"\n\t\t__________________________________________________________________________________________________________________________________________________________________________";
        cout<<"\n\n\t\t\tNAME               :"<<username;
        cout<<"\n\n\t\t\tDATE               :"<<date<<"-"<<month<<"-"<<year;
        cout<<"\n\n\t\t\tTRAIN NO           :"<<train_n;
        cout<<"\n\n\t\t\tSOURCE STATION     :"<<sourcestat;
        cout<<"\n\n\t\t\tDESTINATION STATION:"<<desti_Stat;
        cout<<"\n\n\t\t\tSTATION NO         :"<<station_no;
        cout<<"\n\n\t\t\tDEPARTURE TIME     :"<<hour<<":"<<minute;
        cout<<"\n\n\t\t\tSEAT BOOKED        :"<<seat;
        cout<<"\n\n\t\t\tSEAT CLASS         :"<<type_seat;
        cout<<"\n\n\t\t\tTOTAL FARE         :"<<fare;
        cout<<"\n\n\t\t\tPNR.NO             :"<<PNR_no;
        cout<<"\n\n\t\t\tTICKET-NO          :"<<ticket_id;
        cout<<"\n\n\t\t\tTRANSACTION ID     :"<<transaction_id;
        flag=1;
      }
    }
    if(flag==0)
    {
      cout<<"\n\n\n\t\t\t<<<<<<<NO TICKETS BOOKED>>>>>>>";
    }
    fin.close();
    cout<<"\n\n\t\t_____________________________________________________________________________________________________________________________________________________________________________";
    cout<<"\n\n\n\t\t<<<<<<<<<<<<<<<<<<<PRESS ANY KEY FOR BACK MENU>>>>>>>>>>>>>>>>>>>>>>>";
    getch();
  }
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct stack
{
int tid;
int amount;
int seatsbooked;
struct stack* next;
};
class stacks
{
public:
  void push(struct stack** top,int tamount,int seat,int id)
  {
    struct stack* temp=new(nothrow)struct stack;
    if(*top==NULL)
    {
      temp->next=NULL;
    }
    else
    {
      temp->next=*top;
    }
    *top=temp;
    //temp->tid=tid;
    temp->amount=tamount;
    temp->seatsbooked=seat;
    temp->tid=id;
  }
  void pop(struct stack** top)
  {
    struct stack* temp=*top;
    *top=temp->next;
    free(temp);
  }
  void display(struct stack** top)
  {
    struct stack* temp=*top;
    cout<<"\n\n\t\t\tYOUR RECENT TRANSACTIONS:\n";
    while(temp!=NULL)
    {
      cout<<"\n\t________________________________________________________________________________________________________________________________________________________________";
      cout<<"\n\n\t\t\tTRANSACTION ID    :"<<temp->tid;
      cout<<"\n\n\t\t\tTRANSACTION AMOUNT:"<<temp->amount;
      cout<<"\n\n\t\t\tSEATS_BOOKED      :"<<temp->seatsbooked;
       //temp=temp->next;
      pop(&temp);
    }
    cout<<"\n\t___________________________________________________________________________________________________________________________________________________________________";
    cout<<"\n\t\t\t<<<<<<<<<<<<<<<<PRESS ANY KEY FOR MAIN MENU>>>>>>>>>>>>>>>>>>";
    getch();
  }
};

class transaction
{
  int id;
  char username[30];
  int seatsbooked;
  int amount;
  int transactionId;
public:
  void store(int seatbooked,int totalfare,char name[],int tranId)
  {
    seatsbooked=seatbooked;
    strcpy(username,name);
    amount=totalfare;
    transactionId=tranId;
  }
  void print(char name[])
  {
    ifstream fin;
    fin.open("transactions.txt",ios::in);
    if(!fin)
    {
      cout<<"\n\t\t\tFILE CANNOT BE OPENED";
      getch();
      return;
    }
    struct stack* top=NULL;
    stacks s1;
    while(fin.read((char*)this,sizeof(*this)))
    {
      if(!strcmp(name,username))
      {
        s1.push(&top,amount,seatsbooked,transactionId);
      }
    }
    fin.close();
    s1.display(&top);
  }
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//void update_train(struct node** head2/*,char name[],int nofseat,int totalfare,'*/,int train_no)   //function to update train info on file after booking of a ticket
void update_train(struct node** head2,int trainno,int date,int month,int year,int totalfare,int nofseat,char name[],int sn,char source[],int hour,int minut,int type,char dest[])
{
  struct node* current=*head2;
  Train t6;
  int y;
  y=t6.delete_train(trainno);
  ofstream fout;
  fout.open("Train1.dat",ios::app|ios::binary);
  store_LL l5;
  //HERE QUEUE IS IMPLEMENT USING REAR pointer
  /*ALGO APPLIED here
   1.from rear items(train data) will be popped as data is stored in increasing order of station number means greater station no are at back.
   2.Items will only be wriiten to file if its train no matches with train_no whose tickets has been booked.
   3.This is done to maintain the convention that greater station no are written first on a file.
   4.So,they are stored first in a linked list.
   5.But insertion is happening at front.So station with higher station numbers will be at the back of linked list.
   */
   if(y==1)  //means ticket is booked, deletetrain function has been runned
  {
    while(rear)
  {
    if(rear->train_no==trainno)
    {
      t6.addTrainAgain(rear->train_no,rear->sour_Stat,rear->hour,rear->minut,rear->fare1,rear->seat1,rear->seat2,rear->fare2,rear->station_n);
      fout.write((char*)&t6,sizeof(t6));
      l5.deleteFrom_rearLL(head2,&rear);
    }
    else
    {
      l5.deleteFrom_rearLL(head2,&rear);
    }
  }
  fout.close();
  ///generating transaction id and it will be written in file bookticket.txt and transactions.txt as well.
  //srand(time(NULL));
  int tranId=rand();
  ofstream fout2;
  fout2.open("Bookticket.txt",ios::app);
  store_bookt st1;
  //cout<<totalfare;
  st1.store(name,trainno,source,hour,minut,totalfare,nofseat,sn,date,month,year,type,dest,tranId);
  fout2.write((char*)&st1,sizeof(st1));
  fout2.close();
  /////storing TRANSACTIONS
  ofstream fout3;
  fout3.open("transactions.txt",ios::app);
  transaction ts1;
  ts1.store(nofseat,totalfare,name,tranId);
  fout3.write((char*)&ts1,sizeof(ts1));
  fout3.close();

}
}
//CLASS 2 ADMIN MENU...................................................................................................
char admin_username[15]="iamadmin";
char admin_password[15]="12345";

class admin_menu
{
private:
    int choice;
    char username[15];
    char password[15];

public:
    Train t2,t3;
    ofstream fout;
    //char admin_username[15]="iamadmin";
    //char admin_password[15]="123456789";
    //ifstream fin;

    void admin_login()
    {
        t2.heading();
        cout<<"\n\n\n";
        cout<<"\n\n\t\t\tENTER USERNAME:\t";
        cin>>username;    //space excluded input
        if(!strcmp(admin_username,username))  //strcmp() returns 0 if matches
        {
            cout<<"\n\n\t\t\tENTER PASSWORD:\t";
            //cin>>password;  //space excluded input
            char ch;
            int i=0;
            while(ch!='\r')
            {
              ch=getch();
              cout<<"*";
              if(ch == '\r')
              {
                password[i]='\0';
                break;
              }
              password[i]=ch;
              i++;
            }
            if(!strcmp(password,admin_password))
            {
                cout<<"\n\n\t\t\t_______________ACCESS GRANTED_____________\n\n\t\t\tPRESS ANY KEY TO CONTINUE.......\n\t\t\t";
                getch();
                system("cls");
                admin_m();
            }
            else
            {
                cout<<"\n\n\t\t\tPASSWORD DOES NOT MATCHED\n\n\t\tPRESS ANY KEY TO BACK MENU";
                getch();
                system("cls");
                return ;    //controls goes to driver program

            }
        }
        else
        {
            cout<<"\n\n\t\t\tUSERNAME DOES NOT MATCHED\n\n\t\t\tPRESS ANY KEY TO BACK MENU.........";
            getch();
            system("cls");
            return ;   //control goes to driver program


    }
    }
    void admin_m()
{
         t2.heading();
        cout<<"\n\n\t\t\tSELECT YOUR CHOICE:\n\n\t\t\t1.ADD TRAIN\n\n\t\t\t2.DELETE TRAIN\n\n\t\t\t3.MODIFY TRAIN SCHEDULE\n\n\t\t\t4.VIEW SCHEDULE\n\n\t\t\t5.LOG OUT-MAIN MENU\n\n\t\t\t";
        cin>>choice;
        switch(choice)
        {
        case 1:
            fout.open("Train1.dat",ios::app|ios::binary);
            t2.addTrain();
            fout.write((char*)&t2 ,sizeof(t2));
            fout.close();
            getch();
            system("cls");
            admin_m();
            break;
        case 2:
            int train_n;
            cout<<"\n\t\tENTER TRAIN NO TO BE DELETED\n\t\t";
            cin>>train_n;
            t2.delete_train(train_n);
            admin_m();
            break;
        case 3:
             cout<<"\n\t\tENTER TRAIN NO WHOSE SCHEDULE HAS TO BE MODIFIED:";
             cin>>train_n;
             t2.delete_train(train_n);
             cout<<"\n\t\tENTER NEW SCHEDULE";
             getch();
             t2.addTrain();
             //ofstream fout;
             fout.open("Train1.dat",ios::app|ios::binary);
             fout.write((char*)&t2,sizeof(t2));
             fout.close();
             system("cls");
             admin_m();
            break;
        case 4:
               {
                t2.view_schedule();
                getch();
                system("cls");
                 admin_m();}
        default :
            system("cls");
         break;
        }
}
};
void usermenu();
//CLASS 4 INNER USERMENU DECLARTION
//class inner_usermenu;
//
void myprofile(char arr[]);
//CLASS 3 USER
class user
{
    int choice;
    char name[50];
    //char namecmp[50];
    char mobile_no[10];
    char aadhar_no[16];
    char password[15];
    char email_id[30];
    char source_stat[50];
    char dest_stati[50];
    Train t1;
public:
    void heading(char arr[])
    {
      cout<<"\n\n\n\n\n\t\t\t\t\t\t\t\t\t==========================================================";
      cout<<"\n\n\t\t\t\t\t\t\t\t\t\t        RAILWAY RESERVATION SYSTEM\n";
      cout<< "\t\t\t\t\t\t\t\t\t===========================================================\n";
        cout<<"\n\n\t\t\t\t\t\t\t\t_________________________WELCOME TO USER PORTAL_________________________\n\n\n\t\t";
        cout<<"\n\n\t\t\tHi! "<<arr<<endl;
    }
    int loginCheck(char name1[],char password1[])
    {
        ifstream fin;
        fin.open("user login.txt",ios::in);
        while(fin.read((char*)this,sizeof(*this)))
        {
            if(!strcmp(name,name1)  && !strcmp(password,password1))
            {
                cout<<"\n\t\tACCESS GRANTED";
                return 1;
            }
        }
        fin.close();
        return 0;
    }
    int usernameCheck()
    {
        ifstream fin;
        fin.open("userlogin.txt",ios::in);
        //cout<<"\n"<<name;
        char name2[50];
        strcpy(name2,name);
        while(fin.read((char*)this,sizeof(*this)))
        {
            if(!strcmp(name2,name))
            {
                cout<<"\n\t\tUSERNAME ALREADY EXISTS!!!\n\t\t";
                getch();
                return 1;
            }
        }
        fin.close();
        return 0;
    }
    void user_signup()
    {
        system("cls");
        t1.heading();
        cout<<"\n\t\tENTER NAME:\t";
        cin>>name;
        cout<<"\n\t\tENTER PASSWORD:\t";
        cin>>password;
        cout<<"\n\t\tENTER MOBILE NUMBER:\n\t\t";
        cin>>mobile_no;
        cout<<"\n\t\tENTER YOUR EMAIL ID:\n\t\t";
        cin>>email_id;
        cout<<"\n\t\tENTER AADHAR NUMBER:\n\t\t";
        cin>>aadhar_no;
        cout<<"\n\t\tYOU SUCCESSFULLY SIGNED UP\n\t\tNOW YOU CAN SIGN IN TO YOUR ACCOUNT....\n\t\tENTER ANY KEY\n\t\t";
        getch();
        }
    void inner_menu(char arr[])
    {
        heading(arr);
        cout<<"\n\n\t\t\tSELECT YOUR CHOICE\n\n\t\t\t1.MY PROFILE\n\n\t\t\t2.BOOK TICKET\n\n\t\t\t3.PRINT TICKET\n\n\t\t\t4.MY TRANSACTIONS\n\n\t\t\t5.BACK";
        cin>>choice;
        switch(choice)
        {
        case 1:
          {
            system("cls");
            heading(arr);
            //cout<<"name1=="<<arr;
            ifstream fin;
            fin.open("user login.txt",ios::in);
            cout<<"\n\t\t\tMYPROFILE :)\n\t\t\t";
            myprofile(arr);
            /*while(fin.read((char*)this,sizeof(*this)))
            {
                if(!strcmp(arr,name))
                {
                    //showdata();
                    myprofile(name);

                }
            }*/
            cout<<"\n\nt\t\t\tPRESS ANY KEY TO BACK MENU......\n\t\t\t";
            getch();
            system("cls");
            inner_menu(name);
            break;
          }
        case 2:
            {Train t4;
            t4.bookticket(name);
            system("cls");
            inner_menu(name);
            break;}
          case 3:
          {
          store_bookt st1;
          system("cls");
          heading(name);
          st1.printticket(name);
          system("cls");
          inner_menu(name);}
          case 4:
          {transaction ts2;
            system("cls");
            heading(name);
          ts2.print(name);
         system("cls");
         inner_menu(name);}

        case 5:
            system("cls");
            usermenu();
            break;

        default:
            break;
        }
    }
    int user_signin()
    {
        system("cls");
        t1.heading();
        ifstream fin;
        fin.open("userlogin.txt",ios::in);
        cout<<"\n\n\t\t\tENTER USERNAME:\t";
        cin>>name;
        char namecmp[15]; //this variable is only created to compare input username with username stored in a file.
        char passwordcmp[15];  //
        strcpy(namecmp,name);
        //cout<<namecmp;
        int flag=0;
        while(fin.read((char*)this,sizeof(*this)))
        {
            //cout<<"\n"<<name;  IMPOARTANT-(USED FOR CHECKING NAME OF ALL USERS ARE STORED AND READ CORRECTLY OR NOT..
            if(!strcmp(namecmp,name))
            {
                cout<<"\n\n\t\t\tENTER PASSWORD:\t";
                //cin>>password;
                char ch;
                int i=0;
                while(ch!='\r')
                {
                  ch=getch();
                  cout<<"*";
                  if(ch == '\r')
                  {
                    passwordcmp[i]='\0';
                    break;
                  }
                  passwordcmp[i]=ch;
                  i++;
                }
                if(!strcmp(passwordcmp,password))
                {
                    flag=1;
                    break;
                }
                else
                {
                    cout<<"\n\t\t!PASSWORD DOES NOT MATCHED\n\t\tPRESS ANY KEY FOR BACK MENU.......";
                    getch();
                    system("cls");
                    usermenu();
                    break;
                }
            }
        }
        if(flag==1)
        {
            system("cls");
            inner_menu(name);
             //return 0;  //WHY IT DOES NOT EXITING FROM A FUNCTION
        }
        if(flag==0)
        {
            cout<<"\n\t\tUSERNAME DOES NOT EXISTS\n\t\tPRESS ANY KEY FOR BACK MENU\n\t\t";
            getch();
            system("cls");
            usermenu();
        }
 }
   void showdata()
   {
       cout<<"\n\n\t\t\tMY NAME          : \t"<<name;
       //cout<<"\n\n\t\t\tMY MOBILE NUMBER : \t"<<mobile_no;
       cout<<"\n\n\t\t\tMY ADDAHAR NUMBER: \t"<<aadhar_no;
       cout<<"\n\n\t\t\tMY EMAIL-ID      : \t"<<email_id;
   }
   friend void myprofile(char arr[]);
};
//FRIEND FUNCTION OF CLASS USER (CAN ACCESS ITS PRIVATE MEMBERS)
void myprofile(char arr[])
{
    user u5;
    ifstream fin;
    fin.open("userlogin.txt",ios::in);
    //cout<<"name=="<<arr;
    while(fin.read((char*)&u5,sizeof(u5)))
    {
        if(!strcmp(arr,u5.name))
            u5.showdata();
    }
}
void usermenu()
{
        Train t1;
        int choice;
        t1.heading();
        user u3;
        ofstream fout;
        cout<<"\n\n\t\t\tSELECT YOUR CHOICE:\n\n\t\t\t1.SIGN UP-NEW USERS\n\n\t\t\t2.SIGN IN-EXISTING USERS\n\n\t\t\t3.LOGOUT\n\n\t\t\t";
        cin>>choice;
        switch(choice)
        {
        case 1:
          {fout.open("userlogin.txt",ios::app);
          user u5;       //if we dont declare this it will taking first input again and again on a file...i.e input taken in first object here we are declaring fresh object every time for input
          u5.user_signup();
          if(!u3.usernameCheck())
          {
              fout.write((char*)&u5,sizeof(u5));
              fout.close();
           }//(char*)this tells location of address and sizeof(*this) tells sizeof object 'this' is pointing to.
          else
          {
              cout<<"TRY OTHER ONE\n\t\tPRESS ANY TO TRY AGAIN.....";
               getch();
          }
          system("cls");
          usermenu();
          break;}
        case 2:
            u3.user_signin();
            break;
        case 3:
            exit(0);
            break;
        }
}
class main_menu
{
public:
    admin_menu ad;
    user u2;
    Train t4;
    int menu()
    {
        cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\tENTER YOUR CHOICE:";
    cout<<"\n\n\t\t\t\t\t\t\t\t\t\t1.YOU ARE-ADMIN\n\n\t\t\t\t\t\t\t\t\t\t2.YOU ARE-USER \n\n\t\t\t\t\t\t\t\t\t\t3.ENQUIRY\n\n\t\t\t\t\t\t\t\t\t\t4.VIEW SCHEDULE\n\n\t\t\t\t\t\t\t\t\t\t5.EXIT\n\n\t\t\t\t\t\t\t\t\t\t";
    int choice;
    cin>>choice;
    system("cls");

    switch(choice)
    {
    case 1:
        ad.admin_login();
        //ad.admin_m();
        break;
    case 2:
        usermenu();
        break;
    case 3:
    t4.heading();
    cout<<"\n\n\t\t\tFOR ENQUIRY CONTACT:\n\n\t\t\tMOBILE.NO-9996464100";
    getch();
    system("cls");
    break;
    case 4:
    t4.view_schedule();
    getch();
    system("cls");
    t4.heading();
    menu();
    break;
    case 5:
        system("cls");
        t4.heading();
        cout<<"\n\n\n\t\t...........................................THANK YOU FOR VISTING US.......................................\n\t\t";
        getch();
        exit(0);
    }
}
};

int main()
{
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
    Train obj;
    admin_menu ad;
    user u1;
    label:
    obj.heading();
    main_menu m1;
    m1.menu();
    goto label;
    }
