#pragma once

void ** mallocMatrix(int m, int n, size_t typeSize);
void scanIntMatrix(int ** matrix, int m, int n);
void printIntMatrix(int ** matrix, int m, int n);
int getSumOfMatrixCol(int ** matrix, int m, int colIdx);