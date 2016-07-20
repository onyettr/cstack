/*
 *****************************************************************************
 *! \file 
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
 * PURPOSE: 
 * Header file for simple stack
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
#ifndef __STACK_H__
#define __STACK_H__

/*
******************************************************************************
Private Constants
******************************************************************************
*/

/*
******************************************************************************
Private Types
******************************************************************************
*/

/**
 * \struct stack
 * \brief  Data structure to hold the details about a stack. 
 */
typedef struct stack { /*! stack type                    */
  int StackMax;        /*! Max size of the created stack */
  int StackTop;        /*! point at the top of the stack */
  int *pStack;         /*! actual stack                  */
} stack_t;

/*
******************************************************************************
Private Macros
******************************************************************************
*/

/*
******************************************************************************
Global variables
******************************************************************************
*/

/*! \fn     int pop  (stack_t *pStack)
 *  \brief  pop an element from the stack pointed to
 *  \param  stack_t *pStack - Pointer to the stack
 *  \param  int - returns (int) element
 */
int pop  (stack_t *pStack);
int peek (stack_t *pStack);
void push(stack_t *pStack, int element);
void StackDump (stack_t *pStack, int num);
stack_t *StackCreate(int maxStack);
void StackDestroy( stack_t *sp );

typedef enum { false, true } bool;

#endif // __STACK_H__

