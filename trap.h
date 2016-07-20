/*!
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
#ifndef __TRAP_H__
#define __TRAP_H__

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
typedef enum e_stack_policy {
  e_lifo = 0,
  e_fifo
} e_stack_policy_t;

typedef enum stack_exception {
  e_stackoverflow    = 100,
  e_stackunderflow   = 200,
  e_stackoutofmemory = 300
} stack_exception_t;

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
void Thrower(stack_exception_t exp);

#endif // __TRAP_H__

