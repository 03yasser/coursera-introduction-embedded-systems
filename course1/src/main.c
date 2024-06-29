/******************************************************************************
 * Copyright (C) 2024 by Yasser Boutslihghoi
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted provided this copyright notice is preserved. Users are 
 * allowed to modify this and use it for learning about embedded software. 
 * Yasser Boutslihghoi is not responsible for any misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file main.c
 * @brief Main entry point for the program
 *
 * This source file contains the main function which is the entry point for the
 * program. It conditionally calls the function 'course1' if the macro 'COURSE1'
 * is defined.
 *
 * @author Yasser Boutslihghoi
 * @date June 29, 2024
 *
 */

#include "course1.h"

int	main(void) 
{
	#ifdef COURSE1
		course1();
	#endif
	return 0;
}