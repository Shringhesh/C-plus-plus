#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

// Stack structure for chat history
typedef struct Stack {
    char messages[MAX_LEN][256]; // Store messages
    int top; // Top index
} Stack;

// Function to initialize the stack
void initStack(Stack* s) {
    s->top = -1;
}

// Function to check if stack is empty
int isEmpty(Stack* s) {
    return s->top == -1;
}

// Function to check if stack is full
int isFull(Stack* s) {
    return s->top == MAX_LEN - 1;
}

// Function to push a message onto the stack
void push(Stack* s, char message[]) {
    if (isFull(s)) {
        printf("Chat history is full!\n");
        return;
    }
    s->top++;
    strcpy(s->messages[s->top], message);
}

// Function to pop a message from the stack (Undo)
void pop(Stack* s, char message[]) {
    if (isEmpty(s)) {
        printf("No messages to undo!\n");
        return;
    }
}
    void pop1(Stack* s, char message[]) {
    if (isEmpty(s)) {
        printf("No messages to redo!\n");
        return;
    }
    strcpy(message, s->messages[s->top]); // Store the removed message
    s->top--;
}

// Function to redo a message (Push it back)
void redo(Stack* s, char message[]) {
    push(s, message);
}

// Function to display chat history
void displayChat(Stack* s) {
    if (isEmpty(s)) {
        printf("Chat is empty!\n");
        return;
    }
    printf("\nChat History:\n");
    for (int i = 0; i <= s->top; i++) {
        printf("%d: %s\n", i + 1, s->messages[i]);
    }
}

// Main function
int main() {
    Stack chatHistory, redoStack;
    char message[256], lastUndone[256];
    int choice;

    initStack(&chatHistory);
    initStack(&redoStack);

    while (1) {
        printf("\n1. Send Message\n2. Undo Last Message\n3. Redo Last Message\n4. Display Chat History\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear input buffer

        switch (choice) {
            case 1:
                printf("Enter your message: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = 0; // Remove newline
                push(&chatHistory, message);
                printf("Message sent!\n");
                break;
            case 2:
                pop(&chatHistory, lastUndone);
                if (strlen(lastUndone) > 0) {
                    push(&redoStack, lastUndone);
                    printf("Message undone: %s\n", lastUndone);
                }
                break;
            case 3:
                pop1(&redoStack, lastUndone);
                if (strlen(lastUndone) > 0) {
                    redo(&chatHistory, lastUndone);
                    printf("Message restored: %s\n", lastUndone);
                }
                break;
            case 4:
                displayChat(&chatHistory);
                break;
            case 5:
                printf("Exiting chat organizer...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
