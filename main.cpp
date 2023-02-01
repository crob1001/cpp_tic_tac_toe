#include <iostream>
#include <ctype.h>
using namespace std;

int ask(string q, int max){
    cout << q << endl;
    while (true){
        int awnser;
        cin >> awnser;
        if (!cin || awnser > max || awnser < 0) {
            cout << "please enter a valid input\n" << q << endl;
        } else {
            cout << endl;
            return awnser;
            break;
        }
    }
}

void printboard(string b){
    cout <<
        " " << b[6] << " | " << b[7] << " | " << b[8] << " \n"  <<
        "-----------\n" <<
        " " << b[3] << " | " << b[4] << " | " << b[5] << " \n"  <<
        "-----------\n" <<
        " " << b[0] << " | " << b[1] << " | " << b[2] << " \n"  << endl;
}

bool checkvalid(int l, string b){
    if (isdigit(b[l - 1])){
        return true;
    } else{
        return false;
    }
}

string playplace(bool pt, string b){
    int l;
    string msg = "where would you like to play ";
    if (pt){
        msg = msg.append("p1");
    } else{
        msg = msg.append("p2");
    }
    while (true){
        l = ask(msg, 9);
        if (!checkvalid(l, b)){
            cout << "please choose an valid square" << endl;
        }else{
            break;
        }
    }
    if (pt){
            b[l - 1] = 'X';
        }else{
            b[l - 1] = 'O';
        }
    return b;
}

bool win(string b){
    bool win = false;
    int allcombo[8][3] = {
        {0,1,2},{3,4,5},{6,7,8},
        {6,3,0},{7,4,1},{8,5,2},
        {6,4,2},{8,4,0}};

    for (auto& i : allcombo){
        if (b[i[0]] == b[i[1]] && b[i[0]] == b[i[2]]){
            win = true;
            break;
        }
    }
    return win;
}

void pvp(){
    bool pt = false;
    int p1 = 0;
    int p2 = 0;
    int c = 0;
    
    while (true){
        bool running = true;
        int tn = 0;
        string b = "123456789";
        cout << "Scores:\np1: " << p1 << "\np2: " << p2 << "\ndraw: " << c << "\n" << endl;
        printboard(b);
        while (true || tn <= 8){
            pt = !pt;
            b = playplace(pt, b);
            if (win(b)){
                switch(pt){
                    case true:
                        p1++;
                        cout << "player 1 wins" << endl;
                        printboard(b);
                        break;
                    case false:
                        p2++;
                        cout << "player 2 wins" << endl;
                        printboard(b);
                        break;
                }
                break;
            }
            printboard(b);
            tn++;
        }
        if (tn > 8){
            c++;
            cout << "draw" << endl;
        }
        switch(ask("\nenter 1 to  play again or 0 to exit", 1)){
            case 0:
                exit(0);
            case 1:
                ;
        }
    }
}

int main(){
    while (true){
        cout << "\nwelcome to tic tac toe\n" << endl;
        switch (ask("0: exit\n1: p vs p\n2: p vs c\n", 2)){
            case 0:
                exit(0);
            case 1:
                pvp();
                break;
            case 2:
                cout << "sorry, this mode is under construction" << endl;
        }
    }
}