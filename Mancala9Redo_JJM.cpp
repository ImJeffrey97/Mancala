/*
Jeffrey Markham 
Title: Mancala game 9 Redo
Description: playing the mancala game  
Due Date: 12/04/2020
*/

#include <iostream> 
#include <iomanip>
using namespace std;

const int MAX = 14;//size of bead array
void printSolidLine (int numStars);//prints solid line to the screen
void printDottedLine();//prints dotted line to the screen
void drawBoardGame(int beadArray[MAX]);//prints board game to screen
void showTopRowNumbers();//prints the top row numbers 
void showBottomRowNumbers();//prints bottom row numbers
void initializeArray(int beadArray[MAX]);//fills bins up with beads
void printArray(int beadArray[MAX]);//will print out beads to the screen
void showTopBins(int beadArray[MAX]);//will show values of top bins
void showBottomBins(int beadArray[MAX]);//will show value of bottom bins
int gameOverCheck(int beadArray[MAX]);//determines if the game is over and which player won
void testArray(int beadArray[MAX]);//test array to show that player 2 wins
int getStartingBin(int player, int beadArray[MAX]);//player chooses the bin to start the game
int binChoice;//player chooses a bin
void dropBeads(int player, int beadArray[MAX]);//this function will drop beads in the bins

int main()
{  
    int beadArray[MAX];//array for beads 
    int winner = -1;//winner of the game
    int player = 1;//player 1 or player 2

    initializeArray(beadArray);
    //testArray(beadArray);//for testing
    //printArray(beadArray);
    drawBoardGame(beadArray);
    do
    {
        //dropBeads(player, beadArray);
        if (player == 1)
        {
            dropBeads(player,beadArray);
            player++;
        }
        else if (player == 2)
        {
            dropBeads(player, beadArray);
            player--;
        }
        winner = gameOverCheck(beadArray);
    } while (winner == -1);
    drawBoardGame(beadArray);
    if (winner == 1)
    {
        cout << "Player 1 Wins";
    }
    else if (winner == 2)
    {
        cout << "Player 2 wins";
    }
    else if (winner == 3)
    {
        cout << "Tie";
    }
    else //(winner == 3)
    {
        cout << "No Winner";
    }

    cout << endl;
    system ("pause");
    return 0;
}

/*****************************
 function: printSolidLine
 description: prints solid line to the screen
 @param1: numStars - number of stars going to the screen
 @return: void
*****************************/

void printSolidLine(int numStars)
{
    for (int i = 0; i < numStars; i++)
    {
        cout << '*';
    }
}//end printSolidLine

/*****************************
 function: printDottedLine
 description: prints a dotted line to screen
 @param1: none
 @return: void
 ****************************/

void printDottedLine()
{
    for (int i = 0; i < 8; i++)
    {
        cout << '*';

        for (int i = 0; i < 6; i++)
        {
            cout << " ";
        }
    }
    cout << '*';
}//end of printDottedLine

/**********************************
 function: showTopRowNumbers
 description: shows the top row of numbers
 @param1: none
 @return: void
**********************************/

void showTopRowNumbers()
{
    cout << "*      ";
    for (int i = 0; i < 6; i++)
    {
        cout << '*' << setw(3) << i << setw(3) << ' ';
    }
    cout << "*      *";
}//end of showTopRowNumbers

/*********************************
 function: showBottomRowNumbers
 description: shows the bottom row numbers
 @param1: none
 @return: none
**********************************/

void showBottomRowNumbers()
{
    cout << "*      ";
    for (int i = 12; i > 6; i--)
    {
        cout << '*' << setw(3) << i << setw(3) << ' ';
    }
    cout << "*      *";
}//end of showBottomRowNumbers

/*****************************
function: drawBoardGame
description: prints Board Game 
@param1: none
@return: void
****************************/

void drawBoardGame(int beadArray[MAX])
{
    printSolidLine(57);
    cout << endl;
    printDottedLine();
    cout << endl;
    showTopRowNumbers();
    cout << endl;
    printDottedLine();
    cout << endl;
    showTopBins(beadArray);
    cout << endl;
    printDottedLine();
    cout << endl;
    printDottedLine();
    cout << endl;
    cout << "*   13 ";
    printSolidLine(43);
    cout << "  6   *";
    cout << endl;
    printDottedLine();
    cout << endl;
    showBottomRowNumbers();
    cout << endl;
    printDottedLine();
    cout << endl;
    showBottomBins(beadArray);
    cout << endl;
    printDottedLine();
    cout << endl;
    printDottedLine();
    cout << endl;
    printSolidLine(57);
    cout << endl;
}// end of drawBoard

/**********************************
 function: intializeArray
 description: fills bins with beads
 @param1: beadArray[] - number of beads in bin
 @return: none
***********************************/

void initializeArray(int beadArray[MAX])
{
    for (int i = 0; i < MAX; i++)
    {
        beadArray[i] = 4; 
    }
    beadArray[13] = 0;
    beadArray[6] = 0;
}//end of intializeArray

/**********************************
 function: printArray
 description: prints the value of the array to 4
 @param1: beadArray[] - number of beads in bins
 @return: none
**********************************/

void printArray(int beadArray[MAX])
{
    for (int i = 0; i < 6; i++)
    {
        cout << beadArray[i] << " "; 
    }
    cout << beadArray[6] << " ";
    cout << "| ";
    for (int i = 7; i < MAX; i++)
    {
        cout << beadArray[i] << " "; 
    }
    cout << endl;
}// end of prinArray

/***********************************
 function: showTopBins
 description: shows beads in the top bin
 @param1: beadArray[]- number of beads in bin
 @return: void 
***********************************/

void showTopBins(int beadArray[MAX])
{
    cout << "*      ";
    for (int i = 0; i < 6; i++)
    {
        cout << '*' << setw(3) << beadArray[i] << setw(3) << ' ';
    }
    cout << "*      *";
}//end of showTopBins

/********************************
 function: showBottomBins
 description: prints bottom row of beads
 @param1: beadArray[] - number of beads in bin
 @return: void
********************************/

void showBottomBins(int beadArray[MAX])
{
    cout << '*' << setw(5) << beadArray[13] << ' ';
    for (int i = 12; i > 6; i--)
    {
        cout << '*' << setw(3) << beadArray[i] << setw(3) << ' ';
    }
    cout << '*' << setw(3) << beadArray[6] << setw(4) <<  '*'; 
}//end of showBottomBins

/***********************************
 function: gameOverCheck
 description: checks to see if the game is over
 @param1: beadArray[] - number of beads in bin
 @return: winner
**********************************/

int gameOverCheck(int beadArray[MAX])
{
    int winner = -1;//variable for the winner 
    int player1Sum = 0;//sum of all middle bin locations for player 1
    int player2Sum = 0;//sum of all middle bin locations for player 2 
    for (int i = 0; i < 6; i++)//from bead array 0 to 5
    {
        player1Sum = player1Sum + beadArray[i];//sum of all bin locations for player 1 
    }
    for (int i = 12; i > 6; i--)//from bead array 12 to 7
    {
        player2Sum = player2Sum + beadArray[i];//sum of all bin locations for player 2
    }
    if (player1Sum == 0 || player2Sum == 0)// check if a player has emptied middle bins
    {
        if (player1Sum == 0)//move opponent player middle bin beads
        {
            beadArray[6] = beadArray[6] + player2Sum;
        }
        else 
        {
            beadArray[13] = beadArray[13] + player1Sum;
        }
        for (int i = 0; i < 6; i++)
        {
            beadArray[i] = 0;
        }
        for (int i = 12; i > 7; i--)
        {
            beadArray[i] = 0;
        }
        if (beadArray[6] > beadArray[13])
        {
            winner = 1;
        }
        else if (beadArray[13] > beadArray[6])
        {
            winner = 2;
        }
        else
        {
            winner = 3;
        }
    }
    return winner;   
}// end of gameOverCheck

/*******************************
 function: testArray
 description: fill beadArray with any values for testing
 @param1: beadArray[] - number of beads in each bin
 @return: none
*******************************/

void testArray(int beadArray[MAX])
{
    beadArray[0] = 0;
    beadArray[1] = 0;
    beadArray[2] = 0;
    beadArray[3] = 0;
    beadArray[4] = 0;
    beadArray[5] = 1;
    beadArray[6] = 20;//player 1 end bin

    beadArray[7] = 0;
    beadArray[8] = 0;
    beadArray[9] = 0;
    beadArray[10] = 0;
    beadArray[11] = 2;
    beadArray[12] = 0;
    beadArray[13] = 20;// player 2 end bin
}//end of testArray

/****************************************
 function: getStartingBin
 description: a player chooses a bin the move the beads
 @param1: player - player 1 or player two
 @param2: beadArray[] - beads in each bin
 @return: valid bin choice
****************************************/

int getStartingBin(int player, int beadArray[MAX])
{
    int low;//low range for player
    int high;//high range for player
    int binChoice;//bin choice for players
    if (player == 1)
    {
       low = 0;
       high = 5;
    }
    else
    {
        low = 7;
        high = 12;
    }
    cout << "Player " << player << " turn" << endl;
    cout << "Enter bin " << low << "-" << high << endl;
    cin >> binChoice;

    while(binChoice < low || binChoice > high || beadArray[binChoice] == 0)
    {
        if (binChoice < low || binChoice > high)
        {
            cout << "Choose a new bin" << endl;
            cin >> binChoice;
        }
        else
        {
            cout << "The bin you selected is empty, pick again" << endl;
            cin >> binChoice;
        }
    }
    return binChoice;
}//end of getStartingBin 

/*************************************
 function: dropBeads
 description: drops beads into bin
 @param1: player - player one or player two
 @param2: beadArray[] - beads in each bin
 @return: none
*************************************/

void dropBeads(int player, int beadArray[MAX])
{
    int endBin;//endbin for each player
    int oppEndBin;//endbin for opposing player
    int bin;//choosing a bin to pick up
    int hand;//picking up the beads

    if(player == 1)
    {
        endBin = 6;
        oppEndBin = 13;
    }
    else
    {
        endBin = 13;
        oppEndBin = 6;
    }
    do
    {
        bin = getStartingBin(player, beadArray);
        printArray(beadArray);//for testing
        do
        {
            hand = beadArray[bin];
            beadArray[bin] = 0;
            while(hand > 0)
            {
                bin++;
                if (bin == oppEndBin)
                {
                    bin++;
                }
                else
                {
                    ;
                }
                if (bin > 13)
                {
                    bin = 0;
                }
                else
                {
                    ;
                }
                beadArray[bin]++;
                hand--;
                printArray(beadArray);//for testing
            }
        } while (beadArray[bin] > 1 && bin != endBin);
        drawBoardGame(beadArray);
    } while (bin == endBin && gameOverCheck(beadArray) == -1);
}//end of dropBeads

//problems: I had a problem on line 434 with the while statement saying that gameovercheck was "ISO C++ forbids comparison between pointer and integer [-permissive]
//but I added beadArray into it and it seemed to work, I was wondering why I was getting that error."

