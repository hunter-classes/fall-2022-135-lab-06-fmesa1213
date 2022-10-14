/*
Author: Frida Mesa
Course: CSCI-135
Instructor: Micheal Zamansky
Assignment: Lab 6 B

I wrote a program that functions implementing Caesar cipher encryption.
*/

#include <iostream>

using namespace std;
char shiftChar(char c, int rshift);

string encryptCaesar(string plaintext, int rshift);
int main()
{
string s;
int n;
cout<<"Enter plaintext:"<<endl;
getline(cin, s);
cout<<"Enter shift:"<<endl;
cin >> n;

cout<<"Ciphertext: "<<encryptCaesar(s, n)<<endl;
return 0;
}
char shiftChar(char c, int rshift) {
if(c>='a' && c <='z')
return 'a' + ((c - 'a' + rshift) % 26);
else
return 'A' + ((c - 'A' + rshift) % 26);
}

string encryptCaesar(string plaintext, int rshift) {
for(int i=0;i<plaintext.length();i++) {
char c = plaintext[i];
if((c>='a' && c <='z') || (c>='A' && c <='Z')) {
plaintext[i] = shiftChar( plaintext[i], rshift);
}
}
return plaintext;
return 0;
}
