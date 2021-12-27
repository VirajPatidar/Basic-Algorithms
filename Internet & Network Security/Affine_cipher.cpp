#include <bits/stdc++.h>
using namespace std;

string encryptMessage(string plain_text, int a, int b)
{

    string cipher = "";

    for (int i = 0; i < plain_text.length(); i++)
    {
        if (plain_text[i] != ' ')
        {
            if (isupper(plain_text[i]))
                cipher = cipher + (char)((((a * (plain_text[i] - 'A')) + b) % 26) + 'A');
            else
                cipher = cipher + (char)((((a * (plain_text[i] - 'a')) + b) % 26) + 'a');
        }
        else
            cipher += plain_text[i];
    }
    return cipher;
}

string decryptCipher(string cipher, int a, int b)
{
    string msg = "";
    int a_inv = 0;
    int flag = 0;

    for (int i = 0; i < 26; i++)
    {
        flag = (a * i) % 26;
        if (flag == 1)
            a_inv = i;
    }

    for (int i = 0; i < cipher.length(); i++)
    {
        if (cipher[i] != ' ')
        {
            if (isupper(cipher[i]))
                msg = msg + (char)(((a_inv * ((cipher[i] + 'A' - b)) % 26)) + 'A');
            else
                msg = msg + (char)(((a_inv * ((cipher[i] + 'a' - b)) % 26)) + 'a');
        }
        else
            msg += cipher[i];
    }
    return msg;
}

int main(void)
{
    int choice, a, b;
    string msg;
    string cipherText, plainText;

    choice = 0;

    while (choice != 3)
    {
        cout << "\nEnter your choice \n 1: Encrytion \n 2: Decryption\n 3: Exit\n";
        cin >> choice;
        switch (choice)
        {
            case 1:
                cout << "\nEnter the Message\n";
                cin.ignore();
                getline(cin, msg);
                cout << "\nEnter the keys\n";
                cin >> a >> b;
                cipherText = encryptMessage(msg, a, b);
                cout << cipherText;
                break;
            case 2:
                cout << "\nEnter Cipher text\n";
                cin.ignore();
                getline(cin, msg);
                cout << "\nEnter keys\n";
                cin >> a >> b;
                plainText = decryptCipher(msg, a, b);
                cout << plainText;
                break;
        }
    }
    return 0;
}