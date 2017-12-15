#include <iostream>
#include <string>

template <typename T, size_t size>
class Stack
{
public:
	Stack();
	void push(const T& value);
	T pop();
private:
	T* stackPtr;
	int top;
};

template <typename T, size_t size>
Stack<T, size>::Stack()
{
	if (size <= 0)
	{
		throw std::string("size of stack is uncorrect");
	}
	else
	{
		stackPtr = new T[size];
		top = 0;
	}

}

template <typename T, size_t size>
T Stack<T, size>::pop()
{
	if (top > 0)
	{
		return(stackPtr[--top]);
	}
	else
	{
		throw std::string("Stack underflow");
	}
}

template <typename T, size_t size>
void Stack<T, size>::push(const T &value)
{
	if (top < size)
	{
		stackPtr[top++] = value;
	}
	else
	{
		throw std::string("Stack overflowed");
	}
}
int main()
{
	try
	{
		Stack<std::string, 12> st;
		try
		{
			for (int i = 0; i < 12; i++)
			{
				st.push(std::string("hey"));
			}
		}
		catch (std::string str)
		{
			std::cout << str << std::endl;
		}

		try
		{
			for (int i = 0; i < 10; i++)
			{
				std::cout << st.pop() << std::endl;
			}
		}
		catch (std::string str)
		{
			std::cout << str << std::endl;
		}
	}
	catch (std::string str)
	{
		std::cout << str << std::endl;
	}


	system("PAUSE");
	return 0;
}