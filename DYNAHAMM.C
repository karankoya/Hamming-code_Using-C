#include<stdio.h>
#include<conio.h>
#include<math.h>

int* forThreeparity(int *datarec, int length)
{
	int c0 = 0,c1 = 0,c3 = 0,c = -1;

	if(length == 6)
	{
	       c0 = datarec[2]^datarec[4];	//p0 = xor(3,5)
	       c1 = datarec[2]^datarec[5];	//p1 = xor(3,6)
	       c3 = datarec[4]^datarec[5];	//p3 = xor(5,6)

	       if(c0 != datarec[0])
	       {
			if(c1 != datarec[1])
			{
				if(c3 != datarec[3])
				{
					c = 4;
				}
				else
				{
					c = 2;
				}
			}
			else
			{
				if(c3 != datarec[3])
				{
					c = 4;
				}
				else
				{
					c = 0;
				}
			}
	       }
	       else if(c1 != datarec[1])
	       {
			if(c3 != datarec[3])
			{
				c = 5;
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
	}
	else
	{
	       c0 = datarec[2]^datarec[4]^datarec[5];	//p0 = xor(3,5,7)
	       c1 = datarec[2]^datarec[5]^datarec[6];	//p1 = xor(3,6,7)
	       c3 = datarec[4]^datarec[5]^datarec[6];	//p3 = xor(5,6,7)

	       if(c0 != datarec[0])
	       {
			if(c3 != datarec[1])
			{
				if(c1 != datarec[3])
				{
					c = 6;
				}
				else
				{
					c = 4;
				}
			}
			else
			{
				if(c1 != datarec[1])
				{
					c = 2;
				}
				else
				{
					c = 0;
				}
			}
	       }
	       else if(c1 != datarec[1])
	       {
			if(c3 != datarec[3])
			{
				c = 5;
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

	}

	if(datarec[c] == 0)
	{
		datarec[c] = 1;
	}
	else
	{
		datarec[c] = 0;
	}

	return datarec;
}
int* forFourparity(int *datarec, int length)
{
	int c0 = 0, c1 = 0, c3 = 0, c7 = 0,c = -1;

	if(length == 9)
	{
		c0 = datarec[2]^datarec[4]^datarec[6]^datarec[8]; //p1 = xor(3,5,7,9)
		c1 = datarec[2]^datarec[5]^datarec[6];            //p2 = xor(3,6,7)
		c3 = datarec[4]^datarec[5]^datarec[6];            //p4 = xor(5,6,7)
		c7 = datarec[8];                                  //p8 = xor(9)

		if(c0 != datarec[0])
		{
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
				c = 2;
			}
			else if(c7 != datarec[7])
			{
				c = 8;
			}
			else
			{
				c = 0;
			}
		}
		else if(c1 != datarec[1])
		{
			if(c3 != datarec[3])
			{
				c = 5;
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
		else if(c7 != datarec[7])
		{
			c = 7;
		}
	}
	else if(length == 10)
	{
		c0 = datarec[2]^datarec[4]^datarec[6]^datarec[8]; //p1 = xor(3,5,7,9)
		c1 = datarec[2]^datarec[5]^datarec[6]^datarec[9]; //p2 = xor(3,6,7,10)
		c3 = datarec[4]^datarec[5]^datarec[6];            //p4 = xor(5,6,7)
		c7 = datarec[8]^datarec[9];                          //p8 = xor(9,10)

		if(c0 != datarec[0])
		{
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
				c = 2;
			}
			else if(c7 != datarec[7])
			{
				c = 8;
			}
			else
			{
				c = 0;
			}
		}
		else if(c1 != datarec[1])
		{
			if(c3 != datarec[3])
			{
				c = 5;
			}
			else if(c7 != datarec[7])
			{
				c = 9;
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
		else if(c7 != datarec[7])
		{
			c = 7;
		}
	}
	else if(length == 11)
	{
		c0 = datarec[2]^datarec[4]^datarec[6]^datarec[8]^datarec[10]; //p1 = xor(3,5,7,9,11)
		c1 = datarec[2]^datarec[5]^datarec[6]^datarec[9]^datarec[10]; //p2 = xor(3,6,7,10,11)
		c3 = datarec[4]^datarec[5]^datarec[6];            	      //p4 = xor(5,6,7)
		c7 = datarec[8]^datarec[9]^datarec[10];                          //p8 = xor(9,10,11)

		if(c0 != datarec[0])
		{
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
			else if(c1 != datarec[1] && c7 != datarec[7])
			{
				c = 10;
			}
			else if(c1 != datarec[1])
			{
				c = 2;
			}
			else if(c7 != datarec[7])
			{
				c = 8;
			}
			else
			{
				c = 0;
			}
		}
		else if(c1 != datarec[1])
		{
			if(c3 != datarec[3])
			{
				c = 5;
			}
			else if(c7 != datarec[7])
			{
				c = 9;
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
		else if(c7 != datarec[7])
		{
			c = 7;
		}
	}

	if(datarec[c] == 0)
	{
		datarec[c] = 1;
	}
	else
	{
		datarec[c] = 0;
	}

	return datarec;
}

void main()
{
	int data[11]={0,0,0,0,0,0,0,0,0,0,0}, input[7];
	int datarec[11]={0,0,0,0,0,0,0,0,0,0,0};
	int n = 0,i = 0,j=0,k=0,parity = 0,length = 0;
	int* ptr;

	clrscr();

	printf("\nLength of the data(must be between 3 to 7):- ");
	scanf("%d",&n);

	for(i = 0;i<n;i++)
	{
		printf("\nEnter element:- ");
		scanf("%d",&input[i]);
	}
	i = 0;
	while(!(pow(2,i) >= (parity+n+1)))  //2^p >= m + r + 1
	{
		parity++;
		i++;
	}

	length = parity + n;

	printf("\nLength = %d\n",length);

	for(i = 0; i<length; i++)
	{
		if(i == ((int)pow(2,k)-1))
		{
			data[i] = 0;
			k = k + 1;
		}
		else
		{
			data[i] = input[j];
			j = j + 1;
		}
	}

	data[0] = data[2]^data[4]^data[6]^data[8]^data[10]; // c1 = xor(3,5,7,9,11)
	data[1] = data[2]^data[5]^data[6]^data[9]^data[10]; // c2 = xor(3,6,7,10,11)
	data[3] = data[4]^data[5]^data[6]; // c3 = xor(5,6,7)
	data[7] = data[8]^data[9]^data[10]; // c4 = xor(9,10,11)

	printf("\nHamming code:- \n");
	for(i=0;i<length;i++)
	{
		printf("%d\t",data[i]);
	}

	printf("\n-------------------RECEIVER SIDE---------------------\n");

	for(i = 0; i<length; i++)
	{
		printf("\nEnter receievd element:- ");
		scanf("%d",&datarec[i]);
	}

	printf("\nReceived Data:- \n");

	for(i = 0; i<length; i++)
	{
		printf("%d\t",datarec[i]);
	}

	if(length == 6 || length == 7)
	{
		ptr = forThreeparity(datarec,length);
	}
	if(length >= 9 && length <= 11)
	{
		ptr = forFourparity(datarec, length);
	}
	printf("\nCorrect data element:- \n");
	for(i = 0; i<length; i++)
	{
		printf("%d\t",ptr[i]);
	}

	getch();
}