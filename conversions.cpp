#include <bits/stdc++.h>
using namespace std;

int binaryToDecimal(int binNum){
    int decNum = 0;
    int base = 0;

    while(binNum > 0){
        int num = binNum % 10;
        decNum = decNum + (pow(2, base++) * num);
        binNum = binNum / 10;
    }
    return decNum;
}

int octalToDecimal(int octalNum){
    int decNum = 0;
    int base = 0;

    while(octalNum > 0){
        int num = octalNum % 10;
        decNum = decNum + (pow(8, base++) * num);
        octalNum = octalNum / 10;
    }
    return decNum;
}

int hexadecToDecimal(string hexadecNum){
    int decNum = 0;
    int base = 0;

    int len = hexadecNum.length();
    for(int i=len-1; i>=0; i--){
        if(hexadecNum[i] >= '0' && hexadecNum[i] <= '9'){
            decNum = decNum + (pow(16, base++) * (hexadecNum[i] - '0'));
        }
        else if(hexadecNum[i] >= 'A' && hexadecNum[i] <= 'F'){
            decNum = decNum + (pow(16, base++) * ((hexadecNum[i] - 'A') + 10));
        } 
    }
    return decNum;
}

int decimalToBinary(int decNum){
    int binNum = 0;
    int base = 0;

    while(decNum != 0){
        int bit = decNum & 1;
        binNum = binNum + (bit * pow(10, base++));
        decNum = decNum >> 1;
    }
    return binNum;
}

int decimalToOctal(int decNum){
    int octalNum = 0;
    int base = 0;

    while(decNum != 0){
        int digit = decNum % 8;
        octalNum = octalNum + (digit * pow(10, base++));
        decNum = decNum / 8;
    }
    return octalNum;
}

string decimalToHexadec(int decNum){
    string hexadecimal = "";
    while(decNum != 0){
        int digit = decNum % 16;
        char hexaDigit;

        if(digit < 10) hexaDigit = digit + '0';
        else hexaDigit = digit + 'A' - 10;

        hexadecimal = hexaDigit + hexadecimal;
        decNum = decNum / 16;
    }

    return hexadecimal;
}
