#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using std::string;
string getTxtData();
string makeList(string inputString);
char* StringToChararray(string input);
bool searchInArrayIfFound(char* input, char searchFor);
int harderThanXY(char input, string inputString, char* usedChar);
int harderThanXY(char input, string inputString);
void ausgeben(string stringList, int length, string trash);

int main(){
    string trash = getTxtData();
    char* data = new char[trash.length()+1];
    data = StringToChararray(trash);
    //std::cout << data;
    string stringList;
    stringList = makeList(trash);
    //std::cout << stringList << std::endl;
    ausgeben(stringList,stringList.length(),trash);
    return 0;
}

void ausgeben(string stringList, int length, string trash){
    int list[stringList.length()];
    char* charList = StringToChararray(stringList);
    for(int i = 0; i<stringList.length(); i++){
        list[i]= harderThanXY(charList[i],trash);
        //std::cout<<harderThanXY(charList[i],trash);
    }
    for(int i = 0; i<length;i++){
        //std::cout<<list[i];
    }
}

string makeList(string inputString){
    //std::cout << "makeList\n";
    int length = inputString.length();
    char* inputArray = StringToChararray(inputString);
    string list;
    for(int i = 0; i<length;i++){
        if(inputArray[i] != '1' && inputArray[i] != '2' && inputArray[i] != '3' && inputArray[i] != '4' && inputArray[i] != '5' && inputArray[i] != '6' && inputArray[i] != '7' && inputArray[i] != '8' && inputArray[i] != '9' && inputArray[i] != '0' && inputArray[i] != '<'){
            char* charList = new char[list.length()+10];
            charList = StringToChararray(list);
            bool found = false;
            for(int j=0; j<list.length()+1; j++){
                if(found == false){
                    if(charList[j]==inputArray[i]){
                        found = true;
                    }
                }
            }
            if(found == false){list = list + inputArray[i];}
            delete charList;
            found = false;
        }
    }
    return list;
}

int harderThanXY(char input, string inputString){
    char* inputArray = new char[inputString.length()+1];
    char* usedChar = new char[inputString.length()+1];
    int found = 0;
    bool active = false;
    inputArray = StringToChararray(inputString);
    for(int i = 0; i<inputString.length(); i++){
        if(inputArray[i] != 1 && inputArray[i] != 2 && inputArray[i] != 3 && inputArray[i] != 4 && inputArray[i] != 5 && inputArray[i] != 6 && inputArray[i] != 7 && inputArray[i] != 8 && inputArray[i] != 9 && inputArray[i] != 0 && inputArray[i] != '<'){
            if(inputArray[i+1] == '<'){
                if(active == true){
                    if(searchInArrayIfFound(usedChar,inputArray[i]) != true){
                            found++;
                            found = found + harderThanXY(inputArray[i],inputString,usedChar);
                        }
                    }
                }else{
                    if(inputArray[i]==input){active = true;}}
            }else{
                    active = false;
            }
        }
    std::cout<<found<<std::endl; 
    return found;
}

int harderThanXY(char input, string inputString,char* usedChar){
    char* inputArray = new char[inputString.length()];
    int found = 0;
    bool active = false;
    inputArray = StringToChararray(inputString);
    for(int i = 0; i<inputString.length()+1; i++){
        if(inputArray[i] != 1 && inputArray[i] != 2 && inputArray[i] != 3 && inputArray[i] != 4 && inputArray[i] != 5 && inputArray[i] != 6 && inputArray[i] != 7 && inputArray[i] != 8 && inputArray[i] != 9 && inputArray[i] != 0 && inputArray[i] != '<'){
            if(inputArray[i+1] == '<'){
                if(active == true){
                    if(searchInArrayIfFound(usedChar,inputArray[i]) != true){
                            found++;
                            found = found + harderThanXY(inputArray[i],inputString,usedChar);
                        }
                    }
                }else{
                    if(inputArray[i]==input){active = true;}}
            }else{
                active = false;
            }
        
    }
    return found;
}

bool searchInArrayIfFound(char* input, char searchFor){
    bool found = false;
    int length = sizeof(input)/sizeof(input[0]);;
    for(int i = 0; i<length; i++){
        if(input[i] == searchFor){
            return true;
        }
    }
    return false;
}

char* StringToChararray(string input){
    const int length = input.length();
    char* charArray = new char[length+1];
    strcpy(charArray, input.c_str());
    return charArray;
}

string getTxtData(){
    std::cout << "Please enter the path for the txt file:";
    string TxtFilePath;
    string TxtData;
    string newData;
    std::cin >> TxtFilePath;
    std::ifstream inFile;
    inFile.open(TxtFilePath);
    if (!inFile){
        std::cerr << "Unable to open file";
        exit(1);
    }
    while (inFile >> newData){
        TxtData = TxtData + newData;
    }
    inFile.close();
    //std::cout << TxtData;
    return TxtData;
}