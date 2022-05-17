//
//  isAlienSorted.c
//  LeetCode
//
//  Created by Marshal on 2022/5/17.
//

#include "isAlienSorted.h"

bool isAlienSorted(char ** words, int wordsSize, char * order) {
    if (wordsSize < 2) return true;
    //按照原有字母顺序，保存对应字母的权, 第一个保存最小的数字，默认为\0
    int rankIndex[26] = {0};
    for (int i = 0; i < 26; i++) {
        int index = order[i] - 'a';
        rankIndex[index] = i;
    }
    int *lengths = (int *)calloc(wordsSize, sizeof(int));
    int maxLength = 0;
    for (int i = 0; i < wordsSize; i++) {
        int len = (int)strlen(words[i]);
        lengths[i] = len;
        if (len > maxLength) maxLength = len;
    }
    for (int idx = 1; idx < wordsSize; idx++) {
        for (int i = 0; i < maxLength; i++) {
            int rankLastC, rankC;
            if (i >= lengths[idx-1]) {
                rankLastC = -1;
            }else {
                rankLastC = rankIndex[words[idx-1][i] - 'a'];//赋予权值
            }
            if (i >= lengths[idx]) {
                rankC = -1;//越界,赋予最小的权
            }else {
                rankC = rankIndex[words[idx][i] - 'a'];//赋予权值
            }
            if (rankLastC > rankC) {
                free(lengths);
                return false;
            }else if (rankLastC < rankC) break;
        }
    }
    free(lengths);
    return true;
}
