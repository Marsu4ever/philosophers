# philosophers

**PREAMBLE**  
Many Philosophers have contributed to society in different ways, but they 3 activities that they have in common:  
1. Think  
2. Eat  
3. Sleep  

These philos sit around a circular table. When they eat, obviously use **2 Forks** to eat Spaghetti.  

Now - that said - there is an EQUAL number of FORKS and PHILOS around the table. This means that if a philo is eating, then the adjacent philos can't be eating. 

If a philo doesn't get to eat soon enough, he will starve and die.  

*************************************************************************************************************************

**How to Run**:  
./philo [number of philos] [death_duration] [eat_duration] [sleep_duration] (OPTIONAL [Number_of_meals])  
f.ex. ./philo 4 1000 200 200 5  

**Note**: Don't use time durations that are below 60(ms) and cap the number of philos at 200.

*************************************************************************************************************************

**The Simulation**:  
The program will run on forever with the philos eating, sleeping, thinking, if no issues arise.  

However, the simulation ends if:
1. a philo dies
2. all meals are eaten

*************************************************************************************************************************

**Why**:
The program is a showcase in employing **threads** and **mutexes**.  

![philosopers_on_terminal](./philo/philosopher.png)
