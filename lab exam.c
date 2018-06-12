/*
 * lab exam.c
 * 
 * Copyright 2018  <examuser@09CPU0247L>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>
#include <stdlib.h>

struct book
{
	int book_id;
	char title[50];
	float price;
	float discount;
}p;

void read(struct book *);
void choice(struct book *);
void price(struct book *,int,int);
int main(int argc, char **argv)
{
	FILE *fp;
 
fp=fopen("book.txt","w");
if(fp==NULL)
{
	printf("error \n");
	exit(1);
}
else
{
	fprintf(&p,sizeof(struct book),1,fp);
}



	struct book p[5];
	read(p);
	choice(p);
	
	
	return 0;
}
void read(struct book *p)
{
	int i;
	for(i=0;i<5;i++)
	{
		printf("enter book_id,book title,book price,book discount/n");
		scanf("%d",&p[i].book_id);
		scanf("%s",p[i].title);
		scanf("%f",&p[i].price);
		scanf("%f",&p[i].discount);
	}
	
}
void choice(struct book *p)
{
	int idc,t=0,i;
	static int count;

	
	while(t==0)
	{
		
			printf("enter bookid /n");
	        scanf("%d",&idc);
	        for(i=0;i<5;i++)
	        {
			if(idc==p[i].book_id)
			{
				printf("enter no of books you want /n");
				scanf("%d",&count);
				printf("enter 1 to exit or 0 to choose another book/n");
				scanf("%d",&t);
				if(t==1)
				{
					printf("total no of books selected by the customer is %d\n",count);
					price(p,count,i);
				}
				else if(t==0)
				{
					
				}
				
				
					
			}
		}
	}
}
void price(struct book *p,int count,int i)
{
	static float price;
	price=p[i].price*count-p[i].discount*count;
	printf("the total price is %f \n",price);
}




	
