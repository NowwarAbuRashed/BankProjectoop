#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
using namespace std;


class clsLoginRegisterMenue :protected clsScreen
{
   
   

   
    static void _PrintUserRecordLine(clsUser::stLoginRegisterRecord UserLogin)
    {

        cout << setw(8) << left << "" << "| " << setw(35) << left << UserLogin.DateTime;
        cout << "| " << setw(20) << left << UserLogin.UserName;
        cout << "| " << setw(20) << left << UserLogin.Password;
        cout << "| " << setw(10) << left << UserLogin.Permissions;

    }
    

public:

    static void ShowLoginRegister()
	{

        system("cls");
        if (!CheckAccessRights(clsUser::enPermissions::pShowLogInRegister))
        {
            return;// this will exit the function and it will not continue
        }
        vector <clsUser::stLoginRegisterRecord> vUsersLogin = clsUser::GetLoginRegisterList();

        string Title = "\t  Login Register List Screen";
        string SubTitle = "\t    (" + to_string(vUsersLogin.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
        cout << "| " << left << setw(20) << "UserName";
        cout << "| " << left << setw(20) << "Password";
        cout << "| " << left << setw(10) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (vUsersLogin.size() == 0)
            cout << "\t\t\t\tNo Users Available In the System!";
        else

            for (clsUser::stLoginRegisterRecord User : vUsersLogin)
            {

                _PrintUserRecordLine(User);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
    }


	


};

