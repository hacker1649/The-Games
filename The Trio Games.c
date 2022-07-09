/* GROUP MEMBERS:
                                          MUHAMMAD ANAS HASSAN (20K-1726)
                                          ABDUL BASIT (20K-0333) 
                                          MUHAMMAD WARZAN (20K-1649)   */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>

struct member
{
    char name[30];
};
//different functions prototype

void LUCKGAME();
void LuckBase(int *pt, int n, struct member a[], int k);
void lettergame();
int quizgame();
int maths_library(char w);
int physics_library(char x);
int chemistry_library(char y);
int generalknowledge_library(char z);

//cordinate function(gotoxy)
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
//startup screen code
//function definition
void Intro()
{
    system("color 5E");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

    printf("\t\t\t___________                ______              ______                                ______     ____\n");
    printf("\t\t\t     |        |      |    |                   '            /\\       |\\         /|   |          /       \n");
    printf("\t\t\t     |        |      |    |                 '             /  \\      | \\       / |   |         |      \n");
    printf("\t\t\t     |        |------|    |-----           '  ______     /____\\     |  \\     /  |   |-----    \\__     \n");
    printf("\t\t\t     |        |      |    |                '        |   /      \\    |   \\   /   |   |             \\  \n");
    printf("\t\t\t     |        |      |    |______            ' _____|  /        \\   |    \\_/    |   |______        | \n");
    printf("\t                                                                                                               ____/");

    gotoxy(0, 35);
    printf("PRESS ANY KEY TO CONTINUE ...");
    getch();
}

//customize font color function
void colorit(int col)
{
    HANDLE hstdout;
    hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
    //12=red, 15=white---------------->this.colorit(12);  this.colorit(15);
    SetConsoleTextAttribute(hstdout, col);
}
//menu function(choice)
void showmenu() //function definition
{
    //variable initialize
    int index = 1;
    int key = 0;
    system("cls"); //to erase screen
    while (key != 13)
    {                       //enter ascii code
        system("color 5e"); //change color of screen and text
        gotoxy(45, 3);      //cordinate(x,y)
        colorit(15);        ////12=red, 15=white---------------->this.colorit(12);  this.colorit(15);///
        printf("\t\t\t\t\t THE GAMES");
        gotoxy(45, 4);
        printf("\t\t\t\t\t==============");
        gotoxy(45, 7);
        colorit(15);
        if (index == 1)
        {
            colorit(12);
        }
        printf("\t\t\t\t\tLETTER GAME");
        gotoxy(45, 10);
        colorit(15);
        if (index == 2)
        {
            colorit(12);
        }
        printf("\t\t\t\t\tQUIZ GAME");
        gotoxy(45, 13);
        colorit(15);
        if (index == 3)
        {
            colorit(12);
        }
        printf("\t\t\t\t\tLUCK GAME");
        gotoxy(45, 16);
        colorit(15);
        if (index == 4)
        {
            colorit(12);
        }
        printf("\t\t\t\t\tEXIT");
        //UP=224/72 Down=224/80 Enter=13 ascii code
        key = getch();
        if (key == 80)
        {
            index++;
        }
        else if (key == 72)
        {
            index--;
        }
        if (index == 5)
        {
            index = 1;
        }
        if (index == 0)
        {
            index = 4;
        }
    }
    if (index == 1) //if this satisfy then this code run
    {
        lettergame(); //calling Function
        printf("\n\n\n\nPRESS ANY KEY TO GO BACK TO MAIN MENU...");
        getch();    //to take input
        showmenu(); //
    }
    else if (index == 2)
    {
        system("cls");
        quizgame(); //calling Function
        printf("\n\n\n\nPRESS ANY KEY TO GO BACK TO MAIN MENU...");
        getch();
        showmenu();
    }

    else if (index == 3)
    {
        system("cls");
        system("color 5e");
        LUCKGAME();
        system("pause");
        system("cls");
        printf("\n\n\n\nPRESS ANY KEY TO GO BACK TO MAIN MENU...");
        getch();
        showmenu();
    }

    else if (index == 4)
    {
        exit(0); //to end
    }
}

void lettergame() //function definition
{
    system("color 5e");
    int x = 5;
    int y = 3;
    int i, line = 35, score = 0;
    char a[26], start, name[40], ch;
    time_t start1, end;
    FILE *fptr;
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t!!!***************************'LETTER GAME'******************************!!!\n");
    printf("\t\t\t\t************************************************************************************************");
    //inputting name of the player name of the player
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tREGISTER YOUR NAME (Complete Name) : ");
    fflush(stdin);
    gets(name);
    system("cls");
    //some instructions given to the player
    printf("\n\n\t\t\t\t---------------WELCOME '%s' AND READY FOR THE LETTER GAME !---------------\n", strupr(name));
    printf("\n\t\t\t_________________________________________________________________________________________________________________");
    printf("\n\n\n\n\n\n\t\t\t\t\t\t>>>>>>>>>>>>>>>> INSTRUCTIONS TO PLAY <<<<<<<<<<<<<<<<<\n\n");
    printf("\t\t\t\t__________________________________________________________________________________________\n");
    printf("\t\t\t\t\t\t_______________________________________________________\n");
    printf("\t\t\t\t\t\t\t\t___________________________\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t>>>>>>     THE LETTER IS FALLING YOU HAVE TO PRESS THAT LETTER FROM  .........\n\n\n\n");
    printf("\t\t\t\t\t\t>>>>>>     KEYBOARD BEFORE THE LETTER TOUCHES THE LINE. .........\n\n\n\n");
    printf("\t\t\t\t\t\t>>>>>>     IF THE LETTER TOUCH THE LINE THE GAME IS OVER! .........\n\n\n\n");
    printf("\t\t\t\t\t\t>>>>>>     THE MORE YOU STAY THE MORE YOUR SCORE! .........\n\n\n\n");
    printf("\t\t\t\t\t\t***************************** BEST OF LUCK ********************************\n\n");
    printf("\t\t\t\tNOTE: CAPS LOCK MUST BE ON! \n\n");

    printf("\n\n\n\t\t\t\tPRESS 'S' OR 's' TO CONTINUE : ");
    fflush(stdin);
    scanf(" %c", &start);
    if ((start == 'S') || (start == 's'))
    {
        system("cls");
        gotoxy(70, 20);
        printf("GAME IS LOADING PLEASE WAIT....");
        sleep(2);
        start1 = time(NULL);
        fptr = fopen("alphabets.txt", "r");
        if (fptr == NULL)
        {
            printf("NO FILE FOUND!");
        }
        else
        {
            system("cls");
            fscanf(fptr, "%s", &a[0]);
            gotoxy(70, 2);
            printf("LETTER GAME");
            for (i = 0; i < 26; i++)
            {
                gotoxy(0, 33);
                printf("========================================================================================================================================================================\n");
                printf("========================================================================================================================================================================");
                x = x + 2;
                y = 3;
                while (y < 33)
                {
                    gotoxy(x, y);
                    printf("%c\n", a[i]);
                    usleep(70000);
                    gotoxy(x, y);
                    printf(" ");
                    y++;
                    if (kbhit())
                    {
                        ch = getch();
                        if (ch == a[i])
                        {
                            score++;
                            break;
                        }
                    }
                }
                if (y == 33 || ch == a[25])
                {
                    end = time(NULL);
                    system("cls");
                    printf("\n\n\n\t\t\t\t\t\t\t\t\t\tGAME OVER!");
                    printf("\n\t\t\t==========================================================================================================================");
                    printf("\n\n\n\t\t\t\t\t\t\t      !!!!!!!!!! YOUR SCORE : %d !!!!!!!!!!", score);
                    printf("\n\n\t\t\t\t\t\t\t\tTOTAL TIME PLAYED:%.1f SECONDS!", difftime(end, start1));
                    if (difftime(end, start1) > 20)
                    {
                        printf("\n\n\t\t\t\t\t\t\t\t NEED TO IMPROVE TYPING SPEED!");
                    }
                    if (difftime(end, start1) <= 20)
                    {
                        printf("\n\n\t\t\t\t\t\t\t\t      GOOD TYPING SPEED!");
                    }
                    if (difftime(end, start1) <= 25 && ch == a[25])
                    {
                        printf("\n\n\t\t\t\t\t\t\t\tOUTSTANDING TYPING SPEED!");
                    }
                    printf("\n\n\t\t\t\t\t\t\t !!!!!!!!!! '%s' TRY AGAIN NEXT TIME !!!!!!!!!!", strupr(name));

                    break;
                }
            }
            fclose(fptr);
        }
    }
    else
    {
        printf("\n\t\t\tINVALID INPUT!\n");
        lettergame();
    }
}

//function definition
int quizgame()
{
    system("color 5e");
    int score, m, n, o, u;
    char a, ch, p, q, r, s, name[20];
    //intro part of C program quiz competition
    printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t!!!***************************'QUIZ COMPETITON'******************************!!!\n");
    printf("\t\t\t\t************************************************************************************************");
    printf("\n\t\t\t_________________________________________________________________________________________________________________");
    printf("\n\n\t\t\t\t\t\tWELCOME TO THE SIMPLE QUIZ COMPETITION IN 'C' PROGRAMMING LANGUAGE : ");
    printf("\n\t\t\t\t\t\t_______________________________________________________________");
    printf("\n\t\t\t\t\t\t_______________________________________________________________");
    printf("\n\t\t\t\t\t\t_______________________________________________________________");
    printf("\n\n\t\t\t\t================================================================================================");
    printf("\n\n\t\t\t\t\t\t<> Press 'S' or 's', to begin the simple Quiz Competition.\n\t\t\t\t\t\t<> Press 'Q' or 'q', to quit the simple Quiz Competition.");
    printf("\n\n\t\t\t\t================================================================================================");
    printf("\n\t\t\t\t\t\t_______________________________________________________________");
    printf("\n\t\t\t\t\t\t_______________________________________________________________");
    printf("\n\t\t\t\t\t\t_______________________________________________________________");
    printf("\n\n\t\t\t\t\t\t\t\tEnter your choice : ");
    scanf("%c", &a);
    //using switch() function based on players choice
    switch (a)
    {
    case 'S':
    case 's':
    {
        system("cls"); //this function is used to clear the console screen
                       //inputting name of the player name of the player
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tREGISTER YOUR NAME (Complete Name) : ");
        fflush(stdin);
        gets(name);
        system("cls");
        //some instructions given to the player
        printf("\n\n\n\t\t\t\t---------------WELCOME '%s' AND READY FOR THE QUIZ COMPETITION !---------------\n", strupr(name));
        printf("\n\n\n\t\t\t\t\tHere are some tips , you might wanna know before playing :");
        printf("\n\t\t\t\t\t----------------------------------------------------------\n");
        printf("\n\t__________________________________________________________________________________________________________________________________\n\n");
        printf("\n\n\t\t___________________________________________________________________________________________________________________\n\n");
        printf("\n\t\t>> This Quiz Competition consists of four sections based on MATHEMATICS , PHYSICS ,CHEMISTRY and GENERAL KNOWLEDGE.\n");
        printf("\n\t\t>> Each section consists of FIVE questions, means the total number of questions in whole Quiz Competiton is 20.\n");
        printf("\n\t\t>> Each right answer will be awarded 2 mark, means the total marks is 40, so try your best to choose the correct option. \n");
        printf("\n\t\t>> You will be given 4 options and you have to enter A,B,C or D for the right option. \n");
        printf("\n\t\t>> No negative marking for the wrong answers. \n");
        printf("\n\n\n\t\t\t\t\t\t!!!!!!!!!! ALL THE BEST '%s' !!!!!!!!!!", name);
        printf("\n\n\t\t___________________________________________________________________________________________________________________\n\n");
        printf("\n\n\t__________________________________________________________________________________________________________________________________\n\n\n");
        printf("\n\t\t\tPress 'W' or 'w' to start the competition : ");
        scanf("%c", &ch);
        if ((ch == 'W') || (ch == 'w'))
        {
            system("cls");
            gotoxy(70, 20);
            printf("YOU QUIZ IS BEING READY PLEASE WAIT....");
            sleep(2);
            system("cls");
            //quiz competition is begin.........
            printf("\n\n\t\t\t\t !!!!!!!!!!!!!  FIRST SECTION : !!!!!!!!!!!!!");
            printf("\n\n\n\n\t\t\t >|MATHEMATICS|< "); //first section
            printf("\n\t\t\t--------------");
            m = maths_library(p); //function calling
            //this function is used to pause the program until the user press any other key to continue
            system("pause");
            system("cls");
            printf("\n\n\t\t\t\t !!!!!!!!!!!!!  SECOND SECTION : !!!!!!!!!!!!!");
            printf("\n\n\n\n\t\t\t >|PHYSICS|< "); //second section
            printf("\n\t\t\t--------------");
            n = physics_library(q); //function calling
            system("pause");
            system("cls");
            printf("\n\n\t\t\t\t !!!!!!!!!!!!!  THIRD SECTION : !!!!!!!!!!!!!");
            printf("\n\n\n\n\t\t\t >|CHEMISTRY|< "); //third section
            printf("\n\t\t\t--------------");
            o = chemistry_library(r); //function calling
            system("pause");
            system("cls");
            printf("\n\n\t\t\t\t !!!!!!!!!!!!!  FOURTH SECTION : !!!!!!!!!!!!!");
            printf("\n\n\n\n\t\t\t >|GENERAL KNOWLEDGE|< "); //fourth section
            printf("\n\t\t\t-----------------------");
            u = generalknowledge_library(s); //function calling
            system("pause");
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t THE SIMPLE 'C' PROGRAM QUIZ COMPETITION IS COMPLETED!!! \n");
            //m = total number of correct answers in first section
            //n = total number of correct answers in second section
            //o = total number of correct answers in third section
            //u = total number of correct answers in fourth section
            //add all of them and store the answer in score variable to get the total number of correct answers in all 4 sections
            score = m + n + o + u;
            //printing the total number of correct answers
            printf("\n\t\t\t\t\t\t----------------------------------------------------------\n");
            printf("\n\t\t\t\t\t\t\t 'YOUR SCORE GENERATED IS %d / 40 .'\n", score);
            printf("\n\t\t\t\t\t\t----------------------------------------------------------\n");
            if (score < 30)
            {
                printf("\n\t\t\t\t\t\t WELL PLAYED , NEED MORE IMPROVEMENT , KEEP IT UP !!!!!\n");
            }
            else if (score >= 30)
            {
                printf("\n\t\t\t\t\t\t WELL PLAYED , EXCELLENT RESULT , KEEP IT UP !!!!!\n");
            }
            else
            {
                printf("\n\t\t\t\t\t\t Invalid Score !!!!!\n");
            }
            printf("\n\t\t\t\t\t_________________________________________________________________________");
            printf("\n\t\t\t\t\t_________________________________________________________________________");
            printf("\n\t\t\t\t\t_________________________________________________________________________");
            printf("\n\n\t\t___________________________________________________________________________________________________________________\n\n");
            printf("\t\t\t*****************************************************************************************************\n\n");
            system("pause");
            system("cls");
            //answer sheet of all the questions
            printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t--------------->|ANSWER SHEET:|<---------------");
            printf("\n\n\t\t\tMATHEMATICS:");
            printf("\t\t1.B or b ");
            printf("\t2.A or a ");
            printf("\t3.C or c ");
            printf("\t4.B or b ");
            printf("\t5.A or a ");
            printf("\n\n\t\t\tPHYSICS:");
            printf("\t\t1.A or a ");
            printf("\t2.A or a ");
            printf("\t3.D or d ");
            printf("\t4.A or a ");
            printf("\t5.B or b ");
            printf("\n\n\t\t\tCHEMISTRY:");
            printf("\t\t1.A or a ");
            printf("\t2.B or b ");
            printf("\t3.D or d ");
            printf("\t4.C or c ");
            printf("\t5.B or b ");
            printf("\n\n\t\t\tGENERAL KNOWLEDGE:");
            printf("\t1.B or b ");
            printf("\t2.C or c ");
            printf("\t3.C or c ");
            printf("\t4.B or b ");
            printf("\t5.C or b ");
            printf("\n\n\n\n\n\t\t___________________________________________________________________________________________________________________\n\n");
            printf("\t\t\t===========================================================================================");
            printf("\n\n\t\t!!!********************************************END QUIZ COMPETITION**********************************************!!!\n");
            printf("\n\t\t\t===========================================================================================");
            printf("\n\t\t___________________________________________________________________________________________________________________\n\n");
        }
        else
        {
            printf("\n\n\t\t\t\t'Invalid Input !!!'");
        }
        break;
    }
    case 'Q':
    case 'q':
    {
        printf("\n\n\t\t\t\t'End Execution !!!!'");
        break;
    }
    default:
    {
        printf("\n\n\t\t\t\t'Invalid Input !!!'");
        break;
    }
    }
    getch();
    return 0;
}
//quiz competition is ended...............

//function definition for first section
int maths_library(char w)
{
    static int m = 0; //this variable 'm' counts the total number of correct answers in this section
    printf("\n\n\t\t\t  'ANSWER THE FOLLOWING QUESTIONS BY ENTERING THE ANSWER NUMBER.' \n");
    printf("\t\t\t   TRY YOUR BEST TO CHOOSE THE CORRECT OPTION IN ORDER TO TAKE MORE POINTS. \n");
    printf("\n\n\t\t\t QUESTION 1 : ");
    printf("\n\t\t\t  <> WHAT IS THE VALUE OF 'X' FOR THE INEQUALITY |2X-3|=4 ? ");
    printf("\n\t\t\t  A.7/2,1/2 \n\t\t\t  B.7/2,-1/2 \n\t\t\t  C.7/2 \n\t\t\t  D.ALL OF THE ABOVE \n");
    fflush(stdin);
    printf("\n\t\t\t  Enter your answer:");
    scanf("%c", &w);
    if ((w == 'B') || (w == 'b'))
    {
        m = m + 2; //incrementing the value of m by 2 because one question carries 2 marks
    }
    printf("\n\n\t\t\t QUESTION 2 : ");
    printf("\n\t\t\t  <> THE FUNCTION f(x)=cosx IS SYMMETRIC ABOUT ? ");
    printf("\n\t\t\t  A.Y-AXIS \n\t\t\t  B.X-AXIS \n\t\t\t  C.ORIGIN \n\t\t\t  D.NONE OF THE ABOVE \n");
    fflush(stdin);
    printf("\n\t\t\t  Enter your answer:");
    scanf("%c", &w);
    if ((w == 'A') || (w == 'a'))
    {
        m = m + 2;
    }
    printf("\n\n\t\t\t QUESTION 3 : ");
    printf("\n\t\t\t  <> THE VALUE OF (0!) AND (1!) ARE ? ");
    printf("\n\t\t\t  A.0,1 \n\t\t\t  B.0,0 \n\t\t\t  C.1,1 \n\t\t\t  D.ALL OF THESE \n");
    fflush(stdin);
    printf("\n\t\t\t  Enter your answer:");
    scanf("%c", &w);
    if ((w == 'C') || (w == 'c'))
    {
        m = m + 2;
    }
    printf("\n\n\t\t\t QUESTION 4 : ");
    printf("\n\t\t\t  <> SOLVE THE FOLLOWING TRIGNOMETRIC EQUATION : 1/1+sin0 + 1/1-sin0 ? ");
    printf("\n\t\t\t  A.sec^2(0) \n\t\t\t  B.2sec^2(0) \n\t\t\t  C.cosec^2(0) \n\t\t\t  D.2cosec^2(0) \n");
    fflush(stdin);
    printf("\n\t\t\t  Enter your answer:");
    scanf("%c", &w);
    if ((w == 'B') || (w == 'b'))
    {
        m = m + 2;
    }
    printf("\n\n\t\t\t QUESTION 5 : ");
    printf("\n\t\t\t  <> IF f(x)=x^3-2x+10, then f'(2)=? ");
    printf("\n\t\t\t  A.10 \n\t\t\t  B.12 \n\t\t\t  C.14 \n\t\t\t  D.16 \n");
    fflush(stdin);
    printf("\n\t\t\t  Enter your answer:");
    scanf("%c", &w);
    if ((w == 'A') || (w == 'a'))
    {
        m = m + 2;
    }
    return m;
}

//function definition for the second section
int physics_library(char x)
{
    static int n = 0; //this variable 'n' counts the total number of correct answers in this section
    printf("\n\n\t\t\t  'ANSWER THE FOLLOWING QUESTIONS BY ENTERING THE ANSWER NUMBER.' \n");
    printf("\t\t\t   TRY TO CHOOSE THE CORRECT OPTION IN ORDER TO TAKE MORE POINTS. \n");
    printf("\n\n\t\t\t QUESTION 1 : ");
    printf("\n\t\t\t  <> THE STUDY OF EARTHQUAKE IS CALLED ? ");
    printf("\n\t\t\t  A.SEISMOLOGY \n\t\t\t  B.COSMOLOGY \n\t\t\t  C.OROLOGY \n\t\t\t  D.ETIMOLOGY \n");
    fflush(stdin);
    printf("\n\t\t\t  Enter your answer:");
    scanf("%c", &x);
    if ((x == 'A') || (x == 'a'))
    {
        n = n + 2; //incrementing the value of n by 2 because one question carries 2 marks
    }
    printf("\n\n\t\t\t QUESTION 2 : ");
    printf("\n\t\t\t  <> THE LAWS OF ELECTROMAGNETIC INDUCTION WERE GIVEN BY ? ");
    printf("\n\t\t\t  A.FARADAY \n\t\t\t  B.TESLA \n\t\t\t  C.MAXWELL \n\t\t\t  D.COULOMB \n");
    fflush(stdin);
    printf("\n\t\t\t  Enter your answer:");
    scanf("%c", &x);
    if ((x == 'A') || (x == 'a'))
    {
        n = n + 2;
    }
    printf("\n\n\t\t\t QUESTION 3 : ");
    printf("\n\t\t\t  <> YOUNG MODULUS IS THE PROPERTY OF ? ");
    printf("\n\t\t\t  A.GAS ONLY \n\t\t\t  B.BOTH SOLID AND LIQUID \n\t\t\t  C.LIQUID ONLY \n\t\t\t  D.SOLID ONLY \n");
    fflush(stdin);
    printf("\n\t\t\t  Enter your answer:");
    scanf("%c", &x);
    if ((x == 'D') || (x == 'd'))
    {
        n = n + 2;
    }
    printf("\n\n\t\t\t QUESTION 4 : ");
    printf("\n\t\t\t  <> AN ARTIFICIAL SATELLITE REVOLVES ROUND THE EARTH IN CIRCULAR ORBIT, WHICH QUANTITY REMAINS CONSTANT ? ");
    printf("\n\t\t\t  A.ANGULAR MOMENTUM \n\t\t\t  B.LINEAR VELOCITY \n\t\t\t  C.ANGULAR DISPLACEMENT \n\t\t\t  D.NONE OF THESE \n");
    fflush(stdin);
    printf("\n\t\t\t  Enter your answer:");
    scanf("%c", &x);
    if ((x == 'A') || (x == 'a'))
    {
        n = n + 2;
    }
    printf("\n\n\t\t\t QUESTION 5 : ");
    printf("\n\t\t\t  <> ELECTRONEGATIVITY IS THE MEASURE OF ? ");
    printf("\n\t\t\t  A.METALLIC CHARACTER \n\t\t\t  B.NON-METALLIC CHARACTER \n\t\t\t  C.BASIC CHARACTER \n\t\t\t  D.NONE OF THESE \n");
    fflush(stdin);
    printf("\n\t\t\t  Enter your answer:");
    scanf("%c", &x);
    if ((x == 'B') || (x == 'b'))
    {
        n = n + 2;
    }
    return n;
}

//function definition for the third section
int chemistry_library(char y)
{
    static int o = 0; //this variable 'o' counts the total number of correct answers in this section
    printf("\n\n\t\t\t  'ANSWER THE FOLLOWING QUESTIONS BY ENTERING THE ANSWER NUMBER.' \n");
    printf("\t\t\t   TRY TO CHOOSE THE CORRECT OPTION IN ORDER TO TAKE MORE POINTS. \n");
    printf("\n\n\t\t\t QUESTION 1 : ");
    printf("\n\t\t\t  <> THE PUREST FORM OF IRON IS ? ");
    printf("\n\t\t\t  A.WROUGHT IRON \n\t\t\t  B.STEEL \n\t\t\t  C.PIG IRON \n\t\t\t  D.NICKEL STEEL \n");
    fflush(stdin);
    printf("\n\t\t\t  Enter your answer:");
    scanf("%c", &y);
    if ((y == 'A') || (y == 'a'))
    {
        o = o + 2; //incrementing the value of o by 2 because one question carries 2 marks
    }
    printf("\n\n\t\t\t QUESTION 2 : ");
    printf("\n\t\t\t  <> HYDROGEN BOMB IS BASED ON THE PRINCIPLE OF ? ");
    printf("\n\t\t\t  A.NUCLEAR FISSION \n\t\t\t  B.NUCLEAR FUSION \n\t\t\t  C.NATURAL RADIOACTIVITY \n\t\t\t  D.ARTIFICIAL RADIOACTIVITY \n");
    fflush(stdin);
    printf("\n\t\t\t  Enter your answer:");
    scanf("%c", &y);
    if ((y == 'B') || (y == 'b'))
    {
        o = o + 2;
    }
    printf("\n\n\t\t\t QUESTION 3 : ");
    printf("\n\t\t\t  <> AMONG THE FOLLOWING THE MAXIMUM COVALENT CHARACTER IS SHOWN BY THE COMPOUND ? ");
    printf("\n\t\t\t  A.MgCl2 \n\t\t\t  B.FeCl2 \n\t\t\t  C.SnCl2 \n\t\t\t  D.AlCl3 \n");
    fflush(stdin);
    printf("\n\t\t\t  Enter your answer:");
    scanf("%c", &y);
    if ((y == 'D') || (y == 'd'))
    {
        o = o + 2;
    }
    printf("\n\n\t\t\t QUESTION 4 : ");
    printf("\n\t\t\t  <> WHICH OF THE FOLLOWING IS A NON-METAL THAT REMAINS LIQUID AT ROOM TEMPERATURE ? ");
    printf("\n\t\t\t  A.CHLORINE \n\t\t\t  B.PHOSPHOROUS \n\t\t\t  C.BROMINE \n\t\t\t  D.HELIUM \n");
    fflush(stdin);
    printf("\n\t\t\t  Enter your answer:");
    scanf("%c", &y);
    if ((y == 'C') || (y == 'c'))
    {
        o = o + 2;
    }
    printf("\n\n\t\t\t QUESTION 5 : ");
    printf("\n\t\t\t  <> WHICH ONE OF THE FOLLOWING IS NOT A MIXTURE ? ");
    printf("\n\t\t\t  A.AIR \n\t\t\t  B.MERCURY \n\t\t\t  C.MILK \n\t\t\t  D.CEMENT \n");
    fflush(stdin);
    printf("\n\t\t\t  Enter your answer:");
    scanf("%c", &y);
    if ((y == 'B') || (y == 'b'))
    {
        o = o + 2;
    }
    return o;
}

//function definition for the fourth section
int generalknowledge_library(char z)
{
    static int u = 0; //this variable 'u' counts the total number of correct answers in this section
    printf("\n\n\t\t\t  'ANSWER THE FOLLOWING QUESTIONS BY ENTERING THE ANSWER NUMBER.' \n");
    printf("\t\t\t   TRY TO CHOOSE THE CORRECT OPTION IN ORDER TO TAKE MORE POINTS. \n");
    printf("\n\n\t\t\t QUESTION 1 : ");
    printf("\n\t\t\t  <> WHICH OF THE FOLLOWING IS A PALINDROME NUMBER ? ");
    printf("\n\t\t\t  A.42042 \n\t\t\t  B.23232 \n\t\t\t  C.101010 \n\t\t\t  D.01234 \n");
    fflush(stdin);
    printf("\n\t\t\t  Enter your answer:");
    scanf("%c", &z);
    if ((z == 'B') || (z == 'b'))
    {
        u = u + 2; //incrementing the value of u by 2 because one question carries 2 marks
    }
    printf("\n\n\t\t\t QUESTION 2 : ");
    printf("\n\t\t\t  <> THE COUNTRY WITH THE HIGHEST ENVIRONMENTAL PERFORMANCE INDEX IS ? ");
    printf("\n\t\t\t  A.FRANCE \n\t\t\t  B.SWITZERLAND \n\t\t\t  C.DENMARK \n\t\t\t  D.FINLAND \n");
    fflush(stdin);
    printf("\n\t\t\t  Enter your answer:");
    scanf("%c", &z);
    if ((z == 'C') || (z == 'c'))
    {
        u = u + 2;
    }
    printf("\n\n\t\t\t QUESTION 3 : ");
    printf("\n\t\t\t  <> WHICH ANIMAL LAUGHS LIKE A HUMAN BEING ? ");
    printf("\n\t\t\t  A.POLAR BEAR \n\t\t\t  B.DONKEY \n\t\t\t  C.HYENA \n\t\t\t  D.CHIMPANZEE \n");
    fflush(stdin);
    printf("\n\t\t\t  Enter your answer:");
    scanf("%c", &z);
    if ((z == 'C') || (z == 'c'))
    {
        u = u + 2;
    }
    printf("\n\n\t\t\t QUESTION 4 : ");
    printf("\n\t\t\t  <> WHAT IS THE NATIONAL GAME OF ENGLAND ? ");
    printf("\n\t\t\t  A.FOOTBALL \n\t\t\t  B.CRICKET \n\t\t\t  C.BASEBALL \n\t\t\t  D.BASKETBALL \n");
    fflush(stdin);
    printf("\n\t\t\t  Enter your answer:");
    scanf("%c", &z);
    if ((z == 'B') || (z == 'b'))
    {
        u = u + 2;
    }
    printf("\n\n\t\t\t QUESTION 5 : ");
    printf("\n\t\t\t  <> AMONG THE TOP 10 HIGHEST PEAKS IN THE WORLD , HOW MANY LIE IN NEPAL ? ");
    printf("\n\t\t\t  A.6 \n\t\t\t  B.7 \n\t\t\t  C.8 \n\t\t\t  D.9 \n");
    fflush(stdin);
    printf("\n\t\t\t  Enter your answer:");
    scanf("%c", &z);
    if ((z == 'C') || (z == 'c'))
    {
        u = u + 2;
    }
    return u;
}

void LUCKGAME()
{
    int i, j, n, k = 2, *pt;
    struct member a[k];
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n========================================================================================================================================================================\n\n");
    printf("\n                       >>>>>>>>>>>>>>>>>>>>                     WELCOME TO LUCK GAME             <<<<<<<<<<<<<<<<<<<<<                                        ");
    printf("\n\n\n\n========================================================================================================================================================================\n\n");
    system("pause");
    system("cls");
    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t>>>>>>>>>>>>>>>> INSTRUCTIONS TO PLAY <<<<<<<<<<<<<<<<<\n\n");
    printf("\t\t\t\t__________________________________________________________________________________________\n");
    printf("\t\t\t\t\t\t_______________________________________________________\n");
    printf("\t\t\t\t\t\t\t\t___________________________\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t>>>>>>     YOU HAVE TO SELECT EVEN NO OF BOXES .........\n\n\n\n");
    printf("\t\t\t\t\t\t>>>>>>     THE DESIRED NO OF BOXES WILL BE GENERATED CONTAINING HIDDEN CASH .........\n\n\n\n");
    printf("\t\t\t\t\t\t>>>>>>     EACH PLAYER HAS TO SELECT THE BOXES ONE BY ONE .........\n\n\n\n");
    printf("\t\t\t\t\t\t>>>>>>     THE CASH WILL BE GIVEN TO THE PLAYERS AFTER EACH TURN .........\n\n\n\n");
    printf("\t\t\t\t\t\t>>>>>>     IN THE END THE PLAYER WHO WILL GET THE GREATER AMOUNT WILL BE DECLARED WINNER .........\n\n\n\n\n");
    printf("\t\t\t\t\t\t***************************** BEST OF LUCK ********************************\n\n");
    system("pause");
    system("cls");
    system("cls");
    gotoxy(70, 20);
    printf("PLEASE WAIT....");
    sleep(2);
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                            FOR PLAYER A:\n\n");
    printf("                                            =============\n\n\n\n");
    printf("                                            ENTER YOUR NAME: ");
    fflush(stdin);
    gets(a[0].name);
    printf("\n\n\n\n                                            FOR PLAYER B:\n\n");
    printf("                                            =============\n\n\n\n");
    printf("                                            ENTER YOUR NAME: ");
    fflush(stdin);
    gets(a[1].name);
    system("cls");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < strlen(a[i].name); j++)
        {
            if (a[i].name[j] >= 'a' && a[i].name[j] <= 'z')
                a[i].name[j] -= 32;
        }
    }
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                                       ENTER EVEN NO OF BOXES: ");
    scanf("%d", &n);
    system("cls");
    while (n % 2 != 0)
    {
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                                             PLEASE CHOOSE EVEN: ");
        scanf("%d", &n);
        system("cls");
    }
    system("cls");
    pt = (int *)calloc(n, sizeof(int));
    if (pt == NULL)
    {
        printf("Memory not allocated");
        exit(0);
    }
    srand(time(0));
    for (i = 0; i < n; i++)
    {
        *(pt + i) = rand() / 11 + 100;
    }
    LuckBase(pt, n, a, k);
}
void LuckBase(int *pt, int n, struct member a[], int k)
{
    FILE *fp1, *fp2;
    int i = 0, cA = 0, cB = 0, x, y, z, h = 0, g = 0, e = 0, f = 0, b[n], p1[n], p2[n], v;
    time_t start, end;
    fp1 = fopen("player1(record).txt", "w");
    fp2 = fopen("player2(record).txt", "w");
    fprintf(fp1, "\n\n >>>>>>>>>>> %s'S RECORD <<<<<<<<<<<<<<\n\n", a[0].name);
    fprintf(fp2, "\n\n >>>>>>>>>>> %s'S RECORD <<<<<<<<<<<<<<\n\n", a[1].name);
    for (v = 0; v < n; v++)
    {
        b[v] = 0;
        p1[v] = 0;
        p2[n] = 0;
    }
    while (i < n) //turn responsible
    {
        start = time(NULL);
        for (x = h; x < n / 2; x++)
        {
            printf("\n\n\n\n\n\n\n\n\n\n\n                     %s'S TURN # %d :\n\n", a[0].name, e + 1);
            printf("                    ==========================\n\n\n\n");
            printf("                    BOXES AVAILABLE:  |");
            for (v = 0; v < n; v++)
            {
                if (b[v] != -1)
                    printf(" %d |", v + 1);
            }
            printf("\n\n\n\n                    CHOOSE A BOX: ");
            scanf("%d", &z);
            while (z > n || z < 1 || p1[z - 1] == -1 || p2[z - 1] == -2)
            {
                if (z > n || z < 1)
                {
                    system("cls");
                    printf("\n\n\n\n\n\n\n\n\n\n\n                     %s'S TURN # %d :\n\n", a[0].name, e + 1);
                    printf("                    ==========================\n\n\n\n");
                    printf("                    BOXES AVAILABLE:  |");
                    for (v = 0; v < n; v++)
                    {
                        if (b[v] != -1)
                            printf(" %d |", v + 1);
                    }
                    printf("\n\n\n\n                    HAVE NO SUCH BOX , CHOOSE ANOTHER: ");
                    scanf("%d", &z);
                }
                else if (p2[z - 1] == -2)
                {
                    system("cls");
                    printf("\n\n\n\n\n\n\n\n\n\n\n                     %s'S TURN # %d :\n\n", a[0].name, e + 1);
                    printf("                    ==========================\n\n\n\n");
                    printf("                    BOXES AVAILABLE:  |");
                    for (v = 0; v < n; v++)
                    {
                        if (b[v] != -1)
                            printf(" %d |", v + 1);
                    }
                    printf("\n\n\n\n                    ALREADY CHOOSEN BY ''%s'', CHOOSE ANOTHER: ", a[1].name);
                    scanf("%d", &z);
                }
                else
                {
                    system("cls");
                    printf("\n\n\n\n\n\n\n\n\n\n\n                     %s'S TURN # %d :\n\n", a[0].name, e + 1);
                    printf("                    ==========================\n\n\n\n");
                    printf("                    BOXES AVAILABLE:  |");
                    for (v = 0; v < n; v++)
                    {
                        if (b[v] != -1)
                            printf(" %d |", v + 1);
                    }
                    printf("\n\n\n\n                    ALREADY CHOOSEN BY ''YOU'', CHOOSE ANOTHER: ");
                    scanf("%d", &z);
                }
            }
            printf("\n\n\n                    BOX %d CONTAINS : %d Rs (cash)\n", z, *(pt + (z - 1)));
            end = time(NULL);
            fprintf(fp1, "TURN # %d\n\n", e + 1);
            fprintf(fp1, "=========\n\n\n");
            fprintf(fp1, "TOOK %f SEC TO DECIDE\n\n", difftime(end, start));
            fprintf(fp1, "SELECTED BOX : %d\n\n", z);
            fprintf(fp1, "BOX %d CONTAINED : %d (cash)\n\n", z, *(pt + (z - 1)));
            cA = cA + *(pt + (z - 1));
            b[z - 1] = -1;
            p1[z - 1] = -1;
            i++;
            e++;
            printf("\n\n\n                    YOU HAVE EARNED TILL NOW : %d Rs\n\n\n", cA);
            printf("************************************************************************************************************************************************************************");
            break;
        }
        system("pause");
        system("cls");
        h = x;
        start = time(NULL);
        for (y = g; y < n / 2; y++)
        {
            printf("\n\n\n\n\n\n\n\n\n\n\n                    %s'S TURN # %d :\n\n", a[1].name, f + 1);
            printf("                    ==========================\n\n\n\n");
            printf("                    BOXES AVAILABLE:  |");
            for (v = 0; v < n; v++)
            {
                if (b[v] != -1)
                    printf(" %d |", v + 1);
            }
            printf("\n\n\n\n                    CHOOSE A BOX: ");
            scanf("%d", &z);
            while (z > n || z < 1 || p1[z - 1] == -1 || p2[z - 1] == -2)
            {
                if (z > n || z < 1)
                {
                    system("cls");
                    printf("\n\n\n\n\n\n\n\n\n\n\n                    %s'S TURN # %d :\n\n", a[1].name, f + 1);
                    printf("                    ==========================\n\n\n\n");
                    printf("                    BOXES AVAILABLE:  |");
                    for (v = 0; v < n; v++)
                    {
                        if (b[v] != -1)
                            printf(" %d |", v + 1);
                    }
                    printf("\n\n\n\n                    HAVE NO SUCH BOX , CHOOSE ANOTHER: ");
                    scanf("%d", &z);
                }
                else if (p1[z - 1] == -1)
                {
                    system("cls");
                    printf("\n\n\n\n\n\n\n\n\n\n\n                    %s'S TURN # %d :\n\n", a[1].name, f + 1);
                    printf("                    ==========================\n\n\n\n");
                    printf("                    BOXES AVAILABLE:  |");
                    for (v = 0; v < n; v++)
                    {
                        if (b[v] != -1)
                            printf(" %d |", v + 1);
                    }
                    printf("\n\n\n\n                    ALREADY CHOOSEN BY ''%s'', CHOOSE ANOTHER: ", a[0].name);
                    scanf("%d", &z);
                }
                else
                {
                    system("cls");
                    printf("\n\n\n\n\n\n\n\n\n\n\n                    %s'S TURN # %d :\n\n", a[1].name, f + 1);
                    printf("                    ==========================\n\n\n\n");
                    printf("                    BOXES AVAILABLE:  |");
                    for (v = 0; v < n; v++)
                    {
                        if (b[v] != -1)
                            printf(" %d |", v + 1);
                    }
                    printf("\n\n\n\n                    ALREADY CHOOSEN BY ''YOU'', CHOOSE ANOTHER: ");
                    scanf("%d", &z);
                }
            }
            printf("\n\n\n                    BOX %d CONTAINS : %d Rs (cash)\n", z, *(pt + (z - 1)));
            end = time(NULL);
            fprintf(fp2, "TURN # %d\n\n", f + 1);
            fprintf(fp2, "=========\n\n\n");
            fprintf(fp2, "TOOK %f SEC TO DECIDE\n\n", difftime(end, start));
            fprintf(fp2, "SELECTED BOX : %d\n\n", z);
            fprintf(fp2, "BOX %d CONTAINED : %d (cash)\n\n", z, *(pt + (z - 1)));
            cB = cB + *(pt + (z - 1));
            b[z - 1] = -1;
            p2[z - 1] = -2;
            i++;
            f++;
            printf("\n\n\n                    YOU HAVE EARNED TILL NOW : %d Rs\n\n\n", cB);
            printf("************************************************************************************************************************************************************************");
            break;
        }
        system("pause");
        system("cls");
        g = y;
    }
    fprintf(fp1, "__________________________________________________\n\n");
    fprintf(fp1, "      TOTAL: %d\n\n", cA);

    fprintf(fp1, "__________________________________________________\n\n");
    fprintf(fp2, "\n\n");
    fprintf(fp2, "__________________________________________________\n\n");
    fprintf(fp2, "      TOTAL: %d\n\n", cB);
    fprintf(fp2, "__________________________________________________\n\n");
    if (cA > cB)
    {
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n           >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>    WINNER OF THE GAME     <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n\n\n");
        printf("________________________________________________________________________________________________________________________________________________________________________\n\n");
        printf("                                                            ''%s'' (AWARDED CASH OF RS %d)\n\n", a[0].name, cA);
        printf("________________________________________________________________________________________________________________________________________________________________________");
    }
    else
    {
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                                             ''WINNER OF THE GAME''\n\n\n\n");
        printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
        printf("                                                            ''%s'' (AWARDED CASH OF RS %d)\n\n", a[1].name, cB);
        printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
    }
    fclose(fp1);
    fclose(fp2);
    free(pt);
}

/* ......................ENDED....................... */

int main()
{
    system("cls");
    Intro();
    showmenu();
}
