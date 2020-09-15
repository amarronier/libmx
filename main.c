#include "libmx.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <locale.h>

bool cmp_list(void *a, void *b) {
    return strcmp((char *)a, (char *)b) > 0;
}

int main() {
    //utils pack check
    //mx_printchar
    printf("\n>> started checking mx_printchar...\n");
    mx_printstr("actual result:   ");
    for (int i = 33; i <= 63; ++i)
        mx_printchar((char)i);
    mx_printstr("\nexpected result: !\"#$%&'()*+,-./0123456789:;<=>?\n");

    //mx_print_unicode
    printf("\n>> started checking mx_print_unicode...\n");
    wchar_t unicode_1 = 0xC389;
    wchar_t unicode_2 = 0xC9;
    wchar_t unicode_3 = 536;
    wchar_t unicode_4 = 0x79;
    setlocale(LC_ALL, "");
    mx_printstr("actual result:   ");
    mx_print_unicode(unicode_1);
    mx_print_unicode(' ');
    mx_print_unicode(unicode_2);
    mx_print_unicode(' ');
    mx_print_unicode(unicode_3);
    mx_print_unicode(' ');
    mx_print_unicode(unicode_4);
    mx_printstr("\nexpected result: ");
    printf("%lc %lc %lc %lc\n", unicode_1, unicode_2, unicode_3, unicode_4);

    //mx_printstr
    printf("\n>> started checking mx_printstr...\n");
    char *printstr_1 = "check libmx";
    char *printstr_2 = "";
    mx_printstr("actual result:   ");
    mx_printstr(printstr_1);
    mx_printstr("\nexpected result: check libmx\n");
    mx_printstr("actual result:   ");
    mx_printstr(printstr_2);
    mx_printstr("\nexpected result: \n");

    //mx_print_strarr
    printf("\n>> started checking mx_print_strarr...\n");
    char *strarr_1[5] = {"ololo", "pushka", "raketa", "check task", NULL};
    char *strarr_2[1] = {NULL};
    const char del = '@';
    mx_printstr("actual result:   ");
    mx_print_strarr(strarr_1, &del);
    mx_printstr("expected result: ololo@pushka@raketa@check task\n");
    mx_printstr("actual result:   ");
    mx_print_strarr(strarr_2, &del);
    mx_printstr("expected result: \n");
    
    //mx_printint
    printf("\n>> started checking mx_printint...\n");
    mx_printstr("actual result:   ");
    mx_printint(INT_MIN);
    printf("\nexpected result: %d\n", INT_MIN);
    mx_printstr("actual result:   ");
    mx_printint(INT_MAX);
    printf("\nexpected result: %d\n", INT_MAX);
    mx_printstr("actual result:   ");
    mx_printint(0);
    printf("\nexpected result: %d\n", 0);
    mx_printstr("actual result:   ");
    mx_printint(-7);
    printf("\nexpected result: %d\n", -7);
    mx_printstr("actual result:   ");
    mx_printint(200);
    printf("\nexpected result: %d\n", 200);

    //mx_pow
    printf("\n>> started checking mx_pow...\n");
    printf("actual result:   ");
    printf("%f", mx_pow(15.36, 3));
    printf("\nexpected result: %f\n", pow(15.36, 3));
    printf("actual result:   ");
    printf("%f", mx_pow(0, 0));
    printf("\nexpected result: %f\n", pow(0, 0));

    //mx_sqrt
    printf("\n>> started checking mx_sqrt...\n");
    printf("actual result:   ");
    printf("%d", mx_sqrt(100));
    printf("\nexpected result: %d\n", (int)sqrt(100));
    printf("actual result:   ");
    printf("%d", mx_sqrt(INT_MAX));
    printf("\nexpected result: %d\n", 0);

    //mx_nbr_to_hex
    printf("\n>> started checking mx_nbr_to_hex...\n");
    printf("actual result:   ");
    printf("%s", mx_nbr_to_hex(52));
    printf("\nexpected result: %x\n", 52);
    printf("actual result:   ");
    printf("%s", mx_nbr_to_hex(1687253));
    printf("\nexpected result: %x\n", 1687253);

    //mx_hex_to_nbr
    printf("\n>> started checking mx_hex_to_nbr...\n");
    printf("actual result:   ");
    printf("%lu", mx_hex_to_nbr("C4"));
    printf("\nexpected result: %lu\n", strtol("C4", NULL, 16));
    printf("actual result:   ");
    printf("%lu", mx_hex_to_nbr("ffhduir"));
    printf("\nexpected result: %d\n", 0);
    printf("actual result:   ");
    printf("%lu", mx_hex_to_nbr("fff67ac50"));
    printf("\nexpected result: %lu\n", strtol("fff67ac50", NULL, 16));
    printf("actual result:   ");
    printf("%lu", mx_hex_to_nbr("ffffffffffff"));
    printf("\nexpected result: %lu\n", strtol("ffffffffffff", NULL, 16));

    //mx_itoa
    printf("\n>> started checking mx_itoa...\n");
    printf("actual result:   ");
    printf("%s", mx_itoa(INT_MAX));
    printf("\nexpected result: %d\n", INT_MAX);
    printf("actual result:   ");
    printf("%s", mx_itoa(INT_MIN));
    printf("\nexpected result: %d\n", INT_MIN);
    printf("actual result:   ");
    printf("%s", mx_itoa(-10));
    printf("\nexpected result: %d\n", -10);

    //mx_foreach
    printf("\n>> started checking mx_foreach...\n");
    int foreach[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    mx_printstr("actual result:   ");
    mx_foreach(foreach, 10, mx_printint);
    mx_printstr("\nexpected result: 0123456789\n");

    //mx_binary_search
    printf("\n>> started checking mx_binary_search...\n");
    int binary_count = 0;
    char *binary_arr[6] = {"222", "Abcd", "aBc", "ab", "az", "z"};
    printf("actual result:   ");
    printf("%d %d", mx_binary_search(binary_arr, 6, "ab", &binary_count), binary_count);
    printf("\nexpected result: %d %d\n", 3, 3);
    binary_count = 0;
    printf("actual result:   ");
    printf("%d %d", mx_binary_search(binary_arr, 6, "aBc", &binary_count), binary_count);
    printf("\nexpected result: %d %d\n", 2, 1);
    binary_count = 0;
    printf("actual result:   ");
    printf("%d %d", mx_binary_search(binary_arr, 6, "aBz", &binary_count), binary_count);
    printf("\nexpected result: %d %d\n", -1, 0);

    //mx_bubble_sort
    printf("\n>> started checking mx_bubble_sort...\n");
    char *bubble_1[4] = {"abc", "xyz", "ghi", "def"};
    printf("actual result:   ");
    printf("%d", mx_bubble_sort(bubble_1, 4));
    printf("\nexpected result: %d\n", 3);
    char *bubble_2[3] = {"abc", "acb", "a"};
    printf("actual result:   ");
    printf("%d", mx_bubble_sort(bubble_2, 3));
    printf("\nexpected result: %d\n", 2);

    //mx_quicksort
    printf("\n>> started checking mx_quicksort...\n");
    char *quicksort_1[4] = {"Michelangelo", "Donatello", "Leonardo", "Raphael"};
    printf("actual result:   ");
    printf("%d ", mx_quicksort(quicksort_1, 0, 3));
    for (int i = 0; i < 4; ++i) printf("%s ", quicksort_1[i]);
    printf("\nexpected result: %d %s\n", 2, "Raphael Leonardo Donatello Michelangelo");
    char *quicksort_2[6] = {"DMC", "Clint Eastwood", "Dr Brown", "Einstein", "Jessica", "Biff Tannen"};
    printf("actual result:   ");
    printf("%d ", mx_quicksort(quicksort_2, 0, 5));
    for (int i = 0; i < 6; ++i) printf("%s ", quicksort_2[i]);
    printf("\nexpected result: %d %s\n", 2, "DMC Jessica Dr Brown Einstein Biff Tannen Clint Eastwood");

    //string pach check
    //mx_strlen
    printf("\n>> started checking mx_strlen...\n");
    const char strlen_str[] = "How many characters does this string contain?";
    printf("actual result:   ");
    printf("%d", mx_strlen(strlen_str));
    printf("\nexpected result: %zu\n", strlen(strlen_str));

    //mx_swap_char
    printf("\n>> started checking mx_swap_char...\n");
    char swap_str[] = "swaP";
    printf("actual result:   ");
    mx_swap_char(&swap_str[0], &swap_str[3]);
    printf("%s", swap_str);
    printf("\nexpected result: Pwas\n");

    //mx_str_reverse
    printf("\n>> started checking mx_str_reverse...\n");
    char reverse_str[] = "reverse string";
    printf("actual result:   ");
    mx_str_reverse(reverse_str);
    printf("%s", reverse_str);
    printf("\nexpected result: gnirts esrever\n");

    //mx_strdel
    printf("\n>> started checking mx_strdel...\n");
    char *strdel_str = mx_strnew(strlen("reverse string"));
    strcpy(strdel_str, "reverse string");
    printf("actual result:   ");
    mx_strdel(&strdel_str);
    printf("%s", strdel_str);
    printf("\nexpected result: (null)\n");

    //mx_del_strarr
    printf("\n>> started checking mx_del_strarr...\n");
    /*char **del_strarr = malloc(4 * sizeof(char *));
    del_strarr[0] = mx_strdup("Michelangelo");
    del_strarr[1] = mx_strdup("Donatello");
    del_strarr[2] = mx_strdup("Leonardo");
    del_strarr[3] = mx_strdup("Raphael");
    printf("actual result:   ");
    mx_del_strarr(&del_strarr);
    printf("%s", (char *)del_strarr);
    printf("\nexpected result: (null)\n");*/

    //mx_get_char_index
    printf("\n>> started checking mx_get_char_index...\n");
    printf("actual result:   ");
    printf("%d", mx_get_char_index("ololo", 'o'));
    printf("\nexpected result: 0\n");
    printf("actual result:   ");
    printf("%d", mx_get_char_index("ololo", 'l'));
    printf("\nexpected result: 1\n");
    printf("actual result:   ");
    printf("%d", mx_get_char_index("ololo", 'q'));
    printf("\nexpected result: -1\n");
    printf("actual result:   ");
    printf("%d", mx_get_char_index("12djsasiuz hjdkhfuer", ' '));
    printf("\nexpected result: 10\n");
    printf("actual result:   ");
    printf("%d", mx_get_char_index(NULL, 'o'));
    printf("\nexpected result: -2\n");

    //mx_strdup
    printf("\n>> started checking mx_strdup...\n");
    printf("actual result:   ");
    printf("%s", mx_strdup("Raphael"));
    printf("\nexpected result: Raphael\n");

    //mx_strndup
    printf("\n>> started checking mx_strndup...\n");
    printf("actual result:   ");
    printf("%s", mx_strndup("Raphael", 3));
    printf("\nexpected result: Rap\n");
    printf("actual result:   ");
    printf("%s", mx_strndup("Raphael", 10));
    printf("\nexpected result: Raphael\n");
    printf("actual result:   ");
    printf("%s", mx_strndup("Raphael", -3));
    printf("\nexpected result: \n");

    //mx_strcpy
    printf("\n>> started checking mx_strcpy...\n");
    char strcpy_str[15] = "Make the test.";
    char strcpy_standart[25] = "Make the test.";
    printf("actual result:   ");
    printf("%s", mx_strcpy(strcpy_str, "Test."));
    printf("\nexpected result: %s\n", strcpy(strcpy_standart, "Test."));
    printf("actual result:   ");
    printf("%s", mx_strcpy(strcpy_str, "Take the test."));
    printf("\nexpected result: %s\n", strcpy(strcpy_standart, "Take the test."));
    printf("actual result:   ");
    printf("%s", mx_strcpy(strcpy_str, "Take the test of strcpy."));
    printf("\nexpected result: %s\n", strcpy(strcpy_standart, "Take the test of strcpy."));

    //mx_strncpy
    printf("\n>> started checking mx_strncpy...\n");
    char strncpy_dest[15] = "Make the test.";
    char strncpy_standart[15] = "Make the test.";
    printf("actual result:   ");
    printf("%s", mx_strncpy(strncpy_dest, "Have", strlen("Have")));
    printf("\nexpected result: %s\n", strncpy(strncpy_standart, "Have", strlen("Have")));

    //mx_strcmp
    printf("\n>> started checking mx_strcmp...\n");
    printf("actual result:   ");
    printf("%d", mx_strcmp("ololo", "Ololo"));
    printf("\nexpected result: %d\n", 32);
    printf("actual result:   ");
    printf("%d", mx_strcmp("ololo", "ololo"));
    printf("\nexpected result: %d\n", strcmp("ololo", "ololo"));
    printf("actual result:   ");
    printf("%d", mx_strcmp("Raketa", "ololo"));
    printf("\nexpected result: %d\n", -29);

    //mx_strcat
    printf("\n>> started checking mx_strcat...\n");
    char strcat_1[50] = "Hello ";
    char strcat_2[50] = "World!";
    char strcat_standart[50] = "Hello ";
    printf("actual result:   ");
    mx_strcat(strcat_1, strcat_2);
    mx_strcat(strcat_1, " ...");
    printf("%s", mx_strcat(strcat_1, " Goodbye World!"));
    strcat(strcat_standart, strcat_2);
    strcat(strcat_standart, " ...");
    printf("\nexpected result: %s\n", strcat(strcat_standart, " Goodbye World!"));

    //mx_strstr
    printf("\n>> started checking mx_strstr...\n");
    printf("actual result:   ");
    printf("%s", mx_strstr("one two three", "two"));
    printf("\nexpected result: %s\n", strstr("one two three", "two"));

    //mx_get_substr_index
    printf("\n>> started checking mx_strstr...\n");
    printf("actual result:   ");
    printf("%d", mx_get_substr_index("McDonalds", "McDonalds"));
    printf("\nexpected result: %d\n", 0);
    printf("actual result:   ");
    printf("%d", mx_get_substr_index("McDonalds", "Don"));
    printf("\nexpected result: %d\n", 2);
    printf("actual result:   ");
    printf("%d", mx_get_substr_index("McDonalds Donuts", "on"));
    printf("\nexpected result: %d\n", 3);
    printf("actual result:   ");
    printf("%d", mx_get_substr_index("McDonalds", "Donatello"));
    printf("\nexpected result: %d\n", -1);
    printf("actual result:   ");
    printf("%d", mx_get_substr_index("McDonalds", NULL));
    printf("\nexpected result: %d\n", -2);
    printf("actual result:   ");
    printf("%d", mx_get_substr_index(NULL, "Don"));
    printf("\nexpected result: %d\n", -2);

    //mx_count_substr
    printf("\n>> started checking mx_count_substr...\n");
    printf("actual result:   ");
    printf("%d", mx_count_substr("yo, yo, yo Neo", "yo"));
    printf("\nexpected result: %d\n", 3);
    printf("actual result:   ");
    printf("%d", mx_count_substr("yo, yo, yo Neo", "bum"));
    printf("\nexpected result: %d\n", 0);
    printf("actual result:   ");
    printf("%d", mx_count_substr("yo, yo, yo Neo", NULL));
    printf("\nexpected result: %d\n", -1);
    printf("actual result:   ");
    printf("%d", mx_count_substr(NULL, "yo"));
    printf("\nexpected result: %d\n", -1);

    //mx_count_words
    printf("\n>> started checking mx_count_words...\n");
    char *count_words_str = "  follow  *   the  white rabbit ";
    printf("actual result:   ");
    printf("%d", mx_count_words(count_words_str, '*'));
    printf("\nexpected result: %d\n", 2);
    printf("actual result:   ");
    printf("%d", mx_count_words(count_words_str, ' '));
    printf("\nexpected result: %d\n", 5);
    printf("actual result:   ");
    printf("%d", mx_count_words(NULL, ' '));
    printf("\nexpected result: %d\n", -1);

    //mx_strtrim
    printf("\n>> started checking mx_strtrim...\n");
    char *strtrim_str =  "\f My name... is Neo \t\n ";
    printf("actual result:   ");
    printf("%s", mx_strtrim(strtrim_str));
    printf("\nexpected result: My name... is Neo\n");
    printf("actual result:   ");
    printf("%s", mx_strtrim(NULL));
    printf("\nexpected result: (null)\n");

    //mx_del_extra_spaces
    printf("\n>> started checking mx_del_extra_spaces...\n");
    char *del_extra_str =  "\f My name...    is  \r Neo  \t\n ";
    printf("actual result:   ");
    printf("%s", mx_del_extra_spaces(del_extra_str));
    printf("\nexpected result: My name... is Neo\n");
    printf("actual result:   ");
    printf("%s", mx_del_extra_spaces(NULL));
    printf("\nexpected result: (null)\n");

    //mx_strsplit
    printf("\n>> started checking mx_strsplit...\n");
    char *strsplit_str_1 =  "*Good bye,**Mr.*Anderson.****";
    char **strsplit_arr_1 = mx_strsplit(strsplit_str_1, '*');
    char *strsplit_str_2 =  "     Knock,  knock,    Neo.   ";;
    char **strsplit_arr_2 = mx_strsplit(strsplit_str_2, ' ');
    printf("actual result:   ");
    for (int i = 0; strsplit_arr_1[i]; ++i)
        printf("%s", strsplit_arr_1[i]);
    printf("\nexpected result: Good bye,Mr.Anderson.\n");
    printf("actual result:   ");  
    for (int i = 0; strsplit_arr_2[i]; ++i)
        printf("%s", strsplit_arr_2[i]);
    printf("\nexpected result: Knock,knock,Neo.\n");
    printf("actual result:   ");
    printf("%s", (char *)mx_strsplit(NULL, 'i'));
    printf("\nexpected result: (null)\n");

    //mx_strjoin
    printf("\n>> started checking mx_strjoin...\n");
    char *strjoin_str_1 =  "this";
    char *strjoin_str_2 =  "dodge ";
    printf("actual result:   ");
    printf("%s", mx_strjoin(strjoin_str_2, strjoin_str_1));
    printf("\nexpected result: dodge this\n");
    printf("actual result:   ");
    printf("%s", mx_strjoin(strjoin_str_1, NULL));
    printf("\nexpected result: this\n");
    printf("actual result:   ");
    printf("%s", mx_strjoin(NULL, NULL));
    printf("\nexpected result: (null)\n");

    //mx_file_to_str
    printf("\n>> started checking mx_file_to_str...\n");
    printf("actual result:   ");
    printf("%s", mx_file_to_str("src/mx_printchar.c"));
    printf("\nexpected result: (cat of mx_printchar.c)\n");

    //mx_read_line
    printf("\n>> started checking mx_read_line...\n");
    int mx_read_line_fragment;
    int mx_read_line_main;
    int mx_read_line_res;
    char *mx_read_line_str = NULL;
    printf("actual result:   \n");

    mx_read_line_fragment = open("fragment", O_RDONLY);
    mx_read_line_str = mx_strnew(1000);
    mx_read_line_res = mx_read_line(&mx_read_line_str, 20, 'f', mx_read_line_fragment);
    printf("%d !%s!\n", mx_read_line_res, mx_read_line_str);
    mx_strdel(&mx_read_line_str);

    close(mx_read_line_fragment);
    mx_read_line_fragment = open("fragment", O_RDONLY);
    mx_read_line_str = mx_strnew(1000);
    mx_read_line_res = mx_read_line(&mx_read_line_str, 35, 't', mx_read_line_fragment);
    printf("%d !%s!\n", mx_read_line_res, mx_read_line_str);
    mx_strdel(&mx_read_line_str);

    mx_read_line_main = open("main.c", O_RDONLY);
    mx_read_line_str = mx_strnew(1000);
    mx_read_line_res = mx_read_line(&mx_read_line_str, 10, '\n', mx_read_line_main);
    printf("%d !%s!\n", mx_read_line_res, mx_read_line_str);
    mx_strdel(&mx_read_line_str);

    close(mx_read_line_fragment);
    mx_read_line_fragment = open("fragment", O_RDONLY);
    mx_read_line_str = mx_strnew(1000);
    mx_read_line_res = mx_read_line(&mx_read_line_str, 4, '.', mx_read_line_fragment);
    printf("%d !%s!\n", mx_read_line_res, mx_read_line_str);
    mx_strdel(&mx_read_line_str);

    close(mx_read_line_main);
    mx_read_line_main = open("main.c", O_RDONLY);
    mx_read_line_str = mx_strnew(1000);
    mx_read_line_res = mx_read_line(&mx_read_line_str, 10, '\n', mx_read_line_main);
    printf("%d !%s!\n", mx_read_line_res, mx_read_line_str);
    mx_strdel(&mx_read_line_str);
    
    close(mx_read_line_fragment);
    mx_read_line_fragment = open("fragment", O_RDONLY);
    mx_read_line_str = mx_strnew(1000);
    mx_read_line_res = mx_read_line(&mx_read_line_str, 5, '?', mx_read_line_fragment);
    printf("%d !%s!\n", mx_read_line_res, mx_read_line_str);
    mx_strdel(&mx_read_line_str);

    close(mx_read_line_fragment);
    close(mx_read_line_main);

    printf("expected result:\n");
    printf("25 !The hotel was abandoned a!\n");
    printf("0 !!\n");
    printf("18 !#include \"libmx.h\"!\n");
    printf("163 !er a fire ... shadow!\n");
    printf("18 !#include <stdio.h>!\n");
    printf("-1 !!\n");

    //mx_replace_substr
    printf("\n>> started checking mx_strjoin...\n");
    char replace_str[] = "xxforxxx xx for xx";
    printf("actual result:   ");
    printf("%s", mx_replace_substr(replace_str, "xx", "Geeks"));
    printf("\nexpected result: GeeksforGeeksx Geeks for Geeks\n");
    printf("actual result:   ");
    printf("%s", mx_replace_substr("hello world!", "", "!"));
    printf("\nexpected result: !h!e!l!l!o! !w!o!r!l!d!!!\n");

    //memory pack check
    //mx_memset
    printf("\n>> started checking mx_memset...\n");
    char *memset_str = mx_strdup("ups");
    char *memset_stand = mx_strdup("ups");

    printf("actual result:   ");
    printf("%s %p", memset_str, (void *)memset_str);
    printf(" - %s", mx_memset(memset_str,'a', 1));
    printf("\nexpected result: ");
    printf("%s %p", memset_stand, (void *)memset_stand);
    printf(" - %s\n", memset(memset_stand,'a', 1));

    printf("actual result:   ");
    printf("%s %p", memset_str, (void *)memset_str);
    printf(" - %s", mx_memset(memset_str,'X', 3));
    printf("\nexpected result: ");
    printf("%s %p", memset_stand, (void *)memset_stand);
    printf(" - %s\n", memset(memset_stand,'X', 3));

    printf("actual result:   ");
    printf("%s %p", memset_str, (void *)memset_str);
    printf(" - %s", mx_memset(memset_str,'~', 5));
    printf("\nexpected result: ");
    printf("%s %p", memset_stand, (void *)memset_stand);
    printf(" - %s\n", memset(memset_stand,'~', 5));

    //mx_memcpy
    printf("\n>> started checking mx_memcpy...\n");
    char memcpy_source_1[10] = "once upon", memcpy_dest_1[10], memcpy_dest_2[10];
    char memcpy_source_2[24] = "once upon ... once upon", memcpy_dest_3[24], memcpy_dest_4[24];
    printf("actual result:   ");
    printf("%s", mx_memcpy(memcpy_dest_1, memcpy_source_1, sizeof(memcpy_source_1)));
    printf("\nexpected result: %s\n", memcpy(memcpy_dest_2, memcpy_source_1, sizeof(memcpy_source_1)));
    printf("actual result:   ");
    printf("%s", mx_memcpy(memcpy_dest_3, memcpy_source_2, sizeof memcpy_source_2));
    printf("\nexpected result: %s\n", memcpy(memcpy_dest_4, memcpy_source_2, sizeof(memcpy_source_2)));

    //mx_memccpy
    printf("\n>> started checking mx_memccpy...\n");
    char memccpy_src_1[14] = "once restrict", memccpy_dest_1[20], memccpy_dest_2[20];;
    char memccpy_src_2[20] = "once restrict chiks";
    printf("actual result:   ");
    printf("%s, %s", (char *)mx_memccpy(memccpy_dest_1, memccpy_src_1, 't', 9), memccpy_dest_1);
    printf("\nexpected result: %s, %s\n", (char *)memccpy(memccpy_dest_2, memccpy_src_1, 't', sizeof("once restric")), memccpy_dest_2);
    printf("actual result:   ");
    printf("%s, %s", (char *)mx_memccpy(memccpy_dest_1, memccpy_src_2, 'x', 9), memccpy_dest_1);
    printf("\nexpected result: %s, %s\n", (char *)memccpy(memccpy_dest_2, memccpy_src_2, 'x', 9), memccpy_dest_2);

    //mx_memcmp
    printf("\n>> started checking mx_memcmp...\n");
    char memcmp_arr1[3] = {'a','b','c'};
    char memcmp_arr2[3] = {'a','b',' '};
    printf("actual result:   ");
    printf("%d", mx_memcmp(memcmp_arr1, memcmp_arr2, 3));
    printf("\nexpected result: %d\n", memcmp(memcmp_arr1, memcmp_arr2, 3));
    printf("actual result:   ");
    printf("%d", mx_memcmp("hello", "helloRaketa", 5));
    printf("\nexpected result: %d\n", memcmp("hello", "helloRaketa", 5));

    //mx_memchr
    printf("\n>> started checking mx_memchr...\n");
    const char memchr_str[8] = "ABCDEFG";
    printf("actual result:   ");
    printf("%s", mx_memchr(memchr_str, 'D', mx_strlen(memchr_str)));
    printf("\nexpected result: %s\n", memchr(memchr_str, 'D', strlen(memchr_str)));
    printf("actual result:   ");
    printf("%s", mx_memchr(memchr_str, 'A', mx_strlen(memchr_str)));
    printf("\nexpected result: %s\n", memchr(memchr_str, 'A', strlen(memchr_str)));
    printf("actual result:   ");
    printf("%s", mx_memchr(memchr_str, '0', mx_strlen(memchr_str)));
    printf("\nexpected result: %s\n", memchr(memchr_str, '0', strlen(memchr_str)));

    //mx_memrchr
    printf("\n>> started checking mx_memrchr...\n");
    char memrchr_str[] = "ABCDEDFG";
    printf("actual result:   ");
    printf("%s", mx_memrchr(memrchr_str, 'A', mx_strlen(memrchr_str)));
    printf("\nexpected result: ABCDEDFG\n");
    printf("actual result:   ");
    printf("%s", mx_memrchr(memrchr_str, 'D', mx_strlen(memrchr_str)));
    printf("\nexpected result: DFG\n");

    //mx_memmem
    printf("\n>> started checking mx_memmem...\n");
    printf("actual result:   ");
    printf("%s", mx_memmem("one two three", mx_strlen("one two three"), "two", mx_strlen("two")));
    printf("\nexpected result: %s\n", memmem("one two three", strlen("one two three"), "two", strlen("two")));
    printf("actual result:   ");
    printf("%s", mx_memmem("one typewo three", mx_strlen("one typewo three"), "two", 1));
    printf("\nexpected result: %s\n", memmem("one typewo three", mx_strlen("one typewo three"), "two", 1)); 
    printf("actual result:   ");
    printf("%s", mx_memmem("oh my god", mx_strlen("oh my god"), "two", 0));
    printf("\nexpected result: %s\n", memmem("oh my god", mx_strlen("oh my god"), "two", 0));
    printf("actual result:   ");
    printf("%s", mx_memmem("one typewo three", mx_strlen("one typewo three"), "two", 2));
    printf("\nexpected result: %s\n", memmem("one typewo three", mx_strlen("one typewo three"), "two", 2));
    printf("actual result:   ");
    printf("%s", mx_memmem("oh my", mx_strlen("oh my"), "oh my god", mx_strlen("oh my god")));
    printf("\nexpected result: %s\n", memmem("oh my", mx_strlen("oh my"), "oh my god", strlen("oh my god")));

    //mx_memmove
    printf("\n>> started checking mx_memmove...\n");
    printf("actual result:   ");
    char memmove_str_1[] = "unsigned";
    char memmove_str_2[] = "unsigned";
    printf("%s", mx_memmove(memmove_str_1 + 2, memmove_str_1, 4));
    printf("\nexpected result: %s\n", memmove(memmove_str_2 + 2, memmove_str_2, 4));
    printf("actual result:   ");
    printf("%s", mx_memmove(memmove_str_1 + 2, memmove_str_1, 4));
    printf("\nexpected result: %s\n", memmove(memmove_str_2 + 2, memmove_str_2, 4));

    //mx_realloc
    printf("\n>> started checking mx_realloc...\n");
    printf("actual result:   ");
    char *realloc_str = mx_strdup("documentation killed");
    printf("%zu", malloc_size(realloc_str));
    realloc_str = mx_realloc(realloc_str, 25);
    realloc_str[25] = '\0';
    printf(" %zu, !%s!", malloc_size(realloc_str), realloc_str);

    printf("\nexpected result: ");
    char *realloc_stand = mx_strdup("documentation killed");
    printf("%zu", malloc_size(realloc_stand));
    realloc_stand = realloc(realloc_stand, 25);
    realloc_stand[25] = '\0';
    printf(" %zu, !%s!\n", malloc_size(realloc_stand), realloc_stand);

    printf("actual result:   ");
    realloc_str = mx_strdup("documentation killed");
    printf("%zu", malloc_size(realloc_str));
    realloc_str = mx_realloc(realloc_str, 10);
    realloc_str[10] = '\0';
    printf(" %zu, !%s!", malloc_size(realloc_str), realloc_str);

    printf("\nexpected result: ");
    realloc_stand = mx_strdup("documentation killed");
    printf("%zu", malloc_size(realloc_stand));
    realloc_stand = realloc(realloc_stand, 10);
    realloc_stand[10] = '\0';
    printf(" %zu, !%s!\n", malloc_size(realloc_stand), realloc_stand);

    printf("actual result:   ");
    realloc_str = mx_strdup("documentation killed");
    printf("%zu", malloc_size(realloc_str));
    realloc_str = mx_realloc(realloc_str, 0);
    printf(" %zu, !%s!", malloc_size(realloc_str), realloc_str);

    printf("\nexpected result: ");
    realloc_stand = mx_strdup("documentation killed");
    printf("%zu", malloc_size(realloc_stand));
    realloc_stand = realloc(realloc_stand, 0);
    printf(" %zu, !%s!\n", malloc_size(realloc_stand), realloc_stand);

    printf("actual result:   ");
    realloc_str = mx_strdup("documentation killed");
    printf("%zu", malloc_size(realloc_str));
    realloc_str = mx_realloc(NULL, 10);
    printf(" %zu, !%s!", malloc_size(realloc_str), realloc_str);

    printf("\nexpected result: ");
    realloc_stand = mx_strdup("documentation killed");
    printf("%zu", malloc_size(realloc_stand));
    realloc_stand = realloc(NULL, 10);
    printf(" %zu, !%s!\n", malloc_size(realloc_stand), realloc_stand);

    //list pack check
    //mx_create_node
    printf("\n>> started checking mx_create_node...\n");
    printf("actual result:   ");
    t_list *create_node_head = mx_create_node(NULL);
    create_node_head->data = "node";
    t_list *check_node = create_node_head;
    while (check_node) {
        printf("%s", check_node->data);
        check_node = check_node->next;
    }
    printf("\nexpected result: %s\n", "node");

    //mx_push_front
    printf("\n>> started checking mx_push_front...\n");
    printf("actual result:   ");
    t_list *push_front_head = mx_create_node("front");
    mx_push_front(&push_front_head, "it ");
    mx_push_front(&push_front_head, "push ");
    t_list *check_push_front = push_front_head;
    while (check_push_front) {
        printf("%s", check_push_front->data);
        check_push_front = check_push_front->next;
    }
    printf("\nexpected result: %s\n", "push it front");

    //mx_push_back
    printf("\n>> started checking mx_push_back...\n");
    printf("actual result:   ");
    t_list *push_back_head = mx_create_node("push ");
    mx_push_back(&push_back_head, "it ");
    mx_push_back(&push_back_head, "back");
    t_list *check_push_back = push_back_head;
    while (check_push_back) {
        printf("%s", check_push_back->data);
        check_push_back = check_push_back->next;
    }
    printf("\nexpected result: %s\n", "push it back");

    //mx_pop_front
    printf("\n>> started checking mx_pop_front...\n");
    printf("actual result:   ");
    t_list *pop_front_head = mx_create_node("raketa ");
    mx_push_back(&pop_front_head, "... ");
    mx_push_back(&pop_front_head, "what ");
    mx_push_back(&pop_front_head, "have been");
    mx_push_back(&pop_front_head, " removed?");
    mx_pop_front(&pop_front_head);
    t_list *check_pop_front = pop_front_head;
    while (check_pop_front) {
        printf("%s", check_pop_front->data);
        check_pop_front = check_pop_front->next;
    }
    printf("\nexpected result: %s\n", "... what have been removed?");

    //mx_pop_back
    printf("\n>> started checking mx_pop_back...\n");
    printf("actual result:   ");
    t_list *pop_back_head = mx_create_node("heeeeey! ");
    mx_push_back(&pop_back_head, "what ");
    mx_push_back(&pop_back_head, "have been");
    mx_push_back(&pop_back_head, " ...");
    mx_push_back(&pop_back_head, " removed?");
    mx_pop_back(&pop_back_head);
    t_list *check_pop_back = pop_back_head;
    while (check_pop_back) {
        printf("%s", check_pop_back->data);
        check_pop_back = check_pop_back->next;
    }
    printf("\nexpected result: %s\n", "heeeeey! what have been ...");

    //mx_list_size
    printf("\n>> started checking mx_list_size...\n");
    printf("actual result:   ");
    printf("%d", mx_list_size(pop_back_head));
    printf("\nexpected result: %d\n", 4);
    printf("actual result:   ");
    printf("%d", mx_list_size(check_pop_back));
    printf("\nexpected result: %d\n", 0);

    //mx_sort_list
    printf("\n>> started checking mx_sort_list...\n");
    printf("actual result:   ");
    t_list *sort_list_head = mx_create_node("now ");
    mx_push_back(&sort_list_head, "something ");
    mx_push_back(&sort_list_head, "will be");
    mx_push_back(&sort_list_head, " ... ");
    mx_push_back(&sort_list_head, "sort ");
    t_list *check_sort_list = mx_sort_list(sort_list_head, cmp_list);
    while (check_sort_list) {
        printf("%s", check_sort_list->data);
        check_sort_list = check_sort_list->next;
    }
    printf("\nexpected result: %s\n", " ... now something sort will be");

    return 0;
}
