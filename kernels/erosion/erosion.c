#include "klee/klee.h"
#include <stdio.h>
#include <stdlib.h>

short **allocate_image_array(length, width) long length, width;
{
  int i, j;

  short **the_array = (short **)malloc(length * sizeof(short *));
  for (i = 0; i < length; i++) {
    the_array[i] = (short *)malloc(width * sizeof(short));
    if (the_array[i] == NULL) {
      printf("\n\tmalloc of the_image[%d] failed", i);
    } /* ends if */
  }   /* ends loop over i */

  for (i = 0; i < length; i++)
    for (j = 0; j < width; j++)
      the_array[i][j] = 0;

  return (the_array);
}

int erosion(short **the_image, short **out_image, short value, int threshold,
            long rows, long cols) {
  int a, b, count, i, j, k;

  /***************************
   *
   *   Loop over image array
   *
   ****************************/

  for (i = 0; i < rows; i++)
    for (j = 0; j < cols; j++)
      out_image[i][j] = the_image[i][j];

  // printf("\n");

  for (i = 1; i < rows - 1; i++) {
    // if( (i%10) == 0) printf("%3d", i);
    for (j = 1; j < cols - 1; j++) {
#ifdef MERGE
      klee_open_merge();
#endif
      if (the_image[i][j] == value) {
        count = 0;
        for (a = -1; a <= 1; a++) {
          for (b = -1; b <= 1; b++) {
#ifdef MERGE
            klee_open_merge();
#endif
            if ((i + a) >= 0) {
#ifdef MERGE
              klee_open_merge();
#endif
              if (the_image[i + a][j + b] == 0)
                count++;
#ifdef MERGE
              klee_close_merge();
#endif
            }
#ifdef MERGE
            klee_close_merge();
#endif
          } /*  ends loop over b */
        }   /* ends loop over a */
#ifdef MERGE
        klee_open_merge();
#endif
        if (count > threshold) {
          out_image[i][j] = 0;
        }
#ifdef MERGE
        klee_close_merge();
#endif
      } /* ends if the_image == value */
#ifdef MERGE
      klee_close_merge();
#endif
    } /* ends loop over j */
  }   /* ends loop over i */

  /*****
  fix_edges(out_image, 3, rows, cols);
  ***/
  return (1);
}

int main() {

  int i, j, mask_type, number;
  int threshold = 1;
  short value = 1;
  long length = SIZE;
  long width = SIZE;
  short **the_image;
  short **out_image;

  the_image = allocate_image_array(length, width);
  out_image = allocate_image_array(length, width);

  for (int i = 0; i < length; i++) {
    klee_make_symbolic(the_image[i], width * sizeof(short), "the_image");
  }

  // each pixel value is either 0 or 1
  for (int i = 0; i < length; i++) {
    for (int j = 0; j < width; j++) {
      klee_assume(((the_image[i][j] == 0) | (the_image[i][j] == 1)));
    }
  }

  erosion(the_image, out_image, value, threshold, length, width);

#ifdef VERIFY
  // each pixel value must be smaller or eqaul to original value
  for (int i = 0; i < length; i++) {
    for (int j = 0; j < width; j++) {
      klee_assert(out_image[i][j] <= the_image[i][j]);
    }
  }
  printf("Verified!\n");
#endif

  return 0;
}
