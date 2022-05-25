//
//  findSubstringInWraproundString.c
//  LeetCode
//
//  Created by Marshal on 2022/5/25.
//

#include "findSubstringInWraproundString.h"
#include <CoreFoundation/CoreFoundation.h>

//467. 环绕字符串中唯一的子字符串
int findSubstringInWraproundString(char * p){
    int allCount = 0;
    int length = (int)strlen(p);
    bool s[26] = {false};
    for (int i = 0; i < length; i++) {
        int idx = p[i] - 'a';
        if (s[idx] == false)  {
            s[idx] = true;
            allCount++;
        }else continue;
        int maxcount = 0, count = 0;
        for (int j = i; j < length - 1; j++) {
            if ((p[j+1] - p[j] + 26) % 26 == 1) {
                count++;
            }else {
                maxcount = count > maxcount ? count : maxcount;
                count = 0;
                while(j + 1 < length - 1 && p[j + 1] != p[i]) j++;
            }
        }
        maxcount = count > maxcount ? count : maxcount;
        allCount += maxcount;
    }
    return allCount;
}
