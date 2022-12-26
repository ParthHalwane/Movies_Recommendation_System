#include <iostream>
#include <istream>
#include <ostream>
#include <fstream>
#include <stdlib.h>
#include <string>
using namespace std;
class genre
{
public:
    int flag = 0;
    string w;
    void select();
    void login();
    void registr();
    void choose_genre();
    void action();
    void actionenglish();
    void actionhindi();
    void comedy();
    void comedyenglish();
    void comedyhindi();
    void romance();
    void romanceenglish();
    void romancehindi();
    void thriller();
    void thrillerenglish();
    void thrillerhindi();
    void scifi();
    void scifienglish();
    void scifihindi();
};
void genre::login()
{
    int flag;
    string user, pass, u, p;
    system("cls");
    cout << "Please enter the following details" << endl;
    cout << "USERNAME : ";
    cin >> user;
    cout << "PASSWORD : ";
    cin >> pass;

    ifstream input("data.txt");
    while (input >> u >> p)
    {
        if (u == user && p == pass)
        {
            flag = 1;
            system("cls");
        }
    }
    input.close();
    if (flag == 1)
    {
        cout << "\nHello " << user << "\nLOGIN SUCCESSFUL\n";
        choose_genre();
    }
    else
    {
        cout << "\nNo info in our Database\n";
        cout << "Register below if haven't already\n"
             << endl;
        registr();
    }
}

void genre::registr()
{
    string r_name, r_pass, ru, rp;
    cout << "Enter the username : ";
    cin >> r_name;
    cout << "\nEnter the password : ";
    cin >> r_pass;

    try
    {
        if (r_pass.length() < 8)
        {
            cout << "\nPassword must be atleast 8 Characters Long" << endl;
            throw r_pass;
        }
        bool integer = false;
        bool ok;
        for (int i = 0; i < r_pass.length(); i++)
            if (isdigit(r_pass[i]))
                integer = true;
        if (!integer)
        {
            ok = false;
            cout << "\nPassword must have atleast One Digit (0-9)" << endl;
            throw r_pass;
        }
        else
        {
            ok = true;
            ofstream registered("data.txt", ios::app);
            registered << r_name << ' ' << r_pass << endl;
            system("cls");
            cout << "\nYou are successfully registered\n";
            registered.close();
            select();
        }
    }
    catch (string regpass)
    {
        cout << "Invalid Password Format!!!\n"
             << endl;
        registr();
        system("cls");
    }
}

void genre::choose_genre()
{
    string gen;
    cout << "\n***********************************************************************\n";
    cout << "Choose any one of the below genres :\n";
    cout << "1. ACTION" << endl;
    cout << "2. COMEDY" << endl;
    cout << "3. ROMANCE" << endl;
    cout << "4. THRILLER" << endl;
    cout << "5. SCIFI" << endl;
    cout << "\nChoose your genre of interest : ";
    cin >> gen;
    cout << "\n***********************************************************************\n";
    if (gen.length() > 1)
    {
        cout << "TRY AGAIN" << endl;
        choose_genre();
    }
    else if (gen == "1" || gen == "2" || gen == "3" || gen == "4" || gen == "5")
    {
        int gene = stoi(gen);
        switch (gene)
        {
        case 1:
            action();
            break;
        case 2:
            comedy();
            break;
        case 3:
            romance();
            break;
        case 4:
            thriller();
            break;
        case 5:
            scifi();
            break;
        }
    }
    else
    {
        system("cls");
        cout << "\nSelect appropriate option..." << endl;
        choose_genre();
    }
}

void genre::select()
{
    string choice;
    cout << "***********************************************************************\n";
    cout << "                      WELCOME TO LOGIN PAGE                               \n";
    cout << "***********************************************************************\n\n";
    cout << "1.LOGIN" << endl;
    cout << "2.REGISTER" << endl;
    cout << "3.USE AS GUEST WITHOUT SIGNING IN" << endl;
    cout << "\nEnter your choice :";
    cin >> choice;
    cout << endl;
    if (choice.length() > 1)
    {
        cout << "TRY AGAIN" << endl;
        select();
    }
    else if (choice == "1" || choice == "2" || choice == "3")
    {
        int choose = stoi(choice);
        switch (choose)
        {
        case 1:
            login();
            break;
        case 2:
            registr();
            break;
        case 3:
            cout << "Welcome to the movies recommendation page.\n";
            choose_genre();
            break;
        }
    }
    else
    {
        cout << "TRY AGAIN" << endl;
        select();
    }
}
void genre::actionenglish()
{
    int no, lr = 0;
    ifstream actionfilee;
    actionfilee.open("actiondataenglish.txt");
    string actiondatae;
    if (actionfilee.is_open())
    {
        while (actionfilee)
        {
            getline(actionfilee, actiondatae);
            cout << actiondatae << '\n';
        }
        actionfilee.close();
        cout << "\nEnter the number of movie you wanted to watch : ";
        cin >> no;
        actionfilee.open("actiondataenglish.txt");
        while (actionfilee)
        {
            getline(actionfilee, actiondatae);
            lr++;
            if (no == lr)
            {
                actionfilee.close();
                cout << "\n***********************************************************************\n";
                cout << "You selected : " << actiondatae;
                cout << "\nDo you wanted to watch this movie : ";
                cin >> w;
                if (w == "y")
                {
                    fstream ae;
                    int ct = 0;
                    string ade;
                    ae.open("actiondataenglishlinks.txt");
                    if (ae.is_open())
                    {
                        while (ae)
                        {
                            getline(ae, ade);
                            ct++;
                            if (ct == no)
                            {
                                ae.close();
                                string got = "start " + ade;
                                system(got.c_str());
                            }
                        }
                    }
                    cout << "\nThanks for watching" << endl;
                    flag = 1;
                    break;
                }
                else
                {
                    actionenglish();
                }
            }
        }
        if (flag == 0)
        {
            cout << "\nNo such movie in recommendation" << endl;
        }
    }
    else
    {
        cout << "Couldn't open file\n";
    }
}
void genre::actionhindi()
{
    int no, lr = 0;
    ifstream actionfileh;
    actionfileh.open("actiondatahindi.txt");
    string actiondatah;
    if (actionfileh.is_open())
    {
        while (actionfileh)
        {
            getline(actionfileh, actiondatah);
            cout << actiondatah << '\n';
        }
        actionfileh.close();
        cout << "\nEnter the number of movie you wanted to watch : ";
        cin >> no;
        actionfileh.open("actiondatahindi.txt");
        while (actionfileh)
        {
            getline(actionfileh, actiondatah);
            lr++;
            if (no == lr)
            {
                actionfileh.close();
                cout << "\n***********************************************************************\n";
                cout << "You selected : " << actiondatah;
                cout << "\nDo you wanted to watch this movie : ";
                cin >> w;
                if (w == "y")
                {
                    fstream ah;
                    int ct = 0;
                    string adh;
                    ah.open("actiondatahindilinks.txt");
                    if (ah.is_open())
                    {
                        while (ah)
                        {
                            getline(ah, adh);
                            ct++;
                            if (ct == no)
                            {
                                ah.close();
                                string got = "start " + adh;
                                system(got.c_str());
                            }
                        }
                    }
                    cout << "\nThanks for watching" << endl;
                    flag = 1;
                    break;
                }
                else
                {
                    actionhindi();
                }
            }
        }
        if (flag == 0)
        {
            cout << "\nNo such movie in recommendation" << endl;
        }
    }
    else
    {
        cout << "Couldn't open file\n";
    }
}
void genre::action()
{
    string choice;
    cout << "Languages available :" << endl;
    cout << "1. English" << endl;
    cout << "2. Hindi" << endl;
    cout << "Choose your language of preference : ";
    cin >> choice;
    cout << "\n***********************************************************************\n";
    if (choice.length() > 1)
    {
        cout << "TRY AGAIN" << endl;
        action();
    }
    else if (choice == "1" || choice == "2")
    {
        int choose = stoi(choice);
        switch (choose)
        {
        case 1:
            cout << "Here we have a list of top 10 ACTION English movies :" << endl;
            actionenglish();

            break;
        case 2:
            cout << "Here we have a list of top 10 ACTION Hindi movies :" << endl;
            actionhindi();
            break;
        }
    }
    else
    {
        cout << "TRY AGAIN" << endl;
        action();
    }
}
void genre::comedyenglish()
{
    int no, lr = 0;
    ifstream comedyfilee;
    comedyfilee.open("comedydataenglish.txt");
    string comedydatae;
    if (comedyfilee.is_open())
    {
        while (comedyfilee)
        {
            getline(comedyfilee, comedydatae);
            cout << comedydatae << '\n';
        }
        comedyfilee.close();
        cout << "\nEnter the number of movie you wanted to watch : ";
        cin >> no;
        comedyfilee.open("comedydataenglish.txt");
        while (comedyfilee)
        {
            getline(comedyfilee, comedydatae);
            lr++;
            if (no == lr)
            {
                comedyfilee.close();
                cout << "\n***********************************************************************\n";
                cout << "You selected : " << comedydatae;
                cout << "\nDo you wanted to watch this movie : ";
                cin >> w;
                if (w == "y")
                {
                    fstream ce;
                    int ct = 0;
                    string cde;
                    ce.open("comedydataenglishlinks.txt");
                    if (ce.is_open())
                    {
                        while (ce)
                        {
                            getline(ce, cde);
                            ct++;
                            if (ct == no)
                            {
                                ce.close();
                                string got = "start " + cde;
                                system(got.c_str());
                            }
                        }
                    }
                    cout << "\nThanks for watching" << endl;
                    flag = 1;
                    break;
                }
                else
                {
                    comedyenglish();
                }
            }
        }
        if (flag == 0)
        {
            cout << "\nNo such movie in recommendation" << endl;
        }
    }
    else
    {
        cout << "Couldn't open file\n";
    }
}
void genre::comedyhindi()
{
    int no, lr = 0;
    ifstream comedyfileh;
    comedyfileh.open("comedydatahindi.txt");
    string comedydatah;
    if (comedyfileh.is_open())
    {
        while (comedyfileh)
        {
            getline(comedyfileh, comedydatah);
            cout << comedydatah << '\n';
        }
        comedyfileh.close();
        cout << "\nEnter the number of movie you wanted to watch : ";
        cin >> no;
        comedyfileh.open("comedydatahindi.txt");
        while (comedyfileh)
        {
            getline(comedyfileh, comedydatah);
            lr++;
            if (no == lr)
            {
                comedyfileh.close();
                cout << "\n***********************************************************************\n";
                cout << "You selected : " << comedydatah;
                cout << "\nDo you wanted to watch this movie : ";
                cin >> w;
                if (w == "y")
                {
                    fstream ch;
                    int ct = 0;
                    string cdh;
                    ch.open("comedydatahindilinks.txt");
                    if (ch.is_open())
                    {
                        while (ch)
                        {
                            getline(ch, cdh);
                            ct++;
                            if (ct == no)
                            {
                                ch.close();
                                string got = "start " + cdh;
                                system(got.c_str());
                            }
                        }
                    }
                    cout << "\nThanks for watching" << endl;
                    flag = 1;
                    break;
                }
                else
                {
                    comedyhindi();
                }
            }
        }
        if (flag == 0)
        {
            cout << "\nNo such movie in recommendation" << endl;
        }
    }
    else
    {
        cout << "Couldn't open file\n";
    }
}
void genre::comedy()
{
    string choice;
    cout << "Languages available :" << endl;
    cout << "1. English" << endl;
    cout << "2. Hindi" << endl;
    cout << "Choose your language of preference : ";
    cin >> choice;
    cout << "\n***********************************************************************\n";
    if (choice.length() > 1)
    {
        cout << "TRY AGAIN" << endl;
        comedy();
    }
    else if (choice == "1" || choice == "2")
    {
        int choose = stoi(choice);
        switch (choose)
        {
        case 1:
            cout << "Here we have a list of top 10 COMEDY English movies :" << endl;
            comedyenglish();
            break;
        case 2:
            cout << "Here we have a list of top 10 COMEDY Hindi movies :" << endl;
            comedyhindi();
            break;
        }
    }
    else
    {
        cout << "TRY AGAIN" << endl;
        comedy();
    }
}
void genre::romanceenglish()
{
    int no, lr = 0;
    ifstream romancefilee;
    romancefilee.open("romancedataenglish.txt");
    string romancedatae;
    if (romancefilee.is_open())
    {
        while (romancefilee)
        {
            getline(romancefilee, romancedatae);
            cout << romancedatae << '\n';
        }
        romancefilee.close();
        cout << "\nEnter the number of movie you wanted to watch : ";
        cin >> no;
        romancefilee.open("romancedataenglish.txt");
        while (romancefilee)
        {
            getline(romancefilee, romancedatae);
            lr++;
            if (no == lr)
            {
                romancefilee.close();
                cout << "\n***********************************************************************\n";
                cout << "You selected : " << romancedatae;
                cout << "\nDo you wanted to watch this movie : ";
                cin >> w;
                if (w == "y")
                {
                    fstream re;
                    int ct = 0;
                    string rde;
                    re.open("romancedataenglishlinks.txt");
                    if (re.is_open())
                    {
                        while (re)
                        {
                            getline(re, rde);
                            ct++;
                            if (ct == no)
                            {
                                re.close();
                                string got = "start " + rde;
                                system(got.c_str());
                            }
                        }
                    }
                    cout << "\nThanks for watching" << endl;
                    flag = 1;
                    break;
                }
                else
                {
                    romanceenglish();
                }
            }
        }
        if (flag == 0)
        {
            cout << "\nNo such movie in recommendation" << endl;
        }
    }
    else
    {
        cout << "Couldn't open file\n";
    }
}
void genre::romancehindi()
{
    int no, lr = 0;
    ifstream romancefileh;
    romancefileh.open("romancedatahindi.txt");
    string romancedatah;
    if (romancefileh.is_open())
    {
        while (romancefileh)
        {
            getline(romancefileh, romancedatah);
            cout << romancedatah << '\n';
        }
        romancefileh.close();
        cout << "\nEnter the number of movie you wanted to watch : ";
        cin >> no;
        romancefileh.open("romancedatahindi.txt");
        while (romancefileh)
        {
            getline(romancefileh, romancedatah);
            lr++;
            if (no == lr)
            {
                romancefileh.close();
                cout << "\n***********************************************************************\n";
                cout << "You selected : " << romancedatah;
                cout << "\nDo you wanted to watch this movie : ";
                cin >> w;
                if (w == "y")
                {
                    fstream rh;
                    int ct = 0;
                    string rdh;
                    rh.open("romancedatahindilinks.txt");
                    if (rh.is_open())
                    {
                        while (rh)
                        {
                            getline(rh, rdh);
                            ct++;
                            if (ct == no)
                            {
                                rh.close();
                                string got = "start " + rdh;
                                system(got.c_str());
                            }
                        }
                    }
                    cout << "\nThanks for watching" << endl;
                    flag = 1;
                    break;
                }
                else
                {
                    romancehindi();
                }
            }
        }
        if (flag == 0)
        {
            cout << "\nNo such movie in recommendation" << endl;
        }
    }
    else
    {
        cout << "Couldn't open file\n";
    }
}
void genre::romance()
{
    string choice;
    cout << "Languages available :" << endl;
    cout << "1. English" << endl;
    cout << "2. Hindi" << endl;
    cout << "Choose your language of preference : ";
    cin >> choice;
    cout << "\n***********************************************************************\n";
    if (choice.length() > 1)
    {
        cout << "TRY AGAIN" << endl;
        romance();
    }
    else if (choice == "1" || choice == "2")
    {
        int choose = stoi(choice);
        switch (choose)
        {
        case 1:
            cout << "Here we have a list of top 10 ROMANCE English movies :" << endl;
            romanceenglish();
            break;
        case 2:
            cout << "Here we have a list of top 10 ROMANCE Hindi movies :" << endl;
            romancehindi();
            break;
        }
    }
    else
    {
        cout << "TRY AGAIN" << endl;
        romance();
    }
}
void genre::thrillerenglish()
{
    int no, lr = 0;
    ifstream thrillerfilee;
    thrillerfilee.open("thrillerdataenglish.txt");
    string thrillerdatae;
    if (thrillerfilee.is_open())
    {
        while (thrillerfilee)
        {
            getline(thrillerfilee, thrillerdatae);
            cout << thrillerdatae << '\n';
        }
        thrillerfilee.close();
        cout << "\nEnter the number of movie you wanted to watch : ";
        cin >> no;
        thrillerfilee.open("thrillerdataenglish.txt");
        while (thrillerfilee)
        {
            getline(thrillerfilee, thrillerdatae);
            lr++;
            if (no == lr)
            {
                thrillerfilee.close();
                cout << "\n***********************************************************************\n";
                cout << "You selected : " << thrillerdatae;
                cout << "\nDo you wanted to watch this movie : ";
                cin >> w;
                if (w == "y")
                {
                    fstream te;
                    int ct = 0;
                    string tde;
                    te.open("thrillerdataenglishlinks.txt");
                    if (te.is_open())
                    {
                        while (te)
                        {
                            getline(te, tde);
                            ct++;
                            if (ct == no)
                            {
                                te.close();
                                string got = "start " + tde;
                                system(got.c_str());
                            }
                        }
                    }
                    cout << "\nThanks for watching" << endl;
                    flag = 1;
                    break;
                }
                else
                {
                    thrillerenglish();
                }
            }
        }
        if (flag == 0)
        {
            cout << "\nNo such movie in recommendation" << endl;
        }
    }
    else
    {
        cout << "Couldn't open file\n";
    }
}
void genre::thrillerhindi()
{
    int no, lr = 0;
    ifstream thrillerfileh;
    thrillerfileh.open("thrillerdatahindi.txt");
    string thrillerdatah;
    if (thrillerfileh.is_open())
    {
        while (thrillerfileh)
        {
            getline(thrillerfileh, thrillerdatah);
            cout << thrillerdatah << '\n';
        }
        thrillerfileh.close();
        cout << "\nEnter the number of movie you wanted to watch : ";
        cin >> no;
        thrillerfileh.open("thrillerdatahindi.txt");
        while (thrillerfileh)
        {
            getline(thrillerfileh, thrillerdatah);
            lr++;
            if (no == lr)
            {
                thrillerfileh.close();
                cout << "\n***********************************************************************\n";
                cout << "You selected : " << thrillerdatah;
                cout << "\nDo you wanted to watch this movie : ";
                cin >> w;
                if (w == "y")
                {
                    fstream th;
                    int ct = 0;
                    string tdh;
                    th.open("thrillerdatahindilinks.txt");
                    if (th.is_open())
                    {
                        while (th)
                        {
                            getline(th, tdh);
                            ct++;
                            if (ct == no)
                            {
                                th.close();
                                string got = "start " + tdh;
                                system(got.c_str());
                            }
                        }
                    }
                    cout << "\nThanks for watching" << endl;
                    flag = 1;
                    break;
                }
                else
                {
                    thrillerhindi();
                }
            }
        }
        if (flag == 0)
        {
            cout << "\nNo such movie in recommendation" << endl;
        }
    }
    else
    {
        cout << "Couldn't open file\n";
    }
}
void genre::thriller()
{
    string choice;
    cout << "Languages available :" << endl;
    cout << "1. English" << endl;
    cout << "2. Hindi" << endl;
    cout << "Choose your language of preference : ";
    cin >> choice;
    cout << "\n***********************************************************************\n";
    if (choice.length() > 1)
    {
        cout << "TRY AGAIN" << endl;
        thriller();
    }
    else if (choice == "1" || choice == "2")
    {
        int choose = stoi(choice);
        switch (choose)
        {
        case 1:
            cout << "Here we have a list of top 10 THRILLER English movies :" << endl;
            thrillerenglish();
            break;
        case 2:
            cout << "Here we have a list of top 10 THRILLER Hindi movies :" << endl;
            thrillerhindi();
            break;
        }
    }
    else
    {
        cout << "TRY AGAIN" << endl;
        thriller();
    }
}
void genre::scifienglish()
{
    int no, lr = 0;
    ifstream scififilee;
    scififilee.open("scifidataenglish.txt");
    string scifidatae;
    if (scififilee.is_open())
    {
        while (scififilee)
        {
            getline(scififilee, scifidatae);
            cout << scifidatae << '\n';
        }
        scififilee.close();
        cout << "\nEnter the number of movie you wanted to watch : ";
        cin >> no;
        scififilee.open("scifidataenglish.txt");
        while (scififilee)
        {
            getline(scififilee, scifidatae);
            lr++;
            if (no == lr)
            {
                scififilee.close();
                cout << "\n***********************************************************************\n";
                cout << "You selected : " << scifidatae;
                cout << "\nDo you wanted to watch this movie : ";
                cin >> w;
                if (w == "y")
                {
                    fstream se;
                    int ct = 0;
                    string sde;
                    se.open("scifidataenglishlinks.txt");
                    if (se.is_open())
                    {
                        while (se)
                        {
                            getline(se, sde);
                            ct++;
                            if (ct == no)
                            {
                                se.close();
                                string got = "start " + sde;
                                system(got.c_str());
                            }
                        }
                    }
                    cout << "\nThanks for watching" << endl;
                    flag = 1;
                    break;
                }
                else
                {
                    scifienglish();
                }
            }
        }
        if (flag == 0)
        {
            cout << "\nNo such movie in recommendation" << endl;
        }
    }
    else
    {
        cout << "Couldn't open file\n";
    }
}
void genre::scifihindi()
{
    int no, lr = 0;
    ifstream scififileh;
    scififileh.open("scifidatahindi.txt");
    string scifidatah;
    if (scififileh.is_open())
    {
        while (scififileh)
        {
            getline(scififileh, scifidatah);
            cout << scifidatah << '\n';
        }
        scififileh.close();
        cout << "\nEnter the number of movie you wanted to watch : ";
        cin >> no;
        scififileh.open("scifidatahindi.txt");
        while (scififileh)
        {
            getline(scififileh, scifidatah);
            lr++;
            if (no == lr)
            {
                scififileh.close();
                cout << "\n***********************************************************************\n";
                cout << "You selected : " << scifidatah;
                cout << "\nDo you wanted to watch this movie : ";
                cin >> w;
                if (w == "y")
                {
                    fstream sh;
                    int ct = 0;
                    string sdh;
                    sh.open("scifidatahindilinks.txt");
                    if (sh.is_open())
                    {
                        while (sh)
                        {
                            getline(sh, sdh);
                            ct++;
                            if (ct == no)
                            {
                                sh.close();
                                string got = "start " + sdh;
                                system(got.c_str());
                            }
                        }
                    }
                    cout << "\nThanks for watching" << endl;
                    flag = 1;
                    break;
                }
                else
                {
                    scifihindi();
                }
            }
        }
        if (flag == 0)
        {
            cout << "\nNo such movie in recommendation" << endl;
        }
    }
    else
    {
        cout << "Couldn't open file\n";
    }
}
void genre::scifi()
{
    string choice;
    cout << "Languages available :" << endl;
    cout << "1. English" << endl;
    cout << "2. Hindi" << endl;
    cout << "Choose your language of preference : ";
    cin >> choice;
    cout << "\n***********************************************************************\n";
    if (choice.length() > 1)
    {
        cout << "TRY AGAIN" << endl;
        scifi();
    }
    else if (choice == "1" || choice == "2")
    {
        int choose = stoi(choice);
        switch (choose)
        {
        case 1:
            cout << "Here we have a list of top 10 SCIFI English movies :" << endl;
            scifienglish();
            break;
        case 2:
            cout << "Here we have a list of top 10 SCIFI Hindi movies :" << endl;
            scifihindi();
            break;
        }
    }
    else
    {
        cout << "TRY AGAIN" << endl;
        scifi();
    }
}
main()
{
    genre g;
    g.select();
}