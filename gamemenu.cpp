#include <stdlib.h>
#include <conio.h>
#include<stdio.h>
#include<time.h>
#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

char square[9]={'1','2','3','4','5','6','7','8','9'};

class Tic
{
public:

      int checkwin()
      {
    if(square[0]==square[1] && square[1]==square[2])
        return 1;
    else if(square[3]==square[4] && square[4]==square[5])
        return 1;
    else if(square[6]==square[7] && square[7]==square[8])
        return 1;
    else if(square[0]==square[3] && square[3]==square[6])
        return 1;
    else if(square[1]==square[4] && square[4]==square[7])
        return 1;
    else if(square[2]==square[5] && square[5]==square[8])
        return 1;
    else if(square[0]==square[4] && square[4]==square[8])
        return 1;
    else if(square[2]==square[4] && square[4]==square[6])
        return 1;
    else
        return -1;
     }


   void board()
  {
    cout<<"Player 1 (X)  -  Player 2 (O)" <<endl<<endl;
    cout<<endl;
    cout<<"     |     |     "<<endl;
    cout<<"  "<<square[0]<<"  |  "<<square[1]<<"  |  "<<square[2]<<endl;
    cout<<"_____|_____|_____"<<endl;
    cout<<"     |     |     "<<endl;
    cout<<"  "<<square[3]<<"  |  "<<square[4]<<"  |  "<<square[5]<<endl;
    cout<<"_____|_____|_____"<<endl;
    cout<<"     |     |     "<<endl;
    cout<<"  "<<square[6]<<"  |  "<<square[7]<<"  |  "<<square[8]<<endl;
    cout<<"     |     |     "<<endl<<endl;
}
};


const int MAXLENGTH=80;
const int MAX_TRIES=5;

class input
{
    int n,i;
    char unknown[MAXLENGTH];
    char letter;
    int num_of_wrong_guesses;
    char word[MAXLENGTH];
public:
    input()
    {

    num_of_wrong_guesses=0;
    srand(time(NULL));
    char words[ ][MAXLENGTH] =
    {
        " ",
        "sabertooth",
        "hippopotamus",
        "racoon",
        "platypus",
        "beaver",
        "alligator",
        "gorilla",
        "lesula",
        "hyena",
        "coyote",
        "leopard",
        "jaguar",
        "cougar"
    };
    int n=rand()%14+1;
    strcpy(word,words[n]);
    //puts(word);
    int length = strlen(word);
    for (i = 0; i < length; i++)
        unknown[i]='?';
    unknown[i]='\0';
    //puts(unknown);
    }
//guess=alphabet guessed by user
//secretword= srand chosen word
//guessword=changing ? sequence
    int letterFill (char guess, char secretword[], char guessword[])
{
    int i;
    int matches=0;
    for (i = 0; secretword[i]!='\0'; i++)
    {
        // Did we already match this letter in a previous guess?
        if (guess == guessword[i])
        {
            cout<<"o.0 You have already entered it. Too bad. You lost a turn"<<endl;
            return 0;
        }
        // Is the guess in the secret word?
        if (guess == secretword[i])
        {
            guessword[i] = guess;
            matches++;
        }
    }
    return matches;
}
    void game()
    {
      while (num_of_wrong_guesses < MAX_TRIES)
    {
        cout<<"\n\n";
        puts(unknown);
        cout << "\n\nGuess a letter: ";
        cin >> letter;
        if (letterFill(letter, word, unknown)==0)
        {
            cout << endl << "Oops! That letter isn't in there o.0!" << endl;
            num_of_wrong_guesses++;
        }
        else
        {
            cout << endl << "You found a letter!" << endl;
        }
        cout << "You have " <<MAX_TRIES - num_of_wrong_guesses<< " guesses left." << endl;
        if (strcmp(word, unknown) == 0)
        {
            cout << word << endl;
            cout << "Yeah! You got it!";
            break;
        }
    }
    if(num_of_wrong_guesses == MAX_TRIES)
    {
        cout << "\nSorry, you lose...you've been hanged." <<endl;
        cout << "The word was : " << word <<endl;
    }
    }
};

int main()
{
    int c;
    cout<<"\tWELCOME!!!"<<endl;
    cout<<"\tChoose a game!"<<endl<<"\t 1. Tic Tac Toe (multiplayer)"<<endl<<"\t 2. Hangman (single player)"<<endl;
    cin>>c;
    if(c==1)
    {

     Tic t;
    cout<<"\n\n\tTic Tac Toe\n\n";
    int player=1,i,choice,z=-1;
    int flag=0;
    ofstream fout;
    char u[30],p[30];

    cout<<"Enter Player 1 name: ";
    cin>>u;
    cout<<"Enter Player 2 name: ";
    cin>>p;

    char mark;
       do
       {
        t.board();
        player=(player%2)?1:2;
        cout<<"Player "<<player<<", enter a number:  ";
        cin>>choice;
        mark=(player==1)?'X' : 'O';
        if(square[choice-1]=='X' || square[choice-1]=='O')
           {
            cout<<"Invalid move ";
           }
        else{
              square[choice-1]=mark;
              z=t.checkwin();
                  if(z==1)
                {
                t.board();
                cout<<"==>\aPlayer "<<player<<" wins ";

                fout.open("scoreboard.txt",ios::app);
                if(player==1)
            {   fout<<u<<" wins, and "<<p<<" looses.\n";  }
                else
            {   fout<<p<<" wins, and "<<u<<" looses.\n";  }
            fout.close();

                flag=0;
                break;
                }
        player++;
        flag++;
        }
       }while(z==-1 && flag<9);
        if(flag!=0)
        {
            t.board();
            cout<<"Draw";

            fout.open("scoreboard.txt",ios::app);
            fout<<u<<" and "<<p<<" tie.\n";
            fout.close();
        }
    }

    else if(c==2)
    {
        cout<<"\n\nWelcome to hangman...Guess an animal";
    cout<<"\n\nEach letter is represented by a question mark";
    cout<<"\n\nYou have to type only one letter in one try";
    cout<<"\n\nYou have " << MAX_TRIES << " tries to try and guess the word.";
    cout<<"\n0.o.0.0.o.0.o0.o.0.o0.o.0.o0.o.0.o0.o.0.o0.o.0.o0.o.0.o"<<endl;
    input *ptr=new input;
    ptr->game();
    }

    else
    {
        cout<<"Invalid Choice";
    }
}
