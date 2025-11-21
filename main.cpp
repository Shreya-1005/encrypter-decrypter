#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;


string encryption(string password, int shift, int digit = 0){
    string encryptData = "";
    if(digit == 0){ 
        digit =shift;
    }
    for(auto c:password){ 
        if('A' <= c && 'Z' >= c){ 
            encryptData += (65 + (c-65+shift)%26 ); 
        }
        else if('a' <= c && 'z' >= c){
            encryptData += (97 + (c-97+shift)%26 ); 
        }
        else if('0'<=c && c<='9'){ //digits
            encryptData += ('0' + (c-'0'+digit)%10 ); 
        }else{ //spl characters
            encryptData += c;
        }
    }
    return encryptData;
}

string decryption(string password, int shift){
    return encryption(password, 26-shift, 10-shift);

}

//also O(n)
string passwordGenerator(int size, int num=0, int symbol=0){
    string resultantPassword ="";
    string digits = "1234567890";
    string alphabets = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
    string symbols = "!@#$%^&*-_=;:<>,./~";
    srand(time(0));

    while (size){
        resultantPassword +=alphabets[rand() % alphabets.size()];
        size--;
        if (num && size){
            resultantPassword +=digits[rand() % 10];
            size--;
            num--;
        }
        if (symbol &&size){
            resultantPassword +=symbols[rand() % symbols.size()];
            size--;
            symbol--;
        }
    }
    return resultantPassword;
}

int main(){
    int choice;
    string pass;
    int shift = 7;
    while(true){
        cout<<"\n ==== ENCRYPTER-DECRYPTER ==== \n";
        cout<<"1. Encrypt your password \n";
        cout<<"2. Decrypt your password \n";
        cout<<"3. Generate a passowrd \n";
        cout<<"4. Exit \n";
        cout<<"Enter your choice: ";
        cin>>choice;
        if(choice ==1){
            string pass;
            cout<<"Enter your password ";
            cin>>pass;
            string encryptedPass = encryption(pass, shift);
            cout<<"Your encryted password is "<<encryptedPass<<endl;
        }
        else if(choice ==2){
            string encrytedPass;
            cout<<"Enter your Encrypted password ";
            cin>>encrytedPass;
            string decryptedPass = decryption(encrytedPass, shift);
            cout<<"Your Decrypted password is "<<decryptedPass<<endl;
        }
        else if(choice ==3){
            int size, dig, symb;
            cout<<"Enter the total no. of characters you want in the password: ";
            cin>>size;
            cout<<"Enter the total no. of digits you want in the password: (Default is 0) ";
            cin>>dig;
            cout<<"Enter the total no. of symbols you want in the password: (Default is 0) ";
            cin>>symb;
            string generatedPass = passwordGenerator(size, dig, symb);
            cout<<"The generated password is: "<<generatedPass<<endl;


        }
        else if (choice ==4){
            cout<<" ==== Thank you for using ENCRYPTER-DECRYPTER ==== ";
            break;
        }
        else {
            cout<<"Invalid input of choice! Try Again \n";
        }

    }
    
    return 0;
}