#pragma once
#include <iostream>
#include "clsScreen.h"
#include"clsBankClient.h"
#include <iomanip>
#include<string>

using namespace std;


class clsTransferLogScreen:protected clsScreen
{


    static void _PrintUserRecordLine(clsBankClient::stTransferslog User)
    {

        cout << setw(8) << left << "" << "| " << setw(25) << left << User.DateTime;
        cout << "| " << setw(9) << left << User.AccountNumberFrom;
        cout << "| " << setw(9) << left << User.AccountNumberTo;
        cout << "| " << setw(9) << left << User.Amount;
        cout << "| " << setw(9) << left << User.AccountBalansse1;
        cout << "| " << setw(9) << left << User.AccountBalansse2;
        cout << "| " << setw(9) << left << User.NameUsre;
    }

public:

	static void ShowTransferLogScreen()
	{
		
		vector <clsBankClient::stTransferslog> Transferslog = clsBankClient::GetTransferslogList();

		string Title = "\t  Transfer Log List Screen";
		string SubTitle = "\t    (" + to_string(Transferslog.size()) + ") User(s).";

		_DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(25) << "Date/Time";
        cout << "| " << left << setw(9) << "s.Acct";
        cout << "| " << left << setw(9) << "d.Acct";
        cout << "| " << left << setw(9) << "Amount";
        cout << "| " << left << setw(9) << "s.Balance";
        cout << "| " << left << setw(9) << "d.Balance";
        cout << "| " << left << setw(9) << "User";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (Transferslog.size() == 0)
            cout << "\t\t\t\tNo Users Available In the System!";
        else

            for (clsBankClient::stTransferslog User : Transferslog)
            {

                _PrintUserRecordLine(User);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

    }





	
};

