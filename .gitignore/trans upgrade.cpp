#include<stdio.h>
#include<string.h>
#include<math.h>
int trans(char str[])
{
    if(strcmp("��",str)==0)return 0;
    if(strcmp("һ",str)==0)return 1;
    if(strcmp("��",str)==0)return 2;
    if(strcmp("��",str)==0)return 3;
    if(strcmp("��",str)==0)return 4;
    if(strcmp("��",str)==0)return 5;
    if(strcmp("��",str)==0)return 6;
    if(strcmp("��",str)==0)return 7;
    if(strcmp("��",str)==0)return 8;
    if(strcmp("��",str)==0)return 9;
    if(strcmp("ʮ",str)==0)return 10;
}
int jud(char str[]){
    char more[10],less[10];
    if(strlen(str)==2){return trans(str); //��Ӧ��һ���ȵ������ֱ�������
    }
    else if(strlen(str)==4){
        more[0]=str[2];
        more[1]=str[3];
        more[2]='\0';      
            if(trans(more)!=10) return 10+trans(more);//��Ӧʮһ��ʮ������ʮ��ͷ���������ֱ�������
            else{
                more[0]=str[0];
                more[1]=str[1];
                more[2]='\0';
                return 10*trans(more);//��Ӧ��ʮ����ʮ����ʮ��β������
            }
    
    }
    else if(strlen(str)==6){
        more[0]=str[4];
        more[1]=str[5];
        more[2]='\0';
        less[0]=str[0];
        less[1]=str[1];
        less[2]='\0';
        return trans(more)+trans(less)*10;//��Ӧ����ʮ�������͵�����
    }
}
int main(){
	char *chinese[11]={"��","һ","��","��","��","��","��","��","��","��","ʮ"};
	char name[200],verb[200],numb[200],oper[200],name1[200],toint[200],name3[200];
	char a[20],b[20],numb2[20],d[20],word[100],e[20],f[20],cold[100],name2[100];
	char age[200],money[200];
	int sum,sum2,sum3;//sum��ʾ�ڶ������䣬sum2��ʾ�㻨Ǯ
	scanf("%s",toint);
	scanf("%s %s %s",name,verb,numb);
	sum=jud(numb);
	while(scanf("%s",name1)!=EOF)
	{	
		if(strcmp(name1,toint)==0)//�ж��Ƿ��ǵڶ���
		{
			scanf("%s %s %s",name3,verb,numb);
			sum2=trans(numb);
		}
		if(strcmp(name1,name)==0){//�Ӽ�������+-+-+-+-+-+-+-+-+-+-+-++-+-+-
			scanf("%s",oper);
			if(strcmp(oper,"����")==0){
				scanf("%s",numb);
				sum3=jud(numb);
				sum+=sum3;}
			if(strcmp(oper,"����")==0){
				scanf("%s",numb);	
				if(strlen(numb)==2)
				{
					sum3=jud(numb);
					sum-=sum3;
				}//printf("%s",chinese[sum]);
			}
		}
		else if(strcmp(name1,"����")==0)
		{
			int lasttmp;
			scanf("%s",name);
			scanf("%s %s %s %s %s %s %s %s %s %s",a,name,b,numb2,d,name2,word,e,f,cold);
			lasttmp=trans(numb2);
			int len=strlen(word);
			int len1=strlen(cold);
			{
				if(sum>=lasttmp)
				{	if(sum>=0&&sum<=10){
					printf("%s\n",chinese[sum]);for (int i=1;i<len-1; i+=2) {printf("%c%c",word[i],word[i+1]);}//ȥ��˫����
					}
					else {
					if(sum%10==0){
						printf("%sʮ\n",chinese[sum/10]);for (int i=1;i<len-1; i+=2) {printf("%c%c",word[i],word[i+1]);}//ȥ��˫����
					}
					else if(sum<=19){
						printf("ʮ%s\n",chinese[sum%10]);for (int i=1;i<len-1; i+=2) {printf("%c%c",word[i],word[i+1]);}//ȥ��˫����
					}
					else {
						printf("%sʮ%s\n",chinese[sum/10],chinese[sum%10]);for (int i=1;i<len-1; i+=2) {printf("%c%c",word[i],word[i+1]);}//ȥ��˫����
					}
				}}
				else if(sum<lasttmp){
						if(sum<0)
						{
							int under=abs(sum);	
							printf("%s%s\n","��",chinese[under]);
							for(int j=1;j<len1-1;j+=2) {printf("%c%c",cold[j],cold[j+1]);}}
						}
				else{	
					printf("%s\n",chinese[sum]);for(int j=1;j<len1-1;j+=2) {printf("%c%c",cold[j],cold[j+1]);}}//ȥ��˫����
			}
			}
		else if(strcmp(name1,"���")==0)//�����ж��Ƿ���ϵڶ���
		{	
			scanf("%s %s %s %s %s %s %s %s %s",age,b,numb2,d,money,word,e,f,cold);
			scanf("%s %s",a,age);
			if(strcmp(a,"����")==0)
			{	
				if(sum>8)//�ڶ���sum��ʾ����,sum2�㻨Ǯ
				{
					int	x=sum2+1;
					printf("%s",chinese[x]);
				}
			}
		}
	}
	return 0;
}
