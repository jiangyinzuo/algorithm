#include <stdio.h>
#include <string.h>

typedef struct String {
    char value[16];
    unsigned short len;
} String;

String dict[10003];
String pattern[52];

void input(int *count, String text[])
{
    while (1) {
        scanf("%s", text[*count].value);
        if (text[*count].value[0] == '#') {
            return;
        }
        text[*count].len = strlen(text[*count].value);
        ++*count;
    }
}

int _equal_compare(String *s1, String *s2)
{
    int unmatched_count = 0;
    for (int i = 0; i < s1->len; ++i) {
        if (s1->value[i] != s2->value[i]) {
            ++unmatched_count;
            if (unmatched_count >= 2) {
                return 2;
            }
        }
    }
    return unmatched_count;
}

/* s1->len == s2->len + 1 */
int _not_equal_compare(String *s1, String *s2)
{
    int i = 0;
    int j = 0;
    while (j < s2->len) {
        if (s1->value[i] != s2->value[j]) {
            --j;
            if (i - j >= 2) {
                return 0;
            } 
        }
        ++j;
        ++i;
    }
    return 1;
}

void _print_words(char *words[], int words_count)
{
    printf(":");
    for (int i = 0; i < words_count; ++i) {
        printf(" %s", words[i]);
    }
    printf("\n");
}

void compare(int dict_count, int pattern_count)
{
    char *words_ptr[15002];
    for (int i = 0; i < pattern_count; ++i) {
        printf("%s", pattern[i].value);
        int words_count = 0;
        short _flag = 1;
        for (int j = 0; j < dict_count; ++j) {
            if (pattern[i].len == dict[j].len) {
                int _unmatched_count = _equal_compare(&pattern[i], &dict[j]);
                if (_unmatched_count == 0) {
                    printf(" is correct\n");
                    _flag = 0;
                    break;
                } else if (_unmatched_count == 1) {
                    words_ptr[words_count++] = dict[j].value;
                }
            } else if (pattern[i].len == dict[j].len + 1) {
                if (_not_equal_compare(&pattern[i], &dict[j])) {
                    words_ptr[words_count++] = dict[j].value;
                }
            } else if (pattern[i].len + 1 == dict[j].len) {
                if (_not_equal_compare(&dict[j], &pattern[i])) {
                    words_ptr[words_count++] = dict[j].value;
                }
            }
        }
        if (_flag) {
            _print_words(words_ptr, words_count);
        }
    }
}

int main()
{
    int dict_count = 0;
    input(&dict_count, dict);
    
    int pattern_count = 0;
    input(&pattern_count, pattern);

    compare(dict_count, pattern_count);
    return 0;
}