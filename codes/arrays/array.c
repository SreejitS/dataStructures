#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int array[10];
    int length;
    int size;
};

void display(struct Array arr)
{
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.array[i]);
    }
}

void append(struct Array *arr, int value)
{
    if (arr->length < arr->size)
    {
        arr->array[arr->length++] = value;
    }
}

void insert(struct Array *arr, int index, int value)
{
    if (index >= 0 && index < arr->length)
    {
        for (int i = arr->length; i > index; i--)
        {
            arr->array[i] = arr->array[i - 1];
        }
        arr->array[index] = value;
        arr->length++;
    }
}

int delete (struct Array *arr, int index)
{
    int value = arr->array[index];
    if (index >= 0 && index < arr->length)
    {
        for (int i = index; i < arr->length - 1; i++)
        {
            arr->array[i] = arr->array[i + 1];
        }
        arr->length--;
        return value;
    }
    return 0;
}

int main(void)
{
    struct Array arr = {{12, 3, 53, 2, 1, 1}, 6, 10};

    append(&arr, 45);
    display(arr);

    printf("\n");

    insert(&arr, 1, 0);
    display(arr);

    printf("\n");

    printf("%d \n", delete (&arr, 0));
    display(arr);

    return 0;
}