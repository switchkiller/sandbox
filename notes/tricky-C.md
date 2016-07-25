
Examples:

Predict the output:

1.

    char *getString()
    {
        char str[] = "Will I be printed?";
        return str;
    }
    int main()
    {
        printf("%s", getString());
        getchar();
    }

2.

    char *getString()
    {
        char *str = "Will I be printed?";
        return str;
    }
    int main()
    {
        printf("%s", getString());
        getchar();
    }


----
In case of 1 we get an error.

    function returns address of local variable

Which means that the getString is returing a variable which no longer exists in stack. Thus str is a dangling pointer.

In case of 2 we get no error. The str is a pointer to a characters. Notice, pointers are not stored in the stack section rather in the heap section. Hence we get normal output.

----

3.

    #include <stdio.h>
    int main()
    {
      printf("%d", main);
      getchar();
      return 0;
    }

Output: Address of the main function.

The name of the function is actually a pointer to the function. Hence we get the address of the function.


----

4.


      i = 1, 2, 3;

i takes the value 1 because the precidence rule. Statement acts as:

`(i = 1), 2, 3;`

5.


        i = (1, 2, 3);

i takes the value 3.
