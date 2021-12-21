#include <iostream>

#include <vector>
#include <queue>
#include <stack> 
#include <string> 

#include <fstream> 

// This function opens a file and copies its contents to a vector
template <typename T>
void load_temps(std::vector<T> &v, std::string filename) {
	std::ifstream infile(filename);
	// Checks if file is open
	if (infile.is_open()) {
		T temp;
		// Read in all data and push it to the input vector 'v'
		while (infile >> temp) {
			v.push_back(temp);
		}
		infile.close();
	}
	else {
		std::cout << "Could not open " << filename << '\n';
	}
}

// Print functions
template <typename T>
void print_vector(const std::vector<T> &v) {
	for (const auto &i : v) {
		std::cout << i << ' ';
	}
	std::cout << '\n';
}

// Notice that the input 'q' is a COPY not a REFERENCE
// 	This is so that we and access front(), then pop() to access the next
// 	front()
template <typename T>
void print_queue(std::queue<T> q) {
	while(!q.empty()) {
		std::cout << q.front() << ' ';
		q.pop();
	}
	std::cout << '\n';
}

// Same methodology as print_queue
template <typename T>
void print_stack(std::stack<T> s) {
	while(!s.empty()) {
		std::cout << s.top() << ' ';
		s.pop();
	}
	std::cout << '\n';
}

//returns the minimum value of the stack
template <typename T>
T getMin(std::stack<T> s) {
	T min = s.top(); //gets top value
	T curr_val;
	while (!s.empty()) {
		curr_val = s.top();
		if (curr_val < min) 
			min = curr_val;
		s.pop(); //removing the topmost element to bring next element on top before the next iteration
	}
	//std::cout<<"The minimum element of the stack is = " << min << "\n";
	return min;

}

//returs the maximum value of the stack
template <typename T>
T getMax(std::stack<T> s) {
	T max = s.top(); //gets top value
        T curr_val;
        while (!s.empty()) {
                curr_val = s.top();
                if (curr_val > max)
                        max = curr_val;
                s.pop(); //removing the topmost element to bring next element on
 			 //top before the next iteration
        }
	//std::cout<<"The maximum element of the stack is = " << max << "\n";
        return max;
}

//returns the mean (average) value of the stack
template <typename T>
T getAverage(std::stack<T> s) {
	T sum, average;
	int count = 0; //calculates the number of elements in stack
	while (!s.empty()) {
		sum += s.top(); //sum every top value and assign it to sum
		s.pop(); //removing the topmost element to bring next element 
			 // on top before the next iteration
		count++; //incrementing count for every sum operation
	}
	/*The s.size() is not used because after loop s.size() = 0 so there are two possibilities
	 * 1- using a temperary stack for sum operation and original stack for count
	 * 2- using a count variable and increment after every sum*/
	average = sum / count; 
	//std::cout<<"The mean(average) value of stack = " << average << "Fahrenheit\n";
	return average;
}

//returns the mean (average) value of the queue
template <typename T>
T getMean(std::queue<T> q) {
	T sum, average;
	int count = 0; //calculates the number of elements in queue since, it will be empty after loop
	while (!q.empty()){
		sum += q.front(); //gets the first element of queue and add it.
		q.pop(); //removes the first element from queue to bring next element on front
		count++; //incrementing count for every sum operation
	}
	average = sum / count;
	//std::cout<<"The mean(average) value of queue = " << average << "Fahrenheit\n";
        return average;

}

// copy elements of Vector into two stacks (a and b) based on the value of temperature
template <typename T>
void copyVector(std::stack<T> &a, std::stack<T> &b, const std::vector<T> v) {
	for(auto &elem : v){
                if(elem < 99.0)
                        a.push(elem);
                else if(elem >= 99.0)
                        b.push(elem);
	}
}

/*copy elements of Queue into two Stacks (a and b) based on the value of temperature
 * no const keyword for queue (q) is used because pop() method is used inside which is a non-const qualified method.
*/
template <typename T>
void copyQueue(std::stack<T> &a, std::stack<T> &b, std::queue<T> q) {
	//No need to create temp_queue because q is already a copy
	//std::queue<float> temp_queue (albuquerque_queue); 
	while(!q.empty()){
                T q_element = q.front();
                if(q_element < 99.0)
                        a.push(q_element);
                else if(q_element >=99.0)
                        b.push(q_element);
                q.pop();
        }
}

int main() {
	std::string albuquerque("albuquerque_temperatures.txt");
	std::string santa_fe("santa_fe_temperatures.txt");
	std::string san_antonio("san_antonio_temperatures.txt");

	// Three vectors that are going to contain temperatures
	std::vector<float> albuquerque_temps;
	std::vector<float> santa_fe_temps;
	std::vector<float> san_antonio_temps;

	// Loading temperatures
	load_temps(albuquerque_temps, albuquerque);
	load_temps(santa_fe_temps, santa_fe);
	load_temps(san_antonio_temps, san_antonio);
	
	/*creating a queue containing elements of albuquerque_temps Vector 
	 *i.e. copying the contents of vector into queue using deque
	*/
	std::queue<float, std::deque<float>> albuquerque_queue(std::deque<float>(albuquerque_temps.begin(), albuquerque_temps.end()));

	// copy elements of Vector into two stacks (group_a and group_b)
	std::stack<float> group_a, group_b;
	//copyVector(group_a, group_b, albuquerque_temps);
	
	//copy elements of Queue (albuquerque_queue) into two stacks (group_a and group_b)
	copyQueue(group_a, group_b, albuquerque_queue);	
	
	std::cout << "City1-Albuquerque:\n";

	//printing the sizes of both of the stacks
	std::cout<<"\tSize of group_a is = "<< group_a.size()<<"\n";
	std::cout<<"\tSize of group_b is = "<< group_b.size()<<"\n";
	
	//find and print minimum value of both stacks
	std::cout << "\tThe minimum value of group_a stack = " << getMin(group_a) << "\n";
	std::cout << "\tThe minimum value of group_b stack = " << getMin(group_b) << "\n";
	
	//find and print maximum value of both stacks
	std::cout << "\tThe maximum value of group_a stack = " << getMax(group_a) << "\n";
        std::cout << "\tThe maximum value of group_b stack = " << getMax(group_b) << "\n";
	
	//find and print the mean (average) value of both stacks and the queue
	std::cout << "\tThe mean (average) value of group_a stack = " << getAverage(group_a) << "\n";
	std::cout << "\tThe mean (average) value of group_b stack = " << getAverage(group_b) << "\n";
	std::cout << "\tThe mean (average) value of queue = " << getMean(albuquerque_queue) << "\n";
	
	/*deleting all elements of group_a and group_b before assigning new elements of santa_fe_temps
	  Vector
	 * using a new empty stack and copying its contents to group_a and group_b in order to empty both
	   stacks*/ 
	group_a = std::stack<float>();
	group_b = std::stack<float>();

	/*creating a queue containing elements of santa_fe_temps Vector
         *i.e. copying the contents of vector into queue using deque
        */
        std::queue<float, std::deque<float>> santa_fe_queue(std::deque<float>(santa_fe_temps.begin(), santa_fe_temps.end()));

	//copy elements of Queue(santa_fe_queue) into two stacks (group_a and group_b)
        copyQueue(group_a, group_b, santa_fe_queue);

        std::cout << "City2-Santa Fe:\n";

        //printing the sizes of both of the stacks
        std::cout<<"\tSize of group_a is = "<< group_a.size()<<"\n";
        std::cout<<"\tSize of group_b is = "<< group_b.size()<<"\n";

        //find and print minimum value of both stacks
        std::cout << "\tThe minimum value of group_a stack = " << getMin(group_a) << "\n";
        std::cout << "\tThe minimum value of group_b stack = " << getMin(group_b) << "\n";

        //find and print maximum value of both stacks
        std::cout << "\tThe maximum value of group_a stack = " << getMax(group_a) << "\n";
        std::cout << "\tThe maximum value of group_b stack = " << getMax(group_b) << "\n";

        //find and print the mean (average) value of both stacks and the queue
        std::cout << "\tThe mean (average) value of group_a stack = " << getAverage(group_a) << "\n";
        std::cout << "\tThe mean (average) value of group_b stack = " << getAverage(group_b) << "\n";
        std::cout << "\tThe mean (average) value of queue = " << getMean(santa_fe_queue) << "\n";
	
	/*deleting all elements of group_a and group_b before assigning new elements of san_antonio_temps
	  Vector
         * using a new empty stack and copying its contents to group_a and group_b in order to empty both
	   stacks */
        group_a = std::stack<float>();
        group_b = std::stack<float>();

	/*creating a queue containing elements of san_antonio_temps Vector
         *i.e. copying the contents of vector into queue using deque
        */
        std::queue<float, std::deque<float>> san_antonio_queue(std::deque<float>(san_antonio_temps.begin(), san_antonio_temps.end()));

        //copy elements of Queue(san_antonio_queue) into two stacks (group_a and group_b)
        copyQueue(group_a, group_b, san_antonio_queue);

        std::cout << "City3-San Antonio:\n";

        //printing the sizes of both of the stacks
        std::cout<<"\tSize of group_a is = "<< group_a.size()<<"\n";
        std::cout<<"\tSize of group_b is = "<< group_b.size()<<"\n";

        //find and print minimum value of both stacks
        std::cout << "\tThe minimum value of group_a stack = " << getMin(group_a) << "\n";
        std::cout << "\tThe minimum value of group_b stack = " << getMin(group_b) << "\n";

        //find and print maximum value of both stacks
        std::cout << "\tThe maximum value of group_a stack = " << getMax(group_a) << "\n";
        std::cout << "\tThe maximum value of group_b stack = " << getMax(group_b) << "\n";

        //find and print the mean (average) value of both stacks and the queue
        std::cout << "\tThe mean (average) value of group_a stack = " << getAverage(group_a) << "\n";
        std::cout << "\tThe mean (average) value of group_b stack = " << getAverage(group_b) << "\n";
        std::cout << "\tThe mean (average) value of queue = " << getMean(san_antonio_queue) << "\n";

	return 0;
}
