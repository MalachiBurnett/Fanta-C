# Fanta-C  
a basic programming language interpreter written in c++  
# Syntax  
#### initialise a variable:  
  variable names can include characters from a-z and A-Z  
  ###### strings:  
    if the value being initialised to a variable is in double quotes, it will be initialised as a string. for example:  
      example = "Hello World!"  
    any ascii charaters except for double quotes can be inside a string  
 ###### integers:  
    if the value being initialised to a variable consists of numbers 0-9, it will be initialised as an int. for example:  
      example = 25  
#### operations:  
  you can calculate and assign a value to a varible by writing:  
    A = B + C  
  operations include:  
    % (modulo)  
    * (multiply)  
    / (integer division)  
    - (subtract)  
    + (add)  
    for strings you can use:  
      + (concatenate)  
#### labels:  
  in Fanta-C, you can write:  
    label "string"  
  to define a label that you can jump to  
  to jump, use:  
    jump "lablename"  
#### conditions:  
  you can also jump if a condition is true:  
    if condition jump "labelname"  
  conditions include:  
    ==  
    !=  
    >=  
    <=  
    >  
    <  
  string comparisons are not available yet. you can only compare integers  
 #### print:  
    you can output to the console by writing:  
      print "string"  
    or  
      print variable  
    this works for both integer variables and string variables  
    
