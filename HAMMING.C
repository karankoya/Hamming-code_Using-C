#include<stdio.h>
#include<conio.h>

void main()
{
	int data[10];
	int datarec[10],c = -1,c0,c1,c3,i;

	clrscr();

	printf("\nEnter your 4 bit message:- ");
	scanf("%d",&data[2]);
	scanf("%d",&data[4]);
	scanf("%d",&data[5]);
	scanf("%d",&data[6]);

	//calculating parity
	data[0] = data[2]^data[4]^data[6];  //p1 = xor(3,5,7)
	data[1] = data[2]^data[5]^data[6];  //p2 = xor(3,6,7)
	data[3] = data[4]^data[5]^data[6];  //p3 = xor(5,6,7)

	printf("\nEncoded Data Strings:- \n");
	for(i = 0;i<7;i++)
	{
		printf("%d\t",data[i]);
	}
	printf("\n\n");
	printf("\nEnter received data bits:- ");
	for(i=0;i<7;i++)
	{
		scanf("%d",&datarec[i]);
	}

	c0 = datarec[6]^datarec[4]^datarec[2]; //c0 = xor(3,5,7)
	c1 = datarec[6]^datarec[5]^datarec[2]; //c1 = xor(3,6,7)
	c3 = datarec[6]^datarec[5]^datarec[4]; //c3 = xor(5,6,7)

	if(c0 != datarec[0])
	{
		printf("\nIN C0\n");
		if(c3 != datarec[3])
		{
			if(c1 != datarec[1])
			{
				c = 6;
			}
			else
			{
				c = 4;
			}
		}
		else if(c1 != datarec[1])
		{
			c = 1;
		}
		else
		{
			c = 0;
		}
	}
	else if(c1 != datarec[1])
	{
		printf("\nIN C1\n");
		if(c3 != datarec[3])
		{
			c = 6;
		}
		else
		{
			c = 1;
		}
	}
	else if(c3 != datarec[3])
	{
		c = 3;
	}

	if(c == -1)
	{
		printf("\nNo errors\n");
	}
	else
	{
		printf("\nError on position: %d",c);

		printf("\nSent data:- \n");
		for(i = 0; i<7;i++)
		{
			printf("%d\t",data[i]);
		}

		printf("\nReceived data:- \n");
		for(i = 0; i<7; i++)
		{
			printf("%d\t",datarec[i]);
		}

		printf("\nCorrect data is:- \n");
		//if errorneous bit is 0, we will compliment the bit and vice versa


		if(datarec[c] == 0)
		{
			datarec[c] = 1;
		}
		else
		{
			datarec[c] = 0;
		}

		for(i=0;i<7;i++)
		{
			printf("%d\t",datarec[i]);
		}
	}
	getch();
}