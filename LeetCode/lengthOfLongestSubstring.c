//
//  lengthOfLongestSubstring.c
//  LeetCode
//
//  Created by Marshal on 2022/5/12.
//

#include "lengthOfLongestSubstring.h"
#include <CoreFoundation/CoreFoundation.h>

//双指针的方式，以一个首尾队列的方式保存最长字符串
//当出现重复时，将队首指针后移到上一个重复的字符后面，避免无效操作
//首指针不一次移动一位，是因为从重复的这里到下一个重复，就已经是这段不重复且最长的子串了，队首再往前子串就出现重复了
//int lengthOfLongestSubstring(char *s) {
//    int len = (int)strlen(s);
//    if (len < 1) return 0;
//
//    int maxCount = 0;
//    //j、i首尾双指针
//    for (int i = 0, j = 0; i < len; i++) {
//        //判重
//        char c = s[i];
//        int isContainerIndex = -1;
//        for (int x = j; x < i; x++) {
//            if (c == s[x]) {
//                isContainerIndex = x;
//                break;
//            }
//        }
//        //重复了
//        if (isContainerIndex >= 0) {
//            j = isContainerIndex + 1;
//        }
//        maxCount = maxCount > i-j+1 ? maxCount : i-j+1;
//    }
//
//    return maxCount;
//}

//双指针的方式(优化)，以一个首尾队列的方式保存最长字符串
//当出现重复时，将队首指针后移到上一个重复的字符后面，避免无效操作
//首指针不一次移动一位，是因为从重复的这里到下一个重复，就已经是这段不重复且最长的子串了，队首再往前子串就出现重复了
//另外采用哈希思想，将字符串判断循环判重过程简化，优化速度
int lengthOfLongestSubstring(char *s) {
    int len = (int)strlen(s);
    if (len < 1) return 0;

    //用来表示字符是否出现过，如果出现过的字母标记 true
    //利用哈希表方式优化比较速度
    bool f[128] = {false};
    int ans = 0; //最大长度
    for (int i = 0, j = 0; j < len; j++) {
        //检查是否重复,
        while (f[s[j]] == true) {
            //有重复，重置前面的字符串出现标记为false
            //将i处标记为false，即j上一次出现的位置
            f[s[i++]] = true;
        }
        //将新出现的不重复字母标记为true
        f[s[j]] = true;
        //去最大结果，j-i长度是一个闭区间因此需要+1
        ans = ans > j - i + 1 ? ans : j - i + 1;
    }
    return ans;
}
