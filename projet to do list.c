//TO DO LIST
#include <stdio.h>
#include <string.h>
#include <time.h>

enum statut {
    aRealiser, 
    enCoursDeRealisation, 
    finalisee
};
typedef struct{
    int min;
    int h;
    int j;
    int m;
    int a;
}date;

typedef struct{
    char id[10];
    char titre[20];
    char description[50];
    date deadline;
    enum statut st;
    
}tache;
tache info[300];

int main()
{
    int choix, etat, n, i, j;
    int compteur=0;
    long deadlinejj, deadlinej, deadlinej1;
    time_t current_time;
    do{
        printf("________________________________________________________________________________________________________________________\n");
		printf("____________________________________________________MENU________________________________________________________________\n\n\n");
		printf("1 - Ajouter une nouvelle tache.");
		printf("                                                   2 - ajoutre plusieurs nv taches.\n\n");
		printf("3 - afficher la liste de toutes les taches.");
		printf("                         4 - modifier une tache.\n\n");
		printf("5 - supprimer une tache.");
		printf("                             6 - rechercher des taches .\n\n");
		printf("7 - statistiques");
		printf("                                 8 - EXIT\n");
		printf("________________________________________________________________________________________________________________________\n");
		printf("________________________________________________________________________________________________________________________\n");
		printf("\n");
		printf("Entrez votre choix : ");
		scanf("%d", &choix);
		if(choix==1 || choix==2){
		    if(choix==2){
		        printf("________________________________________AJOUTER PLUSIEURS NOUVELLES TACHES___________________________________________________\n\n\n");
		        printf("combien de taches voulez vous saisir?\n");
		        scanf("%d", &n);
		    }else if(choix==1){
		        printf("_____________________________________________AJOUTER NOUVELLE TACHE__________________________________________________________\n\n\n");
		        n=1;
		    }
		    if(compteur+n<300){
		        for(i=0; i<n; i++){
		            printf("entrez l'identifiant de la tache  :   ");
		            scanf(" %[^\n]s", info[i+compteur].id);
		            printf("entrez le titre de la tache  :   ");
		            scanf(" %[^\n]s", info[i+compteur].titre);
		            printf("entrez une description à la tache  :   ");
		            scanf(" %[^\n]s", info[i+compteur].description);
		            printf("entrez le statut de la tache  :   ");
		            do{
		                printf("\n1 - à réaliser.");
		                printf("                   2 - en cours de réalisation.\n");
		                printf("3 - finalisee.");
		                scanf("%d", &etat);
		            info[compteur+i].st=etat-1;
		            }while(etat!=3);
		            printf("Deadline(à quand est elle due?) format(JJ/MM/AA)  :   ");
		            scanf(" %d/%d/%d", &info[i+compteur].deadline.j, &info[i+compteur].deadline.m, &info[i+compteur].deadline.a);
		            printf("a quelle heure est elle due format(hh:mm)  :   ");
		            scanf(" %d:%d", &info[i+compteur].deadline.h, &info[i+compteur].deadline.min);
		            compteur+=n;
		        }
		    }
		}
		if(choix==3){
		    
		}
		switch(choix)
		{
		    case 3:
		    int choixAffichage, jours;
		    time (&current_time);
		    struct tm *local_time = localtime(&current_time);
	        int year = local_time->tm_year + 1900;
		    int month = local_time->tm_mon + 1;
		    int day = local_time->tm_mday;
		    long tempsActuel=year*365+month*12+day*jours;
		    deadlinejj=info[j].deadline.a*365+info[j].deadline.m*12+info[j].deadline.j*jours;
		    deadlinej=info[j].deadline.a*365+info[j].deadline.m*12+info[j].deadline.j*jours+info[j].deadline.h*24+info[j].deadline.min*60;
		    deadlinej1=info[j+1].deadline.a*365+info[j+1].deadline.m*12+info[j+1].deadline.j*jours+info[j+1].deadline.h*24+info[j+1].deadline.min*60;
		    tache temp;
		    do{
		        printf("________________________________________________________________________________________________________________________\n");
		    printf("________________________________________________SOUS-MENU_______________________________________________________________\n\n\n");
		    printf("1 - Trier les tâches par ordre alphabétique..");
		    printf("                                                   2 - Trier les tâches par deadline.\n\n");
		    printf("3 - Afficher les tâches dont le deadline est dans 3 jours ou moins\n\n");
		    scanf("%d", &choixAffichage);
		    while(choixAffichage!=3);
		    printf("\n");
		    if(choixAffichage==1 || choixAffichage==2){
		        if(choixAffichage==1){
		            printf("______________________________________________TRI-ALPHABETIQUE____________________________________________________________\n\n\n");
		            for(i=0; i<compteur-1; i++){
		                for(j=0; j<compteur-i-1; j++){
		                    if(strcmp(info[j].titre, info[j+1].titre)>0){
		                        temp=info[j];
		                        info[j]=info[j+1];
		                        info[j+1]=temp;
		                    }
		                }
		            }
		        }
		        if(choixAffichage==2){
		            printf("______________________________________________TRI DE DEADLINE______________________________________________________________\n\n\n");
		            for(i=0; i<compteur-1; i++){
		                for(j=0; j<compteur-i-1; j++){
		                    if(info[j].deadline.m==4 || info[j].deadline.m==6 || info[j].deadline.m==9  || info[j].deadline.m==11){
		                        jours=30;
		                    }
		                    if(info[j].deadline.m==1 || info[j].deadline.m==3 || info[j].deadline.m==5  || info[j].deadline.m==7  || info[j].deadline.m==8  || info[j].deadline.m==10 || info[j].deadline.m==12){
		                        jours=31;
		                    }
		                    if(info[j].deadline.m==2){
		                        jours=28;
		                    }
		                    if(deadlinej> deadlinej1){
		                        temp=info[j];
		                        info[j]=info[j+1];
		                        info[j+1]=temp;
		                    }
		                }
		            }
		        }
		        printf("___________________________________________AFFICHER LA LISTE DES TACHES______________________________________________________\n\n\n");
		        printf("  || identifiant  ||  titre  ||  desciption  ||  deadline  ||  statut  ||\n");
		        for(i=0; i<compteur; i++){
		            printf("  || %s  ||  %s  ||  %s  ||  %d/%d/%d - %d:%d  ||  %d  ||\n", info[i].id, info[i].titre, info[i].description, info[i].deadline.j, info[i].deadline.m, info[i].deadline.a, info[i].deadline.h, info[i].deadline.min, info[i].st+1);
		        }
		    if (choixAffichage==3){
		        printf("____________________________________________TRI DEADLINE DANS 3 JOURS_________________________________________________________\n\n\n");
		        long minuteur=deadlinejj-current_time;
		        if(minuteur<=3){
		            for(i=0; i<compteur; i++){
		            printf("  || %s  ||  %s  ||  %s  ||  %d/%d/%d - %d:%d  ||  %d  ||\n", info[i].id, info[i].titre, info[i].description, info[i].deadline.j, info[i].deadline.m, info[i].deadline.a, info[i].deadline.h, info[i].deadline.min, info[i].st+1);
		            }
		        }
		    }
		    break;
		    case 4:
		    int choixModifier;
		    char identifiantRecherche[10];
		    char nvDescription[50];
		    do{
		        printf("_______________________________________________MODIFIER UNE TACHE____________________________________________________________\n\n\n");
		        printf("________________________________________________________________________________________________________________________\n");
		        printf("____________________________________________________SOUS-MENU________________________________________________________________\n\n\n");
		        printf("1 - Modifier la description d'une tâche.");
		        printf("                                                   2 - Modifier le statut d’une tâche.\n\n");
		        printf("3 - Modifier le deadline d’une tâche.\n\n");
		        scanf("%d", &choixModifier);
		    }while(choixModifier!=3);
		    printf("entrez l'identifiant de la tache");
		    scanf("%[^\n]s", identifiantRecherche);
		    int trouve=0;
		    for(i=0; i<compteur; i++){
		            if(strcmp(identifiantRecherche, id)==0){
		                switch (choixModifier){
		                    case 1:
		                    printf("_____________________________________MODIFIER DESCRIPTION DE TACHE_______________________________________________________\n\n\n");
		                    printf("entrez nouvelle description\n");
		                    scanf("%[^\n]s", nvDescription);
		                    info[i].description=nvDescription;
		                    trouve=1;
		                    printf("description de la tache %d est modifiee avec succes\n", i+1);
		                    break;
		                    case 2:
		                    int nvStatut;
		                    printf("_________________________________________MODIFIER STATUT DE TACHE________________________________________________________\n\n\n");
		                    printf("entrez nouveau statut\n");
		                    do{
		                        printf("\n1 - à réaliser.");
		                        printf("                   2 - en cours de réalisation.\n");
		                        printf("3 - finalisee.");
		                        scanf("%[^\n]s", nvStatut);
		                    }while(nvStatut!=3);
		                    info[i].st=nvStatut;
		                    trouve=1;
		                    printf("statut de la tache %d est modifiee avec succes\n", i+1);
		                    }
		                }if(!trouve){
		                        printf("tache introuvable\n");
		                }
		            }
		        }
		        break;
		        case 3:
		        printf("_______________________________________MODIFIER DEADLINE DE TACHE________________________________________________________\n\n\n");
		        printf("entrez nouveau deadline\n");
		        printf("Deadline(à quand est la tach
		                info[i].st=nvStatut;
		                trouve=1;
		                printf("statut de la tache %d est modifiee avec succes\n", i+1);
		            }
		            if(!trouve){
		                printf("tache introuvable\n");
		            }
		        }
		    e %d due?) format(JJ/MM/AA)  :   ", i+1);
		        int trouve=0;
		        
		        break;
		    }
		    break;
		    case 5:
		    printf("_______________________________________________SUPPRIMER UNE TACHE___________________________________________________________\n\n\n");
		    break;
		    case 6:
		    printf("______________________________________________RECHERCHER DES TACHES__________________________________________________________\n\n\n");
		    break;
		    case 7:
		    printf("_________________________________________________STATISTIQUES________________________________________________________________\n\n\n");
		    break;
		    case 8:
		    printf("____________________________________________________EXIT_____________________________________________________________________\n\n\n");
		    break;
		    default:
		    printf("choix impossible\n");
		    break;
		}
    }while(choix!=8);
    return 0;
}