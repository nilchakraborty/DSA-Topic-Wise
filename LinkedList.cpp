/*//Insert Node at beginning of Linked List
//time Complexity : O(1)
ListNode * InsertatFirst(int value, ListNode * head) {
  ListNode * newnode = new ListNode(value);
  newnode -> next = head;
  head = newnode;
  return head;
}*/
/*//Delete Last Node of Linked List
//Time Complexity: O(N)
void DeleteLast() {
  if (head == nullptr)
    cout << "There are no nodes to delete in LinkedList" << endl;
  if (head -> next == nullptr) {
    delete head;
    head = nullptr;
  } else {
    ListNode * curr = head, * prev = nullptr;
    while (curr -> next != nullptr) {
      prev = curr;
      curr = curr -> next;
    }
    prev -> next = nullptr;
    delete curr;
  }
}*/
/*//Find the length of the linkedlist
//Iterative Approach
int getCount(Node* head){
    int count = 0;
    Node* cur = head;
    while (cur != NULL) {
        count++;
        cur = cur->next;
    }
    return count;
}
//Recursive approach
int getCount(Node* head, int count = 0){
    if (head == NULL)
        return count;
    return getCount(head->next, count + 1);
}*/
/*//Search an element in a Linked List
//Iterative Approach
bool search(Node* head, int x){
    Node* cur = head;
    while (cur != NULL) {
        if (cur->key == x)
            return true;
        cur = cur->next;
    }
    return false;
}
//Recursive Approach
bool search(struct Node* head, int x){
    if (head == NULL)
        return false;
    if (head->key == x)
        return true;
    return search(head->next, x);
}*/
/*//Insert at end of Doubly Linked List
void insertAtTail(node * & head, int val) {
    node* newNode= new node(val);
    if(head==NULL){
        head=newNode;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;
}*/
/*//Delete Last Node of a Doubly Linked List
node* delete_last(node* head) {
  if (head == NULL) {
    return NULL;
  }
  if (head->next == NULL) {
    delete head;
    return NULL;
  }
  node* cur = head;
  while (cur->next != NULL) {
    cur = cur->next;
  }
  node* temp = cur; // Store the last node
  cur->previous->next = NULL;
  delete temp;
  return head;
}*/
/*//Reverse a Linked List
node* reverseLinkedList(node* head) {
    node* prev = NULL;
    while (head != NULL) {
        node* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}*/
/*//Reverse a Doubly Linked List
node* reverseDoublyLinkedList(node* head) {
    node* temp = NULL;
    node* cur = head;
    while (cur != NULL) {
        temp = cur->prev;
        cur->prev = cur->next;//cur's prev pointer points to cur's next
        cur->next = temp;//cur's next pointer points to temp
        head = cur;//head points to cur
        cur = cur->prev;//cur points to cur's prev what was cur's next
    }
    return head;
}*/
/*//Find Middle of a Linked List
ListNode* middleNode(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next)
        slow = slow->next, fast = fast->next->next;
    return slow;
}*/
/*//Detect a Loop in Linked List
bool hasCycle(Node* head){
    if(head==NULL || head->next==NULL)
        return false;
    Node* slow=head, *fast=head;
    while(fast!=NULL && fast->next->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
            return true;
    }
    return false;
}*/
/*//Starting point of loop in a Linked List
ListNode* detectCycle(ListNode* head) {
    ListNode* slow = head, *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            break;
        }
    }
    if (fast == nullptr || fast->next == nullptr) {
        return nullptr;
    }
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}*/
/*//Check if LL is palindrome or not
bool isPalindrome(node* head) {
    if(head==NULL||head->next==NULL) return true; 
    node* slow = head;
    node* fast = head;  
    while(fast->next!=NULL&&fast->next->next!=NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }   
    slow->next = reverse(slow->next);//reverse the second half of the list
    slow = slow->next;
    node* dummy = head;   
    while(slow!=NULL) {//compare the first half and second half
        if(dummy->num != slow->num) return false;
        dummy = dummy->next;
        slow = slow->next;
    }
    return true;
}*/
/*//Segrregate odd and even nodes in LL
void segregateEvenOdd(Node** head) {
    Node* evenStart = NULL, * evenEnd = NULL, * oddStart = NULL, * oddEnd = NULL, * currNode = *head;
    while (currNode != NULL) {
        int val = currNode->data;
        if (val % 2 == 0) {
            if (evenStart == NULL) {
                evenStart = currNode;
                evenEnd = evenStart;
            }
            else {
                evenEnd->next = currNode;
                evenEnd = evenEnd->next;
            }
        }
        else {
            if (oddStart == NULL) {
                oddStart = currNode;
                oddEnd = oddStart;
            }
            else {
                oddEnd->next = currNode;
                oddEnd = oddEnd->next;
            }
        }
        currNode = currNode->next;
    }
    if (oddStart == NULL || evenStart == NULL)
        return;
    evenEnd->next = oddStart;
    oddEnd->next = NULL;
    *head = evenStart;
}*/
/*//Remove N-th node from the end of a Linked List
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode * start = new ListNode();
    start -> next = head;
    ListNode* fast = start;
    ListNode* slow = start;     
    for(int i = 1; i <= n; ++i)
        fast = fast->next;
    while(fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return start->next;
}*/
/*//Delete the middle node of LL
struct Node* deleteMid(struct Node* head) {
    if (head == NULL|| head->next == NULL)
        return NULL;
    struct Node* copyHead = head;
    int count = countOfNodes(head);
    int mid = count / 2;
    while (mid-- > 1)
        head = head->next;
    head->next = head->next->next;
    return copyHead;
}*/
/*//sorting a linked list
ListNode* sortLinkedList(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* secondHalf = slow->next;
    slow->next = nullptr;
    ListNode* sortedFirstHalf = sortLinkedList(head);
    ListNode* sortedSecondHalf = sortLinkedList(secondHalf);
    return mergeLists(sortedFirstHalf, sortedSecondHalf);
}
ListNode* mergeLists(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr)
        return l2;
    if (l2 == nullptr)
        return l1;
    if (l1->val <= l2->val) {
        l1->next = mergeLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeLists(l1, l2->next);
        return l2;
    }
}*/
/*// sort a linked list containing 0s, 1s, and 2s
ListNode* sortLinkedList(ListNode* head) {
    int count[3] = {0};
    ListNode* current = head;
    while (current != nullptr) {
        count[current->val]++;
        current = current->next;
    }
    current = head;
    int i = 0;
    while (current != nullptr) {
        if (count[i] == 0)
            i++;
        else {
            current->val = i;
            count[i]--;
            current = current->next;
        }
    }
    return head;
}*/
/*//Find intersection of Two Linked Lists
// Time Complexity: O(2*max(length of list1,length of list2))
node* intersectionPresent(node* head1,node* head2) {
    node *d1 = head1, *d2 = head2;
    while(d1 != d2) {
        d1 = d1 == NULL? head2:d1->next;
        d2 = d2 == NULL? head1:d2->next;
    }
    return d1;
}*/
/*//Add “1” to a number represented as a Linked List.
Node *addOneUtil(Node *head)
{
    Node *res = head;
    Node *temp, *prev = NULL;
    int carry = 1, sum;
    while (head != NULL)
    {
        sum = carry + head->data;
        carry = (sum >= 10) ? 1 : 0;
        sum = sum % 10;
        head->data = sum;
        temp = head;
        head = head->next;
    }
    if (carry > 0)
        temp->next = newNode(carry);
    return res;
}
Node *addOne(Node *head)
{
    head = reverse(head);
    head = addOneUtil(head);
    return reverse(head);
}*/
/*//Add two numbers represented by linked lists
//Time Complexity: O(max(m,n)) || Space Complexity: O(max(m,n))
//after reversing the linked lists these step goes on
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *dummy = new ListNode(); 
    ListNode *temp = dummy; 
    int carry = 0;
    while( (l1 != NULL || l2 != NULL) || carry) {
        int sum = 0; 
        if(l1 != NULL) {
            sum += l1->val; 
            l1 = l1 -> next; 
        }
        if(l2 != NULL) {
            sum += l2 -> val; 
            l2 = l2 -> next; 
        }
        sum += carry; 
        carry = sum / 10; 
        ListNode *node = new ListNode(sum % 10); 
        temp -> next = node; 
        temp = temp -> next; 
    }
    return dummy -> next; 
}*/
/*//Delete all occurrences of a given key in a doubly linked list
void deleteAllOccurOfX(struct Node** head_ref, int x){
    if ((*head_ref) == NULL)
        return;
    struct Node* current = *head_ref;
    struct Node* next;
    while (current != NULL) {
        if (current->data == x) {
            next = current->next;
            deleteNode(head_ref, current);
            current = next;
        }
        else
            current = current->next;
    }
}*/
/*//Remove duplicates from sorted DLL
void removeDuplicates(struct Node** head_ref){
    if ((*head_ref) == NULL)
        return;
    struct Node* current = *head_ref;
    struct Node* next;
    while (current->next != NULL) {
        if (current->data == current->next->data)
            deleteNode(head_ref, current->next);
        else
            current = current->next;
    }
}*/
/*//Reverse a Linked List in group of Given Size.
Node *reverse(Node *head, int k){
    Node *cur = head;
    Node *next = NULL;
    Node *prev = NULL;
    int count = 0;
    while (cur != NULL && count < k){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
        count++;
    }
    if (next != NULL)
        head->next = reverse(next, k);
    return prev;
}*/
/*//Rotate a Linked List
// Time Complexity: O(length of list) + O(length of list – (length of list%k))
node* rotateRight(node* head, int k) {
    if (head == NULL || head->next == NULL || k == 0) return head;
    int length = 1;
    node* tail = head;
    while (tail->next != NULL) {
        length++;
        tail = tail->next;
    }
    k %= length;// Adjust k to avoid unnecessary rotations
    if (k == 0) return head;
    int end = length - k;// Find the new head and break the link at the appropriate position
    node* newHead = head;
    while (end-- > 1) {
        newHead = newHead->next;
    }
    tail->next = head;
    head = newHead->next;
    newHead->next = NULL;
    
    return head;
}*/
/*//Flattening a Linked List
Node* mergeTwoLists(Node* a, Node* b) {
    if (a == NULL) return b;
    if (b == NULL) return a;
    Node* res;
    if (a->data < b->data) {
        res = a;
        res->bottom = mergeTwoLists(a->bottom, b);
    } else {
        res = b;
        res->bottom = mergeTwoLists(a, b->bottom);
    }
    return res;
}
Node* flatten(Node* root) {
    if (root == NULL || root->next == NULL) 
        return root;
    root->next = flatten(root->next);
    return mergeTwoLists(root, root->next);
}*/
