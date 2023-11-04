#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
int numorsp(char joueur[108][20],int nb);
void remplir1(char uno[108][20],char joueur[108][20],int n,int nb) ;
void supprimer( char uno[108][20],int x,int n);
void power2(char uno[108][20],char c[108][20],char joueur[108][20],char carte[20],int *o,int *n,int *nb,int zh) ;
int resul( char joueur[108][20], int score,int nb);
void game( int jeu , char uno[108][20],char joueur1[54][20],char joueur2[54][20],int n,int nb1,int nb2 );
void affiche(char joueur[108][20],int nb);
int numor(char joueur[108][20],char c[10],int nb);
void power(char uno[108][20],char c[108][20],char joueur[108][20],char carte[20],int *o,int *n,int *nb,int z);
void ajout(char uno[108][20], char joueur[108][20],int nm,int n,int nb);
int valid(char x[108][20],char y[20], int v);
int main()
{  int nb1=7;
int nb2=7;
    int y,jeu=0,n=108;
char joueur1[54][20];
char joueur2[54][20] ;
   char uno[108][20]={"0 bleu", "1 bleu","1 bleu","2 bleu","2 bleu","3 bleu","3 bleu","4 bleu","4 bleu","5 bleu","5 bleu","6 bleu","6 bleu","7 bleu","7 bleu","8 bleu","8 bleu","9 bleu","9 bleu",
"0 rouge","1 rouge","1 rouge","2 rouge","2 rouge","3 rouge","3 rouge","4 rouge","4 rouge","5 rouge","5 rouge","6 rouge","6 rouge","7 rouge","7 rouge","8 rouge","8 rouge","9 rouge","9 rouge",
"0 vert","1 vert","1 vert","2 vert","2 vert","3 vert","3 vert","4 vert","4 vert","5 vert","5 vert","6 vert","6 vert","7 vert","7 vert","8 vert","8 vert","9 vert","9 vert",
"0 jaune","1 jaune","1 jaune","2 jaune","2 jaune","3 jaune","3 jaune","4 jaune","4 jaune","5 jaune","5 jaune","6 jaune","6 jaune","7 jaune","7 jaune","8 jaune","8 jaune","9 jaune","9 jaune",
"|+2 bleu","|+2 bleu","|+2 rouge","|+2 rouge","|+2 vert","|+2 vert","|+2 jaune","|+2 jaune","inv bleu","inv bleu","inv rouge","inv rouge","inv vert","inv vert","inv jaune","inv jaune",
"passe bleu","passe bleu","passe rouge","passe rouge","passe vert","passe vert","passe jaune","passe jaune","+4","+4","+4","+4","Joker","Joker","Joker","Joker"};
    printf("| |-------------------------------| |\n");
    printf("| |-------------------------------| |\n");
    printf("| |     BIENVENUE AU JEU UNO      | |\n");
    printf("| |-------------------------------| |\n");
    printf("| |-------------------------------| |\n");
 do{
    printf("| |  Veuillez choisir une option  | |\n");
    printf("| |-------------------------------| |\n");
    printf("| |-------------------------------| |\n");
    printf("| |   1-Jouer contre la machine   | |\n");
    printf("| |     2-Jouer 1 contre 1        | |\n");
    printf("| |-------------------------------| |\n");
    printf("| |-------------------------------| |\n");
    printf("| |       3-Quitter               | |\n");
    printf("| |-------------------------------| |\n");
    printf("| |-------------------------------| |\n");

    
   
    


    scanf("%i",&jeu);
    }while (jeu<=0|| jeu>3);
game(jeu,uno,joueur1,joueur2,n,nb1,nb2) ;}
void game( int jeu , char uno[108][20],char joueur1[54][20],char joueur2[54][20],int n,int nb1,int nb2 )

{
int v,z,y,b,x,tour=0,score1=0,score2=0 ;
char g='O',u,s,nom1[10],nom2[10] ;
  char carte[20];
  time_t t1,t2;
  int o=1 ;
  srand(time(NULL));
switch(jeu)
{


case 1 : 	{printf("| |-------------------------------| |\n");
            printf("| |--------------------------------| |\n");
            printf("| |            BIENVENUE           | |\n");
            printf("| | mode du jeu contre la machine  | |\n");
            printf("| |-------------------------------| |\n");
            printf("| |    Taper le symbore * pour quitter     | |\n");
            do 
            {
			
            printf("| |     Taper votre Nom svp :       | | \n");
            scanf("%s",&nom1);
            } while (nom1=="");
    do {nb1=7; nb2=7;n=108;
	       remplir1(uno,joueur1,n,nb1);
        n=n-7;
        remplir1(uno,joueur2,n,nb2);
        n=n-7;
        b=rand()%n ;
        strcpy(carte,uno[b]);
        supprimer(uno,b,n);
        n--;
if (strcmp(carte,"Joker")==0||strcmp(carte,"+4")==0 )
        {switch(rand()%4+10);
            
			case 10 : strcpy(carte," rouge") ;
				break;
            case 11 : strcpy(carte," bleu") ; break;
             case 12 : strcpy(carte," jaune") ;break;
            case 13 : strcpy(carte," vert") ;break;} 
	       
	    while(nb1!=0&& nb2!=0 && v!=100)
	    {
         if (o %2==0) //Oridinateur
         {    
		  printf("| |score du %s = %i | |\n",nom1,score1);
             printf("| |score de  L'ordinateur = %i | |\n\n",score2); 
             printf("| |La carte sur table = %s| | \n",carte);
             
             v=rand()%nb2;
             if ((numor(joueur2,carte,nb2)==0&&numorsp(joueur2,nb2)==0))
             { v=99;
			 }
             while ((v!=99)&&((valid(joueur2,carte,v)==0)||((numor(joueur2,carte,nb2)==1&&(strcmp(joueur2[v],"Joker")==0 ||(strcmp(joueur2[v],"+4")==0))))) ){
             v=rand()%nb2;} 
             
         if (v==99)
   {   ajout( uno,joueur2,1,n,nb2);
   n=n-1;
   nb2=nb2+1;
            if (valid(joueur2,carte,nb2-1)==1)
            { 
          power2(uno,joueur2,joueur1,carte,&o,&n,&nb1,nb2-1);
            supprimer(joueur2,nb2-1,nb2);
                nb2--;
            } else 
            {o=o+1;}
   }
   else
   {           if ((numor(joueur2,carte,nb2)==1) &&((strcmp(joueur2[v],"Joker")==0) ||(strcmp(joueur2[v],"+4")==0)))
               {
                       ajout(uno,joueur2,2,n,nb1);
                       nb1=nb1+2;
                       n=n-2;
                       o++;
               }
               else
               {power2(uno,joueur2,joueur1,carte,&o,&n,&nb1,v);
                   supprimer(joueur2,v,nb2);
                   nb2--;
               }
    }
       if (nb2==1)
		 { printf(" | |    UNO    ||  \n");
				}         
				} //o
        
        
        
        
   //joueur    
   else {printf("| |score du %s = %i | |\n",nom1,score1);
          printf("| |score de L'ordinateur =' = %i | |\n\n",score2);
       printf("| |    Les cartes du %s sont :     | |\n",nom1);

        affiche(joueur1,nb1);
            printf("| |La carte sur table = %s| |\n",carte);
            scanf("%i",&v);
while ((v==99&&numor(joueur1,carte,nb1)==1)||((numor(joueur1,carte,nb1)==1)&&valid(joueur1,carte,v-1)==0)&& (numorsp(joueur1,nb1)==1))
{printf("| |vous avez une solution : | |\n");
        printf("| |Taper votre choix  :| |\n");
        printf("| |Taper 100 pour quitter : | |\n");
                        scanf("%i",&v);}
                        while (v==99&&numor(joueur1,carte,nb1)==0&&numorsp(joueur1,nb1)==1)
                        {printf("| |vous avez une solution :| |\n");
        printf("| |Taper votre choix  :| |\n");
        printf("| |Taper 100 pour quitter | |\n");
                        scanf("%i",&v);}
    if (v==99)
   {   ajout( uno,joueur1,1,n,nb1);
   n--;
   nb1++;
   printf(" | | votre Nouvelle carte est %s  |   \n",joueur1[nb1-1]);
            if (valid(joueur1,carte,nb1-1)==1)
            {
          power(uno,joueur1,joueur2,carte,&o,&n,&nb2,nb1-1);
            supprimer(joueur1,nb1-1,nb1);
                nb1--;
            }
            else 
            {o=o+1;}
   }
   else
   {           if ((numor(joueur1,carte,nb1)==1) &&((strcmp(joueur1[v-1],"Joker")==0) ||(strcmp(joueur1[v-1],"+4")==0)))
               {
                       ajout(uno,joueur1,2,n,nb1);
                       nb1=nb1+2;
                       n=n-2;
                       o++;
               }
               else
               {power(uno,joueur1,joueur2,carte,&o,&n,&nb2,v-1);
                   supprimer(joueur1,v-1,nb1);
                   nb1--;
               }
    }
     if (nb1==1)
      {t1=time (NULL) ;
      t2=time (NULL);
      while(difftime(t2,t1)<=3000&&toupper(u)!='U')
    	   {  printf(". . . .");
		   t2=time (NULL);
   	        scanf("%c",&u);
	  }
	  if(toupper(u)!='U')
	     {
	                          ajout( uno, joueur1,2,n,nb1); n=n-2 ;nb1=nb1+2;
							    if(strcmp(carte,"inv bleu")==0||strcmp(carte,"inv vert")==0||strcmp(carte,"inv rouge")==0||strcmp(carte,"inv jaune")==0||strcmp(carte,"passe bleu")==0||strcmp(carte,"passe vert")==0||strcmp(carte,"passe jaune")==0&&strcmp(carte,"passe rouge")==0||carte[0]==' ')
   		{o=o+1;}}
	                          else 
	                          { printf("  ||      UNO      || \n");
							  }}       
   
   }      //j
      
              
	  } //nb+0
	  if(nb2==0)
	  {printf("l'ordinateur a gagnée ce tour !'");
	  }
	  else {printf("tu as gagnée ce tour !'");
	  }
	  tour=tour+1;
	 
score1=resul(joueur1,score1,nb1);
 
score2=resul(joueur2,score2,nb2);
printf(" voulez-vous  faire un autre tour ? \n");
       do {   printf("taper O pour oui \n ");
           printf("taper N pour non \n");
           printf("taper * pour quitter \n");
           scanf("%c",&g);
           g=toupper(g);
       } while (g!='O'&& g!='N'&& g!='*') ;
	   } while((tour<2&& g!='*') ||(g=='O'))  ;   	
	if(g=='N')
           { if (score1>score2) {printf("the winner is :Ordinateur \n");}
               else if(score2>score1){printf("the winner is :%s \n",nom1);}
                   else printf("Null");
                   printf("  | |   Au revoir   ||") ;
        
 
}
}
case 2 :
	{
	

        
        
  printf("| |----------------------------------------| |\n\n");
    printf("| |----------------------------------------| |\n\n");
    printf("| |              BIENVENUE                 | |\n\n");
    printf("| |          mode du jeu 1 contre 1        | |\n\n");
    printf("| |----------------------------------------| |\n\n");
    printf("| |    Taper le symbore 100 pour quitter     | |\n\n");
          do 
            {
			
            printf("| |     Taper le nom du joueur 1 :       | | \n");
            scanf("%s",&nom1);
            } while (nom1=="");
            do 
            {
			
            printf("| |     Taper le nom du joueur 2 :       | | \n");
            scanf("%s",&nom2);
            } while (nom2=="");
	   do {nb1=7; nb2=7;n=108;
	       remplir1(uno,joueur1,n,nb1);
        n=n-7;
        remplir1(uno,joueur2,n,nb2);
        n=n-7;
        b=rand()%n ;
        strcpy(carte,uno[b]);
        supprimer(uno,b,n);
        n--;
if (strcmp(carte,"Joker")==0||strcmp(carte,"+4")==0 )
        {switch(rand()%4+5);
            
			case 5 : strcpy(carte," rouge") ;
				break;
            case 6 : strcpy(carte," bleu") ; break;
             case 7 : strcpy(carte," jaune") ;break;
            case 8 : strcpy(carte," vert") ;break;} 
	       
	    while(nb1!=0&& nb2!=0 && v!=100)
	    {
	    
         if (o %2==0) //joueur2
         {   printf("| |score du %s = %i | |\n",nom1,score1);
             printf("| |score du %s = %i | |\n\n",nom2,score2); 
             printf("| |    Les cartes du %s sont      | |\n \n",nom2);
        affiche(joueur2,nb2);
             printf("| |La carte sur table = %s| |\n",carte);
             scanf("%i",&v);
while ((v==99&&numor(joueur2,carte,nb2)==1)||((numor(joueur2,carte,nb2)==1)&&valid(joueur2,carte,v-1)==0)&& (numorsp(joueur2,nb2)==1))
{       printf("| |vous avez une solution | |\n");
        printf("| |Taper votre choix | |\n");
        printf("| |Taper 100 pour quitter | |\n");
                        scanf("%i",&v);}
                        while (v==99&&numor(joueur2,carte,nb2)==0&&numorsp(joueur2,nb2)==1)
                        {printf("| |vous avez une solution | |\n");
        printf("| |Taper votre choix | |\n");
        printf("| |Taper 100 pour quitter | |\n");
                        scanf("%i",&v);}
         
         
         if (v==99)
   {   ajout( uno,joueur2,1,n,nb2);
   n--;
   nb2++;
      printf(" | | votre Nouvelle carte est %s  | |   \n",joueur2[nb2-1]);

            if (valid(joueur2,carte,nb2-1)==1)
            {
          power(uno,joueur2,joueur1,carte,&o,&n,&nb1,nb2-1);
            supprimer(joueur2,nb2-1,nb2);
                nb2--;
            } else 
            {o=o+1;}
   }
   else
   {           if ((numor(joueur2,carte,nb2)==1) &&((strcmp(joueur2[v-1],"Joker")==0) ||(strcmp(joueur2[v-1],"+4")==0)))
               {
                       ajout(uno,joueur2,2,n,nb1);
                       nb1=nb1+2;
                       n=n-2;
                       o++;
               }
               else
               {power(uno,joueur2,joueur1,carte,&o,&n,&nb1,v-1);
                   supprimer(joueur2,v-1,nb2);
                   nb2--;
               }
    }
          if (nb2==1)
      {t1=time (NULL) ;
      t2=time (NULL);
      while(difftime(t2,t1)<=3000&&toupper(u)!='U')
    	   {  printf(". . . .");
		   t2=time (NULL);
   	        scanf("%c",&u);
	  }
	  if(toupper(u)!='U')
	     {
	                          ajout( uno, joueur2,2,n,nb2); n=n-2 ;nb2=nb2+2;
							    if(strcmp(carte,"inv bleu")==0||strcmp(carte,"inv vert")==0||strcmp(carte,"inv rouge")==0||strcmp(carte,"inv jaune")==0||strcmp(carte,"passe bleu")==0||strcmp(carte,"passe vert")==0||strcmp(carte,"passe jaune")==0&&strcmp(carte,"passe rouge")==0||carte[0]==' ')
   		{o=o+1;}}
	                          else 
	                          { printf("  ||      UNO      || \n");
							  }}
		 }
        
        
        
        
   //joueur 1     
   else {printf("| |score du %s = %i | |\n",nom1,score1);
          printf("| |score du %s = %i | |\n\n",nom2,score2);
       printf("| |    Les cartes du %s sont :     | |\n",nom1);

        affiche(joueur1,nb1);
            printf("| |La carte sur table = %s| |\n",carte);
            scanf("%i",&v);
while ((v==99&&numor(joueur1,carte,nb1)==1)||((numor(joueur1,carte,nb1)==1)&&valid(joueur1,carte,v-1)==0)&& (numorsp(joueur1,nb1)==1))
{printf("| |vous avez une solution | |\n");
        printf("| |Taper votre choix | |\n");
        printf("| |Taper 100 pour quitter | |\n");
                        scanf("%i",&v);}
                        while (v==99&&numor(joueur1,carte,nb1)==0&&numorsp(joueur1,nb1)==1)
                        {printf("| |vous avez une solution | |\n");
        printf("| |Taper votre choix | |\n");
        printf("| |Taper 100 pour quitter | |\n");
                        scanf("%i",&v);}
    if (v==99)
   {   ajout( uno,joueur1,1,n,nb1);
   n--;
   nb1++;
   printf(" | | votre Nouvelle carte est %s  |   \n",joueur1[nb1-1]);
            if (valid(joueur1,carte,nb1-1)==1)
            {
          power(uno,joueur1,joueur2,carte,&o,&n,&nb2,nb1-1);
            supprimer(joueur1,nb1-1,nb1);
                nb1--;
            }
            else 
            {o=o+1;}
   }
   else
   {           if ((numor(joueur1,carte,nb1)==1) &&((strcmp(joueur1[v-1],"Joker")==0) ||(strcmp(joueur1[v-1],"+4")==0)))
               {
                       ajout(uno,joueur1,2,n,nb1);
                       nb1=nb1+2;
                       n=n-2;
                       o++;
               }
               else
               {power(uno,joueur1,joueur2,carte,&o,&n,&nb2,v-1);
                   supprimer(joueur1,v-1,nb1);
                   nb1--;
               }
    }
           
   }      
      if (nb1==1)
      {t1=time (NULL) ;
      t2=time (NULL);
      while(difftime(t2,t1)<=3000&&toupper(u)!='U')
    	   {  printf(". . . .");
		   t2=time (NULL);
   	        scanf("%c",&u);
	  }
	  if(toupper(u)!='U')
	     {
	                          ajout( uno, joueur1,2,n,nb1); n=n-2 ;nb1=nb1+2;
							  if(strcmp(carte,"inv bleu")==0||strcmp(carte,"inv vert")==0||strcmp(carte,"inv rouge")==0||strcmp(carte,"inv jaune")==0||strcmp(carte,"passe bleu")==0||strcmp(carte,"passe vert")==0||strcmp(carte,"passe jaune")==0&&strcmp(carte,"passe rouge")==0||carte[0]==' ')
   		{o=o+1;}}
	                          else 
	                          { printf("  ||      UNO      || \n");
							  }}
              
	  } //nb+0
	  if(nb2==0)
	  {printf(" %s a gagnée ce tour !'",nom2);
	  }
	  else {printf("%s  a gagnée ce tour !'",nom1);
	  }
	  tour=tour+1;
	 
score1=resul(joueur1,score1,nb1);
 
score2=resul(joueur2,score2,nb2);
printf(" voulez-vous  faire un autre tour ? \n");
       do {   printf("taper O pour oui \n ");
           printf("taper N pour non \n");
           printf("taper * pour quitter \n");
           scanf("%c",&g);
           g=toupper(g);
       } while (g!='O'&& g!='N'&& g!='*') ;
	   } while((tour<2&& g!='*') ||(g=='O'))  ;   	
	if(g=='N')
           { if (score1>score2) {printf("	le gagnant(e) est  : %s \n",nom2);}
               else if(score2>score1){printf("	le gagnant(e) est : %s \n",nom1);}
                   else printf("Nul");
               }
			   printf("  ||   au revoir     ||");    
	} // case 2
	default :
	system("exit");
	break;
} // switch
} // game

int resul( char joueur[108][20], int score,int nb)
{int i ;
    for (i=0;i<nb;i++)
    {switch(joueur[i][0])
    {case 'J':score=score+50 ; break;
     case '|':score=score+20 ;break;
     case '+':score=score+50 ;break;
     case 'p':score=score+20 ;break;
     case 'i':score=score+20 ;break;
     case '1' : score=score+1 ;break;
     case '2' : score=score+2 ;break;
     case '3' : score=score+3 ;break;
     case '4' : score=score+4 ;break;
     case '5' : score=score+5 ;break;
     case '6' : score=score+6 ;break;
     case '7' : score=score+7 ;break;
     case '8' : score=score+8 ;break;
     case '9' : score=score+9 ;break;


    }
        
    }
    return score ;}
int numor(char joueur[108][20],char c[20],int nb) //num du solu différent du joker  +4

{int w,i=0,y=0 ;
 while (i<nb&&y==0)
{
    if (valid(joueur,c,i)==1&&((strcmp(joueur[i],"Joker")!=0 )&&(strcmp(joueur[i],"+4")!=0)))
    {
        y++;
    }
    i++;
}
    return y ;
}
int numorsp(char joueur[108][20],int nb) //num du  special(joker,+4)

{int w,i=0,y=0 ;
 while (i<nb&&y==0)
{
    if ((strcmp(joueur[i],"Joker")==0 )||(strcmp(joueur[i],"+4")==0))
    {
        y++;
    }
    i++;
}
    return y ;
}

void power2(char uno[108][20],char c[108][20],char joueur[108][20],char carte[20],int *o,int *n,int *nb,int zh)
{char cl;
int x;
   if (strcmp(c[zh],"Joker")==0)
   { x=rand()%4 ;
   switch(x)
   {case 0:strcpy(carte," rouge") ;
    break;
    case 1:strcpy(carte," bleu") ;
    break ;
    case 2:strcpy(carte," vert") ;
    break;
    case 3:strcpy(carte," jaune") ;
    break;} 
   }
   else { if (strcmp(c[zh],"+4")==0)
   {ajout(uno,joueur,4,*n,*nb);
   *n=*n-4;
   *nb=*nb+4;
	x=rand()%4 ;
   switch(x)
   {case 0:strcpy(carte," rouge") ;
    break;
    case 1:strcpy(carte," bleu") ;
    break ;
    case 2:strcpy(carte," vert") ;
    break;
    case 3:strcpy(carte," jaune") ;
    break;
	}}
   else if (strcmp(c[zh],"|+2 bleu")==0){ ajout(uno,joueur,2,*n,*nb);*n=*n-2;*nb=*nb+2;strcpy(carte,c[zh]);}
   else if (strcmp(c[zh],"|+2 vert")==0){ajout(uno,joueur,2,*n,*nb);*n=*n-2;*nb=*nb+2;strcpy(carte,c[zh]);}
   else if (strcmp(c[zh],"|+2 rouge")==0){ajout(uno,joueur,2,*n,*nb);*n=*n-2;*nb=*nb+2;strcpy(carte,c[zh]);}
   else if (strcmp(c[zh],"|+2 jaune")==0){ajout(uno,joueur,2,*n,*nb);*n=*n-2;*nb=*nb+2;strcpy(carte,c[zh]);}
   		else 
{if(strcmp(c[zh],"inv bleu")!=0&&strcmp(c[zh],"inv vert")!=0&&strcmp(c[zh],"inv rouge")!=0&&strcmp(c[zh],"inv jaune")!=0&&strcmp(c[zh],"passe bleu")!=0&&strcmp(c[zh],"passe vert")!=0&&strcmp(c[zh],"passe jaune")!=0&&strcmp(c[zh],"passe rouge")!=0)
   		{*o=*o+1;strcpy(carte,c[zh]);}else {strcpy(carte,c[zh]);}}
   
       
   }
   
  
   }
       
   
   
  
   
void power(char uno[108][20],char c[108][20],char joueur[108][20],char carte[20],int *o,int *n,int *nb,int zh)
{char cl;
   if (strcmp(c[zh],"Joker")==0)
   {printf("choisir votre coleur svp  \n");
printf("taper R pour rouge  | J pour jaune  | B pour bleu | V pour verte   \n");
do {scanf("%c",&cl);}while (toupper(cl)!='J'&&toupper(cl)!='V'&&toupper(cl)!='B'&&toupper(cl)!='R');
switch(toupper(cl)){
case 'R':strcpy(carte," rouge") ;
break;
case 'B':strcpy(carte," bleu") ;
break ;
case 'V':strcpy(carte," vert") ;
break;
case 'J':strcpy(carte," jaune") ;
break;}
   }
   else { if (strcmp(c[zh],"+4")==0)
   {ajout(uno,joueur,4,*n,*nb);
   *n=*n-4;
   *nb=*nb+4;
printf("choisir votre coleur svp  \n");
printf("taper R pour rouge  | J pour jaune /n | B pour bleu | V pour vert  \n");
do {scanf("%c",&cl);}while (toupper(cl)!='J'&&toupper(cl)!='V'&&toupper(cl)!='B'&&toupper(cl)!='R');
    switch(toupper(cl)){
    case 'R':strcpy(carte," rouge") ;
    break;
    case 'B':strcpy(carte," bleu") ;
    break ;
    case 'V':strcpy(carte," vert") ;
    break;
    case 'J':strcpy(carte," jaune") ;
    break;}
	}
   else if (strcmp(c[zh],"|+2 bleu")==0){ ajout(uno,joueur,2,*n,*nb);*n=*n-2;*nb=*nb+2;strcpy(carte,c[zh]);}
   else if (strcmp(c[zh],"|+2 vert")==0){ajout(uno,joueur,2,*n,*nb);*n=*n-2;*nb=*nb+2;strcpy(carte,c[zh]);}
   else if (strcmp(c[zh],"|+2 rouge")==0){ajout(uno,joueur,2,*n,*nb);*n=*n-2;*nb=*nb+2;strcpy(carte,c[zh]);}
   else if (strcmp(c[zh],"|+2 jaune")==0){ajout(uno,joueur,2,*n,*nb);*n=*n-2;*nb=*nb+2;strcpy(carte,c[zh]);}
   		else 
{if(strcmp(c[zh],"inv bleu")!=0&&strcmp(c[zh],"inv vert")!=0&&strcmp(c[zh],"inv rouge")!=0&&strcmp(c[zh],"inv jaune")!=0&&strcmp(c[zh],"passe bleu")!=0&&strcmp(c[zh],"passe vert")!=0&&strcmp(c[zh],"passe jaune")!=0&&strcmp(c[zh],"passe rouge")!=0)
   		{*o=*o+1;strcpy(carte,c[zh]);}else {strcpy(carte,c[zh]);}}
   
       
   }
   
  
   }

void affiche(char joueur[108][20],int nb)
{int i; 
for (i=0;i<nb;i++)

{printf("| | taper %i pour choisir |   %s| | \n",i+1,joueur[i]);}

printf("| |    Taper 99 si vous n a pas du solution    | |\n");
     printf("| |    Taper votre choix svp     | |\n");




}

int valid(char x[108][20],char y[20], int v)
{ int z ;
    if (x[v][0]==y[0]|| x[v][0]=='J'||x[v][0]=='+')
    {
        z=1;

    }
    else
    {
    if(strcmp(strstr(y," "),strstr(x[v]," "))==0)
    {z=1;
    }
    else
        z=0;
    }


        return z;
}

void ajout(char uno[108][20], char joueur[108][20],int nm,int n,int nb)
{ int i,p;
        for (i=1;i<=nm;i++)

    {p=rand()%n;
    nb++;
    strcpy(joueur[nb-1],uno[p]) ;
    
    supprimer(uno,p,n);
    n--;
    }
    }


void supprimer( char uno[108][20],int x,int n)
{ int i ;
    for (i=x;i<n-1;i++)
    {
        strcpy(uno[i],uno[i+1]) ;
    }
    
}

void remplir1(char uno[108][20],char joueur[108][20],int n,int nb)
{int x,i;
    for (i=0;i<nb;i++)
  {    x=rand()%n;
  strcpy(joueur[i],uno[x]) ;
  supprimer(uno,x,n);
      n--;
  }
}
			
