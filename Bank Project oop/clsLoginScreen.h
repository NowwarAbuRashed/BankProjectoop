#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"

class clsLoginScreen :protected clsScreen
{

private:

    static  void _Login()
    {
       
            bool LoginFaild = false;
            Trials = 3;
            string Username, Password;
            do
            {

                if (LoginFaild)
                {
                    cout << "\nInvlaid Username/Password!\n";
                    cout << "You have " << --Trials << " Trials to login.\n\n";
                    if (Trials == 0)
                    {
                        cout << "\n Your are Locked after " << 3 << " faild trails\n\n";
                        return;
                    }
                }

                cout << "Enter Username? ";
                cin >> Username;

                cout << "Enter Password? ";
                cin >> Password;

                CurrentUser = clsUser::Find(Username, Password);

                LoginFaild = CurrentUser.IsEmpty();

            } while (LoginFaild);
            CurrentUser.RegisterLogIn();
            clsMainScreen::ShowMainMenue();
        
    }

public:


    static void ShowLoginScreen()
    {
        while (true&& Trials)
        {
            system("cls");
            _DrawScreenHeader("\t  Login Screen");
            _Login();
        }

    }

};

