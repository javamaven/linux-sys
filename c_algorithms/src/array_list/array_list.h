//
// Created by andrew on 2021/2/23.
//

#ifndef C_ALGORITHMS_ARRAY_LIST_H
#define C_ALGORITHMS_ARRAY_LIST_H


#ifdef __cplusplus
extern "C" {
#endif

/**
 * A value to be stored in an @ref ArrayList.
 */

typedef void *ArrayListValue;

/**
 * An ArrayList structure.  New ArrayLists can be created using the
 * arraylist_new function.
 *
 * @see arraylist_new
 */

typedef struct _ArrayList ArrayList;

/**
 * Definition of an @ref ArrayList.
 */

struct _ArrayList {

    /** Entries in the array */

    ArrayListValue *data;

    /** Length of the array */
    // 当前列表的长度
    unsigned int length;

    /** Private data and should not be accessed */
    // 当前列表的能力
    unsigned int _alloced;
};

/**
 * Compare two values in an arraylist to determine if they are equal.
 *
 * @return Non-zero if the values are equal, zero if they are not equal.
 */

typedef int (*ArrayListEqualFunc)(ArrayListValue value1,
                                  ArrayListValue value2);

/**
 * Compare two values in an arraylist.  Used by @ref arraylist_sort
 * when sorting values.
 *
 * @param value1              The first value.
 * @param value2              The second value.
 * @return                    A negative number if value1 should be sorted
 *                            before value2, a positive number if value2 should
 *                            be sorted before value1, zero if the two values
 *                            are equal.
 */

typedef int (*ArrayListCompareFunc)(ArrayListValue value1,
                                    ArrayListValue value2);

/**
 * Allocate a new ArrayList for use.
 *
 * @param length         Hint to the initialise function as to the amount
 *                       of memory to allocate initially to the ArrayList.
 *                       If a value of zero is given, a sensible default
 *                       size is used.
 * @return               A new arraylist, or NULL if it was not possible
 *                       to allocate the memory.
 * @see arraylist_free
 */

ArrayList *arraylist_new(unsigned int length);

/**
 * Destroy an ArrayList and free back the memory it uses.
 *
 * @param arraylist      The ArrayList to free.
 */

void arraylist_free(ArrayList *arraylist);

/**
 * Append a value to the end of an ArrayList.
 *
 * @param arraylist      The ArrayList.
 * @param data           The value to append.
 * @return               Non-zero if the request was successful, zero
 *                       if it was not possible to allocate more memory
 *                       for the new entry.
 */

int arraylist_append(ArrayList *arraylist, ArrayListValue data);

/**
 * Prepend a value to the beginning of an ArrayList.
 *
 * @param arraylist      The ArrayList.
 * @param data           The value to prepend.
 * @return               Non-zero if the request was successful, zero
 *                       if it was not possible to allocate more memory
 *                       for the new entry.
 */

int arraylist_prepend(ArrayList *arraylist, ArrayListValue data);

/**
 * Remove the entry at the specified location in an ArrayList.
 *
 * @param arraylist      The ArrayList.
 * @param index          The index of the entry to remove.
 */

void arraylist_remove(ArrayList *arraylist, unsigned int index);

/**
 * Remove a range of entries at the specified location in an ArrayList.
 *
 * @param arraylist      The ArrayList.
 * @param index          The index of the start of the range to remove.
 * @param length         The length of the range to remove.
 */

void arraylist_remove_range(ArrayList *arraylist, unsigned int index,
                            unsigned int length);

/**
 * Insert a value at the specified index in an ArrayList.
 * The index where the new value can be inserted is limited by the
 * size of the ArrayList.
 *
 * @param arraylist      The ArrayList.
 * @param index          The index at which to insert the value.
 * @param data           The value.
 * @return               Returns zero if unsuccessful, else non-zero
 *                       if successful (due to an invalid index or
 *                       if it was impossible to allocate more memory).
 */

int arraylist_insert(ArrayList *arraylist, unsigned int index,
                     ArrayListValue data);

/**
 * Find the index of a particular value in an ArrayList.
 *
 * @param arraylist      The ArrayList to search.
 * @param callback       Callback function to be invoked to compare
 *                       values in the list with the value to be
 *                       searched for.
 * @param data           The value to search for.
 * @return               The index of the value if found, or -1 if not found.
 */

int arraylist_index_of(ArrayList *arraylist,
                       ArrayListEqualFunc callback,
                       ArrayListValue data);

/**
 * Remove all entries from an ArrayList.
 *
 * @param arraylist      The ArrayList.
 */

void arraylist_clear(ArrayList *arraylist);

/**
 * Sort the values in an ArrayList.
 *
 * @param arraylist      The ArrayList.
 * @param compare_func   Function used to compare values in sorting.
 */

void arraylist_sort(ArrayList *arraylist, ArrayListCompareFunc compare_func);

#ifdef __cplusplus
}
#endif


#endif //C_ALGORITHMS_ARRAY_LIST_H
