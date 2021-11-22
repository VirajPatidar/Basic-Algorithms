#include<stdio.h>
int i,j,counter=0,no,x,y,n,flag,bin[100],z,sum,k;
char a[100];
int dec(int x,int y);
void binary(int n);
void main()
{
	printf("Enter the TCP header\n");
	scanf("%s",a);

	printf("Source Port: %d\n",dec(0,4));
	printf("Destination Port: %d\n",dec(4,8));
	printf("Sequence Number: %d\n",dec(8,16));
	printf("Acknowledgement Number: %d\n",dec(16,24));
	printf("Header Length: %d Bytes\n",4*dec(24,25));

    flag=dec(26,28);
	binary(flag);

    printf("Reserved Bits: %d + %d%d\n",dec(25,26),bin[0],bin[1]);

    if(bin[2] == 1)
        printf("Urgent Pointer is valid\n");
    if(bin[3] == 1)
        printf("Acknowledgement Number is valid\n");
    if(bin[4] == 1)
        printf("Packet needs to be delivered to the receiving application as soon as possible\n");
    if(bin[5] == 1)
        printf("Sender is aborting the connection\n");
    if(bin[6] == 1)
        printf("Sender is attempting to Synchronize Sequence Numbers\n");
    if(bin[7] == 1)
        printf("No more Data from Sender\n");

	printf("Window Size: %d\n",dec(28,32));
	printf("Header Checksum: %d\n",dec(32,36));
	printf("Urgent Pointer: %d\n",dec(36,40));
}

int dec(int x,int y)
{    sum=0;k=1;
   for(i=y-1;i>=x;i--)
    {
       if(a[i]>='0'&&a[i]<='9')
          no=a[i]-'0';
        if(a[i]>='A'&&a[i]<='F')
          no=a[i]-55;
		sum=sum+k*no;
    	k*=16;
    }
    z=sum;
    return z;
}
void binary(int n)
{
	for(i=0;i<8;i++)
		bin[i]=0;
	i=7;
	while(n)
	{
         bin[i--]= n % 2;
         n=n / 2;
    }
}
