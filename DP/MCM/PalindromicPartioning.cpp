#include<bits/stdc++.h>

using namespace std;

bool isPalindrome(string s, int i, int j)
{
	if(i>=j)
		return true;
	while(i<j)
	{
		if(s[i]!=s[j])
			return false;
		i++;
		j--;
	}
	return true;
}
int solve(string s, int i, int j)
{
	if(i>=j)
		return 0;
	if(isPalindrome(s,i,j))
		return 0;
	int ans = INT_MAX;
	for(int k=i;k<j;k++)
	{
		int temp = 1+solve(s,i,k)+solve(s,k+1,j);
		ans = min(ans, temp);
	}
	return ans;
}

int main()
{
	string s="nitik";
	int n = s.length();
	cout << solve(s, 0,n-1);

	return 0;
}