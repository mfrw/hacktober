#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool check(char c)
{
	
	if(c>='a'&&c<='z')
	{
	    return true;
	}
	
}

bool isogram(string S)
{
	int n = S.length();
	if(n==1) return true;
	for(int i= 0;i<n;i++)
	{
		S[i] = tolower(S[i]);

	}
	sort(S.begin(),S.end());
	cout << S;
	for (int i = 0; i < n; i++)
	{
		if(!check(S[i])) i++;
		if(S[i]==S[i + 1])
	    return false;
	}
	return true;
}

int main() {
	// your code goes here
	string S;
	getline(cin,S);
	cout << isogram(S) << endl;
	
	return 0;
}
