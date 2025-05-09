#!/bin/python3

import math
import os
import random
import re
import sys


# Complete the highestValuePalindrome function below.
def isPalindrome(s):
    for idx in range(len(s) // 2):
        if s[idx] != s[len(s) - idx - 1]:
            return False
    return True


def highestValuePalindrome(s, n, k):
    first = ''
    second = ''
    h = n - 1
    count = 0
    for i in range(n // 2):
        if s[i] != s[h - i]:
            count += 1
    if k < count:
        print('-1')
        return
    else:
        for i in range(n // 2):
            ch1 = s[i]
            ch2 = s[h - i]
            if ch1 == ch2:
                if ch1 == '9' or k - 2 < count:
                    first += ch1
                    second += ch1
                else:
                    first += '9'
                    second += '9'
                    k -= 2

            else:
                if k - 1 >= count and ch1 != '9' and ch2 != '9':
                    first += '9'
                    second += '9'
                    k -= 2
                else:
                    if ch1 > ch2:
                        first += ch1
                        second += ch1
                    else:
                        first += ch2
                        second += ch2
                    k -= 1
                count -= 1

        if n % 2 == 1:
            if k > 0:
                print(first + '9' + second[::-1])
            else:
                print(first + s[n // 2] + second[::-1])
        else:
            print(first + second[::-1])


if __name__ == '__main__':
    nk = input().split()

    n = int(nk[0])

    k = int(nk[1])

    s = list(input().strip())

    result = highestValuePalindrome(s, n, k)