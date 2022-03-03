
#include<bits/stdc++.h>
int main()
{
	struct GPLT{
		int g;
		int p;
		int l;
		int t;
	}num;
	string s;
	getline(cin,s);
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='g'||s[i]=='G')
			num.g++;
		else if(s[i]=='p'||s[i]=='P')
			num.p++;
		else if(s[i]=='l'||s[i]=='L')
			num.l++;
		else if(s[i]=='t'||s[i]=='T')
			num.t++;
	}
	while(true)
	{
		if(num.g!=0)
		{
			cout<<"G";num.g--;
			if(num.p!=0)
			{
				cout<<"P";num.p--;
				if(num.l!=0)
				{
					cout<<"L";num.l--;
					if(num.t!=0)
					{
						cout<<"t";num.t--;
					}
				}
			}
		}
		if(num.g==0&&num.p==0&&num.l==0&&num.t==0)
			break;
	}
	return 0;
}