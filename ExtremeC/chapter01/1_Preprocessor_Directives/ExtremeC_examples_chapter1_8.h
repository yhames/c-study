// example of Header Guards
// which prevent double inclusions of .h file
// #ifdef #endif could be replaced with #pragma once
// but #pragma is not included in Standard C
// #pragma should not be used when code portability is needed
// this is the code example using #pragma
// ```C
// #pragma once
// 
// void say_hello();
// int read_age();
// ```

#ifndef EXAMPLE_1_8_H 
#define EXAMPLE_1_8_H

void say_hello();
int read_age();

#endif
