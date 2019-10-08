#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;
int check(char s,char *c,int l)
{
	for(int i=0;i<l;i++)
	{
		if(s==c[i])return 0;
	}
	return 1;
}
int main(int argc,char *argv[]){
string inst;
ifstream fin;
fin.open(argv[1],ios::in);
int l=strlen(argv[2]);
char *c=argv[2];
int ok;
cout << "-------------------------Input file " << argv[1] << "-------------------------"<< endl;
while(fin >> inst){
	cout << inst << " ";
        if(inst=="reverse"){
        string str1;
        fin >> str1;
	cout << str1 << endl;
        reverse(str1.begin(),str1.end());
        cout << str1 << endl;
        }
        else if(inst=="split"){
        	ok=0;
        string str1;
	fin >> str1;
	cout << str1 << endl;
		for(int i=0;i<str1.size();i++)
		{
		if(check(str1[i],c,l))
			{
				cout << str1[i];
				ok=1;
			}
		else
		    {
			while(!check(str1[i],c,l))
				i++;
			if(ok)
			cout << " ";
			i--;
		    }
        	}
	cout << endl;
	}
}
cout << "-------------------------End of input file " << argv[1] << "-------------------------"<< endl;
cout << "******************************User input*********************************"<< endl;

while(cin >> inst){
	if(inst=="reverse"){
	string str1;
	cin >> str1;
	reverse(str1.begin(),str1.end());
	cout << str1 << endl;
	}
	else if(inst=="split"){
	 string str1;
	 ok=0;
         cin >> str1;
                for(int i=0;i<str1.size();i++)
                {
                if(check(str1[i],c,l))
                {
                        cout << str1[i];
                        ok=1;
                }
                else
                    {
                        while(!check(str1[i],c,l))
                                i++;
                        if(ok)
                        cout << " ";
                        i--;
                    }
                }
        cout << endl;
	}
	else if(inst=="exit")
	break;
}

return 0;
}
