> This is kinda outated

# Powerscript code documentation
This is not the documentation for the language but for the language's source

> This is still under alot of work, so some parts of it might not be accurate, but you can trust it i guess.
## Coding style
Just make it like really efficient. Keep a basic structure but make it so code get executed the fasted way possible with the less processing needed. Memory might still be important.
Functions need to do what they are named as, and be designed to be the most efficient way to execute their purpose.

Comments are to be written for stuff that is not enough important to be in this documentation but might still help alot, huge blocks of texts are forbideen. ex:
```cpp
std::string CWord; // Current Word
```

Keeping code that might be usefull later in comments are ok. This is probably really wrong but this is the way that is the most efficient in my opinion.
## Operating system specific
The powerscript interpreter runs on Mac OS, Linux and Windows so there is some OS specific code that needs to be run and this is why this section exists.
## Macro
OS Specific macros are very useful in the making of the code. All the macros are contained in the ``OS.h`` file which is made for that purpose.
#### OsCode ``int``
The OsCode is an interger declared in the "OS.h" file, it dictactes on what OS the code is run on.
> Note:  Win32 and Win64 are considered the same OS and code

| OS | Code|
|---------|---|
| Unknow  | 0 |
| Win32 | 1 |
| Win64 | 1 |
| Mac OS  | 2 |
| Linux   | 3 |
### OsString ``macro(string)``
This macro is the string of the platform you are on. There isn't any immediate use to it yet, but when openning the console it is used to display the platform.
| OS | String |
|--|--|
| Unknown | Unknown |
| Win32   | Windows 32bit|
| Win64   | Windows 64bit|
| Mac OS  | MacOS   |
| Linux   | Linux   |

## Core
This interprets and run the code that has been classified by the parser.
### Environement Class
The environement is the class where all the powerscript code is stored,organized,parsed and run. You can use the class to get powerscript values from c++ or c++ values from powerscript.
***
#### Run ``void``
```cpp
Run(
)
```
Execute the code from the environement. Will mostly check for keywords send the values to the Variable,Function or Class file.
> Theses files still doesn't exist
***
#### Add ``void``
```cpp
Add(
std::string
)
```
Add the string to the environement's code, which will be later parsed. This works by using the parser's disjoint function and making the env wordlist as the value disjoint return.
> This does not actually run the code

---
### Argument class
Pretty important for functions and values.

#### CValue ``value``
Stands for current value

#### Type ``int``
| Type | Code |
|--|--|
| Variable | 0 |
| Value | 1 |
Declar what kind of argument it is.

---

### Value Class
Pretty important for values

---
#### Type ``int``
| Type | Code |
|--|--|
| unknown | 0 |
| int | 1 |
| bool | 2 |
| string | 3 |
The type of the value

---

## Parser
The parser is probably the most important part of the code.

#### Disjoint ``std::vector<std::string>``
``Parser.cpp``
```cpp
Disjoint(
	std::string
)
```
Seperate the words in the string, removing the spaces and making syntaxic symbol(if that even makes sense) in a different element that words. The resulting vector is a "wordlist" that can be used by other components of the code.

Code:
```cpp
Disjoint("global a=1")
```
Output:
 ``global,a,=,1``
>Commas are not part of the elements
---
#### Analyze ``void``
```cpp
Analyze(
std::vector<std::string>
)
```
Analyze a word list and return statements, that can be easily ran by the interpreter.
### Statement class
When parsed, the parser will detect statement,this statement class will get analyzed by the interpreter and be ran.

---
#### Statement ``constructor``
Default constructor for a class, pretty much does nothing at the moment.
```cpp
Statement(
)
```
---
#### Type ``int``
This is the type of the statement
| Statement | Code |
|--|--|
| Invalid | 0 |
| Variable Declaration | 1 |
| Variable Definition  | 2 |
| Function Dec | 3 |
| Function Def | 4 |
| Function Call | 5 |
| If | 6 |
| Else | 7 |
#### Name ``std::string``
If it exists, the name of the subject of the statement.
#### Value ``std::string``
If it exists the value which is a string because it can contain pretty much anything.

## Files
There is files in the project xd
I hate it when like big projects have like billions of files and I have no way to know what they do and where to begin. This is why i dont use github alot.

``OS.h`` -- Contains OS specific preprocessors
``Powerscript.cpp`` --  Powerscript core & environement class definition, code is ran there and redirected to specific files
``Powerscript.h`` -- Powerscript core & environement class declaration
``Parser.cpp`` -- Parser core definition, almost all the parser is here
``Parser.h`` -- Parser core declaration
``Variable.cpp`` -- Interacs with values & parse variables
``Variable.h`` -- Interacs with values & parse variables
``Function.cpp`` Define everything to do with functions
``Function.h`` Declare everything to do with functions
``Loop.cpp`` Define loops such as (while,for,etc)
``Loop.h`` Declare loops such as (while,for,etc)

---

##### (c) Maxence Cossette 2019
