/*
Problem: Longest Common Prefix

Write a function to find the longest common prefix string among an array of strings.
If there is no common prefix, return an empty string "".

Constraints:
1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters if it is non-empty.
*/

char* longestCommonPrefix(char** strs, int strsSize) {
    if(strsSize==0)
    {
        return "";
    }
    char* prefix=strs[0];
    int prefixLen=strlen(prefix);

    for(int i=1;i<strsSize;i++)
    {
        int j=0;
        while(j<prefixLen && strs[i][j]==prefix[j])
        {
            j++;
        }
        prefixLen=j;
        if(prefixLen==0)
        {
            return "";
        }
    }
    char* result=(char*)malloc((prefixLen+1)* sizeof(char));
    strncpy(result, prefix,prefixLen);
    result[prefixLen]='\0';
    return result;
}
