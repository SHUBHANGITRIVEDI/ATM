#include <stdio.h>

int amtwit , amtdep ,ot ;
//amtwit is for amount withdraw
//amtdep is for amount deposit
//ot is for other transation
float bal = 0; // initial balance to be zero
int mob; //VARIABLE FOR MOBILE NUMBER
int att; //VARIABLE FOR AMOUNT TO TRANSFER

struct benef
{
char name[50]; //NAME OF BENFICIARY
int acn; //ACCOUNT NUMBER
int ifsc;  // IFSC CODE
};

struct benef b; // STRUCTURE VARIABLE

void transaction()
{
  int o;
  printf("\a\n|ENTER ANY ONE OPTION|\n\n");
  printf("PRESS 1 TO WITHDRAW\n");
  printf("PRESS 2 TO DEPOSIT\n");
  printf("PRESS 3 TO CHECK BALANCE\n");
  printf("PRESS 4 TO PERFORM ONLINE TRANSACTION\n");
  scanf("%d",  &o);

  switch(o)
  {
    case 1:
    // first option should be withdraw

    printf("\aPLEASE ENTER AMOUNT TO WITHDRAW: ");
    scanf("%d", &amtwit);
    if(amtwit > bal)
    {
       printf("BALANCE:%f\n",bal);
      printf("\aYOU DO NOT HAVE SUFFICIENT AMOUNT IN YOUR ACCOUNT.");
      // ask them for another transaction
      printf("\a\n\nWOULD YOU LIKE TO DO ANOTHER TRANSACTION?\nPRESS 1 TO PROCEED AND PRESS 2 TO EXIT\n\n");
      scanf("%d", &ot);
      if(ot == 1)
      {
	// call our transaction method here
	  transaction();
      }
      else
          printf("\aTHANK YOU FOR BANKING WITH US! TAKE YOUR ATM CARD BACK");
    }
    else
        {
      // this means account has something
      // so withdraw amount and update the balance variable
      bal = bal - amtwit;

      printf("\aYOU HAVE WITHDRAWN Rs.%d/- AND YOUR NEW BALANCE IS Rs.%f/- ", amtwit, bal);

      // request for another transaction
      printf("\a\n\nWOULD YOU LIKE TO DO ANOTHER TRANSACTION?\nPRESS 1 TO PROCEED AND PRESS 2 TO EXIT\n\n");
      scanf("%d", &ot);
      if(ot == 1)
        {
	     transaction();     // call our transaction method here
        }
      else
          printf("\aTHANK YOU FOR BANKING WITH US! TAKE YOUR ATM CARD BACK");
    }

    break;

    case 2:         // DEPOSIT
     printf("\aENTER AMOUNT TO DEPOSIT:\n");
     scanf("%d", &amtdep);
     bal = amtdep + bal;
     printf("\aTHANK YOU VERY MUCH FOR DEPOSITING , BALANCE: %f", bal);


    // request for another transaction
      printf("\a\n\nWOULD YOU LIKE TO DO ANOTHER TRANSACTION?\nPRESS 1 TO PROCEED AND PRESS 2 TO EXIT\n\n");
      scanf("%d", &ot);
      if(ot == 1){
	// call our transaction method here
	transaction();

      }
      else
          printf("\aTHANK YOU FOR BANKING WITH US! TAKE YOUR ATM CARD BACK");
    break;

    case 3:

    // BALANCE
    printf("\aYOUR ACCOUNT BALANCE IS: %f", bal);

    // request for another transaction
      printf("\a\n\nWOULD YOU LIKE TO DO ANOTHER TRANSACTION?\nPRESS 1 TO PROCEED AND PRESS 2 TO EXIT\n\n");
      scanf("%d", &ot);
      if(ot == 1){
                                        // call our transaction method here
	transaction();
      }
      else
        printf("\aTHANK YOU FOR BANKING WITH US! TAKE YOUR ATM CARD BACK");

    break;

    case 4:

        printf("\n||**||WELCOME TO JIITBI ONLINE TRANSACTION PORTAL||**||\n\n");
        printf("\aENTER MOBILE NUMBER LINKED WITH YOUR BANK ACCOUNT *FOR VERIFICATION*:\n");
        scanf("%d",&mob);
        printf("\a||ENTER BENEFICIARY DETAILS||\n\n ");
        printf("\aENTER ACCOUNT NUMBER:\n");
        scanf("%d",&b.acn);
        printf("\aENTER NAME:\n");
        fflush(stdin);
        gets(b.name);
        printf("\aENTER IFSC CODE:\n");
        scanf("%d",&b.ifsc);
        printf("\nBALANCE => %f\n",bal);
        printf("\aENTER THE AMOUNT TO TRANSFER:\n");
        scanf("%d",&att);
        if(att>bal)
        {
          printf("\aBALANCE => %f\n",bal);
          printf("\aYOU DO NOT HAVE SUFFICIENT AMOUNT IN YOUR ACCOUNT.");
          printf("\a\n\nWOULD YOU LIKE TO DO ANOTHER TRANSACTION?\nPRESS 1 TO PROCEED AND PRESS 2 TO EXIT\n\n");
          scanf("%d", &ot);
          if(ot == 1)
             transaction();
          else
          printf("\aTHANK YOU FOR BANKING WITH US! TAKE YOUR ATM CARD BACK");        }
        else
        {
            bal=bal-att;
            printf("\n\aAMOUNT TRANSFERED => %d\nBALANCE => %f\n\n",att,bal);
            printf("\n\nWOULD YOU LIKE TO DO ANOTHER TRANSACTION?\nPRESS 1 TO PROCEED AND PRESS 2 TO EXIT\n\n");
          scanf("%d", &ot);
          if(ot == 1)
             transaction();
          else
          printf("\aTHANK YOU FOR BANKING WITH US! TAKE YOUR ATM CARD BACK");        }

    break;

    default:
        printf("\aYOU HAVE ENTERED A WRONG CHOICE.\n");
        printf("WOULD YOU LIKE TO TRY AGAIN:\n");
        printf("PRESS 1 TO PROCEED AND PRESS 2 TO EXIT\n\n");
        scanf("%d", &ot);
           if(ot == 1)
             transaction();
           else
          printf("\aTHANK YOU FOR BANKING WITH US! TAKE YOUR ATM CARD BACK.");
  }
}

int main()
{

  int n,pin;//n for user entry , pin for four digit pin in case 2
  char ch; // for atm card
  int pass;  // for first pass
  int pass1; // for reenter pass
  int retry=1; //  for while loop condition

  printf("||*|*|*|*|*|| WELCOME TO JIIT BANK OF INDIA ||*|*|*|*|*||\n\n");
  printf("INSERT YOUR ATM CARD AND PRESS 'Y' TO CONTINUE\n");
  scanf("%c",&ch);
  if(ch=='Y'||ch=='y')
    {
       printf("\aPRESS 1 IF YOU ARE A NEW USER\nPRESS 2 IF YOU ARE AN EXISTING USER\n");
       scanf("%d",&n);

       if(n==1){
           while(retry){
           printf("\n\aENTER YOUR PIN\n");
           scanf("%d",&pass);
           printf("\n\aREENTER YOUR PIN\n");
           scanf("%d",&pass1);
           if(pass==pass1)
           {
               retry=0;
           }
           else
           {
               printf("\n\nWRONG PIN PLEASE TRY AGAIN\n");
               retry=1;
           }

       }
       transaction();}
     else if(n==2)
     {

     while (pin != 1520)
	{
		printf("ENTER YOUR SECRET PIN NUMBER:");
		scanf("%d", &pin);
		if (pin != 1520)
		printf("PLEASE ENTER VALID PASSWORD\n");
	}
        transaction();
    }     else
     {
         printf("\a\nYOU HAVE ENTERED A WRONG CHOICE. TAKE YOUR ATM CARD BACK AND TRY AGAIN .");
     }

}
}
