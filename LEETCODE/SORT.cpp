#include "SORT.h"

void Sort::selectionSort(vector<int>& nums)
{
	if (nums.size() == 0) return;
	for (int i = 0; i < nums.size() - 1; ++i) {
		int minIndex = i;
		for (int j = i + 1; j < nums.size(); ++j) {
			minIndex = nums[j] < nums[minIndex] ? j : minIndex;
		}
		swap(nums[i], nums[minIndex]);
	}
}

void Sort::bubbleSort(vector<int>& nums)
{
	if (nums.size() == 0) return;
	for (int i = nums.size() - 1; i > 0; --i) {
		for (int j = 0; j < i; ++j) {
			if (nums[j] > nums[j + 1]) {
				swap(nums[j], nums[j + 1]);
			}
		}
	}
}

void Sort::intersectionSort(vector<int>& nums)
{
	if (nums.size() == 0) return;
	for (int i = 1; i < nums.size(); ++i) {
		for (int j = i - 1; j >= 0 && nums[j] > nums[j + 1]; --j) {
			swap(nums[j], nums[j + 1]);
		}
	}
}

void merge(vector<int>& nums, int l, int m, int r) {
	vector<int> result(r - l + 1);
	int i = 0;
	int p1 = l;
	int p2 = m + 1;
	while (p1 <= m && p2 <= r) result[i++] = nums[p1] <= nums[p2] ? nums[p1++] : nums[p2++];
	while (p1 <= m) result[i++] = nums[p1++];
	while (p2 <= r) result[i++] = nums[p2++];
	for (int i = 0; i < result.size(); i++) nums[l + i] = result[i];
}

void Sort::mergeSort(vector<int>& nums, int l, int r)
{
	if (l == r) return;
	int mid = l + ((r - l) >> 1);
	mergeSort(nums, l, mid);
	mergeSort(nums, mid + 1, r);
	merge(nums, l, mid, r);
}

vector<int> partition(vector<int>& nums, int l, int r) {
	int less = l - 1;
	int more = r;
	while (l < more) {
		if (nums[l] < nums[r]) swap(nums[++less], nums[l++]);
		else if (nums[l] > nums[r]) swap(nums[--more], nums[l]);
		else l++;
	}
	swap(nums[more], nums[r]);
	return { less + 1, more };
}
void Sort::quickSort(vector<int>& nums, int l, int r)
{
	if (l < r) {
		//int randnum = l + rand() * (r - l + 1);
		//std::swap(nums[randnum], nums[r]);
		vector<int> p = partition(nums, l, r);
		quickSort(nums, l, p[0] - 1);
		quickSort(nums, p[1] + 1, r);
	}
}

void heapInsert(vector<int>& nums, int index) {
	while (nums[index] > nums[(index - 1) / 2]) {
		swap(nums[index], nums[(index - 1) / 2]);
		index = (index - 1) / 2;
	}
}
void heapify(vector<int>& nums, int index, int heapSize) {
	int l = index * 2 + 1;
	while (l < heapSize) {
		int largest = l + 1 < heapSize && nums[l + 1] > nums[l] ? l + 1 : l;
		largest = nums[largest] > nums[index] ? largest : index;
		if (largest == index) break;
		swap(nums[largest], nums[index]);
		index = largest;
		l = index * 2 + 1;
	}
}
void Sort::heapSort(vector<int>& nums)
{
	if (nums.size() == 0) return;
	for (int i = 0; i < nums.size(); ++i) heapInsert(nums, i);
	int heapSize = nums.size();
	swap(nums[0], nums[--heapSize]);
	while (heapSize > 0) {
		heapify(nums, 0, heapSize);
		swap(nums[0], nums[--heapSize]);
	}
}
/***************************************************************/
void test_mergesort()
{
	Sort ms;
	vector<int> nums = { 4,2,3,6,4,1 };
	ms.mergeSort(nums,0,nums.size() - 1);
}

void test_quicksort()
{
	Sort qs;
	vector<int> nums = { 4,2,3,6,4,1 };
	qs.quickSort(nums, 0, nums.size() - 1);
}

void test_heapsort()
{
	Sort hs;
	vector<int> nums = { 4,2,3,6,4,1 };
	hs.heapSort(nums);
}

void test_bubblesort()
{
	Sort bs;
	vector<int> nums = { 4,2,3,6,4,1 };
	bs.bubbleSort(nums);
}

void test_selectionsort()
{
	Sort ss;
	vector<int> nums = { 4,2,3,6,4,1 };
	ss.selectionSort(nums);
}

void test_intersectionsort()
{

}
