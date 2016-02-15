/* See COPYRIGHT for copyright information. */

#ifndef JOS_INC_ASSERT_H
#define JOS_INC_ASSERT_H

#include <inc/stdio.h>

void _warn(const char*, int, const char*, ...);
void _panic(const char*, int, const char*, ...) __attribute__((noreturn));

#define warn(...) _warn(__FILE__, __LINE__, __VA_ARGS__)
#define panic(...) _panic(__FILE__, __LINE__, __VA_ARGS__)

#define assert(x)		\
	do { if (!(x)) panic("assertion failed: %s", #x); } while (0)

// static_assert(x) will generate a compile-time error if 'x' is false.
#define static_assert(x)	switch (x) case 0: case (x):

// assert macros used by ZBY
// ZBYDEBUG and ZBYassert macros WILL NOT affect complexity
#define ZBYDEBUG
#ifdef ZBYDEBUG
#define ZBYassert assert
#else
#define ZBYassert(x) do {} while (0)
#endif
// ZBYSLOWDEBUG and ZBYSLOWassert macros WILL affect complexity
#define ZBYSLOWDEBUG
#ifdef ZBYSLOWDEBUG
#define ZBYSLOWassert assert
#else
#define ZBYSLOWassert(x) do {} while (0)
#endif

#endif /* !JOS_INC_ASSERT_H */
