#include<stdio.h>
#include<stdlib.h>
struct item {
	int id; //����
	int start;//���ʼʱ��
	int end;//�����ʱ��
};
void swap(struct item* x, struct item* y) {
	struct item t;
	t = *x;
	*x = *y;
	*y = t;
}
void preduce(struct item A[], int i, int n) {
	int x = A[i].end;
	struct item y = A[i];
	int child, parent;
	for (parent = i; (parent * 2 + 1) < n; parent = child) {
		child = parent * 2 + 1;
		if ((child != n - 1) && (A[child].end < A[child + 1].end)) {
			child++;
		}
		if (x >= A[child].end) {
			break;
		}
		else
			A[parent] = A[child];
	}
	A[parent] = y;
}
void heapsort(struct item A[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--) {
		preduce(A, i, n);
	}
	for (int i = n - 1; i > 0; i--) {
		swap(&A[0], &A[i]);
		preduce(A, 0, i);
	}
}
int main() {
	int n;//�����
	int maxsize = 1;//����ж��ٸ��
	int  ei;//��ʼ����ʱ��
	struct item act[100];
	struct item x[100];
	int id = 0;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d %d %d", &act[i].id, &act[i].start, &act[i].end);
	}
	//����ֹʱ����ж�����
	heapsort(act, n);

	ei = act[0].end;
	x[id] = act[0];

	//�ж��Ƿ������
	for (int i = 1; i <= n - 1; i++) {
		if (act[i].start > ei) {
			maxsize++;
			x[++id] = act[i];
			ei = act[i].end;
		}
	}
	printf("%d\n", maxsize);
	for (int i = 0; i < maxsize; i++) {
		printf("%d %d %d\n", x[i].id, x[i].start, x[i].end);
	}
}