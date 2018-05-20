#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n,initial,dis,beg,end,mid;
	//Input-inital floor
	cin>>initial;
	//Input no. of floor requests
	cin>>n;
	//Array to contain the floor requests + initial floor
	int A[n+10];
	// Input-floor requests
	for(int i=0;i<n;i++)
		cin>>A[i];
	A[n]=initial;
	//sorting the sequence in ascending order
	sort(A,A+n+1);
	//binary search for the initial floor's position
	beg=0;
	end=n;
	while(beg<=end)
	{
		mid=(beg+end)/2;
		if(A[mid]==initial)
		break;
		else if(A[mid]>initial)
		end=mid-1;
		else
		beg=mid+1;
	}
	//displaying the scheduled sequence, assuming the lift to be moving up initially
	for(int i=mid;i<=n;i++)
		cout<<A[i]<<' ';
	for(int i=mid-1;i>=0;i--)
		cout<<A[i]<<' ';
	//Total distance calculated and displayed
	dis=(A[n]-initial)+(A[n]-A[0]);
	cout<<"\nTotal Distance: "<<dis;
	return 0;
}