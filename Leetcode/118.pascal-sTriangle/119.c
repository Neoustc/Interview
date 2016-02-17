int* getRow(int rowIndex, int* returnSize) {
    int *array = (int*)malloc((rowIndex+1)*sizeof(int));
    //memset(array, 0, sizeof(int) * (rowIndex + 1));
    for (int i = 0; i < rowIndex + 1; ++i)
    array[i] = 1;
    for(int i = 2;i<=rowIndex;i++)
    	for(int j = i - 1;j>0;j--)
    		array[j]+= array[j-1];
    *returnSize = rowIndex+1;
    return array;
}
