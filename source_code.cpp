#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<fstream.h>
#include<string.h>
#include<iomanip.h>
#define input1() gotoxy(30,15)
#define input2() gotoxy(37,16)
class student
{
	char admno[100];
	char ad_date[50];
	int fees;
	int roll_no;
	char subs[200];
	char bld_grp[10];
	char stream[20];
	void sub_allot()
	{
		char c,d;
		if(classes<=5) strcpy(subs,"English,Hindi,Maths,EVS");
		else if(classes<=8) strcpy(subs,"English,Hindi,Maths,Sanskrit,Science,SST");
		else if(classes<=10) strcpy(subs,"English,Hindi,Maths,Science,SST");
		else if(classes<=12&&strcmpi(stream,"science")==0) {
			cout<<"Choose b for BIOLOGY , c for C.S : ";
			cin>>c;
			cout<<"Choose m for MATHS , h for HINDI : ";
			cin>>d;
			if(c=='b'&&d=='m') strcpy(subs,"English,Chemistry,Physics,Biology,Maths");
			else if(c=='c'&&d=='m') strcpy(subs,"English,Chemistry,Physics,Computer Science,Maths");
			else if(c=='b'&&d=='h') strcpy(subs,"English,Chemistry,Physics,Biology,Hindi");
			else if(c=='c'&&d=='h') strcpy(subs,"English,Chemistry,Physics,Comp. Science,Hindi");
		}
		else if(classes<=12&&strcmpi(stream,"arts")==0) strcpy(subs,"English,Hindi,History,Geography,Economics");
	}
	void fees_cal()
	{
		if(classes>=11) fees=3000;
		else if(classes>=9) fees=2500;
		else if(classes>=5) fees=2000;
		else if(classes>=1) fees=1800;
	}
	public:
		char name[100];
		int classes;
	void input()
	{
		cout<<"\n\t\t*************STUDENT DATA ENTRY*************\n";
		cout<<"Enter the name of the student: ";
		gets(name);
		cout<<"Enter the admission no. of the student: ";
		gets(admno);
		cout<<"Enter the admission date of the student(dd/mm/yyyy): ";
		gets(ad_date);
		cout<<"Enter the class of the student ";
		cin>>classes;
		if(classes>=11&&classes<=12)
			{
				cout<<"Enter stream: ";
				gets(stream);
			}
		sub_allot();
		cout<<"Enter roll no.: ";
		cin>>roll_no;
		cout<<"Enter blood group: ";
		gets(bld_grp);
		fees_cal();
		cout<<"\t\t*************##################*************\n";
	}
	void display()
	{
		cout<<"\t\t*************STUDENT PROFILE*************\n";
		cout.setf(ios::left,ios::adjustfield);
		cout<<setfill('-')<<setw(20)<<"\t\tAdmission no"<<" "<<admno<<endl;
		cout<<setfill('-')<<setw(20)<<"\t\tAdm. date"<<" "<<ad_date<<endl;
		cout<<setfill('-')<<setw(20)<<"\t\tName";
		cout<<" ";
		puts(name);
		cout.setf(ios::left,ios::adjustfield);
		cout<<setfill('-')<<setw(20)<<"\t\tClass"<<" "<<classes<<endl;
			if(classes>=11&&classes<=12)
			{
				cout.setf(ios::left,ios::adjustfield);
				cout<<setfill('-')<<setw(20)<<"\t\tstream"<<" ";
				puts(stream);
			}
		cout.setf(ios::left,ios::adjustfield);	
		cout<<setfill('-')<<setw(20)<<"\t\tFees(quaterly)"<<" "<<fees<<endl;
		cout<<setfill('-')<<setw(20)<<"\t\tRoll no"<<" "<<roll_no<<endl;
		cout<<setfill('-')<<setw(20)<<"\t\tBlood group"<<" "<<bld_grp<<endl;
		cout<<setfill('-')<<setw(20)<<"\t\tSubjects"<<" ";
		puts(subs);
		cout<<"\t\t*************###############*************\n";	
	}
	
	
}student1;
class teacher
{
	public:
	char frst_nm[50];
	char lst_nm[50];
	char qual[100];
	int exp;
	char pay[10];
	char sub[20];
	char phn[14];
	void input()
	{
		cout<<"\n\t\t*************TEACHER DATA ENTRY*************\n";
		cout<<"Enter First name: ";
		gets(frst_nm);
		cout<<"Enter Last name:: ";
		gets(lst_nm);
		cout<<"Enter qualification: ";
		gets(qual);
		cout<<"Enter experiance(year): ";
		cin>>exp;
		cout<<"Enter Subject he/she teaches: ";	
		gets(sub);
		cout<<"Enter the salary per month: ";
		gets(pay);
	    cout<<"Enter Phone Number: ";
	    gets(phn);
	    cout<<"\t\t*************##################*************\n";
	    
	}
	void display()
	{
		cout<<"\t\t*************TEACHER PROFILE*************\n";
		cout.setf(ios::left,ios::adjustfield);	
		cout<<setfill('-')<<setw(20)<<"\t\tFirst name"<<" ";
		puts(frst_nm);
		cout<<setfill('-')<<setw(20)<<"\t\tLast name"<<" ";
		puts(lst_nm);
		cout<<setfill('-')<<setw(20)<<"\t\tqualification"<<" ";
		puts(qual);
		cout<<setfill('-')<<setw(20)<<"\t\texperiance(year)"<<" ";
		cout<<exp<<endl;
		cout<<setfill('-')<<setw(20)<<"\t\tSubject"<<" ";	
		puts(sub);
		cout<<setfill('-')<<setw(20)<<"\t\tsalary per month"<<" ";
		puts(pay);
	    cout<<setfill('-')<<setw(20)<<"\t\tPhone Number"<<" ";
	    puts(phn);
	    cout<<"\t\t*************###############*************\n";
	}
	
}teacher1;

void main()
{
	int choice;
	char save;
	ifstream student_in,teacher_in;	//FOR HANDLING STUDENT_DATA.DAT
	ofstream student_out,teacher_out;	//FOR HANDLING TEACHER_DATA.DAT
main_menu:	//MAIN MENU
 clrscr();
 cout.setf(ios::left,ios::adjustfield);
 cout<<setfill('/')<<setw(80)<<"";
 cout<<"\n\n\t\t\tSCHOOL MANAGEMENT PROGRAM\n\n";
 cout<<setfill('/')<<setw(80)<<"";
  cout<<"\n\n\t\t\t\tMAIN SCREEN\n\n";
 cout<<"Enter your choice: "<<endl;
 cout<<"1.Students information"<<endl;
 cout<<"2.Teacher information"<<endl;
 cout<<"3.Exit program"<<endl;
 input1();
 cout<<"ENTER YOUR CHOICE:";
 input2();
 cin>>choice;
 switch(choice)
 {
 	case 1: {
 	student_menu:	//STUDENT MENU START
    clrscr(); 
    cout<<setfill('/')<<setw(80)<<"";
 	cout<<"\n\n\t\t\tSTUDENTS INFORMATION AND BIO DATA SECTION\n\n";
 	cout<<setfill('/')<<setw(80)<<"";
 	cout<<"\n\n";
	cout<<"Enter your choice: "<<endl;
	cout<<"1.Create new entry\n";
	cout<<"2.Find and display entry\n";
	cout<<"3.Search and delete a record\n";
	cout<<"4.List all students\n";
	cout<<"5.Jump to main\n";
	input1();
 	cout<<"ENTER YOUR CHOICE:";
 	input2();
 	cin>>choice;
 	clrscr();
	switch(choice)
	{
						//STUDENT DATA ENTRY
		case 1:
		
			student_out.open("student_data.dat",ios::binary|ios::out|ios::app);
			student1.input();
			cout<<"Press Y to save and N to discard:";
			cin>>save;
			if(save=='y'||save=='Y')
			{
				student_out.write((char*)&student1,sizeof(student1));
				cout<<"\n \t\tData written successfully...";
			}
			else
				cout<<"\t\tData discarded...";
			
			student_out.close();
			cout<<"\npress any key two times to jump to student menu...";
			getch();
			getch();
			goto student_menu;
			
						//STUDENT DATA SEARCH AND DISPLAY
		case 2:{
			char full_name[100];
			char found='f';
			cout<<"\t\t*************SEARCH RECORD AND DISPLAY*************\n";
			cout<<"Enter the full name of the student: ";
			gets(full_name);
			student_in.open("student_data.dat",ios::binary|ios::in);
			while(!student_in.eof())
			{
				student_in.read((char*)&student1,sizeof(student1));
				if(student_in.eof()) break;
				if(strcmpi(student1.name,full_name)==0)
				{
					found='t';
					cout<<"\tData found...\n";
					student1.display();
					
				}		
			}
			if(found=='f')
				cout<<"\n\t\tdata not found...";
				student_in.close();
				cout<<"\npress any key two times to jump to student menu...";
			getch();
			getch();
			goto student_menu;
	        	}
	        	
	        		//STUDENT DATA SEARCH AND Delete
  		case 3:
  		{
  			char full_name[100];
			char found='f',confirm='n';
			cout<<"\t\t\tSTUDENT'S RECORD DELETION SECTION\n\n\n";
			cout<<"Enter the full name of the student to be deleted: ";
			gets(full_name);
			student_in.open("student_data.dat",ios::binary|ios::in);
			ofstream file("temp.dat",ios::out|ios::binary);
			while(!student_in.eof())
			{
				student_in.read((char*)&student1,sizeof(student1));
				if(student_in.eof()) break;
				if(strcmpi(student1.name,full_name)==0)
				{
					found='t';
					cout<<"Data found...\n";
					student1.display();
					cout<<"Are you sure you want to delete this record? [y/n]";
					cin>>confirm;
					if(confirm=='n')
						file.write((char*)&student1,sizeof(student1));
				}
				else
					file.write((char*)&student1,sizeof(student1));		
			}
			if(found=='f')
				cout<<"\n\t\tdata not found...";
				student_in.close();
				file.close();
				remove("student_data.dat");
				rename("temp.dat","student_data.dat");
				cout<<"\npress any key two times to jump to student menu...";
			getch();
			getch();
			goto student_menu;
	}
		case 4:
			{int i=1;
			cout<<"List all students:\n";
			student_in.open("student_data.dat",ios::binary|ios::in);
			cout<<"sl.no.\tNAME\n";
			while(!student_in.eof())
			{
				student_in.read((char*)&student1,sizeof(student1));
				if(student_in.eof()) break;
				cout<<i<<".\t"<<student1.name<<"\t"<<endl;
				i++;
						
			}
			student_in.close();
			i=1;
			cout<<"\npress any key two times to jump to student menu...";
			getch();
			getch();
			goto student_menu;}
  		case 5:
  			goto main_menu;
		default:
			goto student_menu;
	}
			
			
 			}
	case 2:
	{
		teacher_menu:		//TEACHERS MENU
		    clrscr(); 
  	cout<<setfill('/')<<setw(80)<<"";
 	cout<<"\n\n\t\t\tTEACHERS INFORMATION AND BIO DATA SECTION\n\n";
	cout<<setfill('/')<<setw(80)<<"";
 	cout<<"\n\n";
	cout<<"Enter your choice: "<<endl;
	cout<<"1.Create new entry\n";
	cout<<"2.Find and display entry\n";
	cout<<"3.Search and delete a record\n";
	cout<<"4.List all teachers\n";
	cout<<"5.Jump to main\n";
	input1();
 	cout<<"ENTER YOUR CHOICE:";
 	input2();
 	cin>>choice;
 	clrscr();
	switch(choice)
	{
						//TEACHER DATA ENTRY
		case 1:			
			teacher_out.open("teacher_data.dat",ios::binary|ios::out|ios::app);
			teacher1.input();
			cout<<"\n\nPress Y to save and N to discard:";
			cin>>save;
			if(save=='y'||save=='Y')
			{
				teacher_out.write((char*)&teacher1,sizeof(teacher1));
				cout<<"\n \t\tData written successfully...";
			}
			else
				cout<<"\t\tData discarded...";
			teacher_out.close();
			cout<<"\npress any key two times to jump to teacher's menu...";
			getch();
			getch();
			goto teacher_menu;
			
							//TEACHER DATA SEARCH AND DISPLAY
		case 2:{		
			char full_name[100];
			char found='f';
			cout<<"\t\t*************SEARCH RECORD AND DISPLAY*************\n";
			cout<<"Enter the first name of the teacher: ";
			gets(full_name);
			teacher_in.open("teacher_data.dat",ios::binary|ios::in);
			while(!teacher_in.eof())
			{
				teacher_in.read((char*)&teacher1,sizeof(teacher1));
				if(teacher_in.eof()) break;
				if(strcmpi(teacher1.frst_nm,full_name)==0)
				{
					found='t';
					cout<<"\tData found...\n";
					teacher1.display();
				}			
			}
			if(found=='f')
				cout<<"\n\t\tdata not found...";
				teacher_in.close();
				cout<<"\npress any key two times to jump to teacher's menu...";
			getch();
			getch();
			goto teacher_menu;
	        	}
	        	
	        			//TEACHER DATA SEACH AND DELETE
  		case 3:
  			{		
  			char full_name[100];
			char found='f',confirm='n';
			cout<<"\t\t\tTEACHER'S RECORD DELETION SECTION\n\n\n";
			cout<<"Enter the first name of the teacher to be deleted: ";
			gets(full_name);
			teacher_in.open("teacher_data.dat",ios::binary|ios::in);
			ofstream file("temp.dat",ios::out|ios::binary);
			while(!teacher_in.eof())
			{
				teacher_in.read((char*)&teacher1,sizeof(teacher1));
				if(teacher_in.eof()) break;
				if(strcmpi(teacher1.frst_nm,full_name)==0)
				{
					found='t';
					cout<<"\t\tData found...\n";
					teacher1.display();
					cout<<"Are you sure you want to delete this record? [y/n]";
					cin>>confirm;
					if(confirm=='n')
						file.write((char*)&teacher1,sizeof(teacher1));
				}
				else
					file.write((char*)&teacher1,sizeof(teacher1));		
			}
			if(found=='f')
				cout<<"\n\t\tdata not found...";
				teacher_in.close();
				file.close();
				remove("teacher_data.dat");
				rename("temp.dat","teacher_data.dat");
				cout<<"\npress any key two times to jump to student menu...";
			getch();
			getch();
			goto student_menu;
	}	
		case 4:
			{int i=1;
			teacher_in.open("teacher_data.dat",ios::binary|ios::in);
			cout<<"sl.no.\tNAME\n";
			while(!teacher_in.eof())
			{
				teacher_in.read((char*)&teacher1,sizeof(teacher1));
				if(teacher_in.eof()) break;
				cout<<i<<".\t"<<teacher1.frst_nm<<" "<<teacher1.lst_nm<<endl;
				i++;
						
			}
			teacher_in.close();
			i=1;
			cout<<"\npress any key two times to jump to student menu...";
			getch();
			getch();
			goto teacher_menu;}
  		case 5:
  			goto main_menu;
		default:
			goto teacher_menu;
	}
	}
	case 3:
		exit(0);
	default:
		goto main_menu;
 }
 

}