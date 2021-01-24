#include <stdio.h>
#include <windows.h>

    int i, j, nombre_p, nombre_e = 0, max, exclu, need, cond=1;
    char nom_p[1000][50];//noms presidents
    int tab_cin[100];// CIN electeur
    int tab_p[2][100];//t-ableau presedent indices & conteur votes
   
   
//anas 
    void Insertion() //Insertion des nombres de condida tet nombre des electeuurs
{
          printf("\n\n");
          printf("\t\t\t\t       -----------------------------------------\n\n");
          printf("\t\t\t\t\tBienvenue sur les listes de l'election\n\n\t\t\t\t\t     =======presidentielle======\n\n");  
          printf("\t\t\t\t       -----------------------------------------\n");
          Sleep(1);
          printf("\n\n");
    do
    {
         printf("\t\t\t\t     Entrez les nombres des condidats (Minimum 5):\n");  
          printf("\n\n");
          printf("\t\t\t\t\t\t\t   ");
        scanf("%d", &nombre_p);
        printf("\n\n");
    }while(nombre_p<5);

    do
    {
          printf("\t\t\t\t  Maintenant entrez les nombres d'electurs(Minimum 10)\n");  
          printf("\t\t\t\t\t\t\t   ");
          printf("\n");
          printf("\t\t\t\t\t\t\t  ");
        scanf("%d", &nombre_e);
    }while(nombre_e<10);
}


    void InsertionDonnes() //Insertion Des nomes des condidats et CIN des electeurs
{
   printf("\n\n");
        printf("\t\t\t\t\t **** Entree les noms des candidats: ****\n");
    for(i = 0; i < nombre_p; i++)
    {
    printf("\n");
        printf("\t\t\t\t\t\xFE   ");
        scanf(" %[^\n]s ", nom_p[i]);
    }
        printf("\n\n\n");
        printf("\t\t\t\t\t **** Entree CIN des electeurs : ****\n\n");
    for(j = 0; j < nombre_e; j++)
    {
    printf("\t\t\t\t\t\xFE   ");
        printf("CIN d'electeur N%d : ", j + 1);
        scanf("%d", &tab_cin[j]);
    }
}


    void ListePresident(int exclu) //Lister les president nominee a chaque phase
{
        printf("\t\t\t\t\t Ce sont les %d candidats a la presidence:\n\n", nombre_p);
    for(i = 0; i < nombre_p - exclu; i++)
{
printf("\t\t\t\t\t %d %s \n\n\n", tab_p[0][i], nom_p[tab_p[0][i]-1]);
}
}

    void ZeroVotes() //remetre le conteur de vote a 0
{
for(i = 0; i < nombre_p - exclu; i++) tab_p[1][i]=0;
}
    void Election(int exclu) //Electer les president nominees
{
	printf("\t\t\t\t\t Votez pour votre candidat par le numero correspondant a son nom, de 1 a %d :\n\n", nombre_p);
for(j = 0; j < nombre_e; j++)
{
      printf("\t\t\t\t\t");
      scanf("%d \n", &tab_cin[j]);
 for(i = 0; i < nombre_p - exclu; i++)
 {
   if( tab_cin[j] == tab_p[0][i]) tab_p[1][i] = tab_p[1][i] + 1;
 }
}
      printf("\t\t\t\t\t Les Votes serant calculees dans une instant");
for(i = 0; i < 5; i++)
{
printf(".");
Sleep(1);
}
}


    void results(int exclu) //aficher les resultas de chaque phase
{
for( i = 0; i < nombre_p - exclu; i++)
{
        printf("\t\t\t\t\tCondidat %d |. %s. a %d (%.1f %%) votes\n\n", tab_p[0][i], nom_p[tab_p[0][i]-1], tab_p[1][i], (float)(tab_p[1][i]*100/nombre_e));
        printf("\n\n\n\t\t\t\t\t\t Appuyez sur n'importe quelle touche pour continuer au phase suivant.\n\n\n");  
        system("pause > Null");
}
}

    void Condition1(int exclu) //verefier la condition du premier phase, ta799
{
for( i = 0; i < nombre_p - exclu-1 ; i++)
    {
   if( tab_p[1][i] != tab_p[1][i+1] ) 
   cond=0;
}
}
void Trie(int exclu) //Trie dordre decoissant les votes et echanger les indice
{
for (i=0; i<nombre_p - exclu; i++)
     {
     
      max=i;
      for (j=i+1; j < nombre_p; j++)
          if (tab_p[1][j]>tab_p[1][max]) 
		  max=j;
     
      need=tab_p[1][i];
      tab_p[1][i]=tab_p[1][max];
      tab_p[1][max]=need;
     
      need=tab_p[0][i];
      tab_p[0][i]=tab_p[0][max];
      tab_p[0][max]=need;
     }
}

void ExcluPhase1() //calculer les condidat exlu qu premier phase
{
for(i=0 ; i<nombre_p ; i++)
    {
    if((float)(tab_p[1][i]*100/nombre_e)<15) exclu = exclu + 1;
}
}

void FinalResults() //aficher le resulta final
{
   printf("\t\t\t\t\t\t\xFE  Le President electer est %s avec %d votes\n\n", nom_p[tab_p[0][0]-1] , tab_p[1][0] );
}
   
int main()
{
{

Insertion();
system("cls");
InsertionDonnes();
system("cls");
printf("\n\n\t\t Les elections debutent dans une instant ");

    for(i=0 ; i<5 ; i++)
    {
    printf(". ");
    Sleep(1);
   
}
system("cls");

}
for(i=0 ; i < nombre_p - exclu ; i++) tab_p[0][i]=i+1;

ZeroVotes();
ListePresident(exclu);
Election(exclu);
system("cls");
results(exclu);
Condition1(exclu);


while(cond) 
{
ZeroVotes();
system("cls");
printf("\n\n\t\tTous les presidents nomines ont un nombre de votes ex aequo, le tour doit etre refait.\n\n");
ListePresident(exclu);
Election(exclu);
system("cls");
results(exclu);
Condition1(exclu);
}

ExcluPhase1();
Trie(exclu);

if(exclu == nombre_p-1)
{
system("cls");
FinalResults();
}
else
{
system("cls");
   ZeroVotes();
   ListePresident(exclu);  
   Election(exclu);
   system("cls");
   results(exclu);
   Trie(exclu);
   
   
   while( tab_p[1][nombre_p-exclu-1] == tab_p[1][nombre_p-exclu-2] ) 
   {
    ZeroVotes();
    system("cls");
    
    printf("\n\n\t\t Le tour doit être répété car les candidats ayant obtenu le moins de voix sont tirés au sort.\n\n");
    
    ListePresident(exclu);
    Election(exclu);
    system("cls");
    results(exclu);
    Trie(exclu);
}
   exclu = exclu + 1;
   system("cls");
   ZeroVotes();
   ListePresident(exclu);
   Election(exclu);
   system("cls");
   Trie(exclu);
   
   
   while(tab_p[1][0] == tab_p[1][1])
   {
    ZeroVotes();
    system("cls");
    printf("\n\n\t\t Le tour doit être répété car les candidats ayant obtenu le maximum de voix sont tirés au sort\n\n");
    ListePresident(exclu);
    Election(exclu);
    Trie(exclu);
}

system("cls");
        FinalResults();
}







    return 0;
}