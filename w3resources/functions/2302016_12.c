# include <stdio.h>
# define MAX 10
int *maxmin(int[], int);
int main()
{
  	int  arr[MAX], n;
  	printf("Number of inputs: ");
  	scanf("%d",&n);

  	for(int i = 0; i < n; i++) scanf("%d",&arr[i]);
  	int *p = maxmin(arr,n);

	printf("Minimum value is: %d\n",*p++);
	printf("Maximum value is: %d\n",*p);
}
int *maxmin(int arr[], int v)
{
    static int result[2];
    result[0]=arr[0];
    result[1]=arr[0];
    for (int i = 1; i < v; i++)
    {
        if (result[0] > arr[i]) result[0]=arr[i];
        if (result[1]< arr[i]) result[1]= arr[i];
    }
    return result;
}

