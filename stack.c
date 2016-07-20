/*
 *****************************************************************************
 * 
 * MODULE: C Programming Examples
 *
 * $Header: $
 * $Archive:$
 * 
 * $Workfile: $
 *
 * $Author: Onyettr $
 *
 * NAME: Richard Onyett 
 * EMAIL: 
 *
 * PURPOSE: Simple Stack implementation
 *
 * 
 * $Revision:$
 * $History: $
 *
 ***************************************************************************** 
 */

/*
******************************************************************************
Includes
******************************************************************************
*/
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "trap.h"

static bool isFull (stack_t *pStack);
static bool isEmpty(stack_t *pStack);

/*
 -- --------------------------------------------------------------
 -- static int isEmpty(stack_t *pStack)
 -- --------------------------------------------------------------
*/
static bool isEmpty(stack_t *pStack) {
  return pStack->StackTop == -1 ? true : false;
}

/*
 -- --------------------------------------------------------------
 -- static int isFull(stack_t *pStack) 
 -- --------------------------------------------------------------
*/
static bool isFull(stack_t *pStack) {
  return pStack->StackTop == (pStack->StackMax - 1) ? true : false;
}

/*
 -- --------------------------------------------------------------
 -- int pop(stack_t *pStack) - "pop" off the top of the stack
 --   stack_t *pStack - Stack to pop from
 --
 -- returns: int stack value
 -- --------------------------------------------------------------
*/
int pop(stack_t *pStack) {
  if (isEmpty(pStack)) {
    printf ("Stack empty - Cannot pop\n");
    Thrower(e_stackunderflow);
    
    return -1;
  }

  return pStack->pStack[pStack->StackTop--];
}

/*
 -- --------------------------------------------------------------
 -- int peek(stack_t *pStack) - "peek" the top of the stack
 -- --------------------------------------------------------------
*/
int peek(stack_t *pStack) {
  if (isEmpty(pStack)) {
    printf ("Stack empty - Cannot peek\n");
    Thrower(e_stackunderflow);
    
    return -1;
  }

  return pStack->pStack[pStack->StackTop];  
}

/*
 -- --------------------------------------------------------------
 -- void push(stack_t *pStack, int element) 
 -- --------------------------------------------------------------
*/
void push(stack_t *pStack, int element) {
  if (isFull(pStack)) {
    printf ("Stack Overflow - Cannot push\n");
    Thrower(e_stackoverflow);
    
    return;
  }

  pStack->pStack[++pStack->StackTop] = element;    
}

/*
 -- --------------------------------------------------------------
 -- --------------------------------------------------------------
*/
void StackDump (stack_t *pStack, int num) {
  int i;
  int numtoShow = 0;
  
  if (isEmpty(pStack)) {
    printf ("Stack empty - nothing to display\n");

    return;
  }

  if ( num == 0) {
    numtoShow = pStack->StackMax;
  } else {
    numtoShow = num;
  }
  
  for (i=0; i < numtoShow; i++) {
    printf("Stack[%4d] = %d", i, pStack->pStack[i] );
    if ( i == pStack->StackTop ) {
      printf("  <--- Stacktop");
    }
    printf("\n");  
  }
}

/**
 -- --------------------------------------------------------------
 -- \fn     stack_t *StackCreate(int maxStack)
 -- \brief  creates a stack of the size specified in maxStack
 -- \param  int maxStack - Maximum size of the Stack to create
 -- \param  return stack_t pointer to the stack_t structure
 -- --------------------------------------------------------------
*/
stack_t *StackCreate(int maxStack) {

  /*
   * create a stack "head"
   */
  stack_t *pStackHead = (stack_t *)malloc(sizeof(stack_t));
  if ( pStackHead == NULL )
    return (stack_t *)NULL;
  
  pStackHead->StackMax = maxStack; /* High water mark for the stack */
  pStackHead->StackTop = -1;       /* Ready for push                */

  /*
   * create the actual stack to push and pull from 
   */
  pStackHead->pStack   = (int *)malloc(sizeof(int) * maxStack);

  return pStackHead;
}

/*
 -- --------------------------------------------------------------
 -- --------------------------------------------------------------
*/
void StackDestroy(stack_t *sp) {

  if ( sp == (stack_t *)NULL) {
    printf("StackDestroy: No valid stack handle\n");

    return;
  }

  /*
   * destroy the actual stack to push and pull from 
   */
  free (sp->pStack); 

  return;
}
