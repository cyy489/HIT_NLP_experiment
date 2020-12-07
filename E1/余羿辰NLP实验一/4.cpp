#include<string>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef struct
{
    char word[33];
}word;
word dic[53035];
typedef struct
{
    int f;
    char al[3];
}let;
let senlet[10001];
int f[10001];
char tr[33];
string sen;
int dicn=0;
int chf(unsigned char a,unsigned char b)
{
    if(a>=0xb0&&a<=0xf7&&b>=0xa1&&b<=0xfe)return 1;
    if(a>=0x81&&a<=0xa0&&b>=0x40&&b<=0xfe)return 1;
    if(a>=0xaa&&a<=0x40&&b>=0xfe&&b<=0xa0)return 1;
    if(a==0xa9&&b==0x96)return 1;
    return 0;
}
int sma(int k)
{
    int t=0;
    while(true)
    {
        if(dic[k].word[t]=='\0'||tr[t]=='\0')break;
        if(tr[t]<dic[k].word[t])return true;
        else if(tr[t]>dic[k].word[t])return false;
        t++;
    }
    if(tr[t]=='\0'&&dic[k].word[t]!='\0')return true;
    return false;
}
int equ(int k)
{
    int t=0;
    while(true)
    {
        if(dic[k].word[t]=='\0'||tr[t]=='\0')break;
        if(dic[k].word[t]!=tr[t])return false;
        t++;
    }
    if(dic[k].word[t]=='\0'&&tr[t]=='\0')return true;
    return false;
}
int fin()
{
    int l=0,r=dicn,mid=(l+r)/2;
    while(l+1<=r)
    {
        if(equ(mid))return 1;
        if(sma(mid))r=mid;
        else l=mid+1;
        mid=(l+r)/2;
    }
    return 0;
}
int main()
{
    freopen("dic.txt","r",stdin);
    freopen("seg_FMM.txt","w",stdout);
    while(scanf("%s",dic[dicn].word)!=EOF&&dic[dicn].word!="")dicn++;
    freopen("199801_sent.txt","r",stdin);
    while(getline(cin,sen))
    {
        if(sen=="")
        {
            printf("\n");
            continue;
        }
        int senl=sen.length(),senn=0;
        for(int i=0;i<senl;i++)
        if(sen[i]>=0&&sen[i]<=0x7f)
        {
            senlet[senn].f=0;
            senlet[senn].al[0]=sen[i];
            senlet[senn].al[1]='\0';
            senn++;
        }
        else
        {
            senlet[senn].f=1;
            senlet[senn].al[0]=sen[i];
            senlet[senn].al[1]=sen[i+1];
            senlet[senn].al[2]='\0';
            senn++;
            i++;
        }
        int s=0;
        for(int i=0;i<senn;i++)
        {
            int j=16;
            while(j>=1)
            {
                int l=0;
                for(int k=0;k<j;k++)
                if(senlet[i+k].f==0)
                {
                    tr[l]=senlet[i+k].al[0];
                    l++;
                }
                else
                {
                    tr[l]=senlet[i+k].al[0];
                    l++;
                    tr[l]=senlet[i+k].al[1];
                    l++;
                }
                tr[l]='\0';
                if(fin())
                {
                    s++;
                    for(int k=0;k<j;k++)f[i+k]=s;
                    i+=j-1;
                    break;
                }
                else j--;
            }
            if(j==0)f[i]=0;
        }
        //for(int i=0;i<senn;i++)printf("%d\n",f[i]);
        if(senlet[0].f==0)printf("%c",senlet[0].al[0]);
        else printf("%c%c",senlet[0].al[0],senlet[0].al[1]);
        for(int i=1;i<senn;i++)
        {
            if(f[i]!=f[i-1])printf("/ ");
            if(senlet[i].f==0)printf("%c",senlet[i].al[0]);
            else printf("%c%c",senlet[i].al[0],senlet[i].al[1]);
        }
        printf("/ \n");
    }
    return 0;
}
