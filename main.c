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
    //�½�����
    newArrayList newArrayList;
    ArrayList list = &newArrayList;
    //����
//    testAdd(list);
    //ɾ��
//    testDelete(list);

    //��һ�����������˳���L�в���һ��ֵΪx��Ԫ��
//    testInsIntoSortedList(list);

    //β��
//    testAddEnd(list);

    //��ż����
//    testSeparateOddEvenNum(list);

    //�������򽻼�
//    testIntersectionSortedList(list);

    //ɾ������������ظ�Ԫ��
    testDelRepeatElement(list);

    return 0;
}

/**
 * ����˳���ȡ��Ԫ�ع���
 * @warning ���ڲ��Է������޸Ĳ�������
 * @param list
 */
void testGet(ArrayList list) {
    elementType elem;
    int resultCode;

    elementType data[] = {1, 2, 3, 4, 5};
    initByArray(data, sizeof(data) / sizeof(elementType), list);
    showAll(list);

    //�˴��޸Ĳ�������
    resultCode = get(&elem, 4, list);

    switch (resultCode) {
        case SUCCESS:
            printf("ȡ���ɹ�:%d\n", elem);
            break;
        case ARRAY_BOUND:
            printf("λ��Խ��!!!\n");
            break;
        case NULL_POINT:
            printf("��ָ��!!!\n");
            break;
        default:
            break;
    }
}

/**
 * ����˳�����빦��
 * @warning ���ڲ��Է������޸Ĳ�������
 * @param list
 */
void testAdd(ArrayList list) {
    int resultCode;

    elementType data[] = {1, 2, 3, 4};
    initByArray(data, sizeof(data) / sizeof(elementType), list);
    showAll(list);

    //�˴��޸Ĳ�������
    resultCode = add(33, 4, list);

    switch (resultCode) {
        case SUCCESS:
            showAll(list);
            break;
        case ARRAY_BOUND:
            printf("λ��Խ��!!!\n");
            break;
        case NULL_POINT:
            printf("��ָ��!!!\n");
            break;
        case FULL_LIST:
            printf("˳�������!!!\n");
            break;
        default:
            break;
    }
}

/**
 * ����˳���ɾ������
 * @warning ���ڲ��Է������޸Ĳ�������
 * @param list
 */
void testDelete(ArrayList list) {
    int resultCode;

    elementType data[] = {1, 2, 3, 4, 5};
    initByArray(data, sizeof(data) / sizeof(elementType), list);
    showAll(list);

    //�˴��޸Ĳ�������
    resultCode = delete(1, list);

    switch (resultCode) {
        case SUCCESS:
            showAll(list);
            break;
        case ARRAY_BOUND:
            printf("λ��Խ��!!!\n");
            break;
        case NULL_POINT:
            printf("��ָ��!!!\n");
            break;
        default:
            break;
    }
}

/**
 * ��һ�����������˳���L�в���һ��ֵΪx��Ԫ�أ��������������������
 * @warning ���ڲ��Է������޸Ĳ�������
 * @param list
 */
void testInsIntoSortedList(ArrayList list) {
    int resultCode;

    elementType data[] = {1, 2, 3, 4, 5};
    initByArray(data, sizeof(data) / sizeof(elementType), list);
    showAll(list);

    //�˴��޸Ĳ�������
    resultCode = insIntoSortedList(1, list);

    switch (resultCode) {
        case SUCCESS:
            showAll(list);
            break;
        case ARRAY_BOUND:
            printf("λ��Խ��!!!\n");
            break;
        case NULL_POINT:
            printf("��ָ��!!!\n");
            break;
        case FULL_LIST:
            printf("˳�������!!!\n");
            break;
        default:
            break;
    }
}

/**
 * ����˳���β�幦��
 * @warning ���ڲ��Է������޸Ĳ�������
 * @param list
 */
void testAddEnd(ArrayList list) {
    int resultCode;

    elementType data[] = {1, 2, 3, 4};
    initByArray(data, sizeof(data) / sizeof(elementType), list);
    showAll(list);

    //�˴��޸Ĳ�������
    resultCode = addEnd(1, list);

    switch (resultCode) {
        case SUCCESS:
            showAll(list);
            break;
        case NULL_POINT:
            printf("��ָ��!!!\n");
            break;
        case FULL_LIST:
            printf("˳�������!!!\n");
            break;
        default:
            break;
    }
}

/**
 * ��˳�����е��������ż������ֽ⿪��Ԫ��ֵΪ������ż�������ֱ�����µ�˳�����
 * @warning ���ڲ��Է������޸Ĳ�������
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

    //��ʼż/�����б�
    initArrayList(oddList);
    initArrayList(evenList);

    //�˴��޸Ĳ�������
    resultCode = separateOddEvenNum(list, oddList, evenList);


    switch (resultCode) {
        case SUCCESS:
            showAll(list);
            printf("��:");
            showAll(oddList);
            printf("ż:");
            showAll(evenList);
            break;
        case NULL_POINT:
            printf("��ָ��!!!\n");
            break;
        default:
            break;
    }
}

/**
 * ��������������˳���L1��L2�еĹ���Ԫ�أ������µ�˳���L3��
 * @warning ���ڲ��Է������޸Ĳ�������
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

    //��ʼlistC
    initArrayList(listC);


    //�˴��޸Ĳ�������
    resultCode = intersectionSortedList(listA, listB, listC);


    switch (resultCode) {
        case SUCCESS:
            showAll(listA);
            showAll(listB);
            printf("����:\n");
            showAll(listC);
            break;
        case NULL_POINT:
            printf("��ָ��!!!\n");
            break;
        default:
            break;
    }
}

/**
 * ����˳���β�幦��
 * @warning ���ڲ��Է������޸Ĳ�������
 * @param list
 */
void testDelRepeatElement(ArrayList list) {
    int resultCode, moveCount;

    elementType data[] = {1, 2, 3, 4, 4, 5, 6, 6};
    initByArray(data, sizeof(data) / sizeof(elementType), list);
    showAll(list);

    //�˴��޸Ĳ�������
    resultCode = delRepeatElement(list, &moveCount);

    switch (resultCode) {
        case SUCCESS:
            showAll(list);
            printf("�ƶ�����:%d\n", moveCount);
            break;
        case NULL_POINT:
            printf("��ָ��!!!\n");
            break;
        default:
            break;
    }
}