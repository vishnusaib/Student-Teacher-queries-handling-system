#include<stdio.h>
int n,tot=0,readyqueue[10000],burst[10],arrival[10],pid[10],completion[10],waiting[10],type[10],temp,start=0,last=0;
float totwat=0,tottat=0;
void sort()
{
int i,j;
for(i=0;i<n;i++)
{
for(j=1;j<n-i;j++)
{
if(arrival[j-1]>arrival[j])
{
temp=arrival[j-1];
arrival[j-1]=arrival[j];
arrival[j]=temp;
temp=burst[j-1];
burst[j-1]=burst[j];
burst[j]=temp;
temp=pid[j-1];
pid[j-1]=pid[j];
pid[j]=temp;
temp=type[j-1];
type[j-1]=type[j];
type[j]=temp;
}
}
}
}
void enqueue(int j)
{
readyqueue[last++]=j;
}
int dequeue()
{
return readyqueue[start++];
}
void cal(int pre,int fin)
{
int i;
for(i=start;i<last;i++)
waiting[readyqueue[i]]+=(fin-pre);
}
void getType(int i)
{
	printf("Enter the Type Of Request\n1.Faculty Request\t2.Student Request");
	scanf("%d",&type[i]);
}
void main()
{
int i,j,qat,add=0,k,pre=-1,flag=-1;
printf("Enter no.of processes");
scanf("%d",&n);
printf("Enter Quantum Time");
scanf("%d",&qat);
printf("Enter %d no.of Processes\n",n);
for(i=0;i<n;i++)
{
printf("Enter %d Arrival Time and Burst Time",i+1);
scanf("%d%d",&arrival[i],&burst[i]);
pid[i]=i+1;
tot+=burst[i];
waiting[i]=0;
getType(i);
}
sort();
i=0;
while(i<tot)
{
	if(i>120*60)
	{
		printf("The Time was 12AM and the Online Query System has Ended\n");
		break;
	}
if(add!=n)
{
for(j=0;j<n;j++)
{
if(pre<arrival[j] && arrival[j]<=i)
{
enqueue(j);
add+=1;
waiting[j]+=i-arrival[j];
}
}
}
if(flag!=-1)
{
enqueue(flag);
flag=-1;
}
k=dequeue();
pre=i;
if((burst[k]-completion[k])>qat)
{
completion[k]+=qat;
i+=qat;
flag=k;
}
else
{
i+=(burst[k]-completion[k]);
completion[k]+=(burst[k]-completion[k]);
}
cal(pre,i);
}
printf("Pid\tAT\tBT\tWT\tCT\tTAT\tType Of Request\n");
for(i=0;i<add;i++)
{
	totwat+=waiting[i];  
	tottat+=(waiting[i]+burst[i]); 
printf("%d\t%d\t%d\t%d\t%d\t%d\t",pid[i],arrival[i],burst[i],waiting[i],(arrival[i]+burst[i]+waiting[i]),(burst[i]+waiting[i]));
switch(type[i])
{
	case 1:printf("Faculty Request\n");break;
	case 2:printf("Student Request\n");break;
}
}
}
