struct Queue {
    int *arr;
    int front, rear, size, capacity;
};

struct Queue* createQueue(int capacity) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->arr = (int*)malloc(capacity * sizeof(int));
    q->capacity = capacity;
    q->front = q->size = 0;
    q->rear = -1;
    return q;
}

void enqueue(struct Queue* q, int value) {
    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = value;
    q->size++;
}

int dequeue(struct Queue* q) {
    int value = q->arr[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return value;
}

int getFront(struct Queue* q) {
    return q->arr[q->front];
}

int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize) {
    struct Queue* q = createQueue(studentsSize);
    for(int i = 0; i < studentsSize; i++) {
        enqueue(q, students[i]);
    }
    
    int count = 0, i = 0;
    while(count < q->size && i < sandwichesSize) {
        if(sandwiches[i] == getFront(q)) {
            dequeue(q);
            i++;
            count = 0;
        } else {
            enqueue(q, dequeue(q));
            count++;
        }
    }
    
    int result = q->size;
    free(q->arr);
    free(q);
    return result;
    }