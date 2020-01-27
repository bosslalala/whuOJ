/* woj 333 */
/* c++ */
/* lsy */
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
 
string s[300];
int vis[300];
string tmps;
int length;
int num;
 
bool cmp ( string a, string b )
{
	return a.length() > b.length();
}
 
bool judge ( string str )
{
	for ( int i = 0; i < ( num + 1 ) / 2; i++ )
	{
		vis[i] = 1;
		bool found = false;
		for ( int j = num - 1; j > i; j-- )
		{
			if ( vis[j] == 0 && s[i] + s[j] == str )
			{
				vis[j] = 1;
				found = true;
				break;
			}
		}
		if ( !found )
			return false;
	}
	return true;
}
 
void solve ( )
{
	num = 0;
	char str[300];
	while ( gets ( str ) )
		if ( str[0] )
			s[num++] = str;
		else
			break;
	sort ( s, s + num, cmp );
	length = s[0].length() + s[num-1].length();
	int len1 = s[num-1].length();
	bool found = false;
	for ( int i = num - 1; i >= 0 && s[i].length () == len1; i-- )
	{
		tmps = s[0] + s[i];
		memset ( vis, 0, sizeof vis );
		if ( judge ( tmps ) )
		{
			found = true;
			cout << tmps << endl;
			return ;
		}
	}
	if ( !found )
		cout << s[0] + s[num-1] << endl;
}
 
int main ( )
{
	int n;
	scanf ( "%d\n", &n );
	while ( n-- )
	{
		solve ( );
		if ( n )
			puts ( "" );
	}
	return 0;
}