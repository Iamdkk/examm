#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int temp;
    int swapped;

    for (int i = 0; i < n - 1; i++) {
        swapped = 0; // Flag to check if any swapping is done in this pass

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }

        // If no two elements were swapped in the inner loop, the array is sorted
        if (swapped == 0) {
            break;
        }
    }
}

int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    bubbleSort(arr, n);

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
     next

#include <stdio.h>

int binarySearch(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if the target is at the middle position
        if (arr[mid] == target) {
            return mid;
        }

        // If the target is greater, ignore the left half
        if (arr[mid] < target) {
            left = mid + 1;
        }

        // If the target is smaller, ignore the right half
        else {
            right = mid - 1;
        }
    }

    // If the target is not found, return -1
    return -1;
}

int main() {
    int n, target;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d sorted elements in ascending order:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search for: ");
    scanf("%d", &target);

    int result = binarySearch(arr, n, target);

    if (result != -1) {
        printf("Element %d found at index %d\n", target, result);
    } else {
        printf("Element %d not found in the array\n", target);
    }

    return 0;
}

     next

// Optimized implementation of Bubble sort
#include <stdbool.h>
#include <stdio.h>

void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

// An optimized version of Bubble Sort
void bubbleSort(int arr[], int n)
{
	int i, j;
	bool swapped;
	for (i = 0; i < n - 1; i++) {
		swapped = false;
		for (j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
				swapped = true;
			}
		}

		// If no two elements were swapped by inner loop,
		// then break
		if (swapped == false)
			break;
	}
}

// Function to print an array
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
}

// Driver program to test above functions
int main()
{
	int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
	int n = sizeof(arr) / sizeof(arr[0]);
	bubbleSort(arr, n);
	printf("Sorted array: \n");
	printArray(arr, n);
	return 0;
}

  next

#include <stdio.h>

int binarySearch(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if the target is at the middle position
        if (arr[mid] == target) {
            return mid;
        }

        // If the target is greater, ignore the left half
        if (arr[mid] < target) {
            left = mid + 1;
        }

        // If the target is smaller, ignore the right half
        else {
            right = mid - 1;
        }
    }

    // If the target is not found, return -1
    return -1;
}

int main() {
    int n, target;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d sorted elements in ascending order:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search for: ");
    scanf("%d", &target);

    int result = binarySearch(arr, n, target);

    if (result != -1) {
        printf("Element %d found at index %d\n", target, result);
    } else {
        printf("Element %d not found in the array\n", target);
    }

    return 0;
}

next

// Quick sort in C

#include <stdio.h>

// function to swap elements
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// function to find the partition position
int partition(int array[], int low, int high) {
  
  // select the rightmost element as pivot
  int pivot = array[high];
  
  // pointer for greater element
  int i = (low - 1);

  // traverse each element of the array
  // compare them with the pivot
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
        
      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;
      
      // swap element at i with element at j
      swap(&array[i], &array[j]);
    }
  }

  // swap the pivot element with the greater element at i
  swap(&array[i + 1], &array[high]);
  
  // return the partition point
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    
    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on right of pivot
    int pi = partition(array, low, high);
    
    // recursive call on the left of pivot
    quickSort(array, low, pi - 1);
    
    // recursive call on the right of pivot
    quickSort(array, pi + 1, high);
  }
}

// function to print array elements
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

// main function
int main() {
  int data[] = {8, 7, 2, 1, 0, 9, 6};
  
  int n = sizeof(data) / sizeof(data[0]);
  
  printf("Unsorted Array\n");
  printArray(data, n);
  
  // perform quicksort on data
  quickSort(data, 0, n - 1);
  
  printf("Sorted array in ascending order: \n");
  printArray(data, n);
}

next

// C program for insertion sort
#include <math.h>
#include <stdio.h>

/* Function to sort an array 
using insertion sort*/
void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++) 
	{
		key = arr[i];
		j = i - 1;

		/* Move elements of arr[0..i-1], 
		that are greater than key, 
		to one position ahead of 
		their current position */
		while (j >= 0 && arr[j] > key) 
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

// A utility function to print 
// an array of size n
void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

// Driver code
int main()
{
	int arr[] = {12, 11, 13, 5, 6};
	int n = sizeof(arr) / sizeof(arr[0]);

	insertionSort(arr, n);
	printArray(arr, n);

	return 0;
}

next

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode* insert(struct TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

void inOrderTraversal(struct TreeNode* root) {
    if (root) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

void preOrderTraversal(struct TreeNode* root) {
    if (root) {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void postOrderTraversal(struct TreeNode* root) {
    if (root) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct TreeNode* root = NULL;
    int choice, data;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert a value\n");
        printf("2. In-Order Traversal\n");
        printf("3. Pre-Order Traversal\n");
        printf("4. Post-Order Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("In-Order Traversal: ");
                inOrderTraversal(root);
                printf("\n");
                break;
            case 3:
                printf("Pre-Order Traversal: ");
                preOrderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Post-Order Traversal: ");
                postOrderTraversal(root);
                printf("\n");
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}

next

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

void push(int stack[], int *top, int value) {
    if (*top < MAX_SIZE - 1) {
        stack[++(*top)] = value;
    } else {
        printf("Stack overflow\n");
    }
}

int pop(int stack[], int *top) {
    if (*top >= 0) {
        return stack[(*top)--];
    } else {
        printf("Stack underflow\n");
        return -1;
    }
}

int evaluateMultiDigit(char *exp, int *index) {
    int number = 0;
    while (isdigit(exp[*index])) {
        number = number * 10 + (exp[*index] - '0');
        (*index)++;
    }
    return number;
}

int postfixEvaluation(char *exp) {
    int stack[MAX_SIZE];
    int top = -1;

    int len = strlen(exp);
    for (int i = 0; i < len; i++) {
        if (isdigit(exp[i])) {
            int number = evaluateMultiDigit(exp, &i);
            push(stack, &top, number);
        } else if (exp[i] != ' ') {
            int operand2 = pop(stack, &top);
            int operand1 = pop(stack, &top);

            switch (exp[i]) {
                case '+':
                    push(stack, &top, operand1 + operand2);
                    break;
                case '-':
                    push(stack, &top, operand1 - operand2);
                    break;
                case '*':
                    push(stack, &top, operand1 * operand2);
                    break;
                case '/':
                    push(stack, &top, operand1 / operand2);
                    break;
            }
        }
    }
    return pop(stack, &top);
}

int main() {
    char exp[100];
    printf("Enter a line of text: ");
    gets(exp);
    int result = postfixEvaluation(exp);
    printf("Result: %d\n", result);
    return 0;
}

next

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addToFront(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
    printf("Added %d to the front of the list.\n", data);
}

void addToEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        printf("Added %d to the end of the list.\n", data);
        return;
    }

    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    printf("Added %d to the end of the list.\n", data);
}

void addAfterPosition(struct Node** head, int position, int data) {
    struct Node* newNode = createNode(data);
    struct Node* current = *head;
    int currentPosition = 0;

    if (position < 0) {
        printf("Invalid position. Position must be non-negative.\n");
        return;
    }

    while (current != NULL && currentPosition < position) {
        current = current->next;
        currentPosition++;
    }

    if (current == NULL) {
        printf("Position %d is out of bounds.\n", position);
    } else {
        newNode->next = current->next;
        current->next = newNode;
        printf("Added %d after position %d.\n", data, position);
    }
}

void displayList(struct Node* head) {
    struct Node* current = head;
    if (current == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add to Front\n");
        printf("2. Add to End\n");
        printf("3. Add After a Position\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to add at the front: ");
                scanf("%d", &data);
                addToFront(&head, data);
                break;
            case 2:
                printf("Enter data to add at the end: ");
                scanf("%d", &data);
                addToEnd(&head, data);
                break;
            case 3:
                printf("Enter data to add: ");
                scanf("%d", &data);
                printf("Enter the position after which to add: ");
                scanf("%d", &position);
                addAfterPosition(&head, position, data);
                break;
            case 4:
                displayList(head);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

done...