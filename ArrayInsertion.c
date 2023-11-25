#include <stdio.h>

void display(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int indInsertion(int arr[],int size,int element,int capacity,int index){
   if (size>=capacity)
   {
    return -1;
   }
   for (int i = size-1; i >= index; i--)
   {
    arr[i+1]=arr[i];
   }
   arr[index]=element;
   size++;
   return 1;
}

int sortedInsertion(int arr[],int size,int element,int capacity){
if (size>=capacity)
   {
    return -1;
   }
   int index;
   for (int i = 0; i < size-1; i++)
   {
    if (element>arr[i] && element<arr[i+1])
    {
      index=i+1;
      break;
    }
   }
   for (int i = size-1; i >= index; i--)
   {
    arr[i+1]=arr[i];
   }
   arr[index]=element;
   size++;
   return 1;
}

int main(int argc, char const *argv[])
{
    int arr[100] = {1,2,6,78};
    int size = 4,element = 3,index = 3;
    display(arr,size);

    // indInsertion(arr,size,element,100,index);
    // size++;
    // display(arr,size);

    sortedInsertion(arr,size,element,100);
    size++;
    display(arr,size);

    return 0;
}
