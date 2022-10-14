/*
Author: Frida Mesa
Course: CSCI-135
Instructor: Micheal Zamansky
Assignment: Lab 6 D

I wrote a program that uses the above functions to demonstrate encryption and decryption for both ciphers.

*/

#include<iostream>
#include<string>
#include <tests.cpp>
using namespace std;
string encryptCaesar(string plainText, int rShift);
string encryptVigenere(string plainText, string keyword);
string decryptCaesar(string cipherText, int rShift);
string decryptVigenere(string ciphertext, string keyword);
string encryptCaesar(string plainText, int rShift)

{
char ch;
int i;
for (i = 0; plainText[i] != '\0'; ++i)

{
ch = plainText[i];

if (ch >= 'a' && ch <= 'z')
{
ch = ch + rShift;
if (ch > 'z')
{
ch = ch - 'z' + 'a' - 1;
}
plainText[i] = ch;
}
else if (ch >= 'A' && ch <= 'Z')
{
ch = ch + rShift;
if (ch > 'Z')
{
ch = ch - 'Z' + 'A' - 1;
}
plainText[i] = ch;
}

  }
return plainText;
  }
string decryptCaesar(string cipherText, int rShift)

{
int i;
char ch;
for (i = 0; cipherText[i] != '\0'; ++i)
{

ch = cipherText[i];
if (ch >= 'a' && ch <= 'z')

{
ch = ch - rShift;
if (ch < 'a')
{
ch = ch + 'z' - 'a' + 1;
}
cipherText[i] = ch;
}
else if (ch >= 'A' && ch <= 'Z')

{
ch = ch - rShift;
if (ch < 'A')

{
ch = ch + 'Z' - 'A' + 1;
}
cipherText[i] = ch;
}
}
return cipherText;

  }
string encryptVigenere(string plainText, string keyword)

{
int i, j;
string cipher = "";
char p;
for (int k = 0; k < keyword.length(); k++)
{

if (islower(keyword[k]))

{
keyword[k] = keyword[k] - 32;
}
}
int len = plainText.length() / keyword.length();
for (i = 0; i < len; i++)

{

keyword += keyword;

}

j = 0;
for (i = 0; i<plainText.length(); i++)

{

if ((plainText[i] >= 'a' && plainText[i] <= 'z') ||
(plainText[i] >= 'A' && plainText[i] <= 'Z'))

{
if (plainText[i] >= 'a' && plainText[i] <= 'z')
p=(plainText[i] - 'a' + (keyword[j] - 'A')) % 26 + 'a';
else
p=(plainText[i] - 'A' + (keyword[j] - 'A')) % 26 + 'A';
cipher = cipher + p;
j++;

}

else
cipher = cipher + plainText[i];
  }
return cipher;

  }

string decryptVigenere(string ciphertext, string keyword)

{
int i, j;
string plain = "";
char p;
for (int k = 0; k < keyword.length(); k++)

{
if (islower(keyword[k]))
{
keyword[k] = keyword[k] - 32;
}
}

int len = ciphertext.length() / keyword.length();
for (i = 0; i < len; i++)
{
keyword += keyword;
}
j = 0;
for (i = 0; i<ciphertext.length(); i++)
{
if ((ciphertext[i] >= 'a' && ciphertext[i] <= 'z') ||
(ciphertext[i] >= 'A' && ciphertext[i] <= 'Z'))
{
if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z')
{
p=(ciphertext[i] - 'a' - (keyword[j] - 'A')) % 26 + 'a';
}
else
{
p = (ciphertext[i] - 'A' - (keyword[j] - 'A')) % 26 + 'A';
}
plain = plain + p;
j++;
}
else
plain = plain + ciphertext[i];
}
return plain;
}

int main()
{
string plainText, keyword;
int rShift;

cout << "Enter Plain Text: ";
getline(cin, plainText);
cout << "\n= Caesar =\n";
cout << "\nEnter Shift\t: ";

cin >> rShift;
string cipher = encryptCaesar(plainText, rShift);

cout << "\nCiphertext\t: " << cipher << "\n";
plainText = decryptCaesar(cipher, rShift);
cout << "\nDecrypted\t: " << plainText;
cout << endl;
cout << "\n= Vigenere =\n";
cout << "\nEnter Keyword\t: ";

cin >> keyword;
string cipher_text = encryptVigenere(plainText, keyword);

cout << "\nCiphertext\t: " << cipher_text << "\n";
cout << "\nDecrypted\t: " << decryptVigenere(cipher_text, keyword) << endl;

return 0;

}
