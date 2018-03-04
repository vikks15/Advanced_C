#include "stdio.h"
#include "stdlib.h"

int Find_max_subsequence (int* array, int array_size, int* index1, int* index2) {
	int maxsize = 0, temp_max_size = 0, begin_index = 0;

	for(int i = 1; i < array_size; ++i){
		
		if (array[i] == array[i-1] + 1)
		{
			temp_max_size++;

			if ((i == array_size - 1) && (temp_max_size + 1 > maxsize))
				{
					*index1 = begin_index;
					*index2 = i + 1; //last element
					maxsize = ++temp_max_size;
				}	
		}
		else
		{
			if (temp_max_size + 1 > maxsize) {
				maxsize = ++temp_max_size;
				*index1 = begin_index;
				*index2 = i;
				begin_index = i;
			}
			else begin_index = i;
			temp_max_size = 0;
		}
	}

	return maxsize;
}

int main() {

	int array_size = 0;
	scanf("%d", &array_size);

	if (array_size <= 0)
	{
		printf("%s", "[error]");
		return 0;
	}

	int* array = (int *) malloc(array_size * sizeof(int));

	for(int i = 0; i < array_size; ++i) {

		if (scanf("%d", &array[i]) < 1) {  //right input check
		printf("%s", "[error]");
		free(array);
		return 0;
		}

	}
	int index1 = 0, index2 = 0;
	int max_segment_size = Find_max_subsequence(array, array_size, &index1, &index2);

	if ((max_segment_size == 1) | (max_segment_size == 0)) printf("%d\n", 0);
	else {
		printf("%d\n", max_segment_size);
		for( ; index1 < index2; ++index1) printf("%d ", array[index1]);
	}

	free(array);
	return 0;
}