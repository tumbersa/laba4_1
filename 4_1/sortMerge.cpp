#include "sortMerge.h"
void sortMerge::merge(int* A, int* B, int p, int q, int n) {
	int in_pos1 = p, in_pos2 = q + 1, out_pos = 0;
	while (in_pos1 < q && in_pos2 <= n) {
		if (A[in_pos1] < A[in_pos2])
			B[out_pos++] = A[in_pos1++];
		else
			B[out_pos++] = A[in_pos2++];
	}
	while (in_pos1 <= q)
		B[out_pos++] = A[in_pos1++];
	while (in_pos2 <= n)
		B[out_pos++] = A[in_pos2++];
	for (int i = 0; i < n - p + 1; i++)
		A[p + i] = B[i];
}

void sortMerge::mergeSort(int* A, int* B, int p, int n) {
	if (p < n) {
		int q = (p + n) / 2;
		mergeSort(A, B, p, q);
		mergeSort(A, B, q + 1, n);
		merge(A, B, p, q, n);
	}
}