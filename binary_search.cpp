#include "binary_search.h"
#include <iostream>

bool binary_search(int* array, int target, int size) {
	int left = 0;
	int right = size-1;

	while (left <= right) {
		int mid = (left + right) / 2;

		if (array[mid] == target) {
		       return true;
	      	}

		if (array[mid] < target) {
			left = mid + 1;
		}

		else {
			right = mid - 1;
		}
	}
	
	return false;
}

int comp(const int val1, const int val2) {
	return val1 > val2;
}

int* branchless_binary_search(int* array, const int target, const int size) {

	int length = size-1;
	int* start_index = array;

	while (length > 0) {
		int half = length / 2;
		
		array += comp(target, array[half]) * (length - half);
		length = half;
	}

	return array;
}	
