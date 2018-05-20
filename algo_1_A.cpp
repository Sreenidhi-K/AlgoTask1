#include <iostream>
using namespace std;

void encrypt( char* st, int k, int hut)
{
	char nay[100];
	int i;
	//updating a new string with the encrypted characters
	for( i=0;st[i];i++)
	{
		char a=st[i];
		//for lower case alphabets
		if(a>='a' && a<='z')
		{	
			int sum=a+k;
			if(sum>122)
			{
				sum-=122;
				sum%=26;
				nay[i]=(char)(96+sum);
			}
			else
			nay[i]=(char)(sum);
			
		}
		//for upper case alphabets
		else if(a>='A' && a<='Z')
		{
			int sum=a+k;
			if(sum>90)
			{
				sum-=90;
				sum%=26;
				nay[i]=(char)(64+sum);
			}
			else
			{
			
			nay[i]=(char)(sum);
			}
		}
		//for other characters
		else
		nay[i]=(char)a;
				
	}
	nay[i]='\0';
	cout<<"ciphertext#"<<hut<<":"<<nay<<'\n';
	
}

void decrypt(char* st, int k, int hut)
{
	int i;
	char nay[100];
	//updating a new string with the decrypted characters
	for( i=0;st[i];i++)
	{
		char a=st[i];
		int diff=a-k;
		//for lower case alphabets
		if(a>='A' && a<='Z')
		{
		if(diff<65)
		{
			diff=65-diff;
			diff%=26;
			nay[i]=(char)(91-diff);
		}
		else
		nay[i]=(char)diff;
		}
		//for upper case alphabets
		else if(a>='a' && a<='z')
		{
		if(diff<97)
		{
			diff=97-diff;
			diff%=26;
			nay[i]=(char)(123-diff);
		}
		else
		nay[i]=(char)diff;	
		}
		//for other characters
		else
		nay[i]=(char)a;
		
		
	}
	nay[i]='\0';
	cout<<"plaintext#"<<hut<<":"<<nay<<'\n';
	
}

int main()
{
	char st[100],a[100];
	int n,k;
	cin>>n>>k;
	cin.ignore();
	for(int i=0;i<n;i++)
	{
	cin.getline(st,sizeof(st));
	encrypt(st,k,i+1);
	}
	for(int i=0;i<n;i++)
	{
	cin.getline(st,sizeof(st));
	decrypt(st,k,i+1);
	}

	return 0;
}