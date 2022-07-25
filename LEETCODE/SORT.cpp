#include "SORT.h"
/*
	从0开始一层循环
	二层循环从开始位置+1和开始位置比较，
*/
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
/*
	相邻的数字交换，每次最后位置冒出一个最大的
*/
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
/*
	向前交换，和插扑克一样，内循环很少
*/
void Sort::intersectionSort(vector<int>& nums)
{
	if (nums.size() == 0) return;
	for (int i = 1; i < nums.size(); ++i) {//想要0~i范围有序
		for (int j = i - 1; j >= 0 && nums[j] > nums[j + 1]; --j) {
			swap(nums[j], nums[j + 1]);
		}
	}
}

void merge(vector<int>& nums, int l, int m, int r) {//左：l ~ m 右：m+1 ~ r
	vector<int> result(r - l + 1);//辅助空间
	int i = 0;//辅助空间的索引
	int p1 = l;//左边的第一个索引
	int p2 = m + 1;//右边的第一个索引
	while (p1 <= m && p2 <= r) result[i++] = nums[p1] <= nums[p2] ? nums[p1++] : nums[p2++];//都不越界，谁小拷贝谁
	while (p1 <= m) result[i++] = nums[p1++];//p1没越界，把p1剩余的拷贝到result中
	while (p2 <= r) result[i++] = nums[p2++];//p2没越界，把p2剩余的拷贝到result中
	for (int i = 0; i < result.size(); i++) nums[l + i] = result[i];//把result拷贝到nums中
}

/*
	中点求出来，递归左面排好序，递归右面排好序，利用两个下标，按顺序将左右的数字拷贝到复制空间
*/
void Sort::mergeSort(vector<int>& nums, int l, int r)
{
	if (l == r) return;
	int mid = l + ((r - l) >> 1);
	mergeSort(nums, l, mid);
	mergeSort(nums, mid + 1, r);
	merge(nums, l, mid, r);
}

/*
	
*/
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
/*
	找最后的一个数作为划分值，每次搞定一个数
*/
void Sort::quickSort(vector<int>& nums, int l, int r)
{
	if (l < r) {
		//int randnum = l + rand() * (r - l + 1);
		//std::swap(nums[randnum], nums[r]);
		vector<int> p = partition(nums, l, r);
		quickSort(nums, l, p[0] - 1);//小于区域
		quickSort(nums, p[1] + 1, r);//大于区域
	}
}

void heapInsert(vector<int>& nums, int index) {
	while (nums[index] > nums[(index - 1) / 2]) {
		swap(nums[index], nums[(index - 1) / 2]);
		index = (index - 1) / 2;
	}
}
void heapify(vector<int>& nums, int index, int heapSize) {
	int l = index * 2 + 1;//左孩子的下标
	while (l < heapSize) {//下方还有孩子
		//右孩子如果有，并且比左孩子大，largest变成他的下标，否则就是左孩子
		int largest = l + 1 < heapSize && nums[l + 1] > nums[l] ? l + 1 : l;
		//较大孩子的值和父亲pk，谁大，下标给largest
		largest = nums[largest] > nums[index] ? largest : index;
		if (largest == index) break;
		swap(nums[largest], nums[index]);
		index = largest;
		l = index * 2 + 1;
	}
}
void Sort::heapSort(vector<int>& nums)
{
	//先让所有树变成大根堆
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
