#include<stdio.h>
void main() {
    int data[11];
    int recdata[11],c,c1,c2,c3,c4,i;

    printf("Enter 7 bits of data one by one\n");
    scanf("%d",&data[8]);
    scanf("%d",&data[6]);
    scanf("%d",&data[5]);
    scanf("%d",&data[4]);
    scanf("%d",&data[2]);
    scanf("%d",&data[1]);
    scanf("%d",&data[0]);

    data[10]=data[8]^data[6]^data[4]^data[2]^data[0];
	data[9]=data[8]^data[5]^data[4]^data[1]^data[0];
	data[7]=data[6]^data[5]^data[4];
	data[3]=data[2]^data[1]^data[0];
	printf("The redundant bits are:\n");
	printf("%d %d %d %d",data[10],data[9],data[7],data[3]);


	printf("\nHamming code for the given data is\n");
	for(i=0;i<11;i++)
        printf("%d",data[i]);

    printf("\n\nEnter received data bits one by one\n");
    for(i=0;i<11;i++)
        scanf("%d",&recdata[i]);


    c1=recdata[10]^recdata[8]^recdata[6]^recdata[4]^recdata[2]^recdata[0];
	c2=recdata[9]^recdata[8]^recdata[5]^recdata[4]^recdata[1]^recdata[0];
	c3=recdata[7]^recdata[6]^recdata[5]^recdata[4];
	c4=recdata[3]^recdata[2]^recdata[1]^recdata[0];
	c=c4*8+c3*4+c2*2+c1 ;

	printf("The syndrome bits are:\n");
    printf("%d %d %d %d",c4,c3,c2,c1);

    if(c==0&&recdata[10]==data[10]&&recdata[9]==data[9]&&recdata[7]==data[7]&&recdata[3]==data[3]){
		printf("\nNo error while transmission of data\n");
    }
	else{
		printf("\nError on position %d",c);
		printf("\nData sent : ");
        for(i=0;i<11;i++)
        	printf("%d",data[i]);
		printf("\nData received : ");
        for(i=0;i<11;i++)
        	printf("%d",recdata[i]);
		printf("\nCorrect message is\n");
		if(recdata[11-c]==0)
			recdata[11-c]=1;
        else
			recdata[11-c]=0;

		for (i=0;i<11;i++) {
			printf("%d",recdata[i]);
		}
	}
}