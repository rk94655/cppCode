
#include<iostream>
<<<<<<< HEAD
=======
#include<vector>
#include<algorithm>
#include<stack>
>>>>>>> c0efdc7a2927456c7c248ee165b6971d1135d8f8
using namespace std;
  

<<<<<<< HEAD
void print(int *x){
  cout << *x;

}
int main(void)
{ 
  const int* a;
  int b = 15;
  a=&b;
  int*temp = const_cast<int*>(a);
  print(temp);
=======
bool compare(pair<int,int> a, pair<int,int> b)
{
	return a.first>b.first;
}
int main()
{
	vector<pair<int,int>> a;
	for(int i=0;i<10;i++)
	{
		a.push_back(make_pair(10-i,i));
	}
	sort(a.begin(),a.end(),compare);
	cout << "Printing \n";
	for(int i=0;i<10;i++)
		cout << a[i].first <<" , " <<a[i].second << "\n";
	return 0;
>>>>>>> c0efdc7a2927456c7c248ee165b6971d1135d8f8

  return 0;
}