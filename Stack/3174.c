char* clearDigits(char* s) {
    char* ans = malloc((strlen(s) + 1)*sizeof(char));
    int i = 0, k = 0;
    while (s[i] != '\0') {
        if (s[i]>=0 &&s[i] <= '9') // here checking the element is btw 0 and 9
        {
            k--; 
        } else   // if not then it is char
        {
            ans[k++] = s[i]; // Add a character
        }
        i++;
    }
    ans[k] = '\0';
    return ans;
}