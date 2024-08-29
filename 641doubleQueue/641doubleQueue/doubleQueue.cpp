typedef struct node* ptr;
struct node {
    int val;
    ptr prev;
    ptr next;
};

class MyCircularDeque {
private:
    ptr head, rear;
    int maxSize;
    int size;
    ptr newNode(int val, ptr prev, ptr next) {
        ptr pnode = new node;
        pnode->val = val;
        pnode->next = next;
        pnode->prev = prev;
        return pnode;
    }
public:
    MyCircularDeque(int k) {
        head = nullptr;
        rear = nullptr;
        maxSize = k;
        size = 0;
    }

    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        if (!head) {
            // if the queue is empty
            head = newNode(value, nullptr, nullptr);
            rear = head;
        }
        else {
            // if the queue is not empty
            head->prev = newNode(value, nullptr, head);
            head = head->prev;
        }
        size++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        if (!rear) {
            // if the queue is empty
            rear = newNode(value, nullptr, nullptr);
            head = rear;
        }
        else {
            rear->next = newNode(value, rear, nullptr);
            rear = rear->next;
        }
        size++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) {
            // queue is empty, delete failed;
            return false;
        }
        else if (head == rear) {
            delete(head);
            head = rear = nullptr;
        }
        else {
            ptr temp = head;
            head = head->next;
            head->prev = nullptr;
            delete(temp);
        }
        size--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) {
            // queue is empty, delete failed;
            return false;
        }
        else if (head == rear) {
            // if only one node
            delete rear;
            rear = head = nullptr;
        }
        else {
            ptr temp = rear;
            rear = rear->prev;
            rear->next = nullptr;
            delete(temp);
        }
        size--;
        return true;
    }

    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        else {
            return head->val;
        }
    }

    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        else {
            return rear->val;
        }
    }

    bool isEmpty() {
        return !size;
    }

    bool isFull() {
        return (size == maxSize);
    }
};