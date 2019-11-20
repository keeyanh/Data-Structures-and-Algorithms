#include <iostream>

using namespace std;

struct LinkedList {
    int data;
    LinkedList* next;
    LinkedList* prev;
};

// only for the 1st Node
void initNode(struct LinkedList *head,int n){
    head->data = n;
    head->next =NULL;
}

// apending
void add(struct LinkedList *head, int n) {
    LinkedList *newNode = new LinkedList;
    newNode->data = n;
    newNode->next = NULL;
    newNode->prev = NULL;
    
    LinkedList *cur = head;
    while(cur) {
        if(cur->next == NULL) {
            cur->next = newNode;
            newNode->prev = cur;
            return;
        }
        cur = cur->next;
    }
}

void insertFront(struct LinkedList **head, int n) {
    LinkedList *newNode = new LinkedList;
    newNode->data = n;
    newNode->next = *head;
    *head = newNode;
}

struct LinkedList *searchNode(struct LinkedList *head, int n) {
    LinkedList *cur = head;
    while(cur) {
        if(cur->data == n) return cur;
        cur = cur->next;
    }
    cout << "No Node " << n << " in list.\n";
    return cur;
}


void print(struct LinkedList *head) {
    LinkedList *list = head;
    while(list) {
        cout << list->data << " ";
        list = list->next;
    }
    cout << endl;
    cout << endl;
}
struct LinkedList* getTail(struct LinkedList** head)
{
    LinkedList *parent = *head;
    while(parent->next != NULL) {
        parent=parent->next;
    }
    return parent;
}
int getSize(struct LinkedList** head) {
    int i = 1;
    LinkedList *parent = *head;
    while(parent->next != NULL) {
        parent=parent->next;
        i++;
    }
    return i;
}
int getLocation(struct LinkedList** head, int i) {
    int x = 0;
    LinkedList *parent = *head;
    while(parent !=NULL) {
        if (parent->data ==i) {
            
        }
        parent=parent->next;
        x++;
    }
    return x;
}
struct LinkedList* getNodeatLocation(struct LinkedList** head, int i) {
    LinkedList *parent = *head;
    for (int j = 0; j <i; j++) {
        parent = parent->next;
    }
    return parent;
}
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void partition(struct LinkedList** head, int low, int high, int &i, int &j)
{
    LinkedList *parent = *head;
    LinkedList *reverse = getTail(&parent);
    // To handle 2 elements
    
    if (high - low <= 1)
    {
        if ( reverse->data < parent->data)
            swap(&reverse->data, &parent->data);
        i = low;
        j = high;
        return;
    }
    int mid = low;
    cout << "PIVOT " << endl;
    int pivot =getNodeatLocation(&parent, high)->data;
    while (mid <= high)
    {
        cout << "Comparing " <<getNodeatLocation(&parent, mid)->data << " and " << pivot << endl;
        if (getNodeatLocation(&parent, mid)->data<pivot) {
            swap(getNodeatLocation(&parent, low)->data, getNodeatLocation(&parent, mid)->data);
            cout << "Swapped " <<getNodeatLocation(&parent, mid)->data << " and " << pivot << endl;
            low++;
            mid++;
        }
        else if (getNodeatLocation(&parent, mid)->data==pivot){
            mid++;
            
        }
        else if (getNodeatLocation(&parent, mid)->data>pivot) {
            swap(getNodeatLocation(&parent, mid)->data, getNodeatLocation(&parent, high)->data);
            high--;
            cout << "Swapped " <<getNodeatLocation(&parent, mid)->data << " and " << pivot << endl;
        
        }
    }

    //update i and j
    i = low-1;
    j = mid; //or high-1
    cout << "LIST AFTER PARTITION" << endl;
    print(parent);
}
void quicksort(struct LinkedList** head, int low, int high)
{
    if (low>=high) //1 or 0 elements
        return;
    
    int i, j;
    
    // Note that i and j are passed as reference
    partition(head, low, high, i, j);
    
    // Recur two halves
    quicksort(head, low, i);
    quicksort(head, j, high);
}


int main()
{
    struct LinkedList *head = new LinkedList;
    
    initNode(head,5);
    print(head);
    add(head,7);
    print(head);
    add(head,4);
    print(head);
    add(head,2);
    print(head);
    add(head,9);
    print(head);
    add(head,1);
    print(head);
    add(head,2);
    print(head);
    add(head,9);
    print(head);
    add(head,5);
    print(head);
    add(head,3);
    print(head);
    add(head,4);
    print(head);
    add(head,1);
    print(head);
    
    
    print(head);
    struct LinkedList *nhead = head;
    nhead = nhead->next;
    cout << "This is nhead" << endl;
    print(nhead);
    
    
    swap(head->data, nhead->data);
    cout << "This is nhead after swap" << endl;
    print(nhead);
    cout << "This is head after swap" << endl;
    print(head);
    cout << "This is node at location" << endl;
    cout << getNodeatLocation(&head, 2)->data << endl;
    print(head);
    cout << "This is size of head" << endl;
    cout << getSize(&head)-1 << endl;
    quicksort(&head, 0, getSize(&head)-1);
    cout << "This is tail" << endl;
    print(getTail(&head)->prev);
    print(head);
    
    return 0;
}
