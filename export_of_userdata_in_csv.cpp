#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>

using namespace std;

struct Employe
{
    double ID;
    char Name[100];
    double Age;
    char pos[100];

}emp[1000];

class FileOp
{
public:
    int i=0;
    char ch;
    ofstream fout;
    void pro1()
    {
        cout<< "### Enter the info of the employees ###\n";
        do
        {
            cout<< "Enter the emp_"<<i+1<<" ID :"<<endl;
            cin>>emp[i].ID;
            cout<< "Enter the emp_"<<i+1<<" Name:"<<endl;
            cin>>emp[i].Name;
            cout<< "Enter the emp_"<<i+1<<" Age :"<<endl;
            cin>>emp[i].Age;
            cout<< "Enter the emp_"<<i+1<<" Position :"<<endl;
            cin>>emp[i].pos;
            cout<< "Do you want to add more info?(Y/N)"<<endl;
            cin>>ch;
            i++;

        }while(ch=='Y'||ch=='y');

    }
    void pro2()
    {

        cout<<"ID "<<setw(3)<<"NAME "<<setw(3)<< "AGE" <<setw(3)<< "POSITION "<<endl;
        for(int j=0;j<i;j++)
        {
            cout<< emp[j].ID<<setw(4)<<emp[j].Name<<setw(4)<<emp[j].Age<<setw(4)<< emp[j].pos<<endl;
        }




    }
    void pro3()
    {

        fout.open("task.csv");
        fout<<"ID"<<","<<"NAME"<<","<<"AGE"<<","<<"POSITION"<<endl;

        for(int k=0;k<i;k++)
        {
            fout<<emp[k].ID<<","<<emp[k].Name<<","<<emp[k].Age<<","<<emp[k].pos<<endl;


        }
        fout.close();
    }

};

int main()
{
    FileOp fp;
    fp.pro1();
    fp.pro3();
    return 0;

}
