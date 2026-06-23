//Tao mot kieu du lieu Word bao gom 1 ngan chua tu goc va 1 ngan chua ki tu da sap xep
typedef struct {
    char* original;
    char sorted[101];
} Word;

//Ham con de sap xep cac ki tu
int compareChars(const void* a, const void* b) {
    return (*(char*)a - *(char*)b);
}

//Ham con de sap xep cac chuoi ki tu
int compareWords(const void* a, const void* b) {
    return strcmp(((Word*)a)->sorted, ((Word*)b)->sorted);
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    if (strsSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    
   
    Word* words = (Word*)malloc(strsSize * sizeof(Word));
    for (int i = 0; i < strsSize; i++) {
        words[i].original = strs[i]; 
        strcpy(words[i].sorted, strs[i]); 
        
        
        qsort(words[i].sorted, strlen(words[i].sorted), sizeof(char), compareChars);
    } //Sort cac ki tu voi nhau vi du e,a,t thanh a,e,t, t a n thanh a n t

    
    qsort(words, strsSize, sizeof(Word), compareWords); //xep cac chuoi gan nhau lai: vi du aet, aet, ant
    
    //Khai bao con tro chua bo nho, cap phat du lieu
    char*** result = (char***)malloc(strsSize * sizeof(char**));
    *returnColumnSizes = (int*)malloc(strsSize * sizeof(int));
    *returnSize = 0;
    
    
    int i = 0;
    while (i < strsSize) {
        int j = i;
        
        while (j < strsSize && strcmp(words[i].sorted, words[j].sorted) == 0) {
            j++;
        }
        
        int groupSize = j - i; 
        
        
        result[*returnSize] = (char**)malloc(groupSize * sizeof(char*));
        
        
        for (int k = 0; k < groupSize; k++) {
            result[*returnSize][k] = words[i + k].original;
        }
        
       
        (*returnColumnSizes)[*returnSize] = groupSize;
        (*returnSize)++;
        
        i = j; 
    }
    
    
    free(words);
    
    return result;
}