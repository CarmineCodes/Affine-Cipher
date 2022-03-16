/*
This program will encrypt and decrypt text strings
using the affine cipher
Carmine Attanasio
2022
*/


#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int a;
int b;


string getPlainText()
{
	string plainText = " ";
	
	//prompts user to input string to be used as plain text for cipher
	cout << "Please enter a string of text to be encrypted" << endl;
	std::getline(cin, plainText);
	
	//makes userinput all caps to work with cipher corectly
	std::transform(plainText.begin(), plainText.end(), plainText.begin(), ::toupper);

	//cout << "You entered: " << plainText << endl;

	return plainText;
}

int getKey1(int a)

//user will input data to be used as key values

{
	//prompts user to input integers for key values
	cout << "Please enter two integers for the key" << endl;

	cout << "Enter an integer for the first key value " << endl;
	cin >> a;

	/*
	checks to see if user input an integer or not
	if user did not enter an integer, they are prompted to enter a integer again
	this will continue until user enters an integer
	*/
	while (std::cin.fail())
	{
		//checks if an integer was entered, if not variable is cleared and prompt starts over
		std::cout << "Error, please enter an integer" << std::endl;
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cin >> a;
	}

	return a;
}

int getKey2(int b)
{
	//prompts user to input integer for second key value
	cout << "Please enter an integer for the second key value" << endl;
	cin >> b;

	/*
	checks to see if user input an integer or not
	if user did not enter an integer, they are prompted to enter a integer again
	this will continue until user enters an integer
	*/
	while(std::cin.fail())
	{
		//checks if an integer was entered, if not variable is cleared and prompt starts over
		std::cout << "Error, please enter an integer" << std::endl;
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cin >> b;
	}
	
	
	return b;
}

string encryptMessage(string msg, int key1,int key2)
{
	//to start there is no cipher text
	string cipher = "";
	int a = key1;
	int b = key2;
	

	for (size_t i = 0; i < msg.length(); i++)
	{
		//prevents white space from being encrypted
		if (msg[i] != ' ')
			/*
			affine cipher uses slope formula
			y=mx+b mod 26
			x is plain text
			ascii alphabet 65-90=english alphabet
			*/

			cipher = cipher + (char)((((a * (msg[i] - 'A')) + b) % 26) + 'A');
		else
			//apends space character
			cipher += msg[i];
	}


	return cipher;
}

string decryptCipher(string cipher,int key1, int key2)
{
	string msg =" ";
	
	int a_inv = 0;
	int flag = 0;
	int a = key1;
	int b = key2;
	
	//finds the multiplicative inverse of a
	for (int i = 0; i < 26; i++)
	{
		flag = (a * i) % 26;
		
		//checks if (a*i)%26==1
		//i will be mulp inverse of a

		if (flag == 1)
		{
			a_inv = i;
		}
	}

	for (size_t i = 0; i < cipher.length(); i++)
	{
		if (cipher[i] != ' ')
			/*
			applies decryption formula
			a^-1 (x-b) mod 26
			to bring in range of ascii alpha
			*/

			msg=msg + 
			(char)(((a_inv * ((cipher[i] + 'A' - b)) % 26)) + 'A');		else

			//amends space character
			msg += cipher[i];
	}



	return msg;
}

//driver
int main()
{
	
	string msg = " ";

	//calls getPlainText function to get user input string
	msg = getPlainText();


	//calls key values from getKey functions
	int key1 = getKey1(a);
	int key2 = getKey2(b);

	//outputs user entered key values
	cout << "You entered " << key1 << " as the first key value and " << key2 << " as the second key value" << endl;
	
	//calls encryption function
	string cipherText = encryptMessage(msg, key1,key2);
	cout << "Encrypted Message is : " << cipherText << endl;

	//calls decryption function
	cout << "Decrypted Message is: " << decryptCipher(cipherText,key1,key2);

	return 0;
}