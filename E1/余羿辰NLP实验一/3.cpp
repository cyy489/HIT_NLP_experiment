#include<string>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef struct
{
    char dna[100];
}sz;
sz s[1000000];
int chf(unsigned char a,unsigned char b)
{
    if(a>=0xb0&&a<=0xf7&&b>=0xa1&&b<=0xfe)return 1;
    if(a>=0x81&&a<=0xa0&&b>=0x40&&b<=0xfe)return 1;
    if(a>=0xaa&&a<=0x40&&b>=0xfe&&b<=0xa0)return 1;
    if(a==0xa9&&b==0x96)return 1;
    return 0;
}
bool cmp(sz s1,sz s2)
{
    int t=0;
    while(true)
    {
        if(s1.dna[t]=='\0'||s2.dna[t]=='\0')break;
        if(s1.dna[t]<s2.dna[t])return true;
        else if(s1.dna[t]>s2.dna[t])return false;
        t++;
    }
    if(s1.dna[t]=='\0')return true;
    else return 0;
}
int ff(int k)
{
    int t=0;
    while(true)
    {
        if(s[k].dna[t]=='\0'||s[k-1].dna[t]=='\0')break;
        if(s[k].dna[t]!=s[k-1].dna[t])return true;
        t++;
    }
    if(s[k].dna[t]!='\0'||s[k-1].dna[t]!='\0')return true;
    return false;
}
int main()
{
    freopen("dic.txt","r",stdin);
    freopen("test.out","w",stdout);
    int n=0,maxn=0;
    while(scanf("%s",s[n].dna)!=EOF&&s[n].dna!="")
    {
        int t=strlen(s[n].dna);
        maxn=max(maxn,t);
        n++;
    }
    sort(s,s+n,cmp);
    printf("%s\n",s[0].dna);
    for(int i=1;i<n;i++)if(ff(i))printf("%s\n",s[i].dna);
    return 0;
}
