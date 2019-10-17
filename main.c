#include "ArrayList.h"

void testGet(ArrayList list);

void testAdd(ArrayList list);

void testDelete(ArrayList list);

void testInsIntoSortedList(ArrayList list);

void testAddEnd(ArrayList list);

void testSeparateOddEvenNum(ArrayList list);

void testIntersectionSortedList(ArrayList list);

void testDelRepeatElement(ArrayList list);

int main() {
    //新建链表
    newArrayList newArrayList;
    ArrayList list = &newArrayList;
    //新增
//    testAdd(list);
    //删除
//    testDelete(list);

    //在一个递增有序的顺序表L中插入一个值为x的元素
//    testInsIntoSortedList(list);

    //尾插
//    testAddEnd(list);

    //奇偶分离
//    testSeparateOddEvenNum(list);

    //递增有序交集
//    testIntersectionSortedList(list);

    //删除递增有序表重复元素
    testDelRepeatElement(list);

    return 0;
}

/**
 * 测试顺序表取出元素功能
 * @warning 请在测试方法中修改测试数据
 * @param list
 */
void testGet(ArrayList list) {
    elementType elem;
    int resultCode;

    elementType data[] = {1, 2, 3, 4, 5};
    initByArray(data, sizeof(data) / sizeof(elementType), list);
    showAll(list);

    //此处修改测试数据
    resultCode = get(&elem, 4, list);

    switch (resultCode) {
        case SUCCESS:
            printf("取出成功:%d\n", elem);
            break;
        case ARRAY_BOUND:
            printf("位置越界!!!\n");
            break;
        case NULL_POINT:
            printf("空指针!!!\n");
            break;
        default:
            break;
    }
}

/**
 * 测试顺序表插入功能
 * @warning 请在测试方法中修改测试数据
 * @param list
 */
void testAdd(ArrayList list) {
    int resultCode;

    elementType data[] = {1, 2, 3, 4};
    initByArray(data, sizeof(data) / sizeof(elementType), list);
    showAll(list);

    //此处修改测试数据
    resultCode = add(33, 4, list);

    switch (resultCode) {
        case SUCCESS:
            showAll(list);
            break;
        case ARRAY_BOUND:
            printf("位置越界!!!\n");
            break;
        case NULL_POINT:
            printf("空指针!!!\n");
            break;
        case FULL_LIST:
            printf("顺序表已满!!!\n");
            break;
        default:
            break;
    }
}

/**
 * 测试顺序表删除功能
 * @warning 请在测试方法中修改测试数据
 * @param list
 */
void testDelete(ArrayList list) {
    int resultCode;

    elementType data[] = {1, 2, 3, 4, 5};
    initByArray(data, sizeof(data) / sizeof(elementType), list);
    showAll(list);

    //此处修改测试数据
    resultCode = delete(1, list);

    switch (resultCode) {
        case SUCCESS:
            showAll(list);
            break;
        case ARRAY_BOUND:
            printf("位置越界!!!\n");
            break;
        case NULL_POINT:
            printf("空指针!!!\n");
            break;
        default:
            break;
    }
}

/**
 * 在一个递增有序的顺序表L中插入一个值为x的元素，并保持其递增有序特性
 * @warning 请在测试方法中修改测试数据
 * @param list
 */
void testInsIntoSortedList(ArrayList list) {
    int resultCode;

    elementType data[] = {1, 2, 3, 4, 5};
    initByArray(data, sizeof(data) / sizeof(elementType), list);
    showAll(list);

    //此处修改测试数据
    resultCode = insIntoSortedList(1, list);

    switch (resultCode) {
        case SUCCESS:
            showAll(list);
            break;
        case ARRAY_BOUND:
            printf("位置越界!!!\n");
            break;
        case NULL_POINT:
            printf("空指针!!!\n");
            break;
        case FULL_LIST:
            printf("顺序表已满!!!\n");
            break;
        default:
            break;
    }
}

/**
 * 测试顺序表尾插功能
 * @warning 请在测试方法中修改测试数据
 * @param list
 */
void testAddEnd(ArrayList list) {
    int resultCode;

    elementType data[] = {1, 2, 3, 4};
    initByArray(data, sizeof(data) / sizeof(elementType), list);
    showAll(list);

    //此处修改测试数据
    resultCode = addEnd(1, list);

    switch (resultCode) {
        case SUCCESS:
            showAll(list);
            break;
        case NULL_POINT:
            printf("空指针!!!\n");
            break;
        case FULL_LIST:
            printf("顺序表已满!!!\n");
            break;
        default:
            break;
    }
}

/**
 * 将顺序表Ｌ中的奇数项和偶数项结点分解开（元素值为奇数、偶数），分别放入新的顺序表中
 * @warning 请在测试方法中修改测试数据
 * @param list
 */
void testSeparateOddEvenNum(ArrayList list) {
    int resultCode;
    newArrayList oddL;
    newArrayList evenL;
    ArrayList oddList = &oddL;
    ArrayList evenList = &evenL;

    elementType data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 30, 40, 50, 60};
    initByArray(data, sizeof(data) / sizeof(elementType), list);

    //初始偶/奇数列表
    initArrayList(oddList);
    initArrayList(evenList);

    //此处修改测试数据
    resultCode = separateOddEvenNum(list, oddList, evenList);


    switch (resultCode) {
        case SUCCESS:
            showAll(list);
            printf("奇:");
            showAll(oddList);
            printf("偶:");
            showAll(evenList);
            break;
        case NULL_POINT:
            printf("空指针!!!\n");
            break;
        default:
            break;
    }
}

/**
 * 求两个递增有序顺序表L1和L2中的公共元素，放入新的顺序表L3中
 * @warning 请在测试方法中修改测试数据
 * @param list
 */
void testIntersectionSortedList(ArrayList list) {
    int resultCode;
    newArrayList lA;
    newArrayList lB;
    newArrayList lC;
    ArrayList listA = &lA;
    ArrayList listB = &lB;
    ArrayList listC = &lC;

    elementType dataA[] = {1, 2, 3,};
    initByArray(dataA, sizeof(dataA) / sizeof(elementType), listA);
    elementType dataB[] = {2, 3, 4, 5};
    initByArray(dataB, sizeof(dataB) / sizeof(elementType), listB);

    //初始listC
    initArrayList(listC);


    //此处修改测试数据
    resultCode = intersectionSortedList(listA, listB, listC);


    switch (resultCode) {
        case SUCCESS:
            showAll(listA);
            showAll(listB);
            printf("交集:\n");
            showAll(listC);
            break;
        case NULL_POINT:
            printf("空指针!!!\n");
            break;
        default:
            break;
    }
}

/**
 * 测试顺序表尾插功能
 * @warning 请在测试方法中修改测试数据
 * @param list
 */
void testDelRepeatElement(ArrayList list) {
    int resultCode, moveCount;

    elementType data[] = {1, 2, 3, 4, 4, 5, 6, 6};
    initByArray(data, sizeof(data) / sizeof(elementType), list);
    showAll(list);

    //此处修改测试数据
    resultCode = delRepeatElement(list, &moveCount);

    switch (resultCode) {
        case SUCCESS:
            showAll(list);
            printf("移动次数:%d\n", moveCount);
            break;
        case NULL_POINT:
            printf("空指针!!!\n");
            break;
        default:
            break;
    }
}