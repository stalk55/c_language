#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node{

    int var;
    struct Node *nxt;

} Node;



    bool estVide(Node head){
        return head == NULL;
    }

    Node createNode(int val){
        Node *newNode = (Node*)malloc(sizeof(Node));
        if (newNode == NULL)
        {
            fprintf(stderr, "Erreur : impossible de créer un nouveau nœud\n");
            exit(EXIT_FAILURE);
        }
        newNode->var = val;
        newNode->nxt = NULL;
        return *newNode;
    }

    Node insertTete(Node head,int val){
        Node newNode = createNode(val);
        newNode.nxt = &head;
        return newNode;
    }


    void printMenu(){
        system("cls"); // Sur Windows: system("cls")
        printf("\n╔══════════════════════════════════════════════════════════╗\n");
        printf("║          MANIPULATION DES LISTES CHAÎNÉES                ║\n");
        printf("╚══════════════════════════════════════════════════════════╝\n\n");
        printf("┌─────────────── OPÉRATIONS D'INSERTION ───────────────┐\n");
        printf("│  1. Insérer au début                                 │\n");
        printf("│  2. Insérer à la fin                                 │\n");
        printf("│  3. Insérer à une position                           │\n");
        printf("│  4. Insérer dans une liste triée                     │\n");
        printf("└──────────────────────────────────────────────────────┘\n");
        printf("0. Quitter\n");
    }

    void afficherList(Node *head){
        Node *temp = head;
        while(temp != NULL){
            printf("%d",temp->var);
            temp = temp->nxt;
        }



    }


int main(){

    Node head = NULL;
    int choix ,val ,position;

    do{
        printMenu();
        printf("entrez votre choix :");
        scanf("%d",&choix);
        switch(choix){
            case 1:
                printf("entrez la valeur a inserer");
                scanf("%d",&val);
                insertTete(head,val);
                printf("la liste apres insertion :");
                afficherList(&head);
        }
    }
    

}