#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/tests.h"

#include "../include/charQueueADT.h"
#include "../include/linkedListQueue.h"
#include "../include/unity/unity.h"

static void test_mkQueue(void)
{
    CharQueueADT pQ = mkQueue();
    if (pQ == NULL) return;
    TEST_ASSERT_NULL(pQ->front);
    TEST_ASSERT_NULL(pQ->rear);

    dsQueue(&pQ);
}

static void test_dsQueue(void)
{
    CharQueueADT pQ = mkQueue();
    if (pQ == NULL) return;

    dsQueue(&pQ);

    TEST_ASSERT_NULL(pQ);
}

static void test_enQueue(void)
{
    CharQueueADT pQ = mkQueue();
    if (pQ == NULL) return;

    // null pointer
    bool ris1 = enqueue(NULL, 'a');
    TEST_ASSERT_FALSE(ris1);

    // empty string
    bool ris2 = enqueue(pQ, '\0');
    TEST_ASSERT_FALSE(ris2);

    // just adding at the beginning 
    bool ris3 = enqueue(pQ, 'a');
    TEST_ASSERT_TRUE(ris3);
    TEST_ASSERT_EQUAL_PTR(pQ->front, pQ->rear);
    TEST_ASSERT_EQUAL_INT(pQ->front->data, 'a');
    TEST_ASSERT_EQUAL_INT(pQ->rear->data, 'a');
    TEST_ASSERT_EQUAL_INT(pQ->size, 1);

    // just adding, not front
    bool ris4 = enqueue(pQ, 'b');
    TEST_ASSERT_TRUE(ris3);
    TEST_ASSERT_EQUAL_INT(pQ->front->data, 'a');
    TEST_ASSERT_EQUAL_PTR(pQ->front->next, pQ->rear); 
    TEST_ASSERT_EQUAL_INT(pQ->rear->data, 'b');
    TEST_ASSERT_EQUAL_INT(pQ->size, 2);

    dsQueue(&pQ);
}

static void test_dequeue(void)
{
    CharQueueADT pQ = mkQueue();
    if (pQ == NULL) return;
    char res;

    // NULL pointers
    bool ris1 = dequeue(NULL, NULL);
    TEST_ASSERT_FALSE(ris1);

    // empty q
    bool ris2 = dequeue(pQ, &res);
    TEST_ASSERT_FALSE(ris2);

    // just works
    enqueue(pQ, 'a');
    enqueue(pQ, 'b');
    enqueue(pQ, 'c');
    enqueue(pQ, 'd');

    bool ris3 = dequeue(pQ, &res);
    TEST_ASSERT_TRUE(ris3);
    TEST_ASSERT_EQUAL_INT(pQ->front->data, 'b');
    TEST_ASSERT_EQUAL_INT(pQ->rear->data, 'd');
    TEST_ASSERT_EQUAL_INT(res, 'a');
    TEST_ASSERT_EQUAL_INT(pQ->size, '3');

    dsQueue(&pQ);
}

static void test_isEmpty(void)
{

}

static void test_size(void)
{

}

static void test_peek(void)
{

}

void setUp(void)
{
}

void tearDown(void)
{
}

int runAllTests(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_mkQueue);
    RUN_TEST(test_dsQueue);
    RUN_TEST(test_enQueue);
    RUN_TEST(test_dequeue);
    // RUN_TEST(test_isEmpty);
    // RUN_TEST(test_size);
    // RUN_TEST(test_peek);
    return UNITY_END();
}