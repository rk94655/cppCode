#include<bits/stdc++.h>

using namespace std;

int countSubsetWithGivenDifference(int arr[],  int sum, int n)
{
	int dp[n+1][sum+1];
	for(int j=0;j<=sum;j++)
		dp[0][j]=0;
	for(int i=0;i<=n;i++)
		dp[i][0]=1;

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=sum;j++)
		{
			if(arr[i-1]<=sum)
			{
				dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
			}
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	return dp[n][sum];

}


int main()
{

	int arr[] = {1,1,2,3};
	int diff=1;
	int n=sizeof(arr)/sizeof(int);
	int sum=0;
	for(int i=0;i<n;i++)
		sum+=arr[i];
	cout << "Count = "<<countSubsetWithGivenDifference(arr,(sum+diff)/2, n);
	return 0;
}