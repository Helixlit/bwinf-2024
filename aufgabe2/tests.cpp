#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using std::string;

int harderThanXY(char input, string inputString);
char* StringToChararray(string input);
int harderThanXYT(char input, string inputString, string used);

int main(){
    string input = "12345A<B<CD<B<FC<F<GA<G";
    char cont = 'A';
    int out = harderThanXY(cont,input);
    std::cout<<out;
}


int harderThanXY(char input, string inputString){
    char* inputArray = StringToChararray(inputString);
    string used;
    bool allow = false;
    bool already = false;
    int found = 0;
    for(int i = 0; i<inputString.length()+1; i++){
        if(allow == true){
            char toCount = inputArray[i];
            if(toCount != '1' && toCount != '2' && toCount != '3' && toCount != '4' && toCount != '5' && toCount != '6' && toCount != '7' && toCount != '8' && toCount != '9' && toCount != '0' && toCount != '<'){
                if(inputArray[i+1] == '<'){
                    char* usedA = StringToChararray(used);
                    for(int j = 0; j<used.length(); j++){
                        if(toCount == usedA[j]){
                            already = false;
                        }
                    }
                    if(already == false){
                        found++;
                        used = used + toCount;
                        harderThanXYT(toCount, inputString, used);
                    }
                }else{
                    allow = false;
                }
            }
        }else{if(inputArray[i]==input){
            allow = true;}
        }
        already = false;
    }
    return found;
}

int harderThanXYT(char input, string inputString, string used){
    char* inputArray = StringToChararray(inputString);
    bool allow = false;
    bool already = false;
    int found = 0;
    for(int i = 0; i<inputString.length(); i++){
        std::cout<<i;
        std::cout<<"\n";
        if(allow == true){
            char toCount = inputArray[i];
            if(toCount != '1' && toCount != '2' && toCount != '3' && toCount != '4' && toCount != '5' && toCount != '6' && toCount != '7' && toCount != '8' && toCount != '9' && toCount != '0' && toCount != '<'){
                if(inputArray[i+1] == '<'){
                    char* usedA = StringToChararray(used);
                    for(int j = 0; j<used.length(); j++){
                        if(toCount == usedA[j]){
                            already = true;
                        }
                    }
                    if(already == false){
                        found++;
                        used = used + toCount;
                        harderThanXYT(toCount, inputString, used);
                    }
                }else{
                    allow = false;
                }
            }
        }else{if(inputArray[i]==input){std::cout<<"found\n";
            allow = true;}
        }
        already = false;
    }
    return found;
}

char* StringToChararray(string input){
    const int length = input.length();
    char* charArray = new char[length+1];
    strcpy(charArray, input.c_str());
    return charArray;
}