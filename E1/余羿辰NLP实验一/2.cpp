#include<string>
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
char s[100001];
int chf(unsigned char a,unsigned char b)
{
    if(a>=0xb0&&a<=0xf7&&b>=0xa1&&b<=0xfe)return 1;
    if(a>=0x81&&a<=0xa0&&b>=0x40&&b<=0xfe)return 1;
    if(a>=0xaa&&a<=0x40&&b>=0xfe&&b<=0xa0)return 1;
    if(a==0xa9&&b==0x96)return 1;
    return 0;
}
int main()
{
    freopen("dic.txt","r",stdin);
    freopen("test.out","w",stdout);
    while(scanf("%s",s)!=EOF&&s!="")
    {
        int n=strlen(s),t=0,f=0;
        for(int i=n-1;i>=0;i--)if(s[i]=='/'){t=i;break;}
        for(int i=0;i<t;i++)
        {
            if(s[i]>=0&&s[i]<=0x7f)continue;
            else
            {
                if(chf(s[i],s[i+1])){f=1;break;}
                i++;
            }
        }
        if(!f)continue;
        for(int i=0;i<t;i++)
        {
            if(i==0&&s[i]=='[')continue;
            if(s[i]>=0&&s[i]<=0x7f)printf("%c",s[i]);
            else
            {
                printf("%c%c",s[i],s[i+1]);
                i++;
            }
        }
        printf("\n");
    }
    return 0;
}
