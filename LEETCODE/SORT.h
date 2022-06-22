#pragma once

#include <vector>
#include <algorithm>

using namespace std;

/*
				 时间			空间			稳定性
	选择		    O(N^2)			O(1)		  ×
	冒泡			O(N^2)			O(1)		  √
	插入			O(N^2)			O(1)		  √
	归并			O(N*logN)		O(N)		  √
	快速			O(N*logN)		O(N)		  ×
	堆			O(N*logN)		O(N)		  ×
*/


class Sort {
public:
	void selectionSort(vector<int>& nums);
	void bubbleSort(vector<int>& nums);
	void intersectionSort(vector<int>& nums);
	void mergeSort(vector<int>& nums, int l, int r);
	void quickSort(vector<int>& nums, int l, int r);
	void heapSort(vector<int>& nums);
};


void test_bubblesort();
void test_selectionsort();
void test_intersectionsort();
void test_mergesort();
void test_quicksort();
void test_heapsort();
