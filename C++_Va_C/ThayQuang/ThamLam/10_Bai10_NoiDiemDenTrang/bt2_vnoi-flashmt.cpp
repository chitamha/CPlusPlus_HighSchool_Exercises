#include<iostream>
#include<algorithm>
#define fr(a,b,c) for (a=b;a<=c;a++)
using namespace std;
struct rec
{
 int x,y;
};
int n,re,i;
rec a[200002];

bool cmp(rec i,rec j)
{
 return (i.x<j.x);
}

int main()
{
 freopen("BWPOINTS.INP", "r", stdin);
 freopen("BWPOINTS.OUT", "w", stdout);
 cin >> n;
 fr(i,1,n*2)
 {
  scanf("%d",&a[i].x);
  if (i>n) a[i].y=1;
 }
 sort(a+1,a+n*2+1,cmp);
 i=1;
 while (i<n*2)
 {
  if (a[i].y!=a[i+1].y)
  {
   re++; i++;
  }
  i++;
 }
 cout << re << endl;
}
