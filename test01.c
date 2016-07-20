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
 * NAME: Richard Onyett (STMicroelectronics,San Jose)
 * EMAIL: richard.onyett@st.com
 *
 * PURPOSE: Test harness for Stack.
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
#include "stack.h"
#include "test.h"

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

/*
******************************************************************************
Private variables (static)
******************************************************************************
*/

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

/*
******************************************************************************
Exported Global variables
******************************************************************************
*/

/*
******************************************************************************
Prototypes of all functions contained in this file (in order of occurance)
******************************************************************************
*/

int test01 ( void )
{
  stack_t *sp = NULL;

  printf("\ntest01 - create stack and push some values\n" );

  sp = StackCreate(5);

  StackDump(sp,0);  /* Should be empty */

  push( sp, 100 );
  push( sp, 200 );
  push( sp, 300);
  push( sp, 700);

  StackDump(sp, 0);

  StackDestroy(sp);
  
  return 0;
}

int test02 ( void )
{
  stack_t *sp = NULL;

  printf("\ntest02 - create stack and push some values\n" );

  sp = StackCreate(3);

  push( sp, 100 );
  push( sp, 200 );
  push( sp, 300);
  StackDump(sp, 0);

  printf("pop %d\n", pop(sp));
  printf("pop %d\n", pop(sp));
  printf("pop %d\n", pop(sp));
  StackDump(sp, 0);
  
  return 0;
}

int test03 ( void )
{
  stack_t *sp = NULL;

  printf("\ntest03 - destroy stack tests\n" );

  printf("test03-01: destroy stack not created\n");
  StackDestroy(sp);
  
  printf("test03-02: destroy stack that is created\n");
  sp = StackCreate(3);
  StackDestroy(sp);
  
  StackDump(sp, 0);
  
  return 0;
}

int test04 ( void ) {
  stack_t *sp = NULL;

  printf("\ntest04 - Stack overflow\n" );

  sp = StackCreate(2);

  push( sp, 100 );
  push( sp, 200 );
  push( sp, 300 );    /* Should fail here */
  StackDump(sp, 0);

  printf("pop %d\n", pop(sp));
  printf("pop %d\n", pop(sp));
  printf("pop %d\n", pop(sp));
  StackDump(sp, 0);

  printf ("test04 - Ends\n");
  
  return 0;
}

int test05 ( void ) {
  stack_t *sp = NULL;

  printf("test05 - peeking\n");

  sp = StackCreate(3);
  printf("Peeking with nothing there %d\n", peek(sp));

  push(sp, 2001);
  push(sp, 2002);
  push(sp, 2003);

  StackDump(sp, 0);
  printf("Peeking with something there %d\n", peek(sp));

  return 0;
}

int test_run ( void ) {
  int error_code = 0;

  error_code = test01();    /* Run one of the tests */
  error_code = test02();    /* Run one of the tests */
  error_code = test03();    /* Run one of the tests */  
  error_code = test04();    /* Run one of the tests */
  error_code = test05();    /* Run one of the tests */
  
  return error_code;
}

//
// Fin
//
  
