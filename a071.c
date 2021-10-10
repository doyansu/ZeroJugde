#include <stdio.h>
#include <stdlib.h>
#define MAXINF 0x7fffffff

typedef struct memory_s{
    int address, size, timeLeft;
    struct memory_s *next;
}memory_t;

typedef memory_t* memoryp_t;

memoryp_t createNewMemory(int address, int size, int time){
    memoryp_t newMem = malloc(sizeof(memory_t));
    newMem->address = address;
    newMem->size = size;
    newMem->timeLeft = time;
    newMem->next = NULL;
    return newMem;
}

static inline void freeMemory(memoryp_t mem, int time){
    memoryp_t temp;
    while(mem && mem->next){
        if((mem->next->timeLeft -= time) < 0){
            temp = mem->next;
            mem->next = temp->next;
            free(temp);
        }
        else
            mem = mem->next;
    }
}

memoryp_t insertFormEnd(memoryp_t end, memoryp_t now){
    return end->next = now;
}

static inline memoryp_t queryMemory(memoryp_t mem, memoryp_t now){
    while(mem->size < MAXINF){
        if(mem->next->address - mem->address - mem->size >= now->size)
            return mem;
        mem = mem->next;
    }
    return NULL;
}

static inline void checkQueue(memoryp_t mem, memoryp_t queue) {
    memoryp_t inser, temp;
    if(queue->next && (inser = queryMemory(mem, queue->next))){
        temp = queue->next;
        temp->address = inser->address + inser->size;
        queue->next = temp->next;
        temp->next = inser->next;
        inser->next = temp;
        checkQueue(mem, queue);
    }
}

static inline int searchMinTime(memoryp_t mem){
    int min = MAXINF;
    while(mem->size < MAXINF){
        if(mem->timeLeft < min)
            min = mem->timeLeft;
        mem = mem->next;
    }
    return min + 1;
}

void putmem(memoryp_t inser, int lastime){
    printf("\nmem time = %d\n", lastime);
    while(inser){
        printf("%d %d %d\n", inser->address, inser->size, inser->timeLeft);
        inser = inser->next;
    }
    putchar('\n');
}

int main() {
    int nowt, m, p, lastime = 0;
    scanf("%d", &m);
    memoryp_t memory = createNewMemory(0, 0, MAXINF), queue = createNewMemory(-1, -1, 0);
    memoryp_t queueEnd = queue, now, temp;
    memory->next = createNewMemory(m, MAXINF, MAXINF);

    while(scanf("%d%d%d", &nowt, &m, &p) == 3 && (nowt || m || p)){
        now = createNewMemory(nowt, m, p - 1);
        for(;lastime <= nowt; lastime++){
            freeMemory(memory, 1);
            checkQueue(memory, queue);
            if(queue->next == NULL)
                queueEnd = queue;
        }
        if(temp = queryMemory(memory, now)){
            now->address = temp->address + temp->size;
            now->next = temp->next;
            temp->next = now;
        }
        else{
            queueEnd = insertFormEnd(queueEnd, now);
            (queue->timeLeft)++;
        }
    }

    int min;
    while(memory->next->size < MAXINF){
        freeMemory(memory, min = searchMinTime(memory));
        checkQueue(memory, queue);
        lastime += min;
    }

    printf("%d\n%d\n", lastime - 1, queue->timeLeft);
	return 0;
}


/*#include <stdio.h>//AC (0.5s, 376KB)
#include <stdlib.h>
#define MAXINF 0x7fffffff

typedef struct memory_s{
    int address, size, timeLeft;
    struct memory_s *next;
}memory_t;

typedef memory_t* memoryp_t;

memoryp_t createNewMemory(int address, int size, int time){
    memoryp_t newMem = malloc(sizeof(memory_t));
    newMem->address = address;
    newMem->size = size;
    newMem->timeLeft = time;
    newMem->next = NULL;
    return newMem;
}

void freeMemory(memoryp_t mem, int time){
    memoryp_t temp;
    while(mem && mem->next){
        if((mem->next->timeLeft -= time) < 0){
            temp = mem->next;
            mem->next = temp->next;
            free(temp);
        }
        else
            mem = mem->next;
    }
}

memoryp_t insertFormEnd(memoryp_t end, memoryp_t now){
    return end->next = now;
}

memoryp_t queryMemory(memoryp_t mem, memoryp_t now){
    while(mem->size < MAXINF){
        if(mem->next->address - mem->address - mem->size >= now->size)
            return mem;
        mem = mem->next;
    }
    return NULL;
}

void checkQueue(memoryp_t mem, memoryp_t queue) {
    memoryp_t inser, temp;
    if(queue->next && (inser = queryMemory(mem, queue->next))){
        temp = queue->next;
        temp->address = inser->address + inser->size;
        queue->next = temp->next;
        temp->next = inser->next;
        inser->next = temp;
        checkQueue(mem, queue);
    }
}

void putmem(memoryp_t inser, int lastime){
    printf("\nmem time = %d\n", lastime);
    while(inser){
        printf("%d %d %d\n", inser->address, inser->size, inser->timeLeft);
        inser = inser->next;
    }
    putchar('\n');
}

int main() {
    int nowt, m, p, lastime = 0;
    scanf("%d", &m);
    memoryp_t memory = createNewMemory(0, 0, MAXINF), queue = createNewMemory(-1, -1, 0), queueEnd = queue, now, inser;
    memory->next = createNewMemory(m, MAXINF, MAXINF);
    while(scanf("%d%d%d", &nowt, &m, &p) == 3 && (nowt || m || p)){
        now = createNewMemory(nowt, m, p - 1);
        for(;lastime <= nowt; lastime++){
            freeMemory(memory, 1);
            checkQueue(memory, queue);
            if(queue->next == NULL)
                queueEnd = queue;
        }
        if(inser = queryMemory(memory, now)){
            now->address = inser->address + inser->size;
            now->next = inser->next;
            inser->next = now;
        }
        else{
            queueEnd = insertFormEnd(queueEnd, now);
            (queue->timeLeft)++;
        }
    }
    for(; memory->next->size < MAXINF; lastime++){
        freeMemory(memory, 1);
        checkQueue(memory, queue);
    }

    printf("%d\n%d\n", lastime - 1, queue->timeLeft);
	return 0;
}*/




/*#include <stdio.h>// NA (score:20%)
#include <stdlib.h>
#define MAXINF 0x7fffffff

typedef struct memory_s{
    int address, size, timeLeft;
    struct memory_s *next;
}memory_t;

typedef memory_t* memoryp_t;

memoryp_t createNewMemory(int address, int size, int time){
    memoryp_t newMem = malloc(sizeof(memory_t));
    newMem->address = address;
    newMem->size = size;
    newMem->timeLeft = time;
    newMem->next = NULL;
    return newMem;
}

void freeMemory(memoryp_t mem, int time){
    memoryp_t temp;
    while(mem && mem->next){
        if((mem->next->timeLeft -= time) < 0){
            temp = mem->next;
            mem->next = temp->next;
            free(temp);
        }
        else
            mem = mem->next;
    }
}

memoryp_t insertFormEnd(memoryp_t end, memoryp_t now){
    return end->next = now;
}

memoryp_t queryMemory(memoryp_t mem, memoryp_t now){
    while(mem->size < MAXINF){
        if(mem->next->address - mem->address - mem->size >= now->size)
            return mem;
        mem = mem->next;
    }
    return NULL;
}

void checkQueue(memoryp_t mem, memoryp_t queue) {
    memoryp_t inser, temp;
    if(queue->next && (inser = queryMemory(mem, queue->next))){
        temp = queue->next;
        temp->timeLeft -= 1;
        temp->address = inser->address + inser->size;
        queue->next = temp->next;
        temp->next = inser->next;
        inser->next = temp;
        //checkQueue(mem, queue);
    }
}

void putmem(memoryp_t inser, int lastime){
    printf("\nmem time = %d\n", lastime);
    while(inser){
        printf("%d %d %d\n", inser->address, inser->size, inser->timeLeft);
        inser = inser->next;
    }
    putchar('\n');
}

int main() {
    int nowt, m, p, lastime = 0;
    scanf("%d", &m);
    memoryp_t memory = createNewMemory(0, 0, MAXINF), queue = createNewMemory(-1, -1, 0), queueEnd = queue, now, inser;
    memory->next = createNewMemory(m, MAXINF, MAXINF);

    while(scanf("%d%d%d", &nowt, &m, &p) == 3 && (nowt || m || p)){
        now = createNewMemory(nowt, m, p);

        for(;lastime < nowt; lastime++){
            freeMemory(memory, 1);
            checkQueue(memory, queue);
            if(queue->next == NULL)
                queueEnd = queue;
            //putmem(memory->next, lastime);
        }

        if(inser = queryMemory(memory, now)){
            now->address = inser->address + inser->size;
            now->next = inser->next;
            inser->next = now;
        }
        else{
            queueEnd = insertFormEnd(queueEnd, now);
            (queue->timeLeft)++;
        }

        //putmem(memory->next, lastime);

    }
    for(; memory->next->size < MAXINF; lastime++){
        freeMemory(memory, 1);
        checkQueue(memory, queue);

        //putmem(memory->next, lastime);
    }

    printf("%d\n%d\n", lastime - 1, queue->timeLeft);
	return 0;
}*/

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXINF 0x7fffffff

typedef struct memory_s{
    int address, size, timeLeft;
    struct memory_s *next;
}memory_t;

typedef memory_t* memoryp_t;

memoryp_t createNewMemory(int address, int size, int time){
    memoryp_t newMem = malloc(sizeof(memory_t));
    newMem->address = address;
    newMem->size = size;
    newMem->timeLeft = time;
    newMem->next = NULL;
    return newMem;
}

void freeMemory(memoryp_t mem, int time){
    memoryp_t temp;
    while(mem && mem->next){
        if((mem->next->timeLeft -= time) <=  0){
            temp = mem->next;
            mem->next = temp->next;
            free(temp);
        }
        mem = mem->next;
    }
}

memoryp_t insertFormEnd(memoryp_t end, memoryp_t now){
    return end->next = now;
}

memoryp_t queryMemory(memoryp_t mem, memoryp_t now){
    while(mem->size < MAXINF){
        if(mem->next->address - mem->address - mem->size >= now->size)
            return mem;
        mem = mem->next;
    }
    return NULL;
}

void checkQueue(memoryp_t mem, memoryp_t queue) {
    memoryp_t inser, temp;
    while(queue && queue->next){
        if(inser = queryMemory(mem, queue->next)){
            temp = queue->next;
            temp->address = inser->address + inser->size;
            //temp->timeLeft -= 1;
            queue->next = temp->next;
            temp->next = inser->next;
            inser->next = temp;
        }
        queue = queue->next;
    }
}


int main() {
    int nowt, m, p, lastime = 0;
    scanf("%d", &m);
    memoryp_t memory = createNewMemory(0, 0, MAXINF), queue = createNewMemory(-1, -1, 0), queueEnd = queue, now, inser;
    memory->next = createNewMemory(m, MAXINF, MAXINF);
    while(scanf("%d%d%d", &nowt, &m, &p) == 3 && nowt && m && p){
        now = createNewMemory(nowt, m, p);
        freeMemory(memory, nowt - lastime);
        checkQueue(memory, queue);
        if(queue->next == NULL)
            queueEnd = queue;
        if(inser = queryMemory(memory, now)){
            now->address = inser->address + inser->size;
            //now->timeLeft -= 1;
            now->next = inser->next;
            inser->next = now;
        }
        else{
            queueEnd = insertFormEnd(queueEnd, now);
            (queue->timeLeft)++;
        }
        lastime = nowt;
    }

    int max = 0;
    inser = memory;
    while((inser = inser->next)->size < MAXINF){
        if(inser->timeLeft > max)
            max = inser->timeLeft;
    }
    puts("mem");
    while(memory){
        printf("%d %d %d\n", memory->address, memory->size, memory->timeLeft);
        memory = memory->next;
    }
    puts("queue");
    while(queue){
        printf("%d %d %d\n", queue->address, queue->size, queue->timeLeft);
        queue = queue->next;
    }
    printf("\n%d\n%d", lastime, queue->timeLeft);
	return 0;
}
*/
