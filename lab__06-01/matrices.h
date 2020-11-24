#pragma once

void ** mallocMatrix(int m, int n, size_t typeSize);
void scanIntMatrix(void ** matrix, int m, int n);
void printIntMatrix(void ** matrix, int m, int n);
void swapIntMatrixCols(int ** matrix, int rowCount, int aIdx, int bIdx);
void sortIntMatrixColsByRow(int ** matrix, int rowIdx, int m, int n);
