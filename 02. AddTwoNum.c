/*
 * Problem: Add Two Numbers
 
 * You are given two non-empty linked lists representing two non-negative integers. 
 * The digits are stored in reverse order, and each of their nodes contains a single digit. 
 * Add the two numbers and return the sum as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 
 * Constraints:
 * - The number of nodes in each linked list is in the range [1, 100].
 * - 0 <= Node.val <= 9
 * - It is guaranteed that the list represents a number that does not have leading zeros.
 */

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *dummyHead = malloc(sizeof(struct ListNode));
    dummyHead->val = 0;
    dummyHead->next = NULL;

    struct ListNode *current = dummyHead;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry;
        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;

        struct ListNode* newNode = malloc(sizeof(struct ListNode));
        newNode->val = sum % 10;
        newNode->next = NULL;

        current->next = newNode;
        current = current->next;
    }

    struct ListNode* result = dummyHead->next;
    free(dummyHead);  
    return result;
}

struct ListNode* createList(int* arr, int size) {
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;

    for (int i = 0; i < size; i++) {
        struct ListNode* newNode = malloc(sizeof(struct ListNode));
        newNode->val = arr[i];
        newNode->next = NULL;

        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
    }
    return head;
}

void printList(struct ListNode* head) {
    while (head) {
        printf("%d", head->val);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

void freeList(struct ListNode* head) {
    while (head) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int arr1[] = {2, 4, 3};
    int arr2[] = {5, 6, 4};

    struct ListNode* l1 = createList(arr1, 3);
    struct ListNode* l2 = createList(arr2, 3);

    struct ListNode* result = addTwoNumbers(l1, l2);

    printf("Result: ");
    printList(result);

    freeList(l1);
    freeList(l2);
    freeList(result);

    return 0;
}
