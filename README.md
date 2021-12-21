# Final
Final of ECE 231, due 12/14/2021 at 2:30 pm.

## Objective
In this exam, you will be analyzing anonymous temperature data from hundreds of people. You will take some statistics on this data set and give a short report on the results. A makefile will be provided to make compiling easier.

## The data
The data that will be given to you are three text (txt) files that contain anonymous temperatures from three cities (these are actually randomly generated but play along with it) each of the files have the names of the cities of where the data 'comes from'.

```
    - Albuquerque
    - Santa Fe
    - San Antonio
```

You have been provided `main.cpp` but all it does right now is read in the data of the three files into three std::vectors. There are also some utility functions for opening a file and copying its contents to a vector, printing a std::vector, std::stack, and a std::queue.

Instead of using the stack and queue class from the previous homework, you must use the ones from the Standard Template Library (STL). Here are some [links on the STL stack class](https://en.cppreference.com/w/cpp/container/stack), [as well as the STL queue class](https://en.cppreference.com/w/cpp/container/queue).

## Objective breakdown
**This will be done for each dataset** in `main.cpp`.

```
    * Copy the contents of the vector into a queue
    * Go through the queue and split the vector data into two stacks: group_a and group_b.
    * If the temperature is lower than 99, add it to group_a
    * If the temperature is higher than or equal to 99, add it to group_b.
    * Print the sizes of both of the stacks.
    * Find and print the minimum value of both stacks.
    * Find and print the maximum value of both stacks.
    * Find and print the mean (average) value of both stacks, and the queue.
    * Write a small report on your results for each dataset.
```

## Report
When writing your report for the datasets, you must comment on the entire dataset, group_a, and group_b. Are the min/max/mean values high? Are they low? What does it mean if it is higher or lower than the average human temperature (98.6 Fahrenheit before, now is considered 97.5 Fahrenheit pick one to consider your baseline)? For humans, they have a fever when their temperature raises above 99 degrees. What does that say about the population? Should that area be concerned about getting fevers? Address these things in your report. Pretend your a data scientist working for a bio-analytics company. The report should contain 4-5 sentences for each dataset.

# Rubric
| Requirement                                         | Score |
| :-------------------------------------------------: | :---: |
|-----------------------------------------------------|-------|
| Creation of stacks and queues                       |   10  |
| Separating data into group_a and group_b            |   10  |
| Print size of group_a and group_b                   |   5   |
| Calculate min and max of group_a, and group_b       |   10  |
| Calculate the mean for group_a, group_b and queue   |   20  |
| Reports                                             |   25  |
| Clean code                                          |   10  |
|-----------------------------------------------------|-------|
| Total                                               |  100  |
