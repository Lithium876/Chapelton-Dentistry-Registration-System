/**
THIS CODE IS DESIGNED TO RUN ON UNIX SYSTEMS (MAC OR LINUX)
IF YOU ARE USING WINDOWS TO COMPLIE THIS CODE, YOU'LL NEED TO MAKE A COUPLE CANGES.

THESE CHANGES ARE:
1. REPLACE <unistd.h> WITH <time.h>
2. REPLACE <termios.h> WITH <conio.h>
3. REMOVE THE GETCH FUNCTION FROM THE CODE (IT IS INDECATED IN THE CODE AS "GETCH FUNCTION")
4. REPLACE ALL INSTANCES OF sleep() WITH Sleep()
5. IN THE SLEEP FUNCTION, THE DIGIT WHICH INDICATES THE NUMBER OF SECONDS TO PAUSE FOR SHOULD BE IN MILLISECONDS.
   I.E. 1 SECOND = 1000 MILLISECONDS
7. ALL INSTANCES OF "clear" SHOULD BE REPLACED WITH "cls"
8. SEE COMMENTS FOR MORE CHANGES.. (LOGIN FUNCTION)
**/

//--- Header Files ----
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>  /**This library is only for unix users (Mac or Linux) for windows users this library would have to be
                     replaced with the time.h library to use the sleep() function**/

#include <termios.h> /**This library is only for unix users (Mac or Linux) for windows users this library would have to be
                     replaced with the conio.h library to use the getch() function**/
//---------------------

//--- Function Proto-types-----
void login();				//Login Function username: Admin password: P@$$w0rd (case sensitive)
int displaymenu();		    //Display the menu
void menu();				//Calls the respective function based on the option selected in the menu displayed
/**void add();				//Allows the user to add patients into a structure array
void search();              //ALlows the user to search for a patients based on patient number
void display();	**/			//Displays all patient detals
//---------------------------------------------------------------------------------------------------

//------------------------- MAIN FUNCTION ------------------------
int main()
{
    int choice;
   // login();                //Calling the login function
    choice=displaymenu();   //Calling the display menu function and storing the return valued the the variable "choice"
    menu(choice);			//Calling the "choice" option function from the menu function
	getch();				//Holds the information on the screen until a key is pressed
    return 0;
}
//--------------------------------------------------------------------------------------------------

//---------------------- MENU FUNCTION ---------------------------
void menu(int x)									//Function accepts an integer value of "choice" from the main function
{
    switch(x)
    {
        case 1:                                     //Executes the following block of code if the integer value x is 1
        {
			system("clear");						//Clears the screen
			puts("\n \t \t  |=======================================|");
			puts("\t \t  |\t         ADD PATIENT     \t  |");
			puts("\t \t--|=======================================|--");
			//add();								//Add function called to add records Patient structure
            break;									//Ends this instance of the program
        }

        case 2:										//Executes the following block of code if the integer value x is 2
        {
			system("clear");						//Clears the screen
			puts("\n \t \t  |=======================================|");
			puts("\t \t  |\t       LOOK UP PATIENT    \t  |");
			puts("\t \t--|=======================================|--");
			//search();								//ALlows the user to search for a patients based on patient number
            break;									//Ends this instance of the program
        }

        case 3:                                     //Executes the following block of code if the integer value x is 3
        {
            system("clear");						//Clears the screen
			puts("\n \t \t  |=======================================|");
			puts("\t \t  |\t       PATIENT DETAILS \t\t  |");
			puts("\t \t--|=======================================|--");
			//display();							//Display all patient details
            break;									//Ends this instance of the program
        }

        case 4:                                     //Executes the following block of code if the integer value x is 4
        {
			printf("\t\t\t\tLogin Out...\n");       //Message to user
			sleep(2);							    //Pause program for 2 seconds
            exit(0);								//Close program
            break;									//Ends this instance of the program
        }
        default:                                    //Executes the following block of code if the integer value x is not any of the instances above
            {
                printf("\a \t \t|    Invaild Option Selection, Try Again    |\n");
                puts("\t \t|-------------------------------------------|");
                sleep(1);                         //Pause program for 1 second
                system("clear");			     //Clears Screen
                menu(displaymenu());		    //Calls the menu function using the return value from the displaymenu function as arugment
                break;						   //Ends this instance of the program
            }
    }
}
//-------------------------------------------------------------------------------------

//---------------- DISPLAY MENU FUNCTION -----------------
int displaymenu()
{
    int option;
    puts("\n \t \t  |=======================================|");
    puts("\t \t  | \t           MAIN MENU \t \t  |");
    puts("\t \t--|=======================================|--");
    printf("\t \t|  Select the number that corresponds with  |\n \t \t|\t \t your option.\t \t    |\n");
    puts("\t \t|-------------------------------------------|");
    printf("\t \t|\t  1. Add Patient \t\t    |\n");
    printf("\t \t|\t  2. Look up Patient \t \t    |\n");
    printf("\t \t|\t  3. Display Patient Details\t    |\n");
    printf("\t \t|\t  4. Exit\t \t \t    |\n");
    puts("\t \t|-------------------------------------------|");
    printf("\t \t| Option: ");
    scanf("%d",&option);
    puts("\t \t|-------------------------------------------|");
    return option;  //Returns the number the user chooses and stores it in the "choice" variable in the main function
}
//--------------------------------------------------------------------------------------

//------------------- LOGIN FUNCTION -----------------------------
void login()
{
    int i;									     //Variable Declaration
    char uid[25],pwd[25],s_uid[25]={"Admin"};    /**Created three variables one for user ID (uid[25]) and one user password
                                                 (pwd[25]). s_uid[25] is the varible holding the user ID the user is suppose to
                                                 enter to get in the system. Anything other that user ID (Admin) will be not
                                                 have access to the system**/

    char s_pwd[25]={"p@$$w0rd"},ch=' ';          /**Created a variable (s_pwd[25]) to hold the password the user is suppose to
                                                 enter to get access to the system. Anything other that user password (p@$$w0rd)
                                                 will be not have access to the system. **/
	puts("\n\n\n\n\n\t\t\t\t    WELCOME");
	puts("\n\t\t    CHAPELTON DENTISTRY REGISTRATION SYSTEM");
    puts("\n\t \t \t |-----------------------------|");
    puts("\t \t \t |             LOGIN           |");
    puts("\t \t \t |-----------------------------|");
    printf(" \t \t \t |Enter the User ID : ");
    scanf("%s",uid);
    getchar();
    printf(" \t \t \t |Enter the Password : ");
    i=0;
    while(1)	 //Loops code forever
    {
        ch=getch();
        if(ch==10)			 //10 is the ASCII value for the "Enter" key. Windows users would use the value 13 instead.
            break;			 //Exit loop
        else if(ch==127)	 //127 is the ASCII value for the "backspace" key. Windows users would use the value 8 instead.
        {       if(i!=0)     //This is for avoiding the input from being deleted
            {
                printf("\b");		//'\b' represents blackspace escape character
                printf(" ");
                printf("\b");		//'\b' represents blackspace escape character
                i--;                //Go back to the array position that had the character that was removed by backspace
                pwd[i]='\0';        //End of array
            }
            else
                continue;
        }
        else
        {
            putchar('*');         //Replaces each character type by a *
            pwd[i]=ch;            //Adds the character typed to the pwd array
            i++;                  //Move to the next postion in the array
        }
    }
    puts("\n \t \t \t |-----------------------------|");
    pwd[i]='\0';
    if((strcmp(uid,s_uid))==0 && (strcmp(pwd,s_pwd))==0) //checks if the user input is the same as what was set in the code (Admin, p@$$20rd)
    {
        printf("\t \t \t |\t USER AUTHENTICATED    |");
        puts("\n \t \t \t |-----------------------------|");
        sleep(1); //Pause the program for 1 second. Windows users would have to change this function to Sleep(1000) to get the same result
        system("clear"); //"clear" is for unix users. Windows users whould use "cls" instead of "clear"
    }
    else
    {
        printf("\t \a \t \t |UNABLE TO AUTHENTICATE USER, |\n \t \t \t | \t    Try again\t       |");
        puts("\n \t \t \t |-----------------------------|");
        sleep(2); //Pause the program for 2 second. Windows users would have to change this function to Sleep(2000) to get the same result
        system("clear"); //"clear" is for unix users. Windows users whould use "cls" instead of "clear"
		fflush(stdin);
        login(); //Recall the login function (Recursion)
    }
}
//-----------------------------------------------------------------------------------------

//------------------- GETCH FUNCTION -----------------------------
/**BECAUSE UNIX SYSTEMS DON'T SUPPORT THE CONIO.H LIBRARY THAT CONTAINS IT'S OWN BUILT IN GETCH() FUNCTION
WE HAVE TO MANUALLY BUILD A GETCH FUNCTION SUPPORTED BY THE TERMIOS.H LIBRARY. WINDOWS USERS CAN USE INCLUDE
THE CONIO.H AND REMOVE THIS FUNCTION**/

int getch(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO);//knock down keybuffer
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    system("stty -echo");//shell out to kill echo
    ch = getchar();
    system("stty echo");
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}
//-----------------------------------------------------------------------------------------
