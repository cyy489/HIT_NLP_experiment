#include<string>
#include<cstdio>
#include<cstring>
#include<fstream>
#include<iostream>
#include<algorithm>
using namespace std;
int sen1n[10001],sen2n[10001],sen3n[10001];
string sen1,sen2,sen3;
int main()
{
    fstream fin1,fin2,fin3;
    fin1.open("199801_seg&pos.txt",fstream::in);
    fin2.open("seg_FMM.txt",fstream::in);
    fin3.open("seg_BMM.txt",fstream::in);
    freopen("score.txt","w",stdout);
    int sen1s=0,sen2s=0,sen3s=0,Fr=0,Br=0;
    while(getline(fin1,sen1))
    {
        getline(fin2,sen2);
        getline(fin3,sen3);
        if(sen1=="")continue;
        int senl=sen1.length(),tri=0;
        sen1n[0]=0;
        for(int i=0;i<senl-1;i++)
        if(sen1[i]==' '&&sen1[i+1]==' ')
        {
            sen1n[0]++;
            int j,t=0;
            for(j=i-1;j>=tri;j--)if(sen1[j]=='/')break;
            for(int k=tri;k<j;k++)
            if(sen1[k]>=0&&sen1[k]<=0x7f)t++;
            else t++,k++;
            if(sen1[tri]=='[')t--;
            sen1n[sen1n[0]]=t;
            tri=i+2;
            i++;
        }
        senl=sen2.length(),tri=0;
        sen2n[0]=0;
        for(int i=0;i<senl;i++)
        if(sen2[i]==' ')
        {
            sen2n[0]++;
            int t=0;
            for(int k=tri;k<i-1;k++)
            if(sen2[k]>=0&&sen2[k]<=0x7f)t++;
            else t++,k++;
            sen2n[sen2n[0]]=t;
            tri=i+1;
        }
        senl=sen3.length(),tri=0;
        sen3n[0]=0;
        for(int i=0;i<senl;i++)
        if(sen3[i]==' ')
        {
            sen3n[0]++;
            int t=0;
            for(int k=tri;k<i-1;k++)
            if(sen3[k]>=0&&sen3[k]<=0x7f)t++;
            else t++,k++;
            sen3n[sen3n[0]]=t;
            tri=i+1;
        }
        /*for(int i=1;i<=sen1n[0];i++)printf("%d ",sen1n[i]);
        printf("\n");
        for(int i=1;i<=sen2n[0];i++)printf("%d ",sen2n[i]);
        printf("\n");
        for(int i=1;i<=sen3n[0];i++)printf("%d ",sen3n[i]);
        printf("\n");
        printf("\n");*/
        sen1s+=sen1n[0];
        sen2s+=sen2n[0];
        sen3s+=sen3n[0];
        int t1=0,t2=0,t3=0,j=1;
        for(int i=1;i<=sen2n[0];i++)
        {
            if(t1==t2)
            {
                t1+=sen1n[j];
                t2+=sen2n[i];
                if(t1==t2)Fr++;
                j++;
                if(j>sen1n[0])break;
            }else if(t1>t2){t2+=sen2n[i];continue;}
            else
            {
                while(t1<t2)
                {
                    t1+=sen1n[j];
                    j++;if(j>sen1n[0])break;
                }
                if(j>sen1n[0])break;
                if(t1==t2)
                {
                    t1+=sen1n[j];
                    t2+=sen2n[i];
                    if(t1==t2)Fr++;
                    j++;if(j>sen1n[0])break;
                }
                else t2+=sen2n[i];
            }
        }
        t1=0,j=1;
        for(int i=1;i<=sen3n[0];i++)
        {
            if(t1==t3)
            {
                t1+=sen1n[j];
                t3+=sen3n[i];
                if(t1==t3)Br++;
                j++;
                if(j>sen1n[0])break;
            }else if(t1>t3){t3+=sen3n[i];continue;}
            else
            {
                while(t1<t3)
                {
                    t1+=sen1n[j];
                    j++;if(j>sen1n[0])break;
                }
                if(j>sen1n[0])break;
                if(t1==t3)
                {
                    t1+=sen1n[j];
                    t3+=sen3n[i];
                    if(t1==t3)Br++;
                    j++;if(j>sen1n[0])break;
                }
                else t3+=sen3n[i];
            }
        }
    }
    printf("%d %d %d %d %d\n",sen1s,sen2s,sen3s,Fr,Br);
    printf("FMM: precision:%f recall:%f F:%f\n",(double)Fr/sen2s,(double)Fr/sen1s,2.0*Fr/sen2s*Fr/sen1s/((double)Fr/sen2s+(double)Fr/sen1s));
    printf("BMM: precision:%f recall:%f F:%f\n",(double)Br/sen3s,(double)Br/sen1s,2.0*Br/sen3s*Br/sen1s/((double)Br/sen3s+(double)Br/sen1s));
    fin1.close();
    fin2.close();
    fin3.close();
    return 0;
}
