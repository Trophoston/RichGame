#include <stdio.h>
#include <time.h>
#include<stdlib.h>
int bankc=500, cashc=500, businessc=0, taxc, incomec, dayc=0, inote[10];

void startuping()
{
  taxc = rand()%10;
  dayc = dayc + 1;
  inote[3] = rand()%10; //businessc tax
  inote[4] = rand()%10; //bankc tax
  incomec = rand()%10;

  if(taxc >= incomec){cashc = cashc + (incomec - taxc);}
  else{cashc = cashc + incomec;
       for(int i=1;i<=5;i++)
         {if(inote[i] >= incomec)
         {
           inote[i] = 0;
         }
        }
    }

  printf("taxc = %d \ndayc = %d\ninvestment tax = %d\nbusinessc tax = %d\nbankc tax = %d\nincomec = %d\n\n",taxc,dayc,inote[2],inote[3],inote[4],incomec);
}

void bank()
{
  printf("your bank balance is %d coin\nwhat you want to do?\nA : deposit\nB : withdraw\n\nInput : ",bankc);

  char bnote;
  scanf("%c",&bnote);

  if(bnote == 'a'||bnote == 'A')
  {
    printf("\nHow much you want to deposit : ");
  scanf("%d",&inote[0]);
  if(cashc < (inote[0] + inote[4]))
  {
    bankc = bankc + inote[0];
    cashc = cashc - (inote[0] + inote[4]);
    printf("deposit successful! \nNow you have %d cash and %d bank balance",cashc,bankc);
  }
  else
  {
    printf("Sorry wrong amount please try again\n");
  }
    }
  
  else if(bnote == 'b' || bnote == 'B')
  {
    printf("\nHow much you want to withdraw : ");
    scanf("%d",&inote[0]);
  if(inote[0] < (inote[0] + inote[4]))
  {
    bankc = bankc - inote[0];
    cashc = cashc + (inote[0] - inote[4]);
    printf("deposit successful!  \nNow you have %d cash and %d bank balance",cashc,bankc);
  }
  else
  {
    printf("Sorry wrong amount please try again\n");
  }
   }

}

void bet()
{
  printf("your bank balance is %d coin\nwhat how much want to bet?\n\nInput : ",bankc);

  scanf("%d",&inote[0]);

   if(cashc > inote[0])
  {
    int betran=rand()%10;
    if(betran <= 4)
    {
      cashc = cashc + inote[0];
      printf("You won %d coin!\nNow you have %d coin",inote[0]*2,cashc);
    }
    else
    {
      cashc = cashc - inote[0];
      printf("You loose %d coin\nTry again later!\nNow you have %d coin",inote[0],cashc);
    }
  }
  
}

void business()
{
  printf("your business balance is %d unit\nwhat how much unit you want to buy?(1 unit = 3 coin)\n\nInput : ",businessc);

  scanf("%d",&inote[0]);

  if(cashc > (inote[0]*3))
  {
    businessc = businessc + inote[0];
    cashc = cashc - (inote[0]*3 + inote[3]);
    printf("-%d deposit\n-%d tax\ntotal : -%d\ndeposit successful! \nNow you have %d cash and %d business unit!",inote[0]*3,inote[3],inote[0]*3+inote[3],cashc,businessc);
  }
}

int main (void) 
{
  
  srand(time(0));
  startuping();
  inote[9] = 0;
  char gate;

  for(;;)
  {
    if(bankc == 250)
    {
      break;
      printf("\n\n=== Victory! ===");
    }
    printf("\n\nWhat do you want to go?\nA : bank\nB : investment\nC : bet\nD : business\n\nInput : ");
    scanf("%c",&gate);
      
    if(gate == 'A' || gate == 'a')
    {
      bank();
    }
    else if(gate == 'B' || gate == 'b')
    {
      bet();
    }
    else if(gate == 'C' || gate == 'c')
    {
       business();
    }
      else{}
  }
  
  return 0;
}