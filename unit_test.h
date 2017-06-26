#ifndef UNIT_TEST_H
#define UNIT_TEST_H
#include "my_string.h"

Status test_init_default_returns_nonNULL(char* buffer, int length);
Status test_get_size_on_init_default_returns_0(char* buffer, int length);
Status test_mmalone_get_capacity_on_init_default_returns_7(char* buffer, int length);
Status test_mmalone_my_string_empty_after_init_default(char* buffer, int length);
Status test_mmalone_init_c_string_get_size(char* buffer, int length);
Status test_mmalone_string_at_returns_nonNULL(char* buffer, int length);
Status test_mmalone_my_string_compare(char* buffer, int length);
Status test_mmalone_my_string_at(char* buffer, int length);
Status test_mmalone_my_string_push_back(char* buffer, int length);
Status test_mmalone_init_c_string_get_capacity(char* buffer, int length);
Status test_mmalone_my_c_str(char* buffer, int length);
Status test_mmalone_my_string_concat(char* buffer, int length);
Status test_mmalone_my_string_empty_after_init_c_string(char* buffer, int length);
Status test_mmalone_init_c_string_returns_nonNULL(char* buffer, int length);
Status test_mmalone_my_string_popback_size(char* buffer, int length);
Status test_mmalone_my_string_push_back_capacity(char* buffer, int length);
Status test_mmalone_pop_back_on_empty(char* buffer, int length);
Status test_mmalone_resize_my_string_pushback(char* buffer, int length);
Status test_mmalone_pop_back_on_my_string_object(char* buffer, int length);
Status test_mmalone_popback_and_pushback_on_init_default(char* buffer, int length);
Status test_mmalone_my_string_extraction_from_dictionary(char* buffer, int length);
Status test_mmalone_push_back_pushing_char_on_empty_string(char* buffer, int length);
Status test_mmalone_my_string_pushback_at_index(char* buffer, int length);
Status test_mmalone_my_string_compare_with_larger_left_string(char* buffer, int length);
Status test_mmalone_my_string_compare_with_larger_right_string(char* buffer, int length);


#endif