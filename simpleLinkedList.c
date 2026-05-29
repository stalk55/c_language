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

        printf("┌─────────────── OPÉRATIONS DE SUPPRESSION ────────────┐\n");
        printf("│  6. Supprimer au début                               │\n");
        printf("│  7. Supprimer à la fin                               │\n");
        printf("│  8. Supprimer par valeur                             │\n");
        printf("│  9. Supprimer à une position                         │\n");
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

    void insertPos(Node** head,int val,int pos){
        Node* newNode = createNode(val);
        Node* tmp = *head;
        if(pos < 0){
            printf("Position invalide. La position doit être un entier positif.\n");
            return;
        }

        else if(pos == 0){
            insertTete(head,val);
            return;
        }

        for (int i = 0; i < pos-1&& tmp != NULL; i++)
        {
            /* code */
            tmp = tmp->nxt;
        }

        if(tmp == NULL){
            printf("Position invalide. La position dépasse la taille de la liste.\n");
            return;
        }
        newNode->nxt = tmp->nxt;
        tmp->nxt = newNode;
        
    }
    void insertTrie(Node** head,int val){
        Node* newNode = createNode(val);
        if(*head == NULL || (*head)->data >= val){
            newNode->nxt = *head;
            *head = newNode;
            return;
        }
        Node* current = *head;
        while(current->nxt != NULL && current->nxt->data < val){
            current = current->nxt;
        }
        newNode->nxt = current->nxt;
        current->nxt = newNode;
    }

    void supprimeTet(Node** head){
        if(estVide(*head)){
            printf("la liste est vide");
            return;
        }
        Node* tmp = *head;
        *head = (*head)->nxt;
        free(tmp);
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
            break;

            case 3:
                printf("entrez la valeur a inserer");
                scanf("%d",&val);
                insertfin(&list,val);
            break;
                
            case 4:
                printf("entrez la valeur a inserer");
                scanf("%d",&val);
                printf("entrer la position");
                scanf("%d",&position);
                insertPos(&list,val,position);
            break;

            case 5:
                printf("entrez la avleur a inserer ");
                scanf("%d",&val);
                insertTrie(&list,val);
            break;

            case 6:
                supprimeTet(&list);
                afficherList(list);
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