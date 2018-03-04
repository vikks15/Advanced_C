//#1 var 2
#include "stdio.h"
#include "stdlib.h"

int main() {
	int array_size = 0;
	int begin_index = 0;
	int index1 = 0, index2 = 0, max_segment_size = 0;
	scanf("%d", &array_size);

	if (array_size <= 0)
	{
		perror("[error]");
		//printf("%s", "[error]");
		return 0;
	}

	int* array = (int *) malloc(array_size * sizeof(int));
	scanf("%d", &array[0]); //reading first number

	int temp_size = 0;

	for(int i = 1; i < array_size; ++i){

		scanf("%d", &array[i]);
		
		if (array[i] == array[i-1] + 1)
		{
			temp_size++;

			if ((i == array_size - 1) && (temp_size + 1 > max_segment_size))
				{
					index1 = begin_index;
					index2 = i + 1; //last element
					max_segment_size = ++temp_size;
				}	
		}
		else
		{
			if (temp_size + 1 > max_segment_size) {
				max_segment_size = ++temp_size;
				index1 = begin_index;
				index2 = i;
				begin_index = i;
			}
			else begin_index = i;
			temp_size = 0;
		}

	printf("%s ", "temp_size");
	printf("%d\n", temp_size);
	printf("%s ", "max_segment_size");
	printf("%d\n", max_segment_size);
	}

	printf("%s ", "index1");
	printf("%d ", index1);
	printf("%s ", "index2");
	printf("%d\n", index2);

	if ((max_segment_size == 1) | (max_segment_size == 0)) printf("%d\n", 0);
	else
	{
		printf("%d\n", max_segment_size);

		for(int i = index1; i < index2; ++i)
			printf("%d ", array[i]);
	} 

	free(array);
	return 0;
}