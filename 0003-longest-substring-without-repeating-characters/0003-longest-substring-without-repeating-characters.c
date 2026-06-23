int lengthOfLongestSubstring(char* s) {
    int max_len = 0;
    int left = 0;
    int count[256] ={0};
    for(int right =0; s[right]!='\0'; right++){
        count[(unsigned char)s[right]]++;
        while(count[(unsigned char)s[right]]>1){
            count[(unsigned char)s[left]]--;
            left++;
        }
        int current_size = right - left + 1;
        if(current_size > max_len){
            max_len = current_size;
        }
    }
    return max_len;
}