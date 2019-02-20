/****************************************************************************
If you get "Try to run as an administrator!" error,                       ***
in a bin folder when you compile the program you                          ***
will see a file named WebSiteBlocking                                     ***
Run that file from the terminal with the sudo ./WebSiteBlocking command.  ***
*****************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int selection;
    string website;
    // ofstream used for writing in a file
    ofstream out;
    start:
        cout<<"Select the operating system you are using:"<<endl;
        cout<<"1:Windows"<<endl<<"2:Linux"<<endl;
        cin>>selection;
    switch(selection)
    {
    case 1:
        cout<<"Enter the website to block (www.example.com):";
        cin>>website;
        out.open("C:/Windows/System32/drivers/etc/hosts",ios::app);
        if(!out)
        {
            cout<<"Try to run as an administrator!"<<endl;
        }
        else
        {
            out<<"127.0.0.1"<<"\t"<<website<<endl;
            cout<<website<<"\tBlocked"<<endl;
        }
        break;
    case 2:
        cout<<"Enter the website to block (www.example.com):";
        cin>>website;
        out.open("/etc/hosts",ios::app);
        if(!out)
        {
            cout<<"Try to run as an administrator!"<<endl;
        }
        else
        {
            out<<"127.0.0.1"<<"\t"<<website<<endl;
            cout<<website<<"\tBlocked"<<endl;
        }
        break;
    default:
       cout<<"You made wrong selection!"<<endl;
       goto start;
       break;
    }
    return 0;
}
