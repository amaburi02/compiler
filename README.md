So far, if I remember correctly, as it is right now it only supports basic arithmetic (+, -, *, /), IF/THEN, CONST, VAR, compound statements, and relational operators, thus input2.txt probably won't work past generating a symbol table.
### Program Files:
- main.cpp
- scanner.cpp/scanner.h
- syntax_analyzer.cpp/syntax_analyzer.h
- code_gen.cpp/code_gen.h

### Input Files:
- token_fsa.txt (state table for finite state automata)
- symbol_fsa.txt
- syntax_table.txt (precedence state table)
- input.txt (example programs)
- input2.txt
- input3.txt
- input4.txt

### Output Files:
- token_list.txt
- symbol_table.txt
- parse_output.txt (quads)
- program.asm (generated assembly file)

### Java0 Grammar
#### Scanner:
```
<ident> ::= <letter>
          | <letter><letter-digit>

<letter-digit> ::= <letter-digit><letter>
                 | <letter-digit><digit>
                 | <letter>
                 | <digit>

<integer> ::= <digit>
            | <integer><digit>

<letter> ::= a | b | c | ... | y | z
           | A | B | C | ... | Y | Z

<digit> ::= 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9

<comment> ::= /* any comment string */
```
#### Parser:
```
<program> ::= CLASS <ident> { <block> }

<block> ::= <constant def part>
            <variable def part>
            <procedure def part>
            <stmt>

<constant def part> ::= <empty>
                      | CONST <const list> ;

<const list> ::= <const list> , <ident> = <integer>
               | <ident> = <integer>

<variable def part> ::= <empty>
                      | VAR <var list> ;

<var list> ::= <var list> , <ident>
             | <ident>

<procedure def part> ::= PROCEDURE <ident> ( ) { <block> }
                       | PROCEDURE <ident> <parm list> { <block> }
                       | <empty>

<stmt> ::= <simple stmt>
         | <call stmt>
         | <compound stmt>
         | <if stmt>
         | <while stmt>
         | <stmt list>
         | <empty>

<empty> ::= 

<simple stmt> ::= <ident> = <exp>

<call stmt> ::= CALL <ident> ( )
              | CALL <ident> <parm list>

<parm list> ::= ( <ident list> )

<ident list> ::= <ident list> , <ident>
               | <ident>

<compound stmt> ::= { <stmt list> }

<stmt list> ::= <stmt list> ; <stmt>
              | <stmt>

<if stmt> ::= IF <b.e.> THEN <stmt>

<while stmt> ::= WHILE <b.e.> DO <stmt>

<b.e.> ::= ODD <exp>
         | <exp> <relop> <exp>

<relop> ::= == | != | > | < | >= | <=

<exp> ::= <addop> <term>
        | <exp> <addop> <term>

<addop> ::= + | -

<term> ::= <fac>
         | <term> <mop> <fac>

<mop> ::= * | /

<fac> ::= <ident>
        | <integer>
        | ( <exp> )
```
 Reserved Words:
```
CONST	IF	VAR	THEN
PROCEDURE	WHILE	CALL	DO
ODD	CLASS		
```
Single Character Delimiters:
```
=	,	;	+
-	*	/	(
)	<	>	{
}			
```
Double Character Delimiters:
```
==	>=	<=	!=
/*	*/		
```
Comments are enclosed in “```/*```” and “```*/```”.  They may appear anywhere in a sentence and have no meaning to the translator.
