/******************
 * 顺序表实现
 ******************/
#include "ArrayList.h"

void initArrayList(ArrayList list) {
    list->length = 0;
}

int initByArray(const elementType *data, int n, ArrayList list) {
    int i = 0;
    if (list == NULL) {
        return NULL_POINT;
    }
    if (n > MAX_LENGTH) {
        return FULL_LIST;
    }
    //初始顺序表长度
    list->length = 0;
    for (i = 0; i < n; i++) {
        list->data[i] = data[i];
        list->length++;
    }
    return SUCCESS;
}

void showAll(ArrayList list) {
    int i;
    int len = size(list);
    for (i = 0; i < len; i++) {
        printf("%d\t", list->data[i]);
    }
    printf("\n");
}

int size(ArrayList list) {
    if (list == NULL) {
        return NULL_POINT;
    }
    return list->length;
}

int get(elementType *elem, int index, ArrayList list) {
    if (list == NULL) {
        return NULL_POINT;
    }
    if (index < 0 || index >= size(list)) {
        return ARRAY_BOUND;
    } else {
        *elem = list->data[index];
        return SUCCESS;
    }
}

int add(elementType elem, int index, ArrayList list) {
    int len, i;
    if (list == NULL) {
        return NULL_POINT;
    }
    if (index < 0 || index > (len = size(list))) {
        return ARRAY_BOUND;
    }
    if (len == MAX_LENGTH) {
        return FULL_LIST;
    }
    //插入元素
    for (i = len; i > index; i--) {
        //后移复制
        list->data[i] = list->data[i - 1];
    }
    //插入
    list->data[i] = elem;
    list->length++;
    return SUCCESS;
}

int delete(int index, ArrayList list) {
    int len, i;
    if (list == NULL) {
        return NULL_POINT;
    }
    if (index < 0 || index >= (len = size(list))) {
        return ARRAY_BOUND;
    }
    //删除
    for (i = index; i < len - 1; i++) {
        list->data[i] = list->data[i + 1];
    }
    list->length--;
    return SUCCESS;
}

int insIntoSortedList(elementType elem, ArrayList list) {
    int len, i;
    if (list == NULL) {
        return NULL_POINT;
    }
    if ((len = size(list)) == MAX_LENGTH) {
        return FULL_LIST;
    }

    //插入表头或表尾
    if (elem <= list->data[0]) {
        return add(elem, 0, list);
    } else if (elem >= list->data[len - 1]) {
        return add(elem, len, list);
    }

    for (i = 0; i < len; i++) {
        //插入
        if (elem >= list->data[i] && elem <= list->data[i + 1]) {

            return add(elem, i + 1, list);
        }
    }
    return SUCCESS;
}

int separateOddEvenNum(ArrayList list, ArrayList oddList, ArrayList evenList) {
    int len, i, data;
    if (list == NULL || oddList == NULL || evenList == NULL) {
        return NULL_POINT;
    }
    //分离
    len = size(list);
    for (i = 0; i < len; i++) {
        //偶数
        data = list->data[i];
        if (data % 2 == 0) {
            addEnd(data, evenList);
        } else {
            addEnd(data, oddList);
        }
    }
    return SUCCESS;
}


int addEnd(elementType elem, ArrayList list) {
    int len;
    if (list == NULL) {
        return NULL_POINT;
    }
    if ((len = size(list)) == MAX_LENGTH) {
        return FULL_LIST;
    }
    //尾插
    add(elem, len, list);
    return SUCCESS;
}

int intersectionSortedList(ArrayList listA, ArrayList listB, ArrayList listC) {
    int indexA, indexB;
    if (listA == NULL || listB == NULL || listC == NULL) {
        return NULL_POINT;
    }

    indexA = 0;
    indexB = 0;
    //A < B
    while (indexA < listA->length && indexB < listB->length) {
        if (listA->data[indexA] < listB->data[indexB]) {
            indexA++;
        } else if (listA->data[indexA] > listB->data[indexB]) {
            indexB++;
        } else {
            //交集,公共元素
            addEnd(listA->data[indexA], listC);
            indexA++;
            indexB++;
        }
    }
    return SUCCESS;
}

int delRepeatElement(ArrayList list, int *moveCount) {
    int i, j, len;
    if (list == NULL) {
        return NULL_POINT;
    }

    *moveCount = 0;
    len = size(list);
    //从后往前删除,提高效率
    for (i = len - 1; i > 0; i--) {
        //重复元素
        if (list->data[i] == list->data[i - 1]) {
            //从前往后覆盖
            for (j = i - 1; j < list->length; j++) {
                list->data[j] = list->data[j + 1];
                (*moveCount)++;
            }
            list->length--;
        }
    }
    return SUCCESS;
}
