/* woj 372 */
/* c++ */
/* lsy */
#include <iostream>
using namespace std;
const int MAX = 100100;
int data[MAX];
int ans[MAX];
int data1[MAX];
void merge(int lo,int m, int hi) ;
void divid(int lo,int hi) {
    if (hi>lo) {
        int m=(hi+lo)/2;
        divid(lo,m);
        divid(m+1,hi);
        merge(lo,m,hi);
    }
    else data1[hi] = data[hi];
}

void merge(int lo,int m, int hi) {
    int i=lo,j=m+1,k=lo;
    for (;i<=m&&j<=hi;k++) {
        if(data1[i]<data1[j]) ans[k]=data1[i++];
        else ans[k] = data1[j++];
    }
    if(i<=m) 
      for(;i<=m;i++,k++) ans[k] = data1[i];
    if(j<=hi)
       for(;j<=hi;j++,k++) ans[k] =data1[j];
    for(int i=lo;i<=hi;i++) data1[i] = ans[i];
}


int main() {
    int t;  int integer;
    int n;  
    while(cin>>n&&cin>>integer) {
        if(!n&&!integer) break;
        for (int i=1;i<=n;i++) {
            cin>>data[i];
        }
        divid(1,n);
        for(int i=1;i<=n;i+=integer) {
        cout<<data1[i];
        if(i+integer<=n) cout<<" ";}
        cout<<endl;
    }
}