# MergeStringList

## Question: 
Write an immutable function that merges the following inputs into a single list.

Inputs
- Original list of strings
- List of strings to be added
- List of strings to be removed

Return
- List shall only contain unique values
- List shall be ordered as follows
--- Most character count to least character count
--- In the event of a tie, reverse alphabetical

Other Notes
- You can use any programming language you like
- The function you submit shall be runnable

For example:

Original List = ['one', 'two', 'three',]
Add List = ['one', 'two', 'five', 'six]
Delete List = ['two', 'five']
Result List = ['three', 'six', 'one']

Test Example 2:

Original List = ['a', 'b', 'z', 'c', 'aa', 'ab', 'az', 'ac', 'aaaaa', 'ba', 'za']

Add List = ['a', 'aa', aa']

Delete List = ['aa']

Result List = ['aaaaa', 'za', 'ba', 'az', 'ac', 'ab', 'z', 'c', 'b', 'a']

## Prerequisites:

1. C++20

2. Make

## Build and Run:
```shell
#Build and Run
make && ./main

#clean
make clean
```
