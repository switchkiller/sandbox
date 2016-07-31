/*
The structure of the node of the queue is
struct QueueNode
{
    int data;
    QueueNode *next;
};


and the structure of the class is
class Queue {
private:
    QueueNode *front;
    QueueNode *rear;
public :
    void push(int);
    int pop();
};

 */

/* The method push to push element into the queue*/
void Queue:: push(int x)
{
        // Your Code
        QueueNode *queue = new QueueNode;
        queue->data = x;
        queue->next = NULL;
        if (this->front == NULL){
            this->rear = this->front = queue;
        }
        else{
            this->rear->next = queue;
            this->rear = queue;
        }
}

/*The method pop which return the element poped out of the queue*/
int Queue :: pop()
{
        // Your Code
        if (front == NULL)
            return -1;
        QueueNode *queue = front;
        int x = queue->data;
        this->front = queue->next;
        if (this->front == NULL)
            this->rear = NULL;
        free(queue);
        return x;
}
