#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>



void insertionsort(int arr[], int n1)
{
    int i, k, j;

    for (i = 1; i < n1; i++)
    {
        k = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > k)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = k;
    }
}


void insertionsort_ch(char array[], int n1)
{
    int i, j;
    char x;

    for (i = 1; i < n1; i++)
    {
        x = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > x)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = x;
    }
}

void swap_numb(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}


void swap_ch(char* x, char* y)
{
    char temp = *x;
    *x = *y;
    *y = temp;
}

void selectionsort(int array[], int n2)
{
    int i, j, m;

    for (i = 0; i < n2 - 1; i++)
    {
        m = i;
        for (j = i + 1; j < n2; j++)
        {
            if (array[j] < array[m])
                m = j;
        }
        swap_numb(&array[m], &array[i]);
    }
}

void selectionsort_ch(char array[], int n2)
{
    int i, j;
    char m;

    for (i = 0; i < n2 - 1; i++)
    {
        m = i;
        for (j = i + 1; j < n2; j++)
        {
            if (array[j] < array[m])
                m = j;
        }
        swap_ch(&array[m], &array[i]);
    }
}

void bubblesort(int array[], int n3)
{
    int i, j;
    for (i = 0; i < n3 - 1; i++)
    {
        for (j = 0; j < n3 - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap_numb(&array[j], &array[j + 1]);
            }
        }
    }
}

void bubblesort_ch(char array[], int n3)
{
    int i, j;

    for (i = 0; i < n3 - 1; i++)
    {
        for (j = 0; j < n3 - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap_ch(&array[j], &array[j + 1]);
            }
        }

    }
}

void merge_N(int array[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = array[l + i];


    for (j = 0; j < n2; j++)
        R[j] = array[m + 1 + j];

    i = 0;
    j = 0;
    k = l;


    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            array[k] = L[i];
            i++;
        }
        else
        {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        array[k] = R[j];
        j++;
        k++;
    }
}

void
mergeSort_N(int array[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort_N(array, l, m);
        mergeSort_N(array, m + 1, r);
        merge_N(array, l, m, r);
    }
}

void merge_ch(char array[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = array[l + i];

    for (j = 0; j < n2; j++)
        R[j] = array[m + 1 + j];


    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            array[k] = L[i];
            i++;
        }
        else
        {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        array[k] = R[j];
        j++;
        k++;
    }
}

void  mergesort_ch(char array[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergesort_ch(array, l, m);
        mergesort_ch(array, m + 1, r);
        merge_ch(array, l, m, r);
    }
}

void printArray(int array[], int n1)
{

    int i;

    for (i = 0; i < n1; i++)

        printf("%d ", array[i]);
    printf("\n");
}

int main()
{


    //Insertion

    clock_t time;

    int School_Number1[] = { 2, 0, 1, 7, 5, 5, 6, 0, 1, 2 };
    char NAME1[] = " Elif Cicek";


    int n1 = sizeof(School_Number1) / sizeof(School_Number1[0]);
    int charsize = strlen(NAME1);


    time = clock();
    insertionsort(School_Number1, n1);
    time = clock() - time;
    printArray(School_Number1, n1);
    printf("Time of Insertion Sort: %f\n", ((double)time) / CLOCKS_PER_SEC);

    insertionsort_ch(NAME1, charsize);

    time = clock() - time;

    printf("%s\n", NAME1);
    printf("Time of char Insertion  Sort:  %f\n\n",
        ((double)time) / CLOCKS_PER_SEC);
    //-----------------


     //Selection

    int School_Number2[] = { 2, 0, 1, 7, 5, 5, 6, 0, 1, 2 };
    char NAME2[] = "Elif Cicek";

    int n2 = sizeof(School_Number2) / sizeof(School_Number2[0]);
    int charsize1 = strlen(NAME2);

    selectionsort(School_Number2, n2);
    time = clock() - time;

    printArray(School_Number2, n2);
    printf("Time of Selection Sort: %f\n", ((double)time) / CLOCKS_PER_SEC);

    selectionsort_ch(NAME2, charsize1);
    time = clock() - time;

    printf("%s \n", NAME2);
    printf("Time of char Selection Sort: %f\n\n",
        ((double)time) / CLOCKS_PER_SEC);
    //-----------------

     //Bubble

    int  School_Number3[] = { 2, 0, 1, 7, 5, 5, 6, 0, 1, 2 };
    char NAME3[] = " Elif Cicek ";

    int n3 = sizeof(School_Number3) / sizeof(School_Number3[0]);
    int charsize2 = strlen(NAME3);

    bubblesort(School_Number3, n3);
    time = clock() - time;

    printArray(School_Number3, n3);
    printf("Time of Bubble Sort: %f\n", ((double)time) / CLOCKS_PER_SEC);

    bubblesort_ch(NAME3, charsize2);

    time = clock() - time;

    printf("%s\n", NAME3);
    printf("Time of char Bubble Sort: %f\n\n",
        ((double)time) / CLOCKS_PER_SEC);
    //-----------------


    //Merge

    int School_Number4[] = { 2, 0, 1, 7, 5, 5, 6, 0, 1, 2 };
    char NAME4[] = " Elif Cicek ";

    int n4 = sizeof(School_Number4) / sizeof(School_Number4[0]);
    int charSize3 = strlen(NAME4);

    mergeSort_N(School_Number4, 0, n3 - 1);
    time = clock() - time;

    printArray(School_Number4, n3);
    printf("Time of Merge Sort: %f\n", ((double)time) / CLOCKS_PER_SEC);

    mergesort_ch(NAME4, 0, charSize3 - 1);
    time = clock() - time;

    printf("%s\n", NAME4);
    printf("Time of char Merge Sort: %f\n\n",
        ((double)time) / CLOCKS_PER_SEC);

    return 0;


}

