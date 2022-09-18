struct queue;
typedef struct queue queue;

queue *hiq(int size)          ;
void byeq(queue *q)           ;
void enq(queue *q, void *dat) ;
void deq(queue *q, void *dat) ;
