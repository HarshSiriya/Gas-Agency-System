#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string>
#include<stdlib.h>

using namespace std;
class agency
{
	private:
		string name,unique,cylinder,contact,mail,type, address;
	public:
		
		void enter();                                                                                                                            //use this to enter details of student
		void show();                                                                                                                             //use this to see details of student
		void delete_record();                                                                                                                    //use this to delete the details of student
		void update();                                                                                                                           //use this to update the details of any student
		void search();
		void agency_details();
		void emergency_service();                                                                                                                           // use this to search the specific student through their roll no
		

};

void agency::enter()
{
    system("cls");
    fstream inFile;
    cout << "Please enter details .." << endl;
    cout << " " << endl;
    cout << " Enter Name : ";
    cin >> name;
    cout << " Enter Unique ID. : ";
    cin >> unique;
    cout << " Enter No. of Cylinder : ";
    cin >> cylinder;
    cout << " Enter mail Id : ";
    cin >> mail;
    cout << " Enter Contact No.: ";
    cin >> contact;
    cout << " Enter Type(Commercial/Domestic) : ";
    cin >>type;
    cout << " Enter City.: ";
    cin >> address;
    inFile.open("harshsiriya.txt", ios::app | ios::out);
    inFile << "  " << name << "  " << unique << "  " << cylinder << "  " << mail << "  " << contact << "  " << type << "  " << address <<"\n";                                                             
    inFile.close();                                                                                                                                                                                 
}
void agency::show()
{
    system("cls");
    fstream inFile;
    int total = 1;
    cout << "-----------------------------------------------------------------------------------------------" << endl;
    cout << "                                Agency Recorded Data is                                        " << endl;
    cout << "-----------------------------------------------------------------------------------------------" << endl;
    inFile.open("harshsiriya.txt", ios::in);
    if (!inFile)
    {
        cout << "\n\n Data not found....";
        inFile.close();
    }
    else
    {
        inFile >> name >> unique >> cylinder >> mail >> contact >> type >> address;
        while (!inFile.eof())
        {
            
            cout<<"  Name                 : "<< name << endl;
            cout<<"  Unique ID            : "<< unique << endl;
            cout<<"  No. of cylinder      : "<< cylinder << endl;
            cout<<"  mail Id              : "<< mail << endl;
            cout<<"  Contact No.          : "<< contact <<endl;
            cout<<"  type                 : "<< type << endl;
            cout<<"  Address              : "<< address << endl;
            inFile >> name >> unique >> cylinder >> mail >> contact >> type >> address;
        }
        if (total == 0)
        {
            cout << "\n\t\t Data not found....";
        }
    }
    inFile.close();
}
void agency::update()
{
    system("cls");
    fstream file, file1;
    string uid;
    int match = 0;
    file.open("harshsiriya.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t No Data Found....";                                                                                                                                          
        file.close();
    }
    else
    {
        cout << "\n Enter the Unique ID you wish to order cylinder: ";
        cin >> uid;
        file1.open("Record.txt", ios::app | ios::out);
        file >> name >> unique >> cylinder >> mail >> contact >> type >> address;
        while (!file.eof())
        {
            if (uid != unique)
            {
                file1 << "  " << name << "  " << unique << "  " << cylinder << "  " << mail << "  " << contact << "  " << type << "  " << address <<"\n";
            }
            else
            {
                cout << "\n Enter Name: ";
                cin >> name;
                cout << "\n Enter Unique ID.: ";
                cin >> unique;
                cout << "\n Enter No. of cylinder: ";
                cin >> cylinder;
                cout << "\n Enter E-mail Id: ";
                cin >> mail;
                cout << "\n Enter Contact No.: ";
                cin >> contact;
                cout<<"\n Type(commercial/domestic) : " ;
                cin>>type;
                cout<<"\n Address : ";
                cin>>address;


                
                file1 << "  " << name << "  " << unique << "  " << cylinder << "  " << mail << "  " << contact << "  " << type  << "  "  << "  " << address <<"\n";
                match++;
            }
            file >> name >> unique >> cylinder >> mail >> contact >> type >> address ;
            if (match == 0)
            {
                cout << "\n\t\t Not found, Invalid data!";
            }
        }
        file1.close();
        file.close();
        remove("harshsiriya.txt");
        rename("Record.txt", "harshsiriya.txt");
    }
}
void agency::search()
{
    system("cls");
    fstream file;
    int match = 0;
    file.open("harshsiriya.txt", ios::in);
    if (!file)
    {
        cout << "Search Operation" << endl;
        cout << "\n No data Found...";
    }
    else
    {
        string uid;
        cout << "Search Operation" << endl;
        cout << "\n Enter Unique ID you wish to Search : ";
        cin >> uid;
        file >> name >> unique >> cylinder >> mail >> contact >> type >> address;
        while (!file.eof())
        {
            if (uid == unique)
            {
                cout<<"  Name : " << name << endl;
                cout<<"  Unique ID. : " << unique << endl;
                cout<<"  Cylinder: " << cylinder << endl;
                cout<<"  E-mail Id: " << mail << endl;
                cout<<"  Contact No. : " << contact <<endl;
                cout<<"  Type : "<< type << endl;
                cout<<"  Address: " << address << endl;
                match++;
            }
            file >> name >> unique >> cylinder >> mail >> contact >> type >> address;
        }
        if (match == 0)
        {
            cout << (" Sorry ! Data Not Found.");
        }
        file.close();
    }
}
void agency::delete_record()
{
    system("cls");
    fstream file, file1;
    string uid1;
    int match = 0;
    cout << "Delete Account Details" << endl;
    file.open("harshsiriya.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t Data not found.";
    }
    else
    {
        cout << "\n Enter Unique ID to Delete Account : ";
        cin >> uid1;
        file1.open("Record.txt", ios::app | ios::out);
        file >> name >> unique >> cylinder >> mail >> contact >> type >> address;
        while (!file.eof())
        {
            if (uid1 != unique)
            {
                file1 << "  " << name << "  " << unique << "  " << cylinder << "  " << mail << "  " << contact << "  " << type << "  " << address <<"\n";
            }
            else
            {
                match++;
                cout << "\n\t\t Operation Deletion Done\n";
            }
            file >> name >> unique >> cylinder >> mail >> contact >> type >> address;
        }
        if (match == 0)
        {
            cout << "\n\t\t Sorry ! Record not found.";
        }
        file1.close();
        file.close();
        remove("harshsiriya.txt");
        rename("Record.txt", "harshsiriya.txt");
    }
}

void agency::agency_details()
{
	cout<<"\n*********************************************************\n";
	cout<<"****** SIRIYA GAS AGENCY ******\n";
	cout<<"contact dealership : 9975055420\n";
	cout<<"mail address : siriyagasservice@hplpg.com\n";
	cout<<"website : www.siriyagasagency.com\n";
	cout<<"\n*********************************************************\n";
}
void agency::emergency_service()
{
	cout<<"\n*********************************************************\n";
	cout<<"24x7 Helpline number : 9766899899\n";
	cout<<"Enquiry : Enquiry - My HpGas\n";
	cout<<"Emergency number : 1906\n";
	cout<<"Fire Emergency contact : 112\n";
	cout<<"\n*********************************************************\n";
}
int main()
{
    system("COLOR B0");
    agency pr;
	int value;
	while(true)                                                                                                                                                                                 
	{
    cout<<"----------------------------------------------------------------------------------------------------" << endl;
	cout<<"                             ----Please Choose any Option----"<<endl;
    cout<<"----------------------------------------------------------------------------------------------------" << endl;
	cout<<"\n|   Press 1 --> Register New Account                  |"<<endl;
	cout<<"|   Press 2 --> Show Registered Accounts              |"<<endl;
	cout<<"|   Press 3 --> Search Account                        |"<<endl;
	cout<<"|   Press 4 --> Order Cylinder on Registered Accounts |"<<endl;
	cout<<"|   Press 5 --> Delete Account                        |"<<endl;
	cout<<"|   Press 6 --> Agency Details                        |"<<endl;
	cout<<"|   Press 7 --> Helpline & Emergency Services         |"<<endl;
	cout<<"|   Press 8 --> Exit                                  |"<<endl;
	cin>>value;
	switch(value)
	{
		case 1:
			 pr.enter();
			break;
		case 2:
			pr.show();
			break;
		case 3:
			pr.search();
			break;
		case 4:
			pr.update();
			break;
		case 5:
			pr.delete_record();
			break;
			
		case 6:
			pr.agency_details();
			break;
			
		case 7:
			pr.emergency_service();
			break;
			
		case 8:
			cout<<"\n Thank You  \n Visit Again";
			
			exit(0);
			break;
				
		default:
			cout<<"Wrong Choice...!!\n\n\n\n Please Press again Between [1 to 6].."<<endl;
			break;
	}
	
}   
}
