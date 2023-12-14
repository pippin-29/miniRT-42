# libft
My work for 42 School, Contains a library designed for the work later assigned in the cursus.

I have learnt alot about the logic involved in maipulating strings,
I have also learnt about linked lists.

My grade for the project was 120 out of 100.


ft_substr will segfault on fsoares own test (No. 4) (KO segfault) using the francinette tester,
ft_substr("hola", 4294967295, 0): Segmentation Fault, I have not tested if moulinette is okay with this, but i would say so.
If you want a definite pass for substr, remove the helper function and malloc using len + 1, which will allocate too much memory in some cases. I have not found a fix for passing this test, although i see no reason to do that.


## Updated 17 Nov 2023

added functions:
  - is_whitespace // checks if string is only whitespace
  - strjoin_e       // creates a char * that has a variable number of input strings to be joined
  - ft_tabcpy      // creates duplicate of a char ** with memory allocated.

## Updated 15 Dec 2023

renamed ft_tabcpy to ft_tabdup, as it has similar functionality to strdup from <string.h>
   - i.e. it creates a pointer and allocates memory to be moved to a new variable, whilst not destroying the old variable.
   - naming convention uses the word tab (table).
