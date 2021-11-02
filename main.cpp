#include <iostream>
#include <stdio.h>   
#include <stdlib.h>  
#include <vector>

using namespace std;


int getNum(string q){
    int i = 0;
    cout << q;
    cin >> i;

    return i;
}

string getString(string q){
    string s = "";
    cout << q;

    cin >> s;

    return s;
}


vector<string> split (string s, string delimiter) {
    size_t start = 0;
    size_t end, delim_len = delimiter.length();
    string token;
    vector<string> words;

    while ((end = s.find (delimiter, start)) != string::npos) {
        token = s.substr (start, end - start);
        start = end + delim_len;
        words.push_back (token);
    }

    words.push_back(s.substr(start));
    return words;
}

string parseString(string sentence){

    vector<string> words = split(sentence, " ");

    string newcow;
    string oldcow;
    string relation;
    string animalyear;

    for (int i = 0; i < words.size(); i++){
        string word = words[i];
        cout << "Word: " << word <<endl;

        if (i == 0){
            newcow = word;
        } else if ( i == words.size() - 1){
            oldcow = word;
        } else if (i == 3){
            relation = word;
        } else if (i == 4){
            animalyear = word;
        }
    }

    cout << "Newcow: " << newcow << endl;
    cout << "Old cow: " << oldcow << endl;
    cout << "Relation: " << relation << endl;
    cout << "Animalyear: " << animalyear << endl;

    string order[12] = {"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};

    // find current index
    int curryearindex ;
    for (int i = 0; i < 12; i++){
        string year = order[i];

        if (animalyear == year){
            curryearindex = i;
            break;
        }
    }



    if (relation == "next"){
        cout << "Do next relation" << endl;
    }else{
        cout << "Do previous relation" << endl;
        cout << curryearindex << endl;
    }

    return "";
}


int main() {
    // int total_tests = getNum("Enter total tests: ");
    string line = "Mildred born in previous Dragon year from Bessie";
    string parsed_setence = parseString(line);

    
    
    return 0;
}