#pragma once
#include<iostream>
#include"clsDate.h"
#include"clsUser.h"
#include"Global.h"
using namespace std;

class clsScreen
{
   
   static void _ShowUserAndTimeScreen()
    { 
        clsDate Date;
        cout << "\t\t\t\t\tUser: " << CurrentUser.GetUserName() << endl;
        cout << "\t\t\t\t\tDate:" <<Date.DateToString() << endl<<endl;
    }
protected:

    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";

        _ShowUserAndTimeScreen();
    }

    static bool CheckAccessRights(clsUser::enPermissions Permission)
    {

        if (!CurrentUser.CheckAccessPermission(Permission))
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
        else
        {
            return true;
        }
    }




};

