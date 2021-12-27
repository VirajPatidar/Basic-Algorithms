#include <bits/stdc++.h>
using namespace std;

string generateKey(string str, string key)
{
    int x = str.size();

    for (int i = 0;; i++)
    {
        if (x == i)
            i = 0;
        if (key.size() == str.size())
            break;
        key.push_back(key[i]);
    }
    return key;
}

string encryptMessage(string str, string key)
{
    string cipher_text;

    for (int i = 0; i < str.size(); i++)
    {
        if(str[i] == ' ')
            cipher_text.push_back(' ');
        else
        {
            char x = (str[i] + key[i]) % 26;
            x += 'A';
            cipher_text.push_back(x);
        }
    }
    return cipher_text;
}

string decryptCipher(string cipher_text, string key)
{
    string orig_text;

    for (int i = 0; i < cipher_text.size(); i++)
    {
        if(cipher_text[i] == ' ')
            orig_text.push_back(' ');
        else 
        {
            char x = (cipher_text[i] - key[i] + 26) % 26;
            x += 'A';
            orig_text.push_back(x);
        }
    }
    return orig_text;
}

int main(void)
{
    int choice;
    string msg, key;
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
                cout << "\nEnter the key\n";
                cin >> key;
                cipherText = encryptMessage(msg, generateKey(msg, key));
                cout << cipherText;
                break;
            case 2:
                cout << "\nEnter Cipher text\n";
                cin.ignore();
                getline(cin, msg);
                cout << "\nEnter the key\n";
                cin >> key;
                plainText = decryptCipher(msg, generateKey(msg, key));
                cout << plainText;
                break;
        }
    }
    return 0;
}