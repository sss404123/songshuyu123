#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 40
#define increase 10
int f,t=0;
typedef struct
{
char name[20];
char sex[20];
int num;
int room;
}stu;
stu stud;
typedef struct
{
int length;
stu *elem;
int listsize;
}linklist;
void init(linklist &l)
{
l.length=0;
l.elem=(stu *)malloc(N*sizeof(stu ));
l.listsize=N;
}
void menu()//�����˵�
{
printf("\n");
printf("            ***************�밴��ѡ�����****************\n");
printf("\n");printf("\n");
printf("            1 ����������                  2 ��ѧ������\n");
printf("\n");
printf("            3 ����������                  4 ����������\n");
printf("\n");
printf("            5 ��ѧ�Ų���                  6 ��������\n");
printf("\n");
printf("            7 ��ѧ�Ų���                  8 ��ѧ��ɾ��\n");
printf("\n");    printf("\n");    printf("\n");    printf("\n");
printf("��ʾ:����������ּ�Ϊ0ʱ���˳�����\n");
if(t==1)
{
printf("���������ּ�(1~8Ϊ������):");//1~8Ϊ��Ч���ֲ�����
scanf("%d",&f);
if(f<0||f>9)
{
system("cls");
printf("\n");
printf("�������ֲ���,����ԭ������!\n");  printf("\n");
menu();
}
}
}
void disp()      //����������
{
char c;
fflush(stdin);
printf("\n");
printf("�밴���������������:");
scanf("%c",&c);
system("cls");
}
void panduan3()  //�������ѧ����¼�򷵻�������
{
printf("\n");
printf("����ѧ����¼\n");
printf("\n");
disp();
menu();
}
void shuru(linklist l)  //����ѧ������Ϣ
{
printf("����������:");
fflush(stdin);      // ������뻺�������õ���ȷ����������
gets(stud.name);    //����һ���ַ�����������
printf("�������Ա�:");  //�������
fflush(stdin);      // ������뻺�������õ���ȷ���������ݡ�����
gets(stud.sex);    //����һ���ַ������Ա𣩡�������
printf("������ѧ��:");
scanf("%d",&stud.num);
printf("�����뷿��:");
scanf("%d",&stud.room);
}
void create(linklist &l)//����ѧ����Ϣ��
{
if(l.length>=l.listsize)  //�ж�ѧ���������Ƿ񳬹���ֵ����������������·���
{
stu *newbase;
newbase=(stu*)realloc(l.elem,(N+increase)*sizeof(stu ));//���·���洢����
l.elem=newbase;
l.listsize+=increase;
}
int i=2;
char ch;
printf("\n");
printf(" **************************��ʼ�������Ա�***************************\n");printf("\n");
printf("�������1��ѧ������Ϣ\n");
shuru(l);    //�������뺯��
ch=getchar();
strcpy(l.elem[l.length].name,stud.name);//ָ�븴��
l.elem[l.length].num=stud.num;
l.elem[l.length].room=stud.room;
l.length++;
printf("\n");
printf("�Ƿ��������?<y/n>:");
scanf("%c",&ch);
printf("\n");printf("\n");//�������
while(ch=='y')
{
printf("�������%d��ѧ������Ϣ\n",i);
shuru(l);
strcpy(l.elem[l.length].name,stud.name);
l.elem[l.length].num=stud.num;
l.elem[l.length].room=stud.room;
l.length++;
i++;
ch=getchar(); printf("\n");
printf("�Ƿ��������?<y/n>:");
scanf("%c",&ch);//�ַ���ֵ��
printf("\n");printf("\n");
}
if(ch=='n') system("cls");
}
void sort3(linklist &l)//���������򣨲���ð������
{
int i,j;
stu temp;
for(i=0;i<l.length-1;i++)
for(j=i+1;j<l.length;j++)
if(l.elem[i].room>l.elem[j].room)
{
temp=l.elem[i];
l.elem[i]=l.elem[j];
l.elem[j]=temp;
}
}
void sort2(linklist &l)//��ѧ�����򣨲���ð������
{
int i,j;
stu temp;
for(i=0;i<l.length-1;i++)
for(j=i+1;j<l.length;j++)
if(l.elem[i].num>l.elem[j].num)
{
temp=l.elem[i];
l.elem[i]=l.elem[j];
l.elem[j]=temp;
}
}
void sort1(linklist &l)//���������򣨲���ð������
{
int i,j;
stu temp;
for(i=0;i<l.length-1;i++)
for(j=i+1;j<l.length;j++)
if(strcmp(l.elem[i].name,l.elem[j].name)>0)
{
temp=l.elem[i];
l.elem[i]=l.elem[j];
l.elem[j]=temp;
}
}
void print1(linklist &l)//��ӡѧ����Ϣ
{
int i;
printf("\n");
printf("����          ѧ��    ����\n");printf("\n");
for(i=0;i<l.length;i++)
printf("%-15s %-3d %5d\n",l.elem[i].name,l.elem[i].num,l.elem[i].room);
}
void print2(linklist &l,int mid)  //��ӡ���ҵ���ѧ����Ϣ
{
printf("���ҳɹ�----->��ѧ����ϢΪ:\n");
printf("����          ѧ��    ����\n");printf("\n");
printf("%-15s %-5d %-5d\n",l.elem[mid].name,l.elem[mid].num,l.elem[mid].room);
}
int panduan1(char ch)  //�ж��Ƿ��������
{
scanf("%c",&ch);
printf("�Ƿ��������?<y/n>:");
fflush(stdin);
scanf("%c",&ch);
if(ch=='y')
{
system("cls");
return(1);
}
else
return 0;
}
int panduan2(char ch)  //���ѧ��������,�ж��Ƿ��������
{
scanf("%c",&ch);
printf("��ѧ��������,�Ƿ��������?<y/n>:");
fflush(stdin);
scanf("%c",&ch);
if(ch=='y')
{
system("cls");
return(1);
}
else
return 0;
}
void chazhao3(linklist &l)//�����Ŵ�С������ң����ö��ֲ��ң�
{
if(l.length==0) panduan3();    //�˺�������Ϊ������������
else
{
int low=0,high=l.length,mid,flag=0;//flag��Ϊ��־����Ϊ1���ʾ���ҳɹ�������û����Ҫ���ҵ�ѧ��
int m;
char ch;
printf("\n");printf("\n");
printf("�����Ų���----->������Ҫ���ҵķ���:");
scanf("%d",&m);
printf("\n");
while(low<=high)
{
mid=(low+high)/2;
if(m==l.elem[mid].room)
{
flag=1;
break;
}
else if(m>l.elem[mid].room)
low=mid+1;
else
high=mid-1;
}
if(flag==1)
{
print2(l,mid);
if(panduan1(ch))    //�����жϺ���1
chazhao3(l);
else
{
system("cls");
menu();
}
}
else
{
if(panduan2(ch))  //�����жϺ���2
chazhao3(l);
else
{
system("cls");//����ϵͳ����cls�������
menu();
}
}
}
}
void chazhao2(linklist &l)//��ѧ�Ŵ�С������ң����ö��ֲ��ң�
{
if(l.length==0) panduan3();
else
{
int low=0,high=l.length,mid,flag=0;
int n;
char ch;
printf("\n");printf("\n");
printf("��ѧ�Ų���----->������Ҫ���ҵ�ѧ��:");
scanf("%d",&n);
printf("\n");
while(low<=high)
{
mid=(low+high)/2;
if(n==l.elem[mid].num)
{
flag=1;
break;
}
else if(n>l.elem[mid].num)
low=mid+1;
else
high=mid-1;
}
if(flag==1)
{
print2(l,mid);
if(panduan1(ch))
chazhao2(l);
else
{
system("cls");
menu();
}
}
else
{
if(panduan2(ch))     chazhao2(l);
else
{
system("cls");
menu();
}
}
}
}
void chazhao1(linklist &l)//��������С������ң����ö��ֲ��ң�
{
if(l.length==0) panduan3();
else
{
int low=0,high=l.length,mid,flag=0;
printf("\n");printf("\n");
printf("����������----->������Ҫ���ҵ�����:");
char a[15],ch;
scanf("%s",a);
printf("\n");
while(low<=high)
{
mid=(low+high)/2;
if(strcmp(a,l.elem[mid].name)==0)
{
flag=1;
break;
}
else if(strcmp(a,l.elem[mid].name)>0)
low=mid+1;
else
high=mid-1;
}
if(flag==1)
{
print2(l,mid);    //��ӡ���ҵ���ѧ������Ϣ
if(panduan1(ch)) chazhao1(l);
else
{
system("cls");
menu();
}
}
else
{
if(panduan2(ch))    chazhao1(l);
else
{
system("cls");
menu();
}
}
}
}
void insert(linklist &l)//��ѧ�Ŵ�С��������ѧ��
{
int i,j,k;
char ch;
printf("\n");
printf("�����ѧ����ϢΪ:\n");
printf("����:");
fflush(stdin);// ������뻺�������õ���ȷ����������
gets(stud.name);
printf("ѧ��:");    scanf("%d",&stud.num);
printf("����:");    scanf("%d",&stud.room);
if(l.length==0)
{
strcpy(l.elem[l.length].name,stud.name);
l.elem[l.length].num=stud.num;
l.elem[l.length].room=stud.room;
}
for(i=0;i<l.length;i++)
{
if(stud.num<l.elem[i].num)
{
k=i;
for(j=l.length;j>k;j--)
l.elem[j]=l.elem[j-1];
strcpy(l.elem[k].name,stud.name);
l.elem[k].num=stud.num;
l.elem[k].room=stud.room;
break;
}
else
{
strcpy(l.elem[l.length].name,stud.name);
l.elem[l.length].num=stud.num;
l.elem[l.length].room=stud.room;
}
}
l.length++;
fflush(stdin);//����ļ������������ļ���д��ʽ��ʱ��������������д���ļ�
printf("\n");
printf("�Ƿ��������?<y/n>:");
scanf("%c",&ch);
if(ch=='y') insert(l);
else system("cls");
}
void Delete(linklist &l)//��ѧ��ɾ����ѧ��
{
int i,j,k=-1;
char ch;
printf("\n");printf("\n");
printf("������Ҫɾ��ѧ����ѧ��:");
scanf("%d",&stud.num);//���͸�ֵ
for(i=0;i<l.length;i++)
{
if(stud.num==l.elem[i].num)
{
printf("��ѧ������ϢΪ:\n");printf("\n");
printf("%-15s %-3d %7d\n",l.elem[i].name,l.elem[i].num,l.elem[i].room);
k=i;
for(j=k;j<l.length-1;j++)
l.elem[j]=l.elem[j+1];
printf("\n");
break;
}
}
if(i>=l.length) printf("��ѧ��������\n");
if(k>=0)l.length--;
fflush(stdin);
printf("\n");
printf("�Ƿ����ɾ��?<y/n>:");
scanf("%c",&ch);
system("cls");
if(ch=='y') Delete(l);
else system("cls");
}
int main()    //������
{
linklist l;    //�������Ա� l
init(l);        //���ó�ʼ��������ָ�룩
char ch;
system("color a");
printf("\n");
printf("  *************************��ӭ������������ѯϵͳ*************************\n");
printf("\n");
printf("�밴�������ʼ����:");
scanf("%c",&ch);
system("cls");//����Ļ��ǰ��ʾ�����������
create(l);    //�������Ա�������
system("cls");
t=1;
menu();        //�������˵�����
while(f!=0)
{
system("cls");
switch(f)
{
case 1: sort1(l);    //���ð�����������
printf("\n");
if(l.length==0)
{
printf("����ѧ����¼\n");
printf("\n");
disp();
menu();
}
else
{
printf("����������:\n");
print1(l);
disp();  //���÷���������
menu();
}
break;
case 2: sort2(l);  //���ð�ѧ��������
printf("\n");
if(l.length==0)
{
printf("����ѧ����¼\n");
printf("\n");
disp();
menu();
}
else
{
printf("��ѧ������:\n");
print1(l);
disp();
menu();
}break;
case 3: sort3(l);  //���ð�����������
printf("\n");
if(l.length==0)
{
printf("����ѧ����¼\n");
printf("\n");
disp();
menu();
}
else
{
printf("����������:\n");
print1(l);
disp();
menu();
}break;
case 4:sort1(l);      //�ȵ��ð�������������������
chazhao1(l);  //�ٵ��ð��������Һ������У����֣�����
break;
case 5: sort2(l);    //�ȵ��ð�ѧ����������������
chazhao2(l);    //�ٵ��ð�ѧ�Ų��Һ������У����֣�����
break;
case 6: sort3(l);      //�ȵ��ð�������������������
chazhao3(l);    //�ٵ��ð����Ų��Һ������У����֣�����
break;
case 7: sort2(l);      //���ò��뺯��
insert(l);
system("cls");
printf("��ʾ������ѧ����Ϣ:\n");print1(l);
disp();
menu();
break;
case 8: Delete(l);    //����ɾ������
if(l.length==0)
{
printf("\n");
printf("ѧ����¼�ѱ�ɾ����\n");
printf("\n");
disp();
menu();
}
else
{
printf("��ʾɾ�����ѧ����Ϣ:\n");
print1(l);
disp();
menu();
}
break;
}
}
}