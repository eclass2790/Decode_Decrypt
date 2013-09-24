//Elbert Dockery
//Decode Project

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <cassert>
#include <string>
#include <string.h>
using namespace std;

const int MaxNumberOfWords = 22000;
const int InputLength = 128;
const int Size = 16;

//Function to lookup words in dictionary array
bool lookUpWord(char array[][Size], char inputWord[Size])
{
	bool wordFound = false;
	char dictWord[Size];
	char* pDictWord = &dictWord[0];
    
	char* pInputWord = &inputWord[0];
    
	for( int i = 0; i < MaxNumberOfWords; i++ )
	{
		for( int j = 0; j < Size; j++ )
		{
			dictWord[j] = array[i][j];		//store each word into one demensional array in order to compare to inputWord
			//cout << pDictWord << "\n";
			//cout << pInputWord << "\n";
		}
        if(strcmp(pDictWord, pInputWord) == 0)
        {
            wordFound = true;
            break;
            break;
            break;
            break;
        }
	}
    return wordFound;
}

//Function to do vigenere encryption
void vigenereCypher(char array[], char key[])
{
	int x = strlen(key);
	char encoded[InputLength] = "NULL";
	int j = 0;
    
	//Loop to turn words into all caps
	for(int i = 0; i < strlen(array); i++)
	{
		if(array[i] >= 'a' && array[i] <= 'z')
		{
			array[i] += 'A' - 'a';
		}		
	}
    
	//Loop to turn key words into all caps
	for(int i = 0; i < strlen(key); ++i)
    {
        if(key[i] >= 'a' && key[i] <= 'z')
        {
			key[i] += 'A' - 'a';
        }
	}
    
	//The Encryption
	for(int i = 0; i < strlen(array); i++)
	{
		if(array[i] >= 'A' || array[i] <= 'Z')
		{
            if(isspace(array[i]) || ispunct(array[i]))
            {
                encoded[i] = ' ';
            }
			else 
                encoded[i] = (array[i] + key[j] - 2*'A') % 26 + 'A'; 
            j = (j + 1) % strlen(key);
            //cout << key[i];
		}	
	}
	cout << encoded << endl;
}

//Function for vigenere decryption
void vigenereDecrypt(char array[], char key[])
{
	int x = strlen(key);
	char encoded[InputLength] = "NULL";
	int j = 0;
    
	//Loop to turn words into all caps
	for(int i = 0; i < strlen(array); i++)
	{
		if(array[i] >= 'a' && array[i] <= 'z')
		{
			array[i] += 'A' - 'a';
		}		
	}
    
	//Loop to turn key words into all caps
	for(int i = 0; i < strlen(key); ++i)
    {
        if(key[i] >= 'a' && key[i] <= 'z')
        {
			key[i] += 'A' - 'a';
        }
	}
    
	//The Decryption
	cout << array << endl;
	for(int i = 0; i < strlen(array); i++)
	{
		if(array[i] >= 'A' || array[i] <= 'Z')
		{
            if(isspace(array[i]) || ispunct(array[i]))
            {
                encoded[i] = ' ';
            }
			else 
                encoded[i] = (array[i] - key[j] + 26) % 26 + 'A'; 
            j = (j + 1) % strlen(key);
		}		 
	}
	cout << encoded << endl;
}

//Function to transpose
void transpose(char input[], const int transValue)
{
	for(int i = 0; i < strlen(input); i++)
	{
		if(isspace(input[i]) || ispunct(input[i]))
        {
                input[i] = ' ';
        }
        else if(input[i] == 'z')  //wrap around
        {
			if(transValue == 0)
			{
				input[i] = 'a';             //no wrap around
			}

			else if(transValue >= 1)
			{
				input[i] = 'a' + (transValue - 1);
			}
        }
		else if(input[i] == 'Z')  //wrap around
        {
			if(transValue == 0)
			{
				input[i] = 'A';            //no wrap around
			}

			else if(transValue >= 1)
			{
				input[i] = 'A' + (transValue - 1);
			}
        }
        else if ( (input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z') )
        {
             if(input[i]>= 'a' && input[i] <= 'z')
             {
              if ( input[i] -'a' + transValue >= 26)
{
//wrap around for lowercase
}                
             }
             else 
{
 input[i] = input[i] + transValue;
}
            if (input[i] >= 'A' && input[i] <= 'Z')
            {
             if ( input[i] -'A' + transValue >= 26)    //wrap around for uppercase
            }
             else 
{
 input[i] = input[i] + transValue;
}
            input[i] = input[i] + transValue;
        }
	}
}

//Function to un-transpose
void detranspose(char input[], const int deTransValue)
{
	for(int i = 0; i < strlen(input); i++)
	{
		if(isspace(input[i]) || ispunct(input[i]))
        {
            input[i] = ' ';
        }
        else if(input[i] == 'a')  //wrap around
        {
			if(deTransValue == 0)
			{
				input[i] = 'z';             //no wrap around
			}
            
			else if(deTransValue >= 1)
			{
				input[i] = 'z' - (deTransValue - 1);
			}
        }
		else if(input[i] == 'A')  //wrap around
        {
			if(deTransValue == 0)
			{
				input[i] = 'Z';            //no wrap around
			}
            
			else if(deTransValue >= 1)
			{
				input[i] = 'Z' - (deTransValue - 1);
			}
        }
        else if ( (input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z') )
        {
            input[i] = input[i] - deTransValue;
        }
    }
	cout << input << endl;
}

//Function to reverse order of a word
void reverse(char input[])
{
	int n = strlen(input);
	char c;
    for (int i = 0; i < n/2; i++) 
    {
        c = input[i];
        input[i] = input[n-i-1];
        input[n-i-1] = c;
    }
    cout << input << endl;
}

//Function to un-reverse
void deverse(char input[])
{
	int n = strlen(input);
	char c;
    for (int i = 0; i < n/2; i++) 
    {
        c = input[n-i-1];
        input[n-i-1] = input[i];
        input[i] = c;
    }
    cout << input << "\n";
}

int main()
{
    /*************************TITLE*******************************/
	cout << "Authors: Andre Thomas, Jr. and Elbert Dockery\n"
    << "Progam 4: Decode\n"
    << "TA: Sean Deitz\n"
    << "November 14 2012\n"
    << endl;
    /*************************************************************/
    
    /***************************MENU*****************************/
	int menuInput;
	cout << "Chose from the following options\n"
    << "1. Encode some text\n"
    << "2. Decode using user-entered values\n"
    << "3. Decode the ciphertext given with the assignment\n"
    << "4. Exit the program\n"
    << endl;
    
	cout << "Input = ";
	cin >> menuInput;
	cout << "\n";
    /*************************************************************/
    
	/************************VARIABLES and ARRAYS*****************/
	//test values
	char testTrans = 3;
	char testkey[60] = {"bath"};
    char testWord[]= "Storms are coming even it.s eradicationAAaa";
	char testDeWord[] = "TTHYNS HSE JPMBUH XCFN PU L FRTKJCTAJOG";
	char testDeTrans[] = "Vwrupv duh frplqj hyhq lw v hudglfdwlrq";
	char testDeVerse[] = "noitacidare s.ti neve gnimoc era smrotS";
    
	int transposition;				//value for transposition function
	
	//Storage Arrays
	char inputWord[InputLength];	//array to store input for encoding
	char originalIn[InputLength];	//copy of input
	char direction[10];				//array to store reverse of input word
	char vigenere[InputLength];		//array to store vigenere text
	char keyWord[128];				//array to store key for vigenere
    
	//Required items for loop which will store words into an array
	char theWords[MaxNumberOfWords][Size];		// Declare array for dictionary
	int wordRow = 0;							// Will increase in loop
    char input[Size] = " ";
    int keyRow = 0;
    int theKeys[MaxNumberOfWords][Size];
    /****************************************************************/
    
	ifstream inStream;
	inStream.open("TheSecretAgencyByJosephConrad.txt");
	//assert( ! inStream.fail() );
    
	//Loop to store words from dictionary into theWords
	while ( wordRow < MaxNumberOfWords && inStream >> theWords[wordRow] )
	{
		/*if(wordRow%20==0)
         {
         cout<<wordRow<<theWords[wordRow]<<endl;
         }*/
		wordRow++;
        
		if(wordRow>MaxNumberOfWords)
		{
			cout<<"END"<<endl;
			break;
		}
	}
    
    /******If Menu input is 1******************************/
	if(menuInput == 1)
	{
		cout << "Your choice: 1" << "\n" << endl;
        
		cin.ignore(100, '\n');										//to make sure cin.getline allows input
		cout << "Enter the text to be encoded: ";
		cin.getline (inputWord, InputLength);						//word to be encoded
		cout << endl;
        
		for(int i = 0; i < strlen(inputWord); i++)
		{
			originalIn[i] = inputWord[i];
		}
        
                                                                    //to make sure cin.getline allows input
		cout << "Enter a direction (forwards or reverse) "; 		//forwards or reverse in lower case
		cin >> direction;
		if(strcmp(direction, "reverse") == 0)
		{
			reverse(inputWord);
		}
		
		cout << "Enter transposition value (0..25): ";				//this value is added to each individual letter in the array until it reaches "z" when it loops back to a
		cin >> transposition;
		transpose(inputWord, transposition);
		cout << endl;
        
        cout << "Enter keyword for vigenere encryption: ";
        cin >> keyWord;
		cout << "\n";
        cout << "Keyword is: " << keyWord << "\n";
		cout << endl;

		cout << "Keyword, plainText and ciphertext are:" << "\n";
		cout << keyWord << keyWord << keyWord << keyWord << keyWord << keyWord << keyWord << keyWord << keyWord << keyWord << keyWord << keyWord << keyWord << keyWord << keyWord << keyWord << keyWord << "\n";                                                //Please keyword above following lines
		cout << originalIn << "\n";
		vigenereCypher(inputWord, keyWord);
        
		system("pause");
		return(0);
	}
	/*****************************************************/
    
	/******If Menu input is 2******************************/
	else if(menuInput == 2)
	{
		cout << "Your choice: 2" << "\n" << endl;
        
		cin.ignore(100, '\n');										//to make sure cin.getline allows input
		cout << "Enter the cipherText to be decoded: ";
		cin.getline (vigenere, InputLength);
		cout << endl;
        
		cout << "Enter the Vigenere keywords to be tried: ";
        cin.getline(keyWord, InputLength);
		cout << "\n" << endl;
        
		cout << "cyphertext is: " << vigenere << "\n";
        cout << "string of possible keywords is: " << keyWord << "\n";
        
        int trans = 0;
        int hits = 1;
        bool reverse = true;
        
        for (int i = 0; i < strlen(vigenere) ; i++) {
            detranspose(vigenere, trans);
            deverse(vigenere);
            if(reverse == true)
            {
                vigenereDecrypt(vigenere, keyWord);
            }
            
            
            if(lookUpWord(theWords, vigenere) == true)
            {
                cout << "New best: " << "Dictionary hits: " << hits << ", " << "keyword: " << "" << ", " <<  "transposition: "<< trans << ", " <<  "direction: " << reverse << "\n";
            }
            
            trans++;
            hits++;
            reverse = false;
        }
	}
	/*****************************************************/
	
	/******If Menu input is 3******************************/
	else if(menuInput == 3)
	{
		cout << "In Progress" << "\n";
	}
	/*****************************************************/
	
	/******If Menu input is 4******************************/
	else if(menuInput == 4)
	{
		return(0);
	}
	/*****************************************************/
	
	/******If Menu input is not valid******************************/
	else if( (menuInput != 1) || (menuInput != 2) || (menuInput != 3) || (menuInput != 4) )
	{
        cout << "You did not enter a valid number" << "\n"
        << "Goodbye";
	}
	/*****************************************************/
    
	return 0;
}
