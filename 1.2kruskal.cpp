#include<stdio.h>
#include<string.h>

int n, m;

struct node {
	int x, y, z;
}a[111],temp;

int find(int *p,int f) {
	while (p[f] > 0) {
		f = p[f];
	}
	return f;
}

void kruskal() {
	int parent[111] = { 0 }, q , w;
	for (int i = 0; i < m; i++) {
		q = find(parent,a[i].x);
		w = find(parent,a[i].y);
		if (q != w) {
			parent[q] = w;
			printf("%d->%d ", a[i].x, a[i].y);
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a[i].x, &a[i].y, &a[i].z);
	}
	for (int i = 0; i < m - 1; i++) {
		for (int j = i + 1; j < m; j++) {
			if (a[i].z > a[j].z) {
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	kruskal();
	return 0;
}