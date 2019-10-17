#ifndef ARRAY_LIST
#define ARRAY_LIST

/******************
 * 顺序表声明头文件
 ******************/

#include <stdio.h>

//定义元素类型
typedef int elementType;

//定义最大容量
#define MAX_LENGTH 30

//定义链表结构
typedef struct {
    elementType data[MAX_LENGTH];
    int length;
} *ArrayList, newArrayList;


/**
 *  初始化链表
 * @param list
 */
void initArrayList(ArrayList list);

/**
 * 通过数组初始化链表
 * @param data  数据源数组
 * @param n 数组长度
 * @param list
 * @return SUCCESS
 *         NULL_POINT:空指针
 *         FULL_LIST:超出最大初始容量
 */
int initByArray(const elementType *data, int n, ArrayList list);

/**
 * 打印所有元素
 * @param list
 */
void showAll(ArrayList list);

/**
 * 取得顺序表长度
 * @param list
 * @return 正常返回长度
 *          NULL_POINT:空指针返回-1
 */
int size(ArrayList list);

/**
 * 求顺序表中第i个元素
 * @param elem  接收所求元素
 * @param index
 * @param list
 * @return SUCCESS
 *         ARRAY_BOUND:下标越界
 *         NULL_POINT:空指针
 */
int get(elementType *elem, int index, ArrayList list);

/**
 * 在第i个结点前插入值为x的结点
 * @param elem
 * @param index
 * @param list
 * @return SUCCESS
 *         ARRAY_BOUND:下标越界
 *         NULL_POINT:空指针
 *         FULL_LIST:顺序表已满
 */
int add(elementType elem, int index, ArrayList list);

/**
 * 删除顺序表中第i个元素结点
 * @param index
 * @param list
 * @return SUCCESS
 *         ARRAY_BOUND:下标越界
 *         NULL_POINT:空指针
 */
int delete(int index, ArrayList list);


/**
 * 在一个递增有序的顺序表L中插入一个值为x的元素，并保持其递增有序特性
 * @param elem
 * @param list
 * @return SUCCESS
 *         NULL_POINT:空指针
 *         FULL_LIST:顺序表已满
 */
int insIntoSortedList(elementType elem, ArrayList list);

/**
 * 将顺序表Ｌ中的奇数项和偶数项结点分解开（元素值为奇数、偶数），分别放入新的顺序表中，然后原表和新表元素同时输出到屏幕上，以便对照求解结果
 * @param list
 * @param oddList
 * @param evenList
 * @return NULL_POINT:空指针
 */
int separateOddEvenNum(ArrayList list, ArrayList oddList, ArrayList evenList);

/**
 * 尾插元素
 * @param elem
 * @param list
 * @return NULL_POINT:空指针
 *         FULL_LIST:顺序表已满
 */
int addEnd(elementType elem, ArrayList list);

/**
 * 交集
 * 求两个递增有序顺序表L1和L2中的公共元素，放入新的顺序表L3中
 * @param listA
 * @param listB
 * @param listC 交集结果
 * @return NULL_POINT:空指针
 */
int intersectionSortedList(ArrayList listA, ArrayList listB, ArrayList listC);

/**
 * 删除递增有序顺序表中的重复元素，并统计移动元素次数
 * @param list
 * @return NULL_POINT:空指针
 */
int delRepeatElement(ArrayList list, int *moveCount);

/*************************
 * 操作结果标志定义
 *
 * @SUCCESS 操作成功
 * @ARRAY_BOUND 数组下标越界,<0或>=size
 * @NULL_POINT 空指针
 * @FULL_LIST 列表已满
 ************************/
enum CODE {
    SUCCESS = 1,
    NULL_POINT = -1,
    ARRAY_BOUND = -2,
    FULL_LIST = -3
};

#endif