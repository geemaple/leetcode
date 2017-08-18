import pytest
import random
import sorting
import time
import inspect

all_sortings = inspect.getmembers(sorting, inspect.isfunction)
all_sortings.insert(0, ('built_in', sorted))

test_cases = {}

def input_tests(count):
    test_reault = range(count)
    if count not in test_cases:
        test_case = test_reault[:]
        random.shuffle(test_case)
        test_cases[count] = test_case

        print '\n', '=' * 50
        print 'input inversions = %d' % inversions(test_case)

    return test_cases[count][:], test_reault

def inversions(arrs):
    count = len(arrs)
    return len([(i, j) for i in range(count) for j in range(i + 1, count) if arrs[i] > arrs[j]])

def sizeof_fmt(num, suffix=''):
    for unit in [' ','K','M','B']:
        if abs(num) < 1000:
            return "%d%s%s" % (num, unit, suffix)
        num /= 1000

    return num;

def general_test(sort_name, sort_func, count=10):
    test_case, test_reault = input_tests(count)

    now = time.time()
    result = sort_func(test_case)

    print '\ninputs = %4s %15s execute %10fms' % \
      (sizeof_fmt(count), sort_name, (time.time() - now) * 1000),

    if result is not None:
        test_case = result

    assert test_case == test_reault

@pytest.mark.parametrize("sort_name, sort_func", all_sortings)
def test_correct(sort_name, sort_func):
    general_test(sort_name, sort_func, 100)

@pytest.mark.parametrize("sort_name, sort_func", all_sortings)
def test_1k(sort_name, sort_func):
    general_test(sort_name, sort_func, 1000)

@pytest.mark.parametrize("sort_name, sort_func", all_sortings)
def test_10k(sort_name, sort_func):
    general_test(sort_name, sort_func, 10000)

@pytest.mark.parametrize("sort_name, sort_func", all_sortings)
def test_100k(sort_name, sort_func):
    general_test(sort_name, sort_func, 100000)

# @pytest.mark.parametrize("sort_name, sort_func", all_sortings)
# def test_1m(sort_name, sort_func):
#     general_test(sort_name, sort_func, 1000000)
#
# @pytest.mark.parametrize("sort_name, sort_func", all_sortings)
# def test_10m(sort_name, sort_func):
#     general_test(sort_name, sort_func, 10000000)
#
# @pytest.mark.parametrize("sort_name, sort_func", all_sortings)
# def test_100m(sort_name, sort_func):
#     general_test(sort_name, sort_func, 100000000)
#
# @pytest.mark.parametrize("sort_name, sort_func", all_sortings)
# def test_1b(sort_name, sort_func):
#     general_test(sort_name, sort_func, 1000000000)
