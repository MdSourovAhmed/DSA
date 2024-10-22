#include<iostream>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;

const char A[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
const char B[]="A   3  HIL JM O   2TUVWXY51SE Z  8 ";
map<char,char>m;
void Map()
{
	for(int i=0;A[i];i++)
	{
		m[A[i]]=B[i];
	}
}

int main()
{
	Map();

	string s;
	while(cin>>s)
	{
		string st="",rev;
		rev=s;
		reverse(rev.begin(),rev.end());
		for(char &c:rev)st+=m[c];

		
		if(st==s && rev==s)
             cout<<s<<" -- is a mirrored palindrome.";
        else if(st==s)
            cout<<s<<" -- is a mirrored string.";
        else if(rev==s)
            cout<<s<<" -- is a regular palindrome.";
        else
            cout<<s<<" -- is not a palindrome.";	
		cout<<endl<<endl;		
	}
}