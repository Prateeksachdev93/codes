/*The following program checks whether a number is armstrong number or not and also displays all armstrong numbers
from 1 to 1000. Armstrong numbers are such numbers whose sum of the cubes of digits is equal to the number itself.
For Example
371 is an Armstrong number
371=3*3*3+7*7*7+1*1*1
*/
#include<stdio.h>

#include<math.h>
int main()
{
int numcheck;
int choice;
int rem;
int sum;
int temp;
printf("Enter Choice 1 to check whether a number is armstrong or not and Choice 2 to display all armstrong numbers from 1 to 1000\n");
scanf("%d",&choice);//It's a menu driven program and we work as per user's choice
switch(choice)
{
case 1:
    printf("Enter the number\n");
    scanf("%d",&numcheck);
    temp=numcheck;/*We create a temporary copy of the number we will require to divide the number zero which changes it
    and we need the actual number to compare after the loop operations.*/
    sum=0;//variable to hold the sum of cubes of digits
    while(temp>0)
    {
        rem=temp%10;//We find the digit at last place by finding the remainder after division by 10
        sum=sum+rem*rem*rem;
        temp=temp/10;
    }
    if(sum==numcheck)//Finally we check if the sum of the cubes of the digits equals the number or not
        printf("The Number is an armstrong number\n");
    else
        printf("The Number is not an armstrong number\n");
    break;
case 2:
    for(numcheck=1;numcheck<=1000;numcheck++)
    {//A loop which allows us to move through all numbers from 1 to 1000
    //Now we perform the same operations on all numbers
    temp=numcheck;
    sum=0;
    while(temp>0)
    {
        rem=temp%10;
        sum=sum+rem*rem*rem;
        temp=temp/10;
    }
    if(sum==numcheck)
        printf("The Number %d is an armstrong number\n",numcheck);

    }
break;
}

return 0;
}
/*A sample run of the program was carried out and it was found to give result as
Enter Choice 1 to check whether a number is armstrong or not and Choice 2 to display all armstrong numbers from 1 to 1000
2
The Number 1 is an armstrong number
The Number 153 is an armstrong number
The Number 370 is an armstrong number
The Number 371 is an armstrong number
The Number 407 is an armstrong number
*/