#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>
#include<string>

using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void importDataFromFile(string filename, vector<string> &name, vector<int> &score, vector<char> &grade){
    ifstream file(filename);
    string textline;
    char n[100];
    int s1 , s2, s3;
    while(getline(file, textline)){
        sscanf(textline.c_str(), "%[^:]: %d %d %d " , n , &s1, &s2, &s3);
        name.push_back(n);
        score.push_back(s1 +s2 + s3);
        grade.push_back(score2grade(s1 + s2 + s3));
    }
}

void getCommand(string &command, string &key){
    cout <<  "Please input your command:" ;
    cin >> command;
    cin.ignore();
    if(toUpperStr(command) == "EXIT") return;
    else getline(cin, key);
}

void searchName(vector<string> &name, vector<int> &score, vector<char> &grade, string key){
        cout << "---------------------------------" << endl;
        bool isFound = false ;
        key = toUpperStr(key) ; 
        for(unsigned int i= 0 ; i< name.size(); i++){
                    
            if(key == toUpperStr(name[i])){
       
                cout << name[i] <<"'s score = " << score[i] << endl;
                cout << name[i] <<"'s grade = " << grade[i] << endl;
                isFound = 1 ;
            }
            else if(isFound == 0 && i == name.size() -1){
                cout << "Cannot found." << endl;
            }
        }
        cout << "---------------------------------" << endl;

}

void searchGrade(vector<string> &names, vector<int> &scores, vector<char> &grades, string key){
    cout << "---------------------------------" << endl;
    key = toUpperStr(key) ; 
    for(unsigned int i = 0; i < grades.size(); i++){
        if(key == toUpperStr(grades[i].c_str())){
            cout << names[i] << " " << scores[i] << endl;
        }
    }
    cout << "---------------------------------" << endl;
}


int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);
    
    do{
        string command, key;
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
    
    return 0;
}
