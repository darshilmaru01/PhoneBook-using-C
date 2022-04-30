/**
 * Roll: 20BCE514
 * Name: Darshil Maru 
 * AIM 9: PhoneBook using BST 
 *  
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*Create phone book entry structure.*/
typedef struct pbentry {
	char lastname[16];
	char firstname[11];
	char phone[11];
} Entry;

/*Create tree node structure.*/
struct tree_node {
	Entry data;
	struct tree_node *left;
	struct tree_node *right;
};

struct tree_node * insert(struct tree_node *p, Entry e);
struct tree_node * create_node (struct tree_node *q, struct tree_node *r, Entry e);
void search_node(struct tree_node *p, char l[], char f[]);
void print_tree(struct tree_node *p);

int main(void)
{
	int option = 0; 
	Entry e; 
	struct tree_node *p = NULL; 
	char ln[16]; 
	char fn[11]; 


	while (option != 6) {
		printf("\n\n_____PHONEBOOK_____\n");
		printf("\nMENU\n");
		printf("1. Add\n");
		printf("2. Search\n");
		printf("3. Display\n");
		printf("4. Quit\n");

		printf("\nPlease select an option: ");
		scanf("%d", &option);
		
        /*For Add*/
		if (option == 1) {
			printf("Please enter the Last Name: ");
			scanf("%s", &e.lastname);
			printf("Please enter the First Name: ");
			scanf("%s", &e.firstname);
			printf("Please enter the Phone Number: ");
			scanf("%s", &e.phone);
    
			p = insert(p, e);

			printf("\n----------------------------\n");
			printf("\nRecord added successfully.\n");
			printf("\n----------------------------");
		}

        /*For Search*/		
		else if (option == 2) {
			
			printf("Please enter the Last Name: ");
			scanf("%s", &ln);
			printf("Please enter the First Name: ");
			scanf("%s", &fn);
			printf("\n");
			
			search_node(p, ln, fn);
		}

		/*For Display*/		
		else if (option == 3) {
			printf("\n");
			print_tree(p);
		}

		/*To Exit*/		
		else if (option == 4) {
			break;
		}
		
		else {
			printf("That option does not exist. Please try again.\n\n");
		}

	}
	return 0;
}

struct tree_node * insert(struct tree_node *p, Entry e) {
	/*If there is no root:*/
	if (p == NULL) {
	
		p = create_node(NULL, NULL, e);
	}
	
	else if (strcmp(e.lastname, p->data.lastname) < 0) {
		/*Add before root.*/
		p->left = insert(p->left, e);
	}
	else if (strcmp(e.lastname, p->data.lastname) > 0) {
		/*Add after root.*/
		p->right = insert(p->right, e);
	}
	else {
		if (strcmp(e.firstname, p->data.firstname) < 0) {
			/*Add before root.*/
			p->left = insert(p->left, e);
		}
		else if (strcmp(e.firstname, p->data.firstname) > 0) {
			/*Add after root.*/
			p->right = insert(p->right, e);
		}
		else {
			return p;
		}
	}
	return p;
}
	
    /*Creates a new node.*/
struct tree_node * create_node (struct tree_node *q, struct tree_node *r, Entry e) {
	struct tree_node* newnode;
	newnode = (struct tree_node*)(malloc(sizeof(struct tree_node)));
	newnode->data = e;
	newnode->left = q;
	newnode->right = r;
	return newnode;
}

/*Searches for a node and retrieves data.*/
void search_node(struct tree_node *p, char l[], char f[]) {
	if (strcmp(l, p->data.lastname) < 0) {
		search_node(p->left, l, f);
	}
	else if (strcmp(l, p->data.lastname) > 0) {
		search_node(p->right, l, f);
	}
	else if (strcmp(l, p->data.lastname) == 0 && strcmp(f, p->data.firstname) != 0) {
		if (strcmp(f, p->data.firstname) < 0) {
			search_node(p->left, l, f);
		}
		if (strcmp(f, p->data.firstname) > 0) {
			search_node(p->right, l, f);
		}
	}
	else if (strcmp(l, p->data.lastname) == 0 && strcmp(f, p->data.firstname) == 0) {
		printf("%s, %s, %s\n\n", p->data.lastname, p->data.firstname, p->data.phone);	
	}
	else {
		printf("No Record Found.\n\n");
	}
}

/*Prints contents of tree.*/
void print_tree(struct tree_node *p)
{
	if (p != NULL) {
		print_tree(p->left);
		printf("%s, %s, %s\n\n", p->data.lastname, p->data.firstname, p->data.phone);
		print_tree(p->right);
	}
}