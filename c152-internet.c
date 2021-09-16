#pragma warning (disable:4996)

#include <stdio.h>
#include <stdlib.h>
#define MAXN 10000
#define INF 2147483647
int vNum, eNum, srcIdx, dstIdx;

typedef struct lnode {
	int destination;
	int distance;
	int velocity;
	struct lnode* next;
	double costTime;
}ListNode;

typedef struct gnode {
	int reachCost_dis;
	struct lnode* lhead;
	struct lnode* ltail;
	double reachCost_time;
}GraphNode;
GraphNode graph[MAXN + 1];

typedef struct qnode {
	int idx;
	struct qnode* next;
}QueueNode;
QueueNode* qhead;
QueueNode* qtail;

static inline void readNonNegativeInt(int* const);
static inline void printNonNegativeInt(const int* const);
inline void initialize();
inline void insertEdge(const int* const, const int* const, const int* const, const int* const);
inline void solve();

static inline void readNonNegativeInt(int* const integer) {
	static char ch;
	while ((ch = getchar()) < 48 || ch > 57);

	if (ch < 48 || ch > 57)
		return;

	(*integer) = ch - 48;
	while ((ch = getchar()) >= 48 && ch <= 57)
		(*integer) = ((*integer) * 10) + (ch - 48);

	return;
}

static inline void printNonNegativeInt(const int* const integer) {
	if (*integer == 0) {
		putchar('0');
		return;
	}

	static char str[22];
	static int idx;
	static int number;

	number = *integer;
	idx = 0;

	while (number > 0) {
		str[idx++] = number % 10;
		number /= 10;
	}

	while (idx)
		putchar(str[--idx] + 48);

	return;
}

inline void initialize() {
	for (int k = 0; k <= vNum; ++k) {
		ListNode* p = graph[k].lhead;
		ListNode* q;
		while (p != NULL) {
			q = p;
			p = p->next;
			free(q);
		}

		graph[k].lhead = graph[k].ltail = NULL;
		graph[k].reachCost_dis = INF;
		graph[k].reachCost_time = (double)INF;
	}
	qhead = qtail = NULL;

	return;
}

inline void insertEdge(const int* const u, const int* const v, const int* const dis, const int* const vel) {
	ListNode* newListNode = (ListNode*)malloc(sizeof(ListNode));
	newListNode->destination = *v;
	newListNode->distance = *dis;
	newListNode->velocity = *vel;
	newListNode->costTime = (double)(*dis) / *vel;
	newListNode->next = NULL;

	if (graph[*u].lhead == NULL) {
		graph[*u].lhead = newListNode;
		graph[*u].ltail = newListNode;
	}
	else {
		graph[*u].ltail->next = newListNode;
		graph[*u].ltail = graph[*u].ltail->next;
	}

	return;
}

inline void solve() {
	QueueNode* newQHeadNode = (QueueNode*)malloc(sizeof(QueueNode));
	newQHeadNode->idx = srcIdx;
	newQHeadNode->next = NULL;

	qhead = newQHeadNode;
	qtail = newQHeadNode;
	graph[srcIdx].reachCost_dis = 0;

	while (qhead != NULL) {
		ListNode* p = graph[qhead->idx].lhead;
		while (p != NULL) {
			if(graph[qhead->idx].reachCost_dis + p->distance < graph[p->destination].reachCost_dis) {
				graph[p->destination].reachCost_dis = graph[qhead->idx].reachCost_dis + p->distance;

				QueueNode* newQNode = (QueueNode*)malloc(sizeof(QueueNode));
				newQNode->idx = p->destination;
				newQNode->next = NULL;

				qtail->next = newQNode;
				qtail = qtail->next;
			}

			p = p->next;
		}

		QueueNode* qt = qhead;
		qhead = qhead->next;
		free(qt);
	}
	printNonNegativeInt(&(graph[dstIdx].reachCost_dis)), putchar(' ');

	// =====================================================================

	newQHeadNode = (QueueNode*)malloc(sizeof(QueueNode));
	newQHeadNode->idx = srcIdx;
	newQHeadNode->next = NULL;

	qhead = newQHeadNode;
	qtail = newQHeadNode;
	graph[srcIdx].reachCost_time = 0.0;

	while (qhead != NULL) {
		ListNode* p = graph[qhead->idx].lhead;
		while (p != NULL) {
			if (graph[qhead->idx].reachCost_time + p->costTime < graph[p->destination].reachCost_time) {
				graph[p->destination].reachCost_time = graph[qhead->idx].reachCost_time + p->costTime;
				graph[p->destination].reachCost_dis = graph[qhead->idx].reachCost_dis + p->distance;

				QueueNode* newQNode = (QueueNode*)malloc(sizeof(QueueNode));
				newQNode->idx = p->destination;
				newQNode->next = NULL;

				qtail->next = newQNode;
				qtail = qtail->next;
			}

			p = p->next;
		}

		QueueNode* qt = qhead;
		qhead = qhead->next;
		free(qt);
	}
	printNonNegativeInt(&(graph[dstIdx].reachCost_dis)), putchar('\n');

	return;
}

int main() {
	int kase;
	readNonNegativeInt(&kase);

	int u, v, dis, vel;
	while (kase--) {
		readNonNegativeInt(&vNum), readNonNegativeInt(&eNum),
		readNonNegativeInt(&srcIdx), readNonNegativeInt(&dstIdx);

		initialize();

		for (int m = 0; m < eNum; ++m) {
			readNonNegativeInt(&u),
			readNonNegativeInt(&v),
			readNonNegativeInt(&dis),
			readNonNegativeInt(&vel);

			insertEdge(&u, &v, &dis, &vel);
			insertEdge(&v, &u, &dis, &vel);
		}

		solve();
	}

	return 0;
}


