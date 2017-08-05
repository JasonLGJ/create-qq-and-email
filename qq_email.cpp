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

DWORD produceQQMail() //→→→→→产生QQ邮箱函数
{ 
unsigned int i,count; 
char zj[20]; 
char compare[20]; 
unsigned long relative; 
//for(count=1;count<=MAX_ADDRESS;count++)     /*qq太多了，换成生成10个吧。*/
for(count=1;count<=10;count++) 
{ 
Sleep(600); 
srand((unsigned)time(0)); 
while(1)                  
{ 
relative=1+(int)(10.0*rand()/(RAND_MAX+1.0));//产生QQ号码的位数
if(relative<7||relative>9) 
continue;//判断是否满足所需要的位数 
Sleep(100); 
for(i=0;i<relative;i++) 
{ 
itoa(1+(int)(10.0*rand()/(RAND_MAX+1.0)),&zj[i],10);//生成每一位数字,将其转换为字符型,并保存在数组中
} 
zj[i]='\0'; 
strcat(zj,"@qq.com");//连接生成邮箱 
if(count>1&&strcmp(compare,zj)==0) //比较前后两者以防出现相同的邮箱
continue; 
strcpy(compare,zj); 
if(writeFile(directory,zj)==1) 
{ 
printf("===>生成第%d个QQ邮箱\n",count);
//system("cls"); 
break; 
} 
} 
} 
return 1; 
} 

void main() 
{ 
puts("=>请输入您要保存到的文件名及其目录");
scanf("%s",directory); 
puts("=>Now producing QQ mail addresses……"); 
produceQQMail(); 
}