#include <stdio.h>
#include <stdlib.h>
#define ARRAYSIZE 10


struct array {
    int numbersArray[ARRAYSIZE];
    int swapArray[ARRAYSIZE];
    int totalNumOfSwaps;
}array;


void swap(int array[] ,int indexA, int indexB){
    int tmp = array[indexA];
    array[indexA] = array[indexB];
    array[indexB] = tmp;
    

}

void bubbleSort(struct array array){
    // From the end towards the front
    // Ex) array 1
    // 97 16 45 63 13 22 7 58
    // 16 45 63 13 22 7 | 97
    // 16 45 13 22 7 | 63 97
    // 16 13 22 7 | 45 63 97
    // etc

    int i = ARRAYSIZE - 1;
    while(i > 0){
        int tmpIndex = 0;
        for(int b = 1;b < i;++b){

            if(array.numbersArray[tmpIndex]>array.numbersArray[b]){
                array.swapArray[tmpIndex] += 1;
                array.swapArray[b] += 1;
                array.totalNumOfSwaps += 1;
                swap(array.numbersArray,tmpIndex,b);
                swap(array.swapArray,tmpIndex,b);
                tmpIndex = b;
            }
            else{
                tmpIndex = b;
            }
        }
       
        --i;
    }
    printf("\n");
    for(int b = 0; b < ARRAYSIZE - 1;++b){
        printf("%d: %d\n",array.numbersArray[b],array.swapArray[b]);
    }
    printf("Total number of swaps for bubble sort: %d", array.totalNumOfSwaps);
    printf("\n");





}

void selectionSort(struct array array){
    // From the front towards the end
    // Ex) array 1
    // 97 16 45 63 13 22 7 58
    // 7 | 16 45 63 13 22 97 58
    // 7 13 | 45 63 16 22 97 58
    // 7 13 16 | 63 45 22 97 58
    // 7 13 16 22 | 45 63 97 58
    // 7 13 16 22 45 63 | 97 58
    // 7 13 16 22 45 63 58 97 |
    // etc

    int i = ARRAYSIZE - 1;
    int baseIndex = 0;
    while(i >= 0){
        int tmpIndex = 0;
        int minIndex = baseIndex;
        for(int b = baseIndex;b < ARRAYSIZE -1 ;++b){
            if(array.numbersArray[tmpIndex]>array.numbersArray[b] && array.numbersArray[b]<array.numbersArray[minIndex]){
                minIndex = b;
                tmpIndex = b;
            }
            else{
                tmpIndex = b;
            }
        }
        if(minIndex != baseIndex){
            array.swapArray[baseIndex] += 1;
            array.swapArray[minIndex] += 1;
            array.totalNumOfSwaps++;
            swap(array.numbersArray,minIndex,baseIndex);
            swap(array.swapArray,minIndex,baseIndex);
            
        }
        ++baseIndex;
        --i;
    }

    printf("\n");
    for(int b = 0; b < ARRAYSIZE - 1;++b){
        printf("%d: %d\n",array.numbersArray[b],array.swapArray[b]);
    }
    printf("Total number of swaps for Selection sort: %d", array.totalNumOfSwaps);
    printf("\n");


}


int main(){
    struct array array1;
    struct array array2;

    int array1base[ARRAYSIZE] = {97,16,45,63,13,22,7,58,72};
    int array2base[ARRAYSIZE] = {90,80,70,60,50,40,30,20,10};

    for(int i = 0; i < ARRAYSIZE ; ++i){
        array1.numbersArray[i] = array1base[i];
        array2.numbersArray[i] = array2base[i];

        array1.swapArray[i] = 0;
        array2.swapArray[i] = 0;
    }
    array1.totalNumOfSwaps = 0;
    array2.totalNumOfSwaps = 0;

    bubbleSort(array1);
    bubbleSort(array2);

    selectionSort(array1);
    selectionSort(array2);


    
}