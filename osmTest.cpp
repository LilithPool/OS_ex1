
#include "osm.h"
#include <sys/time.h>
#include <iostream>



int main()
{
	double time1 = osm_syscall_time(1000);
	double time2 = osm_operation_time(1000);
	double time3 = osm_function_time(1000);
	std::cout << "Syscall time: " << time1 << std::endl;
	std::cout << "Operation time: " << time2 << std::endl;
	std::cout << "Function time: " << time3 << std::endl;
	return 0;
}


/* Initialization function that the user must call
 * before running any other library function.
 * The function may, for example, allocate memory or
 * create/open files.
 * Pay attention: this function may be empty for some desings. It's fine.
 * Returns 0 uppon success and -1 on failure
 */
int osm_init() {return 0;}


/* finalizer function that the user must call
 * after running any other library function.
 * The function may, for example, free memory or
 * close/delete files.
 * Returns 0 uppon success and -1 on failure
 */
int osm_finalizer() {return 0;}


/* Time measurement function for a simple arithmetic operation.
   returns time in nano-seconds upon success,
   and -1 upon failure.
   */
double osm_operation_time(unsigned int iterations = 1000)
{
	// illegal value
	if (iterations == 0)
	{
		return -1;
	}
	timeval start, end;
	int a = 0;
	gettimeofday(&start, NULL);
	for (unsigned int i = 0; i < iterations/10; ++i)
	{
		a = a + 1;
		a = a + 1;
		a = a + 1;
		a = a + 1;
		a = a + 1;
		a = a + 1;
		a = a + 1;
		a = a + 1;
		a = a + 1;
		a = a + 1;
		a = 0;  // to assure the compiler doesn't do funny things
	}
	gettimeofday(&end, NULL);
	// time from gettimeofday measured in microseconds so need to multiple by 1000
	double time = (end.tv_usec - start.tv_usec) * 1000;
	return time / iterations;
}


/* An empty function with no arguments.
 */
void empty_func(){}


/* Time measurement function for an empty function call.
   returns time in nano-seconds upon success,
   and -1 upon failure.
   */
double osm_function_time(unsigned int iterations = 1000)
{
	// illegal value
	if (iterations == 0)
	{
		return -1;
	}
	timeval start, end;
	gettimeofday(&start, NULL);
	for (unsigned int i = 0; i < iterations / 10; i++)
	{
		empty_func();
		empty_func();
		empty_func();
		empty_func();
		empty_func();
		empty_func();
		empty_func();
		empty_func();
		empty_func();
		empty_func();
	}
	gettimeofday(&end, NULL);
	// time from gettimeofday measured in microseconds so need to multiple by 1000
	double time = (end.tv_usec - start.tv_usec) * 1000;
	return time / iterations;
}


/* Time measurement function for an empty trap into the operating system.
   returns time in nano-seconds upon success,
   and -1 upon failure.
   */
double osm_syscall_time(unsigned int iterations = 1000)
{
	// illegal value
	if (iterations == 0)
	{
		return -1;
	}
	timeval start, end;
	gettimeofday(&start, NULL);
	for (unsigned int i = 0; i < iterations/10; i++)
	{
		OSM_NULLSYSCALL;
		OSM_NULLSYSCALL;
		OSM_NULLSYSCALL;
		OSM_NULLSYSCALL;
		OSM_NULLSYSCALL;
		OSM_NULLSYSCALL;
		OSM_NULLSYSCALL;
		OSM_NULLSYSCALL;
		OSM_NULLSYSCALL;
		OSM_NULLSYSCALL;
	}
	gettimeofday(&end, NULL);
	// time from gettimeofday measured in microseconds so need to multiple by 1000
	double time = (end.tv_usec - start.tv_usec) * 1000;
	return time / iterations;
}




