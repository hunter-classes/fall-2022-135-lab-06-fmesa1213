/*
Author: Frida Mesa
Course: CSCI-135
Instructor: Micheal Zamansky
Assignment: Lab 6 A

I wrote a program that  that asks the user to input a line of text (which may possibly include spaces). 
The program should report all characters from the input line together with their ASCII codes.

*/

#include <string>
#include <sstream>
#include <iostream>
using namespace std;
void convertToASCII(string letter)
{
for (int i = 0; i < letter.length(); i++)
{
char x = letter.at(i);
cout << letter.at(i) <<" "<< int(x) << endl;
}
}
int main()
{
string plainText;
cout << "Enter text to convert to ASCII: ";
getline(cin, plainText);
convertToASCII(plainText);
return 0;
}
