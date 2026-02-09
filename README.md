# TheBohrAtom
This program recieves and validates user input, then calculates the transition energy between electron shell levels from the given input.



### Statement on the use of AI
No generative AI was used in the writing of or debugging of this code, all code was written and debugged by me with the use of the internet.

### Description of devlopment timeline
Intitially wrote a base code that simply takes an input and calculates the transition energy using a separate function, then prints out that output. For me pow(n, 2) is preffered over n^2, as I personally find it easier to read in the expression, and doesn't meaningfully impact performance in this case. I then introduced a loop to keep the program running until told to stop.

I then introduced some basic input validation - making sure the input is of the correct type and value. Input was converted to lowercase to ensure program runs whether input is capitalised or not. Initially had some errors with attempting to validate integers, and then remembered "cin" only looks at the values up the first non-integer, and places the rest in a buffer, meaning an input of "4.53" would not fail as it would take the first integer part successfully. Instead, retrieved the entire line using getline(), and then parsed the string as a stream to validate each character within the string. The code for this process was taken and slightly modified from https://thelinuxcode.com/check-integer-input-cpp/. Used stringstreams as it made for easy and clean range validation, also as input is small, there is little need to worry about resource overhead.

The physical constrains implemented were that all variables must be integer and greater than 0 (Z, n1, n2) and that n2 must be greater than n1. No maximum condition was set on Z, as although there are several theoretical limits on Z (Some theories suggest a max of 137, others of 173), there is no consistent, experimentally known maximum, and the physical meaning of the equation still stands beyond these values, so I believe constraining between two values is unecessary.

Once final program was working as intended, added in a title and description.