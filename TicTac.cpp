#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

bool menu_page(ifstream & fin)
{
    char *menu = new char [100];
    int choice;

    while(!fin.eof())
    {
        fin.getline(menu , 100);
        cout<<menu<<endl;
    }
    cout<<endl;

    cout<<"Enter choice : ";

    while(1)
    {
        cin >>choice;
        if(choice == 1 || choice == 2){break;}
        else
        {
            cout<<"Invalid option ! \nEnter correct choice : ";
        }
    }

    delete [] menu;
    
    if(choice == 1)
    return true;
    else
    return false;

}
void instrc()
{
    ifstream inst("instruction.txt");
    char *lines = new char[100];
    char cont;

    while(!inst.eof())
    {
        inst.getline(lines , 100);
        cout<<lines<<endl;
    }
    cout<<"             Press any button to continue \n\n\n\n";
    cin >>cont;

    delete [] lines;
    inst.close();
}
void player_names(string & p1 , string & p2)
{
    cout<<"Enter 1st player : ";
    cin >> p1;
    cout<<"Enter 2nd player : ";
    cin >> p2;

    cout<<"\nNames entered successfully ! \n"<<endl;
}
int game_series(int & games)
{
    cout<<"How many games to play : ";
    cin >> games;
    cout<<"\n\n\n";
    return games;
}
void tac_board(char **tac , int & Rows , int & Col)
{
    ifstream board ("tacboard.txt");
    char *line = new char[9];
    int count = 0;
    int i = 0;

    while(!board.eof())
    {
        board >> line[i];
        i++;
    }

    for(int i = 0 , k = 0; i<Rows ; i++)
    {
        for(int j = 0 ; j<Col; j++)
        {
            tac[i][j] = line[k];
            k++;
        }
    }

    delete[]line;
    board.close(); 
}
void display_tac(char **tac , int &Rows , int &Col)
{

    cout<<"         |         |         "<<endl;
    cout<<"         |         |         "<<endl;
    cout<<"    "<<tac[0][0]<<"    |    "<<tac[0][1]<<"    |    "<<tac[0][2]<<"   "<<endl;
    cout<<"         |         |         "<<endl;
    cout<<"_________|_________|_________"<<endl;
    cout<<"         |         |         "<<endl;
    cout<<"         |         |         "<<endl;
    cout<<"    "<<tac[1][0]<<"    |    "<<tac[1][1]<<"    |    "<<tac[1][2]<<"   "<<endl;
    cout<<"         |         |         "<<endl;
    cout<<"_________|_________|_________"<<endl;
    cout<<"         |         |         "<<endl;
    cout<<"         |         |         "<<endl;
    cout<<"    "<<tac[2][0]<<"    |    "<<tac[2][1]<<"    |    "<<tac[2][2]<<"   "<<endl;
    cout<<"         |         |         "<<endl;
    cout<<"         |         |         "<<endl;

}
void turns(int &turner , string & p1 , string & p2)
{
    if(turner == 1)
    cout<<" << "<<p1<<" Turn >>   \n"<<endl;
    else
    cout<<" << "<<p2<<" Turn >>   \n"<<endl;

}
void character(char &t1 , char &t2 , string &p1 , string&p2)
{
    cout<<"Choose your character to play as :- "<<endl;
    cout<<"\n"<<p1<<" 's character : ";

    while(1)
    {
        cin >> t1;
        if((t1>='a' && t1 <='z') || (t1>='A' && t1 <='Z'))
        break;
        else
        {
            cout<<"Only characters allowed ! \nEnter character : ";
        }
    }

    cout<<"\n"<<p2<<" 's character : ";

    while(1)
    {
        cin >> t2;
        if(t1 == t2)
        {
            cout<<"Same characters not allowed ! "<<endl;
            cout<<"Enter character other than "<<p1<<" 's : ";
        }
        else if((t2>='a' && t2 <='z') || (t2>='A' && t2 <='Z'))
        {
            break;
        }
        else
        cout<<"Only characters allowed ! \nEnter character : ";
    }

    
}
void loc_evaluate(int &loc , int & r1 , int & c1)
{
    if(loc == 1)
    {
        r1 = 0 , c1 = 0;
    }
    else if(loc == 2)
    {
        r1 = 0 , c1 = 1;
    }
    else if(loc == 3)
    {
        r1 = 0 , c1 = 2;
    }
    else if(loc == 4)
    {
        r1 = 1 , c1 = 0;
    }
    else if(loc == 5)
    {
        r1 = 1 , c1 = 1;
    }
    else if(loc == 6)
    {
        r1 = 1 , c1 = 2;
    }
    else if(loc == 7)
    {
        r1 = 2 , c1 = 0;
    }
    else if(loc == 8)
    {
        r1 = 2 , c1 = 1;
    }
    else
    {
        r1 = 2 , c1 = 2;
    }
}
void location(int & loc , int & turn , char & t1 , char & t2)
{
    if(turn == 1)
    {
        cout <<"Enter location to place ' "<<t1<<" ' at : ";
        cin >> loc;
    }
    else if(turn == -1)
    {
        cout <<"Enter location to place ' "<<t2<<" ' at : ";
        cin >> loc;
    }

    if(loc >=1 && loc <= 9)
    {}
    else
    {
        while(1)
        {
            cout<<"Enter valid location from 1-9 : ";
            cin >> loc;
 
            if(loc >=1 && loc <= 9)
            break;
        }
    }
}
void previous_occ(int & loc , int &turn , char **tac ,int & i , int & j ,char & t1 , char & t2, string & p1 , string & p2)
{
    if(turn == 1)
    {
        while(1)
        {
            if(tac[i][j] == t1)
            {
                cout<<"Already played location by "<<p1<<" (you)"<<endl;
                cout<<p1<<" 's turn interrupted ! "<<endl;
                location(loc , turn , t1 , t2);
                loc_evaluate(loc , i , j);

            }
            else if(tac[i][j] == t2)
            {
                cout<<"Already played location by "<<p2<<endl;
                cout<<p1<<" 's turn interrupted ! : "<<endl;
                location(loc , turn , t1 , t2);
                loc_evaluate(loc , i , j);
            }
            else
            {break;}
        }
    }
    else if(turn == -1)
    {
        while(1)
        {
            if(tac[i][j] == t1)
            {
                cout<<"Already played location by "<<p1<<endl;
                cout<<p2<<" 's turn interrupted ! : "<<endl;
                location(loc , turn , t1 , t2);
                loc_evaluate(loc , i , j);
            }
            else if(tac[i][j] == t2)
            {
                cout<<"Already played location by "<<p2<<" (you)"<<endl;
                cout<<p2<<" 's turn interrupted ! : "<<endl;
                location(loc , turn , t1 , t2);
                loc_evaluate(loc , i , j);
            }
            else
            {break;}
        }
    }

}
int rules(int &turn , char **tac , int &r1 , int &c1, char &t1 , char &t2 , string &p1 , string &p2 , int &draw)
{
    int val ;
    if(turn == 1)
    {
        //Rule 1 (Row 1)
        if(tac[0][0] == t1 && tac[0][1] == t1 && tac[0][2] == t1)
        {
            val = 3;
        }
        //Rule 2 (Row 2)
        else if(tac[1][0] == t1 && tac[1][1] == t1 && tac[1][2] == t1)
        {
            val = 3;
        }
        //Rule 3 (Row 3)
        else if(tac[2][0] == t1 && tac[2][1] == t1 && tac[2][2] == t1)
        {
            val = 3;
        }
        //Rule 4 (Col 1)
        if(tac[0][0] == t1 && tac[1][0] == t1 && tac[2][0] == t1)
        {
            val = 3;
        }
        //Rule 5 (Col 2)
        else if(tac[0][1] == t1 && tac[1][1] == t1 && tac[2][1] == t1)
        {
            val = 3;
        }
        //Rule 6 (Col 3)
        else if(tac[0][2] == t1 && tac[1][2] == t1 && tac[2][2] == t1)
        {
            val = 3;
        }
        //Rule 7 (Dgl 1)
        else if(tac[0][0] == t1 && tac[1][1] == t1 && tac[2][2] == t1)
        {
            val = 3;
        }
        //Rule 8 (Dgl 2)
        else if(tac[0][2] == t1 && tac[1][1] == t1 && tac[2][0] == t1)
        {
            val = 3;
        }
        else if(draw == 9)
        {
            val = - 99;
        }
    }

    else if(turn == -1)
    {
        //Rule 1 (Row 1)
        if(tac[0][0] == t2 && tac[0][1] == t2 && tac[0][2] == t2)
        {
            val = 3;
        }
        //Rule 2 (Row 2)
        else if(tac[1][0] == t2 && tac[1][1] == t2 && tac[1][2] == t2)
        {
            val = 3;
        }
        //Rule 3 (Row 3)
        else if(tac[2][0] == t2 && tac[2][1] == t2 && tac[2][2] == t2)
        {
            val = 3;
        }
        //Rule 4 (Col 1)
        if(tac[0][0] == t2 && tac[1][0] == t2 && tac[2][0] == t2)
        {
            val = 3;
        }
        //Rule 5 (Col 2)
        else if(tac[0][1] == t2 && tac[1][1] == t2 && tac[2][1] == t2)
        {
            val = 3;
        }
        //Rule 6 (Col 3)
        else if(tac[0][2] == t2 && tac[1][2] == t2 && tac[2][2] == t2)
        {
            val = 3;
        }
        //Rule 7 (Dgl 1)
        else if(tac[0][0] == t2 && tac[1][1] == t2 && tac[2][2] == t2)
        {
            val = 3;
        }
        //Rule 8 (Dgl 2)
        else if(tac[0][2] == t2 && tac[1][1] == t2 && tac[2][0] == t2)
        {
            val = 3;
        }
        else if(draw == 9)
        {
            val = - 99;
        }

    }
        draw++;
        return val;
}
void gameplay(int & turn , string & p1 , string & p2 , char **tac ,  char & t1 , char & t2 , int & ret_val , int &draw)
{
    
    int loc = 0 , r1=0 , c1=0;

    location(loc , turn , t1 , t2);
    loc_evaluate(loc , r1 , c1);
    previous_occ(loc , turn ,tac , r1 , c1 , t1 , t2 , p1 , p2);

    if(turn == 1)
    tac[r1][c1] = t1;
    else
    tac[r1][c1] = t2;

    int count = rules(turn , tac , r1 , c1, t1 , t2 , p1 , p2 ,draw);
    
    if(count == 3)
    ret_val = 3;
    else
    ret_val = 0;
    
}
string winner(string & winner, int &p1_win_counter ,int &p2_win_counter  ,int &turn)
{
    if(turn == 1)
    {
        if(p1_win_counter == 1)
        {
            winner ="1st ";
        }
        else if(p1_win_counter == 2)
        {
            winner ="2nd ";
        }
        else if(p1_win_counter == 3)
        {
            winner ="3rd ";
        }
        else if(p1_win_counter > 3)
        {
            winner ="th ";
        }
    }
    else
    {
        if(p2_win_counter == 1)
        {
            winner ="1st ";
        }
        else if(p2_win_counter == 2)
        {
            winner ="2nd ";
        }
        else if(p2_win_counter == 3)
        {
            winner ="3rd ";
        }
        else if(p2_win_counter > 3)
        {
            winner ="th ";
        }
    }

    return winner;

}
void results(string &p1, string &p2, int &p1_win_counter, int &p2_win_counter)
{
    cout<<"\n\n     ----RESULTS----     "<<endl<<endl;
    cout<<p1<<" won Games = "<<p1_win_counter<<endl<<endl;
    cout<<p2<<" won Games = "<<p2_win_counter<<endl<<endl;

    if(p1_win_counter!=p2_win_counter)
    {
        cout<<"()()()^&^&^ CONGRATULATIONS ^&^&^()()()"<<endl;
        if(p1_win_counter > p2_win_counter)
        {
            cout<<"     "<<p1<<" WON THE SERIES"<<endl<<endl;
        }
        else
        {
            cout<<"     "<<p2<<" WON THE SERIES"<<endl<<endl;
        }
        cout<<"---------------------------------------"<<endl;
    }
    else
    {
        cout<<"^&^^&^^&&SERIES DRAWN&&^^&^^&^"<<endl;
    }

}
int main()
{
    int series = 0 , R = 3 , C = 3 ,ret_val = 0;
    int p1_win_counter = 0 ,p2_win_counter = 0 ,game_count = 0;
    string p1 , p2 , win_count;
    char t1 , t2;

    char **tac = new char *[R];
    for(int i = 0 ; i < R ; i++)
    {
        tac[i] = new char[C];
    }

        ifstream fin("menu_page.txt");
        bool get = menu_page(fin);
        fin.close();

        player_names(p1 , p2);
        series = game_series(series);

    while(1)
    {
        if(get == true)
        {
            tac_board(tac , R , C);

            int turner = 1 , draw  = 0;

            cout<<"GAME     # "<<game_count+1<<endl;
            cout<<"-------------"<<endl<<endl;

            character(t1 , t2 , p1 , p2);

            while(1)
            {
                turns(turner , p1 , p2);
                display_tac(tac , R , C);
                gameplay(turner , p1 , p2 , tac , t1 , t2 ,ret_val,draw);

                if(ret_val == 3)
                {
                    display_tac(tac , R , C);
                    if(turner == 1)
                    {
                        p1_win_counter ++;
                        
                        cout<<"--- "<<p1<<" Won the ";
                        if(p1_win_counter > 3)
                        cout<<p1_win_counter<<winner(win_count ,p1_win_counter ,p2_win_counter,turner)<<" game ---"<<endl;
                        else
                        cout<<winner(win_count ,p1_win_counter ,p2_win_counter,turner)<<" game ---"<<endl;

                      
                    }
                    else
                    {
                        p2_win_counter ++;
                        
                        cout<<"--- "<<p2<<" Won the ";
                        if(p2_win_counter > 3)
                        cout<<p2_win_counter<<winner(win_count ,p1_win_counter ,p2_win_counter,turner)<<" game ---"<<endl;
                        else
                        cout<<winner(win_count ,p1_win_counter ,p2_win_counter,turner)<<" game ---"<<endl;

                    }
                    game_count += 1;
                    break;
                }
                else if(draw == 9)
                {
                    display_tac(tac , R , C);
                    cout<<"--- Game is drawn between "<<p1<<" && "<<p2<<" ---"<<endl;

                    game_count += 1;
                    break;
                }

                turner *= -1;  
            }
                
                
                if(game_count == series)
                {
                    results(p1,p2,p1_win_counter,p2_win_counter);
                    break;
                }
                
        }
        else if(get == false)
        {
            instrc();
        }
    }
    for(int i = 0 ; i < R ; i++)
    {
        delete[]tac[i];
    }
    delete[]tac;
    return 0;
}

