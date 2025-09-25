#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
unordered_map<char,string> mmm;
int main()
{
    int n=0;
    string line;
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++){
        getline(cin,line);
        size_t pos = line.find('=');
        if(pos!=string::npos){
            char var='\0';
            for(size_t i=0;i<line.length();i++){
                if(line[i]>='A'&&line[i]<='Z'){
                    var=line[i];
                    break;
                }
            }
            if(var!='\0'){
                string value = line.substr(pos+1);
                mmm[var]=value;
            }
        }
    }
    while(getline(cin,line)){
        size_t i=0;
        while(i<line.length()){
            if(line[i]=='$'){
                if(i + 1 < line.length()){
                    if(line[i+1]=='$')line.erase(i,1);
                    else if(line[i+1]<='Z'&&line[i+1]>='A'){
                        string replacement = mmm[line[i+1]];
                        line.replace(i,2,replacement);
                        i+=replacement.length();
                        continue;
                    }
                }
            }
            i++;
        }
        cout<<line<<'\n';
    }
    return 0;
}