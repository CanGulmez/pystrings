/* String Merhods in Python with C */

// Libraries:
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Identifier name:
#define PYSTRINGS_H 1

// Macros:
#define True  1
#define False 0

// New data types:
typedef char * string;
typedef unsigned short boolean;

/* --------------------------------------------------------------- */
/* ------------------------- Main Methods ------------------------ */
/* --------------------------------------------------------------- */

/* Return true if '__s' is alphanumeric. For example: 

string message = "Hello World";
boolean result = isalnum_py(message);
printf("%d\n", result);

0
*/
boolean isalnum_py(string __s) {
   // Iterate the all characters of '__s'.
   for (int i=0; i<strlen(__s); i++) 
      if (!isalnum(__s[i])) return False;

   return True;
}

/* Return true if '__s' is alphabet. For example: 

string message = "Hello World";
boolean result = isalpha_py(message);
printf("%d\n", result);

0
*/
boolean isalpha_py(string __s) {
   // Iterate the all characters of '__s'.
   for (int i=0; i<strlen(__s); i++) 
      if (!isalpha(__s[i])) return False;
      
   return True;
}

/* Return true if '__s' is ascii. For example: 

string message = "Hello World";
boolean result = isascii_py(message);
printf("%d\n", result);

1
*/
boolean isascii_py(string __s) {
   // Iterate the all characters of '__s'.
   for (int i=0; i<strlen(__s); i++) 
      if (!isascii(__s[i])) return False;
      
   return True;
}

/* Return true if '__s' is digit. For example: 

string message = "Hello World";
boolean result = isdigit_py(message);
printf("%d\n", result);

0
*/
boolean isdigit_py(string __s) {
   // Iterate the all characters of '__s'.
   for (int i=0; i<strlen(__s); i++) 
      if (!isdigit(__s[i])) return False;
      
   return True;
}

/* Return true if '__s' is identifier. For example: 

string message = "Hello_World";
boolean result = isidentifier(message);
printf("%d\n", result);

1
*/
boolean isidentifier(string __s) {
   // Check the first letter of '__s'.
   if (isdigit(__s[0])) return False;
   // Iterate the all characters of '__s'.
   for (int i=0; i<strlen(__s); i++) 
      if (__s[i] != '_')
         if (!isalnum(__s[i])) 
            return False;
      
   return True;
}

/* Return true if the all characters of '__s' is lower case. 
For example: 

string message = "hello world";
boolean result = islower_py(message);
printf("%d\n", result);

1
*/
boolean islower_py(string __s) {
   // Iterate the all elements of '__s'.
   for (int i=0; i<strlen(__s); i++) 
      if (isalpha(__s[i]) && !islower(__s[i]))
         return False;

   return True;
}

/* Return true if the all characters of '__s' is upper case. 
For example: 

string message = "HELLO WORLD";
boolean result = isupper_py(message);
printf("%d\n", result);

1
*/
boolean isupper_py(string __s) {
   // Iterate the all elements of '__s'.
   for (int i=0; i<strlen(__s); i++) 
      if (isalpha(__s[i]) && !isupper(__s[i]))
         return False;

   return True;
}

/* Return true if '__s' is printable. For example: 

string message = "Hello World\n";
boolean result = isprintable(message);
printf("%d\n", result);

0
*/
boolean isprintable(string __s) {
   // Iterate the all elements of '__s'.
   for (int i=0; i<strlen(__s); i++) 
      if (!isprint(__s[i]))
         return False;

   return True;
}

/* Return true if '__s' has space character/s. For example: 

string message = "Hello World";
boolean result = isspace_py(message);
printf("%d\n", result);

0
*/
boolean isspace_py(string __s) {
   // Iterate the all elements of '__s'.
   for (int i=0; i<strlen(__s); i++) 
      if (!isspace(__s[i]))
         return False;

   return True;
}

/* Convert the first letter to upper case of '__s'. For example: 

string message = "hello World";
string result = capitalize(message);
printf("%s\n", result);

Hello World
*/
string capitalize(string __s) {
   // Use the heap of the memory.
   string str = malloc(sizeof(char) * strlen(__s));
   // Copy the '__s' string into 'str'.
   for (int i=0; i<strlen(__s); i++) {
      if (isalpha(__s[i]) && !isupper(__s[i]) && i == 0)
         str[i] = toupper(__s[i]);
      else
         str[i] = __s[i];
   }
   return str;
}

/* Convert the '__s' to lower case. For example:

string message = "Hello World";
string result = casefold(message);
printf("%s\n", result);

hello world
*/
string casefold(string __s) {
   // Use the heap section of the memory.
   string str = malloc(sizeof(char) * strlen(__s));
   // Iterate the all characters of '__s'.
   for (int i=0; i<strlen(__s); i++) 
      str[i] = tolower(__s[i]);

   return str;
}

/* Return true if '__s' starts with '__value'. For example: 

string message = "Hello World";
boolean result = startswith(message, "Hello");
printf("%d\n", result);

1
*/
boolean startswith(string __s, string __value) {
   // Iterate the all characters of '__s'.
   for (int i=0; i<strlen(__s); i++)
      if (strcmp(strstr(__s, __value), __s))
         return False;

   return True; 
}

/* Return true if '__s' ends with '__value'. For example: 

string message = "Hello World";
boolean result = endswith(message, "ld");
printf("%d\n", result);

1
*/
boolean endswith(string __s, string __value) {
   // Iterate the all characters of '__s'.
   for (int i=0; i<strlen(__s); i++) 
      if (strlen(strstr(__s, __value)) != strlen(__value))
         return False;

   return True;
}

/* Convert the '__s' to lower case. For example:

string message = "Hello World";
string result = lower(message);
printf("%s\n", result);

hello world
*/
string lower(string __s) {
   // Can be used 'casefold' method for that.
   return casefold(__s);
}

/* Swap the case of all characters of '__s'. For example: 

string message = "Hello World";
string result = swapcase(message);
printf("%s\n", result);

hELLO wORLD
*/
string swapcase(string __s) {
   // Use the heap section of the memory.
   string str = malloc(sizeof(char) * strlen(__s));
   // Iterate the all characters of '__s'.
   for (int i=0; i<strlen(__s); i++) {
      if (isalpha(__s[i]) && islower(__s[i]))
         str[i] = toupper(__s[i]);
      else if (isalpha(__s[i]) && isupper(__s[i]))
         str[i] = tolower(__s[i]);
      else
         str[i] = __s[i];
   }
   return str;
}

/* Convert the all charaters of '__s' to upper. For example: 

string message = "Hello World";
string result = upper(message);
printf("%s\n", result);

HELLO WORLD
*/
string upper(string __s) {
   // Use the heap section of the memory.
   string str = malloc(sizeof(char) * strlen(__s));
   // Iterate the all characters of '__'.
   for (int i=0; i<strlen(__s); i++) 
      str[i] = toupper(__s[i]);

   return str;
}

/* Fill the '__s' with a specified number of 0. For example: 

string message = "Hello World";
string result = zfill(message, 15);
printf("%s\n", result);

0000Hello World
*/
string zfill(string __s, size_t __len) {
   // Return '__s' if lenght of '__s' is bigger than 'len'.
   if (strlen(__s) >= __len) return __s;
   // Use the heap section of the memory.
   int index = 0, remain = __len - strlen(__s);
   string str = malloc(sizeof(char) * __len);
   // Iterate the all characters of '__s'.
   for (int i=0; i<remain; i++) 
      str[i] = '0';
   for (int i=remain; i<__len; i++) 
      str[i] = __s[index], index ++;
   
   return str;
}

/* Reverse the '__s' from end to front. For example:

string message = "  Hello World";
string result = reverse(message);
printf("%s\n", result);

dlroW olleH
*/
string reverse(string __s) {
   // Use the heap section of memory.
   string str = malloc(sizeof(char) * strlen(__s));
   int index = 0; 
   // Iterate the '__s'.
   for (int i=strlen(__s)-1; i>=0; i--)
      str[index] = __s[i], index ++;

   return str;
}

/* Center the '__s' with '__el' and set its lenght to '__len'.
For example: 

string message = "hello";
string result = center(message, '-', 15);
printf("%s\n", result);

-----hello-----
*/
string center(string __s, char __el, size_t __len) {
   // Check if the lenght of '__s' is bigger than '__len'.
   if (strlen(__s) >= __len) return __s;
   // Use the heap section of the memory.
   string str = malloc(sizeof(char) * __len);
   int index = 0, cen = (int) (__len - strlen(__s)) / 2;
   // Append '__el' to front of 'str'.
   for (int i=0; i<cen; i++)
      str[index] = __el, index ++;
   // Append the characters of '__s' to 'str'.
   for (int i=0; i<strlen(__s); i++)
      str[index] = __s[i], index ++;
   // Append '__el' to end of 'str'.
   for (int i=strlen(__s) + cen; i<__len; i++)
      str[index] = __el, index ++;
   // Append the last '__el' at end of 'str'.
   if ((__len - strlen(__s)) % 2 == 1)
      str[index] = __el;
   
   return str;
}

/* Count the '__value' inside '__s'. For example:  

string message = "Hello World";
int result = count(message, "l");
printf("%d\n", result);

3
*/
int count(string __s, string __value) {
   // Declare the some variables.
   int index = 0, initial = 0, existance = 0;
   int finish = strlen(__value);
   // Slice the '__s' into substrings and check
   // if that is same with '__value'.
   while (True) {
      // Create the substrings.
      char substring[strlen(__value)]; 
      // Iterate the all characters of '__s'.
      for (int i=initial; i<finish; i++)
         substring[index] = __s[i], index++;
      // Compare the '__value' and 'substring'.
      if (!strcmp(__value, substring)) 
         existance ++;
      // Update the control variables.
      index = 0, initial ++, finish ++;
      // Break up the loop.
      if (finish == strlen(__s) + 1) break;
   }
   return existance;
}

/* Converrt the first character of each word to upper case. 
For example: 

string message = "hello world";
string result = title(message);
printf("%s\n", result);

Hello World
*/
string title(string __s) {
   // Use the heap section of the memory.
   string str = malloc(sizeof(char) * strlen(__s));
   int index = 0;
   // Check the first character of '__s'.
   if (isalpha(__s[0])) str[index] = toupper(__s[0]), index ++;
   else str[index] = __s[0], index ++;
   // Iterate the all characters of '__s'.
   for (int i=1; i<strlen(__s); i++) {
      if (isalpha(__s[i]) && !isalpha(__s[i-1]))
         str[index] = toupper(__s[i]), index ++;
      else
         str[index] = __s[i], index ++;
   }
   return str;
}

/* Return true, if '__s' string is title. For example: 

string message = "Hello World";
boolean result = istitle(message);
printf("%d\n", result);

1
*/
boolean istitle(string __s) {
   // Can be checked with 'title' method.
   if (!strcmp(__s, title(__s))) return True;
   else return False;
}

/* Search the '__s' for a specified '__value' and return the
position of where it was found. For example: 

string message = "Hello World";
boolean result = istitle(message);
printf("%d\n", result);

6
*/
int find(string __s, string __value) {
   // Check if the '__value' is in '__s' or not.
   if (!strstr(__s, __value)) return -1;
   else return strlen(__s) - strlen(strstr(__s, __value));
}

/* Convert the elements of '__slist' into string using '_sep'.
For example: 

string messages[] = {"Hello", "World", "!!!"};
string result = join(3, messages, " ");
printf("%s\n", result);

Hello World !!!
*/
string join(size_t __len, string __slist[__len], string __sep){
   // Use the heap section of the memory.
   int index = 0;
   string str = malloc(sizeof(char) * __len);
   // Iterate the all strings in the '__slist'. 
   for (int i=0; i<__len; i++) {
      // Concatenate the strings in order.
      for (int j=0; j<strlen(__slist[i]); j++)
         str[index] = __slist[i][j], index ++;
      // Append the '__sep' between each string.
      if (i != __len-1)
         for (int k=0; k<strlen(__sep); k++)
            str[index] = __sep[k], index ++;
   }
   return str;
}

/* Divide the '__s' into three parts using '__value' and
append them onto '__res'. For example:  

string message = "Hello World !!!";
string result[3];
partition(message, "World", result);
puts(result[0]);
puts(result[1]);
puts(result[2]);

Hello 
World
 !!!
*/
void partition(string __s, string __value, string __res[3]) {
   // Declare the some variables in here.
   int startpoint = find(__s, __value), index = 0;
   int endpoint = startpoint + strlen(__value);
   // If '__value' is not in '__s'.
   if (startpoint == -1) __res[0] = __s, exit(1);
   // Store the substrings is here.
   string s1 = malloc(sizeof(char) * startpoint);
   string s2 = malloc(sizeof(char) * strlen(__value));
   string s3 = malloc(sizeof(char) * (strlen(__s)-endpoint));
   // Otherwise slice the '__s' into substrings.
   for (int i=0; i<startpoint; i++)
      s1[i] = __s[i];
   for (int j=startpoint; j<endpoint; j++)
      s2[j - startpoint] = __s[j];
   for (int k=endpoint; k<strlen(__s); k++)
      s3[k - endpoint] = __s[k];
   // Append the substrings onto '__res'.
   __res[0] = s1, __res[1] = s2, __res[2] = s3;
}

/* Align the '__s' to left using specified '__value' and
resize the '__s' using '__len'. For example: 

string message = "Hello World";
string result = ljust(message, '-', 20);
printf("%s\n", result);

Hello World---------
*/
string ljust(string __s, char __el, size_t __len) {
   // Use the heap section of the memory.
   string str = malloc(sizeof(char) * __len);
   int index = 0;
   // If lenght of '__s' is bigger than '__len', in that
   // case return '__s' directly.
   if (__len <= strlen(__s)) return __s;
   // Otherwise, align the '__s'.
   for (int i=0; i<strlen(__s); i++)
      str[index] = __s[i], index ++;
   for (int j=0; j<__len-strlen(__s); j++)
      str[index] = __el, index ++;

   return str;
}

/* Delete the any leading '__value' from '__s'. For example: 

string message = "  Hello World";
string result = lstrip(message, "  ");
printf("%s\n", result);

Hello World
*/
string lstrip(string __s, string __value) {
   // Use the heap section of the memory.
   string str = malloc(sizeof(char) * strlen(__s));
   int index = 0;
   // If '__value' is not in '__s'.
   if (find(__s, __value) != 0) return __s;
   // Otherwise, delete the '__value'.
   for (int i=strlen(__value); i<strlen(__s); i++)
      str[index] = __s[i], index ++;
   
   return str;
}

/* Replace a specifed '__old' with '__new' in the '__s'. 
For example: 

string message = " Hello World ";
string result = replace(message, " ", "__");
printf("%s\n", result);

__Hello__World__
*/
string replace(string __s, string __old, string __new) {
   // Use the heap section of the memory.
   int lenght = strlen(__s)+strlen(__new)-strlen(__old);
   string str = malloc(sizeof(char) * lenght);
   // Determine the indexes which will be used in loop.
   int index1 = 0, index2 = 0;
   // Declare the first and last boundaries.
   int initial = 0, end = strlen(__old);
   // Create a infinite loop.
   while (True) {
      // Generate the substrings in order.
      string substr = malloc(sizeof(char) * strlen(__s));
      for (int i=initial; i<end; i++)
         substr[index1] = __s[i], index1 ++;
      // Compare the 'substr' and '__old'.
      if (strcmp(substr, __old)) 
         for (int i=0; i<strlen(substr); i++)
            str[index2] = substr[i], index2 ++;
      else
         // Replace the '__new' with '__old'.
         for (int j=0; j<strlen(__new); j++)
            str[index2] = __new[j], index2 ++;
      // Update the control variables.
      index1 = 0, initial += strlen(__old);
      end += strlen(__old);
      // Break up the infinite loop.
      if (end > strlen(__s)) break;
   }
   return str;
}

/* Delete any leading '__value' to the right of '__s'. 
For example: 

string message = " Hello World!!!";
string result = rstrip(message, "!!!");
printf("%s\n", result);

Hello World
*/
string rstrip(string __s, string __value) {
   // Previously, get the reverse of '__s' and '__value'
   string rs = reverse(__s), rvalue = reverse(__value);
   // Use the 'strip()' method for that.
   string lstriped = lstrip(rs, rvalue);
   // And again, get the reverse and return it.
   return reverse(lstriped);
}

/* Find the last occurance of '__value' in '__s'. For example: 

string message = "Hello World";
int result = rfind(message, "l");
printf("%d\n", result);

9
*/
int rfind(string __s, string __value) {
   // Previously, get the reverse of '__s' and '__value'.
   string rs = reverse(__s), rvalue = reverse(__value);
   // Use the 'find()' method for that.
   int roccur = find(rs, rvalue);
   // Return the proper respose to function.
   if (roccur == -1) return -1;
   else return strlen(__s) - (roccur + strlen(__value)); 
}

/* Delete any leading '__value' to the both right and  
left of the '__s'. For example:

string message = "__Hello World__";
string result = strip(message, "__");
printf("%s\n", result);

Hello World
*/
string strip(string __s, string __value) {
   // Can be used both 'lstrip()' and 'rstrip()' method.
   return rstrip(lstrip(__s, __value), __value);
}

/* Align right the '__s' using specified  '__el' and resize
the '__s' according to '__len'. For example: 

string message = "Hello World";
string result = rjust(message, '_', 15);
printf("%s\n", result);

----Hello World
*/ 
string rjust(string __s, char __el, size_t __len) {
   // Can be used both 'reverse()' and 'ljust' methods.
   return reverse(ljust(reverse(__s), __el, __len));
}

/* Search for a specified '__value' in '__s' and save
them onto '__res'. For example: 

string message = "Hello World !!!";
string result[3];
rpartition(message, "l", result);
puts(result[0]);
puts(result[1]);
puts(result[2]);

Hello Wor
l
d !!!
*/
void rpartition(string __s, string __value, string __res[3]) {
   // Previously, get the reverse of both '__s' and '__value'
   string rs = reverse(__s), rvalue = reverse(__value);
   // Using 'partition()' method, split the reversed '__s'
   // with reversed '__value' and same them onto '__rres'.
   string __rres[3]; partition(rs, rvalue, __rres);
   // Lastly, get the reverse of each substring in '__rres'
   // and then same them onto '__res'.
   __res[0] = reverse(__rres[2]); 
   __res[1] = reverse(__rres[1]); 
   __res[2] = reverse(__rres[0]); 
}
