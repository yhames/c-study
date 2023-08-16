# 1 "ExtremeC_examples_chapter2_1.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 414 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "ExtremeC_examples_chapter2_1.c" 2
# 1 "./ExtremeC_examples_chapter2_1.h" 1



typedef enum {
 NONE,
 NORMAL,
 SQUARED
} average_type_t;

double avg(int*, int, average_type_t);
# 2 "ExtremeC_examples_chapter2_1.c" 2

double avg(int *array, int length, average_type_t type)
{
 int i;
 double sum;

 if (length <= 0 || type == NONE)
 {
  return (0);
 }
 sum = 0.0;
 i = 0;
 while (i < length)
 {
  if (type == NORMAL)
  {
   sum += array[i];
  }
  else if (type == SQUARED)
  {
   sum += array[i] * array[i];
  }
  i++;
 }
 return (sum / length);
}
