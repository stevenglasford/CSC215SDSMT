#include <iostream>
#include <cstring>

using namespace std;

int main ()
{
    char initialmessage[40] = "Demonstrating bitwise operators";
    char encryptedmessage[40] = "";
    char decryptedmessage[40] = "";
    unsigned i;
    unsigned char encdecmask = 173;  //try 123, 34,35 96 original 173

    for ( i = 0; i < strlen ( initialmessage ); i++ )
    {
        encryptedmessage[i] = initialmessage[i] ^ encdecmask;
    }

    encryptedmessage[i] = '\0';

    for ( i = 0; i < strlen ( encryptedmessage ); i++ )
    {
        decryptedmessage[i] = encryptedmessage[i] ^ encdecmask;
    }

    decryptedmessage[i] = '\0';
    cout << "Initial Message:   " << initialmessage << endl;
    cout << "Encrypted Message: " << encryptedmessage << endl;
    cout << "Decrypted Message: " << decryptedmessage << endl;
    return 0;
}






