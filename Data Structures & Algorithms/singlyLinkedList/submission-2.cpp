//implementation for nodes
class ListNode {
public:
    int val;
    ListNode* next;

    //default constructor sets next to nullptr
    ListNode(int val) : val(val), next(nullptr) {}

    //constructor takes in both value and next node
    ListNode(int val, ListNode* next) : val(val), next(next) {}
};

class LinkedList {
private:
    //points to nodes at start and end of singly linked list
    ListNode* head;
    ListNode* tail;

public:
    LinkedList(){
        head = new ListNode(-1);
        tail = head;
    }

    int get(int index) {
        ListNode* current = head->next;
        int i = 0;
        while (current != nullptr) {
            if (i == index) {
                return current->val;
            }
            i++;
            current = current->next;
        }
        return -1;
        //index is out of bounds or the list is empty
    }

    void insertHead(int val) {
       ListNode* newNode = new ListNode(val);
       newNode->next = head->next;
       head->next = newNode;
       if (newNode->next == nullptr) {
        tail = newNode;
       }
    }
    
    void insertTail(int val) {
        //makes current last node point to new node 
        tail->next = new ListNode(val);
        //updates tail pointer to point at the new node
        tail = tail->next;
    }

    //removes node at given index
    bool remove(int index) {
        int i = 0;
        ListNode* current = head;
        //iterates through linked list starting at 0 until current is pointing to null ptr or index is reached
        while (i < index && current != nullptr) {
            i++;
            current = current->next;
        }

        //removes the node ahead of current node
    if (current != nullptr && current->next != nullptr) {
        if (current->next == tail) {
            tail = current;
        }
        ListNode* deletethis = current->next;
        current->next = deletethis->next;
        delete deletethis;
        return true;
    }
    return false;
 }
    


    vector<int> getValues() {
        vector<int> values;
        //node pointer to the first node 
        ListNode* current = head->next;
        //if first node = null ptr, then return empty vector, else, add value of current node to end of vector
        while (current != nullptr) {
            values.push_back(current->val);
            current = current->next;
        }
        return values;
    }
};
