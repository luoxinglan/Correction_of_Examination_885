//
// Created by heihuhu on 25-12-9.
//
#include <stdio.h>

void repeatedLetters(char *nums) {
    int i, j, count = 0;
    for (i = 0, j = 1; nums[j] != '\0';) {
        if (nums[j] == nums[j - 1]) {
            count++;
            j++;
        } else if (count == 0) {
            nums[++i] = nums[j++];
        } else if (count) {
            // nums[i++] = nums[j - 1];
            nums[++i] = count + '0';
            count = 0;
        }
    }
    if (count) {
        nums[++i] = count + '0';
        nums[++i] = '\0';
        count = 0;
    }
    puts(nums);
}
