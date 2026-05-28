#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node{

    int data;
    struct Node *nxt;

} Node;



    bool estVide(Node* head){
        return head == NULL;
    }

    Node* createNode(int val){
        Node* newNode = (Node*)malloc(sizeof(Node));
        if (newNode == NULL)
        {
            fprintf(stderr, "Erreur : impossible de créer un nouveau nœud\n");
            exit(EXIT_FAILURE);
        }
        newNode->data = val;
        newNode->nxt = NULL;
        return newNode;
    }

    void insertTete(Node** head,int val){
        Node* newNode = createNode(val);
        newNode->nxt = *head;
        *head = newNode;
    }


    void printMenu(){ // Sur Windows: system("cls")
        printf("\n╔══════════════════════════════════════════════════════════╗\n");
        printf("║          MANIPULATION DES LISTES CHAÎNÉES                ║\n");
        printf("╚══════════════════════════════════════════════════════════╝\n\n");
        printf("┌─────────────── OPÉRATIONS D'INSERTION ───────────────┐\n");
        printf("│  1. Afficher la liste                                │\n");
        printf("│  2. Insérer au début                                 │\n");
        printf("│  3. Insérer à la fin                                 │\n");
        printf("│  4. Insérer à une position                           │\n");
        printf("│  5. Insérer dans une liste triée                     │\n");
        printf("└──────────────────────────────────────────────────────┘\n");
        printf("0. Quitter\n");
    }

    void afficherList(Node* head){
        if(estVide(head)){
            printf("la liste est vide");
            return;
        }
        Node* temp = head;
        printf("[HEAD] ");
        while(temp != NULL){
            printf("%d ->",temp->data);
            temp = temp->nxt;
        }
        printf("NULL\n");
    }

    void insertfin(Node** head,int val){
        Node* newNode = createNode(val);
        if(estVide(*head)){
            *head = newNode;
            return;
        }

        Node* temp = *head;
        while(temp->nxt != NULL){
            temp = temp->nxt;
        }
        temp->nxt = newNode;
    }

int main(){

    Node* list = NULL;
    int choix ,val ,position;

    do{
        printMenu();
        printf("entrez votre choix :");
        scanf("%d",&choix);
        switch(choix){

            case 1:
            afficherList(list);
            break;

            case 2:
                printf("entrez la valeur a inserer");
                scanf("%d",&val);
                insertTete(&list,val);
                printf("la liste apres insertion :");
                afficherList(list);
            break;

            case 3:
                printf("entrez la valeur a inserer");
                scanf("%d",&val);
                insertfin(&list,val);
                printf("la liste apres insertion :");
            break;
                
            default:
                if (choix != 0) {
                    printf("Choix invalide. Veuillez réessayer.\n");
                }
                break;
        }
    }while(choix != 0);
    
    return 0;
}