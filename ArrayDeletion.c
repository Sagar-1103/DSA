#include <stdio.h>

void display(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int indDeletion(int arr[],int size,int capacity,int index){
   if (size<=index)
   {
    return -1;
   }
   for (int i = index; i <=size-1; i++)
   {
    arr[i]=arr[i+1];
   }
   
   return 1;
}

int main(int argc, char const *argv[])
{
    int arr[100] = {1,2,6,78};
    int size = 4,index = 1;
    display(arr,size);

    indDeletion(arr,size,100,index);
    size--;
    display(arr,size);

    return 0;
}
