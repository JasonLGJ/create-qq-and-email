#include<windows.h> 
#include<stdio.h> 
#include<stdlib.h> 
#include<time.h> 
#define MAX_ADDRESS 1000 

char directory[20]; 
DWORD writeFile(const char*filename,char*str) 
{ 
FILE *fp; 
fp=fopen(filename,"a+"); 
if(fp==NULL) 
{ 
puts("Cannot open this file!"); 
return -1; 
} 
fprintf(fp,"%s\n",str); 
fflush(fp); 
//fputs(str,fp); 
return 1; 
} 

DWORD produceQQMail() //��������������QQ���亯��
{ 
unsigned int i,count; 
char zj[20]; 
char compare[20]; 
unsigned long relative; 
//for(count=1;count<=MAX_ADDRESS;count++)     /*qq̫���ˣ���������10���ɡ�*/
for(count=1;count<=10;count++) 
{ 
Sleep(600); 
srand((unsigned)time(0)); 
while(1)                  
{ 
relative=1+(int)(10.0*rand()/(RAND_MAX+1.0));//����QQ�����λ��
if(relative<7||relative>9) 
continue;//�ж��Ƿ���������Ҫ��λ�� 
Sleep(100); 
for(i=0;i<relative;i++) 
{ 
itoa(1+(int)(10.0*rand()/(RAND_MAX+1.0)),&zj[i],10);//����ÿһλ����,����ת��Ϊ�ַ���,��������������
} 
zj[i]='\0'; 
strcat(zj,"@qq.com");//������������ 
if(count>1&&strcmp(compare,zj)==0) //�Ƚ�ǰ�������Է�������ͬ������
continue; 
strcpy(compare,zj); 
if(writeFile(directory,zj)==1) 
{ 
printf("===>���ɵ�%d��QQ����\n",count);
//system("cls"); 
break; 
} 
} 
} 
return 1; 
} 

void main() 
{ 
puts("=>��������Ҫ���浽���ļ�������Ŀ¼");
scanf("%s",directory); 
puts("=>Now producing QQ mail addresses����"); 
produceQQMail(); 
}