#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include<string.h>
#include<cstring>
#include<windows.h>
using namespace std;
class Bus{
	private:
		string b_no,b_name,d_name;
		int b_seats;
	public:
		void menu();	
		void add_bus();
		void view_bus();
		void single_bus_view();
		void All_bus_view();
		void ubdate_bus();
		void delete_bus();
		void routs_bus();
		void Booking();
};

 void Bus::menu(){
 	p:
 	int choice;
 	system("cls");
 	system("color E4");
 	cout<<"\t\t\t\t---------Wellcome to----------------";
 	cout<<"\n\n\t\t\t\t-------------Bus Managment system-------------";
 	cout<<"\n\n\t\t\t\t**********Main Menu**********";
 	cout<<"\n\n\t\t\t\t1. ADD Bus Record";
 	cout<<"\n\n\t\t\t\t2. View BUS DETILAS";
 	cout<<"\n\n\t\t\t\t3. Update BUS DETIALS";
 	cout<<"\n\n\t\t\t\t4. Delete BUS DETIALS";
 	cout<<"\n\n\t\t\t\t5. ROUTS OF BUSES";
 	cout<<"\n\n\t\t\t\t6. Booking Record";
 	cout<<"\n\n\t\t\t\t7. SEATS RENEW";
 	cout<<"\n\n\t\t\t\t8. SEARCH BOOKING RECORD";
 	cout<<"\n\n\t\t\t\t9. UPDATE BOOKING RECORD";
 	cout<<"\n\n\t\t\t\t10. DELETE BOOKING RECORD";
 	cout<<"\n\n\t\t\t\t11. SHOW ALL BOOKING RECORD";
 	cout<<"\n\n\t\t\t\t12. EXIT";
 	cout<<"\n\n\t\t\t\tEnter your CHOICE:-";
 	cin>>choice;
 	switch(choice)
 	{
 		case 1:
 			add_bus();
 			break;
 		case 2:
 			view_bus();
 			break;
 		case 3:
 			ubdate_bus();
 			break;
 		case 4:
 			delete_bus();
 			break;
 		case 5:
 			routs_bus();
 			break;
 		case 6:
 			Booking();
 			break;
 		case 7:
 			break;
 		case 8:
 			break;
 		case 9:
 			break;
	    case 10:
 			break;
 		case 11:
 			break;
 		case 12:
 			exit(0);
 			default:
 				cout<<"You enter a invalid choice *** please try again";
 				
	 }
	 getch();
	 goto p;
 	
 }
 void Bus::add_bus(){
	p:
	system("cls");
	system("color A");
	string tb_no,tb_name,td_name;
	int tb_seats,found=0;
	
	
	cout<<"\n\n\t\t\t\t-------------Bus Managment system-------------";
	cout<<"\n\nEnter a Bus NO=-";
		cin>>b_no;
	
	cout<<"\n\nEnter a Bus Name=";
	cin>>b_name;
	cout<<"\n\nTotal Seats=";
	cin>>b_seats;
	cout<<"\n\nEnter a Driver name";
	cin>>d_name;
	fstream file;
	file.open("Bus.txt",ios::in);
	if(!file)
	{
		file.open("Bus.txt",ios::app|ios::out);
		file<<"Bus No="<<b_no<<"     "<<"Bus Name="<<b_name<<"       "<<"Total Seats="<<b_seats<<"    "<<"Driver name="<<d_name;
		file.close();
	}
	else 
	{
		file>>tb_no>>tb_name>>td_name>>tb_seats;
		while(!file.eof())
		{
			if(b_no == tb_no)
			{
				found++;
			}
			file>>tb_no>>tb_name>>td_name>>tb_seats;
		}
		file.close();
		if(found==0)
		{
			file.open("Bus.txt",ios::app|ios::out|ios::binary);
		file<<"Bus No="<<b_no<<"     "<<"Bus Name="<<b_name<<"       "<<"Total Seats="<<b_seats<<"    "<<"Driver name="<<d_name;
		file.close();
		}
		else 
		{
			cout<<"\n\nDuplicate record found";
			getch();
			goto p;
		}
	}
	cout<<"\n\n\t\t\tyour record is successfully saved";
}
void Bus::view_bus(){
	p:
	system("cls");
	system("color B0");
	cout<<"\n\n\t\t\t\t-------------Bus Managment system-------------";
	int choice;
	cout<<"\n\n\t\t\t\t-------------1. single Bus view-------------";
    cout<<"\n\n\t\t\t\t-------------2. All Buses view-------------";
    cout<<"\n\n\t\t\t\t-------------3. GoBack-------------";
    cout<<"\n\n\t\t\t\tEnter your choice=";
    cin>>choice;
    switch(choice)
    {
    	case 1:
    		single_bus_view();
    		break;
    	case 2:
    		All_bus_view();
    		break;
	    case 3:
    		menu();
    	default:
    		cout<<"You Enter a wrong nbr";
	}
	getch();
	goto p;
}
void Bus::single_bus_view(){
	system("cls");
	cout<<"\n\n\t\t\t\t-------------Bus Managment system-------------";
	string tb_no;
	int found=0;
	cout<<"\n\n\t\t\tEnter your Bus no=";
	cin>>tb_no;
	fstream file;
	file.open("Bus.txt",ios::in);
	if(!file)
	{
		cout<<"\n\nFile Oppeniong error.........";
		
	}
	else
	{
	cout<<"\n\n\t\t\tEnter your Bus no=";
	cin>>tb_no;	
		file>>b_no>>b_name>>d_name>>b_seats;
		while(!file.eof())
		{
			if(tb_no == b_no)
			{
				cout<<"Bus No.\t\t\tBUS NAME\t\t\tNo of seats\t\t\tDriver name";
				cout<<"\n"<<b_no<<"\t\t"<<b_name<<"\t\t"<<b_seats<<"\t\t"<<d_name;
				found++;
			}
				file>>b_no>>b_name>>d_name>>b_seats;
		}
		file.close();
		if(found == 0)
		{
			cout<<"\n\nInvalid Bus number";
		}
	}
}
void Bus::All_bus_view(){
	system("cls");
		int foundd=0;
	cout<<"\n\n\t\t\t\t-------------Bus Managment system-------------";
	
	fstream file;
	file.open("Bus.txt",ios::in);
	if(!file){
		cout<<"\n\nFile Oppeniong error.........";
		
	}
	else
	{
	   	cout<<"Bus No.\t\t\tBUS NAME\t\t\tNo of seats\t\t\tDriver name";
		file>>b_no>>b_name>>d_name>>b_seats;
		while(!file.eof())
		{
			
			
				cout<<"\n"<<b_no<<"\t\t"<<b_name<<"\t\t"<<b_seats<<"\t\t"<<d_name;
			    file>>b_no>>b_name>>d_name>>b_seats;
		}
		file.close();
		
	}
}
void Bus::ubdate_bus(){
		system("cls");
	system("color A");
	string tb_no,no,tb_name,td_name;
	int tb_seats,found;
	cout<<"\n\n\t\t\t\t-------------Bus Managment system-------------";
	fstream file, file1;
	file.open("Bus.txt",ios::in);
	if(!file)
	{
		cout<<"\n\nFile openiong error";
	}
	else
	{
		cout<<"\n\nEnter bus no=";
		cin>>tb_no;
		file>>b_no>>b_name>>d_name>>b_seats;
		while(!file.eof())
		{
			if(b_no==tb_no)
			{
				cout<<"\n\nEnter a new bus no=";
				cin>>no;
				cout<<"\n\nEnter a bus name=";
				cin>>tb_name;
				cout<<"\n\nEnter a no of seats=";
				cin>>tb_seats;
				cout<<"\n\nEnter a bus  driver name=";
				cin>>td_name;
				
				file1.open("Bus1.txt",ios::app|ios::out);
				file1<<b_no<<"  "<<b_name<<"  "<<d_name<<"  "<<b_seats;
				cout<<"\n\n\tUbdate Bus record sucessfully.....\n ";
				found++;
			}
			else
			{
			file1<<b_no<<"  "<<b_name<<"  "<<d_name<<"  "<<b_seats;	
			}
			file>>b_no>>b_name>>d_name>>b_seats;
		}
		file.close();
		file1.close();
		remove("Bus.txt");
		rename("Bus1.txt","Bus.txt");
		if(found==0)
		{
			cout<<"\n\n\t\t\tBus nbr is invalid....";
		}
	}
}
void Bus::delete_bus(){
	system("cls");
	system("color A");
	string tb_no;
	int found=0;
	cout<<"\n\n\t\t\t\t-------------Bus Managment system-------------";
	fstream file, file1;
	file.open("Bus.txt",ios::in);
	if(!file)
	{
		cout<<"\n\nFile openiong error";
	}
	else
	{
		cout<<"\n\nEnter bus no=";
		cin>>tb_no;
		file>>b_no>>b_name>>d_name>>b_seats;
		while(!file.eof())
		{
			if(b_no==tb_no)
			{
				
				file1.open("Bus1.txt",ios::app|ios::out);
				cout<<"\n\n\tDelete Bus record sucessfully.....\n ";
				found++;
			}
			else
			{
			file1<<b_no<<"  "<<b_name<<"  "<<d_name<<"  "<<b_seats;	
			}
			file>>b_no>>b_name>>d_name>>b_seats;
		}
		file.close();
		file1.close();
		remove("Bus.txt");
		rename("Bus1.txt","Bus.txt");
		if(found==0)
		{
			cout<<"\n\n\t\t\tBus nbr is invalid....";
		}
	}
}
void Bus::routs_bus()
{
	p:
	system("cls");
	int choice;
	cout<<"\n\n\t\t\t\t-------------Bus Managment system-------------";
	cout<<"\n\t\t\t\t________________________________________________";
	cout<<"\n\n\t\t\t\t1. 1st ROUT Detials";
	cout<<"\n\n\t\t\t\t2. 2st ROUT Detials";
	cout<<"\n\n\t\t\t\t3. 3st ROUT Detials";
    cout<<"\n\n\t\t\t\t4. 4st ROUT Detials";
    cout<<"\n\t\t\t\t________________________________________________";
    cout<<"Enter your choice=";
    cin>>choice;
    switch(choice)
    {
    	case 1:
    		cout<<"\n\n\t\t\t\t..........................................";
    		cout<<"\n\n\t\t.........From Sialkot to lahore:..............";
    		cout<<"\n\t\t\t\t............9:00 AM---------11:00 AM  .......";
    		cout<<"\n\n\t\t.........From  lahore TO Faisalbad:..............";
    		cout<<"\n\t\t\t\t............12:00 PM---------2:30 PM  .......";
    		cout<<"\n\n\t\t.........From Sahiwaal to Bahawalpur:..............";
    		cout<<"\n\t\t\t\t................4:00 AM---------9:00 AM  .......";
    		cout<<"\n\n\t\t.........From  lahore to Multan:..............";
    		cout<<"\n\t\t\t\t............7:00 AM---------2:00 PM  .......";
    		cout<<"\n\n\t\t.........From Islamabad to Murree:..............";
    		cout<<"\n\t\t\t\t............10:00 AM---------11:30 AM  .......";
    		cout<<"\n\n\t\t.........From Daska to lahore:..............";
    		cout<<"\n\t\t\t\t............8:30 AM---------10:00 AM  .......";
    		break;
    	case 2:
    		cout<<"\n\n\t\t.........From Sialkot to Gujranwala:..............";
    		cout<<"\n\t\t\t\t............9:00 AM---------10:00 AM  ..........";
    		cout<<"\n\n\t\t.........From  lahore to Kamoki:..................";
    		cout<<"\n\t\t\t\t............12:00 PM---------1:00 PM  ..........";
    		cout<<"\n\n\t\t.........From Islamabad to Rawlpindi:.............";
    		cout<<"\n\t\t\t\t............9:00 AM---------10:00 AM  ..........";
    		cout<<"\n\t\t\t\t................................................";
    		break;
    	case 3:
    		cout<<"\n\n\t\t.........From Komoki to wazirabad:..............";
    		cout<<"\n\t\t\t\t............9:00 AM---------11:00 AM  ........";
    		cout<<"\n\n\t\t.........From  lahore to Gujranwala:............";
    		cout<<"\n\t\t\t\t............12:30 AM---------2:00 PM  ........";
    		cout<<"\n\n\t\t.........From Naran to Nthiya Gali:.............";
    		cout<<"\n\t\t\t\t............6:00 AM---------11:00 AM  ........";
    		cout<<"\n\n\t\t.........From Sialkot to Jehlum:..............";
    		cout<<"\n\t\t\t\t............9:00 AM---------12:00 PM  .......";
    		break;
    	case 4:
    		cout<<"\n\n\t\t.........From Rawalpindi to Attack:..............";
    		cout<<"\n\t\t\t\t............9:00 AM---------11:00 AM  .......";
    		cout<<"\n\n\t\t.........From Sialkot to Quttea:..............";
    		cout<<"\n\t\t\t\t............9:00 AM---------11:00 PM  .......";
    		cout<<"\n\n\t\t.........From Sialkot to islamaba:..............";
    		cout<<"\n\t\t\t\t............9:00 AM---------12:00 AM  .......";
    		
    		default:
    		cout<<"\nYou Enter a wrong no";
    		getch();
    		goto p;
	}
}
void Bus::Booking()
{
	p:
	system("cls");
	string tb_no,s_b_no,cu_name,phone,from,to;
	int found=0,s_no,seats,count=0,s_s_no,ss_no[15],i=0,s_amount,total_amount=0,r_amount;
	
	char x;
	
	cout<<"\n\n\t\t\t\t-------------Bus Managment system-------------";
	fstream file;
	file.open("Bus.txt",ios::in);
	if(!file)
	{
		cout<<"\nFileing openiong error.........";
		
	}
	else{
		cout<<"Enter a bus no=";
		cin>>tb_no;
		file.close();
		file.open("seat.txt",ios::in);
		if(file)
		{
			
		
		file>>s_b_no>>s_s_no;
		while(!file.eof())
		{
			if(tb_no==s_b_no)
			{
				count++;
			}
		file>>s_b_no>>s_s_no;	
		}
		file.close();
	}
		file.open("Bus.txt",ios::in);
		
		file>>b_no>>b_name>>d_name>>b_seats;
		while(!file.eof())
		{
			if(tb_no==b_no)
			{
			   seats=b_seats;
				found++;
			}
			
			file>>b_no>>b_name>>d_name>>b_seats;
		}
		file.close();
		if(seats-count==0)
		{
			cout<<"All seats are booking";
			
		}
	  else	if(found==1)
		{
		do{
			h:
			cout<<"\n\nSeat NO=";
			cin>>s_no;
			if(s_no>seats)
			{
				cout<<"Your seat No is invalid";
				goto h;
			}
			file.open("Seat.txt",ios::in);
			if(!file)
			{
				file.open("seat.txt",ios::app|ios::out);
				file<<tb_no<<"  "<<s_no<<endl;
				file.close();
				
			}
			else{
				file>>s_b_no>>s_s_no;
				while(!file.eof())
				{
					if(tb_no==s_b_no&&s_no== s_s_no)
					{
						cout<<"\n\nSeat is already Book plz try again....";
						goto h;
					}
					file>>s_b_no>>s_s_no;
				}
				file.close();
				file.open("seat.txt",ios::app|ios::out);
				file<<tb_no<<"  "<<s_no<<endl;
				file.close();
			}
			ss_no[i]=s_no;
			i++;
			cout<<"\n\nBooking another seats(y,N)";
			cin>>x; 
		}
		while(x=='Y'||x=='y');	
		system("cls");
		cout<<"\n\n\t\t\t\t-------------Bus Managment system-------------";
		cout<<"\n\n customer Name=";
		cin>>cu_name;
		cout<<"Enter a phone nbr:=";
		cin>>phone;
		cout<<"\n\nFrom=";
		cin>>from;
		cout<<"\n\nTo";
		cin>>to;
		cout<<"\n\nSingle seat amount=";
		cin>>s_amount;
		total_amount=s_amount*i;
		cout<<"\n\nTotal amount="<<total_amount;
		cout<<"\n\nRecive amount=";
		cin>>r_amount;
		file.open("Customer.txt",ios::app|ios::in);
		file<<cu_name<<"  "<<tb_no<<"  "<<phone<<"  "<<i<<"  "<<total_amount<<"\n";
		file.close();
		system("cls");
		cout<<"\n\n\t\t\t\t-------------Bus Managment system-------------";
		cout<<"\n\n\t\t\t\t..............................................";
		cout<<"\n\n\t\t\t\t-------------Booking information--------------";
		cout<<"\n\n\t\t\t\t..............................................";
		cout<<"\n\n\t\t\t\tCustomer Name=:  "<<cu_name;
		cout<<"\n\n\t\t\t\tFrom=:  "<<from;
		cout<<"\n\n\t\t\t\tto=:  "<<to;
		cout<<"\n\n\t\t\t\tTotal seats=:  "<<i;
		cout<<"\n\n\t\t\t\tReserved seats=:  ";
		for(int a=0;a<i;a++)
		{
			if(a!=0)
			cout<<",";
			cout<<"your seat"<<ss_no[a];
		}
		cout<<"\n\n\t\t\t\tSingle seat amount="<<s_amount;
		cout<<"\n\n\t\t\t\tTotal seat amount="<<total_amount;
		cout<<"\n\n\t\t\t\tRecive amount="<<r_amount;
		cout<<"\n\n\t\t\t\tReturn amount="<<r_amount-total_amount;
		cout<<"\n\n\t\t\t\t..............................................";
		cout<<"\n\n\t\t\t\t    Thank you so much for booking";
		cout<<"\n\n\t\t\t\t..............................................";
		}
		else
		{
		cout<<"\n\nBus no invslid";
		getch();
		goto p;
		}
		
	}
}

int main(){
	Bus b;
   p:
   	system("cls");
	string email,pass;
	char ch;
	cout<<"\n\n\t\t\t****Security are required****";
	cout<<"\n\t\t\tEnter Email=";
	cin>>email;
	cout<<"\t\t\tEnter a password=";
	for(int i=1;i<=6;i++)
	{
		ch= getch();
		pass += ch;
		cout<<"*";
	}
	if(email=="o.com" && pass=="khannn")
	{
	  cout<<"\n\n\t\t\t\tLoading";
	  for(int i=0;i<=3;i++)
	  {
	   Sleep(500); 
	  	cout<<".";
		  }	
		  b.menu();
	}
	else{
		cout<<"\n\t\t\tYou Enter a wrong password";
		getch();
		goto p;
		
	}
	
}
