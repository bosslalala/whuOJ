/* woj 332 */
/* c++ */
/* lsy */
#include<cstdio>
#include<cctype>
#include<cstring>
using namespace std;
int n,m;
char a[102][130],b[102][130],s[3],ap[20000],bp[20000];
const char ans[][30]={"Accepted","Wrong Answer","Presentation Error"};
int p;
bool ac(){
	if(n!=m)return false;
	for(int i=0;i<=n;++i)
	for(int j=0;a[i][j]||b[i][j];++j)
	if(a[i][j]!=b[i][j])return false;
	return true;
}
bool pe(){
	int cnta=0,cntb=0;
	for(int i=1;i<=n;++i)
	for(int j=0;a[i][j];++j)if(isdigit(a[i][j]))ap[++cnta]=a[i][j];
	for(int i=1;i<=m;++i)
	for(int j=0;b[i][j];++j)if(isdigit(b[i][j]))bp[++cntb]=b[i][j];
	if(cnta!=cntb)return false;
	for(int j=1;j<=cnta;++j)if(ap[j]!=bp[j])return false;
	return true;
}
int main(){
	int t=0;
	while(scanf("%d",&n)&&n){
		gets(s);
		for(int i=1;i<=n;++i)gets(a[i]);
		scanf("%d",&m);
		gets(s);
		for(int i=1;i<=m;++i)gets(b[i]);
		if(ac())p=0;else
		if(pe())p=2;else
		p=1;
		printf("Run #%d: %s\n",++t,ans[p]);
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
	}
	return 0;
}