
# C - Sorted array
**Description**
You are given an array of integers and need to output the numbers from that array in increasing order. Note: use the sorting function of your chosen language.

**Input**
Each line gives a number in the array until the end-of-file (EOF) is found.

**Output**
The numbers of the array, one per line, in increasing order.

**Example**
		
Input
	
	2
	3
	1
		
Output

	1
	2
	3



# D - Building a list
**Description**
You start with a list that contains a single value 0, and a pointer to that value. Then you receive a list of instructions that can take the following values:

	MOVE LEFT
	MOVE RIGHT
	INSERT LEFT int
	INSERT RIGHT int
  
The first two instruct you to move the pointer to the left or to the right respectively. It is guaranteed that you will never move beyond the limits of the list. The last two instructions tells you to insert a new integer before or after the current pointer. Note that, when you insert an element, the pointer does not move.

When there are no more instructions you should print the list, one value per line.

**Input**
List of instructions, one per line, until EOF. There are at most 100000 instructions.

**Output**
The final list, starting from the leftmost value.

**Example**
Input

	INSERT RIGHT 2
	INSERT LEFT -1	
	MOVE RIGHT
	INSERT LEFT 1
	INSERT RIGHT 3
	MOVE LEFT
	MOVE LEFT
	MOVE LEFT
	INSERT LEFT -3
	INSERT LEFT -2
Output

	-3
	-2
	-1
	0
	1
	2
	3
**Explanation**

Note: parenthesis denote the element where the pointer is.
- List before any instruction: (0)
- List after instruction #1:   (0) 2  
- List after instruction #2:   -1 (0) 2  
- List after instruction #3:   -1 0 (2)
- List after instruction #4:   -1 0 1 (2)
- List after instruction #5:   -1 0 1 (2) 3
- List after instruction #6:   -1 0 (1) 2 3
- List after instruction #7:   -1 (0) 1 2 3
- List after instruction #8:   (-1) 0 1 2 3
- List after instruction #9:   -3 (-1) 0 1 2 3
- List after instruction #10:  -3 -2 (-1) 0 1 2 3
- Final list:                  -3 -2 -1 0 1 2 3


# E - Postfix calculator
**Description**
Given a set of mathematical expression in postfix notation, such that each operand/operator is separated by a space, print the result of that expression. To simplify, only the '+' and '-' operators are considered.

Example of a postfix expression:

	2 3 4 - +
To compute the result process the expression from the left to the right, then:

- If the next token is a number, push it into the stack

- If the next token is an operator, pop the two top numbers from the stack, perform the computation with that operator, and put the result back into the top of the stack. Note that the order is important, so for example: "3 4 -" should be evaluated as "3 - 4 = -1".

Once the expression is fully processed the result will be the only element left in the stack.

So the contents of the stack for the processing of that expression would be

- After push operation: 2
- After push operation: 2 3
- After push operation: 2 3 4
- After '-' operation:  2 -1
- After '+' operation:  1 
**Input**
The first line contains the number of postfix expressions to process. Then, each line of the following lines contains a postfix expression to evaluate.

**Output**
For each expression print the result of the evaluation.

**Example**
Input

	3
	2 3 4 - +
	10 82 - 12 +
	-1 2 + 1 -
Output

	1
	-60
	0


# F - Queue processing time
**Description**
Given a list of tasks that arrive to an execution queue at a given time and that take a given amount of processing, find the total time needed to process all the tasks. Note that the tasks are processed in the order they arrive, and only one task is processed at each time.

**Input**
The first line contains the number of tasks that arrive in the system. The following lines contain a task each, such that a task is described by two integers, the arrival time and the processing time. The list is guaranteed to be sorted by the arrival time.

**Output**
Return the time at which the system will have processed all the tasks, assuming that the tasks are processed in the order they arrive.

**Example**
Input

	4
	1 2
	1 1
	3 2
	4 1
Output

	7
Explanation

- Task #1 arrives at time 1, starts at time 1, and finishes at time 3
- Task #2 arrives at time 1, starts at time 3, and finishes at time 4
- Task #3 arrives at time 3, starts at time 4, and finishes at time 6
- Task #4 arrives at time 4, starts at time 6, and finishes at time 7
- System stops processing at time 7

# G - Bowling shoes
**Description**
You manage a bowling alleys' shoe lending facility. When a customer arrives, they ask for a given shoe size. If you have a pair of shoes in that size, you lend them those shoes, if not you lend a pair of shoes that have a greater size but that are the closest to that customer's ideal size. For example, if they ask for 40, but you only have 39, 42, and 44. You lend the shoes with size 42. If no such shoes are available in a greater size you turn the customer down.

Initially your shoe stand is empty, then there are two operations that can occur.

	  ADD x      # you add a pair of shoes of size x (int) into your stand
	  REQUEST y  # service a customer's request for a pair of shoes of size y (int)
When you receive a request, you need to service it following what was described above, and print either the size that you gave to the customer, or print "impossible" if no feasible size was available. Note that, if you service a request the shoes of that that size leaves your stand.

**Input**
List of instructions, one per line, until EOF. All sizes are positive integers. There are at most 200000 instructions.

**Output**
Each time a request comes in print an integer denoting the size of the pair of shoes you lent, or "impossible" if it was not possible to service the request.

**Example**
Input

	ADD 30
	ADD 50
	ADD 50
	REQUEST 50
	ADD 40
	REQUEST 35
	REQUEST 33
	REQUEST 32
	ADD 10
Output
	
	50
	40
	50
	impossible
**Explanation**

 - Available sizes after instruction #1: [30] 
 - Available sizes after instruction #2: [30,50] 
 - Available sizes after instruction #3:[30,50,50] 
 - Available sizes after instruction #4: [30,50] 
 - Available sizes after instruction #5: [30,40,50] 
 - Available sizes after instruction #6: [30,50] 
 - Available sizes after instruction #7: [30]
 - Available sizes after instruction #8: [30] 
 - Available sizes after instruction #9: [10,30]

# H - Inventory Management
**Description**
You are responsible for the software that manages the inventory for your company. To do this, you need to quickly process three types of instructions:

	  ADD x y    # you add `x` copies of the item with id `y` to the inventory
	  REM x y    # you remove `x` copies of the item `y` from the inventory
	  QUERY y    # you print how many items with id `y` exist in the inventory 
Note that, if not enough items exist in the inventory for the remove instruction you print "removal refused" and do not remove any item.

**Input**
List of instructions, one per line, until EOF. All ids and quantities are positive integers. There are at most 500000 instructions.

**Output**
When a query instruction appears, print the number of items available for the queried item id. For the remove instruction, if there are not enough items to remove print "removal refused".

**Example**
Input

	ADD 10 1
	ADD 5 2
	REM 4 2
	REM 2 2
	QUERY 2
	REM 2 1
	QUERY 1
	QUERY 3
Output

	removal refused
	1
	8
	0
