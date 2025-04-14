#include <iostream>
#include <execution>
#include <mutex>

int main()
{	
	bool flaga = false;
	int x = 0,sum = 0, i=3;
		std::mutex m;
		int a[10000]{2,9,6,1};
		
		for(int& val : a)	
		{
			i++;
			val= i;
		}	
		std::for_each(std::execution::par, std::begin(a), std::end(a), [&](int value) 
		{
			std::lock_guard<std::mutex> guard(m);
		    sum+=value; // process1 (4) // process2(4) 4
			++x; // correct
		});
		std::cout << sum << "\n";
		                                           
return 0;
}
