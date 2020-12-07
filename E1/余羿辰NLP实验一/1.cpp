#include <iostream>
#include<cstring>
#include<string>
#include <clocale>//c->ctype,cmath;locale->local environment
using namespace std;
wchar_t s[50045];
string ss;
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
    freopen("wl.in", "r", stdin);
    freopen("test.out", "w", stdout);
    char s1[212];
    char s2[22];
    scanf("%s",s1);
    scanf("%s",s2);
    printf("%d ",s1[0]);
    printf("%d\n",s2[0]);
    getline(cin,ss);
    for(int i=0;i<ss.length();i++)
    if(ss[i]>=0&&ss[i]<=0x7f)
    {
        printf(" ");
        printf("%c",ss[i]);
        printf(" ");
    }
    else
    {
        if(chf(ss[i],ss[i+1]))printf("%c%c",ss[i],ss[i+1]);
        else
        {
            printf(" ");
            printf("%c%c",ss[i],ss[i+1]);
            printf(" ");
        }
        i++;
    }
    return 0;
}
