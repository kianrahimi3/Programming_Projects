# 21f-pa02-team_kian
21f-pa02-team_kian created by GitHub Classroom


This project emphasizes the data collection and creation of iterators for 3 data structures. 
The data structures being created are a vector, linked list, and a balanced binary tree.
Each of these structures have iterators to allow for going through the structure. 
While the binary tree and the linked list both only have forward iterators, the vector supports both
the forward and random access iterator.

The following data were collected for both integers and strings:

dataset of size s with 0% duplicates
dataset of size s with 0% duplicates that is sorted in ascending order
dataset of size s with 0% duplicates that is sorted in descending order
randomized dataset of size s with 20% duplicates
randomized dataset of size s with 40% duplicates

The sizes of this data consisted of the following sizes:

1000, 10000, 100000, 500000, 1000000, 2000000

In order to generate the random strings and integers, I have use srand() as well as
created separate functions that takes in the type being requested,
and from there, create the requested dataset. In order to check
if the right amount was being duplicated, I made sure to input the same string/integer that was first
generated the amount of times necessary. This was done by multiplying the size * 0.2 or by 0.4 to ensure the 
20% or 40% duplicated.

As for the sorting algorithms, the vectors that the data was sorted on can be 
ran with a for loop using iterators..specifically using the random iterators. 
This can be determined by using vec.random_begin() and vec.random_end().

Under the Graphs folder you can find the images of the graphs
for the different sorting algorithms. Though many look similar, 
it can be determined that a common trend of string sorting takes 
more time than sorting integers. This may due to the fact that characters
and strings in general take up more memory than integers do..thus making performance time a longer one.