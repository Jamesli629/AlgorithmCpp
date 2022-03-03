#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct book//书的基本信息
{
	char CN[10];//书的索书号
	char name[30];//书名
	char type[10];//类型
	char author[30];//作者
    int number;//书的剩余数量
	char time[50];//出版时间
	char press[50];//出版社
	char address[100];//书籍所在地点（三牌楼校区或仙林校区）
	double price;//价格
	char state[50];//借阅状态
	char time1[50];//入库日期
	int frequency;//借阅次数
}book;

typedef struct book1//书的数量和基本信息
{
	int a;//书的数量
	book b[100];//一次最多存入100本
}book1;

void get(book1 *a);//录入图书
int change(book1 *p);//修改图书
void add(book1 *p);//添加图书
int grabble(book1 *p);//搜索图书 
int del(book1 *p);//删除图书
int ReadFile(char *fname,book1 d);
void WriteFile(char *fname,book1 d,int n);  /*将更改后的信息存文件并输出*/  
int main()
{
	
	int i;
	book1 d;                  /*定义一个结构体数组存放图书信息*/
	int num,b,e,f,c=1;
	int a;
	char filename[20];             /*文件名*/                           
	printf("Please input source file name:\n");
	scanf( "%s", filename );  	    /*读入原始数据文件名*/	            
	num=ReadFile(filename,d) ;    /*调用函数从文件读记录到结构体数组*/
   	do
   	  {
   	  	printf("\n\n\n\n\n\t\t\t\t图书管理系统\t\t\t\t\t\t\n");
	    printf("\t\t**********************************************\n");
		printf("\t\t\t*********1、录入图书信息**************\n");
		printf("\t\t\t*********2、修改图书信息**************\n");
		printf("\t\t\t*********3、添加图书信息**************\n");
		printf("\t\t\t*********4、删除图书信息**************\n");
		printf("\t\t\t*********5、图书信息查询**************\n");
		printf("\t\t\t*********6、图书的借阅次数************\n");
		printf("\t\t\t*********7、即将到期的图书************\n");
		printf("\t\t\t*********0、退出图书信息系统**********\n");
		printf("\t\t**********************************************\n");
		printf( "\t\tPlease Enter Choose: ");
        scanf("%d",&a);
        switch(a)
        {
			case 1:
				get(&d); //录入图书信息
				WriteFile(filename,d,d.a);
				continue; 
        	case 2:
        		b=change(&d);//修改图书信息
				if(b==0){printf("查无此书");}
				WriteFile(filename,d,d.a);
				break; 
		    case 3:
        		add(&d); //添加图书信息
				WriteFile(filename,d,d.a);
				break; 
			case 4:
        		f=del(&d);//删除图书信息
				if(f==0){printf("查无此书");}
				WriteFile(filename,d,d.a);
				break; 
			case 5:
        		e=grabble(&d);//搜索图书
				if(e==0){printf("查无此书");}
				WriteFile(filename,d,d.a);
				break; 
			case 6:
        		//jieyuecishu(); //jieyuecishu图书借阅次数排序函数
				WriteFile(filename,d,d.a);
				break; 
			case 7:
        	//	jijiangdaoqi(); //jijiangdaoqi即将到期的图书函数（三天之内） 
				WriteFile(filename,d,d.a);
				break; 
			case 0:
        		printf("\n退出\n");
				break; 
			default:
				printf("\n错误序号\n");
		
		}
	} while(c!=1) ;
	WriteFile(filename,d,d.a);

	getchar();getchar();
	return 0;
}
int ReadFile(char *fname,book1 d)    
{	int i=0;                       /*此处i应初始化为0*/
	FILE *fp;                     /*定义文件指针*/                    
	fp=open(fname,"r");            /*打开文本文件准备读入数据*/        
	if ( fp == 0 )                   /*如果文件打开失败 */               
	{	printf( "source file error\n" );
	    getchar();getchar();
		exit(1);
	}
/*下一条语句是从文件中读出第一条记录存入数组下标0处*/
	scanf( fp, "%s%s%s%s%d%s%s%s%lf%s%s%d", d.b[i].CN,d.b[i].name,d.b[i].type,d.b[i].author,&d.b[i].number,d.b[i].time,d.b[i].press,d.b[i].address,&d.b[i].price,d.b[i].state,d.b[i].time1,&d.b[i].frequency);    
	while( !feof(fp) )               /*当文件未结束时进入循环*/          
	{   i++;                     /*结构体数组的下标加1然后继续读入*/		   
	    scanf( fp, "%s%s%s%s%d%s%s%s%lf%s%s%d", d.b[i].CN,d.b[i].name,d.b[i].type,d.b[i].author,&d.b[i].number,d.b[i].time,d.b[i].press,d.b[i].address,&d.b[i].price,d.b[i].state,d.b[i].time1,&d.b[i].frequency);
    }
	close(fp);                    /*关闭文件*/                          
	return i;                      /*返回实际记录条数*/
}
void WriteFile(char *fname,book1 d,int n)  
{	
    int i;
    n=d.a;
	FILE *fp;                                                        
	fp=open(fname,"a");      /*以a方式打开文本文件准备写入内容*/    
	if ( fp == 0 )	      	    /* 如果文件打开失败 */  
{ 	printf( "create new file error\n" );
		exit(1);
	}
	for (i=0;i<n;i++)           /*记录条数n确知时可以这样控制循环*/
	{  /*下面两条语句以相同的格式将记录分别写入文件和屏幕显示*/
	 printf( fp, "%s\t%s\t%s\t%s\t%d\t%s\t%s\t%s\t%.2f\t%s\t%s\t%d\n", d.b[i].CN,d.b[i].name,d.b[i].type,d.b[i].author,d.b[i].number,d.b[i].time,d.b[i].press,d.b[i].address,d.b[i].price,d.b[i].state,d.b[i].time1,d.b[i].frequency );
     printf(  "%s\t%s\t%s\t%s\t%d\t%s\t%s\t%s\t%.2f\t%s\t%s\t%d\n", d.b[i].CN,d.b[i].name,d.b[i].type,d.b[i].author,d.b[i].number,d.b[i].time,d.b[i].press,d.b[i].address,d.b[i].price,d.b[i].state,d.b[i].time1,d.b[i].frequency );   
	}
	close(fp);              /*关闭文件*/                              
}
void get(book1 *a)//图书的基本信息,用指针P传参
{
    int e = 0;
	book1 d;
	int c = 1;//c决定是否录入下一本书
	char f[20]="可借阅";
	while(c)
	{   printf("请输入索书号：\n");
		scanf("%s", d.b[e].CN);
		printf("请输入书名：\n");
		scanf("%s", d.b[e].name);
		printf("请输入类型（人文、科技、外语、自然科学、社会科学等）:\n");
		scanf("%s", d.b[e].type);
		printf("请输入作者：\n");
		scanf("%s", d.b[e].author);
		printf("请输入书的数目：\n");
		scanf("%d", &d.b[e].number);
		printf("请输入出版社名称：\n");
		scanf("%s", d.b[e].press);
		printf("请输入出版时间(如2020年1月1日)：\n");
		scanf("%s", d.b[e].time);
		printf("请输入书籍所在地（“仙林校区”或“三牌楼校区”或“三牌楼校区和仙林校区”）：\n");
		scanf("%s", d.b[e].address);
		printf("请输入书籍价格（如“30.00”）：\n");
		scanf("%lf", &d.b[e].price);
		strcpy(d.b[e].state,f);//初始为可借阅
		printf("请输入入库日期（如2020年1月1日）：\n");
		scanf("%s", d.b[e].time1);
		d.b[e].frequency = 0;//初始时借阅次数为0
		printf("是否继续录入信息，是请输入“1”，否请输入“0”\n");
		scanf("%d", &c);
		e++;
		d.a=e;
	}
	printf("\n\n书有%d本\n",d.a);
	*a=d;
}
int change(book1 *p)//修改信息,如果找不到索书号返回值将为0
{
	book1 x=*p;
	char n[10];
	int i,k,y,z=1;
	k=x.a;//k为书籍数目
		printf("请输入待修改书籍的索书号\n");//由于书名可能有相同的，所以这里采用索书号
		scanf("%s",n);
		for(i=0;i<k;i++)
		{
			y=strcmp(x.b[i].CN,n);
			if(y==0)
			{printf("请输入索书号：\n");
			scanf("%s", x.b[i].CN);
			printf("请输入书名：\n");
			scanf("%s", x.b[i].name);
			printf("请输入类型（人文、科技、外语、自然科学、社会科学等）:\n");
			scanf("%s", x.b[i].type);
			printf("请输入作者：\n");
			scanf("%s", x.b[i].author);
			printf("请输入书的数目：\n");
			scanf("%d", &x.b[i].number);
			printf("请输入出版社名称：\n");
			scanf("%s", x.b[i].press);
			printf("请输入出版时间(如2020年1月1日)：\n");
			scanf("%s", x.b[i].time);
			printf("请输入书籍所在地（“仙林校区”或“三牌楼校区”或“三牌楼校区和仙林校区”）：\n");
			scanf("%s", x.b[i].address);
			printf("请输入书籍价格（如“30.00”）：\n");
			scanf("%lf", &x.b[i].price);
			printf("请输入入库日期（如2020年1月1日）：\n");
			scanf("%s", x.b[i].time1);
			break;//如果y等于0跳出循环		 
		   }
	     }//借阅次数和状态不变
	if(y!=0){z=0;}
	*p=x;
	return z;
}
void add(book1 *p)//增加书籍                                                
{
	int c=1;//c决定是否录入下一本书
	char f[20]="可借阅";
	book1 x=*p;
	int k=x.a;
	if(k>99)
	{printf("已满，无法输入");}//如果该book1型参数的书籍数目超过或者等于100，无法输入
	else{
	x=*p;
	while(c)
	{   printf("请输入索书号：\n");
		scanf("%s", x.b[k].CN);
		printf("请输入书名：\n");
		scanf("%s", x.b[k].name);
		printf("请输入类型（人文、科技、外语、自然科学、社会科学等）:\n");
		scanf("%s", x.b[k].type);
		printf("请输入作者：\n");
		scanf("%s", x.b[k].author);
		printf("请输入书的数目：\n");
		scanf("%d", &x.b[k].number);
		printf("请输入出版社名称：\n");
		scanf("%s", x.b[k].press);
		printf("请输入出版时间(如2020年1月1日)：\n");
		scanf("%s", x.b[k].time);
		printf("请输入书籍所在地（“仙林校区”或“三牌楼校区”或“三牌楼校区和仙林校区”）：\n");
		scanf("%s", x.b[k].address);
		printf("请输入书籍价格（如“30.00”）：\n");
		scanf("%lf", &x.b[k].price);
		strcpy(x.b[k].state,f );//初始为可借阅
		printf("请输入入库日期（如2020年1月1日）：\n");
		scanf("%s", x.b[k].time1);
		x.b[k].frequency = 0;//初始时借阅次数为0
		printf("是否继续录入信息，是请输入“1”，否请输入“0”\n");
		scanf("%d",&c);
		k++;
		x.a=k;
	}
	}
	*p=x;
}
int grabble(book1 *p)//搜索图书，如果没有返回值为0
{
	
	book1 x=*p;
	char n[10];
	int i,k,y,h=1,z=1;
	k=x.a;//k为书籍数目
	while(h)
	{
		printf("请输入待搜索书籍的索书号\n");
		scanf("%s",n);
		for(i=0;i<k;i++)
		{
			y=strcmp(x.b[i].CN,n);
			if(y==0)
			{
		      printf("索书号：%s\n",x.b[i].CN);
			  printf("书名：%s\n", x.b[i].name);
			  printf("类型:%s\n",x.b[i].type);
			  printf("作者:%s\n", x.b[i].author);
			  printf("书的数目：%d\n",x.b[i].number);
			  printf("出版社名称：%s\n", x.b[i].press);
			  printf("出版时间：%s\n", x.b[i].time);
			  printf("书籍所在地：%s\n",x.b[i].address);
			  printf("书籍价格：%f\n",x.b[i].price);
			  printf("入库日期：%s\n",x.b[i].time1);
			 break;//如果y等于0跳出循环		 
			}
		}
	}
	if(y!=0){z=0;}
	return z;
}
int del(book1 *p)//删除图书
{
	book1 x=*p;
	char n[10];
	int i,k,y,h=1,z=1;
	k=x.a;//k为书籍数目
	//while(h)
	//{
		printf("请输入待删除书籍的索书号\n");
		scanf("%s",n);
		for(i=0;i<k;i++)
		{
			y=strcmp(x.b[i].CN,n);
			if(y==0)
			{ break;}//如果y等于0跳出循环
		}
		if(i!=k)
		{
			for (;i<k-1;i++)
			{
				strcpy(x.b[i].CN,x.b[i+1].CN);
				strcpy(x.b[i].name,x.b[i+1].name);
				strcpy(x.b[i].type,x.b[i+1].type);
				strcpy(x.b[i].author,x.b[i+1].author);
				x.b[i].number=x.b[i+1].number;
				strcpy(x.b[i].time,x.b[i+1].time);
				strcpy(x.b[i].press,x.b[i+1].press);
				strcpy(x.b[i].address,x.b[i+1].address);
				x.b[i].price=x.b[i+1].price;
				strcpy(x.b[i].state,x.b[i+1].state);
				strcpy(x.b[i].time1,x.b[i+1].time1);
				x.b[i].frequency=x.b[i+1].frequency;
			}
			x.a--;
		}
		else  {z=0;return z;}
		//}
} 